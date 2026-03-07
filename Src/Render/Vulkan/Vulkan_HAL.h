/**************************************************************************

Filename    :   Vulkan_HAL.h
Content     :   Vulkan HAL and init params (scaffold).
Created     :   2025
Authors     :   Vulkan backend

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

**************************************************************************/

#ifndef INC_SF_VULKAN_HAL_H
#define INC_SF_VULKAN_HAL_H
#pragma once

#include "Render/Vulkan/Vulkan_Config.h"
#include "Render/Render_HAL.h"
#include "Render/Vulkan/Vulkan_MeshCache.h"
#include "Render/Vulkan/Vulkan_Shader.h"
#include "Render/Vulkan/Vulkan_Texture.h"
#include "Render/Render_ShaderHAL.h"

namespace Scaleform { namespace Render { namespace Vulkan {

struct HALInitParams : public Render::HALInitParams
{
    VkInstance        Instance;
    VkPhysicalDevice  PhysicalDevice;
    VkDevice          Device;
    VkQueue           Queue;
    unsigned          QueueFamilyIndex;
    VkRenderPass      RenderPass;
    VkFormat          ColorFormat;

    HALInitParams(VkInstance instance, VkPhysicalDevice physicalDevice, VkDevice device,
                  VkQueue queue, unsigned queueFamilyIndex,
                  UInt32 halConfigFlags = 0, ThreadId renderThreadId = ThreadId())
        : Render::HALInitParams(0, halConfigFlags, renderThreadId)
        , Instance(instance), PhysicalDevice(physicalDevice), Device(device)
        , Queue(queue), QueueFamilyIndex(queueFamilyIndex)
        , RenderPass(VK_NULL_HANDLE), ColorFormat(VK_FORMAT_UNDEFINED)
    { }
    HALInitParams(VkInstance instance, VkPhysicalDevice physicalDevice, VkDevice device,
                  VkQueue queue, unsigned queueFamilyIndex, VkRenderPass renderPass, VkFormat colorFormat,
                  UInt32 halConfigFlags = 0, ThreadId renderThreadId = ThreadId())
        : Render::HALInitParams(0, halConfigFlags, renderThreadId)
        , Instance(instance), PhysicalDevice(physicalDevice), Device(device)
        , Queue(queue), QueueFamilyIndex(queueFamilyIndex)
        , RenderPass(renderPass), ColorFormat(colorFormat)
    { }

    void SetTextureManager(TextureManager* manager) { pTextureManager = manager; }
    TextureManager* GetTextureManager() const     { return (TextureManager*)pTextureManager.GetPtr(); }
};

class HAL : public Render::ShaderHAL<ShaderManager, ShaderInterface>
{
public:
    VkDevice              pDevice;
    VkPhysicalDevice      pPhysicalDevice;
    VkQueue               pQueue;
    unsigned              QueueFamilyIndex;

    MeshCache              Cache;
    Ptr<TextureManager>    pTextureManager;

    PrimitiveBatch::BatchType PrevBatchType;

    bool StencilChecked;
    bool StencilAvailable;
    bool DepthBufferAvailable;

    BlendMode CurrentBlendMode;
    bool      CurrentSourceAc;

    enum StencilMode
    {
        StencilMode_Disabled = 0,
        StencilMode_WriteMask,
        StencilMode_TestMask,
        StencilMode_ClearMasksAbove,
        StencilMode_Count
    };
    StencilMode     CurrentStencilMode;

    struct MaskStackEntry
    {
        Ptr<MaskPrimitive> pPrimitive;
        bool               OldViewportValid;
        Rect<int>          OldViewRect;
    };
    ArrayLH<MaskStackEntry> MaskStack;
    unsigned                MaskStackTop;
    unsigned                DebugFrame;  // used by GFXVK_DIAG_LOG

    HAL* getThis() { return this; }

public:
    HAL(ThreadCommandQueue* commandQueue = 0);
    virtual ~HAL();

    virtual bool    InitHAL(const Vulkan::HALInitParams& params);
    virtual bool    ShutdownHAL();

    virtual bool    BeginScene() override;
    virtual bool    EndScene() override;
    virtual void    EndDisplay();
    virtual void    beginDisplay(BeginDisplayData* data);
    virtual void    updateViewport();
    virtual void    clearSolidRectangle(const Rect<int>& r, Color color);

    virtual void    Draw(const RenderQueueItem& item);

    virtual void    DrawProcessedPrimitive(Primitive* pprimitive,
                                            PrimitiveBatch* pstart, PrimitiveBatch* pend);
    virtual void    DrawProcessedComplexMeshes(ComplexMesh* complexMesh,
                                               const StrideArray<HMatrix>& matrices);

    virtual void    PushMask_BeginSubmit(MaskPrimitive* primitive);
    virtual void    EndMaskSubmit();
    virtual void    PopMask();

    virtual void    applyBlendModeImpl(BlendMode mode, bool sourceAc = false, bool forceAc = false);

    bool            checkMaskBufferCaps();
    void            applyStencilMode(StencilMode mode, unsigned referenceValue);
    void            drawMaskClearRectangles(const HMatrix* matrices, UPInt count);

    virtual Render::TextureManager* GetTextureManager() const;
    virtual MeshCache&              GetMeshCache();

    // Create a render target from external VkImageViews (e.g. swap chain image). Pass VK_NULL_HANDLE for depthView if no depth.
    virtual RenderTarget* CreateRenderTarget(VkImageView colorView, VkImageView depthView, const ImageSize& size);
    virtual RenderTarget* CreateRenderTarget(Render::Texture* texture, bool needsStencil);
    virtual RenderTarget* CreateTempRenderTarget(const ImageSize& size, bool needsStencil);
    virtual bool          SetRenderTarget(RenderTarget* target, bool setState = 1);
    virtual void          PushRenderTarget(const RectF& frameRect, RenderTarget* prt, unsigned flags = 0);
    virtual void          PopRenderTarget(unsigned flags = 0);

    virtual bool createDefaultRenderBuffer();

    virtual void    MapVertexFormat(PrimitiveFillType fill, const VertexFormat* sourceFormat,
                                    const VertexFormat** single,
                                    const VertexFormat** batch, const VertexFormat** instanced, unsigned = 0);

    VkDevice GetDevice() const { return pDevice; }
    VkRenderPass GetRenderPass() const { return pRenderPass; }
    VkFormat GetColorFormat() const { return pColorFormat; }

    // Optional: set the current frame's command buffer for recording (when HAL implements drawing).
    void BeginFrame(VkCommandBuffer cmd) { pCurrentCommandBuffer = cmd; }
    VkCommandBuffer GetCurrentCommandBuffer() const { return pCurrentCommandBuffer; }

protected:
    VkRenderPass     pRenderPass;
    VkFormat         pColorFormat;
    VkCommandBuffer  pCurrentCommandBuffer;
    virtual void setBatchUnitSquareVertexStream();
    virtual void drawPrimitive(unsigned indexCount, unsigned meshCount);
    virtual void drawScreenQuad();
};

// RenderTargetData for Vulkan (VkImageView for color and optional depth/stencil).
class RenderTargetData : public RenderBuffer::RenderTargetData
{
public:
    friend class HAL;
    VkImageView  pRenderView;
    VkImageView  pDepthView;

    static void UpdateData(RenderBuffer* buffer, VkImageView colorView,
                          DepthStencilBuffer* pdsb, VkImageView depthView);
    virtual ~RenderTargetData();
private:
    RenderTargetData(RenderBuffer* buffer, DepthStencilBuffer* pdsb,
                     VkImageView colorView, VkImageView depthView);
};

}}} // Scaleform::Render::Vulkan

#endif // INC_SF_VULKAN_HAL_H
