/**************************************************************************

Filename    :   Video_CriHeap.h
Content     :   Video memory allocator for CRI Mana
Created     :   June 4, 2008
Authors     :   Maxim Didenko, Vladislav Merker

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/

#ifndef INC_GFX_VIDEO_CRIHEAP_H
#define INC_GFX_VIDEO_CRIHEAP_H

#include "GFxConfig.h"
#ifdef GFX_ENABLE_VIDEO

#include "Kernel/SF_MemoryHeap.h"

namespace Scaleform { namespace GFx { namespace Video {

// Register Scaleform memory heap as the allocator for CRI Mana library.
// Must be called before criMana_Initialize.
void criManaHeap_Register(MemoryHeap* pHeap);

// Unregister the Scaleform memory allocator from CRI Mana.
// Call after criMana_Finalize.
void criManaHeap_Unregister();

}}} // Scaleform::GFx::Video

#endif // GFX_ENABLE_VIDEO

#endif // INC_GFX_VIDEO_CRIHEAP_H
