/**************************************************************************

Filename    :   Vulkan_Events.h
Content     :   Vulkan render events for profiling (optional stub).
Created     :   2025
Authors     :   Vulkan backend

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

**************************************************************************/

#ifndef INC_SF_VULKAN_EVENTS_H
#define INC_SF_VULKAN_EVENTS_H
#pragma once

#include "Render/Vulkan/Vulkan_Config.h"
#include "Render/Render_Events.h"

namespace Scaleform { namespace Render { namespace Vulkan {

class RenderEvent : public Render::RenderEvent
{
public:
    static void InitializeEvents(VkDevice device) { (void)device; }
    virtual void Begin(const char* name) { (void)name; }
    virtual void End() {}
};

}}} // Scaleform::Render::Vulkan

#endif // INC_SF_VULKAN_EVENTS_H
