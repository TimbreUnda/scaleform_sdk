/**************************************************************************

Filename    :   Vulkan_Sync.h
Content     :   Vulkan GPU/CPU synchronization (optional stub).
Created     :   2025
Authors     :   Vulkan backend

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

**************************************************************************/

#ifndef INC_SF_VULKAN_SYNC_H
#define INC_SF_VULKAN_SYNC_H
#pragma once

#include "Render/Vulkan/Vulkan_Config.h"
#include "Render/Render_Sync.h"

namespace Scaleform { namespace Render { namespace Vulkan {

class RenderSync : public Render::RenderSync
{
public:
    RenderSync() {}
    bool SetDevice(VkDevice device, VkQueue queue) { (void)device; (void)queue; return true; }
    virtual void BeginFrame() { Render::RenderSync::BeginFrame(); }
    virtual bool EndFrame() { return Render::RenderSync::EndFrame(); }
    virtual void KickOffFences(Render::FenceType waitType) { (void)waitType; }
    virtual bool IsPending(Render::FenceType waitType, UInt64 handle, const Render::FenceFrame& parent) { (void)waitType; (void)handle; (void)parent; return false; }
    virtual void WaitFence(Render::FenceType waitType, UInt64 handle, const Render::FenceFrame& parent) { (void)waitType; (void)handle; (void)parent; }
    virtual UInt64 SetFence() { return 0; }
};

}}} // Scaleform::Render::Vulkan

#endif // INC_SF_VULKAN_SYNC_H
