/**************************************************************************

Filename    :   Vulkan_MeshCache.h
Content     :   Vulkan mesh cache (scaffold).
Created     :   2025
Authors     :   Vulkan backend

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

**************************************************************************/

#ifndef INC_SF_VULKAN_MESHCACHE_H
#define INC_SF_VULKAN_MESHCACHE_H
#pragma once

#include "Render/Vulkan/Vulkan_Config.h"
#include "Render/Render_MeshCache.h"
#include "Kernel/SF_Array.h"
#include "Kernel/SF_AllocAddr.h"
#include "Kernel/SF_Alg.h"

namespace Scaleform { namespace Render { namespace Vulkan {

class HAL;
class MeshCache;
class ShaderManager;

// Chunk buffer holding both vertex and index data (unified allocation).
class VulkanMeshBuffer : public Render::MeshBuffer
{
public:
    VkBuffer        Buffer;
    VkDeviceMemory  Memory;
    VkDevice        Device;

    VulkanMeshBuffer(UPInt size, AllocType type, unsigned arena);
    virtual ~VulkanMeshBuffer();

    bool Create(VkDevice device, VkPhysicalDevice physicalDevice);
    void Destroy();
};

class MeshCacheItem : public Render::MeshCacheItem
{
    friend class MeshCache;
    friend class HAL;

    VkBuffer    pVertexBuffer;
    VkBuffer    pIndexBuffer;
    UPInt       VBAllocOffset, VBAllocSize;
    UPInt       IBAllocOffset, IBAllocSize;

public:
    UPInt       AllocAddress;   // CPU address for AllocAddr eviction
    UPInt       AllocSize;      // Total allocation size for Evict

    static MeshCacheItem* Create(MeshType type, MeshCacheListSet* pcacheList, MeshBaseContent& mc,
                                 VkBuffer pvb, VkBuffer pib,
                                 UPInt vertexOffset, UPInt vertexAllocSize, unsigned vertexCount,
                                 UPInt indexOffset, UPInt indexAllocSize, unsigned indexCount,
                                 UPInt allocAddress, UPInt allocSize);
};

class MeshCache : public Render::MeshCache
{
    friend class HAL;

    VkDevice            pDevice;
    VkPhysicalDevice    pPhysicalDevice;
    MeshCacheListSet    CacheList;
    AllocAddr           Allocator;
    UPInt               TotalSize;
    List<Render::MeshBuffer> Buffers;

    static const unsigned VBAlignment = 16;
    static const unsigned IBAlignment = 16;
    static const unsigned BufferAlignment = 16;
    static const UPInt MinGranularity = 64 * 1024;

    VkBuffer        pMaskEraseBatchVertexBuffer;
    VkDeviceMemory  MaskEraseBatchVertexMemory;
    List<Render::MeshBuffer> PendingDestructionBuffers;

    bool createMaskEraseBatchVertexBuffer(VkPhysicalDevice physicalDevice);
    VulkanMeshBuffer* allocMeshBuffer(UPInt size, MeshBuffer::AllocType atype, unsigned arena = 0);
    void releaseMeshBuffer(VulkanMeshBuffer* pbuffer);
    bool allocBuffer(UPInt* pallocAddress, UPInt size, bool waitForCache);
    VulkanMeshBuffer* findBuffer(UPInt address);
    void destroyPendingBuffers();
    bool evictMeshesInBuffer(MeshCacheListSet::ListSlot* slots, unsigned slotCount, VulkanMeshBuffer* pbuffer);

    inline MeshCache* getThis() { return this; }

public:
    MeshCache(MemoryHeap* pheap, const MeshCacheParams& params);
    virtual ~MeshCache();

    bool Initialize(VkDevice device, VkPhysicalDevice physicalDevice);
    void Reset();

    virtual QueueMode GetQueueMode() const override { return QM_ExtendLocks; }
    virtual bool    LockBuffers() override { return true; }
    virtual void    UnlockBuffers() override { }
    virtual bool    AreBuffersLocked() const override { return false; }
    virtual void    ClearCache() override;
    virtual bool    SetParams(const MeshCacheParams& params) override;
    virtual void    EndFrame() override;
    virtual UPInt   Evict(Render::MeshCacheItem* p, AllocAddr* pallocator = 0, MeshBase* pskipMesh = 0) override;
    virtual bool    PreparePrimitive(PrimitiveBatch* pbatch,
                                     MeshCacheItem::MeshContent& mc, bool waitForCache) override;
    virtual AllocResult AllocCacheItem(Render::MeshCacheItem** pdata,
                                      UByte** pvertexDataStart, IndexType** pindexDataStart,
                                      MeshCacheItem::MeshType meshType,
                                      MeshCacheItem::MeshBaseContent& mc,
                                      UPInt vertexBufferSize,
                                      unsigned vertexCount, unsigned indexCount,
                                      bool waitForCache,
                                      const VertexFormat* pDestFormat) override;

    virtual void    GetStats(Stats* stats) override;
    MeshCacheListSet& GetCacheList() { return CacheList; }
};

}}} // Scaleform::Render::Vulkan

#endif // INC_SF_VULKAN_MESHCACHE_H
