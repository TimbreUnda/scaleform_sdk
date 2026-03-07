/**************************************************************************

Filename    :   Vulkan_Shader.h
Content     :   Vulkan shader manager and interface (scaffold).
Created     :   2025
Authors     :   Vulkan backend

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

**************************************************************************/

#ifndef INC_SF_VULKAN_SHADER_H
#define INC_SF_VULKAN_SHADER_H
#pragma once

#include <map>
#include "Render/Vulkan/Vulkan_Config.h"
#include "Render/Vulkan/Vulkan_ShaderDescs.h"
#include "Render/Render_Shader.h"
#include "Render/Render_States.h"
#include "Render/Render_Image.h"

namespace Scaleform { namespace Render { namespace Vulkan {

class HAL;
class Texture;
class TextureManager;

struct VertexShader
{
    const VertexShaderDesc* pDesc;
    VkShaderModule          Module;
    VkDevice                pDevice;

    VertexShader() : pDesc(0), Module(VK_NULL_HANDLE), pDevice(VK_NULL_HANDLE) {}
    ~VertexShader() { Shutdown(); }

    bool Init(VkDevice device, const VertexShaderDesc* pd);
    void Shutdown();
};

struct FragShader
{
    const FragShaderDesc* pDesc;
    VkShaderModule       Module;
    VkDevice             pDevice;

    FragShader() : pDesc(0), Module(VK_NULL_HANDLE), pDevice(VK_NULL_HANDLE) {}
    ~FragShader() { Shutdown(); }

    bool Init(VkDevice device, const FragShaderDesc* pd);
    void Shutdown();
};

struct ShaderPair
{
    const VertexShader*     pVS;
    const VertexShaderDesc* pVDesc;
    const FragShader*       pFS;
    const FragShaderDesc*   pFDesc;
    const VertexFormat*     pVFormat;

    ShaderPair() : pVS(0), pVDesc(0), pFS(0), pFDesc(0), pVFormat(0) {}

    const ShaderPair* operator->() const { return this; }
    operator bool() const { return pVS && pFS && pVDesc && pFDesc && pVFormat; }
};

class SysVertexFormat : public Render::SystemVertexFormat
{
public:
    static const unsigned MaxVertexAttributes = 8;
    VkVertexInputBindingDescription   BindingDesc;
    VkVertexInputAttributeDescription AttribDescs[MaxVertexAttributes];
    unsigned                          AttribCount;

    SysVertexFormat(VkDevice device, const VertexFormat* vf, const VertexShaderDesc* vdesc);
};

class ShaderInterface : public ShaderInterfaceBase<Uniform, ShaderPair>
{
    friend class ShaderManager;

    HAL*        pHal;
    ShaderPair  CurShaders;

public:
    typedef const ShaderPair Shader;

    ShaderInterface(Render::HAL* phal);

    void           BeginScene();
    const Shader&  GetCurrentShaders() const { return CurShaders; }
    bool           SetStaticShader(ShaderDesc::ShaderType shader, const VertexFormat* pvf);
    void           SetTexture(Shader, unsigned stage, Render::Texture* ptexture, ImageFillMode fm, unsigned index = 0);
    void           Finish(unsigned meshCount);
};

class ShaderManager : public StaticShaderManager<ShaderDesc, VertexShaderDesc, Uniform, ShaderInterface, Texture>
{
    friend class ShaderInterface;
public:
    typedef StaticShaderManager<ShaderDesc, VertexShaderDesc, Uniform, ShaderInterface, Texture> Base;
    typedef Uniform UniformType;

    static const unsigned kUniformSliceSize = Uniform::SU_TotalSize * sizeof(float);
    static const unsigned MaxDrawsPerFrame = 512;

    ShaderManager(ProfileViews* prof);

    void MapVertexFormat(PrimitiveFillType fill, const VertexFormat* sourceFormat,
                         const VertexFormat** single, const VertexFormat** batch, const VertexFormat** instanced);

    bool HasInstancingSupport() const;
    bool Initialize(HAL* phal);
    void Reset();

    void BeginScene();
    void EndScene();

    ShaderDesc::ShaderVersion GetShaderVersion() const { return ShaderModel; }
    static unsigned GetDrawableImageFlags() { return 0; }

    VkPipelineLayout GetSolidPipelineLayout() const { return SolidPipelineLayout; }
    VkPipeline       GetSolidPipeline() const       { return SolidPipeline; }
    VkPipeline       GetSolidBlendPipeline() const  { return SolidBlendPipeline; }

    // stencilVariant: 0=normal (ALWAYS/REPLACE/color), 1=test (GREATER_OR_EQUAL/KEEP/color), 2=maskWrite (EQUAL/INCR/no color)
    VkPipeline GetOrCreatePipeline(VertexShaderDesc::ShaderIndex vsi, FragShaderDesc::ShaderIndex fsi, BlendMode blend, const VertexFormat* pvf, uint8_t stencilVariant = 0);

private:
    struct PipelineKey
    {
        unsigned VSI;
        unsigned FSI;
        BlendMode Blend;
        const VertexFormat* pVF;
        uint8_t StencilVariant;
        bool operator<(const PipelineKey& o) const
        {
            if (VSI != o.VSI) return VSI < o.VSI;
            if (FSI != o.FSI) return FSI < o.FSI;
            if (Blend != o.Blend) return Blend < o.Blend;
            if (pVF != o.pVF) return pVF < o.pVF;
            return StencilVariant < o.StencilVariant;
        }
    };

    FragShader   StaticFShaders[FragShaderDesc::FSI_Count];
    VertexShader StaticVShaders[VertexShaderDesc::VSI_Count];

    VkDevice           pDevice;
    HAL*               pHal;
    ShaderDesc::ShaderVersion ShaderModel;

    VkPipelineLayout   SolidPipelineLayout;
    VkPipeline         SolidPipeline;
    VkPipeline         SolidBlendPipeline;

    VkDescriptorSetLayout UniformSetLayout;
    VkBuffer           UniformBuffer;
    VkDeviceMemory     UniformMemory;
    void*              pUniformMapped;
    unsigned           UniformAlignedSlice;
    unsigned           FrameDrawIndex;
    VkDescriptorPool   DescriptorPool;
    VkDescriptorSet    AllocateDescriptorSet();

    VkSampler          TextureSamplers[4];

    void CreateTextureSamplers();
    void DestroyTextureSamplers();
    VkSampler GetSamplerForFillMode(ImageFillMode fm) const;

    VkPipelineCache    VkPipeCache;
    std::map<PipelineKey, VkPipeline> PipelineCache;
};

}}} // Scaleform::Render::Vulkan

#endif // INC_SF_VULKAN_SHADER_H
