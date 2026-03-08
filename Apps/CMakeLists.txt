# Scaleform SDK sample applications.
#
# Common source files shared across most sample apps.
set(SF_APP_COMMON_SOURCES
    ${CMAKE_SOURCE_DIR}/Apps/Samples/Common/FontConfigParser.cpp
    ${CMAKE_SOURCE_DIR}/Apps/Samples/Common/FxAmpAppControlCallback.cpp
    ${CMAKE_SOURCE_DIR}/Apps/Samples/Common/FxPlayerAppBase.cpp
    ${CMAKE_SOURCE_DIR}/Apps/Samples/Common/FxPlayerAutotest.cpp
    ${CMAKE_SOURCE_DIR}/Apps/Samples/Common/FxRenderThread.cpp
    ${CMAKE_SOURCE_DIR}/Apps/Samples/Common/FxSharedObjectManager.cpp
    ${CMAKE_SOURCE_DIR}/Apps/Samples/Common/FxSoundFMOD.cpp
)

# Helper: configure a full sample app (Platform + renderer + sound + common)
# Usage: sf_add_sample_app(<name> <renderer_target> <platform_target> SOURCES ...)
function(sf_add_sample_app name renderer_target platform_target)
    cmake_parse_arguments(ARG "" "" "SOURCES;EXTRA_DEFS" ${ARGN})

    # Platform-based apps use wmain() via SF_PLATFORM_SYSTEM_APP — console subsystem
    add_executable(${name} ${SF_APP_COMMON_SOURCES} ${ARG_SOURCES})
    sf_apply_app_flags(${name})
    target_link_libraries(${name} PRIVATE
        sf_core
        ${renderer_target}
        ${platform_target}
        gfxsound_fmod
        dsound Msacm32
    )
    target_compile_definitions(${name} PRIVATE ${ARG_EXTRA_DEFS})
    set_target_properties(${name} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,Win32>/Msvc10/${name}"
    )
endfunction()

# ---------------------------------------------------------------------------
# GFxPlayerTinyVulkan (Vulkan-only, minimal — no Platform lib needed)
# ---------------------------------------------------------------------------
if(SF_RENDERER_VULKAN)
    add_executable(GFxPlayerTinyVulkan WIN32
        ${CMAKE_SOURCE_DIR}/Apps/Samples/GFxPlayerTiny/GFxPlayerTinyVulkan.cpp
    )
    sf_apply_app_flags(GFxPlayerTinyVulkan)
    target_link_libraries(GFxPlayerTinyVulkan PRIVATE
        sf_core
        gfxrender_vulkan
    )
    target_link_options(GFxPlayerTinyVulkan PRIVATE
        /WHOLEARCHIVE:libgfxrender_vulkan
    )
    set_target_properties(GFxPlayerTinyVulkan PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,Win32>/Msvc10/GFxPlayerTinyVulkan"
    )
endif()

# ---------------------------------------------------------------------------
# PlayerTiny -- minimal player (D3D9/D3D10/D3D11/GL, each a separate target)
# ---------------------------------------------------------------------------
if(SF_RENDERER_D3D11)
    add_executable(PlayerTiny_D3D11 WIN32
        ${CMAKE_SOURCE_DIR}/Apps/Samples/Common/FxSoundFMOD.cpp
        ${CMAKE_SOURCE_DIR}/Apps/Samples/GFxPlayerTiny/GFxPlayerTinyD3D1x.cpp
    )
    sf_apply_app_flags(PlayerTiny_D3D11)
    target_link_libraries(PlayerTiny_D3D11 PRIVATE
        sf_core gfxrender_d3d1x gfxsound_fmod dsound Msacm32
    )
    set_target_properties(PlayerTiny_D3D11 PROPERTIES
        OUTPUT_NAME "PlayerTiny"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,Win32>/Msvc10/PlayerTiny"
    )
endif()

if(SF_RENDERER_D3D9)
    add_executable(PlayerTiny_D3D9 WIN32
        ${CMAKE_SOURCE_DIR}/Apps/Samples/Common/FxSoundFMOD.cpp
        ${CMAKE_SOURCE_DIR}/Apps/Samples/GFxPlayerTiny/GFxPlayerTinyD3D9.cpp
    )
    sf_apply_app_flags(PlayerTiny_D3D9)
    target_link_libraries(PlayerTiny_D3D9 PRIVATE
        sf_core gfxrender_d3d9 gfxsound_fmod dsound Msacm32
    )
    set_target_properties(PlayerTiny_D3D9 PROPERTIES
        OUTPUT_NAME "PlayerTinyD3D9"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,Win32>/Msvc10/PlayerTiny"
    )
endif()

if(SF_RENDERER_GL)
    add_executable(PlayerTiny_GL WIN32
        ${CMAKE_SOURCE_DIR}/Apps/Samples/Common/FxSoundFMOD.cpp
        ${CMAKE_SOURCE_DIR}/Apps/Samples/GFxPlayerTiny/GFxPlayerTinyGLWin32.cpp
    )
    sf_apply_app_flags(PlayerTiny_GL)
    target_link_libraries(PlayerTiny_GL PRIVATE
        sf_core gfxrender_gl gfxsound_fmod dsound Msacm32
    )
    set_target_properties(PlayerTiny_GL PROPERTIES
        OUTPUT_NAME "PlayerTinyGL"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,Win32>/Msvc10/PlayerTiny"
    )
endif()

# ---------------------------------------------------------------------------
# PlayerTinyCompat -- D3D9Compat variant
# ---------------------------------------------------------------------------
if(SF_RENDERER_D3D9)
    add_executable(PlayerTinyCompat WIN32
        ${CMAKE_SOURCE_DIR}/Apps/Samples/Common/FxSoundFMOD.cpp
        ${CMAKE_SOURCE_DIR}/Apps/Samples/GFxPlayerTiny/GFxPlayerTinyD3D9Compat.cpp
    )
    sf_apply_app_flags(PlayerTinyCompat)
    target_link_libraries(PlayerTinyCompat PRIVATE
        sf_core gfxrender_d3d9 gfxsound_fmod dsound Msacm32
    )
    set_target_properties(PlayerTinyCompat PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,Win32>/Msvc10/PlayerTiny"
    )
endif()

# ---------------------------------------------------------------------------
# GFxPlayer -- full-featured player with HUD
# ---------------------------------------------------------------------------
# Macro to add GFxPlayer for a specific renderer
function(sf_add_gfxplayer suffix renderer_target platform_target)
    set(target_name "GFxPlayer_${suffix}")
    # GFxPlayer uses wmain() via SF_PLATFORM_SYSTEM_APP — console subsystem
    add_executable(${target_name}
        ${SF_APP_COMMON_SOURCES}
        ${CMAKE_SOURCE_DIR}/Apps/Samples/FxPlayer/FxHUD.cpp
        ${CMAKE_SOURCE_DIR}/Apps/Samples/FxPlayer/FxPlayer.cpp
    )
    sf_apply_app_flags(${target_name})
    target_link_libraries(${target_name} PRIVATE
        sf_core ${renderer_target} ${platform_target}
        gfxsound_fmod dsound Msacm32
    )
    set_target_properties(${target_name} PROPERTIES
        OUTPUT_NAME "GFxPlayer"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,Win32>/Msvc10/GFxPlayer"
    )
endfunction()

if(SF_RENDERER_D3D11)
    sf_add_gfxplayer(D3D11 gfxrender_d3d1x gfxplatform_d3d11)
endif()
if(SF_RENDERER_D3D10)
    sf_add_gfxplayer(D3D10 gfxrender_d3d10 gfxplatform_d3d10)
endif()
if(SF_RENDERER_D3D9)
    sf_add_gfxplayer(D3D9 gfxrender_d3d9 gfxplatform_d3d9)
endif()
if(SF_RENDERER_GL)
    sf_add_gfxplayer(GL gfxrender_gl gfxplatform_gl)
endif()

# ---------------------------------------------------------------------------
# DrawText
# ---------------------------------------------------------------------------
function(sf_add_drawtext suffix renderer_target platform_target)
    set(target_name "DrawText_${suffix}")
    sf_add_sample_app(${target_name} ${renderer_target} ${platform_target}
        SOURCES ${CMAKE_SOURCE_DIR}/Apps/Samples/DrawText/DrawTextApp.cpp
    )
endfunction()

if(SF_RENDERER_D3D11)
    sf_add_drawtext(D3D11 gfxrender_d3d1x gfxplatform_d3d11)
endif()
if(SF_RENDERER_D3D9)
    sf_add_drawtext(D3D9 gfxrender_d3d9 gfxplatform_d3d9)
endif()
if(SF_RENDERER_GL)
    sf_add_drawtext(GL gfxrender_gl gfxplatform_gl)
endif()

# ---------------------------------------------------------------------------
# ImageDelegate
# ---------------------------------------------------------------------------
function(sf_add_imagedelegate suffix renderer_target platform_target)
    set(target_name "ImageDelegate_${suffix}")
    sf_add_sample_app(${target_name} ${renderer_target} ${platform_target}
        SOURCES ${CMAKE_SOURCE_DIR}/Apps/Samples/ImageDelegate/ImageDelegateApp.cpp
    )
endfunction()

if(SF_RENDERER_D3D11)
    sf_add_imagedelegate(D3D11 gfxrender_d3d1x gfxplatform_d3d11)
endif()
if(SF_RENDERER_D3D9)
    sf_add_imagedelegate(D3D9 gfxrender_d3d9 gfxplatform_d3d9)
endif()
if(SF_RENDERER_GL)
    sf_add_imagedelegate(GL gfxrender_gl gfxplatform_gl)
endif()

# ---------------------------------------------------------------------------
# SWFToTexture / TextureInSWF — source files not in repo; skipped
# ---------------------------------------------------------------------------

# ---------------------------------------------------------------------------
# Kit demo applications (HUDKit, MenuKit, MMOKit)
# ---------------------------------------------------------------------------
if(SF_BUILD_KITS)
    # HUDKit
    function(sf_add_hudkit suffix renderer_target platform_target)
        set(target_name "HUDKit_${suffix}")
        sf_add_sample_app(${target_name} ${renderer_target} ${platform_target}
            SOURCES
                ${CMAKE_SOURCE_DIR}/Apps/Samples/FxPlayer/FxHUD.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Samples/GameDelegate/FxGameDelegate.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/HUD/Common/FxHUDView.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/HUD/Common/FxMinimapView.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/HUD/HUDDemo/HUDAdapter.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/HUD/HUDDemo/HUDEntityController.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/HUD/HUDDemo/HUDKitDemo.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/HUD/HUDDemo/HUDSimulation.cpp
            EXTRA_DEFS UNICODE
        )
    endfunction()

    if(SF_RENDERER_D3D11)
        sf_add_hudkit(D3D11 gfxrender_d3d1x gfxplatform_d3d11)
    endif()
    if(SF_RENDERER_D3D9)
        sf_add_hudkit(D3D9 gfxrender_d3d9 gfxplatform_d3d9)
    endif()
    if(SF_RENDERER_GL)
        sf_add_hudkit(GL gfxrender_gl gfxplatform_gl)
    endif()

    # MenuKit
    function(sf_add_menukit suffix renderer_target platform_target)
        set(target_name "MenuKit_${suffix}")
        sf_add_sample_app(${target_name} ${renderer_target} ${platform_target}
            SOURCES
                ${CMAKE_SOURCE_DIR}/Apps/Samples/FxPlayer/FxHUD.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/Menu/States/GameState_InGame.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/Menu/States/GameState_Loading.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/Menu/States/GameState_MainMenu.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/Menu/States/GameState_Splash.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/Menu/States/GameState_Start.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/Menu/States/GameState_System.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/Menu/States/GameStateWidgetSupport.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/Menu/Views/MainMenuView.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/Menu/Views/ManagerView.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/Menu/Views/MenuDialog.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/Menu/Views/MenuView.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/Menu/Views/SettingsView.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/Menu/Views/StartGameView.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/Menu/Views/SystemUIDialog.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/Menu/Views/UIView.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/Menu/Util/GameMemoryFileCache.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/Menu/Util/GameDataLoader.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/Menu/Game.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/Menu/GameResourceManager.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/Menu/GameUIManager.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/Menu/MenuKitDemo.cpp
            EXTRA_DEFS UNICODE
        )
    endfunction()

    if(SF_RENDERER_D3D11)
        sf_add_menukit(D3D11 gfxrender_d3d1x gfxplatform_d3d11)
    endif()
    if(SF_RENDERER_D3D9)
        sf_add_menukit(D3D9 gfxrender_d3d9 gfxplatform_d3d9)
    endif()
    if(SF_RENDERER_GL)
        sf_add_menukit(GL gfxrender_gl gfxplatform_gl)
    endif()

    # MMOKit
    function(sf_add_mmokit suffix renderer_target platform_target)
        set(target_name "MMOKit_${suffix}")
        sf_add_sample_app(${target_name} ${renderer_target} ${platform_target}
            SOURCES
                ${CMAKE_SOURCE_DIR}/Apps/Samples/FxPlayer/FxHUD.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/MMO/Game/GameAiBehavior.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/MMO/Game/GameChatChannel.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/MMO/Game/GameEntity.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/MMO/Game/GameEntitySlot.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/MMO/Game/GameGuild.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/MMO/Game/GamePawn.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/MMO/Game/GamePawnEquipment.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/MMO/Game/GamePawnInventory.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/MMO/Game/GamePawnSpellbook.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/MMO/Game/GameServer.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/MMO/Game/GameSimulation.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/MMO/Game/GameEntityEvent.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/MMO/Game/GameCommon.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/MMO/Game/GameEvent.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/MMO/Game/GameClient.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/MMO/Game/GameClientState.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/MMO/Game.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/MMO/UI/GameUIActionBar.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/MMO/UI/GameUIAdapter.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/MMO/UI/GameUIDataBindings.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/MMO/UI/GameUIRuntimeAtlas.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Samples/DataBinding/CLIKDataBinding.cpp
                ${CMAKE_SOURCE_DIR}/Apps/Kits/MMO/MMOKitDemo.cpp
            EXTRA_DEFS UNICODE
        )
    endfunction()

    if(SF_RENDERER_D3D11)
        sf_add_mmokit(D3D11 gfxrender_d3d1x gfxplatform_d3d11)
    endif()
    if(SF_RENDERER_D3D9)
        sf_add_mmokit(D3D9 gfxrender_d3d9 gfxplatform_d3d9)
    endif()
    if(SF_RENDERER_GL)
        sf_add_mmokit(GL gfxrender_gl gfxplatform_gl)
    endif()
endif()
