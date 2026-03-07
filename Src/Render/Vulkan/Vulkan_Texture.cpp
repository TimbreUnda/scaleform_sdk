/**************************************************************************

Filename    :   Vulkan_Texture.cpp
Content     :   Vulkan texture and texture manager (scaffold).
Created     :   2025
Authors     :   Vulkan backend

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

**************************************************************************/

#include "Render/Vulkan/Vulkan_Texture.h"
#include "Kernel/SF_Debug.h"
#include "Kernel/SF_HeapNew.h"
#include "Render/Render_ResizeImage.h"
#include "Render/Render_TextureUtil.h"

namespace Scaleform { namespace Render { namespace Vulkan {

static VkFormat GetVkFormat(ImageFormat format)
{
    switch (format)
    {
    case Image_R8G8B8A8: return VK_FORMAT_R8G8B8A8_UNORM;
    case Image_B8G8R8A8: return VK_FORMAT_B8G8R8A8_UNORM;
    case Image_A8:       return VK_FORMAT_R8_UNORM;
    default:             return VK_FORMAT_UNDEFINED;
    }
}

static uint32_t GetMemoryTypeIndex(VkPhysicalDevice physicalDevice, uint32_t typeBits, VkMemoryPropertyFlags properties)
{
    VkPhysicalDeviceMemoryProperties memProps;
    vkGetPhysicalDeviceMemoryProperties(physicalDevice, &memProps);
    for (uint32_t i = 0; i < memProps.memoryTypeCount; i++)
    {
        if ((typeBits & (1u << i)) && (memProps.memoryTypes[i].propertyFlags & properties) == properties)
            return i;
    }
    return (uint32_t)-1;
}

static VkFormat pickDepthStencilFormat(VkPhysicalDevice pd)
{
    VkFormat candidates[] = { VK_FORMAT_D24_UNORM_S8_UINT, VK_FORMAT_D32_SFLOAT_S8_UINT };
    for (VkFormat f : candidates)
    {
        VkFormatProperties p = {};
        vkGetPhysicalDeviceFormatProperties(pd, f, &p);
        if ((p.optimalTilingFeatures & VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT) != 0)
            return f;
    }
    return VK_FORMAT_D32_SFLOAT_S8_UINT;
}

Texture::Texture(TextureManagerLocks* pmanagerLocks, const TextureFormat* pformat, unsigned mipLevels,
                 const ImageSize& size, unsigned use, ImageBase* pimage)
    : Render::Texture(pmanagerLocks, size, (UByte)mipLevels, (UInt16)use, pimage, pformat)
{
    Texture0.Size = size;
    Texture0.Image = VK_NULL_HANDLE;
    Texture0.View = VK_NULL_HANDLE;
    Texture0.Memory = VK_NULL_HANDLE;
    LayoutShaderReadReady = false;
}

Texture::~Texture()
{
    ReleaseHWTextures(true);
}

ImageSize Texture::GetTextureSize(unsigned plane) const
{
    (void)plane;
    return Texture0.Size;
}

Render::TextureManager* Texture::GetManager() const
{
    return pManagerLocks ? pManagerLocks->pManager : 0;
}

bool Texture::IsValid() const
{
    return State != State_InitFailed && State != State_Dead;
}

bool Texture::Initialize()
{
    TextureManager* pmgr = (TextureManager*)GetManager();
    if (!pmgr || !Texture0.Size.Width || !Texture0.Size.Height)
    {
        State = State_Valid;
        return true;
    }
    VkDevice device = pmgr->GetDevice();
    VkPhysicalDevice physicalDevice = pmgr->GetPhysicalDevice();
    VkFormat vkFormat = GetVkFormat(GetFormat());
    if (vkFormat == VK_FORMAT_UNDEFINED)
    {
        State = State_InitFailed;
        return false;
    }

    VkImageCreateInfo imgInfo = {};
    imgInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    imgInfo.imageType = VK_IMAGE_TYPE_2D;
    imgInfo.format = vkFormat;
    imgInfo.extent.width = Texture0.Size.Width;
    imgInfo.extent.height = Texture0.Size.Height;
    imgInfo.extent.depth = 1;
    imgInfo.mipLevels = MipLevels;
    imgInfo.arrayLayers = 1;
    imgInfo.samples = VK_SAMPLE_COUNT_1_BIT;
    imgInfo.tiling = VK_IMAGE_TILING_OPTIMAL;
    imgInfo.usage = VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
    imgInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
    imgInfo.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;

    if (vkCreateImage(device, &imgInfo, 0, &Texture0.Image) != VK_SUCCESS)
    {
        State = State_InitFailed;
        return false;
    }

    VkMemoryRequirements memReq;
    vkGetImageMemoryRequirements(device, Texture0.Image, &memReq);
    uint32_t memTypeIndex = GetMemoryTypeIndex(physicalDevice, memReq.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    if (memTypeIndex == (uint32_t)-1)
    {
        vkDestroyImage(device, Texture0.Image, 0);
        Texture0.Image = VK_NULL_HANDLE;
        State = State_InitFailed;
        return false;
    }

    VkMemoryAllocateInfo allocInfo = {};
    allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocInfo.allocationSize = memReq.size;
    allocInfo.memoryTypeIndex = memTypeIndex;

    if (vkAllocateMemory(device, &allocInfo, 0, &Texture0.Memory) != VK_SUCCESS)
    {
        vkDestroyImage(device, Texture0.Image, 0);
        Texture0.Image = VK_NULL_HANDLE;
        State = State_InitFailed;
        return false;
    }
    vkBindImageMemory(device, Texture0.Image, Texture0.Memory, 0);

    VkImageViewCreateInfo viewInfo = {};
    viewInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
    viewInfo.image = Texture0.Image;
    viewInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
    viewInfo.format = vkFormat;
    viewInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    viewInfo.subresourceRange.baseMipLevel = 0;
    viewInfo.subresourceRange.levelCount = MipLevels;
    viewInfo.subresourceRange.baseArrayLayer = 0;
    viewInfo.subresourceRange.layerCount = 1;

    if (vkCreateImageView(device, &viewInfo, 0, &Texture0.View) != VK_SUCCESS)
    {
        vkFreeMemory(device, Texture0.Memory, 0);
        vkDestroyImage(device, Texture0.Image, 0);
        Texture0.Image = VK_NULL_HANDLE;
        Texture0.Memory = VK_NULL_HANDLE;
        State = State_InitFailed;
        return false;
    }

    State = State_Valid;
    return Render::Texture::Initialize();
}

void Texture::ReleaseHWTextures(bool staging)
{
    (void)staging;
    TextureManager* pmgr = (TextureManager*)GetManager();
    if (pmgr)
    {
        VkDevice device = pmgr->GetDevice();
        if (Texture0.View != VK_NULL_HANDLE)
        {
            vkDestroyImageView(device, Texture0.View, 0);
            Texture0.View = VK_NULL_HANDLE;
        }
        if (Texture0.Image != VK_NULL_HANDLE)
        {
            vkDestroyImage(device, Texture0.Image, 0);
            Texture0.Image = VK_NULL_HANDLE;
        }
        if (Texture0.Memory != VK_NULL_HANDLE)
        {
            vkFreeMemory(device, Texture0.Memory, 0);
            Texture0.Memory = VK_NULL_HANDLE;
        }
        LayoutShaderReadReady = false;
    }
}

void Texture::ApplyTexture(unsigned stageIndex, const ImageFillMode& fm)
{
    Render::Texture::ApplyTexture(stageIndex, fm);
    TextureManager* pmgr = (TextureManager*)GetManager();
    if (pmgr && stageIndex < TextureManager::MaxTextureStages && Texture0.View != VK_NULL_HANDLE)
        pmgr->SetTextureView(stageIndex, Texture0.View, fm);
}

Image* Texture::GetImage() const
{
    return pImage && pImage->GetImageType() != Image::Type_ImageBase ? (Image*)pImage : 0;
}

ImageFormat Texture::GetFormat() const
{
    return pFormat ? ((const TextureFormat*)pFormat)->GetImageFormat() : Image_None;
}

bool Texture::Update(const UpdateDesc* updates, unsigned count, unsigned mipLevel)
{
    if (!updates || count == 0 || Texture0.Image == VK_NULL_HANDLE)
        return true;
    TextureManager* pmgr = (TextureManager*)GetManager();
    if (!pmgr)
        return false;
    VkDevice device = pmgr->GetDevice();
    VkQueue queue = pmgr->GetQueue();
    VkCommandPool cmdPool = pmgr->GetCommandPool();
    if (queue == VK_NULL_HANDLE || cmdPool == VK_NULL_HANDLE)
        return false;
    const unsigned bpp = (GetFormat() == Image_A8) ? 1 : 4;
    VkDeviceSize maxStagingSize = 0;
    for (unsigned i = 0; i < count; i++)
    {
        const UpdateDesc& d = updates[i];
        unsigned w = d.DestRect.Width(), h = d.DestRect.Height();
        VkDeviceSize size = (VkDeviceSize)w * h * bpp;
        if (size > maxStagingSize)
            maxStagingSize = size;
    }
    if (maxStagingSize == 0)
        return true;
    VkBuffer stagingBuffer = VK_NULL_HANDLE;
    VkDeviceMemory stagingMemory = VK_NULL_HANDLE;
    VkBufferCreateInfo bufInfo = {};
    bufInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    bufInfo.size = maxStagingSize;
    bufInfo.usage = VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
    bufInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
    if (vkCreateBuffer(device, &bufInfo, 0, &stagingBuffer) != VK_SUCCESS)
        return false;
    VkMemoryRequirements memReq;
    vkGetBufferMemoryRequirements(device, stagingBuffer, &memReq);
    uint32_t memTypeIndex = GetMemoryTypeIndex(pmgr->GetPhysicalDevice(), memReq.memoryTypeBits,
        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
    if (memTypeIndex == (uint32_t)-1)
    {
        vkDestroyBuffer(device, stagingBuffer, 0);
        return false;
    }
    VkMemoryAllocateInfo allocInfo = {};
    allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocInfo.allocationSize = memReq.size;
    allocInfo.memoryTypeIndex = memTypeIndex;
    if (vkAllocateMemory(device, &allocInfo, 0, &stagingMemory) != VK_SUCCESS)
    {
        vkDestroyBuffer(device, stagingBuffer, 0);
        return false;
    }
    vkBindBufferMemory(device, stagingBuffer, stagingMemory, 0);
    void* mapped = 0;
    if (vkMapMemory(device, stagingMemory, 0, maxStagingSize, 0, &mapped) != VK_SUCCESS)
    {
        vkFreeMemory(device, stagingMemory, 0);
        vkDestroyBuffer(device, stagingBuffer, 0);
        return false;
    }
    VkCommandBufferAllocateInfo cmdAlloc = {};
    cmdAlloc.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    cmdAlloc.commandPool = cmdPool;
    cmdAlloc.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    cmdAlloc.commandBufferCount = 1;
    VkCommandBuffer cmd = VK_NULL_HANDLE;
    if (vkAllocateCommandBuffers(device, &cmdAlloc, &cmd) != VK_SUCCESS)
    {
        vkUnmapMemory(device, stagingMemory);
        vkFreeMemory(device, stagingMemory, 0);
        vkDestroyBuffer(device, stagingBuffer, 0);
        return false;
    }
    VkCommandBufferBeginInfo beginInfo = {};
    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
    vkBeginCommandBuffer(cmd, &beginInfo);
    const bool wasReady = LayoutShaderReadReady;
    VkImageMemoryBarrier barrier = {};
    barrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
    barrier.oldLayout = wasReady ? VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL : VK_IMAGE_LAYOUT_UNDEFINED;
    barrier.newLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
    barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    barrier.image = Texture0.Image;
    barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    barrier.subresourceRange.baseMipLevel = mipLevel;
    barrier.subresourceRange.levelCount = 1;
    barrier.subresourceRange.baseArrayLayer = 0;
    barrier.subresourceRange.layerCount = 1;
    barrier.srcAccessMask = wasReady ? VK_ACCESS_SHADER_READ_BIT : 0;
    barrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
    VkPipelineStageFlags srcStage = wasReady ? VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT : VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
    vkCmdPipelineBarrier(cmd, srcStage, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, 0, 0, 0, 1, &barrier);
    const TextureFormat* pfmt = (const TextureFormat*)pFormat;
    Image::CopyScanlineFunc copyFn = pfmt ? pfmt->GetScanlineCopyFn() : 0;
    if (!copyFn)
        copyFn = &Image::CopyScanlineDefault;
    for (unsigned i = 0; i < count; i++)
    {
        const UpdateDesc& d = updates[i];
        unsigned w = d.DestRect.Width(), h = d.DestRect.Height();
        ImagePlane srcPlane(d.SourcePlane);
        srcPlane.SetSize(w, h);
        UByte* dstRow = (UByte*)mapped;
        const unsigned dstPitch = w * bpp;
        for (unsigned y = 0; y < h; y++)
        {
            const UByte* srcRow = srcPlane.GetScanline(y);
            copyFn(dstRow, srcRow, (UPInt)(w * bpp), 0, 0);
            dstRow += dstPitch;
        }
        VkBufferImageCopy region = {};
        region.bufferOffset = 0;
        region.bufferRowLength = w;
        region.bufferImageHeight = h;
        region.imageSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        region.imageSubresource.mipLevel = mipLevel;
        region.imageSubresource.baseArrayLayer = 0;
        region.imageSubresource.layerCount = 1;
        region.imageOffset.x = (int32_t)d.DestRect.x1;
        region.imageOffset.y = (int32_t)d.DestRect.y1;
        region.imageOffset.z = 0;
        region.imageExtent.width = w;
        region.imageExtent.height = h;
        region.imageExtent.depth = 1;
        vkCmdCopyBufferToImage(cmd, stagingBuffer, Texture0.Image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &region);
    }
    barrier.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
    barrier.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
    barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
    barrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
    vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0, 0, 0, 0, 0, 1, &barrier);
    vkEndCommandBuffer(cmd);
    VkFence fence = VK_NULL_HANDLE;
    VkFenceCreateInfo fenceInfo = {};
    fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    if (vkCreateFence(device, &fenceInfo, 0, &fence) != VK_SUCCESS)
    {
        vkFreeCommandBuffers(device, cmdPool, 1, &cmd);
        vkUnmapMemory(device, stagingMemory);
        vkFreeMemory(device, stagingMemory, 0);
        vkDestroyBuffer(device, stagingBuffer, 0);
        return false;
    }
    VkSubmitInfo submit = {};
    submit.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submit.commandBufferCount = 1;
    submit.pCommandBuffers = &cmd;
    vkQueueSubmit(queue, 1, &submit, fence);
    vkWaitForFences(device, 1, &fence, VK_TRUE, (uint64_t)-1);
    vkDestroyFence(device, fence, 0);
    vkFreeCommandBuffers(device, cmdPool, 1, &cmd);
    vkUnmapMemory(device, stagingMemory);
    vkFreeMemory(device, stagingMemory, 0);
    vkDestroyBuffer(device, stagingBuffer, 0);
    LayoutShaderReadReady = true;
    return true;
}

void Texture::uploadImage(ImageData* psource)
{
    if (!psource || Texture0.Image == VK_NULL_HANDLE)
        return;
    TextureManager* pmgr = (TextureManager*)GetManager();
    if (!pmgr)
        return;
    VkDevice device = pmgr->GetDevice();
    VkPhysicalDevice physicalDevice = pmgr->GetPhysicalDevice();
    VkQueue queue = pmgr->GetQueue();
    VkCommandPool cmdPool = pmgr->GetCommandPool();
    if (queue == VK_NULL_HANDLE || cmdPool == VK_NULL_HANDLE)
        return;

    ImagePlane plane;
    psource->GetPlane(0, &plane);
    if (!plane.pData || plane.Width == 0 || plane.Height == 0)
        return;

    const unsigned bytesPerPixel = (GetFormat() == Image_A8) ? 1 : 4;
    const unsigned rowBytes = Texture0.Size.Width * bytesPerPixel;
    VkDeviceSize bufferSize = (VkDeviceSize)rowBytes * Texture0.Size.Height;

    VkBuffer stagingBuffer = VK_NULL_HANDLE;
    VkDeviceMemory stagingMemory = VK_NULL_HANDLE;

    VkBufferCreateInfo bufInfo = {};
    bufInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    bufInfo.size = bufferSize;
    bufInfo.usage = VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
    bufInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
    if (vkCreateBuffer(device, &bufInfo, 0, &stagingBuffer) != VK_SUCCESS)
        return;

    VkMemoryRequirements memReq;
    vkGetBufferMemoryRequirements(device, stagingBuffer, &memReq);
    uint32_t memTypeIndex = GetMemoryTypeIndex(physicalDevice, memReq.memoryTypeBits,
        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
    if (memTypeIndex == (uint32_t)-1)
    {
        vkDestroyBuffer(device, stagingBuffer, 0);
        return;
    }

    VkMemoryAllocateInfo allocInfo = {};
    allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocInfo.allocationSize = memReq.size;
    allocInfo.memoryTypeIndex = memTypeIndex;
    if (vkAllocateMemory(device, &allocInfo, 0, &stagingMemory) != VK_SUCCESS)
    {
        vkDestroyBuffer(device, stagingBuffer, 0);
        return;
    }
    vkBindBufferMemory(device, stagingBuffer, stagingMemory, 0);

    void* mapped = 0;
    if (vkMapMemory(device, stagingMemory, 0, bufferSize, 0, &mapped) != VK_SUCCESS)
    {
        vkFreeMemory(device, stagingMemory, 0);
        vkDestroyBuffer(device, stagingBuffer, 0);
        return;
    }
    for (unsigned y = 0; y < plane.Height; y++)
        memcpy((UByte*)mapped + y * rowBytes, plane.GetScanline(y), rowBytes);
    vkUnmapMemory(device, stagingMemory);

    VkCommandBufferAllocateInfo cmdAlloc = {};
    cmdAlloc.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    cmdAlloc.commandPool = cmdPool;
    cmdAlloc.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    cmdAlloc.commandBufferCount = 1;
    VkCommandBuffer cmd = VK_NULL_HANDLE;
    if (vkAllocateCommandBuffers(device, &cmdAlloc, &cmd) != VK_SUCCESS)
    {
        vkFreeMemory(device, stagingMemory, 0);
        vkDestroyBuffer(device, stagingBuffer, 0);
        return;
    }

    VkCommandBufferBeginInfo beginInfo = {};
    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
    vkBeginCommandBuffer(cmd, &beginInfo);

    VkImageMemoryBarrier barrier = {};
    barrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
    barrier.oldLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    barrier.newLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
    barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    barrier.image = Texture0.Image;
    barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    barrier.subresourceRange.baseMipLevel = 0;
    barrier.subresourceRange.levelCount = MipLevels;
    barrier.subresourceRange.baseArrayLayer = 0;
    barrier.subresourceRange.layerCount = 1;
    barrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
    vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, 0, 0, 0, 1, &barrier);

    VkBufferImageCopy region = {};
    region.bufferOffset = 0;
    region.bufferRowLength = 0;
    region.bufferImageHeight = 0;
    region.imageSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    region.imageSubresource.mipLevel = 0;
    region.imageSubresource.baseArrayLayer = 0;
    region.imageSubresource.layerCount = 1;
    region.imageOffset = { 0, 0, 0 };
    region.imageExtent = { Texture0.Size.Width, Texture0.Size.Height, 1 };
    vkCmdCopyBufferToImage(cmd, stagingBuffer, Texture0.Image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &region);

    barrier.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
    barrier.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
    barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
    barrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
    vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0, 0, 0, 0, 0, 1, &barrier);

    vkEndCommandBuffer(cmd);

    VkFence fence = VK_NULL_HANDLE;
    VkFenceCreateInfo fenceInfo = {};
    fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    if (vkCreateFence(device, &fenceInfo, 0, &fence) != VK_SUCCESS)
    {
        vkFreeCommandBuffers(device, cmdPool, 1, &cmd);
        vkFreeMemory(device, stagingMemory, 0);
        vkDestroyBuffer(device, stagingBuffer, 0);
        return;
    }
    VkSubmitInfo submit = {};
    submit.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submit.commandBufferCount = 1;
    submit.pCommandBuffers = &cmd;
    vkQueueSubmit(queue, 1, &submit, fence);
    vkWaitForFences(device, 1, &fence, VK_TRUE, (uint64_t)-1);
    vkDestroyFence(device, fence, 0);
    vkFreeCommandBuffers(device, cmdPool, 1, &cmd);
    vkFreeMemory(device, stagingMemory, 0);
    vkDestroyBuffer(device, stagingBuffer, 0);
    // The image is now in SHADER_READ_ONLY_OPTIMAL; record this so that any
    // subsequent MappedTexture::Unmap() uses the correct oldLayout in its barrier.
    LayoutShaderReadReady = true;
}

void Texture::computeUpdateConvertRescaleFlags(bool rescale, bool swMipGen, ImageFormat inputFormat,
                                                ImageRescaleType& rescaleType, ImageFormat& rescaleBuffFormat, bool& convert)
{
    rescaleBuffFormat = inputFormat;
    rescaleType = ResizeNone;
    convert = false;
    const TextureFormat* pfmt = (const TextureFormat*)pFormat;
    if (!pfmt)
        return;
    ImageFormat texFormat = pfmt->GetImageFormat();
    if (rescale)
    {
        if (texFormat != Image_R8G8B8A8 && texFormat != Image_A8)
            convert = true;
        else if (rescaleType == ResizeNone)
            rescaleType = GetImageFormatRescaleType(inputFormat);
    }
    if (swMipGen)
    {
        if (texFormat != Image_R8G8B8A8 && texFormat != Image_A8)
            convert = true;
    }
}

// TextureManager
static TextureFormat s_R8G8B8A8Format(Image_R8G8B8A8, &Image::CopyScanlineDefault);
static TextureFormat s_B8G8R8A8Format(Image_B8G8R8A8, &Image::CopyScanlineDefault);
static TextureFormat s_A8Format(Image_A8, &Image::CopyScanlineDefault);

void TextureManager::SetTextureView(unsigned stage, VkImageView view, ImageFillMode fm)
{
    if (stage < MaxTextureStages)
    {
        CurrentTextureView[stage] = view;
        CurrentFillMode[stage] = fm;
    }
}

VkImageView TextureManager::GetCurrentTextureView(unsigned stage) const
{
    return (stage < MaxTextureStages) ? CurrentTextureView[stage] : VK_NULL_HANDLE;
}

ImageFillMode TextureManager::GetCurrentFillMode(unsigned stage) const
{
    return (stage < MaxTextureStages) ? CurrentFillMode[stage] : ImageFillMode();
}

void TextureManager::ClearCurrentTextureViews()
{
    for (unsigned i = 0; i < MaxTextureStages; i++)
        CurrentTextureView[i] = VK_NULL_HANDLE;
}

TextureManager::TextureManager(VkDevice device, VkPhysicalDevice physicalDevice, VkQueue queue, unsigned queueFamilyIndex,
                               ThreadId renderThreadId, ThreadCommandQueue* commandQueue,
                               TextureCache* texCache)
    : Render::TextureManager(renderThreadId, commandQueue, texCache)
    , pDevice(device)
    , pPhysicalDevice(physicalDevice)
    , pQueue(queue)
    , QueueFamilyIndex(queueFamilyIndex)
    , pCommandPool(VK_NULL_HANDLE)
{
    for (unsigned i = 0; i < MaxTextureStages; i++)
    {
        CurrentTextureView[i] = VK_NULL_HANDLE;
        CurrentFillMode[i] = ImageFillMode();
    }
    VkCommandPoolCreateInfo poolInfo = {};
    poolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    poolInfo.flags = VK_COMMAND_POOL_CREATE_TRANSIENT_BIT;
    poolInfo.queueFamilyIndex = queueFamilyIndex;
    if (vkCreateCommandPool(device, &poolInfo, 0, &pCommandPool) != VK_SUCCESS)
        pCommandPool = VK_NULL_HANDLE;
}

TextureManager::~TextureManager()
{
    Reset();
}

void TextureManager::Reset()
{
    if (pCommandPool != VK_NULL_HANDLE && pDevice != VK_NULL_HANDLE)
    {
        vkDestroyCommandPool(pDevice, pCommandPool, 0);
        pCommandPool = VK_NULL_HANDLE;
    }
}

void TextureManager::BeginScene()
{
}

Render::Texture* TextureManager::CreateTexture(ImageFormat format, unsigned mipLevels, const ImageSize& size,
                                               unsigned use, ImageBase* pimage, Render::MemoryManager* manager)
{
    (void)manager;
    const Render::TextureFormat* ptformat = precreateTexture(format, use, pimage);
    if (!ptformat) return 0;
    Texture* ptexture = SF_HEAP_AUTO_NEW(this) Texture(pLocks, (const TextureFormat*)ptformat, mipLevels, size, use, pimage);
    return postCreateTexture(ptexture, use);
}

unsigned TextureManager::GetTextureUseCaps(ImageFormat format)
{
    unsigned caps = ImageUse_Wrap | ImageUse_Update | ImageUse_RenderTarget;
    if (!ImageData::IsFormatCompressed(format))
        caps |= ImageUse_PartialUpdate | ImageUse_GenMipmaps;
    const Render::TextureFormat* ptformat = getTextureFormat(format);
    if (ptformat && isScanlineCompatible(ptformat))
        caps |= ImageUse_MapRenderThread;
    return caps;
}

DepthStencilSurface::DepthStencilSurface(TextureManagerLocks* pmanagerLocks, const ImageSize& size)
    : Render::DepthStencilSurface(pmanagerLocks, size)
    , Image(VK_NULL_HANDLE)
    , View(VK_NULL_HANDLE)
    , Memory(VK_NULL_HANDLE)
{
}

DepthStencilSurface::~DepthStencilSurface()
{
    TextureManager* pmgr = (TextureManager*)GetTextureManager();
    if (pmgr)
    {
        VkDevice device = pmgr->GetDevice();
        if (View != VK_NULL_HANDLE)
        {
            vkDestroyImageView(device, View, 0);
            View = VK_NULL_HANDLE;
        }
        if (Image != VK_NULL_HANDLE)
        {
            vkDestroyImage(device, Image, 0);
            Image = VK_NULL_HANDLE;
        }
        if (Memory != VK_NULL_HANDLE)
        {
            vkFreeMemory(device, Memory, 0);
            Memory = VK_NULL_HANDLE;
        }
    }
}

bool DepthStencilSurface::Initialize()
{
    TextureManager* pmgr = (TextureManager*)GetTextureManager();
    if (!pmgr || Size.Width == 0 || Size.Height == 0)
    {
        State = Texture::State_Valid;
        return true;
    }
    VkDevice device = pmgr->GetDevice();
    VkPhysicalDevice physicalDevice = pmgr->GetPhysicalDevice();
    VkFormat format = pickDepthStencilFormat(physicalDevice);
    VkImageCreateInfo imgInfo = {};
    imgInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    imgInfo.imageType = VK_IMAGE_TYPE_2D;
    imgInfo.format = format;
    imgInfo.extent.width = Size.Width;
    imgInfo.extent.height = Size.Height;
    imgInfo.extent.depth = 1;
    imgInfo.mipLevels = 1;
    imgInfo.arrayLayers = 1;
    imgInfo.samples = VK_SAMPLE_COUNT_1_BIT;
    imgInfo.tiling = VK_IMAGE_TILING_OPTIMAL;
    imgInfo.usage = VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT;
    imgInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
    imgInfo.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    if (vkCreateImage(device, &imgInfo, 0, &Image) != VK_SUCCESS)
    {
        State = Texture::State_InitFailed;
        return false;
    }
    VkMemoryRequirements memReq;
    vkGetImageMemoryRequirements(device, Image, &memReq);
    uint32_t memTypeIndex = GetMemoryTypeIndex(physicalDevice, memReq.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    if (memTypeIndex == (uint32_t)-1)
    {
        vkDestroyImage(device, Image, 0);
        Image = VK_NULL_HANDLE;
        State = Texture::State_InitFailed;
        return false;
    }
    VkMemoryAllocateInfo allocInfo = {};
    allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocInfo.allocationSize = memReq.size;
    allocInfo.memoryTypeIndex = memTypeIndex;
    if (vkAllocateMemory(device, &allocInfo, 0, &Memory) != VK_SUCCESS)
    {
        vkDestroyImage(device, Image, 0);
        Image = VK_NULL_HANDLE;
        State = Texture::State_InitFailed;
        return false;
    }
    vkBindImageMemory(device, Image, Memory, 0);
    VkImageViewCreateInfo viewInfo = {};
    viewInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
    viewInfo.image = Image;
    viewInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
    viewInfo.format = format;
    viewInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT;
    viewInfo.subresourceRange.baseMipLevel = 0;
    viewInfo.subresourceRange.levelCount = 1;
    viewInfo.subresourceRange.baseArrayLayer = 0;
    viewInfo.subresourceRange.layerCount = 1;
    if (vkCreateImageView(device, &viewInfo, 0, &View) != VK_SUCCESS)
    {
        vkFreeMemory(device, Memory, 0);
        vkDestroyImage(device, Image, 0);
        Memory = VK_NULL_HANDLE;
        Image = VK_NULL_HANDLE;
        State = Texture::State_InitFailed;
        return false;
    }
    State = Texture::State_Valid;
    return true;
}

Render::DepthStencilSurface* TextureManager::CreateDepthStencilSurface(const ImageSize& size, MemoryManager* manager)
{
    (void)manager;
    if (!pDevice || size.Width == 0 || size.Height == 0)
        return 0;
    DepthStencilSurface* pdss = SF_HEAP_AUTO_NEW(this) DepthStencilSurface(pLocks, size);
    return postCreateDepthStencilSurface(pdss);
}

bool TextureManager::IsDrawableImageFormat(ImageFormat format) const
{
    return format == Image_R8G8B8A8 || format == Image_B8G8R8A8;
}

static MappedTexture s_DefaultMappedTexture;

Render::MappedTextureBase& TextureManager::getDefaultMappedTexture()
{
    return s_DefaultMappedTexture;
}

Render::MappedTextureBase* TextureManager::createMappedTexture()
{
    return SF_HEAP_AUTO_NEW(this) MappedTexture;
}

bool MappedTexture::Map(Render::Texture* ptexture, unsigned mipLevel, unsigned levelCount)
{
    if (!ptexture || IsMapped())
        return false;
    Texture* pvtex = (Texture*)ptexture;
    if (pvtex->Texture0.Image == VK_NULL_HANDLE)
        return false;
    TextureManager* pmgr = (TextureManager*)ptexture->GetTextureManager();
    if (!pmgr)
        return false;
    ImageSize size = pvtex->GetTextureSize(0);
    if (size.Width == 0 || size.Height == 0)
        return false;
    if (levelCount == 0)
        levelCount = ptexture->MipLevels - mipLevel;
    const unsigned bpp = (ptexture->GetFormat() == Image_A8) ? 1 : 4;
    const unsigned rowBytes = size.Width * bpp;
    VkDeviceSize bufferSize = (VkDeviceSize)rowBytes * size.Height;
    VkDevice device = pmgr->GetDevice();
    VkBufferCreateInfo bufInfo = {};
    bufInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    bufInfo.size = bufferSize;
    bufInfo.usage = VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT;
    bufInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
    if (vkCreateBuffer(device, &bufInfo, 0, &StagingBuffer) != VK_SUCCESS)
        return false;
    VkMemoryRequirements memReq;
    vkGetBufferMemoryRequirements(device, StagingBuffer, &memReq);
    uint32_t memTypeIndex = GetMemoryTypeIndex(pmgr->GetPhysicalDevice(), memReq.memoryTypeBits,
        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
    if (memTypeIndex == (uint32_t)-1)
    {
        vkDestroyBuffer(device, StagingBuffer, 0);
        StagingBuffer = VK_NULL_HANDLE;
        return false;
    }
    VkMemoryAllocateInfo allocInfo = {};
    allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocInfo.allocationSize = memReq.size;
    allocInfo.memoryTypeIndex = memTypeIndex;
    if (vkAllocateMemory(device, &allocInfo, 0, &StagingMemory) != VK_SUCCESS)
    {
        vkDestroyBuffer(device, StagingBuffer, 0);
        StagingBuffer = VK_NULL_HANDLE;
        return false;
    }
    vkBindBufferMemory(device, StagingBuffer, StagingMemory, 0);
    if (vkMapMemory(device, StagingMemory, 0, bufferSize, 0, &pMappedPtr) != VK_SUCCESS)
    {
        vkFreeMemory(device, StagingMemory, 0);
        vkDestroyBuffer(device, StagingBuffer, 0);
        StagingMemory = VK_NULL_HANDLE;
        StagingBuffer = VK_NULL_HANDLE;
        return false;
    }
    pTexture = ptexture;
    StartMipLevel = mipLevel;
    LevelCount = (int)levelCount;
    Data.Initialize(ptexture->GetImageFormat(), levelCount, Planes, 1, true);
    Data.SetPlane(0, size, rowBytes, (UPInt)bufferSize, (UByte*)pMappedPtr);
    ptexture->pMap = this;
    return true;
}

void MappedTexture::Unmap(bool applyUpdate)
{
    if (!IsMapped() || !pTexture)
    {
        LevelCount = 0;
        return;
    }
    Texture* pvtex = (Texture*)pTexture;
    TextureManager* pmgr = (TextureManager*)pTexture->GetTextureManager();
    if (!pmgr)
    {
        if (pTexture)
            pTexture->pMap = 0;
        pTexture = 0;
        LevelCount = 0;
        return;
    }
    VkDevice device = pmgr->GetDevice();
    if (pMappedPtr)
    {
        vkUnmapMemory(device, StagingMemory);
        pMappedPtr = 0;
    }
    VkQueue queue = pmgr->GetQueue();
    VkCommandPool cmdPool = pmgr->GetCommandPool();
    if (applyUpdate && StagingBuffer != VK_NULL_HANDLE && queue != VK_NULL_HANDLE && cmdPool != VK_NULL_HANDLE && pvtex->Texture0.Image != VK_NULL_HANDLE)
    {
        ImageSize size = pvtex->GetTextureSize(0);
        const unsigned bpp = (pTexture->GetFormat() == Image_A8) ? 1 : 4;
        VkDeviceSize bufferSize = (VkDeviceSize)size.Width * bpp * size.Height;
        VkCommandBufferAllocateInfo cmdAlloc = {};
        cmdAlloc.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        cmdAlloc.commandPool = cmdPool;
        cmdAlloc.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        cmdAlloc.commandBufferCount = 1;
        VkCommandBuffer cmd = VK_NULL_HANDLE;
        if (vkAllocateCommandBuffers(device, &cmdAlloc, &cmd) == VK_SUCCESS)
        {
            VkCommandBufferBeginInfo beginInfo = {};
            beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
            beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
            vkBeginCommandBuffer(cmd, &beginInfo);
            VkImageMemoryBarrier barrier = {};
            barrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
            barrier.oldLayout = pvtex->LayoutShaderReadReady ? VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL : VK_IMAGE_LAYOUT_UNDEFINED;
            barrier.newLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
            barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            barrier.image = pvtex->Texture0.Image;
            barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
            barrier.subresourceRange.baseMipLevel = 0;
            barrier.subresourceRange.levelCount = 1;
            barrier.subresourceRange.baseArrayLayer = 0;
            barrier.subresourceRange.layerCount = 1;
            barrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
            vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, 0, 0, 0, 1, &barrier);
            VkBufferImageCopy region = {};
            region.bufferOffset = 0;
            region.bufferRowLength = 0;
            region.bufferImageHeight = 0;
            region.imageSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
            region.imageSubresource.mipLevel = 0;
            region.imageSubresource.baseArrayLayer = 0;
            region.imageSubresource.layerCount = 1;
            region.imageOffset = { 0, 0, 0 };
            region.imageExtent = { size.Width, size.Height, 1 };
            vkCmdCopyBufferToImage(cmd, StagingBuffer, pvtex->Texture0.Image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &region);
            barrier.oldLayout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
            barrier.newLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
            barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
            barrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
            vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT, 0, 0, 0, 0, 0, 1, &barrier);
            pvtex->LayoutShaderReadReady = true;
            vkEndCommandBuffer(cmd);
            VkFence fence = VK_NULL_HANDLE;
            VkFenceCreateInfo fenceInfo = {};
            fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
            if (vkCreateFence(device, &fenceInfo, 0, &fence) == VK_SUCCESS)
            {
                VkSubmitInfo submit = {};
                submit.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
                submit.commandBufferCount = 1;
                submit.pCommandBuffers = &cmd;
                vkQueueSubmit(queue, 1, &submit, fence);
                vkWaitForFences(device, 1, &fence, VK_TRUE, (uint64_t)-1);
                vkDestroyFence(device, fence, 0);
            }
            vkFreeCommandBuffers(device, cmdPool, 1, &cmd);
        }
    }
    if (StagingMemory != VK_NULL_HANDLE)
    {
        vkFreeMemory(device, StagingMemory, 0);
        StagingMemory = VK_NULL_HANDLE;
    }
    if (StagingBuffer != VK_NULL_HANDLE)
    {
        vkDestroyBuffer(device, StagingBuffer, 0);
        StagingBuffer = VK_NULL_HANDLE;
    }
    if (pTexture)
        pTexture->pMap = 0;
    pTexture = 0;
    LevelCount = 0;
}

const Render::TextureFormat* TextureManager::getTextureFormat(ImageFormat format) const
{
    if (format == Image_R8G8B8A8)
        return &s_R8G8B8A8Format;
    if (format == Image_B8G8R8A8)
        return &s_B8G8R8A8Format;
    if (format == Image_A8)
        return &s_A8Format;
    return 0;
}

}}} // Scaleform::Render::Vulkan
