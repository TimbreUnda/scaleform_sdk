/**************************************************************************

Filename    :   Vulkan_HAL.cpp
Content     :   Vulkan HAL implementation (scaffold).
Created     :   2025
Authors     :   Vulkan backend

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

**************************************************************************/

#include "Kernel/SF_Debug.h"
#include "Kernel/SF_HeapNew.h"
#include "Render/Vulkan/Vulkan_HAL.h"
#include "Render/Render_BufferGeneric.h"
#include "Render/Render_Vertex.h"

namespace Scaleform { namespace Render { namespace Vulkan {

HAL::HAL(ThreadCommandQueue* commandQueue)
    : Render::ShaderHAL<ShaderManager, ShaderInterface>(commandQueue)
    , pDevice(VK_NULL_HANDLE)
    , pPhysicalDevice(VK_NULL_HANDLE)
    , pQueue(VK_NULL_HANDLE)
    , QueueFamilyIndex(0)
    , pRenderPass(VK_NULL_HANDLE)
    , pColorFormat(VK_FORMAT_UNDEFINED)
    , Cache(Memory::GetGlobalHeap(), MeshCacheParams::PC_Defaults)
    , PrevBatchType(PrimitiveBatch::DP_None)
    , StencilChecked(false)
    , StencilAvailable(false)
    , DepthBufferAvailable(false)
    , CurrentBlendMode(Blend_None)
    , CurrentSourceAc(false)
    , CurrentStencilMode(StencilMode_Disabled)
    , MaskStackTop(0)
    , DebugFrame(0)
    , pCurrentCommandBuffer(VK_NULL_HANDLE)
{
}

HAL::~HAL()
{
    ShutdownHAL();
}

bool HAL::InitHAL(const Vulkan::HALInitParams& params)
{
    if (!initHAL(params))
        return false;

    if (!params.Device || !params.Queue)
        return false;

    pDevice         = params.Device;
    pPhysicalDevice = params.PhysicalDevice;
    pQueue          = params.Queue;
    QueueFamilyIndex = params.QueueFamilyIndex;
    pRenderPass     = params.RenderPass;
    pColorFormat    = params.ColorFormat;

    if (SManager.Initialize(this) && Cache.Initialize(pDevice, pPhysicalDevice))
    {
        if (params.pTextureManager)
            pTextureManager = params.GetTextureManager();
        else
        {
            pTextureManager = *SF_HEAP_AUTO_NEW(this) TextureManager(pDevice, pPhysicalDevice, pQueue, QueueFamilyIndex, params.RenderThreadId, pRTCommandQueue);
            if (!pTextureManager)
            {
                Cache.Reset();
                SManager.Reset();
                return false;
            }
        }

        Matrices = *SF_HEAP_AUTO_NEW(this) MatrixState(this);

        if (params.pRenderBufferManager)
            pRenderBufferManager = params.pRenderBufferManager;
        else
        {
            pRenderBufferManager = *SF_HEAP_AUTO_NEW(this) RenderBufferManagerGeneric(RBGenericImpl::DSSM_Exact);
            if (!pRenderBufferManager || !createDefaultRenderBuffer())
            {
                ShutdownHAL();
                return false;
            }
        }

        if (pTextureManager && pRenderBufferManager)
        {
            HALState |= HS_ModeSet;
            notifyHandlers(HAL_Initialize);
            return true;
        }
    }

    pDevice = VK_NULL_HANDLE;
    pQueue  = VK_NULL_HANDLE;
    return false;
}

bool HAL::ShutdownHAL()
{
    if (!(HALState & HS_ModeSet))
        return true;

    if (!shutdownHAL())
        return false;

    Cache.Reset();
    SManager.Reset();
    if (pTextureManager)
        pTextureManager->Reset();
    pTextureManager = 0;
    pRenderBufferManager = 0;
    Matrices = 0;

    pDevice = VK_NULL_HANDLE;
    pQueue  = VK_NULL_HANDLE;
    HALState &= ~HS_ModeSet;
    notifyHandlers(HAL_Shutdown);
    return true;
}

// Vulkan does not override BeginFrame(); the base Render::HAL::BeginFrame() is used,
// which calls GetRQProcessor().BeginFrame() and thus registers the mesh cache via
// meshCache.SetRQCacheInterface(&Caches). Ensure the app calls BeginFrame() before drawing.
bool HAL::BeginScene()
{
    VKDIAG("VK[F%04u] BeginScene (HALBeginScene)\n", DebugFrame);
    if (!Render::HAL::BeginScene())
        return false;
    SManager.BeginScene();
    ShaderData.BeginScene();
    return true;
}

bool HAL::EndScene()
{
    unsigned f = DebugFrame > 0 ? DebugFrame - 1 : 0;
    VKDIAG("VK[F%04u] EndScene enter (RTstackSz=%u)\n", f, (unsigned)RenderTargetStack.GetSize());
    if (!Render::HAL::EndScene())
    {
        VKDIAG("VK[F%04u] EndScene: base class returned false\n", f);
        return false;
    }
    VKDIAG("VK[F%04u] EndScene after base (Flush done)\n", f);
    SManager.EndScene();
    VKDIAG("VK[F%04u] EndScene after SManager.EndScene\n", f);
    for (UPInt i = 0; i < RenderTargetStack.GetSize(); i++)
    {
        RenderTargetData* phd = (RenderTargetData*)RenderTargetStack[i].pRenderTarget->GetRenderTargetData();
        if (phd && phd->pDepthStencilBuffer)
            pRenderBufferManager->NotifyDepthStencilFrameDone(phd->pDepthStencilBuffer);
    }
    VKDIAG("VK[F%04u] EndScene done\n", f);
    return true;
}

void HAL::EndDisplay()
{
    VKDIAG("VK[F%04u] EndDisplay enter (MaskTop=%u)\n", DebugFrame > 0 ? DebugFrame - 1 : 0, MaskStackTop);
    Flush();
    VKDIAG("VK[F%04u] EndDisplay after Flush\n", DebugFrame > 0 ? DebugFrame - 1 : 0);
    Render::HAL::EndDisplay();
    VKDIAG("VK[F%04u] EndDisplay done\n", DebugFrame > 0 ? DebugFrame - 1 : 0);
}

void HAL::Draw(const RenderQueueItem& item)
{
    Render::HAL::Draw(item);
}

void HAL::beginDisplay(BeginDisplayData* data)
{
    VKDIAG("VK[F%04u] beginDisplay MaskTop=%u\n", DebugFrame, MaskStackTop);
    DebugFrame++;
    StencilChecked  = false;
    StencilAvailable = false;
    DepthBufferAvailable = false;
    HALState &= ~HS_DrawingMask;
    Render::HAL::beginDisplay(data);
    if (pCurrentCommandBuffer)
        applyStencilMode(StencilMode_Disabled, 0);
}

void HAL::updateViewport()
{
    if (!(HALState & HS_ViewValid))
        return;
    if (!pCurrentCommandBuffer)
        return;
    int dx = ViewRect.x1 - VP.Left;
    int dy = ViewRect.y1 - VP.Top;
    CalcHWViewMatrix(0, &Matrices->View2D, ViewRect, dx, dy);
    Matrices->SetUserMatrix(Matrices->User);
    Matrices->ViewRect = ViewRect;
    Matrices->UVPOChanged = true;

    if (!pCurrentCommandBuffer)
        return;
    Rect<int> vpRect;
    if (!(HALState & HS_InRenderTarget))
        vpRect = ViewRect;
    else
        vpRect.SetRect(VP.Left, VP.Top, VP.Left + VP.Width, VP.Top + VP.Height);

    int w = vpRect.Width();
    int h = vpRect.Height();
    if (w < 1) w = 1;
    if (h < 1) h = 1;

    VkViewport viewport = {};
    viewport.x = (float)vpRect.x1;
    viewport.y = (float)vpRect.y1 + (float)h;
    viewport.width = (float)w;
    viewport.height = -(float)h;
    viewport.minDepth = 0.0f;
    viewport.maxDepth = 1.0f;
    vkCmdSetViewport(pCurrentCommandBuffer, 0, 1, &viewport);

    VkRect2D scissor = {};
    scissor.offset.x = vpRect.x1;
    scissor.offset.y = vpRect.y1;
    scissor.extent.width = (uint32_t)w;
    scissor.extent.height = (uint32_t)h;
    vkCmdSetScissor(pCurrentCommandBuffer, 0, 1, &scissor);
}

void HAL::clearSolidRectangle(const Rect<int>& r, Color color)
{
    if (!pCurrentCommandBuffer)
        return;
    int w = r.Width();
    int h = r.Height();
    if (w <= 0 || h <= 0)
        return;
    VkClearAttachment clearAtt = {};
    clearAtt.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    clearAtt.colorAttachment = 0;
    clearAtt.clearValue.color.float32[0] = color.GetRed()   / 255.0f;
    clearAtt.clearValue.color.float32[1] = color.GetGreen() / 255.0f;
    clearAtt.clearValue.color.float32[2] = color.GetBlue()  / 255.0f;
    clearAtt.clearValue.color.float32[3] = color.GetAlpha() / 255.0f;
    VkClearRect clearRect = {};
    clearRect.rect.offset.x = r.x1;
    clearRect.rect.offset.y = r.y1;
    clearRect.rect.extent.width  = (uint32_t)w;
    clearRect.rect.extent.height = (uint32_t)h;
    clearRect.baseArrayLayer = 0;
    clearRect.layerCount = 1;
    vkCmdClearAttachments(pCurrentCommandBuffer, 1, &clearAtt, 1, &clearRect);
}

void HAL::DrawProcessedPrimitive(Primitive* pprimitive,
                                 PrimitiveBatch* pstart, PrimitiveBatch* pend)
{
    VKDIAG("VK[F%04u] DrawProcessedPrimitive enter (meshCount=%u inDisplay=%d)\n",
        DebugFrame > 0 ? DebugFrame - 1 : 0,
        pprimitive ? pprimitive->GetMeshCount() : 0,
        (int)!!(GetHALState() & HS_InDisplay));
    if (!checkState(HS_InDisplay, __FUNCTION__) ||
        !pCurrentCommandBuffer || !pprimitive->GetMeshCount())
        return;

    SF_ASSERT(pend != 0);

    PrimitiveBatch* pbatch = pstart ? pstart : pprimitive->Batches.GetFirst();

    ShaderData.BeginPrimitive();

    while (pbatch != pend)
    {
        MeshCacheItem* pmesh = (MeshCacheItem*)pbatch->GetCacheItem();
        unsigned       meshIndex = pbatch->GetMeshIndex();
        unsigned       batchMeshCount = pbatch->GetMeshCount();

        if (pmesh)
        {
            unsigned fillFlags = FillFlags;
            if (batchMeshCount > 0)
                fillFlags |= pprimitive->Meshes[0].M.Has3D() ? FF_3DProjection : 0;

            SManager.SetPrimitiveFill(pprimitive->pFill, fillFlags, pbatch->Type, pbatch->pFormat, batchMeshCount, Matrices,
                                      &pprimitive->Meshes[meshIndex], &ShaderData);

            VkDeviceSize vbOffset = (VkDeviceSize)pmesh->VBAllocOffset;
            VkBuffer vb = pmesh->pVertexBuffer;
            vkCmdBindVertexBuffers(pCurrentCommandBuffer, 0, 1, &vb, &vbOffset);
            vkCmdBindIndexBuffer(pCurrentCommandBuffer, pmesh->pIndexBuffer, pmesh->IBAllocOffset, VK_INDEX_TYPE_UINT16);

            if (HALState & HS_ViewValid)
            {
                unsigned drawInstances;
                if (pbatch->Type != PrimitiveBatch::DP_Instanced)
                {
                    vkCmdDrawIndexed(pCurrentCommandBuffer, pmesh->IndexCount, 1, 0, 0, 0);
                    drawInstances = 1;
                }
                else
                {
                    vkCmdDrawIndexed(pCurrentCommandBuffer, pmesh->IndexCount, batchMeshCount, 0, 0, 0);
                    drawInstances = batchMeshCount;
                }

                AccumulatedStats.Primitives++;
                AccumulatedStats.Meshes += drawInstances;
                AccumulatedStats.Triangles += pmesh->IndexCount / 3 * drawInstances;
            }

            pmesh->MoveToCacheListFront(MCL_ThisFrame);
        }

        pbatch = pbatch->GetNext();
    }
}

void HAL::DrawProcessedComplexMeshes(ComplexMesh* complexMesh,
                                    const StrideArray<HMatrix>& matrices)
{
    typedef ComplexMesh::FillRecord   FillRecord;
    typedef PrimitiveBatch::BatchType BatchType;

    MeshCacheItem* pmesh = (MeshCacheItem*)complexMesh->GetCacheItem();
    VKDIAG("VK[F%04u] DrawProcessedComplexMeshes enter (hasMesh=%d inDisplay=%d)\n",
        DebugFrame > 0 ? DebugFrame - 1 : 0,
        (int)(pmesh != 0),
        (int)!!(GetHALState() & HS_InDisplay));
    if (!checkState(HS_InDisplay, __FUNCTION__) || !pCurrentCommandBuffer || !pmesh)
        return;

    const FillRecord* fillRecords = complexMesh->GetFillRecords();
    unsigned    fillCount     = complexMesh->GetFillRecordCount();
    unsigned    instanceCount = (unsigned)matrices.GetSize();
    unsigned    indexBufferOffset = (unsigned)(pmesh->IBAllocOffset / sizeof(IndexType));
    BatchType   batchType = PrimitiveBatch::DP_Single;
    unsigned    formatIndex;
    unsigned    maxDrawCount = 1;
    unsigned    vertexBaseIndex = 0;
    unsigned    vertexSize = 0;

    if (instanceCount > 1 && SManager.HasInstancingSupport())
    {
        maxDrawCount = Alg::Min(instanceCount, Cache.GetParams().MaxBatchInstances);
        batchType = PrimitiveBatch::DP_Instanced;
        formatIndex = 1;
    }
    else
    {
        batchType = PrimitiveBatch::DP_Single;
        formatIndex = 0;
    }

    const Matrix2F* textureMatrices = complexMesh->GetFillMatrixCache();
    VkBuffer vb = pmesh->pVertexBuffer;
    vkCmdBindIndexBuffer(pCurrentCommandBuffer, pmesh->pIndexBuffer, 0, VK_INDEX_TYPE_UINT16);

    for (unsigned fillIndex = 0; fillIndex < fillCount; fillIndex++)
    {
        const FillRecord& fr = fillRecords[fillIndex];

        unsigned fillFlags = FillFlags;
        unsigned startIndex = 0;
        if (instanceCount > 0)
        {
            const HMatrix& hm = matrices[0];
            fillFlags |= hm.Has3D() ? FF_3DProjection : 0;

            for (unsigned i = 0; i < instanceCount; i++)
            {
                const HMatrix& hm2 = matrices[startIndex + i];
                if (!(hm2.GetCxform() == Cxform::Identity))
                    fillFlags |= FF_Cxform;
            }
        }

        const VertexFormat* pfmt = fr.pFormats[formatIndex];
        if (!pfmt)
            pfmt = fr.pFormats[0];
        if (!pfmt)
            continue;

        PrimitiveFillType fillType = fr.pFill->GetType();
        const ShaderManager::Shader& pso = SManager.SetFill(fillType, fillFlags, batchType, pfmt, &ShaderData);

        if (pfmt->Size != vertexSize)
        {
            vertexSize      = pfmt->Size;
            vertexBaseIndex = 0;

            VkDeviceSize vbOffset = (VkDeviceSize)(fr.VertexByteOffset + pmesh->VBAllocOffset);
            vkCmdBindVertexBuffers(pCurrentCommandBuffer, 0, 1, &vb, &vbOffset);
        }

        UByte textureCount = fr.pFill->GetTextureCount();
        bool solid = (fillType == PrimFill_None || fillType == PrimFill_Mask || fillType == PrimFill_SolidColor);

        for (unsigned i = 0; i < instanceCount; i++)
        {
            const HMatrix& hm = matrices[startIndex + i];

            ShaderData.SetMatrix(pso, Uniform::SU_mvp, complexMesh->GetVertexMatrix(), hm, Matrices, 0, i % maxDrawCount);
            if (solid)
                ShaderData.SetColor(pso, Uniform::SU_cxmul, fr.pFill->GetSolidColor(), 0, i % maxDrawCount);
            else if (fillFlags & FF_Cxform)
                ShaderData.SetCxform(pso, hm.GetCxform(), 0, i % maxDrawCount);

            for (unsigned tm = 0, stage = 0; tm < textureCount; tm++)
            {
                ShaderData.SetMatrix(pso, Uniform::SU_texgen, textureMatrices[fr.FillMatrixIndex[tm]], tm, i % maxDrawCount);
                Texture* ptex = (Texture*)fr.pFill->GetTexture(tm);
                ShaderData.SetTexture(pso, Uniform::SU_tex, ptex, fr.pFill->GetFillMode(tm), stage);
                stage += ptex->GetPlaneCount();
            }

            bool lastPrimitive = (i == instanceCount - 1);
            if (batchType != PrimitiveBatch::DP_Instanced)
            {
                ShaderData.Finish(1);
                vkCmdDrawIndexed(pCurrentCommandBuffer, fr.IndexCount, 1, fr.IndexOffset + indexBufferOffset, vertexBaseIndex, 0);
                AccumulatedStats.Primitives++;
                AccumulatedStats.Meshes++;
                AccumulatedStats.Triangles += fr.IndexCount / 3;
                if (!lastPrimitive)
                    ShaderData.BeginPrimitive();
            }
            else if (((i + 1) % maxDrawCount == 0 && i != 0) || lastPrimitive)
            {
                unsigned drawCount = maxDrawCount;
                if (lastPrimitive && (i + 1) % maxDrawCount != 0)
                    drawCount = (i + 1) % maxDrawCount;
                ShaderData.Finish(drawCount);
                vkCmdDrawIndexed(pCurrentCommandBuffer, fr.IndexCount, drawCount, fr.IndexOffset + indexBufferOffset, vertexBaseIndex, 0);
                AccumulatedStats.Primitives++;
                AccumulatedStats.Meshes += drawCount;
                AccumulatedStats.Triangles += fr.IndexCount / 3 * drawCount;
                if (!lastPrimitive)
                    ShaderData.BeginPrimitive();
            }
        }

        vertexBaseIndex += fr.VertexCount;
    }

    pmesh->MoveToCacheListFront(MCL_ThisFrame);
}

void HAL::PushMask_BeginSubmit(MaskPrimitive* prim)
{
    if (!checkState(HS_InDisplay, __FUNCTION__))
        return;

    if (!StencilAvailable && !DepthBufferAvailable)
    {
        if (!checkMaskBufferCaps())
            return;
    }

    bool viewportValid = (HALState & HS_ViewValid) != 0;
    unsigned maxStencilValue = MaskStackTop;

    if (MaskStackTop && (MaskStack.GetSize() > MaskStackTop) && viewportValid && StencilAvailable)
    {
        applyStencilMode(StencilMode_ClearMasksAbove, maxStencilValue);
        MaskPrimitive* erasePrim = MaskStack[MaskStackTop].pPrimitive;
        drawMaskClearRectangles(erasePrim->GetMaskAreaMatrices(), erasePrim->GetMaskCount());
    }

    MaskStack.Resize(MaskStackTop + 1);
    MaskStackEntry& e = MaskStack[MaskStackTop];
    e.pPrimitive       = prim;
    e.OldViewportValid = viewportValid;
    e.OldViewRect      = ViewRect;
    unsigned depthBefore = MaskStackTop;
    MaskStackTop++;
    VKDIAG("VK[F%04u] PushMask %u->%u WriteMaskRef=%u\n", DebugFrame > 0 ? DebugFrame - 1 : 0, depthBefore, MaskStackTop, MaskStackTop - 1);
    HALState |= HS_DrawingMask;
    AccumulatedStats.Masks++;

    if (prim->IsClipped() && viewportValid)
    {
        const Matrix2F& m = prim->GetMaskAreaMatrix(0).GetMatrix2D();
        RectF clipBounds(m.Tx(), m.Ty(), m.Tx() + m.Sx(), m.Ty() + m.Sy());
        Rect<int> newViewRect;
        newViewRect.SetRect(
            Alg::Max<int>(ViewRect.x1, (int)clipBounds.x1),
            Alg::Max<int>(ViewRect.y1, (int)clipBounds.y1),
            Alg::Min<int>(ViewRect.x2, (int)ceilf(clipBounds.x2)),
            Alg::Min<int>(ViewRect.y2, (int)ceilf(clipBounds.y2)));

        if (newViewRect.x2 > newViewRect.x1 && newViewRect.y2 > newViewRect.y1)
        {
            ViewRect = newViewRect;
            HALState |= HS_ViewValid;
            updateViewport();
        }
    }

    if (StencilAvailable)
        // Pass MaskStackTop-1 (parent depth) so the EQUAL+INCR pipeline only writes
        // the new depth value inside the parent mask's existing area, matching D3D1x
        // which calls OMSetDepthStencilState(WriteMask, MaskStackTop-1).
        applyStencilMode(StencilMode_WriteMask, MaskStackTop - 1);
}

void HAL::EndMaskSubmit()
{
    if (!checkState(HS_InDisplay | HS_DrawingMask, __FUNCTION__))
        return;
    HALState &= ~HS_DrawingMask;
    SF_ASSERT(MaskStackTop);

    UPInt size = BlendModeStack.GetSize();
    applyBlendMode(size > 0 ? BlendModeStack[size - 1] : Blend_Normal);

    if (StencilAvailable)
        applyStencilMode(StencilMode_TestMask, MaskStackTop);
    VKDIAG("VK[F%04u] EndMaskSubmit TestMaskRef=%u\n", DebugFrame > 0 ? DebugFrame - 1 : 0, MaskStackTop);
}

void HAL::PopMask()
{
    if (!checkState(HS_InDisplay, __FUNCTION__))
        return;

    if (!StencilAvailable && !DepthBufferAvailable)
        return;
    SF_ASSERT(MaskStackTop);
    unsigned depthBefore = MaskStackTop;
    MaskStackTop--;
    VKDIAG("VK[F%04u] PopMask %u->%u\n", DebugFrame > 0 ? DebugFrame - 1 : 0, depthBefore, MaskStackTop);
    if (MaskStack[MaskStackTop].pPrimitive->IsClipped())
    {
        ViewRect = MaskStack[MaskStackTop].OldViewRect;
        if (MaskStack[MaskStackTop].OldViewportValid)
            HALState |= HS_ViewValid;
        else
            HALState &= ~HS_ViewValid;
        updateViewport();
    }

    if (StencilAvailable)
    {
        if (MaskStackTop == 0)
            applyStencilMode(StencilMode_Disabled, 0);
        else
            applyStencilMode(StencilMode_TestMask, MaskStackTop);
    }
}

bool HAL::checkMaskBufferCaps()
{
    if (!StencilChecked)
    {
        StencilChecked = true;
        StencilAvailable = false;
        DepthBufferAvailable = false;

        if (RenderTargetStack.GetSize() > 0)
        {
            RenderTargetData* phd = (RenderTargetData*)RenderTargetStack.Back().pRenderTarget->GetRenderTargetData();
            if (phd && phd->pDepthStencilBuffer)
            {
                StencilAvailable = true;
                DepthBufferAvailable = true;
            }
        }
    }
    if (!StencilAvailable && !DepthBufferAvailable)
    {
        SF_DEBUG_WARNONCE(1, "HAL::PushMask_BeginSubmit used, but stencil is not available");
        return false;
    }
    return true;
}

void HAL::applyStencilMode(StencilMode mode, unsigned referenceValue)
{
    if (!pCurrentCommandBuffer)
        return;
    CurrentStencilMode = mode;
    switch (mode)
    {
    case StencilMode_Disabled:
        vkCmdSetStencilReference(pCurrentCommandBuffer, VK_STENCIL_FACE_FRONT_AND_BACK, 0);
        vkCmdSetStencilWriteMask(pCurrentCommandBuffer, VK_STENCIL_FACE_FRONT_AND_BACK, 0);
        vkCmdSetStencilCompareMask(pCurrentCommandBuffer, VK_STENCIL_FACE_FRONT_AND_BACK, 0);
        break;
    case StencilMode_WriteMask:
        vkCmdSetStencilReference(pCurrentCommandBuffer, VK_STENCIL_FACE_FRONT_AND_BACK, referenceValue);
        vkCmdSetStencilWriteMask(pCurrentCommandBuffer, VK_STENCIL_FACE_FRONT_AND_BACK, 0xFF);
        vkCmdSetStencilCompareMask(pCurrentCommandBuffer, VK_STENCIL_FACE_FRONT_AND_BACK, 0xFF);
        break;
    case StencilMode_TestMask:
        vkCmdSetStencilReference(pCurrentCommandBuffer, VK_STENCIL_FACE_FRONT_AND_BACK, referenceValue);
        vkCmdSetStencilWriteMask(pCurrentCommandBuffer, VK_STENCIL_FACE_FRONT_AND_BACK, 0);
        vkCmdSetStencilCompareMask(pCurrentCommandBuffer, VK_STENCIL_FACE_FRONT_AND_BACK, 0xFF);
        break;
    case StencilMode_ClearMasksAbove:
        vkCmdSetStencilReference(pCurrentCommandBuffer, VK_STENCIL_FACE_FRONT_AND_BACK, referenceValue);
        vkCmdSetStencilWriteMask(pCurrentCommandBuffer, VK_STENCIL_FACE_FRONT_AND_BACK, 0xFF);
        vkCmdSetStencilCompareMask(pCurrentCommandBuffer, VK_STENCIL_FACE_FRONT_AND_BACK, 0xFF);
        break;
    default:
        break;
    }
}

void HAL::drawMaskClearRectangles(const HMatrix* matrices, UPInt count)
{
    if (!pCurrentCommandBuffer || count == 0)
        return;

    // Use vkCmdClearAttachments to directly write the target stencil value into each
    // rectangle. MaskStackTop still holds the "erase-to" value here because it has
    // not been incremented yet when this function is called from PushMask_BeginSubmit.
    VkClearAttachment clearAtt = {};
    clearAtt.aspectMask = VK_IMAGE_ASPECT_STENCIL_BIT;
    clearAtt.clearValue.depthStencil.stencil = MaskStackTop;

    for (UPInt i = 0; i < count; i++)
    {
        const Matrix2F& m = matrices[i].GetMatrix2D();
        float x1 = m.Tx();
        float y1 = m.Ty();
        float x2 = x1 + m.Sx();
        float y2 = y1 + m.Sy();

        if (x2 <= x1 || y2 <= y1)
            continue;

        VkClearRect clearRect = {};
        clearRect.rect.offset.x      = (int32_t)x1;
        clearRect.rect.offset.y      = (int32_t)y1;
        clearRect.rect.extent.width  = (uint32_t)(x2 - x1 + 0.5f);
        clearRect.rect.extent.height = (uint32_t)(y2 - y1 + 0.5f);
        clearRect.baseArrayLayer = 0;
        clearRect.layerCount     = 1;
        vkCmdClearAttachments(pCurrentCommandBuffer, 1, &clearAtt, 1, &clearRect);
    }
}

void HAL::applyBlendModeImpl(BlendMode mode, bool sourceAc, bool forceAc)
{
    CurrentBlendMode = mode;
    CurrentSourceAc = sourceAc;
    (void)forceAc;
    // Pipeline selection (solid vs solid+blend) is done in ShaderInterface::Finish based on CurrentBlendMode.
}

Render::TextureManager* HAL::GetTextureManager() const
{
    return pTextureManager.GetPtr();
}

MeshCache& HAL::GetMeshCache()
{
    return Cache;
}

RenderTargetData::RenderTargetData(RenderBuffer* buffer, DepthStencilBuffer* pdsb,
                                   VkImageView colorView, VkImageView depthView)
    : RenderBuffer::RenderTargetData(buffer, pdsb)
    , pRenderView(colorView)
    , pDepthView(depthView)
{
}

RenderTargetData::~RenderTargetData()
{
}

void RenderTargetData::UpdateData(RenderBuffer* buffer, VkImageView colorView,
                                  DepthStencilBuffer* pdsb, VkImageView depthView)
{
    if (!buffer) return;
    RenderTargetData* pold = (Vulkan::RenderTargetData*)buffer->GetRenderTargetData();
    if (!pold)
    {
        pold = SF_NEW RenderTargetData(buffer, pdsb, colorView, depthView);
        buffer->SetRenderTargetData(pold);
        return;
    }
    if (pdsb)
        pold->pDepthStencilBuffer = pdsb;
    pold->pRenderView = colorView;
    if (depthView)
        pold->pDepthView = depthView;
}

RenderTarget* HAL::CreateRenderTarget(VkImageView colorView, VkImageView depthView, const ImageSize& size)
{
    if (!colorView || size.Width == 0 || size.Height == 0)
        return 0;
    RenderTarget* prt = pRenderBufferManager->CreateRenderTarget(size, RBuffer_User, Image_R8G8B8A8, 0);
    if (!prt) return 0;
    Ptr<DepthStencilBuffer> pdsb = 0;
    if (depthView)
        pdsb = *pRenderBufferManager->CreateDepthStencilBuffer(size);
    RenderTargetData::UpdateData(prt, colorView, pdsb, depthView);
    return prt;
}

RenderTarget* HAL::CreateRenderTarget(Render::Texture* texture, bool needsStencil)
{
    Vulkan::Texture* pt = (Vulkan::Texture*)texture;
    if (!pt || texture->GetTextureStageCount() != 1)
        return 0;
    RenderTarget* prt = pRenderBufferManager->CreateRenderTarget(
        texture->GetSize(), RBuffer_Texture, texture->GetFormat(), texture);
    if (!prt) return 0;
    VkImageView colorView = pt->Texture0.View;
    Ptr<DepthStencilBuffer> pdsb = 0;
    VkImageView depthView = VK_NULL_HANDLE;
    if (needsStencil)
    {
        pdsb = *pRenderBufferManager->CreateDepthStencilBuffer(texture->GetSize());
        if (pdsb && pdsb->GetSurface())
            depthView = ((Vulkan::DepthStencilSurface*)pdsb->GetSurface())->GetView();
    }
    RenderTargetData::UpdateData(prt, colorView, pdsb, depthView);
    return prt;
}

RenderTarget* HAL::CreateTempRenderTarget(const ImageSize& size, bool needsStencil)
{
    RenderTarget* prt = pRenderBufferManager->CreateTempRenderTarget(size);
    if (!prt) return 0;
    Vulkan::Texture* pt = (Vulkan::Texture*)prt->GetTexture();
    VkImageView colorView = pt ? pt->Texture0.View : VK_NULL_HANDLE;
    Ptr<DepthStencilBuffer> pdsb = 0;
    VkImageView depthView = VK_NULL_HANDLE;
    if (needsStencil)
    {
        pdsb = *pRenderBufferManager->CreateDepthStencilBuffer(size);
        if (pdsb && pdsb->GetSurface())
            depthView = ((Vulkan::DepthStencilSurface*)pdsb->GetSurface())->GetView();
    }
    RenderTargetData::UpdateData(prt, colorView, pdsb, depthView);
    return prt;
}

bool HAL::SetRenderTarget(RenderTarget* target, bool setState)
{
    (void)setState;
    if (HALState & HS_InScene)
        Flush();
    if (HALState & HS_InDisplay)
        return false;
    RenderTargetEntry entry;
    entry.pRenderTarget = target;
    if (RenderTargetStack.GetSize() > 0)
        RenderTargetStack[0] = entry;
    else
        RenderTargetStack.PushBack(entry);
    return true;
}

void HAL::PushRenderTarget(const RectF& frameRect, RenderTarget* prt, unsigned flags)
{
    (void)flags;
    HALState |= HS_InRenderTarget;
    RenderTargetEntry entry;
    entry.pRenderTarget = prt;
    entry.OldViewport = VP;
    entry.OldViewRect = ViewRect;
    entry.OldMatrixState.CopyFrom(Matrices);
    if (!prt)
    {
        RenderTargetStack.PushBack(entry);
        return;
    }

    Matrices->Orient2D.SetIdentity();
    Matrices->Orient3D.SetIdentity();
    Matrices->SetUserMatrix(Matrix2F::Identity);
    Rect<int> viewRect = prt->GetRect();
    const ImageSize& bs = prt->GetBufferSize();
    VP = Viewport(bs.Width, bs.Height, viewRect.x1, viewRect.y1, viewRect.Width(), viewRect.Height());
    ViewRect.x1 = (int)frameRect.x1;
    ViewRect.y1 = (int)frameRect.y1;
    ViewRect.x2 = (int)frameRect.x2;
    ViewRect.y2 = (int)frameRect.y2;

    Matrices->ViewRectOriginal.Offset(-entry.OldViewport.Left, -entry.OldViewport.Top);
    Matrices->UVPOChanged = true;
    StencilChecked = false;
    ++AccumulatedStats.RTChanges;
    HALState |= HS_ViewValid;
    updateViewport();

    if ((flags & PRT_NoClear) == 0)
    {
        Rect<int> clearRect(ViewRect.x1, ViewRect.y1, ViewRect.x2, ViewRect.y2);
        clearSolidRectangle(clearRect, Color(0, 0, 0, 0));
    }

    RenderTargetStack.PushBack(entry);
}

void HAL::PopRenderTarget(unsigned flags)
{
    (void)flags;
    RenderTargetEntry& entry = RenderTargetStack.Back();
    RenderTarget* prt = entry.pRenderTarget;

    prt->SetInUse(false);

    if (prt && prt->GetType() == RBuffer_Temporary)
    {
        RenderTargetData* phd = (RenderTargetData*)prt->GetRenderTargetData();
        if (phd)
        {
            phd->pDepthView = VK_NULL_HANDLE;
            phd->pDepthStencilBuffer = 0;
        }
    }

    Matrices->CopyFrom(&entry.OldMatrixState);
    ViewRect = entry.OldViewRect;
    VP = entry.OldViewport;
    RenderTargetStack.PopBack();

    if (RenderTargetStack.GetSize() == 1)
        HALState &= ~HS_InRenderTarget;

    StencilChecked = false;
    HALState |= HS_ViewValid;
    updateViewport();
}

bool HAL::createDefaultRenderBuffer()
{
    ImageSize rtSize(1280, 720);
    return pRenderBufferManager->Initialize(pTextureManager, Image_R8G8B8A8, rtSize);
}

void HAL::MapVertexFormat(PrimitiveFillType fill, const VertexFormat* sourceFormat,
                          const VertexFormat** single,
                          const VertexFormat** batch, const VertexFormat** instanced, unsigned)
{
    SManager.MapVertexFormat(fill, sourceFormat, single, batch, instanced);
}

void HAL::setBatchUnitSquareVertexStream()
{
    if (!pCurrentCommandBuffer || Cache.pMaskEraseBatchVertexBuffer == VK_NULL_HANDLE)
        return;
    VkDeviceSize offset = 0;
    vkCmdBindVertexBuffers(pCurrentCommandBuffer, 0, 1, &Cache.pMaskEraseBatchVertexBuffer, &offset);
}

void HAL::drawPrimitive(unsigned indexCount, unsigned meshCount)
{
    if (!pCurrentCommandBuffer)
        return;
    vkCmdDraw(pCurrentCommandBuffer, indexCount, meshCount, 0, 0);
}

void HAL::drawScreenQuad()
{
    setBatchUnitSquareVertexStream();
    drawPrimitive(6, 1);
}

}}} // Scaleform::Render::Vulkan
