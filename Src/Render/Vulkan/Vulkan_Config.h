/**************************************************************************

Filename    :   Vulkan_Config.h
Content     :   Vulkan backend configuration.
Created     :   2025
Authors     :   Vulkan backend

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/

#ifndef INC_SF_VULKAN_CONFIG_H
#define INC_SF_VULKAN_CONFIG_H
#pragma once

#include <vulkan/vulkan.h>

// Set to 1 to enable per-frame diagnostic printf logging (stdout); 0 to disable.
#define GFXVK_DIAG_LOG 1

#if GFXVK_DIAG_LOG
#  include <cstdio>
#  define VKDIAG(fmt, ...) do { printf(fmt, ##__VA_ARGS__); fflush(stdout); } while(0)
#else
#  define VKDIAG(fmt, ...) do {} while(0)
#endif

namespace Scaleform { namespace Render { namespace Vulkan {

// Vulkan backend configuration flags (extend as needed).
enum HALConfigFlags
{
};

}}} // Scaleform::Render::Vulkan

#endif // INC_SF_VULKAN_CONFIG_H
