/**************************************************************************

Filename    :   Video_CriMvSystemTimer.h
Content     :   Video system timer (LEGACY STUB - CRI Mana has built-in timer modes)
Created     :   June 4, 2008
Authors     :   Maxim Didenko, Vladislav Merker

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/

#ifndef INC_GFX_VIDEO_CRIMVSYSTEMTIMER_H
#define INC_GFX_VIDEO_CRIMVSYSTEMTIMER_H

#include "GFxConfig.h"
#ifdef GFX_ENABLE_VIDEO

// CRI Mana 2019 has built-in timer modes (SYSTEM, AUDIO, MANUAL).
// The CriMvSystemTimerInterface wrapper is no longer needed.
// This header is kept for backward compatibility.

#include "Kernel/SF_RefCount.h"
#include "Video/Video_Video.h"

namespace Scaleform { namespace GFx { namespace Video {

//////////////////////////////////////////////////////////////////////////
// SystemTimerSyncObject is still used by VideoPlayerImpl for external sync

class SystemTimerSyncObject : public VideoPlayer::SyncObject
{
public:
    SystemTimerSyncObject() : pause_flag(false), time_count(0), time_unit(1000000), total_count(0) {}
    ~SystemTimerSyncObject() {}

    virtual void SetStartFrame(unsigned) {}
    virtual void Start(void);
    virtual void Stop(void);
    virtual void Pause(bool sw);
    virtual void GetTime(UInt64 *count, UInt64 *unit);

private:
    bool        pause_flag;
    UInt64      time_count;
    UInt64      time_unit;
    UInt64      total_count;
    UInt64      StartTicks;
    UInt64      StopTicks;
    bool        IsRunning;
};

}}} // Scaleform::GFx::Video

#endif // GFX_ENABLE_VIDEO

#endif // INC_GFX_VIDEO_CRIMVSYSTEMTIMER_H
