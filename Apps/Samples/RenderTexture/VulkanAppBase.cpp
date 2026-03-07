/*
 * Vulkan Windowed Program
 *
 * Copyright (C) 2016, 2018 Valve Corporation
 * Copyright (C) 2016, 2018 LunarG, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
Vulkan C++ Windowed Project Template
Create and destroy a Vulkan surface on an SDL window.
*/

// Enable the WSI extensions
#if defined(__ANDROID__)
#define VK_USE_PLATFORM_ANDROID_KHR
#elif defined(__linux__)
#define VK_USE_PLATFORM_XLIB_KHR
#elif defined(_WIN32)
#define VK_USE_PLATFORM_WIN32_KHR
#endif

// Tell SDL not to mess with main()
#define SDL_MAIN_HANDLED

//#include <glm/glm.hpp>
#include <../Apps/Samples/RenderTexture/VulkanAppBase.h>

namespace VulkanBaseApp {

// Define the vertex structure
struct Vertex {
    float position[3];
    float color[3];
};

// Define the vertices for a cube
std::vector<Vertex> vertices = {
    // Front face
    {{-1.0f, -1.0f,  1.0f}, {1.0f, 0.0f, 0.0f}},
    {{ 1.0f, -1.0f,  1.0f}, {0.0f, 1.0f, 0.0f}},
    {{ 1.0f,  1.0f,  1.0f}, {0.0f, 0.0f, 1.0f}},
    {{-1.0f,  1.0f,  1.0f}, {1.0f, 1.0f, 0.0f}},

    // Back face
    {{-1.0f, -1.0f, -1.0f}, {1.0f, 0.0f, 1.0f}},
    {{ 1.0f, -1.0f, -1.0f}, {0.0f, 1.0f, 1.0f}},
    {{ 1.0f,  1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}},
    {{-1.0f,  1.0f, -1.0f}, {0.0f, 0.0f, 0.0f}},
};

// Define the indices for the cube
std::vector<uint16_t> indices = {
    0, 1, 2, 2, 3, 0, // Front face
    4, 5, 6, 6, 7, 4, // Back face
    0, 1, 5, 5, 4, 0, // Bottom face
    2, 3, 7, 7, 6, 2, // Top face
    0, 3, 7, 7, 4, 0, // Left face
    1, 2, 6, 6, 5, 1  // Right face
};

VkBuffer vertexBuffer;
VkDeviceMemory vertexBufferMemory;

void createVertexBuffer(VkDevice device, VkPhysicalDevice physicalDevice) {
    VkResult res;

    VkDeviceSize bufferSize = sizeof(vertices[0]) * vertices.size();

    // Create the buffer
    VkBufferCreateInfo bufferInfo{};
    bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    bufferInfo.size = bufferSize;
    bufferInfo.usage = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
    bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

    if (vkCreateBuffer(device, &bufferInfo, nullptr, &vertexBuffer) != VK_SUCCESS) {
        throw std::runtime_error("failed to create vertex buffer!");
    }

    VkMemoryRequirements memRequirements;
    vkGetBufferMemoryRequirements(device, vertexBuffer, &memRequirements);
    

    VkMemoryAllocateInfo allocInfo{};
    allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocInfo.allocationSize = memRequirements.size;
    allocInfo.memoryTypeIndex = 0;

    if (vkAllocateMemory(device, &allocInfo, nullptr, &vertexBufferMemory) != VK_SUCCESS) {
        throw std::runtime_error("failed to allocate vertex buffer memory!");
    }

    res = vkBindBufferMemory(device, vertexBuffer, vertexBufferMemory, 0);
    assert(res == VK_SUCCESS);

    uint8_t* pData;
    res = vkMapMemory(device, vertexBufferMemory, 0, bufferSize, 0, (void**)&pData);
    assert(res == VK_SUCCESS);

    memcpy(pData, vertices.data(), (size_t)bufferSize);
    vkUnmapMemory(device, vertexBufferMemory);
}


int VulkanAppMain()
{
    // Create an SDL window that supports Vulkan rendering.
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Could not initialize SDL." << std::endl;
        return 1;
    }
    SDL_Window* window = SDL_CreateWindow("Vulkan Window", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_VULKAN);
    if(window == NULL) {
        std::cout << "Could not create SDL window." << std::endl;
        return 1;
    }

    // Get WSI extensions from SDL (we can add more if we like - we just can't remove these)
    unsigned extension_count;
    if(!SDL_Vulkan_GetInstanceExtensions(window, &extension_count, NULL)) {
        std::cout << "Could not get the number of required instance extensions from SDL." << std::endl;
        return 1;
    }
    std::vector<const char*> extensions(extension_count);
    if(!SDL_Vulkan_GetInstanceExtensions(window, &extension_count, extensions.data())) {
        std::cout << "Could not get the names of required instance extensions from SDL." << std::endl;
        return 1;
    }

    // Use validation layers if this is a debug build
    std::vector<const char*> layers;
#if defined(_DEBUG)
    layers.push_back("VK_LAYER_KHRONOS_validation");
#endif

    // vk::ApplicationInfo allows the programmer to specifiy some basic information about the
    // program, which can be useful for layers and tools to provide more debug information.
    vk::ApplicationInfo appInfo = vk::ApplicationInfo()
        .setPApplicationName("Vulkan C++ Windowed Program Template")
        .setApplicationVersion(1)
        .setPEngineName("LunarG SDK")
        .setEngineVersion(1)
        .setApiVersion(VK_API_VERSION_1_0);

    // vk::InstanceCreateInfo is where the programmer specifies the layers and/or extensions that
    // are needed.
    vk::InstanceCreateInfo instInfo = vk::InstanceCreateInfo()
        .setFlags(vk::InstanceCreateFlags())
        .setPApplicationInfo(&appInfo)
        .setEnabledExtensionCount(static_cast<uint32_t>(extensions.size()))
        .setPpEnabledExtensionNames(extensions.data())
        .setEnabledLayerCount(static_cast<uint32_t>(layers.size()))
        .setPpEnabledLayerNames(layers.data());

    // Create the Vulkan instance.
    vk::Instance instance;
    try {
        instance = vk::createInstance(instInfo);
    } catch(const std::exception& e) {
        std::cout << "Could not create a Vulkan instance: " << e.what() << std::endl;
        return 1;
    }

    // Create a Vulkan surface for rendering
    VkSurfaceKHR c_surface;
    if(!SDL_Vulkan_CreateSurface(window, static_cast<VkInstance>(instance), &c_surface)) {
        std::cout << "Could not create a Vulkan surface." << std::endl;
        return 1;
    }
    vk::SurfaceKHR surface(c_surface);

    // This is where most initializtion for a program should be performed
    std::vector<VkPhysicalDevice> gpus;

    uint32_t gpu_count = 1;
    VkResult res = vkEnumeratePhysicalDevices(instance, &gpu_count, NULL);
    assert(res == VK_SUCCESS);
    assert(gpu_count);
    gpus.resize(gpu_count);
    res = vkEnumeratePhysicalDevices(instance, &gpu_count, gpus.data());
    assert(!res && gpu_count >= 1);

    uint32_t queue_family_count = 1;
    std::vector<VkQueueFamilyProperties> queue_props;
    queue_props.resize(queue_family_count);

    vkGetPhysicalDeviceQueueFamilyProperties(gpus[0], &queue_family_count, queue_props.data());
    assert(queue_family_count >= 1);

    float queue_priorities[1] = { 0.0 };
    VkDeviceQueueCreateInfo queue_info = {};
    bool found = false;
    for (unsigned int i = 0; i < queue_family_count; i++) {
        if (queue_props[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) {
            queue_info.queueFamilyIndex = i;
            found = true;
            break;
        }
    }
    assert(found);
    assert(queue_family_count >= 1);

    queue_info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    queue_info.pNext = NULL;
    queue_info.queueCount = 1;
    queue_info.pQueuePriorities = queue_priorities;

    const char* requiredExtensions[] = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME, // to be able to use LAYOUT_PRESENT; would LAYOUT_GENERAL work?
        VK_KHR_EXTERNAL_MEMORY_EXTENSION_NAME,
        VK_KHR_EXTERNAL_MEMORY_WIN32_EXTENSION_NAME,
        VK_KHR_DEDICATED_ALLOCATION_EXTENSION_NAME,
        VK_KHR_GET_MEMORY_REQUIREMENTS_2_EXTENSION_NAME
        // Other extensions as necessary
    };

    const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
    };

    VkDeviceCreateInfo device_info = {};
    device_info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    device_info.pNext = NULL;
    device_info.queueCreateInfoCount = 1;
    device_info.pQueueCreateInfos = &queue_info;
    device_info.enabledExtensionCount = 0;
    device_info.ppEnabledExtensionNames = NULL;
    device_info.enabledLayerCount = 0;
    device_info.ppEnabledLayerNames = NULL;
    device_info.pEnabledFeatures = NULL;
    device_info.enabledExtensionCount = sizeof(requiredExtensions) / sizeof(requiredExtensions[0]);
    device_info.ppEnabledExtensionNames = requiredExtensions;

    VkDevice vkDevice;
    res = vkCreateDevice(gpus[0], &device_info, NULL, &vkDevice);
    assert(res == VK_SUCCESS);

    VkPhysicalDeviceExternalImageFormatInfo PhysicalDeviceExternalImageFormatInfo = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO };
    PhysicalDeviceExternalImageFormatInfo.handleType = VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT;
    VkPhysicalDeviceImageFormatInfo2 PhysicalDeviceImageFormatInfo2 = { VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2 };
    PhysicalDeviceImageFormatInfo2.pNext = &PhysicalDeviceExternalImageFormatInfo;
    PhysicalDeviceImageFormatInfo2.format = VK_FORMAT_R8G8B8A8_UNORM;
    PhysicalDeviceImageFormatInfo2.type = VK_IMAGE_TYPE_2D;
    PhysicalDeviceImageFormatInfo2.tiling = VK_IMAGE_TILING_OPTIMAL;
    PhysicalDeviceImageFormatInfo2.usage = VK_IMAGE_USAGE_TRANSFER_DST_BIT;
    VkExternalImageFormatProperties ExternalImageFormatProperties = { VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES };
    VkImageFormatProperties2 ImageFormatProperties2 = { VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2 };
    ImageFormatProperties2.pNext = &ExternalImageFormatProperties;
    assert(vkGetPhysicalDeviceImageFormatProperties2(gpus[0], &PhysicalDeviceImageFormatInfo2, &ImageFormatProperties2) == VK_SUCCESS);
    assert(ExternalImageFormatProperties.externalMemoryProperties.externalMemoryFeatures & VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT);
    assert(ExternalImageFormatProperties.externalMemoryProperties.externalMemoryFeatures & VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT);
    assert(ExternalImageFormatProperties.externalMemoryProperties.compatibleHandleTypes & VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT);

    VkExternalMemoryImageCreateInfo ExternalMemoryImageCreateInfo = { VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO };
    ExternalMemoryImageCreateInfo.handleTypes = VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT;
    VkImageCreateInfo ImageCreateInfo = { VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO };
    ImageCreateInfo.pNext = &ExternalMemoryImageCreateInfo;
    ImageCreateInfo.imageType = VK_IMAGE_TYPE_2D;
    ImageCreateInfo.format = VK_FORMAT_R8G8B8A8_UNORM;
    ImageCreateInfo.flags = 0;
    ImageCreateInfo.extent.width = 1280;
    ImageCreateInfo.extent.height = 720;
    ImageCreateInfo.extent.depth = 1;
    ImageCreateInfo.mipLevels = 1;
    ImageCreateInfo.arrayLayers = 1;
    ImageCreateInfo.samples = VK_SAMPLE_COUNT_1_BIT;
    ImageCreateInfo.tiling = VK_IMAGE_TILING_OPTIMAL;
    ImageCreateInfo.usage = VK_IMAGE_USAGE_TRANSFER_DST_BIT;
    ImageCreateInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
    ImageCreateInfo.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    VkImage Image;
    assert(vkCreateImage(vkDevice, &ImageCreateInfo, nullptr, &Image) == VK_SUCCESS);

    VkMemoryDedicatedRequirements MemoryDedicatedRequirements = { VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS };
    VkMemoryRequirements2 MemoryRequirements2 = { VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2 };
    MemoryRequirements2.pNext = &MemoryDedicatedRequirements;
    VkImageMemoryRequirementsInfo2 ImageMemoryRequirementsInfo2 = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2 };
    ImageMemoryRequirementsInfo2.image = Image;
    // WARN: Memory access violation unless validation instance layer is enabled, otherwise success but...
    vkGetImageMemoryRequirements2(vkDevice, &ImageMemoryRequirementsInfo2, &MemoryRequirements2);
    //       ... if we happen to be here, MemoryRequirements2 is empty
    VkMemoryRequirements& MemoryRequirements = MemoryRequirements2.memoryRequirements;

    //assert(!MemoryRequirements.size);
    vkGetImageMemoryRequirements(vkDevice, Image, &MemoryRequirements);
    assert(MemoryRequirements.size);


    VkMemoryDedicatedAllocateInfo MemoryDedicatedAllocateInfo = { VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO };
    MemoryDedicatedAllocateInfo.image = Image;
    VkImportMemoryWin32HandleInfoKHR ImportMemoryWin32HandleInfo = { VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR };
    ImportMemoryWin32HandleInfo.pNext = &MemoryDedicatedAllocateInfo;
    ImportMemoryWin32HandleInfo.handleType = VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT;
    ImportMemoryWin32HandleInfo.handle = (HANDLE)0x0000000000000f0c;
    VkMemoryAllocateInfo MemoryAllocateInfo = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
    MemoryAllocateInfo.pNext = &ImportMemoryWin32HandleInfo;
    MemoryAllocateInfo.allocationSize = MemoryRequirements.size;
    // WARN: MemoryAllocateInfo.memoryTypeIndex remains zero
    VkDeviceMemory ImageMemory;
    auto allocResult = vkAllocateMemory(vkDevice, &MemoryAllocateInfo, nullptr, &ImageMemory);
    assert(allocResult == VK_SUCCESS);

    allocResult = vkBindImageMemory(vkDevice, Image, ImageMemory, 0);
    assert(allocResult == VK_SUCCESS);

    VkImageViewCreateInfo imageViewCreateInfo = {};
    imageViewCreateInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
    imageViewCreateInfo.image = Image;
    imageViewCreateInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
    imageViewCreateInfo.format = VK_FORMAT_R8G8B8A8_UNORM;
    imageViewCreateInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    imageViewCreateInfo.subresourceRange.baseMipLevel = 0;
    imageViewCreateInfo.subresourceRange.levelCount = 1;
    imageViewCreateInfo.subresourceRange.baseArrayLayer = 0;
    imageViewCreateInfo.subresourceRange.layerCount = 1;

    VkImageView vkImageView;
    VkResult result = vkCreateImageView(vkDevice, &imageViewCreateInfo, nullptr, &vkImageView);
    assert(result == VK_SUCCESS);



    //createVertexBuffer(device, gpus[0]);

    // Poll for user input.
    bool stillRunning = true;
    while(stillRunning) {

        SDL_Event event;
        while(SDL_PollEvent(&event)) {

            switch(event.type) {

            case SDL_QUIT:
                stillRunning = false;
                break;

            default:
                // Do nothing.
                break;
            }
        }

        SDL_Delay(10);
    }

    // Clean up.
    instance.destroySurfaceKHR(surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
    instance.destroy();

    return 0;
}

}