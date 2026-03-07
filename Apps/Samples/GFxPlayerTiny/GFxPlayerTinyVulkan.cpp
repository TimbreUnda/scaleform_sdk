/**************************************************************************

Filename    :   GFxPlayerTinyVulkan.cpp
Content     :   Tiny GFxPlayer sample for Vulkan.
Created     :   2025
Authors     :   Vulkan sample

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/

#define VK_USE_PLATFORM_WIN32_KHR 1

// GFx Includes
#include "GFx_Kernel.h"
#include "GFx.h"
#include "GFx_Renderer_Vulkan.h"

#include "Render/ImageFiles/PNG_ImageFile.h"
#include "Render/ImageFiles/DDS_ImageFile.h"

#include <windows.h>
#include <winuser.h>
#ifndef WM_MOUSEWHEEL
#define WM_MOUSEWHEEL                   0x020A
#define WHEEL_DELTA                     120
#endif

#include <vector>
#include <stdio.h>

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_win32.h>

#include "GFx_FontProvider_Win32.h"

#define FXPLAYER_APP_TITLE  "Scaleform GFxPlayerTinyVulkan" " v" GFX_VERSION_STRING
#define FXPLAYER_FILENAME   "Window.swf"

#define LOG(fmt, ...) do { printf("[GFxVk] " fmt "\n", ##__VA_ARGS__); fflush(stdout); } while(0)

#include "Render/Renderer2D.h"
#include "Render/Render_Buffer.h"
#include "GFx/AS3/AS3_Global.h"

namespace SF = Scaleform;
using namespace Scaleform;
using namespace Render;
using namespace GFx;

// ***** Helpers and command queue

class FxPlayerFSCommandHandler : public FSCommandHandler
{
public:
    virtual void Callback(Movie* pmovie, const char* pcommand, const char* parg)
    {
        SF_UNUSED3(pmovie, pcommand, parg);
    }
};

class FxPlayerThreadCommandQueue : public ThreadCommandQueue
{
public:
    virtual void GetRenderInterfaces(Render::Interfaces* p)
    {
        p->pHAL = pHAL;
        p->pRenderer2D = pR2D;
        p->pTextureManager = pHAL ? pHAL->GetTextureManager() : 0;
        p->RenderThreadID = 0;
    }
    virtual void PushThreadCommand(ThreadCommand* command)
    {
        if (command)
            command->Execute();
    }
    Ptr<Render::Vulkan::HAL> pHAL;
    Renderer2D* pR2D;
};

class GFxPlayerLog : public GFx::Log
{
public:
    virtual void LogMessageVarg(SF::LogMessageId messageId, const char* pfmt, va_list argList)
    {
        SF_UNUSED(messageId);
        vprintf(pfmt, argList);
    }
};

// ***** FxPlayerTiny Vulkan Application Class

class FxPlayerTiny
{
    const char*             pWndClassName;
    HWND                    hWnd;
    HINSTANCE               hInstance;

    // Vulkan state
    VkInstance              vkInstance;
    VkSurfaceKHR            vkSurface;
    VkPhysicalDevice        vkPhysicalDevice;
    VkDevice                vkDevice;
    VkQueue                 vkQueue;
    unsigned                vkQueueFamilyIndex;
    VkSwapchainKHR          vkSwapchain;
    VkFormat                vkSwapchainFormat;
    VkExtent2D              vkSwapchainExtent;
    std::vector<VkImage>            swapchainImages;
    std::vector<VkImageView>        swapchainImageViews;
    VkCommandPool           vkCommandPool;
    std::vector<VkCommandBuffer>    vkCommandBuffers;
    VkRenderPass            vkRenderPass;
    std::vector<VkFramebuffer>      vkFramebuffers;
    VkImage                 vkDepthStencilImage;
    VkDeviceMemory          vkDepthStencilMemory;
    VkImageView             vkDepthStencilView;
    VkSemaphore             vkImageAvailableSemaphore;
    VkSemaphore             vkRenderFinishedSemaphore;
    VkFence                 vkInFlightFence;

    Ptr<MovieDef>           pMovieDef;
    Ptr<Movie>              pMovie;
    Ptr<Render::Vulkan::HAL> pRenderHAL;
    Ptr<Render::Renderer2D> pRenderer;
    ThreadCommandQueue*     pCommandQueue;
    MovieDisplayHandle      hMovieDisplay;

    RenderTarget*           pSwapChainRenderTarget;

    UInt32                  MovieStartTime;
    UInt32                  MovieLastTime;
    float                   ExitTimeout;

    bool                    ControlKeyDown;
    bool                    Paused;

    String                  FileName;
    int                     Width;
    int                     Height;
    bool                    VerboseAction;

public:
    FxPlayerTiny(int argc, char* argv[]);
    ~FxPlayerTiny();

    int     Run();
    void    AdvanceAndDisplay();
    void    Display();

    void    OnKey(unsigned keyCode, bool downFlag);
    void    OnMouse(GFx::Event::EventType eventType, unsigned button, int x, int y);
    void    OnMouseWheel(int zdelta, int x, int y);
    void    HandleKeyEvent(unsigned keyCode, bool downFlag);

    bool    SetupWindow(const String& name);
    bool    CreateVulkanSwapChain();
    bool    CreateVulkanRenderPassAndFramebuffers();
    void    CleanupVulkanSwapChain();

    LRESULT MemberWndProc(UINT msg, WPARAM wParam, LPARAM lParam);
    static LRESULT CALLBACK StaticWindowProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
};

FxPlayerTiny::FxPlayerTiny(int argc, char* argv[])
    : vkInstance(VK_NULL_HANDLE)
    , vkSurface(VK_NULL_HANDLE)
    , vkPhysicalDevice(VK_NULL_HANDLE)
    , vkDevice(VK_NULL_HANDLE)
    , vkQueue(VK_NULL_HANDLE)
    , vkQueueFamilyIndex(0)
    , vkSwapchain(VK_NULL_HANDLE)
    , vkSwapchainFormat(VK_FORMAT_UNDEFINED)
    , vkCommandPool(VK_NULL_HANDLE)
    , vkRenderPass(VK_NULL_HANDLE)
    , vkDepthStencilImage(VK_NULL_HANDLE)
    , vkDepthStencilMemory(VK_NULL_HANDLE)
    , vkDepthStencilView(VK_NULL_HANDLE)
    , vkImageAvailableSemaphore(VK_NULL_HANDLE)
    , vkRenderFinishedSemaphore(VK_NULL_HANDLE)
    , vkInFlightFence(VK_NULL_HANDLE)
    , pSwapChainRenderTarget(0)
    , MovieStartTime(0)
    , MovieLastTime(0)
    , ExitTimeout(0)
    , ControlKeyDown(false)
    , Paused(false)
    , Width(800)
    , Height(600)
    , VerboseAction(false)
{
    pWndClassName = "GFxPlayerTinyVulkan_WindowClass";
    hWnd = 0;
    hInstance = 0;
    pCommandQueue = 0;

    FileName = FXPLAYER_FILENAME;

    for (int i = 1; i < argc; ++i)
    {
        if (argv[i][0] == '-')
        {
            const char* curArg = argv[i] + 1;
            if (_stricmp(curArg, "test") == 0)
                ExitTimeout = 5.f;
        }
        else
            FileName = argv[i];
    }
}

FxPlayerTiny::~FxPlayerTiny()
{
    if (pRenderHAL && pSwapChainRenderTarget)
        pSwapChainRenderTarget = 0; // release ref if any

    if (vkDevice != VK_NULL_HANDLE)
    {
        vkDeviceWaitIdle(vkDevice);
        CleanupVulkanSwapChain();
        if (vkImageAvailableSemaphore != VK_NULL_HANDLE)
            vkDestroySemaphore(vkDevice, vkImageAvailableSemaphore, 0);
        if (vkRenderFinishedSemaphore != VK_NULL_HANDLE)
            vkDestroySemaphore(vkDevice, vkRenderFinishedSemaphore, 0);
        if (vkInFlightFence != VK_NULL_HANDLE)
            vkDestroyFence(vkDevice, vkInFlightFence, 0);
        if (vkCommandPool != VK_NULL_HANDLE)
            vkDestroyCommandPool(vkDevice, vkCommandPool, 0);
        vkDestroyDevice(vkDevice, 0);
        vkDevice = VK_NULL_HANDLE;
    }
    if (vkSurface != VK_NULL_HANDLE && vkInstance != VK_NULL_HANDLE)
    {
        vkDestroySurfaceKHR(vkInstance, vkSurface, 0);
        vkSurface = VK_NULL_HANDLE;
    }
    if (vkInstance != VK_NULL_HANDLE)
    {
        vkDestroyInstance(vkInstance, 0);
        vkInstance = VK_NULL_HANDLE;
    }
    delete pCommandQueue;
    pCommandQueue = 0;
    if (hInstance && pWndClassName)
        UnregisterClass(pWndClassName, hInstance);
}

bool FxPlayerTiny::SetupWindow(const String& name)
{
    LOG("SetupWindow() start");
    hInstance = GetModuleHandle(NULL);
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_OWNDC, StaticWindowProc, 0L, sizeof(FxPlayerTiny*),
                      hInstance, NULL, NULL, NULL, NULL, pWndClassName, NULL };
    if (!RegisterClassEx(&wc))
        { LOG("SetupWindow: RegisterClassEx failed"); return false; }

    RECT r = { 100, 100, 100 + Width, 100 + Height };
    AdjustWindowRect(&r, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, 0);

    hWnd = CreateWindow(pWndClassName, name.ToCStr(),
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
        r.left, r.top, r.right - r.left, r.bottom - r.top,
        GetDesktopWindow(), NULL, wc.hInstance, (LPVOID)this);
    if (!hWnd)
        { LOG("SetupWindow: CreateWindow failed"); return false; }
    LOG("Window created %dx%d", Width, Height);

    // Vulkan instance
    const char* instanceExtensions[] = { VK_KHR_SURFACE_EXTENSION_NAME, VK_KHR_WIN32_SURFACE_EXTENSION_NAME };
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "GFxPlayerTinyVulkan";
    appInfo.applicationVersion = 1;
    appInfo.pEngineName = "Scaleform";
    appInfo.engineVersion = 1;
    appInfo.apiVersion = VK_API_VERSION_1_1;

    VkInstanceCreateInfo instInfo = {};
    instInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instInfo.pApplicationInfo = &appInfo;
    instInfo.enabledExtensionCount = 2;
    instInfo.ppEnabledExtensionNames = instanceExtensions;

    if (vkCreateInstance(&instInfo, 0, &vkInstance) != VK_SUCCESS)
        { LOG("SetupWindow: vkCreateInstance failed"); return false; }
    LOG("Vulkan instance created");

    VkWin32SurfaceCreateInfoKHR surfInfo = {};
    surfInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
    surfInfo.hwnd = hWnd;
    surfInfo.hinstance = hInstance;
    if (vkCreateWin32SurfaceKHR(vkInstance, &surfInfo, 0, &vkSurface) != VK_SUCCESS)
        { LOG("SetupWindow: vkCreateWin32SurfaceKHR failed"); return false; }
    LOG("Vulkan surface created");

    uint32_t devCount = 0;
    vkEnumeratePhysicalDevices(vkInstance, &devCount, 0);
    if (devCount == 0) return false;
    std::vector<VkPhysicalDevice> devices(devCount);
    vkEnumeratePhysicalDevices(vkInstance, &devCount, devices.data());
    vkPhysicalDevice = devices[0];

    uint32_t queueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(vkPhysicalDevice, &queueFamilyCount, 0);
    std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(vkPhysicalDevice, &queueFamilyCount, queueFamilies.data());

    vkQueueFamilyIndex = (unsigned)(-1);
    for (uint32_t i = 0; i < queueFamilyCount; ++i)
    {
        if (queueFamilies[i].queueFlags & VK_QUEUE_GRAPHICS_BIT)
        {
            VkBool32 presentSupport = VK_FALSE;
            vkGetPhysicalDeviceSurfaceSupportKHR(vkPhysicalDevice, i, vkSurface, &presentSupport);
            if (presentSupport) { vkQueueFamilyIndex = i; break; }
        }
    }
    if (vkQueueFamilyIndex == (unsigned)(-1))
        return false;

    float queuePriority = 1.0f;
    VkDeviceQueueCreateInfo queueInfo = {};
    queueInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    queueInfo.queueFamilyIndex = vkQueueFamilyIndex;
    queueInfo.queueCount = 1;
    queueInfo.pQueuePriorities = &queuePriority;

    const char* deviceExtensions[] = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };
    VkDeviceCreateInfo deviceInfo = {};
    deviceInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    deviceInfo.queueCreateInfoCount = 1;
    deviceInfo.pQueueCreateInfos = &queueInfo;
    deviceInfo.enabledExtensionCount = 1;
    deviceInfo.ppEnabledExtensionNames = deviceExtensions;

    if (vkCreateDevice(vkPhysicalDevice, &deviceInfo, 0, &vkDevice) != VK_SUCCESS)
        { LOG("SetupWindow: vkCreateDevice failed"); return false; }
    LOG("Vulkan device created, queue family %u", vkQueueFamilyIndex);

    vkGetDeviceQueue(vkDevice, vkQueueFamilyIndex, 0, &vkQueue);

    if (!CreateVulkanSwapChain())
        { LOG("SetupWindow: CreateVulkanSwapChain failed"); return false; }
    LOG("Swapchain created, %u images", (unsigned)swapchainImages.size());
    if (!CreateVulkanRenderPassAndFramebuffers())
        { LOG("SetupWindow: CreateVulkanRenderPassAndFramebuffers failed"); return false; }
    LOG("Render pass and framebuffers created");

    VkCommandPoolCreateInfo poolInfo = {};
    poolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    poolInfo.queueFamilyIndex = vkQueueFamilyIndex;
    poolInfo.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    if (vkCreateCommandPool(vkDevice, &poolInfo, 0, &vkCommandPool) != VK_SUCCESS)
        { LOG("SetupWindow: vkCreateCommandPool failed"); return false; }

    vkCommandBuffers.resize(swapchainImageViews.size());
    if (!vkCommandBuffers.empty())
    {
        VkCommandBufferAllocateInfo allocInfo = {};
        allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        allocInfo.commandPool = vkCommandPool;
        allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        allocInfo.commandBufferCount = (uint32_t)vkCommandBuffers.size();
        if (vkAllocateCommandBuffers(vkDevice, &allocInfo, vkCommandBuffers.data()) != VK_SUCCESS)
            { LOG("SetupWindow: vkAllocateCommandBuffers failed"); return false; }
    }
    LOG("SetupWindow() OK");

    VkSemaphoreCreateInfo semInfo = {};
    semInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
    if (vkCreateSemaphore(vkDevice, &semInfo, 0, &vkImageAvailableSemaphore) != VK_SUCCESS) return false;
    if (vkCreateSemaphore(vkDevice, &semInfo, 0, &vkRenderFinishedSemaphore) != VK_SUCCESS) return false;

    VkFenceCreateInfo fenceInfo = {};
    fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;
    if (vkCreateFence(vkDevice, &fenceInfo, 0, &vkInFlightFence) != VK_SUCCESS) return false;

    return true;
}

bool FxPlayerTiny::CreateVulkanSwapChain()
{
    VkSurfaceCapabilitiesKHR caps;
    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(vkPhysicalDevice, vkSurface, &caps);

    uint32_t formatCount;
    vkGetPhysicalDeviceSurfaceFormatsKHR(vkPhysicalDevice, vkSurface, &formatCount, 0);
    std::vector<VkSurfaceFormatKHR> formats(formatCount);
    vkGetPhysicalDeviceSurfaceFormatsKHR(vkPhysicalDevice, vkSurface, &formatCount, formats.data());

    vkSwapchainFormat = VK_FORMAT_B8G8R8A8_UNORM;
    for (const auto& f : formats)
    {
        if (f.format == VK_FORMAT_B8G8R8A8_UNORM && f.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR)
            break;
        if (f.format == VK_FORMAT_R8G8B8A8_UNORM && f.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR)
        { vkSwapchainFormat = VK_FORMAT_R8G8B8A8_UNORM; break; }
    }

    vkSwapchainExtent.width = Width;
    vkSwapchainExtent.height = Height;
    if (caps.currentExtent.width != (uint32_t)-1)
    {
        vkSwapchainExtent.width = caps.currentExtent.width;
        vkSwapchainExtent.height = caps.currentExtent.height;
    }
    else
    {
        if (vkSwapchainExtent.width < caps.minImageExtent.width) vkSwapchainExtent.width = caps.minImageExtent.width;
        if (vkSwapchainExtent.height < caps.minImageExtent.height) vkSwapchainExtent.height = caps.minImageExtent.height;
        if (vkSwapchainExtent.width > caps.maxImageExtent.width) vkSwapchainExtent.width = caps.maxImageExtent.width;
        if (vkSwapchainExtent.height > caps.maxImageExtent.height) vkSwapchainExtent.height = caps.maxImageExtent.height;
    }

    uint32_t imageCount = caps.minImageCount + 1;
    if (caps.maxImageCount > 0 && imageCount > caps.maxImageCount)
        imageCount = caps.maxImageCount;

    VkSwapchainCreateInfoKHR swapInfo = {};
    swapInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    swapInfo.surface = vkSurface;
    swapInfo.minImageCount = imageCount;
    swapInfo.imageFormat = vkSwapchainFormat;
    swapInfo.imageColorSpace = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
    swapInfo.imageExtent = vkSwapchainExtent;
    swapInfo.imageArrayLayers = 1;
    swapInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
    swapInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
    swapInfo.preTransform = caps.currentTransform;
    swapInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
    swapInfo.presentMode = VK_PRESENT_MODE_FIFO_KHR;
    swapInfo.clipped = VK_TRUE;

    if (vkCreateSwapchainKHR(vkDevice, &swapInfo, 0, &vkSwapchain) != VK_SUCCESS)
        return false;

    vkGetSwapchainImagesKHR(vkDevice, vkSwapchain, &imageCount, 0);
    swapchainImages.resize(imageCount);
    vkGetSwapchainImagesKHR(vkDevice, vkSwapchain, &imageCount, swapchainImages.data());

    swapchainImageViews.resize(swapchainImages.size());
    for (size_t i = 0; i < swapchainImages.size(); ++i)
    {
        VkImageViewCreateInfo viewInfo = {};
        viewInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        viewInfo.image = swapchainImages[i];
        viewInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
        viewInfo.format = vkSwapchainFormat;
        viewInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        viewInfo.subresourceRange.baseMipLevel = 0;
        viewInfo.subresourceRange.levelCount = 1;
        viewInfo.subresourceRange.baseArrayLayer = 0;
        viewInfo.subresourceRange.layerCount = 1;
        if (vkCreateImageView(vkDevice, &viewInfo, 0, &swapchainImageViews[i]) != VK_SUCCESS)
        {
            while (i > 0) vkDestroyImageView(vkDevice, swapchainImageViews[--i], 0);
            return false;
        }
    }
    return true;
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

bool FxPlayerTiny::CreateVulkanRenderPassAndFramebuffers()
{
    const VkFormat depthStencilFormat = pickDepthStencilFormat(vkPhysicalDevice);

    // --- Create depth/stencil image ---
    VkImageCreateInfo dsImgInfo = {};
    dsImgInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    dsImgInfo.imageType = VK_IMAGE_TYPE_2D;
    dsImgInfo.format = depthStencilFormat;
    dsImgInfo.extent.width = vkSwapchainExtent.width;
    dsImgInfo.extent.height = vkSwapchainExtent.height;
    dsImgInfo.extent.depth = 1;
    dsImgInfo.mipLevels = 1;
    dsImgInfo.arrayLayers = 1;
    dsImgInfo.samples = VK_SAMPLE_COUNT_1_BIT;
    dsImgInfo.tiling = VK_IMAGE_TILING_OPTIMAL;
    dsImgInfo.usage = VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT;
    dsImgInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
    dsImgInfo.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    if (vkCreateImage(vkDevice, &dsImgInfo, 0, &vkDepthStencilImage) != VK_SUCCESS)
        { LOG("CreateDS: vkCreateImage failed"); return false; }

    VkMemoryRequirements memReq;
    vkGetImageMemoryRequirements(vkDevice, vkDepthStencilImage, &memReq);

    VkPhysicalDeviceMemoryProperties memProps;
    vkGetPhysicalDeviceMemoryProperties(vkPhysicalDevice, &memProps);
    uint32_t memTypeIndex = (uint32_t)-1;
    for (uint32_t i = 0; i < memProps.memoryTypeCount; ++i)
    {
        if ((memReq.memoryTypeBits & (1u << i)) &&
            (memProps.memoryTypes[i].propertyFlags & VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT))
        { memTypeIndex = i; break; }
    }
    if (memTypeIndex == (uint32_t)-1)
        { LOG("CreateDS: no suitable memory type"); vkDestroyImage(vkDevice, vkDepthStencilImage, 0); vkDepthStencilImage = VK_NULL_HANDLE; return false; }

    VkMemoryAllocateInfo dsAllocInfo = {};
    dsAllocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    dsAllocInfo.allocationSize = memReq.size;
    dsAllocInfo.memoryTypeIndex = memTypeIndex;
    if (vkAllocateMemory(vkDevice, &dsAllocInfo, 0, &vkDepthStencilMemory) != VK_SUCCESS)
        { LOG("CreateDS: vkAllocateMemory failed"); vkDestroyImage(vkDevice, vkDepthStencilImage, 0); vkDepthStencilImage = VK_NULL_HANDLE; return false; }
    vkBindImageMemory(vkDevice, vkDepthStencilImage, vkDepthStencilMemory, 0);

    VkImageViewCreateInfo dsViewInfo = {};
    dsViewInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
    dsViewInfo.image = vkDepthStencilImage;
    dsViewInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
    dsViewInfo.format = depthStencilFormat;
    dsViewInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT;
    dsViewInfo.subresourceRange.baseMipLevel = 0;
    dsViewInfo.subresourceRange.levelCount = 1;
    dsViewInfo.subresourceRange.baseArrayLayer = 0;
    dsViewInfo.subresourceRange.layerCount = 1;
    if (vkCreateImageView(vkDevice, &dsViewInfo, 0, &vkDepthStencilView) != VK_SUCCESS)
    {
        LOG("CreateDS: vkCreateImageView failed");
        vkFreeMemory(vkDevice, vkDepthStencilMemory, 0); vkDepthStencilMemory = VK_NULL_HANDLE;
        vkDestroyImage(vkDevice, vkDepthStencilImage, 0); vkDepthStencilImage = VK_NULL_HANDLE;
        return false;
    }

    // --- Render pass: color + depth/stencil ---
    VkAttachmentDescription attachments[2] = {};
    attachments[0].format = vkSwapchainFormat;
    attachments[0].samples = VK_SAMPLE_COUNT_1_BIT;
    attachments[0].loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
    attachments[0].storeOp = VK_ATTACHMENT_STORE_OP_STORE;
    attachments[0].stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    attachments[0].stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    attachments[0].initialLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
    attachments[0].finalLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

    attachments[1].format = depthStencilFormat;
    attachments[1].samples = VK_SAMPLE_COUNT_1_BIT;
    attachments[1].loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
    attachments[1].storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    attachments[1].stencilLoadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
    attachments[1].stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    attachments[1].initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    attachments[1].finalLayout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;

    VkAttachmentReference colorRef = {};
    colorRef.attachment = 0;
    colorRef.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

    VkAttachmentReference depthRef = {};
    depthRef.attachment = 1;
    depthRef.layout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;

    VkSubpassDescription subpass = {};
    subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
    subpass.colorAttachmentCount = 1;
    subpass.pColorAttachments = &colorRef;
    subpass.pDepthStencilAttachment = &depthRef;

    VkRenderPassCreateInfo rpInfo = {};
    rpInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
    rpInfo.attachmentCount = 2;
    rpInfo.pAttachments = attachments;
    rpInfo.subpassCount = 1;
    rpInfo.pSubpasses = &subpass;
    if (vkCreateRenderPass(vkDevice, &rpInfo, 0, &vkRenderPass) != VK_SUCCESS)
    {
        vkDestroyImageView(vkDevice, vkDepthStencilView, 0);
        vkFreeMemory(vkDevice, vkDepthStencilMemory, 0);
        vkDestroyImage(vkDevice, vkDepthStencilImage, 0);
        vkDepthStencilView = VK_NULL_HANDLE;
        vkDepthStencilMemory = VK_NULL_HANDLE;
        vkDepthStencilImage = VK_NULL_HANDLE;
        return false;
    }

    // --- Framebuffers: color + depth/stencil ---
    vkFramebuffers.resize(swapchainImageViews.size());
    for (size_t i = 0; i < swapchainImageViews.size(); ++i)
    {
        VkImageView fbAttachments[2] = { swapchainImageViews[i], vkDepthStencilView };
        VkFramebufferCreateInfo fbInfo = {};
        fbInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
        fbInfo.renderPass = vkRenderPass;
        fbInfo.attachmentCount = 2;
        fbInfo.pAttachments = fbAttachments;
        fbInfo.width = vkSwapchainExtent.width;
        fbInfo.height = vkSwapchainExtent.height;
        fbInfo.layers = 1;
        if (vkCreateFramebuffer(vkDevice, &fbInfo, 0, &vkFramebuffers[i]) != VK_SUCCESS)
        {
            while (i > 0) vkDestroyFramebuffer(vkDevice, vkFramebuffers[--i], 0);
            vkDestroyRenderPass(vkDevice, vkRenderPass, 0);
            vkRenderPass = VK_NULL_HANDLE;
            vkDestroyImageView(vkDevice, vkDepthStencilView, 0);
            vkFreeMemory(vkDevice, vkDepthStencilMemory, 0);
            vkDestroyImage(vkDevice, vkDepthStencilImage, 0);
            vkDepthStencilView = VK_NULL_HANDLE;
            vkDepthStencilMemory = VK_NULL_HANDLE;
            vkDepthStencilImage = VK_NULL_HANDLE;
            return false;
        }
    }
    return true;
}

void FxPlayerTiny::CleanupVulkanSwapChain()
{
    if (!vkDevice || vkSwapchain == VK_NULL_HANDLE) return;
    vkDeviceWaitIdle(vkDevice);
    if (!vkCommandBuffers.empty() && vkCommandPool != VK_NULL_HANDLE)
        vkFreeCommandBuffers(vkDevice, vkCommandPool, (uint32_t)vkCommandBuffers.size(), vkCommandBuffers.data());
    vkCommandBuffers.clear();
    for (auto fb : vkFramebuffers)
        vkDestroyFramebuffer(vkDevice, fb, 0);
    vkFramebuffers.clear();
    if (vkRenderPass != VK_NULL_HANDLE)
    {
        vkDestroyRenderPass(vkDevice, vkRenderPass, 0);
        vkRenderPass = VK_NULL_HANDLE;
    }
    if (vkDepthStencilView != VK_NULL_HANDLE)
    {
        vkDestroyImageView(vkDevice, vkDepthStencilView, 0);
        vkDepthStencilView = VK_NULL_HANDLE;
    }
    if (vkDepthStencilMemory != VK_NULL_HANDLE)
    {
        vkFreeMemory(vkDevice, vkDepthStencilMemory, 0);
        vkDepthStencilMemory = VK_NULL_HANDLE;
    }
    if (vkDepthStencilImage != VK_NULL_HANDLE)
    {
        vkDestroyImage(vkDevice, vkDepthStencilImage, 0);
        vkDepthStencilImage = VK_NULL_HANDLE;
    }
    for (auto v : swapchainImageViews)
        vkDestroyImageView(vkDevice, v, 0);
    swapchainImageViews.clear();
    swapchainImages.clear();
    vkDestroySwapchainKHR(vkDevice, vkSwapchain, 0);
    vkSwapchain = VK_NULL_HANDLE;
    pSwapChainRenderTarget = 0;
}

int FxPlayerTiny::Run()
{
    LOG("Run() start, loading '%s'", FileName.ToCStr());
    if (!SetupWindow(String(FXPLAYER_APP_TITLE " ") + FileName))
        { LOG("Run(): SetupWindow failed"); return 1; }

    ShowWindow(hWnd, SW_SHOWDEFAULT);
    UpdateWindow(hWnd);
    LOG("Window shown");

    Loader loader;
    loader.SetLog(Ptr<GFx::Log>(*new GFxPlayerLog()));
    Ptr<ActionControl> pactControl = *new ActionControl(ActionControl::Action_ErrorSuppress);
    pactControl->SetVerboseAction(VerboseAction);
    loader.SetActionControl(pactControl);
    Ptr<FileOpener> pfileOpener = *new FileOpener;
    loader.SetFileOpener(pfileOpener);
    Ptr<FSCommandHandler> pcommandHandler = *new FxPlayerFSCommandHandler;
    loader.SetFSCommandHandler(pcommandHandler);
    Ptr<FontProviderWin32> fontProvider = *new FontProviderWin32(::GetDC(0));
    loader.SetFontProvider(fontProvider);

    SF::Ptr<GFx::ImageFileHandlerRegistry> pimgReg = *new GFx::ImageFileHandlerRegistry();
#ifdef SF_ENABLE_LIBJPEG
    pimgReg->AddHandler(&SF::Render::JPEG::FileReader::Instance);
#endif
#ifdef SF_ENABLE_LIBPNG
    pimgReg->AddHandler(&SF::Render::PNG::FileReader::Instance);
#endif
    pimgReg->AddHandler(&SF::Render::TGA::FileReader::Instance);
    pimgReg->AddHandler(&SF::Render::DDS::FileReader::Instance);
    loader.SetImageFileHandlerRegistry(pimgReg);

    Ptr<ASSupport> pASSupport = *new GFx::AS3Support();
    loader.SetAS3Support(pASSupport);
    Ptr<ASSupport> pAS2Support = *new GFx::AS2Support();
    loader.SetAS2Support(pAS2Support);

    FxPlayerThreadCommandQueue* queue = new FxPlayerThreadCommandQueue;
    pCommandQueue = queue;

    if (!(pMovieDef = *loader.CreateMovie(FileName)))
    {
        LOG("CreateMovie('%s') failed, trying AS2\\Samples\\...", FileName.ToCStr());
        if (!(pMovieDef = *loader.CreateMovie("AS2\\Samples\\" + FileName)))
        {
            LOG("CreateMovie failed");
            String errorString = "Unable to load file: ";
            errorString += FileName;
            MessageBox(NULL, errorString.ToCStr(), "Error", MB_OK | MB_ICONEXCLAMATION);
            return 1;
        }
    }
    LOG("MovieDef loaded");

    if (!(pMovie = *pMovieDef->CreateInstance(false, 0, 0, pCommandQueue)))
        { LOG("CreateInstance failed"); return 1; }

    pMovie->SetMouseCursorCount(1);
    hMovieDisplay = pMovie->GetDisplayHandle();

    pRenderHAL = *new Render::Vulkan::HAL();
    if (!(pRenderer = *new Render::Renderer2D(pRenderHAL.GetPtr())))
        return 1;

    queue->pHAL = pRenderHAL;
    queue->pR2D = pRenderer;

    Render::Vulkan::HALInitParams halParams(vkInstance, vkPhysicalDevice, vkDevice, vkQueue, vkQueueFamilyIndex, vkRenderPass, vkSwapchainFormat);
    if (!pRenderHAL->InitHAL(halParams))
        { LOG("InitHAL failed"); return 1; }
    LOG("Vulkan HAL initialized");

    ImageSize rtSize((int)vkSwapchainExtent.width, (int)vkSwapchainExtent.height);
    pSwapChainRenderTarget = pRenderHAL->CreateRenderTarget(swapchainImageViews[0], vkDepthStencilView, rtSize);
    if (!pSwapChainRenderTarget)
        { LOG("CreateRenderTarget failed"); return 1; }
    LOG("Render target created %dx%d", rtSize.Width, rtSize.Height);

    pMovie->SetViewport((int)vkSwapchainExtent.width, (int)vkSwapchainExtent.height, 0, 0, (int)vkSwapchainExtent.width, (int)vkSwapchainExtent.height);

    MovieStartTime = MovieLastTime = timeGetTime();

    LOG("Entering main loop");
    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        // Process all pending messages so the window stays responsive (avoids "Not Responding")
        while (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        if (msg.message == WM_QUIT)
            break;
        AdvanceAndDisplay();
        if ((ExitTimeout > 0) && (MovieLastTime - MovieStartTime > (UInt32)(ExitTimeout * 1000)))
            break;
        Sleep(1);
    }
    LOG("Main loop exit (msg=WM_QUIT or timeout)");
    return 0;
}

void FxPlayerTiny::AdvanceAndDisplay()
{
    static int advFrame = 0;
    advFrame++;
    if (advFrame <= 20 || advFrame % 60 == 0)
        LOG("AdvanceAndDisplay frame %d start", advFrame);

    if (!pMovie || !pRenderer || !pRenderHAL || !pSwapChainRenderTarget || vkCommandBuffers.empty() || vkSwapchain == VK_NULL_HANDLE)
        { static bool once = true; if (once) { LOG("AdvanceAndDisplay: early exit (missing init)"); once = false; } return; }

    // Wait for previous frame's GPU work with timeout and pump messages so window doesn't go "Not Responding"
    {
        const uint64_t timeoutNs = 16000000; // 16 ms
        MSG msg;
        VkResult waitRes;
        while ((waitRes = vkWaitForFences(vkDevice, 1, &vkInFlightFence, VK_TRUE, timeoutNs)) == VK_TIMEOUT)
        {
            while (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
            {
                if (msg.message == WM_QUIT)
                    return;
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
            Sleep(0);
        }
        if (waitRes != VK_SUCCESS)
            return;
    }
    vkResetFences(vkDevice, 1, &vkInFlightFence);

    uint32_t imageIndex;
    VkResult res = vkAcquireNextImageKHR(vkDevice, vkSwapchain, UINT64_MAX, vkImageAvailableSemaphore, VK_NULL_HANDLE, &imageIndex);
    if (res != VK_SUCCESS && res != VK_SUBOPTIMAL_KHR)
        { static int errCount = 0; if (errCount++ < 5) LOG("vkAcquireNextImageKHR failed: %d", (int)res); return; }
    if (advFrame <= 20 || advFrame % 60 == 0)
        LOG("Acquired image %u", (unsigned)imageIndex);

    Vulkan::RenderTargetData::UpdateData(pSwapChainRenderTarget, swapchainImageViews[imageIndex], 0, vkDepthStencilView);
    pRenderHAL->SetRenderTarget(pSwapChainRenderTarget);

    UInt32 time = timeGetTime();
    float delta = ((float)(time - MovieLastTime)) / 1000.0f;
    if (!Paused)
        pMovie->Advance(delta);
    MovieLastTime = time;

    VkCommandBuffer cmd = vkCommandBuffers[imageIndex];
    vkResetCommandBuffer(cmd, 0);
    VkCommandBufferBeginInfo beginInfo = {};
    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    if (vkBeginCommandBuffer(cmd, &beginInfo) != VK_SUCCESS)
        { static int errCount = 0; if (errCount++ < 5) LOG("vkBeginCommandBuffer failed"); return; }

    pRenderHAL->BeginFrame(cmd);

    VkImageMemoryBarrier barrierToRender = {};
    barrierToRender.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
    barrierToRender.oldLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    barrierToRender.newLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
    barrierToRender.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    barrierToRender.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    barrierToRender.image = swapchainImages[imageIndex];
    barrierToRender.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    barrierToRender.subresourceRange.baseMipLevel = 0;
    barrierToRender.subresourceRange.levelCount = 1;
    barrierToRender.subresourceRange.baseArrayLayer = 0;
    barrierToRender.subresourceRange.layerCount = 1;
    barrierToRender.srcAccessMask = 0;
    barrierToRender.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
    vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, 0, 0, nullptr, 0, nullptr, 1, &barrierToRender);

    VkClearValue clearValues[2] = {};
    clearValues[0].color.float32[0] = 0.2f;
    clearValues[0].color.float32[1] = 0.2f;
    clearValues[0].color.float32[2] = 0.2f;
    clearValues[0].color.float32[3] = 1.0f;
    clearValues[1].depthStencil.depth = 1.0f;
    clearValues[1].depthStencil.stencil = 0;
    VkRenderPassBeginInfo rpBegin = {};
    rpBegin.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    rpBegin.renderPass = vkRenderPass;
    rpBegin.framebuffer = vkFramebuffers[imageIndex];
    rpBegin.renderArea.offset = { 0, 0 };
    rpBegin.renderArea.extent = vkSwapchainExtent;
    rpBegin.clearValueCount = 2;
    rpBegin.pClearValues = clearValues;
    vkCmdBeginRenderPass(cmd, &rpBegin, VK_SUBPASS_CONTENTS_INLINE);

    Display();

    vkCmdEndRenderPass(cmd);

    VkImageMemoryBarrier barrierToPresent = {};
    barrierToPresent.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
    barrierToPresent.oldLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
    barrierToPresent.newLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
    barrierToPresent.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    barrierToPresent.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    barrierToPresent.image = swapchainImages[imageIndex];
    barrierToPresent.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    barrierToPresent.subresourceRange.baseMipLevel = 0;
    barrierToPresent.subresourceRange.levelCount = 1;
    barrierToPresent.subresourceRange.baseArrayLayer = 0;
    barrierToPresent.subresourceRange.layerCount = 1;
    barrierToPresent.srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
    barrierToPresent.dstAccessMask = 0;
    vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, 0, 0, nullptr, 0, nullptr, 1, &barrierToPresent);

    vkEndCommandBuffer(cmd);

    VkPipelineStageFlags waitStage = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    VkSubmitInfo submitInfo = {};
    submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submitInfo.waitSemaphoreCount = 1;
    submitInfo.pWaitSemaphores = &vkImageAvailableSemaphore;
    submitInfo.pWaitDstStageMask = &waitStage;
    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers = &cmd;
    submitInfo.signalSemaphoreCount = 1;
    submitInfo.pSignalSemaphores = &vkRenderFinishedSemaphore;

    if (vkQueueSubmit(vkQueue, 1, &submitInfo, vkInFlightFence) != VK_SUCCESS)
        { static int errCount = 0; if (errCount++ < 5) LOG("vkQueueSubmit failed"); return; }
    { static int subFrame = 0; subFrame++; if (subFrame <= 20 || subFrame % 60 == 0) LOG("Frame submitted %d", subFrame); }

    VkPresentInfoKHR presentInfo = {};
    presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
    presentInfo.waitSemaphoreCount = 1;
    presentInfo.pWaitSemaphores = &vkRenderFinishedSemaphore;
    presentInfo.swapchainCount = 1;
    presentInfo.pSwapchains = &vkSwapchain;
    presentInfo.pImageIndices = &imageIndex;
    VkResult presRes = vkQueuePresentKHR(vkQueue, &presentInfo);
    if (presRes != VK_SUCCESS && presRes != VK_SUBOPTIMAL_KHR)
        { static int errCount = 0; if (errCount++ < 5) LOG("vkQueuePresentKHR failed: %d", (int)presRes); }
}

void FxPlayerTiny::Display()
{
    if (!pRenderer) return;
    pRenderer->BeginFrame();
    bool captured = hMovieDisplay.NextCapture(pRenderer->GetContextNotify());
    static int logFrame = 0;
    logFrame++;
    if (logFrame <= 20 || logFrame % 60 == 0)
        LOG("Display() frame %d NextCapture=%d", logFrame, (int)captured);
    if (captured)
    {
        LOG("Display() calling pRenderer->Display(hMovieDisplay)...");
        pRenderer->Display(hMovieDisplay);
        LOG("Display() pRenderer->Display() returned");
    }
    LOG("Display() calling EndFrame()");
    pRenderer->EndFrame();
    LOG("Display() EndFrame() returned");
}

void FxPlayerTiny::HandleKeyEvent(unsigned keyCode, bool downFlag)
{
    Key::Code key = Key::None;
    if (keyCode >= 'A' && keyCode <= 'Z')
        key = (Key::Code)((keyCode - 'A') + Key::A);
    else if (keyCode >= VK_F1 && keyCode <= VK_F15)
        key = (Key::Code)((keyCode - VK_F1) + Key::F1);
    else if (keyCode >= '0' && keyCode <= '9')
        key = (Key::Code)((keyCode - '0') + 48);
    else if (keyCode >= VK_NUMPAD0 && keyCode <= VK_NUMPAD9)
        key = (Key::Code)((keyCode - VK_NUMPAD0) + Key::KP_0);
    else
    {
        static struct { int vk; Key::Code gs; } table[] = {
            { VK_SHIFT, Key::Shift }, { VK_RSHIFT, Key::Shift }, { VK_CONTROL, Key::Control }, { VK_RCONTROL, Key::Control },
            { VK_MENU, Key::Alt }, { VK_RMENU, Key::Alt }, { VK_RETURN, Key::Return }, { VK_ESCAPE, Key::Escape },
            { VK_LEFT, Key::Left }, { VK_UP, Key::Up }, { VK_RIGHT, Key::Right }, { VK_DOWN, Key::Down },
            { VK_SPACE, Key::Space }, { VK_BACK, Key::Backspace }, { VK_DELETE, Key::Delete }, { VK_INSERT, Key::Insert },
            { 0, Key::None }
        };
        for (int i = 0; table[i].vk != 0; i++)
            if (keyCode == (unsigned)table[i].vk) { key = table[i].gs; break; }
    }
    if (key != Key::None && pMovie)
    {
        KeyEvent event(downFlag ? GFx::Event::KeyDown : KeyEvent::KeyUp, key);
        pMovie->HandleEvent(event);
    }
}

void FxPlayerTiny::OnKey(unsigned keyCode, bool downFlag)
{
    if (!pMovie) return;
    if (keyCode == VK_CONTROL) { ControlKeyDown = downFlag; return; }
    if (keyCode == VK_MENU && downFlag) return;
    bool ctrl = ControlKeyDown;
    if (ctrl && downFlag)
    {
        if (keyCode == 'P') Paused = !Paused;
        return;
    }
    if (!ctrl)
        HandleKeyEvent(keyCode, downFlag);
}

void FxPlayerTiny::OnMouse(GFx::Event::EventType eventType, unsigned button, int x, int y)
{
    if (pMovie)
    {
        MouseEvent mevent(eventType, button, (float)x, (float)y);
        pMovie->HandleEvent(mevent);
    }
}

void FxPlayerTiny::OnMouseWheel(int zdelta, int x, int y)
{
    if (pMovie)
    {
        MouseEvent mevent(GFx::Event::MouseWheel, 0, (float)x, (float)y, (float)((zdelta / WHEEL_DELTA) * 3));
        pMovie->HandleEvent(mevent);
    }
}

LRESULT FxPlayerTiny::MemberWndProc(UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_SETCURSOR:
        if (LOWORD(lParam) == HTCLIENT) { SetCursor(LoadCursor(0, IDC_ARROW)); return 0; }
        break;
    case WM_MOUSEMOVE:
        OnMouse(GFx::Event::MouseMove, 0, LOWORD(lParam), HIWORD(lParam));
        return 0;
    case WM_MOUSEWHEEL:
        {
            POINT wcl = { 0, 0 };
            ClientToScreen(hWnd, &wcl);
            int x = (int)(short)LOWORD(lParam) - wcl.x;
            int y = (int)(short)HIWORD(lParam) - wcl.y;
            OnMouseWheel((int)(short)HIWORD(wParam) * 128 / WHEEL_DELTA, x, y);
            return 0;
        }
    case WM_LBUTTONDOWN:
        SetCapture(hWnd);
        OnMouse(GFx::Event::MouseDown, 0, LOWORD(lParam), HIWORD(lParam));
        return 0;
    case WM_LBUTTONUP:
        ReleaseCapture();
        OnMouse(GFx::Event::MouseUp, 0, LOWORD(lParam), HIWORD(lParam));
        return 0;
    case WM_KEYDOWN:
        OnKey((unsigned)wParam, 1);
        return 0;
    case WM_KEYUP:
        OnKey((unsigned)wParam, 0);
        return 0;
    case WM_CHAR:
        if (pMovie && (UInt32)wParam) { CharEvent event((UInt32)wParam); pMovie->HandleEvent(event); }
        break;
    case WM_SIZE:
        if (wParam != SIZE_MINIMIZED && vkDevice && vkSwapchain && pRenderHAL)
        {
            Width = LOWORD(lParam);
            Height = HIWORD(lParam);
            if (Width > 0 && Height > 0)
            {
                CleanupVulkanSwapChain();
                if (CreateVulkanSwapChain() && CreateVulkanRenderPassAndFramebuffers() && vkCommandPool != VK_NULL_HANDLE && !swapchainImageViews.empty())
                {
                    vkCommandBuffers.resize(swapchainImageViews.size());
                    VkCommandBufferAllocateInfo allocInfo = {};
                    allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
                    allocInfo.commandPool = vkCommandPool;
                    allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
                    allocInfo.commandBufferCount = (uint32_t)vkCommandBuffers.size();
                    if (vkAllocateCommandBuffers(vkDevice, &allocInfo, vkCommandBuffers.data()) == VK_SUCCESS)
                    {
    ImageSize rtSize((int)vkSwapchainExtent.width, (int)vkSwapchainExtent.height);
    pSwapChainRenderTarget = pRenderHAL->CreateRenderTarget(swapchainImageViews[0], vkDepthStencilView, rtSize);
                        if (pMovie)
                            pMovie->SetViewport((int)vkSwapchainExtent.width, (int)vkSwapchainExtent.height, 0, 0, (int)vkSwapchainExtent.width, (int)vkSwapchainExtent.height);
                    }
                }
            }
        }
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

LRESULT CALLBACK FxPlayerTiny::StaticWindowProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    FxPlayerTiny* papp = 0;
    if (iMsg == WM_NCCREATE)
    {
        papp = (FxPlayerTiny*)((LPCREATESTRUCT)lParam)->lpCreateParams;
        if (!papp) return DefWindowProc(hwnd, iMsg, wParam, lParam);
        SetWindowLongPtr(hwnd, 0, (LONG_PTR)papp);
        papp->hWnd = hwnd;
    }
    papp = (FxPlayerTiny*)(size_t)GetWindowLongPtr(hwnd, 0);
    if (!papp) return DefWindowProc(hwnd, iMsg, wParam, lParam);
    return papp->MemberWndProc(iMsg, wParam, lParam);
}

int SF_CDECL main(int argc, char* argv[])
{
    if (AllocConsole())
    {
        FILE* f = 0;
        if (freopen_s(&f, "CONOUT$", "w", stdout)) { }
        if (freopen_s(&f, "CONOUT$", "w", stderr)) { }
        SetConsoleTitleA("GFxPlayerTinyVulkan - Console");
    }
    LOG("main() start");

    SF::SysAllocMalloc a;
    SF::GFx::System gfxInit(&a);
    LOG("GFx system initialized");

    int result = 1;
    {
        FxPlayerTiny player(argc, argv);
        LOG("FxPlayerTiny created, calling Run()");
        result = player.Run();
        LOG("Run() returned %d", result);
    }
    LOG("main() exit %d", result);
    return result;
}
