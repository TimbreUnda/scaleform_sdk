# 3rdParty dependencies — built from source as static libraries.

# ---------------------------------------------------------------------------
# zlib 1.2.7
# ---------------------------------------------------------------------------
set(ZLIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/zlib-1.2.7)
add_library(zlib STATIC
    ${ZLIB_DIR}/adler32.c
    ${ZLIB_DIR}/compress.c
    ${ZLIB_DIR}/crc32.c
    ${ZLIB_DIR}/deflate.c
    ${ZLIB_DIR}/infback.c
    ${ZLIB_DIR}/inffast.c
    ${ZLIB_DIR}/inflate.c
    ${ZLIB_DIR}/inftrees.c
    ${ZLIB_DIR}/trees.c
    ${ZLIB_DIR}/uncompr.c
    ${ZLIB_DIR}/zutil.c
)
target_include_directories(zlib PUBLIC ${ZLIB_DIR})
target_compile_definitions(zlib PRIVATE WIN32 $<$<CONFIG:Debug>:_DEBUG> $<$<NOT:$<CONFIG:Debug>>:NDEBUG>)
set_target_properties(zlib PROPERTIES OUTPUT_NAME "zlib")

# ---------------------------------------------------------------------------
# libpng 1.5.13
# ---------------------------------------------------------------------------
set(PNG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libpng-1.5.13)
add_library(libpng STATIC
    ${PNG_DIR}/png.c
    ${PNG_DIR}/pngerror.c
    ${PNG_DIR}/pngget.c
    ${PNG_DIR}/pngmem.c
    ${PNG_DIR}/pngpread.c
    ${PNG_DIR}/pngread.c
    ${PNG_DIR}/pngrio.c
    ${PNG_DIR}/pngrtran.c
    ${PNG_DIR}/pngrutil.c
    ${PNG_DIR}/pngset.c
    ${PNG_DIR}/pngtrans.c
    ${PNG_DIR}/pngwio.c
    ${PNG_DIR}/pngwrite.c
    ${PNG_DIR}/pngwtran.c
    ${PNG_DIR}/pngwutil.c
)
target_include_directories(libpng PUBLIC ${PNG_DIR})
target_link_libraries(libpng PRIVATE zlib)
target_compile_definitions(libpng PRIVATE WIN32
    $<$<CONFIG:Debug>:_DEBUG;DEBUG;PNG_DEBUG=1>
    $<$<NOT:$<CONFIG:Debug>>:NDEBUG>
)
set_target_properties(libpng PROPERTIES OUTPUT_NAME "libpng")

# ---------------------------------------------------------------------------
# expat 2.1.0
# ---------------------------------------------------------------------------
set(EXPAT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/expat-2.1.0)
add_library(expat STATIC
    ${EXPAT_DIR}/lib/xmlparse.c
    ${EXPAT_DIR}/lib/xmlrole.c
    ${EXPAT_DIR}/lib/xmltok.c
    ${EXPAT_DIR}/lib/xmltok_impl.c
    ${EXPAT_DIR}/lib/xmltok_ns.c
)
target_include_directories(expat PUBLIC ${EXPAT_DIR}/lib)
target_compile_definitions(expat PRIVATE WIN32 COMPILED_FROM_DSP
    $<$<CONFIG:Debug>:_DEBUG>
    $<$<NOT:$<CONFIG:Debug>>:NDEBUG>
)
set_target_properties(expat PROPERTIES OUTPUT_NAME "expat")

# ---------------------------------------------------------------------------
# libjpeg 8d
# ---------------------------------------------------------------------------
set(JPEG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/jpeg-8d)
add_library(libjpeg STATIC
    ${JPEG_DIR}/jaricom.c
    ${JPEG_DIR}/jcapimin.c
    ${JPEG_DIR}/jcapistd.c
    ${JPEG_DIR}/jcarith.c
    ${JPEG_DIR}/jccoefct.c
    ${JPEG_DIR}/jccolor.c
    ${JPEG_DIR}/jcdctmgr.c
    ${JPEG_DIR}/jcinit.c
    ${JPEG_DIR}/jcmainct.c
    ${JPEG_DIR}/jcmarker.c
    ${JPEG_DIR}/jcmaster.c
    ${JPEG_DIR}/jcomapi.c
    ${JPEG_DIR}/jcparam.c
    ${JPEG_DIR}/jcprepct.c
    ${JPEG_DIR}/jcsample.c
    ${JPEG_DIR}/jctrans.c
    ${JPEG_DIR}/jdapimin.c
    ${JPEG_DIR}/jdapistd.c
    ${JPEG_DIR}/jdarith.c
    ${JPEG_DIR}/jdatadst.c
    ${JPEG_DIR}/jdatasrc.c
    ${JPEG_DIR}/jdcoefct.c
    ${JPEG_DIR}/jdcolor.c
    ${JPEG_DIR}/jddctmgr.c
    ${JPEG_DIR}/jdhuff.c
    ${JPEG_DIR}/jdinput.c
    ${JPEG_DIR}/jdmainct.c
    ${JPEG_DIR}/jdmarker.c
    ${JPEG_DIR}/jdmaster.c
    ${JPEG_DIR}/jdmerge.c
    ${JPEG_DIR}/jdpostct.c
    ${JPEG_DIR}/jdsample.c
    ${JPEG_DIR}/jdtrans.c
    ${JPEG_DIR}/jerror.c
    ${JPEG_DIR}/jfdctflt.c
    ${JPEG_DIR}/jfdctfst.c
    ${JPEG_DIR}/jfdctint.c
    ${JPEG_DIR}/jidctflt.c
    ${JPEG_DIR}/jidctfst.c
    ${JPEG_DIR}/jidctint.c
    ${JPEG_DIR}/jmemmgr.c
    ${JPEG_DIR}/jmemnobs.c
    ${JPEG_DIR}/jquant1.c
    ${JPEG_DIR}/jquant2.c
    ${JPEG_DIR}/jutils.c
)
target_include_directories(libjpeg PUBLIC ${JPEG_DIR})
target_compile_definitions(libjpeg PRIVATE WIN32 _LIB _CRT_SECURE_NO_WARNINGS
    $<$<CONFIG:Debug>:_DEBUG>
    $<$<NOT:$<CONFIG:Debug>>:NDEBUG>
)
set_target_properties(libjpeg PROPERTIES OUTPUT_NAME "libjpeg")

# ---------------------------------------------------------------------------
# pcre
# ---------------------------------------------------------------------------
set(PCRE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/pcre)
add_library(pcre STATIC
    ${PCRE_DIR}/pcre_chartables.c
    ${PCRE_DIR}/pcre_compile.c
    ${PCRE_DIR}/pcre_config.c
    ${PCRE_DIR}/pcre_dfa_exec.c
    ${PCRE_DIR}/pcre_exec.c
    ${PCRE_DIR}/pcre_fullinfo.c
    ${PCRE_DIR}/pcre_get.c
    ${PCRE_DIR}/pcre_globals.c
    ${PCRE_DIR}/pcre_info.c
    ${PCRE_DIR}/pcre_maketables.c
    ${PCRE_DIR}/pcre_newline.c
    ${PCRE_DIR}/pcre_ord2utf8.c
    ${PCRE_DIR}/pcre_refcount.c
    ${PCRE_DIR}/pcre_study.c
    ${PCRE_DIR}/pcre_tables.c
    ${PCRE_DIR}/pcre_try_flipped.c
    ${PCRE_DIR}/pcre_ucd.c
    ${PCRE_DIR}/pcre_valid_utf8.c
    ${PCRE_DIR}/pcre_version.c
    ${PCRE_DIR}/pcre_xclass.c
)
target_include_directories(pcre PUBLIC ${PCRE_DIR})
target_compile_definitions(pcre PRIVATE WIN32 HAVE_CONFIG_H _CRT_SECURE_NO_WARNINGS
    $<$<CONFIG:Debug>:_DEBUG>
    $<$<NOT:$<CONFIG:Debug>>:NDEBUG>
)
set_target_properties(pcre PROPERTIES OUTPUT_NAME "pcre")

# ---------------------------------------------------------------------------
# fmod (prebuilt vendor library — IMPORTED target)
# ---------------------------------------------------------------------------
set(FMOD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/fmod/pc)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(FMOD_PLATFORM "x64")
    set(FMOD_LIB_NAME "fmodex64_vc")
else()
    set(FMOD_PLATFORM "Win32")
    set(FMOD_LIB_NAME "fmodex_vc")
endif()

add_library(fmod STATIC IMPORTED GLOBAL)
set_target_properties(fmod PROPERTIES
    IMPORTED_LOCATION "${FMOD_DIR}/${FMOD_PLATFORM}/lib/${FMOD_LIB_NAME}.lib"
    INTERFACE_INCLUDE_DIRECTORIES "${FMOD_DIR}/${FMOD_PLATFORM}/inc"
)

# ---------------------------------------------------------------------------
# nvtt (NVIDIA Texture Tools — texture compression)
# ---------------------------------------------------------------------------
set(NVTT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/nvtt)
add_library(nvtt STATIC
    ${NVTT_DIR}/src/nvcore/Debug.cpp
    ${NVTT_DIR}/src/nvcore/Memory.cpp
    ${NVTT_DIR}/src/nvcore/StrLib.cpp
    ${NVTT_DIR}/src/nvimage/BlockDXT.cpp
    ${NVTT_DIR}/src/nvimage/ColorBlock.cpp
    ${NVTT_DIR}/src/nvimage/DirectDrawSurface.cpp
    ${NVTT_DIR}/src/nvimage/Filter.cpp
    ${NVTT_DIR}/src/nvimage/FloatImage.cpp
    ${NVTT_DIR}/src/nvimage/Image.cpp
    ${NVTT_DIR}/src/nvimage/ImageIO.cpp
    ${NVTT_DIR}/src/nvimage/NormalMap.cpp
    ${NVTT_DIR}/src/nvimage/NormalMipmap.cpp
    ${NVTT_DIR}/src/nvimage/Quantize.cpp
    ${NVTT_DIR}/src/nvtt/CompressDXT.cpp
    ${NVTT_DIR}/src/nvtt/CompressRGB.cpp
    ${NVTT_DIR}/src/nvtt/CompressionOptions.cpp
    ${NVTT_DIR}/src/nvtt/Compressor.cpp
    ${NVTT_DIR}/src/nvtt/InputOptions.cpp
    ${NVTT_DIR}/src/nvtt/OptimalCompressDXT.cpp
    ${NVTT_DIR}/src/nvtt/OutputOptions.cpp
    ${NVTT_DIR}/src/nvtt/QuickCompressDXT.cpp
    ${NVTT_DIR}/src/nvtt/cuda/CudaCompressDXT.cpp
    ${NVTT_DIR}/src/nvtt/cuda/CudaUtils.cpp
    ${NVTT_DIR}/src/nvtt/nvtt.cpp
    ${NVTT_DIR}/src/nvtt/nvtt_wrapper.cpp
    ${NVTT_DIR}/src/nvtt/squish/alpha.cpp
    ${NVTT_DIR}/src/nvtt/squish/clusterfit.cpp
    ${NVTT_DIR}/src/nvtt/squish/colourblock.cpp
    ${NVTT_DIR}/src/nvtt/squish/colourfit.cpp
    ${NVTT_DIR}/src/nvtt/squish/colourset.cpp
    ${NVTT_DIR}/src/nvtt/squish/fastclusterfit.cpp
    ${NVTT_DIR}/src/nvtt/squish/maths.cpp
    ${NVTT_DIR}/src/nvtt/squish/weightedclusterfit.cpp
)
target_include_directories(nvtt PUBLIC
    ${NVTT_DIR}/src
    ${NVTT_DIR}/src/nvtt/squish
)
target_compile_definitions(nvtt PRIVATE
    WIN32 NVTT_EXPORTS NVTT_SHARED __SSE2__ __SSE__ __MMX__
    $<$<CONFIG:Debug>:_DEBUG>
    $<$<NOT:$<CONFIG:Debug>>:NDEBUG>
)
set_target_properties(nvtt PROPERTIES OUTPUT_NAME "nvtt")
