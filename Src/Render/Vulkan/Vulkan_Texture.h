/**************************************************************************

Filename    :   Vulkan_Texture.h
Content     :   Vulkan texture and texture manager (scaffold).
Created     :   2025
Authors     :   Vulkan backend

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

**************************************************************************/

#ifndef INC_SF_VULKAN_TEXTURE_H
#define INC_SF_VULKAN_TEXTURE_H
#pragma once

#include "Render/Vulkan/Vulkan_Config.h"
#include "Kernel/SF_List.h"
#include "Render/Render_Image.h"

namespace Scaleform { namespace Render { namespace Vulkan {

struct TextureFormat : public Render::TextureFormat
{
    ImageFormat Format;
    Image::CopyScanlineFunc CopyFn;

    TextureFormat(ImageFormat fmt, Image::CopyScanlineFunc copyFn = 0) : Format(fmt), CopyFn(copyFn) {}
    virtual ImageFormat GetImageFormat() const { return Format; }
    virtual Image::CopyScanlineFunc GetScanlineCopyFn() const { return CopyFn; }
    virtual Image::CopyScanlineFunc GetScanlineUncopyFn() const { return 0; }
};

class Texture : public Render::Texture
{
public:
    struct HWTextureDesc
    {
        ImageSize      Size;
        VkImage        Image;
        VkImageView    View;
        VkDeviceMemory Memory;
    };

    HWTextureDesc Texture0;
    bool          LayoutShaderReadReady;  // True after first transition to SHADER_READ_ONLY_OPTIMAL

    Texture(TextureManagerLocks* pmanagerLocks, const TextureFormat* pformat, unsigned mipLevels,
            const ImageSize& size, unsigned use, ImageBase* pimage);
    ~Texture();

    virtual ImageSize       GetTextureSize(unsigned plane = 0) const;
    Render::TextureManager* GetManager() const;
    bool                    IsValid() const;

    bool                    Initialize();
    void                    ReleaseHWTextures(bool staging = true);

    void                    ApplyTexture(unsigned stageIndex, const ImageFillMode& fm);

    virtual Image*          GetImage() const;
    virtual ImageFormat     GetFormat() const;
    virtual bool            Update(const UpdateDesc* updates, unsigned count = 1, unsigned mipLevel = 0);
    virtual void            uploadImage(ImageData* psource);

protected:
    virtual void            computeUpdateConvertRescaleFlags(bool rescale, bool swMipGen, ImageFormat inputFormat,
                                                             ImageRescaleType& rescaleType, ImageFormat& rescaleBuffFormat, bool& convert);
};

class TextureManager : public Render::TextureManager
{
    VkDevice         pDevice;
    VkPhysicalDevice pPhysicalDevice;
    VkQueue          pQueue;
    unsigned         QueueFamilyIndex;
    VkCommandPool    pCommandPool;

public:
    TextureManager(VkDevice device, VkPhysicalDevice physicalDevice, VkQueue queue, unsigned queueFamilyIndex,
                   ThreadId renderThreadId = 0, ThreadCommandQueue* commandQueue = 0,
                   TextureCache* texCache = 0);
    ~TextureManager();

    void Reset();

    virtual void            BeginScene();

    virtual Render::Texture* CreateTexture(ImageFormat format, unsigned mipLevels, const ImageSize& size,
                                           unsigned use, ImageBase* pimage = 0,
                                           Render::MemoryManager* manager = 0);
    virtual unsigned        GetTextureUseCaps(ImageFormat format);
    virtual Render::DepthStencilSurface* CreateDepthStencilSurface(const ImageSize& size,
                                                                   MemoryManager* manager = 0);
    virtual bool            IsDrawableImageFormat(ImageFormat format) const;

    virtual Render::MappedTextureBase& getDefaultMappedTexture();
    virtual Render::MappedTextureBase* createMappedTexture();

    VkDevice         GetDevice() const { return pDevice; }
    VkPhysicalDevice GetPhysicalDevice() const { return pPhysicalDevice; }
    VkQueue          GetQueue() const { return pQueue; }
    unsigned         GetQueueFamilyIndex() const { return QueueFamilyIndex; }
    VkCommandPool    GetCommandPool() const { return pCommandPool; }

    void SetTextureView(unsigned stage, VkImageView view, ImageFillMode fm);
    VkImageView GetCurrentTextureView(unsigned stage) const;
    ImageFillMode GetCurrentFillMode(unsigned stage) const;
    void ClearCurrentTextureViews();

    static const unsigned MaxTextureStages = 4;

protected:
    virtual const Render::TextureFormat* getTextureFormat(ImageFormat format) const;

private:
    VkImageView   CurrentTextureView[MaxTextureStages];
    ImageFillMode CurrentFillMode[MaxTextureStages];
};

// Vulkan DepthStencilSurface for render targets that need depth/stencil.
class DepthStencilSurface : public Render::DepthStencilSurface
{
public:
    VkImage        Image;
    VkImageView   View;
    VkDeviceMemory Memory;

    DepthStencilSurface(TextureManagerLocks* pmanagerLocks, const ImageSize& size);
    virtual ~DepthStencilSurface();
    virtual bool Initialize();

    VkImageView GetView() const { return View; }
};

// Vulkan MappedTexture (implements MappedTextureBase for Map/Unmap).
class MappedTexture : public Render::MappedTextureBase
{
public:
    MappedTexture() : Render::MappedTextureBase(), StagingBuffer(VK_NULL_HANDLE), StagingMemory(VK_NULL_HANDLE), pMappedPtr(0) {}

    virtual bool Map(Render::Texture* ptexture, unsigned mipLevel, unsigned levelCount);
    virtual void Unmap(bool applyUpdate = true);

private:
    VkBuffer       StagingBuffer;
    VkDeviceMemory StagingMemory;
    void*          pMappedPtr;
};

}}} // Scaleform::Render::Vulkan

#endif // INC_SF_VULKAN_TEXTURE_H
