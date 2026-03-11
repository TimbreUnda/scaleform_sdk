/**************************************************************************

Filename    :   Video_CriHeap.cpp
Content     :   Video memory allocator for CRI Mana
Created     :   June 4, 2008
Authors     :   Maxim Didenko, Vladislav Merker

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/

#include "GFxConfig.h"
#ifdef GFX_ENABLE_VIDEO

#include "Kernel/SF_Types.h"
#include "Kernel/SF_HeapNew.h"
#include "Video/Video_CriHeap.h"

#include "Kernel/SF_Memory.h"
#if defined(SF_BUILD_DEFINE_NEW) && defined(SF_DEFINE_NEW)
#undef new
#endif
#include <cri_mana.h>
#include <cri_atom_ex.h>
#if defined(SF_BUILD_DEFINE_NEW) && defined(SF_DEFINE_NEW)
#define new SF_DEFINE_NEW
#endif

namespace Scaleform { namespace GFx { namespace Video {

//////////////////////////////////////////////////////////////////////////
//

static MemoryHeap* s_pManaHeap = NULL;

static void* CRIAPI manaAllocFunc(void* obj, CriUint32 size)
{
    SF_UNUSED(obj);
    SF_ASSERT(s_pManaHeap);
    void* ptr = SF_HEAP_MEMALIGN(s_pManaHeap, size, 16, Stat_Video_Mem);
    return ptr;
}

static void CRIAPI manaFreeFunc(void* obj, void* mem)
{
    SF_UNUSED(obj);
    if (mem)
        SF_FREE_ALIGN(mem);
}

void criManaHeap_Register(MemoryHeap* pHeap)
{
    s_pManaHeap = pHeap;
    criAtomEx_SetUserAllocator(manaAllocFunc, manaFreeFunc, NULL);
    criMana_SetUserAllocator(manaAllocFunc, manaFreeFunc, NULL);
}

void criManaHeap_Unregister()
{
    criMana_SetUserAllocator(NULL, NULL, NULL);
    criAtomEx_SetUserAllocator(NULL, NULL, NULL);
    s_pManaHeap = NULL;
}

}}} // Scaleform::GFx::Video

#endif // GFX_ENABLE_VIDEO
