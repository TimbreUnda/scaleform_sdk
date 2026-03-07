/**************************************************************************

Filename    :   Vulkan_MeshCache.cpp
Content     :   Vulkan mesh cache with chunk-based allocation and eviction.
Created     :   2025
Authors     :   Vulkan backend

Copyright   :   Copyright 2011 Autodesk, Inc. All rights reserved.

**************************************************************************/

#include "Render/Vulkan/Vulkan_MeshCache.h"
#include "Render/Vulkan/Vulkan_ShaderDescs.h"
#include "Render/Render_Vertex.h"
#include "Kernel/SF_Debug.h"
#include "Kernel/SF_HeapNew.h"

namespace Scaleform { namespace Render { namespace Vulkan {

// ***** VulkanMeshBuffer

VulkanMeshBuffer::VulkanMeshBuffer(UPInt size, AllocType type, unsigned arena)
    : Render::MeshBuffer(size, type, arena)
    , Buffer(VK_NULL_HANDLE)
    , Memory(VK_NULL_HANDLE)
    , Device(VK_NULL_HANDLE)
{
}

VulkanMeshBuffer::~VulkanMeshBuffer()
{
    Destroy();
}

bool VulkanMeshBuffer::Create(VkDevice device, VkPhysicalDevice physicalDevice)
{
    if (Buffer != VK_NULL_HANDLE)
        return true;

    Device = device;

    VkBufferCreateInfo bufInfo = {};
    bufInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    bufInfo.size = Size;
    bufInfo.usage = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT | VK_BUFFER_USAGE_INDEX_BUFFER_BIT;
    bufInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

    if (vkCreateBuffer(device, &bufInfo, 0, &Buffer) != VK_SUCCESS)
        return false;

    VkMemoryRequirements memReq;
    vkGetBufferMemoryRequirements(device, Buffer, &memReq);

    VkPhysicalDeviceMemoryProperties memProps;
    vkGetPhysicalDeviceMemoryProperties(physicalDevice, &memProps);
    uint32_t memTypeIndex = (uint32_t)-1;
    for (uint32_t i = 0; i < memProps.memoryTypeCount; i++)
    {
        if ((memReq.memoryTypeBits & (1u << i)) &&
            (memProps.memoryTypes[i].propertyFlags & (VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT)) ==
                (VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT))
        {
            memTypeIndex = i;
            break;
        }
    }
    if (memTypeIndex == (uint32_t)-1)
    {
        vkDestroyBuffer(device, Buffer, 0);
        Buffer = VK_NULL_HANDLE;
        return false;
    }

    VkMemoryAllocateInfo allocInfo = {};
    allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocInfo.allocationSize = memReq.size;
    allocInfo.memoryTypeIndex = memTypeIndex;

    if (vkAllocateMemory(device, &allocInfo, 0, &Memory) != VK_SUCCESS)
    {
        vkDestroyBuffer(device, Buffer, 0);
        Buffer = VK_NULL_HANDLE;
        return false;
    }

    vkBindBufferMemory(device, Buffer, Memory, 0);

    if (vkMapMemory(device, Memory, 0, Size, 0, &pData) != VK_SUCCESS)
    {
        vkFreeMemory(device, Memory, 0);
        vkDestroyBuffer(device, Buffer, 0);
        Buffer = VK_NULL_HANDLE;
        Memory = VK_NULL_HANDLE;
        return false;
    }

    return true;
}

void VulkanMeshBuffer::Destroy()
{
    if (Device == VK_NULL_HANDLE)
        return;
    if (pData)
    {
        vkUnmapMemory(Device, Memory);
        pData = 0;
    }
    if (Memory != VK_NULL_HANDLE)
    {
        vkFreeMemory(Device, Memory, 0);
        Memory = VK_NULL_HANDLE;
    }
    if (Buffer != VK_NULL_HANDLE)
    {
        vkDestroyBuffer(Device, Buffer, 0);
        Buffer = VK_NULL_HANDLE;
    }
    Device = VK_NULL_HANDLE;
}

// ***** MeshCacheItem

MeshCacheItem* MeshCacheItem::Create(MeshType type, MeshCacheListSet* pcacheList, MeshBaseContent& mc,
                                     VkBuffer pvb, VkBuffer pib,
                                     UPInt vertexOffset, UPInt vertexAllocSize, unsigned vertexCount,
                                     UPInt indexOffset, UPInt indexAllocSize, unsigned indexCount,
                                     UPInt allocAddress, UPInt allocSize)
{
    MeshCacheItem* p = (MeshCacheItem*)Render::MeshCacheItem::Create(type, pcacheList, sizeof(MeshCacheItem), mc,
                                                                      vertexAllocSize + indexAllocSize, vertexCount, indexCount);
    if (p)
    {
        p->pVertexBuffer = pvb;
        p->pIndexBuffer  = pib;
        p->VBAllocOffset = vertexOffset;
        p->VBAllocSize   = vertexAllocSize;
        p->IBAllocOffset = indexOffset;
        p->IBAllocSize   = indexAllocSize;
        p->AllocAddress  = allocAddress;
        p->AllocSize     = allocSize;
    }
    return p;
}

// ***** MeshCache

MeshCache::MeshCache(MemoryHeap* pheap, const MeshCacheParams& params)
    : Render::MeshCache(pheap, params)
    , pDevice(VK_NULL_HANDLE)
    , pPhysicalDevice(VK_NULL_HANDLE)
    , CacheList(this)
    , Allocator(pHeap)
    , TotalSize(0)
    , pMaskEraseBatchVertexBuffer(VK_NULL_HANDLE)
    , MaskEraseBatchVertexMemory(VK_NULL_HANDLE)
{
}

MeshCache::~MeshCache()
{
    Reset();
}

bool MeshCache::Initialize(VkDevice device, VkPhysicalDevice physicalDevice)
{
    pDevice = device;
    pPhysicalDevice = physicalDevice;

    if (!StagingBuffer.Initialize(pHeap, Params.StagingBufferSize))
        return false;

    // Create initial reserve buffer if configured
    if (Params.MemReserve > 0)
    {
        UPInt reserveSize = Alg::Align(Params.MemReserve, (UPInt)BufferAlignment);
        if (!allocMeshBuffer(reserveSize, MeshBuffer::AT_Reserve))
            return false;
    }

    if (!createMaskEraseBatchVertexBuffer(physicalDevice))
        return false;

    return true;
}

void MeshCache::Reset()
{
    ClearCache();
    while (!Buffers.IsEmpty())
    {
        VulkanMeshBuffer* pb = (VulkanMeshBuffer*)Buffers.GetFirst();
        pb->RemoveNode();
        releaseMeshBuffer(pb);
    }
    TotalSize = 0;

    if (pDevice != VK_NULL_HANDLE)
    {
        if (pMaskEraseBatchVertexBuffer != VK_NULL_HANDLE)
        {
            vkDestroyBuffer(pDevice, pMaskEraseBatchVertexBuffer, 0);
            pMaskEraseBatchVertexBuffer = VK_NULL_HANDLE;
        }
        if (MaskEraseBatchVertexMemory != VK_NULL_HANDLE)
        {
            vkFreeMemory(pDevice, MaskEraseBatchVertexMemory, 0);
            MaskEraseBatchVertexMemory = VK_NULL_HANDLE;
        }
    }

    pDevice = VK_NULL_HANDLE;
    pPhysicalDevice = VK_NULL_HANDLE;
    StagingBuffer.Reset();
}

VulkanMeshBuffer* MeshCache::allocMeshBuffer(UPInt size, MeshBuffer::AllocType atype, unsigned arena)
{
    VulkanMeshBuffer* pb = SF_NEW(pHeap) VulkanMeshBuffer(size, atype, arena);
    if (!pb || !pb->Create(pDevice, pPhysicalDevice))
    {
        if (pb)
            delete pb;
        return 0;
    }

    Allocator.AddSegment((UPInt)pb->pData, pb->GetSize());
    TotalSize += pb->GetSize();
    Buffers.PushBack(pb);

    return pb;
}

void MeshCache::releaseMeshBuffer(VulkanMeshBuffer* pbuffer)
{
    if (!pbuffer)
        return;
    Allocator.RemoveSegment((UPInt)pbuffer->pData, pbuffer->GetSize());
    TotalSize -= pbuffer->GetSize();
    pbuffer->RemoveNode();
    pbuffer->Destroy();
    delete pbuffer;
}

VulkanMeshBuffer* MeshCache::findBuffer(UPInt address)
{
    VulkanMeshBuffer* pb = (VulkanMeshBuffer*)Buffers.GetFirst();
    while (!Buffers.IsNull(pb))
    {
        UPInt base = (UPInt)pb->pData;
        if (address >= base && address < base + pb->GetSize())
            return pb;
        pb = (VulkanMeshBuffer*)pb->pNext;
    }
    return 0;
}

bool MeshCache::allocBuffer(UPInt* pallocAddress, UPInt size, bool waitForCache)
{
    *pallocAddress = Allocator.Alloc(size);
    if (*pallocAddress != ~UPInt(0))
        return true;

    MeshCacheItem* pitems;

    // #1. Reclaim memory from destroyed-but-not-freed items
    if (CacheList.EvictPendingFree(Allocator))
        goto alloc_size_available;

    // #2. Evict LRU items, optionally with limit to allow growth
    if ((TotalSize + MinGranularity) <= Params.MemLimit)
    {
        if (CacheList.EvictLRUTillLimit(MCL_LRUTail, Allocator, size, Params.LRUTailSize))
            goto alloc_size_available;

        if (size <= Alg::PMin(Params.MemLimit - TotalSize, (UPInt)Params.MemGranularity))
        {
            if (allocMeshBuffer(Alg::PMin(Params.MemLimit - TotalSize, (UPInt)Params.MemGranularity), MeshBuffer::AT_Chunk, 0))
                goto alloc_size_available;
        }
    }

    if (CacheList.EvictLRU(MCL_LRUTail, Allocator, size))
        goto alloc_size_available;

    // #3. Evict from previous frame
    MeshCacheListSet::ListSlot& prevFrameList = CacheList.GetSlot(MCL_PrevFrame);
    pitems = (MeshCacheItem*)prevFrameList.GetFirst();
    while (!prevFrameList.IsNull(pitems))
    {
        if (Evict(pitems, &Allocator) >= size)
            goto alloc_size_available;
        pitems = (MeshCacheItem*)prevFrameList.GetFirst();
    }

    // #4. Evict from current frame (Vulkan uses QM_ExtendLocks, no fences - always evict)
    MeshCacheListSet::ListSlot& thisFrameList = CacheList.GetSlot(MCL_ThisFrame);
    pitems = (MeshCacheItem*)thisFrameList.GetFirst();
    while (!thisFrameList.IsNull(pitems))
    {
        if (Evict(pitems, &Allocator) >= size)
            goto alloc_size_available;
        pitems = (MeshCacheItem*)thisFrameList.GetFirst();
    }

    (void)waitForCache;
    return false;

alloc_size_available:
    *pallocAddress = Allocator.Alloc(size);
    SF_ASSERT(*pallocAddress != ~UPInt(0));
    return true;
}

bool MeshCache::createMaskEraseBatchVertexBuffer(VkPhysicalDevice physicalDevice)
{
    struct VertexXY32fAlpha { float x, y; UByte Alpha[4]; };
    const unsigned bufferSize = sizeof(VertexXY32fAlpha) * 6 * SF_RENDER_MAX_BATCHES;
    VkBufferCreateInfo bufInfo = {};
    bufInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    bufInfo.size = bufferSize;
    bufInfo.usage = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
    bufInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
    if (vkCreateBuffer(pDevice, &bufInfo, 0, &pMaskEraseBatchVertexBuffer) != VK_SUCCESS)
        return false;
    VkMemoryRequirements memReq;
    vkGetBufferMemoryRequirements(pDevice, pMaskEraseBatchVertexBuffer, &memReq);
    VkPhysicalDeviceMemoryProperties memProps;
    vkGetPhysicalDeviceMemoryProperties(physicalDevice, &memProps);
    uint32_t memTypeIndex = (uint32_t)-1;
    for (uint32_t i = 0; i < memProps.memoryTypeCount; i++)
    {
        if ((memReq.memoryTypeBits & (1u << i)) &&
            (memProps.memoryTypes[i].propertyFlags & (VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT)) ==
                (VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT))
        {
            memTypeIndex = i;
            break;
        }
    }
    if (memTypeIndex == (uint32_t)-1)
    {
        vkDestroyBuffer(pDevice, pMaskEraseBatchVertexBuffer, 0);
        pMaskEraseBatchVertexBuffer = VK_NULL_HANDLE;
        return false;
    }
    VkMemoryAllocateInfo allocInfo = {};
    allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocInfo.allocationSize = memReq.size;
    allocInfo.memoryTypeIndex = memTypeIndex;
    if (vkAllocateMemory(pDevice, &allocInfo, 0, &MaskEraseBatchVertexMemory) != VK_SUCCESS)
    {
        vkDestroyBuffer(pDevice, pMaskEraseBatchVertexBuffer, 0);
        pMaskEraseBatchVertexBuffer = VK_NULL_HANDLE;
        return false;
    }
    vkBindBufferMemory(pDevice, pMaskEraseBatchVertexBuffer, MaskEraseBatchVertexMemory, 0);
    void* pMapped = 0;
    if (vkMapMemory(pDevice, MaskEraseBatchVertexMemory, 0, bufferSize, 0, &pMapped) != VK_SUCCESS)
    {
        vkFreeMemory(pDevice, MaskEraseBatchVertexMemory, 0);
        vkDestroyBuffer(pDevice, pMaskEraseBatchVertexBuffer, 0);
        pMaskEraseBatchVertexBuffer = VK_NULL_HANDLE;
        MaskEraseBatchVertexMemory = VK_NULL_HANDLE;
        return false;
    }
    fillMaskEraseVertexBuffer<VertexXY32fAlpha>((VertexXY32fAlpha*)pMapped, SF_RENDER_MAX_BATCHES);
    vkUnmapMemory(pDevice, MaskEraseBatchVertexMemory);
    return true;
}

void MeshCache::ClearCache()
{
    CacheList.EvictAll();
    // Release dynamically allocated chunks; keep reserve
    VulkanMeshBuffer* pbuffer = (VulkanMeshBuffer*)Buffers.GetFirst();
    while (!Buffers.IsNull(pbuffer))
    {
        VulkanMeshBuffer* p = pbuffer;
        pbuffer = (VulkanMeshBuffer*)pbuffer->pNext;
        if (p->GetType() == MeshBuffer::AT_Chunk)
            releaseMeshBuffer(p);
    }
    SF_ASSERT(BatchCacheItemHash.GetSize() == 0);
}

bool MeshCache::SetParams(const MeshCacheParams& params)
{
    Params = params;
    return true;
}

void MeshCache::EndFrame()
{
    CacheList.EndFrame();
    CacheList.EvictPendingFree(Allocator);
    destroyPendingBuffers();

    UPInt totalFrameSize = CacheList.GetSlotSize(MCL_PrevFrame);
    UPInt lruTailSize    = CacheList.GetSlotSize(MCL_LRUTail);
    UPInt expectedSize   = totalFrameSize + Alg::PMin(lruTailSize, Params.LRUTailSize);
    expectedSize += expectedSize / 4;

    SPInt extraSpace = (SPInt)TotalSize - (SPInt)expectedSize;
    if (extraSpace > (SPInt)Params.MemGranularity)
    {
        VulkanMeshBuffer* pb = (VulkanMeshBuffer*)Buffers.GetLast();
        while (!Buffers.IsNull(pb) && (extraSpace > (SPInt)Params.MemGranularity))
        {
            VulkanMeshBuffer* prev = (VulkanMeshBuffer*)pb->pPrev;
            if (pb->GetType() == MeshBuffer::AT_Chunk)
            {
                extraSpace -= (SPInt)pb->GetSize();
                bool allEvicted = evictMeshesInBuffer(CacheList.GetSlots(), MCL_ItemCount, pb);
                if (allEvicted)
                {
                    pb->RemoveNode();
                    releaseMeshBuffer(pb);
                }
                else
                {
                    pb->RemoveNode();
                    PendingDestructionBuffers.PushBack(pb);
                }
            }
            pb = prev;
        }
    }
}

void MeshCache::destroyPendingBuffers()
{
    VulkanMeshBuffer* p = (VulkanMeshBuffer*)PendingDestructionBuffers.GetFirst();
    while (!PendingDestructionBuffers.IsNull(p))
    {
        VulkanMeshBuffer* pNext = (VulkanMeshBuffer*)p->pNext;
        MeshCacheListSet::ListSlot& pendingFreeList = CacheList.GetSlot(MCL_PendingFree);
        MeshCacheItem* pitem = (MeshCacheItem*)pendingFreeList.GetFirst();
        bool itemsRemaining = false;
        while (!pendingFreeList.IsNull(pitem))
        {
            if (pitem->pVertexBuffer == p->Buffer || pitem->pIndexBuffer == p->Buffer)
            {
                itemsRemaining = true;
                break;
            }
            pitem = (MeshCacheItem*)pitem->pNext;
        }
        if (!itemsRemaining)
        {
            p->RemoveNode();
            releaseMeshBuffer(p);
        }
        p = pNext;
    }
}

bool MeshCache::evictMeshesInBuffer(MeshCacheListSet::ListSlot* slots, unsigned slotCount, VulkanMeshBuffer* pbuffer)
{
    bool allEvicted = true;
    for (unsigned s = 0; s < slotCount; s++)
    {
        MeshCacheItem* pitem = (MeshCacheItem*)slots[s].GetFirst();
        while (!slots[s].IsNull(pitem))
        {
            MeshCacheItem* pnext = (MeshCacheItem*)pitem->pNext;
            if (pitem->pVertexBuffer == pbuffer->Buffer || pitem->pIndexBuffer == pbuffer->Buffer)
            {
                Evict(pitem, &Allocator);
            }
            pitem = pnext;
        }
    }
    return allEvicted;
}

UPInt MeshCache::Evict(Render::MeshCacheItem* pbatch, AllocAddr* pallocator, MeshBase* pskipMesh)
{
    MeshCacheItem* p = (MeshCacheItem*)pbatch;

    UPInt freedSize = pallocator ? pallocator->Free(p->AllocAddress, p->AllocSize) : Allocator.Free(p->AllocAddress, p->AllocSize);
    p->Destroy(pskipMesh, true);
    return freedSize;
}

bool MeshCache::PreparePrimitive(PrimitiveBatch* pbatch,
                                 MeshCacheItem::MeshContent& mc, bool waitForCache)
{
    Primitive* prim = pbatch->GetPrimitive();

    if (mc.IsLargeMesh())
    {
        SF_ASSERT(mc.GetMeshCount() == 1);
        MeshResult mr = GenerateMesh(mc[0], prim->GetVertexFormat(),
                                     pbatch->pFormat, 0, waitForCache);

        if (mr.Succeded())
            pbatch->SetCacheItem(mc[0]->CacheItems[0]);
        if (mr == MeshResult::Fail_LargeMesh_NeedCache)
            return false;
        return true;
    }

    unsigned totalVertexCount, totalIndexCount;
    pbatch->CalcMeshSizes(&totalVertexCount, &totalIndexCount);
    if (!pbatch->pFormat)
        return false;

    Render::MeshCacheItem* batchData = 0;
    unsigned destVertexSize = pbatch->pFormat->Size;
    UByte* pvertexDataStart = 0;
    IndexType* pindexDataStart = 0;
    AllocResult allocResult = AllocCacheItem(&batchData, &pvertexDataStart, &pindexDataStart,
        MeshCacheItem::Mesh_Regular, mc,
        totalVertexCount * destVertexSize,
        totalVertexCount, totalIndexCount, waitForCache, 0);
    if (allocResult != Alloc_Success)
        return (allocResult == Alloc_Fail) ? false : true;

    pbatch->SetCacheItem(batchData);

    StagingBufferPrep meshPrep(this, mc, prim->GetVertexFormat(), false);
    UByte* pstagingBuffer = StagingBuffer.GetBuffer();
    const VertexFormat* pvf = prim->GetVertexFormat();
    const VertexFormat* pdvf = pbatch->pFormat;
    unsigned indexStart = 0;
    for (unsigned i = 0; i < mc.GetMeshCount(); i++)
    {
        Mesh* pmesh = mc[i];
        if (pmesh->StagingBufferSize == 0)
            continue;
        void* convertArgArray[1] = { &i };
        ConvertVertices_Buffered(*pvf, pstagingBuffer + pmesh->StagingBufferOffset,
            *pdvf, pvertexDataStart, pmesh->VertexCount, &convertArgArray[0]);
        ConvertIndices(pindexDataStart,
            (IndexType*)(pstagingBuffer + pmesh->StagingBufferIndexOffset),
            pmesh->IndexCount, (IndexType)indexStart);
        pvertexDataStart += pmesh->VertexCount * destVertexSize;
        pindexDataStart += pmesh->IndexCount;
        indexStart += pmesh->VertexCount;
    }
    return true;
}

MeshCache::AllocResult MeshCache::AllocCacheItem(Render::MeshCacheItem** pdata,
                                                  UByte** pvertexDataStart, IndexType** pindexDataStart,
                                                  MeshCacheItem::MeshType meshType,
                                                  MeshCacheItem::MeshBaseContent& mc,
                                                  UPInt vertexBufferSize,
                                                  unsigned vertexCount, unsigned indexCount,
                                                  bool waitForCache,
                                                  const VertexFormat* pDestFormat)
{
    (void)pDestFormat;

    UPInt vertexAligned = Alg::Align(vertexBufferSize, VBAlignment);
    UPInt indexAligned = Alg::Align((UPInt)indexCount * sizeof(IndexType), IBAlignment);
    UPInt allocSize = Alg::Align(vertexAligned + indexAligned, BufferAlignment);

    if (allocSize == 0)
        return Alloc_Success;

    UPInt allocAddress;
    if (!allocBuffer(&allocAddress, allocSize, waitForCache))
        return Alloc_Fail;

    VulkanMeshBuffer* pbuffer = findBuffer(allocAddress);
    if (!pbuffer)
        return Alloc_StateError;

    UPInt vbOffset = allocAddress - (UPInt)pbuffer->pData;
    UPInt ibOffset = vbOffset + vertexAligned;

    MeshCacheItem* p = MeshCacheItem::Create(meshType, &CacheList, mc,
        pbuffer->Buffer, pbuffer->Buffer,
        vbOffset, vertexBufferSize, vertexCount,
        ibOffset, indexAligned, indexCount,
        allocAddress, allocSize);
    if (!p)
    {
        Allocator.Free(allocAddress, allocSize);
        return Alloc_StateError;
    }

    *pdata = p;
    *pvertexDataStart = (UByte*)allocAddress;
    *pindexDataStart = (IndexType*)(allocAddress + vertexAligned);
    return Alloc_Success;
}

void MeshCache::GetStats(Stats* stats)
{
    if (!stats)
        return;
    *stats = Stats();
    stats->TotalSize[MeshBuffer_Common] = TotalSize;
    UPInt usedSize = 0;
    for (unsigned i = 0; i < MCL_ItemCount; i++)
        usedSize += CacheList.GetSlotSize((MeshCacheListType)i);
    stats->UsedSize[MeshBuffer_Common] = usedSize;
}

}}} // Scaleform::Render::Vulkan
