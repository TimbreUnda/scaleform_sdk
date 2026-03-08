# ScaleformCompileFlags.cmake — shared compile settings for all targets.
#
# Call sf_apply_compile_flags(<target>) after add_library/add_executable
# to apply the standard Scaleform build settings.

# ---------------------------------------------------------------------------
# Static CRT (/MT, /MTd) — matches original vcxproj settings
# ---------------------------------------------------------------------------
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>" CACHE STRING "")

# ---------------------------------------------------------------------------
# Common include directories (relative to project root)
# ---------------------------------------------------------------------------
set(SF_INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}/Include
    ${CMAKE_SOURCE_DIR}/Src
)

set(SF_3RDPARTY_INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}/3rdParty/zlib-1.2.7
    ${CMAKE_SOURCE_DIR}/3rdParty/jpeg-8d
    ${CMAKE_SOURCE_DIR}/3rdParty/libpng-1.5.13
    ${CMAKE_SOURCE_DIR}/3rdParty/expat-2.1.0/lib
    ${CMAKE_SOURCE_DIR}/3rdParty/pcre
    ${CMAKE_SOURCE_DIR}/3rdParty/glext
    ${CMAKE_SOURCE_DIR}/3rdParty/fmod/pc/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,Win32>/inc
)

# ---------------------------------------------------------------------------
# Helper: apply standard Scaleform compile flags to a target
# ---------------------------------------------------------------------------
function(sf_apply_compile_flags target)
    target_compile_definitions(${target} PRIVATE
        WIN32
        _WINDOWS
        SF_BUILD_STATICLIB
        $<$<CONFIG:Debug>:_DEBUG>
        $<$<NOT:$<CONFIG:Debug>>:NDEBUG>
    )

    target_include_directories(${target} PRIVATE
        ${SF_INCLUDE_DIRS}
        ${SF_3RDPARTY_INCLUDE_DIRS}
    )

    if(MSVC)
        target_compile_options(${target} PRIVATE
            /MP             # Multi-processor compilation
            /W4             # Warning level 4
            /Zp8            # 8-byte struct alignment
            /wd4127         # conditional expression is constant
            /wd4100         # unreferenced formal parameter
            /wd4324         # structure was padded due to alignment specifier
            $<$<NOT:$<CONFIG:Debug>>:/O2 /Oi /Ob2 /Oy>  # Full optimization
        )
    endif()
endfunction()

# ---------------------------------------------------------------------------
# Helper: apply flags for an application/executable target
# ---------------------------------------------------------------------------
function(sf_apply_app_flags target)
    sf_apply_compile_flags(${target})

    target_include_directories(${target} PRIVATE
        ${CMAKE_SOURCE_DIR}/Apps/Samples/Common
        ${CMAKE_SOURCE_DIR}/Apps/Samples/FxPlayer
    )

    # System libraries common to all apps
    target_link_libraries(${target} PRIVATE
        XInput winmm imm32 dbghelp ws2_32
        legacy_stdio_definitions   # _snwprintf for FMOD (VS2010-era lib)
    )
    # FMOD references __iob_func removed in VS2015+ — add compat shim
    target_sources(${target} PRIVATE ${CMAKE_SOURCE_DIR}/cmake/fmod_compat.cpp)
endfunction()
