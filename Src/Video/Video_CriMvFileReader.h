/**************************************************************************

Filename    :   Video_CriMvFileReader.h
Content     :   Video file reader (LEGACY STUB - CRI Mana handles file I/O internally)
Created     :   July 2008
Authors     :   Maxim Didenko, Vladislav Merker

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/

#ifndef INC_GFX_VIDEO_CRIMVFILEREADER_H
#define INC_GFX_VIDEO_CRIMVFILEREADER_H

#include "GFxConfig.h"
#ifdef GFX_ENABLE_VIDEO

// CRI Mana 2019 handles file I/O internally via its own file system (CRI FS).
// The CriMvFileReaderInterface wrapper is no longer needed.
// This header is kept for backward compatibility with any code that includes it.

#include "Kernel/SF_RefCount.h"
#include "Kernel/SF_MemoryHeap.h"
#include "Kernel/SF_Threads.h"

#include "GFx/GFx_Loader.h"
#include "Video/Video_Video.h"

namespace Scaleform { namespace GFx { namespace Video {

class VideoReader;

//////////////////////////////////////////////////////////////////////////
// Simplified VideoReaderConfig (no CRI interfaces)

class VideoReaderConfigSmp : public VideoReaderConfig
{
public:
    VideoReaderConfigSmp(MemoryHeap* pheap, FileOpenerBase* pfileopener) :
        VideoReaderConfig(pheap, pfileopener) {}
    ~VideoReaderConfigSmp() {}

    virtual VideoReader* CreateReader() { return NULL; }
};

//////////////////////////////////////////////////////////////////////////
//

class VideoReaderConfigThrd : public VideoReaderConfig
{
public:
    VideoReaderConfigThrd(MemoryHeap* pheap, FileOpenerBase* pfileopener) :
        VideoReaderConfig(pheap, pfileopener) {}
    ~VideoReaderConfigThrd() {}

    virtual VideoReader* CreateReader() { return NULL; }
    virtual void SetReadCallback(ReadCallback*) {}
    virtual void EnableIO(bool) {}
    virtual void DetachReader(VideoReader*) {}
};

}}} // Scaleform::GFx::Video

#endif // GFX_ENABLE_VIDEO

#endif // INC_GFX_VIDEO_CRIMVFILEREADER_H
