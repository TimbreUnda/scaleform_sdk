/**************************************************************************

Filename    :   Video_CriMvSoundGateway.h
Content     :   Video sound data gateway (LEGACY STUB - CRI Mana uses CriAtomEx for audio)
Created     :   October 2008
Authors     :   Maxim Didenko, Vladislav Merker

Copyright   :   Copyright 2011 Autodesk, Inc. All Rights reserved.

Use of this software is subject to the terms of the Autodesk license
agreement provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/

#ifndef INC_GFX_VIDEO_CRIMVSOUNDGATEWAY_H
#define INC_GFX_VIDEO_CRIMVSOUNDGATEWAY_H

#include "GFxConfig.h"
#ifdef GFX_ENABLE_VIDEO

// CRI Mana 2019 uses CriAtomEx (WASAPI on PC) for audio output internally.
// The CriMvSoundInterface bridge is no longer needed.
// This header is kept for backward compatibility.

#endif // GFX_ENABLE_VIDEO

#endif // INC_GFX_VIDEO_CRIMVSOUNDGATEWAY_H
