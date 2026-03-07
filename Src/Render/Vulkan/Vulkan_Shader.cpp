/**************************************************************************

Filename    :   Vulkan_Shader.cpp
Content     :   Vulkan shader manager and interface (scaffold).
Created     :   2025
Authors     :   Vulkan backend

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

**************************************************************************/

#include "Render/Vulkan/Vulkan_Shader.h"
#include "Render/Vulkan/Vulkan_HAL.h"
#include "Render/Vulkan/Vulkan_Texture.h"
#include "Render/Render_Vertex.h"
#include "Render/Render_States.h"
#include "Render/Render_Matrix2x4.h"
#include "Render/Render_Image.h"
#include "Kernel/SF_Debug.h"
#include <cstring>

namespace Scaleform { namespace Render { namespace Vulkan {

bool VertexShader::Init(VkDevice device, const VertexShaderDesc* pd)
{
    pDesc = pd;
    pDevice = device;
    Module = VK_NULL_HANDLE;
    if (pd && pd->pBinary && pd->BinarySize > 0)
    {
        VkShaderModuleCreateInfo ci = {};
        ci.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        ci.codeSize = pd->BinarySize;
        ci.pCode = (const uint32_t*)pd->pBinary;
        if (vkCreateShaderModule(device, &ci, 0, &Module) != VK_SUCCESS)
            return false;
    }
    return true;
}

void VertexShader::Shutdown()
{
    if (pDevice != VK_NULL_HANDLE && Module != VK_NULL_HANDLE)
    {
        vkDestroyShaderModule(pDevice, Module, 0);
        Module = VK_NULL_HANDLE;
    }
    pDevice = VK_NULL_HANDLE;
    pDesc = 0;
}

bool FragShader::Init(VkDevice device, const FragShaderDesc* pd)
{
    pDesc = pd;
    pDevice = device;
    Module = VK_NULL_HANDLE;
    if (pd && pd->pBinary && pd->BinarySize > 0)
    {
        VkShaderModuleCreateInfo ci = {};
        ci.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        ci.codeSize = pd->BinarySize;
        ci.pCode = (const uint32_t*)pd->pBinary;
        if (vkCreateShaderModule(device, &ci, 0, &Module) != VK_SUCCESS)
            return false;
    }
    return true;
}

void FragShader::Shutdown()
{
    if (pDevice != VK_NULL_HANDLE && Module != VK_NULL_HANDLE)
    {
        vkDestroyShaderModule(pDevice, Module, 0);
        Module = VK_NULL_HANDLE;
    }
    pDevice = VK_NULL_HANDLE;
    pDesc = 0;
}

namespace
{
    void VertexElementToVkFormat(unsigned attr, VkFormat* outFormat, unsigned* outSize)
    {
        using namespace Render;

        unsigned type = attr & VET_Type_Mask;
        switch (type)
        {
        case VET_ColorARGB8:
            *outFormat = VK_FORMAT_B8G8R8A8_UNORM;
            *outSize = 4;
            return;
        case VET_ColorRGBA8:
            *outFormat = VK_FORMAT_R8G8B8A8_UNORM;
            *outSize = 4;
            return;
        case VET_FactorAlpha8:
        case VET_T0Weight8:
            *outFormat = VK_FORMAT_R8_UNORM;
            *outSize = 1;
            return;
        case (VET_Instance8 & VET_Type_Mask):
            *outFormat = VK_FORMAT_R8_USCALED;
            *outSize = 1;
            return;
        }

        unsigned compType = attr & VET_CompType_Mask;
        unsigned comps = attr & VET_Components_Mask;
        if (comps == 0) comps = 1;

        switch (compType)
        {
        case VET_F32:
            *outSize = 4 * comps;
            switch (comps) {
            case 1: *outFormat = VK_FORMAT_R32_SFLOAT; break;
            case 2: *outFormat = VK_FORMAT_R32G32_SFLOAT; break;
            case 3: *outFormat = VK_FORMAT_R32G32B32_SFLOAT; break;
            default: *outFormat = VK_FORMAT_R32G32B32A32_SFLOAT; break;
            }
            break;
        case VET_U8N:
            *outSize = 1 * comps;
            switch (comps) {
            case 1: *outFormat = VK_FORMAT_R8_UNORM; break;
            case 2: *outFormat = VK_FORMAT_R8G8_UNORM; break;
            default: *outFormat = VK_FORMAT_R8G8B8A8_UNORM; break;
            }
            break;
        case VET_U8:
            *outSize = 1 * comps;
            switch (comps) {
            case 1: *outFormat = VK_FORMAT_R8_UINT; break;
            default: *outFormat = VK_FORMAT_R8G8B8A8_UINT; break;
            }
            break;
        case VET_S16:
            *outSize = 2 * comps;
            switch (comps) {
            case 2: *outFormat = VK_FORMAT_R16G16_SINT; break;
            case 3: *outFormat = VK_FORMAT_R16G16B16_SINT; break;
            case 4: *outFormat = VK_FORMAT_R16G16B16A16_SINT; break;
            default: *outFormat = VK_FORMAT_R16G16_SINT; break;
            }
            break;
        case VET_U32:
            *outSize = 4 * comps;
            *outFormat = VK_FORMAT_R32_UINT;
            break;
        default:
            *outFormat = VK_FORMAT_R32G32_SFLOAT;
            *outSize = 8;
            break;
        }
    }
}

SysVertexFormat::SysVertexFormat(VkDevice device, const VertexFormat* vf, const VertexShaderDesc* vdesc)
{
    (void)device;
    memset(&BindingDesc, 0, sizeof(BindingDesc));
    memset(AttribDescs, 0, sizeof(AttribDescs));
    AttribCount = 0;

    if (!vf || !vf->pElements || !vdesc)
        return;

    unsigned count = 0;
    unsigned numShaderAttribs = Alg::Min((unsigned)vdesc->NumAttribs, (unsigned)MaxVertexAttributes);
    for (unsigned i = 0; i < numShaderAttribs; i++)
    {
        unsigned shaderUsage = vdesc->Attributes[i].Attr & VET_Usage_Mask;
        unsigned shaderIndex = vdesc->Attributes[i].Attr & VET_Index_Mask;
        for (const VertexElement* el = vf->pElements; el->Attribute != VET_None; el++)
        {
            if ((el->Attribute & VET_Usage_Mask) == shaderUsage &&
                (el->Attribute & VET_Index_Mask) == shaderIndex)
            {
                VkFormat fmt;
                unsigned size;
                VertexElementToVkFormat(el->Attribute, &fmt, &size);
                AttribDescs[count].location = i;
                AttribDescs[count].binding  = 0;
                AttribDescs[count].format   = fmt;
                AttribDescs[count].offset   = el->Offset;
                count++;
                break;
            }
        }
    }
    AttribCount = count;

    BindingDesc.binding   = 0;
    BindingDesc.stride    = vf->Size;
    BindingDesc.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
}

ShaderInterface::ShaderInterface(Render::HAL* phal)
    : pHal((HAL*)phal)
{
}

void ShaderInterface::BeginScene()
{
    CurShaders = ShaderPair();
}

bool ShaderInterface::SetStaticShader(ShaderDesc::ShaderType shader, const VertexFormat* pformat)
{
    CurShaders.pVFormat = pformat;
    CurShaders.pVS      = &pHal->SManager.StaticVShaders[VertexShaderDesc::GetShaderIndex(shader, pHal->SManager.GetShaderVersion())];
    CurShaders.pVDesc   = CurShaders.pVS->pDesc;
    CurShaders.pFS      = &pHal->SManager.StaticFShaders[FragShaderDesc::GetShaderIndex(shader, pHal->SManager.GetShaderVersion())];
    CurShaders.pFDesc   = CurShaders.pFS->pDesc;

    if (pformat && !pformat->pSysFormat)
        (const_cast<VertexFormat*>(pformat))->pSysFormat = *SF_NEW SysVertexFormat(pHal->GetDevice(), pformat, CurShaders.pVS->pDesc);

    return (bool)CurShaders;
}

void ShaderInterface::SetTexture(Shader, unsigned stage, Render::Texture* ptexture, ImageFillMode fm, unsigned index)
{
    if (!ptexture)
        return;
    Texture* pvtex = (Texture*)ptexture;
    unsigned slot = (CurShaders.pFDesc && stage < (unsigned)Uniform::SU_Count) ?
        (unsigned)(CurShaders.pFDesc->Uniforms[stage].Location >= 0 ? CurShaders.pFDesc->Uniforms[stage].Location + index : 0) : 0;
    pvtex->ApplyTexture(slot, fm);
}

void ShaderInterface::Finish(unsigned meshCount)
{
    (void)meshCount;
    VkCommandBuffer cmd = pHal->GetCurrentCommandBuffer();
    if (!cmd || !CurShaders)
        return;
    VertexShaderDesc::ShaderIndex vsi = VertexShaderDesc::GetShaderIndex(CurShaders.pVDesc->Type, pHal->SManager.GetShaderVersion());
    FragShaderDesc::ShaderIndex fsi = FragShaderDesc::GetShaderIndex(CurShaders.pFDesc->Type, pHal->SManager.GetShaderVersion());
    BlendMode blend = pHal->CurrentBlendMode;
    if (blend == Blend_None)
        blend = Blend_Normal;

    uint8_t stencilVariant = 0;
    if (pHal->GetHALState() & Render::HAL::HS_DrawingMask)
        stencilVariant = 2;  // drawing mask geometry: EQUAL+INCR, suppress color output
    else if (pHal->CurrentStencilMode == HAL::StencilMode_TestMask)
        stencilVariant = 1;  // testing against mask: GREATER_OR_EQUAL so stencil >= ref passes

    VkPipeline pipe = pHal->SManager.GetOrCreatePipeline(vsi, fsi, blend, CurShaders.pVFormat, stencilVariant);
    if (pipe != VK_NULL_HANDLE && pHal->SManager.GetSolidPipelineLayout() != VK_NULL_HANDLE)
    {
        ShaderManager& sm = pHal->SManager;
        if (sm.FrameDrawIndex >= ShaderManager::MaxDrawsPerFrame)
        {
            static unsigned s_lastOverflowLogFrame = (unsigned)-1;
            unsigned frame = (pHal->DebugFrame > 0) ? (pHal->DebugFrame - 1) : 0;
            if (s_lastOverflowLogFrame != frame)
            {
                VKDIAG("VK[F%04u] DRAW OVERFLOW at draw %u (limit %u) -- remaining draws dropped\n", frame, sm.FrameDrawIndex, ShaderManager::MaxDrawsPerFrame);
                s_lastOverflowLogFrame = frame;
            }
            memset(UniformSet, 0, sizeof(UniformSet));
            return;
        }

        unsigned sliceOffset = sm.FrameDrawIndex * sm.UniformAlignedSlice;
        char* pSlice = (char*)sm.pUniformMapped + sliceOffset;
        if (sm.pUniformMapped)
        {
            memset(pSlice, 0, sm.UniformAlignedSlice);
            for (int i = 0; i < Uniform::SU_Count; i++)
            {
                if (!UniformSet[i])
                    continue;
                const UniformVar& vvar = CurShaders.pVDesc->Uniforms[i];
                if (vvar.Size > 0 && vvar.ShadowOffset >= 0)
                {
                    unsigned byteOff = (unsigned)vvar.ShadowOffset * sizeof(float);
                    unsigned byteLen = (unsigned)vvar.Size * sizeof(float);
                    if (byteOff + byteLen <= ShaderManager::kUniformSliceSize)
                        memcpy(pSlice + byteOff, UniformData + vvar.ShadowOffset, byteLen);
                }
                const UniformVar& fvar = CurShaders.pFDesc->Uniforms[i];
                if (fvar.Size > 0 && fvar.ShadowOffset >= 0)
                {
                    unsigned byteOff = (unsigned)fvar.ShadowOffset * sizeof(float);
                    unsigned byteLen = (unsigned)fvar.Size * sizeof(float);
                    if (byteOff + byteLen <= ShaderManager::kUniformSliceSize)
                        memcpy(pSlice + byteOff, UniformData + fvar.ShadowOffset, byteLen);
                }
            }
        }

        VkDescriptorSet ds = sm.AllocateDescriptorSet();
        if (ds != VK_NULL_HANDLE)
        {
            VkDescriptorBufferInfo bufferInfo = {};
            bufferInfo.buffer = sm.UniformBuffer;
            bufferInfo.offset = sliceOffset;
            bufferInfo.range = ShaderManager::kUniformSliceSize;

            VkWriteDescriptorSet writes[2] = {};
            unsigned writeCount = 1;
            writes[0].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
            writes[0].dstSet = ds;
            writes[0].dstBinding = 0;
            writes[0].descriptorCount = 1;
            writes[0].descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
            writes[0].pBufferInfo = &bufferInfo;

            VkDescriptorImageInfo imageInfo = {};
            TextureManager* ptm = (TextureManager*)pHal->GetTextureManager();
            if (ptm)
            {
                VkImageView texView = ptm->GetCurrentTextureView(0);
                if (texView != VK_NULL_HANDLE)
                {
                    VkSampler sampler = sm.GetSamplerForFillMode(ptm->GetCurrentFillMode(0));
                    if (sampler != VK_NULL_HANDLE)
                    {
                        imageInfo.sampler = sampler;
                        imageInfo.imageView = texView;
                        imageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
                        writes[1].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
                        writes[1].dstSet = ds;
                        writes[1].dstBinding = 1;
                        writes[1].descriptorCount = 1;
                        writes[1].descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
                        writes[1].pImageInfo = &imageInfo;
                        writeCount = 2;
                    }
                }
                ptm->ClearCurrentTextureViews();
            }
            vkUpdateDescriptorSets(sm.pDevice, writeCount, writes, 0, 0);
            vkCmdBindDescriptorSets(cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, sm.GetSolidPipelineLayout(), 0, 1, &ds, 0, 0);
        }

        VKDIAG("VK[F%04u]   draw[%04u] sv=%u vsi=%u fsi=%u\n", (pHal->DebugFrame > 0) ? (pHal->DebugFrame - 1) : 0, pHal->SManager.FrameDrawIndex, (unsigned)stencilVariant, (unsigned)vsi, (unsigned)fsi);
        sm.FrameDrawIndex++;
        vkCmdBindPipeline(cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, pipe);
    }
    memset(UniformSet, 0, sizeof(UniformSet));
}

ShaderManager::ShaderManager(ProfileViews* prof)
    : StaticShaderManager(prof), pDevice(VK_NULL_HANDLE), pHal(0), ShaderModel(ShaderDesc::ShaderVersion_Default)
    , SolidPipelineLayout(VK_NULL_HANDLE), SolidPipeline(VK_NULL_HANDLE), SolidBlendPipeline(VK_NULL_HANDLE)
    , UniformSetLayout(VK_NULL_HANDLE), UniformBuffer(VK_NULL_HANDLE), UniformMemory(VK_NULL_HANDLE)
    , pUniformMapped(0), UniformAlignedSlice(0), FrameDrawIndex(0)
    , DescriptorPool(VK_NULL_HANDLE)
    , VkPipeCache(VK_NULL_HANDLE)
{
    memset(StaticVShaders, 0, sizeof(StaticVShaders));
    memset(StaticFShaders, 0, sizeof(StaticFShaders));
}

bool ShaderManager::HasInstancingSupport() const
{
    return true;
}

void ShaderManager::MapVertexFormat(PrimitiveFillType fill, const VertexFormat* sourceFormat,
                                    const VertexFormat** single, const VertexFormat** batch,
                                    const VertexFormat** instanced)
{
    VertexElement floatPositionElements[8];
    VertexFormat floatPositionFormat;
    floatPositionFormat.pElements = floatPositionElements;
    floatPositionFormat.pSysFormat = 0;
    unsigned offset = 0;
    unsigned i;
    for (i = 0; sourceFormat->pElements[i].Attribute != VET_None; ++i)
    {
        floatPositionElements[i].Attribute = sourceFormat->pElements[i].Attribute;
        if ((floatPositionElements[i].Attribute & VET_Usage_Mask) == VET_Pos)
        {
            floatPositionElements[i].Attribute &= ~VET_CompType_Mask;
            floatPositionElements[i].Attribute |= VET_F32;
            floatPositionElements[i].Offset = sourceFormat->pElements[i].Offset + offset;
            if ((sourceFormat->pElements[i].Attribute & VET_CompType_Mask) == VET_S16)
                offset += 4;
        }
        else
        {
            floatPositionElements[i].Offset = sourceFormat->pElements[i].Offset + offset;
        }
    }
    floatPositionElements[i].Attribute = VET_None;
    floatPositionElements[i].Offset    = 0;

    Base::MapVertexFormat(fill, &floatPositionFormat, single, batch, instanced,
        (HasInstancingSupport() ? MVF_HasInstancing : 0) | MVF_Align);
}

bool ShaderManager::Initialize(HAL* phal)
{
    pDevice = phal->GetDevice();
    this->pHal = phal;
    ShaderModel = ShaderDesc::ShaderVersion_Default;

    VkPipelineCacheCreateInfo pcCI = {};
    pcCI.sType = VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO;
    vkCreatePipelineCache(pDevice, &pcCI, 0, &VkPipeCache);

    for (unsigned i = 0; i < VertexShaderDesc::VSI_Count; i++)
    {
        const VertexShaderDesc* vd = VertexShaderDesc::Descs[i];
        if (vd && !StaticVShaders[i].Init(pDevice, vd))
            return false;
    }
    for (unsigned i = 0; i < FragShaderDesc::FSI_Count; i++)
    {
        const FragShaderDesc* fd = FragShaderDesc::Descs[i];
        if (fd && !StaticFShaders[i].Init(pDevice, fd))
            return false;
    }

    VkRenderPass renderPass = phal->GetRenderPass();
    VkFormat colorFormat = phal->GetColorFormat();
    VkPhysicalDevice physicalDevice = phal->pPhysicalDevice;
    memset(TextureSamplers, 0, sizeof(TextureSamplers));

    if (renderPass != VK_NULL_HANDLE && colorFormat != VK_FORMAT_UNDEFINED)
    {
        VkDescriptorSetLayoutBinding bindings[2] = {};
        bindings[0].binding = 0;
        bindings[0].descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        bindings[0].descriptorCount = 1;
        bindings[0].stageFlags = VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT;
        bindings[1].binding = 1;
        bindings[1].descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        bindings[1].descriptorCount = 1;
        bindings[1].stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;
        VkDescriptorSetLayoutCreateInfo dslInfo = {};
        dslInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
        dslInfo.bindingCount = 2;
        dslInfo.pBindings = bindings;
        if (vkCreateDescriptorSetLayout(pDevice, &dslInfo, 0, &UniformSetLayout) != VK_SUCCESS)
            return false;

        CreateTextureSamplers();

        VkPushConstantRange pushRange = {};
        pushRange.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;
        pushRange.offset = 0;
        pushRange.size = 16;

        VkPipelineLayoutCreateInfo plInfo = {};
        plInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        plInfo.setLayoutCount = 1;
        plInfo.pSetLayouts = &UniformSetLayout;
        plInfo.pushConstantRangeCount = 1;
        plInfo.pPushConstantRanges = &pushRange;
        if (vkCreatePipelineLayout(pDevice, &plInfo, 0, &SolidPipelineLayout) != VK_SUCCESS)
        {
            vkDestroyDescriptorSetLayout(pDevice, UniformSetLayout, 0);
            UniformSetLayout = VK_NULL_HANDLE;
            return false;
        }

        VkPhysicalDeviceProperties devProps;
        vkGetPhysicalDeviceProperties(physicalDevice, &devProps);
        unsigned minAlign = (unsigned)devProps.limits.minUniformBufferOffsetAlignment;
        if (minAlign < 1) minAlign = 1;
        UniformAlignedSlice = ((kUniformSliceSize + minAlign - 1) / minAlign) * minAlign;

        VkDeviceSize totalBufferSize = (VkDeviceSize)UniformAlignedSlice * MaxDrawsPerFrame;
        VkBufferCreateInfo bufInfo = {};
        bufInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
        bufInfo.size = totalBufferSize;
        bufInfo.usage = VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT;
        bufInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
        if (vkCreateBuffer(pDevice, &bufInfo, 0, &UniformBuffer) != VK_SUCCESS)
        {
            vkDestroyPipelineLayout(pDevice, SolidPipelineLayout, 0);
            vkDestroyDescriptorSetLayout(pDevice, UniformSetLayout, 0);
            SolidPipelineLayout = VK_NULL_HANDLE;
            UniformSetLayout = VK_NULL_HANDLE;
            return false;
        }
        VkMemoryRequirements memReq;
        vkGetBufferMemoryRequirements(pDevice, UniformBuffer, &memReq);
        VkPhysicalDeviceMemoryProperties memProps;
        vkGetPhysicalDeviceMemoryProperties(physicalDevice, &memProps);
        uint32_t memTypeIndex = (uint32_t)-1;
        for (uint32_t i = 0; i < memProps.memoryTypeCount; i++)
        {
            if ((memReq.memoryTypeBits & (1u << i)) &&
                (memProps.memoryTypes[i].propertyFlags & (VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT)) == (VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT))
            {
                memTypeIndex = i;
                break;
            }
        }
        if (memTypeIndex == (uint32_t)-1)
        {
            vkDestroyBuffer(pDevice, UniformBuffer, 0);
            vkDestroyPipelineLayout(pDevice, SolidPipelineLayout, 0);
            vkDestroyDescriptorSetLayout(pDevice, UniformSetLayout, 0);
            UniformBuffer = VK_NULL_HANDLE;
            SolidPipelineLayout = VK_NULL_HANDLE;
            UniformSetLayout = VK_NULL_HANDLE;
            return false;
        }
        VkMemoryAllocateInfo allocInfo = {};
        allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        allocInfo.allocationSize = memReq.size;
        allocInfo.memoryTypeIndex = memTypeIndex;
        if (vkAllocateMemory(pDevice, &allocInfo, 0, &UniformMemory) != VK_SUCCESS)
        {
            DestroyTextureSamplers();
            vkDestroyBuffer(pDevice, UniformBuffer, 0);
            vkDestroyPipelineLayout(pDevice, SolidPipelineLayout, 0);
            vkDestroyDescriptorSetLayout(pDevice, UniformSetLayout, 0);
            UniformBuffer = VK_NULL_HANDLE;
            UniformMemory = VK_NULL_HANDLE;
            SolidPipelineLayout = VK_NULL_HANDLE;
            UniformSetLayout = VK_NULL_HANDLE;
            return false;
        }
        vkBindBufferMemory(pDevice, UniformBuffer, UniformMemory, 0);
        if (vkMapMemory(pDevice, UniformMemory, 0, totalBufferSize, 0, &pUniformMapped) != VK_SUCCESS)
        {
            DestroyTextureSamplers();
            vkFreeMemory(pDevice, UniformMemory, 0);
            vkDestroyBuffer(pDevice, UniformBuffer, 0);
            vkDestroyPipelineLayout(pDevice, SolidPipelineLayout, 0);
            vkDestroyDescriptorSetLayout(pDevice, UniformSetLayout, 0);
            UniformMemory = VK_NULL_HANDLE;
            UniformBuffer = VK_NULL_HANDLE;
            pUniformMapped = 0;
            SolidPipelineLayout = VK_NULL_HANDLE;
            UniformSetLayout = VK_NULL_HANDLE;
            return false;
        }
        VkDescriptorPoolSize poolSizes[2] = {};
        poolSizes[0].type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        poolSizes[0].descriptorCount = MaxDrawsPerFrame;
        poolSizes[1].type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        poolSizes[1].descriptorCount = MaxDrawsPerFrame;
        VkDescriptorPoolCreateInfo poolInfo = {};
        poolInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
        poolInfo.poolSizeCount = 2;
        poolInfo.pPoolSizes = poolSizes;
        poolInfo.maxSets = MaxDrawsPerFrame;
        if (vkCreateDescriptorPool(pDevice, &poolInfo, 0, &DescriptorPool) != VK_SUCCESS)
        {
            DestroyTextureSamplers();
            vkUnmapMemory(pDevice, UniformMemory);
            vkFreeMemory(pDevice, UniformMemory, 0);
            vkDestroyBuffer(pDevice, UniformBuffer, 0);
            vkDestroyPipelineLayout(pDevice, SolidPipelineLayout, 0);
            vkDestroyDescriptorSetLayout(pDevice, UniformSetLayout, 0);
            pUniformMapped = 0;
            UniformMemory = VK_NULL_HANDLE;
            UniformBuffer = VK_NULL_HANDLE;
            DescriptorPool = VK_NULL_HANDLE;
            SolidPipelineLayout = VK_NULL_HANDLE;
            UniformSetLayout = VK_NULL_HANDLE;
            return false;
        }
    }

    // Use VSolid/FSolid for solid-color pipelines (generator does not emit VSI_Stub/FSI_Stub)
    const VertexShaderDesc::ShaderIndex VSI_Stub = VertexShaderDesc::VSI_Vulkan_SPIRV_VSolid;
    const FragShaderDesc::ShaderIndex FSI_Stub = FragShaderDesc::FSI_Vulkan_SPIRV_FSolid;
    if (renderPass != VK_NULL_HANDLE && SolidPipelineLayout != VK_NULL_HANDLE &&
        VSI_Stub < VertexShaderDesc::VSI_Count && FSI_Stub < FragShaderDesc::FSI_Count &&
        StaticVShaders[VSI_Stub].Module != VK_NULL_HANDLE &&
        StaticFShaders[FSI_Stub].Module != VK_NULL_HANDLE)
    {
        VkPipelineShaderStageCreateInfo stages[2] = {};
        stages[0].sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
        stages[0].stage = VK_SHADER_STAGE_VERTEX_BIT;
        stages[0].module = StaticVShaders[VSI_Stub].Module;
        stages[0].pName = "main";
        stages[1].sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
        stages[1].stage = VK_SHADER_STAGE_FRAGMENT_BIT;
        stages[1].module = StaticFShaders[FSI_Stub].Module;
        stages[1].pName = "main";

        VkVertexInputBindingDescription vb = {};
        vb.binding = 0;
        vb.stride = 16;
        vb.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
        VkVertexInputAttributeDescription va = {};
        va.location = 0;
        va.binding = 0;
        va.format = VK_FORMAT_R32G32B32A32_SFLOAT;
        va.offset = 0;
        VkPipelineVertexInputStateCreateInfo vi = {};
        vi.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
        vi.vertexBindingDescriptionCount = 1;
        vi.pVertexBindingDescriptions = &vb;
        vi.vertexAttributeDescriptionCount = 1;
        vi.pVertexAttributeDescriptions = &va;

        VkPipelineInputAssemblyStateCreateInfo ia = {};
        ia.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
        ia.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;

        VkPipelineViewportStateCreateInfo vp = {};
        vp.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
        vp.viewportCount = 1;
        vp.scissorCount = 1;

        VkPipelineRasterizationStateCreateInfo rs = {};
        rs.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
        rs.polygonMode = VK_POLYGON_MODE_FILL;
        rs.cullMode = VK_CULL_MODE_NONE;
        rs.frontFace = VK_FRONT_FACE_COUNTER_CLOCKWISE;
        rs.lineWidth = 1.0f;

        VkPipelineMultisampleStateCreateInfo ms = {};
        ms.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
        ms.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;

        VkPipelineColorBlendAttachmentState blendAtt = {};
        blendAtt.colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
        blendAtt.blendEnable = VK_FALSE;
        VkPipelineColorBlendStateCreateInfo cb = {};
        cb.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
        cb.attachmentCount = 1;
        cb.pAttachments = &blendAtt;

        VkPipelineDepthStencilStateCreateInfo ds = {};
        ds.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
        ds.depthTestEnable = VK_FALSE;
        ds.depthWriteEnable = VK_FALSE;
        ds.stencilTestEnable = VK_TRUE;
        ds.front.failOp = VK_STENCIL_OP_KEEP;
        ds.front.passOp = VK_STENCIL_OP_REPLACE;
        ds.front.depthFailOp = VK_STENCIL_OP_KEEP;
        ds.front.compareOp = VK_COMPARE_OP_ALWAYS;
        ds.front.compareMask = 0xFF;
        ds.front.writeMask = 0xFF;
        ds.front.reference = 0;
        ds.back = ds.front;

        VkDynamicState dynStates[] = {
            VK_DYNAMIC_STATE_VIEWPORT,
            VK_DYNAMIC_STATE_SCISSOR,
            VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK,
            VK_DYNAMIC_STATE_STENCIL_WRITE_MASK,
            VK_DYNAMIC_STATE_STENCIL_REFERENCE
        };
        VkPipelineDynamicStateCreateInfo dyn = {};
        dyn.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
        dyn.dynamicStateCount = 5;
        dyn.pDynamicStates = dynStates;

        VkGraphicsPipelineCreateInfo gpInfo = {};
        gpInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
        gpInfo.stageCount = 2;
        gpInfo.pStages = stages;
        gpInfo.pVertexInputState = &vi;
        gpInfo.pInputAssemblyState = &ia;
        gpInfo.pViewportState = &vp;
        gpInfo.pRasterizationState = &rs;
        gpInfo.pMultisampleState = &ms;
        gpInfo.pColorBlendState = &cb;
        gpInfo.pDepthStencilState = &ds;
        gpInfo.pDynamicState = &dyn;
        gpInfo.layout = SolidPipelineLayout;
        gpInfo.renderPass = renderPass;
        gpInfo.subpass = 0;
        if (vkCreateGraphicsPipelines(pDevice, VkPipeCache, 1, &gpInfo, 0, &SolidPipeline) != VK_SUCCESS)
        {
            vkDestroyPipelineLayout(pDevice, SolidPipelineLayout, 0);
            SolidPipelineLayout = VK_NULL_HANDLE;
            return false;
        }

        blendAtt.blendEnable = VK_TRUE;
        blendAtt.srcColorBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA;
        blendAtt.dstColorBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
        blendAtt.colorBlendOp = VK_BLEND_OP_ADD;
        blendAtt.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE;
        blendAtt.dstAlphaBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
        blendAtt.alphaBlendOp = VK_BLEND_OP_ADD;
        cb.pAttachments = &blendAtt;
        if (vkCreateGraphicsPipelines(pDevice, VkPipeCache, 1, &gpInfo, 0, &SolidBlendPipeline) != VK_SUCCESS)
        {
            vkDestroyPipeline(pDevice, SolidPipeline, 0);
            vkDestroyPipelineLayout(pDevice, SolidPipelineLayout, 0);
            SolidPipeline = VK_NULL_HANDLE;
            SolidPipelineLayout = VK_NULL_HANDLE;
            return false;
        }
        PipelineKey keyStubNone = { (unsigned)VSI_Stub, (unsigned)FSI_Stub, Blend_None, nullptr, 0 };
        PipelineKey keyStubNorm = { (unsigned)VSI_Stub, (unsigned)FSI_Stub, Blend_Normal, nullptr, 0 };
        PipelineCache[keyStubNone] = SolidPipeline;
        PipelineCache[keyStubNorm] = SolidBlendPipeline;
    }
    return true;
}

VkPipeline ShaderManager::GetOrCreatePipeline(VertexShaderDesc::ShaderIndex vsi, FragShaderDesc::ShaderIndex fsi, BlendMode blend, const VertexFormat* pvf, uint8_t stencilVariant)
{
    if (vsi >= VertexShaderDesc::VSI_Count || fsi >= FragShaderDesc::FSI_Count)
        return VK_NULL_HANDLE;
    PipelineKey key = { (unsigned)vsi, (unsigned)fsi, blend, pvf, stencilVariant };
    auto it = PipelineCache.find(key);
    if (it != PipelineCache.end())
        return it->second;

    const VertexShaderDesc* vd = VertexShaderDesc::Descs[vsi];
    const FragShaderDesc* fd = FragShaderDesc::Descs[fsi];
    if (!vd || !fd || !StaticVShaders[vsi].Module || !StaticFShaders[fsi].Module)
        return VK_NULL_HANDLE;

    VkRenderPass renderPass = pHal->GetRenderPass();
    if (renderPass == VK_NULL_HANDLE || SolidPipelineLayout == VK_NULL_HANDLE)
        return VK_NULL_HANDLE;

    VkPipelineVertexInputStateCreateInfo vi = {};
    VkVertexInputBindingDescription vb = {};
    VkVertexInputAttributeDescription vas[VertexShaderDesc::MaxVertexAttributes];
    unsigned attribCount = 0;

    if (pvf && pvf->pElements && vd->NumAttribs > 0)
    {
        unsigned numShaderAttribs = Alg::Min((unsigned)vd->NumAttribs, (unsigned)VertexShaderDesc::MaxVertexAttributes);
        for (unsigned i = 0; i < numShaderAttribs; i++)
        {
            unsigned shaderUsage = vd->Attributes[i].Attr & VET_Usage_Mask;
            unsigned shaderIndex = vd->Attributes[i].Attr & VET_Index_Mask;
            for (const VertexElement* el = pvf->pElements; el->Attribute != VET_None; el++)
            {
                if ((el->Attribute & VET_Usage_Mask) == shaderUsage &&
                    (el->Attribute & VET_Index_Mask) == shaderIndex)
                {
                    VkFormat fmt;
                    unsigned size;
                    VertexElementToVkFormat(el->Attribute, &fmt, &size);
                    vas[attribCount].location = i;
                    vas[attribCount].binding = 0;
                    vas[attribCount].format = fmt;
                    vas[attribCount].offset = el->Offset;
                    attribCount++;
                    break;
                }
            }
        }
        vb.binding = 0;
        vb.stride = pvf->Size;
        vb.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
        vi.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
        vi.vertexBindingDescriptionCount = 1;
        vi.pVertexBindingDescriptions = &vb;
        vi.vertexAttributeDescriptionCount = attribCount;
        vi.pVertexAttributeDescriptions = vas;
    }
    else
    {
        vb.binding = 0;
        vb.stride = 8;
        vb.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
        vas[0].location = 0;
        vas[0].binding = 0;
        vas[0].format = VK_FORMAT_R32G32_SFLOAT;
        vas[0].offset = 0;
        attribCount = 1;
        vi.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
        vi.vertexBindingDescriptionCount = 1;
        vi.pVertexBindingDescriptions = &vb;
        vi.vertexAttributeDescriptionCount = 1;
        vi.pVertexAttributeDescriptions = vas;
    }

    VkPipelineShaderStageCreateInfo stages[2] = {};
    stages[0].sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    stages[0].stage = VK_SHADER_STAGE_VERTEX_BIT;
    stages[0].module = StaticVShaders[vsi].Module;
    stages[0].pName = "main";
    stages[1].sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    stages[1].stage = VK_SHADER_STAGE_FRAGMENT_BIT;
    stages[1].module = StaticFShaders[fsi].Module;
    stages[1].pName = "main";

    VkPipelineInputAssemblyStateCreateInfo ia = {};
    ia.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
    ia.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;

    VkPipelineViewportStateCreateInfo vp = {};
    vp.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
    vp.viewportCount = 1;
    vp.scissorCount = 1;

    VkPipelineRasterizationStateCreateInfo rs = {};
    rs.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
    rs.polygonMode = VK_POLYGON_MODE_FILL;
    rs.cullMode = VK_CULL_MODE_NONE;
    rs.frontFace = VK_FRONT_FACE_COUNTER_CLOCKWISE;
    rs.lineWidth = 1.0f;

    VkPipelineMultisampleStateCreateInfo ms = {};
    ms.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
    ms.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;

    // Stencil variant: 0=normal, 1=TestMask (GREATER_OR_EQUAL/KEEP), 2=WriteMask (EQUAL/INCR/no color write)
    VkCompareOp         stencilCompareOp  = VK_COMPARE_OP_ALWAYS;
    VkStencilOp         stencilPassOp     = VK_STENCIL_OP_REPLACE;
    VkColorComponentFlags colorWriteMaskBits =
        VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT |
        VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
    if (stencilVariant == 1)
    {
        // D3D1x uses COMPARISON_LESS_EQUAL with (ref <= stencil), i.e. stencil >= ref.
        // Vulkan's GREATER_OR_EQUAL (stencil >= ref) is the exact equivalent.
        stencilCompareOp = VK_COMPARE_OP_GREATER_OR_EQUAL;
        stencilPassOp    = VK_STENCIL_OP_KEEP;
    }
    else if (stencilVariant == 2)
    {
        // D3D1x uses EQUAL(parent_depth) + INCR so that mask geometry only writes
        // the new depth inside the parent mask's existing area.  ALWAYS+REPLACE was
        // wrong: it would overwrite areas outside the parent mask, corrupting the
        // stencil buffer for subsequent GREATER_EQUAL tests.
        stencilCompareOp = VK_COMPARE_OP_EQUAL;
        stencilPassOp    = VK_STENCIL_OP_INCREMENT_AND_CLAMP;
        colorWriteMaskBits = 0;
    }

    VkPipelineColorBlendAttachmentState blendAtt = {};
    blendAtt.colorWriteMask = colorWriteMaskBits;
    blendAtt.blendEnable = (stencilVariant != 2 &&
                            blend != Blend_None && blend != Blend_Overwrite && blend != Blend_OverwriteAll) ? VK_TRUE : VK_FALSE;
    if (blendAtt.blendEnable)
    {
        blendAtt.srcColorBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA;
        blendAtt.dstColorBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
        blendAtt.colorBlendOp = VK_BLEND_OP_ADD;
        blendAtt.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE;
        blendAtt.dstAlphaBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
        blendAtt.alphaBlendOp = VK_BLEND_OP_ADD;
    }
    VkPipelineColorBlendStateCreateInfo cb = {};
    cb.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
    cb.attachmentCount = 1;
    cb.pAttachments = &blendAtt;

    VkPipelineDepthStencilStateCreateInfo ds = {};
    ds.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
    ds.depthTestEnable = VK_FALSE;
    ds.depthWriteEnable = VK_FALSE;
    ds.stencilTestEnable = VK_TRUE;
    ds.front.failOp      = VK_STENCIL_OP_KEEP;
    ds.front.passOp      = stencilPassOp;
    ds.front.depthFailOp = VK_STENCIL_OP_KEEP;
    ds.front.compareOp   = stencilCompareOp;
    ds.front.compareMask = 0xFF;
    ds.front.writeMask   = 0xFF;
    ds.front.reference   = 0;
    ds.back = ds.front;

    VkDynamicState dynStates[] = {
        VK_DYNAMIC_STATE_VIEWPORT,
        VK_DYNAMIC_STATE_SCISSOR,
        VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK,
        VK_DYNAMIC_STATE_STENCIL_WRITE_MASK,
        VK_DYNAMIC_STATE_STENCIL_REFERENCE
    };
    VkPipelineDynamicStateCreateInfo dyn = {};
    dyn.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
    dyn.dynamicStateCount = 5;
    dyn.pDynamicStates = dynStates;

    VkGraphicsPipelineCreateInfo gpInfo = {};
    gpInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
    gpInfo.stageCount = 2;
    gpInfo.pStages = stages;
    gpInfo.pVertexInputState = &vi;
    gpInfo.pInputAssemblyState = &ia;
    gpInfo.pViewportState = &vp;
    gpInfo.pRasterizationState = &rs;
    gpInfo.pMultisampleState = &ms;
    gpInfo.pColorBlendState = &cb;
    gpInfo.pDepthStencilState = &ds;
    gpInfo.pDynamicState = &dyn;
    gpInfo.layout = SolidPipelineLayout;
    gpInfo.renderPass = renderPass;
    gpInfo.subpass = 0;

    VkPipeline pipe = VK_NULL_HANDLE;
    if (vkCreateGraphicsPipelines(pDevice, VkPipeCache, 1, &gpInfo, 0, &pipe) == VK_SUCCESS)
        PipelineCache[key] = pipe;
    return pipe;
}

void ShaderManager::CreateTextureSamplers()
{
    for (unsigned i = 0; i < 4; i++)
    {
        bool clamp = (i >= 2);
        bool linear = (i & 1) != 0;
        VkSamplerCreateInfo sci = {};
        sci.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
        sci.magFilter = linear ? VK_FILTER_LINEAR : VK_FILTER_NEAREST;
        sci.minFilter = linear ? VK_FILTER_LINEAR : VK_FILTER_NEAREST;
        sci.mipmapMode = VK_SAMPLER_MIPMAP_MODE_NEAREST;
        sci.addressModeU = clamp ? VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE : VK_SAMPLER_ADDRESS_MODE_REPEAT;
        sci.addressModeV = sci.addressModeU;
        sci.addressModeW = sci.addressModeU;
        sci.mipLodBias = 0.f;
        sci.anisotropyEnable = VK_FALSE;
        sci.maxAnisotropy = 1.f;
        sci.compareEnable = VK_FALSE;
        sci.minLod = 0.f;
        sci.maxLod = 0.25f;
        sci.borderColor = VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK;
        if (vkCreateSampler(pDevice, &sci, 0, &TextureSamplers[i]) != VK_SUCCESS)
            TextureSamplers[i] = VK_NULL_HANDLE;
    }
}

void ShaderManager::DestroyTextureSamplers()
{
    for (unsigned i = 0; i < 4; i++)
    {
        if (TextureSamplers[i] != VK_NULL_HANDLE)
        {
            vkDestroySampler(pDevice, TextureSamplers[i], 0);
            TextureSamplers[i] = VK_NULL_HANDLE;
        }
    }
}

VkSampler ShaderManager::GetSamplerForFillMode(ImageFillMode fm) const
{
    unsigned wrap = (fm.Fill & Render::Wrap_Mask) ? 2u : 0u;
    unsigned sample = (fm.Fill & Render::Sample_Mask) ? 1u : 0u;
    unsigned idx = wrap + sample;
    return (idx < 4u) ? TextureSamplers[idx] : TextureSamplers[0];
}

VkDescriptorSet ShaderManager::AllocateDescriptorSet()
{
    if (DescriptorPool == VK_NULL_HANDLE || UniformSetLayout == VK_NULL_HANDLE)
        return VK_NULL_HANDLE;
    VkDescriptorSetAllocateInfo setAlloc = {};
    setAlloc.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
    setAlloc.descriptorPool = DescriptorPool;
    setAlloc.descriptorSetCount = 1;
    setAlloc.pSetLayouts = &UniformSetLayout;
    VkDescriptorSet ds = VK_NULL_HANDLE;
    if (vkAllocateDescriptorSets(pDevice, &setAlloc, &ds) != VK_SUCCESS)
        return VK_NULL_HANDLE;
    return ds;
}

void ShaderManager::Reset()
{
    DestroyTextureSamplers();
    for (auto& it : PipelineCache)
    {
        if (it.second != VK_NULL_HANDLE)
            vkDestroyPipeline(pDevice, it.second, 0);
    }
    PipelineCache.clear();
    if (SolidBlendPipeline != VK_NULL_HANDLE)
    {
        vkDestroyPipeline(pDevice, SolidBlendPipeline, 0);
        SolidBlendPipeline = VK_NULL_HANDLE;
    }
    if (SolidPipeline != VK_NULL_HANDLE)
    {
        vkDestroyPipeline(pDevice, SolidPipeline, 0);
        SolidPipeline = VK_NULL_HANDLE;
    }
    if (SolidPipelineLayout != VK_NULL_HANDLE)
    {
        vkDestroyPipelineLayout(pDevice, SolidPipelineLayout, 0);
        SolidPipelineLayout = VK_NULL_HANDLE;
    }
    if (pUniformMapped)
    {
        vkUnmapMemory(pDevice, UniformMemory);
        pUniformMapped = 0;
    }
    if (UniformMemory != VK_NULL_HANDLE)
    {
        vkFreeMemory(pDevice, UniformMemory, 0);
        UniformMemory = VK_NULL_HANDLE;
    }
    if (UniformBuffer != VK_NULL_HANDLE)
    {
        vkDestroyBuffer(pDevice, UniformBuffer, 0);
        UniformBuffer = VK_NULL_HANDLE;
    }
    if (DescriptorPool != VK_NULL_HANDLE)
    {
        vkDestroyDescriptorPool(pDevice, DescriptorPool, 0);
        DescriptorPool = VK_NULL_HANDLE;
    }
    if (UniformSetLayout != VK_NULL_HANDLE)
    {
        vkDestroyDescriptorSetLayout(pDevice, UniformSetLayout, 0);
        UniformSetLayout = VK_NULL_HANDLE;
    }
    if (VkPipeCache != VK_NULL_HANDLE)
    {
        vkDestroyPipelineCache(pDevice, VkPipeCache, 0);
        VkPipeCache = VK_NULL_HANDLE;
    }
    for (unsigned i = 0; i < VertexShaderDesc::VSI_Count; i++)
        StaticVShaders[i].Shutdown();
    for (unsigned i = 0; i < FragShaderDesc::FSI_Count; i++)
        StaticFShaders[i].Shutdown();
}

void ShaderManager::BeginScene()
{
    if (pHal)
        VKDIAG("VK[F%04u] BeginScene prevFrameDraws=%u\n", pHal->DebugFrame, FrameDrawIndex);
    FrameDrawIndex = 0;
    if (DescriptorPool != VK_NULL_HANDLE)
        vkResetDescriptorPool(pDevice, DescriptorPool, 0);
}

void ShaderManager::EndScene()
{
}

}}} // Scaleform::Render::Vulkan
