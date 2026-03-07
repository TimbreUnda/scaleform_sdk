/**************************************************************************

    PublicHeader:   Render
    Filename    :   Vulkan_ShaderDescs.cpp
    Content     :   Vulkan Shader descriptors
    Created     :   04.03.2026
    Authors     :   Automatically generated.

    Copyright   :   Copyright 2026 Autodesk, Inc. All Rights reserved.

    Use of this software is subject to the terms of the Autodesk license
    agreement provided at the time of installation or download, or which
    otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/

#include "Render/Vulkan/Vulkan_Shader.h"
#include "Render/Vulkan/Vulkan_ShaderDescs.h"

namespace Scaleform { namespace Render { namespace Vulkan {

const char* ShaderUniformNames[Uniform::SU_Count] = 
{
    "cxadd",
    "cxmul",
    "cxmul1",
    "fsize",
    "mvp",
    "offset",
    "scolor",
    "scolor2",
    "srctex",
    "srctexscale",
    "tex",
    "texgen",
    "texscale",
    "vfmuniforms",
    "vfuniforms",
};

const unsigned char Uniform::UniformFlags[Uniform::SU_Count] = 
{
    0,  // cxadd
    0,  // cxmul
    0,  // cxmul1
    0,  // fsize
    0,  // mvp
    0,  // offset
    0,  // scolor
    0,  // scolor2
    0,  // srctex
    0,  // srctexscale
    0,  // tex
    0,  // texgen
    0,  // texscale
    0,  // vfmuniforms
    0,  // vfuniforms
};

bool ShaderDesc::IsShaderVersionSupported(ShaderVersion ver)
{
    switch(ver)
    {
        case ShaderVersion_Vulkan_SPIRV: return true;
        default: return false;
    }
};

ShaderDesc::ShaderType ShaderDesc::GetShaderTypeForComboIndex(unsigned comboIndex, ShaderVersion ver)
{
    switch(ver)
    {
        case ShaderDesc::ShaderVersion_Vulkan_SPIRV:
        switch(comboIndex)
        {
            case 0: return ST_TexTG;
            case 1: return ST_TexTGMul;
            case 2: return ST_TexTGInv;
            case 3: return ST_TexTGEAlpha;
            case 4: return ST_TexTGEAlphaMul;
            case 5: return ST_TexTGEAlphaInv;
            case 6: return ST_TexTGCxform;
            case 7: return ST_TexTGCxformMul;
            case 8: return ST_TexTGCxformInv;
            case 9: return ST_TexTGCxformEAlpha;
            case 10: return ST_TexTGCxformEAlphaMul;
            case 11: return ST_TexTGCxformEAlphaInv;
            case 12: return ST_TexTGCxformAc;
            case 13: return ST_TexTGCxformAcMul;
            case 14: return ST_TexTGCxformAcInv;
            case 15: return ST_TexTGCxformAcEAlpha;
            case 16: return ST_TexTGCxformAcEAlphaMul;
            case 17: return ST_TexTGCxformAcEAlphaInv;
            case 18: return ST_Vertex;
            case 19: return ST_VertexMul;
            case 20: return ST_VertexInv;
            case 21: return ST_VertexEAlpha;
            case 22: return ST_VertexEAlphaMul;
            case 23: return ST_VertexEAlphaInv;
            case 24: return ST_VertexCxform;
            case 25: return ST_VertexCxformMul;
            case 26: return ST_VertexCxformInv;
            case 27: return ST_VertexCxformEAlpha;
            case 28: return ST_VertexCxformEAlphaMul;
            case 29: return ST_VertexCxformEAlphaInv;
            case 30: return ST_VertexCxformAc;
            case 31: return ST_VertexCxformAcMul;
            case 32: return ST_VertexCxformAcInv;
            case 33: return ST_VertexCxformAcEAlpha;
            case 34: return ST_VertexCxformAcEAlphaMul;
            case 35: return ST_VertexCxformAcEAlphaInv;
            case 36: return ST_TexTGTexTG;
            case 37: return ST_TexTGTexTGMul;
            case 38: return ST_TexTGTexTGInv;
            case 39: return ST_TexTGTexTGEAlpha;
            case 40: return ST_TexTGTexTGEAlphaMul;
            case 41: return ST_TexTGTexTGEAlphaInv;
            case 42: return ST_TexTGTexTGCxform;
            case 43: return ST_TexTGTexTGCxformMul;
            case 44: return ST_TexTGTexTGCxformInv;
            case 45: return ST_TexTGTexTGCxformEAlpha;
            case 46: return ST_TexTGTexTGCxformEAlphaMul;
            case 47: return ST_TexTGTexTGCxformEAlphaInv;
            case 48: return ST_TexTGTexTGCxformAc;
            case 49: return ST_TexTGTexTGCxformAcMul;
            case 50: return ST_TexTGTexTGCxformAcInv;
            case 51: return ST_TexTGTexTGCxformAcEAlpha;
            case 52: return ST_TexTGTexTGCxformAcEAlphaMul;
            case 53: return ST_TexTGTexTGCxformAcEAlphaInv;
            case 54: return ST_TexTGVertex;
            case 55: return ST_TexTGVertexMul;
            case 56: return ST_TexTGVertexInv;
            case 57: return ST_TexTGVertexEAlpha;
            case 58: return ST_TexTGVertexEAlphaMul;
            case 59: return ST_TexTGVertexEAlphaInv;
            case 60: return ST_TexTGVertexCxform;
            case 61: return ST_TexTGVertexCxformMul;
            case 62: return ST_TexTGVertexCxformInv;
            case 63: return ST_TexTGVertexCxformEAlpha;
            case 64: return ST_TexTGVertexCxformEAlphaMul;
            case 65: return ST_TexTGVertexCxformEAlphaInv;
            case 66: return ST_TexTGVertexCxformAc;
            case 67: return ST_TexTGVertexCxformAcMul;
            case 68: return ST_TexTGVertexCxformAcInv;
            case 69: return ST_TexTGVertexCxformAcEAlpha;
            case 70: return ST_TexTGVertexCxformAcEAlphaMul;
            case 71: return ST_TexTGVertexCxformAcEAlphaInv;
            case 72: return ST_Position3dTexTG;
            case 73: return ST_Position3dTexTGMul;
            case 74: return ST_Position3dTexTGInv;
            case 75: return ST_Position3dTexTGEAlpha;
            case 76: return ST_Position3dTexTGEAlphaMul;
            case 77: return ST_Position3dTexTGEAlphaInv;
            case 78: return ST_Position3dTexTGCxform;
            case 79: return ST_Position3dTexTGCxformMul;
            case 80: return ST_Position3dTexTGCxformInv;
            case 81: return ST_Position3dTexTGCxformEAlpha;
            case 82: return ST_Position3dTexTGCxformEAlphaMul;
            case 83: return ST_Position3dTexTGCxformEAlphaInv;
            case 84: return ST_Position3dTexTGCxformAc;
            case 85: return ST_Position3dTexTGCxformAcMul;
            case 86: return ST_Position3dTexTGCxformAcInv;
            case 87: return ST_Position3dTexTGCxformAcEAlpha;
            case 88: return ST_Position3dTexTGCxformAcEAlphaMul;
            case 89: return ST_Position3dTexTGCxformAcEAlphaInv;
            case 90: return ST_Position3dVertex;
            case 91: return ST_Position3dVertexMul;
            case 92: return ST_Position3dVertexInv;
            case 93: return ST_Position3dVertexEAlpha;
            case 94: return ST_Position3dVertexEAlphaMul;
            case 95: return ST_Position3dVertexEAlphaInv;
            case 96: return ST_Position3dVertexCxform;
            case 97: return ST_Position3dVertexCxformMul;
            case 98: return ST_Position3dVertexCxformInv;
            case 99: return ST_Position3dVertexCxformEAlpha;
            case 100: return ST_Position3dVertexCxformEAlphaMul;
            case 101: return ST_Position3dVertexCxformEAlphaInv;
            case 102: return ST_Position3dVertexCxformAc;
            case 103: return ST_Position3dVertexCxformAcMul;
            case 104: return ST_Position3dVertexCxformAcInv;
            case 105: return ST_Position3dVertexCxformAcEAlpha;
            case 106: return ST_Position3dVertexCxformAcEAlphaMul;
            case 107: return ST_Position3dVertexCxformAcEAlphaInv;
            case 108: return ST_Position3dTexTGTexTG;
            case 109: return ST_Position3dTexTGTexTGMul;
            case 110: return ST_Position3dTexTGTexTGInv;
            case 111: return ST_Position3dTexTGTexTGEAlpha;
            case 112: return ST_Position3dTexTGTexTGEAlphaMul;
            case 113: return ST_Position3dTexTGTexTGEAlphaInv;
            case 114: return ST_Position3dTexTGTexTGCxform;
            case 115: return ST_Position3dTexTGTexTGCxformMul;
            case 116: return ST_Position3dTexTGTexTGCxformInv;
            case 117: return ST_Position3dTexTGTexTGCxformEAlpha;
            case 118: return ST_Position3dTexTGTexTGCxformEAlphaMul;
            case 119: return ST_Position3dTexTGTexTGCxformEAlphaInv;
            case 120: return ST_Position3dTexTGTexTGCxformAc;
            case 121: return ST_Position3dTexTGTexTGCxformAcMul;
            case 122: return ST_Position3dTexTGTexTGCxformAcInv;
            case 123: return ST_Position3dTexTGTexTGCxformAcEAlpha;
            case 124: return ST_Position3dTexTGTexTGCxformAcEAlphaMul;
            case 125: return ST_Position3dTexTGTexTGCxformAcEAlphaInv;
            case 126: return ST_Position3dTexTGVertex;
            case 127: return ST_Position3dTexTGVertexMul;
            case 128: return ST_Position3dTexTGVertexInv;
            case 129: return ST_Position3dTexTGVertexEAlpha;
            case 130: return ST_Position3dTexTGVertexEAlphaMul;
            case 131: return ST_Position3dTexTGVertexEAlphaInv;
            case 132: return ST_Position3dTexTGVertexCxform;
            case 133: return ST_Position3dTexTGVertexCxformMul;
            case 134: return ST_Position3dTexTGVertexCxformInv;
            case 135: return ST_Position3dTexTGVertexCxformEAlpha;
            case 136: return ST_Position3dTexTGVertexCxformEAlphaMul;
            case 137: return ST_Position3dTexTGVertexCxformEAlphaInv;
            case 138: return ST_Position3dTexTGVertexCxformAc;
            case 139: return ST_Position3dTexTGVertexCxformAcMul;
            case 140: return ST_Position3dTexTGVertexCxformAcInv;
            case 141: return ST_Position3dTexTGVertexCxformAcEAlpha;
            case 142: return ST_Position3dTexTGVertexCxformAcEAlphaMul;
            case 143: return ST_Position3dTexTGVertexCxformAcEAlphaInv;
            case 144: return ST_BatchTexTG;
            case 145: return ST_BatchTexTGMul;
            case 146: return ST_BatchTexTGInv;
            case 147: return ST_BatchTexTGEAlpha;
            case 148: return ST_BatchTexTGEAlphaMul;
            case 149: return ST_BatchTexTGEAlphaInv;
            case 150: return ST_BatchTexTGCxform;
            case 151: return ST_BatchTexTGCxformMul;
            case 152: return ST_BatchTexTGCxformInv;
            case 153: return ST_BatchTexTGCxformEAlpha;
            case 154: return ST_BatchTexTGCxformEAlphaMul;
            case 155: return ST_BatchTexTGCxformEAlphaInv;
            case 156: return ST_BatchTexTGCxformAc;
            case 157: return ST_BatchTexTGCxformAcMul;
            case 158: return ST_BatchTexTGCxformAcInv;
            case 159: return ST_BatchTexTGCxformAcEAlpha;
            case 160: return ST_BatchTexTGCxformAcEAlphaMul;
            case 161: return ST_BatchTexTGCxformAcEAlphaInv;
            case 162: return ST_BatchVertex;
            case 163: return ST_BatchVertexMul;
            case 164: return ST_BatchVertexInv;
            case 165: return ST_BatchVertexEAlpha;
            case 166: return ST_BatchVertexEAlphaMul;
            case 167: return ST_BatchVertexEAlphaInv;
            case 168: return ST_BatchVertexCxform;
            case 169: return ST_BatchVertexCxformMul;
            case 170: return ST_BatchVertexCxformInv;
            case 171: return ST_BatchVertexCxformEAlpha;
            case 172: return ST_BatchVertexCxformEAlphaMul;
            case 173: return ST_BatchVertexCxformEAlphaInv;
            case 174: return ST_BatchVertexCxformAc;
            case 175: return ST_BatchVertexCxformAcMul;
            case 176: return ST_BatchVertexCxformAcInv;
            case 177: return ST_BatchVertexCxformAcEAlpha;
            case 178: return ST_BatchVertexCxformAcEAlphaMul;
            case 179: return ST_BatchVertexCxformAcEAlphaInv;
            case 180: return ST_BatchTexTGTexTG;
            case 181: return ST_BatchTexTGTexTGMul;
            case 182: return ST_BatchTexTGTexTGInv;
            case 183: return ST_BatchTexTGTexTGEAlpha;
            case 184: return ST_BatchTexTGTexTGEAlphaMul;
            case 185: return ST_BatchTexTGTexTGEAlphaInv;
            case 186: return ST_BatchTexTGTexTGCxform;
            case 187: return ST_BatchTexTGTexTGCxformMul;
            case 188: return ST_BatchTexTGTexTGCxformInv;
            case 189: return ST_BatchTexTGTexTGCxformEAlpha;
            case 190: return ST_BatchTexTGTexTGCxformEAlphaMul;
            case 191: return ST_BatchTexTGTexTGCxformEAlphaInv;
            case 192: return ST_BatchTexTGTexTGCxformAc;
            case 193: return ST_BatchTexTGTexTGCxformAcMul;
            case 194: return ST_BatchTexTGTexTGCxformAcInv;
            case 195: return ST_BatchTexTGTexTGCxformAcEAlpha;
            case 196: return ST_BatchTexTGTexTGCxformAcEAlphaMul;
            case 197: return ST_BatchTexTGTexTGCxformAcEAlphaInv;
            case 198: return ST_BatchTexTGVertex;
            case 199: return ST_BatchTexTGVertexMul;
            case 200: return ST_BatchTexTGVertexInv;
            case 201: return ST_BatchTexTGVertexEAlpha;
            case 202: return ST_BatchTexTGVertexEAlphaMul;
            case 203: return ST_BatchTexTGVertexEAlphaInv;
            case 204: return ST_BatchTexTGVertexCxform;
            case 205: return ST_BatchTexTGVertexCxformMul;
            case 206: return ST_BatchTexTGVertexCxformInv;
            case 207: return ST_BatchTexTGVertexCxformEAlpha;
            case 208: return ST_BatchTexTGVertexCxformEAlphaMul;
            case 209: return ST_BatchTexTGVertexCxformEAlphaInv;
            case 210: return ST_BatchTexTGVertexCxformAc;
            case 211: return ST_BatchTexTGVertexCxformAcMul;
            case 212: return ST_BatchTexTGVertexCxformAcInv;
            case 213: return ST_BatchTexTGVertexCxformAcEAlpha;
            case 214: return ST_BatchTexTGVertexCxformAcEAlphaMul;
            case 215: return ST_BatchTexTGVertexCxformAcEAlphaInv;
            case 216: return ST_BatchPosition3dTexTG;
            case 217: return ST_BatchPosition3dTexTGMul;
            case 218: return ST_BatchPosition3dTexTGInv;
            case 219: return ST_BatchPosition3dTexTGEAlpha;
            case 220: return ST_BatchPosition3dTexTGEAlphaMul;
            case 221: return ST_BatchPosition3dTexTGEAlphaInv;
            case 222: return ST_BatchPosition3dTexTGCxform;
            case 223: return ST_BatchPosition3dTexTGCxformMul;
            case 224: return ST_BatchPosition3dTexTGCxformInv;
            case 225: return ST_BatchPosition3dTexTGCxformEAlpha;
            case 226: return ST_BatchPosition3dTexTGCxformEAlphaMul;
            case 227: return ST_BatchPosition3dTexTGCxformEAlphaInv;
            case 228: return ST_BatchPosition3dTexTGCxformAc;
            case 229: return ST_BatchPosition3dTexTGCxformAcMul;
            case 230: return ST_BatchPosition3dTexTGCxformAcInv;
            case 231: return ST_BatchPosition3dTexTGCxformAcEAlpha;
            case 232: return ST_BatchPosition3dTexTGCxformAcEAlphaMul;
            case 233: return ST_BatchPosition3dTexTGCxformAcEAlphaInv;
            case 234: return ST_BatchPosition3dVertex;
            case 235: return ST_BatchPosition3dVertexMul;
            case 236: return ST_BatchPosition3dVertexInv;
            case 237: return ST_BatchPosition3dVertexEAlpha;
            case 238: return ST_BatchPosition3dVertexEAlphaMul;
            case 239: return ST_BatchPosition3dVertexEAlphaInv;
            case 240: return ST_BatchPosition3dVertexCxform;
            case 241: return ST_BatchPosition3dVertexCxformMul;
            case 242: return ST_BatchPosition3dVertexCxformInv;
            case 243: return ST_BatchPosition3dVertexCxformEAlpha;
            case 244: return ST_BatchPosition3dVertexCxformEAlphaMul;
            case 245: return ST_BatchPosition3dVertexCxformEAlphaInv;
            case 246: return ST_BatchPosition3dVertexCxformAc;
            case 247: return ST_BatchPosition3dVertexCxformAcMul;
            case 248: return ST_BatchPosition3dVertexCxformAcInv;
            case 249: return ST_BatchPosition3dVertexCxformAcEAlpha;
            case 250: return ST_BatchPosition3dVertexCxformAcEAlphaMul;
            case 251: return ST_BatchPosition3dVertexCxformAcEAlphaInv;
            case 252: return ST_BatchPosition3dTexTGTexTG;
            case 253: return ST_BatchPosition3dTexTGTexTGMul;
            case 254: return ST_BatchPosition3dTexTGTexTGInv;
            case 255: return ST_BatchPosition3dTexTGTexTGEAlpha;
            case 256: return ST_BatchPosition3dTexTGTexTGEAlphaMul;
            case 257: return ST_BatchPosition3dTexTGTexTGEAlphaInv;
            case 258: return ST_BatchPosition3dTexTGTexTGCxform;
            case 259: return ST_BatchPosition3dTexTGTexTGCxformMul;
            case 260: return ST_BatchPosition3dTexTGTexTGCxformInv;
            case 261: return ST_BatchPosition3dTexTGTexTGCxformEAlpha;
            case 262: return ST_BatchPosition3dTexTGTexTGCxformEAlphaMul;
            case 263: return ST_BatchPosition3dTexTGTexTGCxformEAlphaInv;
            case 264: return ST_BatchPosition3dTexTGTexTGCxformAc;
            case 265: return ST_BatchPosition3dTexTGTexTGCxformAcMul;
            case 266: return ST_BatchPosition3dTexTGTexTGCxformAcInv;
            case 267: return ST_BatchPosition3dTexTGTexTGCxformAcEAlpha;
            case 268: return ST_BatchPosition3dTexTGTexTGCxformAcEAlphaMul;
            case 269: return ST_BatchPosition3dTexTGTexTGCxformAcEAlphaInv;
            case 270: return ST_BatchPosition3dTexTGVertex;
            case 271: return ST_BatchPosition3dTexTGVertexMul;
            case 272: return ST_BatchPosition3dTexTGVertexInv;
            case 273: return ST_BatchPosition3dTexTGVertexEAlpha;
            case 274: return ST_BatchPosition3dTexTGVertexEAlphaMul;
            case 275: return ST_BatchPosition3dTexTGVertexEAlphaInv;
            case 276: return ST_BatchPosition3dTexTGVertexCxform;
            case 277: return ST_BatchPosition3dTexTGVertexCxformMul;
            case 278: return ST_BatchPosition3dTexTGVertexCxformInv;
            case 279: return ST_BatchPosition3dTexTGVertexCxformEAlpha;
            case 280: return ST_BatchPosition3dTexTGVertexCxformEAlphaMul;
            case 281: return ST_BatchPosition3dTexTGVertexCxformEAlphaInv;
            case 282: return ST_BatchPosition3dTexTGVertexCxformAc;
            case 283: return ST_BatchPosition3dTexTGVertexCxformAcMul;
            case 284: return ST_BatchPosition3dTexTGVertexCxformAcInv;
            case 285: return ST_BatchPosition3dTexTGVertexCxformAcEAlpha;
            case 286: return ST_BatchPosition3dTexTGVertexCxformAcEAlphaMul;
            case 287: return ST_BatchPosition3dTexTGVertexCxformAcEAlphaInv;
            case 288: return ST_InstancedTexTG;
            case 289: return ST_InstancedTexTGMul;
            case 290: return ST_InstancedTexTGInv;
            case 291: return ST_InstancedTexTGEAlpha;
            case 292: return ST_InstancedTexTGEAlphaMul;
            case 293: return ST_InstancedTexTGEAlphaInv;
            case 294: return ST_InstancedTexTGCxform;
            case 295: return ST_InstancedTexTGCxformMul;
            case 296: return ST_InstancedTexTGCxformInv;
            case 297: return ST_InstancedTexTGCxformEAlpha;
            case 298: return ST_InstancedTexTGCxformEAlphaMul;
            case 299: return ST_InstancedTexTGCxformEAlphaInv;
            case 300: return ST_InstancedTexTGCxformAc;
            case 301: return ST_InstancedTexTGCxformAcMul;
            case 302: return ST_InstancedTexTGCxformAcInv;
            case 303: return ST_InstancedTexTGCxformAcEAlpha;
            case 304: return ST_InstancedTexTGCxformAcEAlphaMul;
            case 305: return ST_InstancedTexTGCxformAcEAlphaInv;
            case 306: return ST_InstancedVertex;
            case 307: return ST_InstancedVertexMul;
            case 308: return ST_InstancedVertexInv;
            case 309: return ST_InstancedVertexEAlpha;
            case 310: return ST_InstancedVertexEAlphaMul;
            case 311: return ST_InstancedVertexEAlphaInv;
            case 312: return ST_InstancedVertexCxform;
            case 313: return ST_InstancedVertexCxformMul;
            case 314: return ST_InstancedVertexCxformInv;
            case 315: return ST_InstancedVertexCxformEAlpha;
            case 316: return ST_InstancedVertexCxformEAlphaMul;
            case 317: return ST_InstancedVertexCxformEAlphaInv;
            case 318: return ST_InstancedVertexCxformAc;
            case 319: return ST_InstancedVertexCxformAcMul;
            case 320: return ST_InstancedVertexCxformAcInv;
            case 321: return ST_InstancedVertexCxformAcEAlpha;
            case 322: return ST_InstancedVertexCxformAcEAlphaMul;
            case 323: return ST_InstancedVertexCxformAcEAlphaInv;
            case 324: return ST_InstancedTexTGTexTG;
            case 325: return ST_InstancedTexTGTexTGMul;
            case 326: return ST_InstancedTexTGTexTGInv;
            case 327: return ST_InstancedTexTGTexTGEAlpha;
            case 328: return ST_InstancedTexTGTexTGEAlphaMul;
            case 329: return ST_InstancedTexTGTexTGEAlphaInv;
            case 330: return ST_InstancedTexTGTexTGCxform;
            case 331: return ST_InstancedTexTGTexTGCxformMul;
            case 332: return ST_InstancedTexTGTexTGCxformInv;
            case 333: return ST_InstancedTexTGTexTGCxformEAlpha;
            case 334: return ST_InstancedTexTGTexTGCxformEAlphaMul;
            case 335: return ST_InstancedTexTGTexTGCxformEAlphaInv;
            case 336: return ST_InstancedTexTGTexTGCxformAc;
            case 337: return ST_InstancedTexTGTexTGCxformAcMul;
            case 338: return ST_InstancedTexTGTexTGCxformAcInv;
            case 339: return ST_InstancedTexTGTexTGCxformAcEAlpha;
            case 340: return ST_InstancedTexTGTexTGCxformAcEAlphaMul;
            case 341: return ST_InstancedTexTGTexTGCxformAcEAlphaInv;
            case 342: return ST_InstancedTexTGVertex;
            case 343: return ST_InstancedTexTGVertexMul;
            case 344: return ST_InstancedTexTGVertexInv;
            case 345: return ST_InstancedTexTGVertexEAlpha;
            case 346: return ST_InstancedTexTGVertexEAlphaMul;
            case 347: return ST_InstancedTexTGVertexEAlphaInv;
            case 348: return ST_InstancedTexTGVertexCxform;
            case 349: return ST_InstancedTexTGVertexCxformMul;
            case 350: return ST_InstancedTexTGVertexCxformInv;
            case 351: return ST_InstancedTexTGVertexCxformEAlpha;
            case 352: return ST_InstancedTexTGVertexCxformEAlphaMul;
            case 353: return ST_InstancedTexTGVertexCxformEAlphaInv;
            case 354: return ST_InstancedTexTGVertexCxformAc;
            case 355: return ST_InstancedTexTGVertexCxformAcMul;
            case 356: return ST_InstancedTexTGVertexCxformAcInv;
            case 357: return ST_InstancedTexTGVertexCxformAcEAlpha;
            case 358: return ST_InstancedTexTGVertexCxformAcEAlphaMul;
            case 359: return ST_InstancedTexTGVertexCxformAcEAlphaInv;
            case 360: return ST_InstancedPosition3dTexTG;
            case 361: return ST_InstancedPosition3dTexTGMul;
            case 362: return ST_InstancedPosition3dTexTGInv;
            case 363: return ST_InstancedPosition3dTexTGEAlpha;
            case 364: return ST_InstancedPosition3dTexTGEAlphaMul;
            case 365: return ST_InstancedPosition3dTexTGEAlphaInv;
            case 366: return ST_InstancedPosition3dTexTGCxform;
            case 367: return ST_InstancedPosition3dTexTGCxformMul;
            case 368: return ST_InstancedPosition3dTexTGCxformInv;
            case 369: return ST_InstancedPosition3dTexTGCxformEAlpha;
            case 370: return ST_InstancedPosition3dTexTGCxformEAlphaMul;
            case 371: return ST_InstancedPosition3dTexTGCxformEAlphaInv;
            case 372: return ST_InstancedPosition3dTexTGCxformAc;
            case 373: return ST_InstancedPosition3dTexTGCxformAcMul;
            case 374: return ST_InstancedPosition3dTexTGCxformAcInv;
            case 375: return ST_InstancedPosition3dTexTGCxformAcEAlpha;
            case 376: return ST_InstancedPosition3dTexTGCxformAcEAlphaMul;
            case 377: return ST_InstancedPosition3dTexTGCxformAcEAlphaInv;
            case 378: return ST_InstancedPosition3dVertex;
            case 379: return ST_InstancedPosition3dVertexMul;
            case 380: return ST_InstancedPosition3dVertexInv;
            case 381: return ST_InstancedPosition3dVertexEAlpha;
            case 382: return ST_InstancedPosition3dVertexEAlphaMul;
            case 383: return ST_InstancedPosition3dVertexEAlphaInv;
            case 384: return ST_InstancedPosition3dVertexCxform;
            case 385: return ST_InstancedPosition3dVertexCxformMul;
            case 386: return ST_InstancedPosition3dVertexCxformInv;
            case 387: return ST_InstancedPosition3dVertexCxformEAlpha;
            case 388: return ST_InstancedPosition3dVertexCxformEAlphaMul;
            case 389: return ST_InstancedPosition3dVertexCxformEAlphaInv;
            case 390: return ST_InstancedPosition3dVertexCxformAc;
            case 391: return ST_InstancedPosition3dVertexCxformAcMul;
            case 392: return ST_InstancedPosition3dVertexCxformAcInv;
            case 393: return ST_InstancedPosition3dVertexCxformAcEAlpha;
            case 394: return ST_InstancedPosition3dVertexCxformAcEAlphaMul;
            case 395: return ST_InstancedPosition3dVertexCxformAcEAlphaInv;
            case 396: return ST_InstancedPosition3dTexTGTexTG;
            case 397: return ST_InstancedPosition3dTexTGTexTGMul;
            case 398: return ST_InstancedPosition3dTexTGTexTGInv;
            case 399: return ST_InstancedPosition3dTexTGTexTGEAlpha;
            case 400: return ST_InstancedPosition3dTexTGTexTGEAlphaMul;
            case 401: return ST_InstancedPosition3dTexTGTexTGEAlphaInv;
            case 402: return ST_InstancedPosition3dTexTGTexTGCxform;
            case 403: return ST_InstancedPosition3dTexTGTexTGCxformMul;
            case 404: return ST_InstancedPosition3dTexTGTexTGCxformInv;
            case 405: return ST_InstancedPosition3dTexTGTexTGCxformEAlpha;
            case 406: return ST_InstancedPosition3dTexTGTexTGCxformEAlphaMul;
            case 407: return ST_InstancedPosition3dTexTGTexTGCxformEAlphaInv;
            case 408: return ST_InstancedPosition3dTexTGTexTGCxformAc;
            case 409: return ST_InstancedPosition3dTexTGTexTGCxformAcMul;
            case 410: return ST_InstancedPosition3dTexTGTexTGCxformAcInv;
            case 411: return ST_InstancedPosition3dTexTGTexTGCxformAcEAlpha;
            case 412: return ST_InstancedPosition3dTexTGTexTGCxformAcEAlphaMul;
            case 413: return ST_InstancedPosition3dTexTGTexTGCxformAcEAlphaInv;
            case 414: return ST_InstancedPosition3dTexTGVertex;
            case 415: return ST_InstancedPosition3dTexTGVertexMul;
            case 416: return ST_InstancedPosition3dTexTGVertexInv;
            case 417: return ST_InstancedPosition3dTexTGVertexEAlpha;
            case 418: return ST_InstancedPosition3dTexTGVertexEAlphaMul;
            case 419: return ST_InstancedPosition3dTexTGVertexEAlphaInv;
            case 420: return ST_InstancedPosition3dTexTGVertexCxform;
            case 421: return ST_InstancedPosition3dTexTGVertexCxformMul;
            case 422: return ST_InstancedPosition3dTexTGVertexCxformInv;
            case 423: return ST_InstancedPosition3dTexTGVertexCxformEAlpha;
            case 424: return ST_InstancedPosition3dTexTGVertexCxformEAlphaMul;
            case 425: return ST_InstancedPosition3dTexTGVertexCxformEAlphaInv;
            case 426: return ST_InstancedPosition3dTexTGVertexCxformAc;
            case 427: return ST_InstancedPosition3dTexTGVertexCxformAcMul;
            case 428: return ST_InstancedPosition3dTexTGVertexCxformAcInv;
            case 429: return ST_InstancedPosition3dTexTGVertexCxformAcEAlpha;
            case 430: return ST_InstancedPosition3dTexTGVertexCxformAcEAlphaMul;
            case 431: return ST_InstancedPosition3dTexTGVertexCxformAcEAlphaInv;
            case 432: return ST_Solid;
            case 433: return ST_SolidMul;
            case 434: return ST_SolidInv;
            case 435: return ST_Text;
            case 436: return ST_TextMul;
            case 437: return ST_TextInv;
            case 438: return ST_TextColor;
            case 439: return ST_TextColorMul;
            case 440: return ST_TextColorInv;
            case 441: return ST_TextColorCxform;
            case 442: return ST_TextColorCxformMul;
            case 443: return ST_TextColorCxformInv;
            case 444: return ST_Position3dSolid;
            case 445: return ST_Position3dSolidMul;
            case 446: return ST_Position3dSolidInv;
            case 447: return ST_Position3dText;
            case 448: return ST_Position3dTextMul;
            case 449: return ST_Position3dTextInv;
            case 450: return ST_Position3dTextColor;
            case 451: return ST_Position3dTextColorMul;
            case 452: return ST_Position3dTextColorInv;
            case 453: return ST_Position3dTextColorCxform;
            case 454: return ST_Position3dTextColorCxformMul;
            case 455: return ST_Position3dTextColorCxformInv;
            case 456: return ST_BatchSolid;
            case 457: return ST_BatchSolidMul;
            case 458: return ST_BatchSolidInv;
            case 459: return ST_BatchText;
            case 460: return ST_BatchTextMul;
            case 461: return ST_BatchTextInv;
            case 462: return ST_BatchTextColor;
            case 463: return ST_BatchTextColorMul;
            case 464: return ST_BatchTextColorInv;
            case 465: return ST_BatchTextColorCxform;
            case 466: return ST_BatchTextColorCxformMul;
            case 467: return ST_BatchTextColorCxformInv;
            case 468: return ST_BatchPosition3dSolid;
            case 469: return ST_BatchPosition3dSolidMul;
            case 470: return ST_BatchPosition3dSolidInv;
            case 471: return ST_BatchPosition3dText;
            case 472: return ST_BatchPosition3dTextMul;
            case 473: return ST_BatchPosition3dTextInv;
            case 474: return ST_BatchPosition3dTextColor;
            case 475: return ST_BatchPosition3dTextColorMul;
            case 476: return ST_BatchPosition3dTextColorInv;
            case 477: return ST_BatchPosition3dTextColorCxform;
            case 478: return ST_BatchPosition3dTextColorCxformMul;
            case 479: return ST_BatchPosition3dTextColorCxformInv;
            case 480: return ST_InstancedSolid;
            case 481: return ST_InstancedSolidMul;
            case 482: return ST_InstancedSolidInv;
            case 483: return ST_InstancedText;
            case 484: return ST_InstancedTextMul;
            case 485: return ST_InstancedTextInv;
            case 486: return ST_InstancedTextColor;
            case 487: return ST_InstancedTextColorMul;
            case 488: return ST_InstancedTextColorInv;
            case 489: return ST_InstancedTextColorCxform;
            case 490: return ST_InstancedTextColorCxformMul;
            case 491: return ST_InstancedTextColorCxformInv;
            case 492: return ST_InstancedPosition3dSolid;
            case 493: return ST_InstancedPosition3dSolidMul;
            case 494: return ST_InstancedPosition3dSolidInv;
            case 495: return ST_InstancedPosition3dText;
            case 496: return ST_InstancedPosition3dTextMul;
            case 497: return ST_InstancedPosition3dTextInv;
            case 498: return ST_InstancedPosition3dTextColor;
            case 499: return ST_InstancedPosition3dTextColorMul;
            case 500: return ST_InstancedPosition3dTextColorInv;
            case 501: return ST_InstancedPosition3dTextColorCxform;
            case 502: return ST_InstancedPosition3dTextColorCxformMul;
            case 503: return ST_InstancedPosition3dTextColorCxformInv;
            case 504: return ST_YUV;
            case 505: return ST_YUVMul;
            case 506: return ST_YUVEAlpha;
            case 507: return ST_YUVEAlphaMul;
            case 508: return ST_YUVCxform;
            case 509: return ST_YUVCxformMul;
            case 510: return ST_YUVCxformEAlpha;
            case 511: return ST_YUVCxformEAlphaMul;
            case 512: return ST_YUVCxformAc;
            case 513: return ST_YUVCxformAcMul;
            case 514: return ST_YUVCxformAcEAlpha;
            case 515: return ST_YUVCxformAcEAlphaMul;
            case 516: return ST_YUVA;
            case 517: return ST_YUVAMul;
            case 518: return ST_YUVAInv;
            case 519: return ST_YUVAEAlpha;
            case 520: return ST_YUVAEAlphaMul;
            case 521: return ST_YUVAEAlphaInv;
            case 522: return ST_YUVACxform;
            case 523: return ST_YUVACxformMul;
            case 524: return ST_YUVACxformInv;
            case 525: return ST_YUVACxformEAlpha;
            case 526: return ST_YUVACxformEAlphaMul;
            case 527: return ST_YUVACxformEAlphaInv;
            case 528: return ST_YUVACxformAc;
            case 529: return ST_YUVACxformAcMul;
            case 530: return ST_YUVACxformAcInv;
            case 531: return ST_YUVACxformAcEAlpha;
            case 532: return ST_YUVACxformAcEAlphaMul;
            case 533: return ST_YUVACxformAcEAlphaInv;
            case 534: return ST_Position3dYUV;
            case 535: return ST_Position3dYUVMul;
            case 536: return ST_Position3dYUVEAlpha;
            case 537: return ST_Position3dYUVEAlphaMul;
            case 538: return ST_Position3dYUVCxform;
            case 539: return ST_Position3dYUVCxformMul;
            case 540: return ST_Position3dYUVCxformEAlpha;
            case 541: return ST_Position3dYUVCxformEAlphaMul;
            case 542: return ST_Position3dYUVCxformAc;
            case 543: return ST_Position3dYUVCxformAcMul;
            case 544: return ST_Position3dYUVCxformAcEAlpha;
            case 545: return ST_Position3dYUVCxformAcEAlphaMul;
            case 546: return ST_Position3dYUVA;
            case 547: return ST_Position3dYUVAMul;
            case 548: return ST_Position3dYUVAInv;
            case 549: return ST_Position3dYUVAEAlpha;
            case 550: return ST_Position3dYUVAEAlphaMul;
            case 551: return ST_Position3dYUVAEAlphaInv;
            case 552: return ST_Position3dYUVACxform;
            case 553: return ST_Position3dYUVACxformMul;
            case 554: return ST_Position3dYUVACxformInv;
            case 555: return ST_Position3dYUVACxformEAlpha;
            case 556: return ST_Position3dYUVACxformEAlphaMul;
            case 557: return ST_Position3dYUVACxformEAlphaInv;
            case 558: return ST_Position3dYUVACxformAc;
            case 559: return ST_Position3dYUVACxformAcMul;
            case 560: return ST_Position3dYUVACxformAcInv;
            case 561: return ST_Position3dYUVACxformAcEAlpha;
            case 562: return ST_Position3dYUVACxformAcEAlphaMul;
            case 563: return ST_Position3dYUVACxformAcEAlphaInv;
            case 564: return ST_BatchYUV;
            case 565: return ST_BatchYUVMul;
            case 566: return ST_BatchYUVEAlpha;
            case 567: return ST_BatchYUVEAlphaMul;
            case 568: return ST_BatchYUVCxform;
            case 569: return ST_BatchYUVCxformMul;
            case 570: return ST_BatchYUVCxformEAlpha;
            case 571: return ST_BatchYUVCxformEAlphaMul;
            case 572: return ST_BatchYUVCxformAc;
            case 573: return ST_BatchYUVCxformAcMul;
            case 574: return ST_BatchYUVCxformAcEAlpha;
            case 575: return ST_BatchYUVCxformAcEAlphaMul;
            case 576: return ST_BatchYUVA;
            case 577: return ST_BatchYUVAMul;
            case 578: return ST_BatchYUVAInv;
            case 579: return ST_BatchYUVAEAlpha;
            case 580: return ST_BatchYUVAEAlphaMul;
            case 581: return ST_BatchYUVAEAlphaInv;
            case 582: return ST_BatchYUVACxform;
            case 583: return ST_BatchYUVACxformMul;
            case 584: return ST_BatchYUVACxformInv;
            case 585: return ST_BatchYUVACxformEAlpha;
            case 586: return ST_BatchYUVACxformEAlphaMul;
            case 587: return ST_BatchYUVACxformEAlphaInv;
            case 588: return ST_BatchYUVACxformAc;
            case 589: return ST_BatchYUVACxformAcMul;
            case 590: return ST_BatchYUVACxformAcInv;
            case 591: return ST_BatchYUVACxformAcEAlpha;
            case 592: return ST_BatchYUVACxformAcEAlphaMul;
            case 593: return ST_BatchYUVACxformAcEAlphaInv;
            case 594: return ST_BatchPosition3dYUV;
            case 595: return ST_BatchPosition3dYUVMul;
            case 596: return ST_BatchPosition3dYUVEAlpha;
            case 597: return ST_BatchPosition3dYUVEAlphaMul;
            case 598: return ST_BatchPosition3dYUVCxform;
            case 599: return ST_BatchPosition3dYUVCxformMul;
            case 600: return ST_BatchPosition3dYUVCxformEAlpha;
            case 601: return ST_BatchPosition3dYUVCxformEAlphaMul;
            case 602: return ST_BatchPosition3dYUVCxformAc;
            case 603: return ST_BatchPosition3dYUVCxformAcMul;
            case 604: return ST_BatchPosition3dYUVCxformAcEAlpha;
            case 605: return ST_BatchPosition3dYUVCxformAcEAlphaMul;
            case 606: return ST_BatchPosition3dYUVA;
            case 607: return ST_BatchPosition3dYUVAMul;
            case 608: return ST_BatchPosition3dYUVAInv;
            case 609: return ST_BatchPosition3dYUVAEAlpha;
            case 610: return ST_BatchPosition3dYUVAEAlphaMul;
            case 611: return ST_BatchPosition3dYUVAEAlphaInv;
            case 612: return ST_BatchPosition3dYUVACxform;
            case 613: return ST_BatchPosition3dYUVACxformMul;
            case 614: return ST_BatchPosition3dYUVACxformInv;
            case 615: return ST_BatchPosition3dYUVACxformEAlpha;
            case 616: return ST_BatchPosition3dYUVACxformEAlphaMul;
            case 617: return ST_BatchPosition3dYUVACxformEAlphaInv;
            case 618: return ST_BatchPosition3dYUVACxformAc;
            case 619: return ST_BatchPosition3dYUVACxformAcMul;
            case 620: return ST_BatchPosition3dYUVACxformAcInv;
            case 621: return ST_BatchPosition3dYUVACxformAcEAlpha;
            case 622: return ST_BatchPosition3dYUVACxformAcEAlphaMul;
            case 623: return ST_BatchPosition3dYUVACxformAcEAlphaInv;
            case 624: return ST_InstancedYUV;
            case 625: return ST_InstancedYUVMul;
            case 626: return ST_InstancedYUVEAlpha;
            case 627: return ST_InstancedYUVEAlphaMul;
            case 628: return ST_InstancedYUVCxform;
            case 629: return ST_InstancedYUVCxformMul;
            case 630: return ST_InstancedYUVCxformEAlpha;
            case 631: return ST_InstancedYUVCxformEAlphaMul;
            case 632: return ST_InstancedYUVCxformAc;
            case 633: return ST_InstancedYUVCxformAcMul;
            case 634: return ST_InstancedYUVCxformAcEAlpha;
            case 635: return ST_InstancedYUVCxformAcEAlphaMul;
            case 636: return ST_InstancedYUVA;
            case 637: return ST_InstancedYUVAMul;
            case 638: return ST_InstancedYUVAInv;
            case 639: return ST_InstancedYUVAEAlpha;
            case 640: return ST_InstancedYUVAEAlphaMul;
            case 641: return ST_InstancedYUVAEAlphaInv;
            case 642: return ST_InstancedYUVACxform;
            case 643: return ST_InstancedYUVACxformMul;
            case 644: return ST_InstancedYUVACxformInv;
            case 645: return ST_InstancedYUVACxformEAlpha;
            case 646: return ST_InstancedYUVACxformEAlphaMul;
            case 647: return ST_InstancedYUVACxformEAlphaInv;
            case 648: return ST_InstancedYUVACxformAc;
            case 649: return ST_InstancedYUVACxformAcMul;
            case 650: return ST_InstancedYUVACxformAcInv;
            case 651: return ST_InstancedYUVACxformAcEAlpha;
            case 652: return ST_InstancedYUVACxformAcEAlphaMul;
            case 653: return ST_InstancedYUVACxformAcEAlphaInv;
            case 654: return ST_InstancedPosition3dYUV;
            case 655: return ST_InstancedPosition3dYUVMul;
            case 656: return ST_InstancedPosition3dYUVEAlpha;
            case 657: return ST_InstancedPosition3dYUVEAlphaMul;
            case 658: return ST_InstancedPosition3dYUVCxform;
            case 659: return ST_InstancedPosition3dYUVCxformMul;
            case 660: return ST_InstancedPosition3dYUVCxformEAlpha;
            case 661: return ST_InstancedPosition3dYUVCxformEAlphaMul;
            case 662: return ST_InstancedPosition3dYUVCxformAc;
            case 663: return ST_InstancedPosition3dYUVCxformAcMul;
            case 664: return ST_InstancedPosition3dYUVCxformAcEAlpha;
            case 665: return ST_InstancedPosition3dYUVCxformAcEAlphaMul;
            case 666: return ST_InstancedPosition3dYUVA;
            case 667: return ST_InstancedPosition3dYUVAMul;
            case 668: return ST_InstancedPosition3dYUVAInv;
            case 669: return ST_InstancedPosition3dYUVAEAlpha;
            case 670: return ST_InstancedPosition3dYUVAEAlphaMul;
            case 671: return ST_InstancedPosition3dYUVAEAlphaInv;
            case 672: return ST_InstancedPosition3dYUVACxform;
            case 673: return ST_InstancedPosition3dYUVACxformMul;
            case 674: return ST_InstancedPosition3dYUVACxformInv;
            case 675: return ST_InstancedPosition3dYUVACxformEAlpha;
            case 676: return ST_InstancedPosition3dYUVACxformEAlphaMul;
            case 677: return ST_InstancedPosition3dYUVACxformEAlphaInv;
            case 678: return ST_InstancedPosition3dYUVACxformAc;
            case 679: return ST_InstancedPosition3dYUVACxformAcMul;
            case 680: return ST_InstancedPosition3dYUVACxformAcInv;
            case 681: return ST_InstancedPosition3dYUVACxformAcEAlpha;
            case 682: return ST_InstancedPosition3dYUVACxformAcEAlphaMul;
            case 683: return ST_InstancedPosition3dYUVACxformAcEAlphaInv;
            case 684: return ST_TexTGCMatrixAc;
            case 685: return ST_TexTGCMatrixAcMul;
            case 686: return ST_TexTGCMatrixAcEAlpha;
            case 687: return ST_TexTGCMatrixAcEAlphaMul;
            case 688: return ST_Box1Blur;
            case 689: return ST_Box1BlurMul;
            case 690: return ST_Box2Blur;
            case 691: return ST_Box2BlurMul;
            case 692: return ST_Box2Shadow;
            case 693: return ST_Box2ShadowMul;
            case 694: return ST_Box2ShadowKnockout;
            case 695: return ST_Box2ShadowKnockoutMul;
            case 696: return ST_Box2InnerShadow;
            case 697: return ST_Box2InnerShadowMul;
            case 698: return ST_Box2InnerShadowKnockout;
            case 699: return ST_Box2InnerShadowKnockoutMul;
            case 700: return ST_Box2Shadowonly;
            case 701: return ST_Box2ShadowonlyMul;
            case 702: return ST_Box2ShadowHighlight;
            case 703: return ST_Box2ShadowHighlightMul;
            case 704: return ST_Box2ShadowHighlightKnockout;
            case 705: return ST_Box2ShadowHighlightKnockoutMul;
            case 706: return ST_Box2InnerShadowHighlight;
            case 707: return ST_Box2InnerShadowHighlightMul;
            case 708: return ST_Box2InnerShadowHighlightKnockout;
            case 709: return ST_Box2InnerShadowHighlightKnockoutMul;
            case 710: return ST_Box2FullShadowHighlight;
            case 711: return ST_Box2FullShadowHighlightMul;
            case 712: return ST_Box2ShadowonlyHighlight;
            case 713: return ST_Box2ShadowonlyHighlightMul;
            case 714: return ST_DrawableCopyPixels;
            case 715: return ST_DrawableCopyPixelsMergeAlpha;
            case 716: return ST_DrawableCopyPixelsNoDestAlpha;
            case 717: return ST_DrawableCopyPixelsAlpha;
            case 718: return ST_DrawableCopyPixelsAlphaMergeAlpha;
            case 719: return ST_DrawableCopyPixelsAlphaNoDestAlpha;
            case 720: return ST_DrawableMerge;
            case 721: return ST_DrawableCompare;
            case 722: return ST_DrawablePaletteMap;
            default: SF_DEBUG_ASSERT1(1, "Invalid shader combo index provided (%d)", comboIndex); return ST_None;
        }
        default: SF_DEBUG_ASSERT1(1, "Invalid shader platform provided (%d)", ver); return ST_None;
    }
};

ShaderDesc::ShaderIndex ShaderDesc::GetShaderIndex(ShaderType type)
{
    switch(type)
    {
        case ST_TexTG:                                           return STI_TexTG;
        case ST_TexTGMul:                                        return STI_TexTGMul;
        case ST_BatchTexTG:                                      return STI_BatchTexTG;
        case ST_BatchTexTGMul:                                   return STI_BatchTexTGMul;
        case ST_InstancedTexTG:                                  return STI_InstancedTexTG;
        case ST_InstancedTexTGMul:                               return STI_InstancedTexTGMul;
        case ST_Position3dTexTG:                                 return STI_Position3dTexTG;
        case ST_Position3dTexTGMul:                              return STI_Position3dTexTGMul;
        case ST_BatchPosition3dTexTG:                            return STI_BatchPosition3dTexTG;
        case ST_BatchPosition3dTexTGMul:                         return STI_BatchPosition3dTexTGMul;
        case ST_InstancedPosition3dTexTG:                        return STI_InstancedPosition3dTexTG;
        case ST_InstancedPosition3dTexTGMul:                     return STI_InstancedPosition3dTexTGMul;
        case ST_TexTGCxform:                                     return STI_TexTGCxform;
        case ST_TexTGCxformMul:                                  return STI_TexTGCxformMul;
        case ST_BatchTexTGCxform:                                return STI_BatchTexTGCxform;
        case ST_BatchTexTGCxformMul:                             return STI_BatchTexTGCxformMul;
        case ST_InstancedTexTGCxform:                            return STI_InstancedTexTGCxform;
        case ST_InstancedTexTGCxformMul:                         return STI_InstancedTexTGCxformMul;
        case ST_Position3dTexTGCxform:                           return STI_Position3dTexTGCxform;
        case ST_Position3dTexTGCxformMul:                        return STI_Position3dTexTGCxformMul;
        case ST_BatchPosition3dTexTGCxform:                      return STI_BatchPosition3dTexTGCxform;
        case ST_BatchPosition3dTexTGCxformMul:                   return STI_BatchPosition3dTexTGCxformMul;
        case ST_InstancedPosition3dTexTGCxform:                  return STI_InstancedPosition3dTexTGCxform;
        case ST_InstancedPosition3dTexTGCxformMul:               return STI_InstancedPosition3dTexTGCxformMul;
        case ST_TexTGEAlpha:                                     return STI_TexTGEAlpha;
        case ST_TexTGEAlphaMul:                                  return STI_TexTGEAlphaMul;
        case ST_BatchTexTGEAlpha:                                return STI_BatchTexTGEAlpha;
        case ST_BatchTexTGEAlphaMul:                             return STI_BatchTexTGEAlphaMul;
        case ST_InstancedTexTGEAlpha:                            return STI_InstancedTexTGEAlpha;
        case ST_InstancedTexTGEAlphaMul:                         return STI_InstancedTexTGEAlphaMul;
        case ST_Position3dTexTGEAlpha:                           return STI_Position3dTexTGEAlpha;
        case ST_Position3dTexTGEAlphaMul:                        return STI_Position3dTexTGEAlphaMul;
        case ST_BatchPosition3dTexTGEAlpha:                      return STI_BatchPosition3dTexTGEAlpha;
        case ST_BatchPosition3dTexTGEAlphaMul:                   return STI_BatchPosition3dTexTGEAlphaMul;
        case ST_InstancedPosition3dTexTGEAlpha:                  return STI_InstancedPosition3dTexTGEAlpha;
        case ST_InstancedPosition3dTexTGEAlphaMul:               return STI_InstancedPosition3dTexTGEAlphaMul;
        case ST_TexTGCxformEAlpha:                               return STI_TexTGCxformEAlpha;
        case ST_TexTGCxformEAlphaMul:                            return STI_TexTGCxformEAlphaMul;
        case ST_BatchTexTGCxformEAlpha:                          return STI_BatchTexTGCxformEAlpha;
        case ST_BatchTexTGCxformEAlphaMul:                       return STI_BatchTexTGCxformEAlphaMul;
        case ST_InstancedTexTGCxformEAlpha:                      return STI_InstancedTexTGCxformEAlpha;
        case ST_InstancedTexTGCxformEAlphaMul:                   return STI_InstancedTexTGCxformEAlphaMul;
        case ST_Position3dTexTGCxformEAlpha:                     return STI_Position3dTexTGCxformEAlpha;
        case ST_Position3dTexTGCxformEAlphaMul:                  return STI_Position3dTexTGCxformEAlphaMul;
        case ST_BatchPosition3dTexTGCxformEAlpha:                return STI_BatchPosition3dTexTGCxformEAlpha;
        case ST_BatchPosition3dTexTGCxformEAlphaMul:             return STI_BatchPosition3dTexTGCxformEAlphaMul;
        case ST_InstancedPosition3dTexTGCxformEAlpha:            return STI_InstancedPosition3dTexTGCxformEAlpha;
        case ST_InstancedPosition3dTexTGCxformEAlphaMul:         return STI_InstancedPosition3dTexTGCxformEAlphaMul;
        case ST_TexTGInv:                                        return STI_TexTGInv;
        case ST_BatchTexTGInv:                                   return STI_BatchTexTGInv;
        case ST_InstancedTexTGInv:                               return STI_InstancedTexTGInv;
        case ST_Position3dTexTGInv:                              return STI_Position3dTexTGInv;
        case ST_BatchPosition3dTexTGInv:                         return STI_BatchPosition3dTexTGInv;
        case ST_InstancedPosition3dTexTGInv:                     return STI_InstancedPosition3dTexTGInv;
        case ST_TexTGCxformInv:                                  return STI_TexTGCxformInv;
        case ST_BatchTexTGCxformInv:                             return STI_BatchTexTGCxformInv;
        case ST_InstancedTexTGCxformInv:                         return STI_InstancedTexTGCxformInv;
        case ST_Position3dTexTGCxformInv:                        return STI_Position3dTexTGCxformInv;
        case ST_BatchPosition3dTexTGCxformInv:                   return STI_BatchPosition3dTexTGCxformInv;
        case ST_InstancedPosition3dTexTGCxformInv:               return STI_InstancedPosition3dTexTGCxformInv;
        case ST_TexTGEAlphaInv:                                  return STI_TexTGEAlphaInv;
        case ST_BatchTexTGEAlphaInv:                             return STI_BatchTexTGEAlphaInv;
        case ST_InstancedTexTGEAlphaInv:                         return STI_InstancedTexTGEAlphaInv;
        case ST_Position3dTexTGEAlphaInv:                        return STI_Position3dTexTGEAlphaInv;
        case ST_BatchPosition3dTexTGEAlphaInv:                   return STI_BatchPosition3dTexTGEAlphaInv;
        case ST_InstancedPosition3dTexTGEAlphaInv:               return STI_InstancedPosition3dTexTGEAlphaInv;
        case ST_TexTGCxformEAlphaInv:                            return STI_TexTGCxformEAlphaInv;
        case ST_BatchTexTGCxformEAlphaInv:                       return STI_BatchTexTGCxformEAlphaInv;
        case ST_InstancedTexTGCxformEAlphaInv:                   return STI_InstancedTexTGCxformEAlphaInv;
        case ST_Position3dTexTGCxformEAlphaInv:                  return STI_Position3dTexTGCxformEAlphaInv;
        case ST_BatchPosition3dTexTGCxformEAlphaInv:             return STI_BatchPosition3dTexTGCxformEAlphaInv;
        case ST_InstancedPosition3dTexTGCxformEAlphaInv:         return STI_InstancedPosition3dTexTGCxformEAlphaInv;
        case ST_TexTGCxformAc:                                   return STI_TexTGCxformAc;
        case ST_TexTGCxformAcMul:                                return STI_TexTGCxformAcMul;
        case ST_BatchTexTGCxformAc:                              return STI_BatchTexTGCxformAc;
        case ST_BatchTexTGCxformAcMul:                           return STI_BatchTexTGCxformAcMul;
        case ST_InstancedTexTGCxformAc:                          return STI_InstancedTexTGCxformAc;
        case ST_InstancedTexTGCxformAcMul:                       return STI_InstancedTexTGCxformAcMul;
        case ST_Position3dTexTGCxformAc:                         return STI_Position3dTexTGCxformAc;
        case ST_Position3dTexTGCxformAcMul:                      return STI_Position3dTexTGCxformAcMul;
        case ST_BatchPosition3dTexTGCxformAc:                    return STI_BatchPosition3dTexTGCxformAc;
        case ST_BatchPosition3dTexTGCxformAcMul:                 return STI_BatchPosition3dTexTGCxformAcMul;
        case ST_InstancedPosition3dTexTGCxformAc:                return STI_InstancedPosition3dTexTGCxformAc;
        case ST_InstancedPosition3dTexTGCxformAcMul:             return STI_InstancedPosition3dTexTGCxformAcMul;
        case ST_TexTGCxformAcEAlpha:                             return STI_TexTGCxformAcEAlpha;
        case ST_TexTGCxformAcEAlphaMul:                          return STI_TexTGCxformAcEAlphaMul;
        case ST_BatchTexTGCxformAcEAlpha:                        return STI_BatchTexTGCxformAcEAlpha;
        case ST_BatchTexTGCxformAcEAlphaMul:                     return STI_BatchTexTGCxformAcEAlphaMul;
        case ST_InstancedTexTGCxformAcEAlpha:                    return STI_InstancedTexTGCxformAcEAlpha;
        case ST_InstancedTexTGCxformAcEAlphaMul:                 return STI_InstancedTexTGCxformAcEAlphaMul;
        case ST_Position3dTexTGCxformAcEAlpha:                   return STI_Position3dTexTGCxformAcEAlpha;
        case ST_Position3dTexTGCxformAcEAlphaMul:                return STI_Position3dTexTGCxformAcEAlphaMul;
        case ST_BatchPosition3dTexTGCxformAcEAlpha:              return STI_BatchPosition3dTexTGCxformAcEAlpha;
        case ST_BatchPosition3dTexTGCxformAcEAlphaMul:           return STI_BatchPosition3dTexTGCxformAcEAlphaMul;
        case ST_InstancedPosition3dTexTGCxformAcEAlpha:          return STI_InstancedPosition3dTexTGCxformAcEAlpha;
        case ST_InstancedPosition3dTexTGCxformAcEAlphaMul:       return STI_InstancedPosition3dTexTGCxformAcEAlphaMul;
        case ST_TexTGCxformAcInv:                                return STI_TexTGCxformAcInv;
        case ST_BatchTexTGCxformAcInv:                           return STI_BatchTexTGCxformAcInv;
        case ST_InstancedTexTGCxformAcInv:                       return STI_InstancedTexTGCxformAcInv;
        case ST_Position3dTexTGCxformAcInv:                      return STI_Position3dTexTGCxformAcInv;
        case ST_BatchPosition3dTexTGCxformAcInv:                 return STI_BatchPosition3dTexTGCxformAcInv;
        case ST_InstancedPosition3dTexTGCxformAcInv:             return STI_InstancedPosition3dTexTGCxformAcInv;
        case ST_TexTGCxformAcEAlphaInv:                          return STI_TexTGCxformAcEAlphaInv;
        case ST_BatchTexTGCxformAcEAlphaInv:                     return STI_BatchTexTGCxformAcEAlphaInv;
        case ST_InstancedTexTGCxformAcEAlphaInv:                 return STI_InstancedTexTGCxformAcEAlphaInv;
        case ST_Position3dTexTGCxformAcEAlphaInv:                return STI_Position3dTexTGCxformAcEAlphaInv;
        case ST_BatchPosition3dTexTGCxformAcEAlphaInv:           return STI_BatchPosition3dTexTGCxformAcEAlphaInv;
        case ST_InstancedPosition3dTexTGCxformAcEAlphaInv:       return STI_InstancedPosition3dTexTGCxformAcEAlphaInv;
        case ST_Vertex:                                          return STI_Vertex;
        case ST_VertexMul:                                       return STI_VertexMul;
        case ST_BatchVertex:                                     return STI_BatchVertex;
        case ST_BatchVertexMul:                                  return STI_BatchVertexMul;
        case ST_InstancedVertex:                                 return STI_InstancedVertex;
        case ST_InstancedVertexMul:                              return STI_InstancedVertexMul;
        case ST_Position3dVertex:                                return STI_Position3dVertex;
        case ST_Position3dVertexMul:                             return STI_Position3dVertexMul;
        case ST_BatchPosition3dVertex:                           return STI_BatchPosition3dVertex;
        case ST_BatchPosition3dVertexMul:                        return STI_BatchPosition3dVertexMul;
        case ST_InstancedPosition3dVertex:                       return STI_InstancedPosition3dVertex;
        case ST_InstancedPosition3dVertexMul:                    return STI_InstancedPosition3dVertexMul;
        case ST_VertexCxform:                                    return STI_VertexCxform;
        case ST_VertexCxformMul:                                 return STI_VertexCxformMul;
        case ST_BatchVertexCxform:                               return STI_BatchVertexCxform;
        case ST_BatchVertexCxformMul:                            return STI_BatchVertexCxformMul;
        case ST_InstancedVertexCxform:                           return STI_InstancedVertexCxform;
        case ST_InstancedVertexCxformMul:                        return STI_InstancedVertexCxformMul;
        case ST_Position3dVertexCxform:                          return STI_Position3dVertexCxform;
        case ST_Position3dVertexCxformMul:                       return STI_Position3dVertexCxformMul;
        case ST_BatchPosition3dVertexCxform:                     return STI_BatchPosition3dVertexCxform;
        case ST_BatchPosition3dVertexCxformMul:                  return STI_BatchPosition3dVertexCxformMul;
        case ST_InstancedPosition3dVertexCxform:                 return STI_InstancedPosition3dVertexCxform;
        case ST_InstancedPosition3dVertexCxformMul:              return STI_InstancedPosition3dVertexCxformMul;
        case ST_VertexEAlpha:                                    return STI_VertexEAlpha;
        case ST_VertexEAlphaMul:                                 return STI_VertexEAlphaMul;
        case ST_BatchVertexEAlpha:                               return STI_BatchVertexEAlpha;
        case ST_BatchVertexEAlphaMul:                            return STI_BatchVertexEAlphaMul;
        case ST_InstancedVertexEAlpha:                           return STI_InstancedVertexEAlpha;
        case ST_InstancedVertexEAlphaMul:                        return STI_InstancedVertexEAlphaMul;
        case ST_Position3dVertexEAlpha:                          return STI_Position3dVertexEAlpha;
        case ST_Position3dVertexEAlphaMul:                       return STI_Position3dVertexEAlphaMul;
        case ST_BatchPosition3dVertexEAlpha:                     return STI_BatchPosition3dVertexEAlpha;
        case ST_BatchPosition3dVertexEAlphaMul:                  return STI_BatchPosition3dVertexEAlphaMul;
        case ST_InstancedPosition3dVertexEAlpha:                 return STI_InstancedPosition3dVertexEAlpha;
        case ST_InstancedPosition3dVertexEAlphaMul:              return STI_InstancedPosition3dVertexEAlphaMul;
        case ST_VertexCxformEAlpha:                              return STI_VertexCxformEAlpha;
        case ST_VertexCxformEAlphaMul:                           return STI_VertexCxformEAlphaMul;
        case ST_BatchVertexCxformEAlpha:                         return STI_BatchVertexCxformEAlpha;
        case ST_BatchVertexCxformEAlphaMul:                      return STI_BatchVertexCxformEAlphaMul;
        case ST_InstancedVertexCxformEAlpha:                     return STI_InstancedVertexCxformEAlpha;
        case ST_InstancedVertexCxformEAlphaMul:                  return STI_InstancedVertexCxformEAlphaMul;
        case ST_Position3dVertexCxformEAlpha:                    return STI_Position3dVertexCxformEAlpha;
        case ST_Position3dVertexCxformEAlphaMul:                 return STI_Position3dVertexCxformEAlphaMul;
        case ST_BatchPosition3dVertexCxformEAlpha:               return STI_BatchPosition3dVertexCxformEAlpha;
        case ST_BatchPosition3dVertexCxformEAlphaMul:            return STI_BatchPosition3dVertexCxformEAlphaMul;
        case ST_InstancedPosition3dVertexCxformEAlpha:           return STI_InstancedPosition3dVertexCxformEAlpha;
        case ST_InstancedPosition3dVertexCxformEAlphaMul:        return STI_InstancedPosition3dVertexCxformEAlphaMul;
        case ST_VertexInv:                                       return STI_VertexInv;
        case ST_BatchVertexInv:                                  return STI_BatchVertexInv;
        case ST_InstancedVertexInv:                              return STI_InstancedVertexInv;
        case ST_Position3dVertexInv:                             return STI_Position3dVertexInv;
        case ST_BatchPosition3dVertexInv:                        return STI_BatchPosition3dVertexInv;
        case ST_InstancedPosition3dVertexInv:                    return STI_InstancedPosition3dVertexInv;
        case ST_VertexCxformInv:                                 return STI_VertexCxformInv;
        case ST_BatchVertexCxformInv:                            return STI_BatchVertexCxformInv;
        case ST_InstancedVertexCxformInv:                        return STI_InstancedVertexCxformInv;
        case ST_Position3dVertexCxformInv:                       return STI_Position3dVertexCxformInv;
        case ST_BatchPosition3dVertexCxformInv:                  return STI_BatchPosition3dVertexCxformInv;
        case ST_InstancedPosition3dVertexCxformInv:              return STI_InstancedPosition3dVertexCxformInv;
        case ST_VertexEAlphaInv:                                 return STI_VertexEAlphaInv;
        case ST_BatchVertexEAlphaInv:                            return STI_BatchVertexEAlphaInv;
        case ST_InstancedVertexEAlphaInv:                        return STI_InstancedVertexEAlphaInv;
        case ST_Position3dVertexEAlphaInv:                       return STI_Position3dVertexEAlphaInv;
        case ST_BatchPosition3dVertexEAlphaInv:                  return STI_BatchPosition3dVertexEAlphaInv;
        case ST_InstancedPosition3dVertexEAlphaInv:              return STI_InstancedPosition3dVertexEAlphaInv;
        case ST_VertexCxformEAlphaInv:                           return STI_VertexCxformEAlphaInv;
        case ST_BatchVertexCxformEAlphaInv:                      return STI_BatchVertexCxformEAlphaInv;
        case ST_InstancedVertexCxformEAlphaInv:                  return STI_InstancedVertexCxformEAlphaInv;
        case ST_Position3dVertexCxformEAlphaInv:                 return STI_Position3dVertexCxformEAlphaInv;
        case ST_BatchPosition3dVertexCxformEAlphaInv:            return STI_BatchPosition3dVertexCxformEAlphaInv;
        case ST_InstancedPosition3dVertexCxformEAlphaInv:        return STI_InstancedPosition3dVertexCxformEAlphaInv;
        case ST_VertexCxformAc:                                  return STI_VertexCxformAc;
        case ST_VertexCxformAcMul:                               return STI_VertexCxformAcMul;
        case ST_BatchVertexCxformAc:                             return STI_BatchVertexCxformAc;
        case ST_BatchVertexCxformAcMul:                          return STI_BatchVertexCxformAcMul;
        case ST_InstancedVertexCxformAc:                         return STI_InstancedVertexCxformAc;
        case ST_InstancedVertexCxformAcMul:                      return STI_InstancedVertexCxformAcMul;
        case ST_Position3dVertexCxformAc:                        return STI_Position3dVertexCxformAc;
        case ST_Position3dVertexCxformAcMul:                     return STI_Position3dVertexCxformAcMul;
        case ST_BatchPosition3dVertexCxformAc:                   return STI_BatchPosition3dVertexCxformAc;
        case ST_BatchPosition3dVertexCxformAcMul:                return STI_BatchPosition3dVertexCxformAcMul;
        case ST_InstancedPosition3dVertexCxformAc:               return STI_InstancedPosition3dVertexCxformAc;
        case ST_InstancedPosition3dVertexCxformAcMul:            return STI_InstancedPosition3dVertexCxformAcMul;
        case ST_VertexCxformAcEAlpha:                            return STI_VertexCxformAcEAlpha;
        case ST_VertexCxformAcEAlphaMul:                         return STI_VertexCxformAcEAlphaMul;
        case ST_BatchVertexCxformAcEAlpha:                       return STI_BatchVertexCxformAcEAlpha;
        case ST_BatchVertexCxformAcEAlphaMul:                    return STI_BatchVertexCxformAcEAlphaMul;
        case ST_InstancedVertexCxformAcEAlpha:                   return STI_InstancedVertexCxformAcEAlpha;
        case ST_InstancedVertexCxformAcEAlphaMul:                return STI_InstancedVertexCxformAcEAlphaMul;
        case ST_Position3dVertexCxformAcEAlpha:                  return STI_Position3dVertexCxformAcEAlpha;
        case ST_Position3dVertexCxformAcEAlphaMul:               return STI_Position3dVertexCxformAcEAlphaMul;
        case ST_BatchPosition3dVertexCxformAcEAlpha:             return STI_BatchPosition3dVertexCxformAcEAlpha;
        case ST_BatchPosition3dVertexCxformAcEAlphaMul:          return STI_BatchPosition3dVertexCxformAcEAlphaMul;
        case ST_InstancedPosition3dVertexCxformAcEAlpha:         return STI_InstancedPosition3dVertexCxformAcEAlpha;
        case ST_InstancedPosition3dVertexCxformAcEAlphaMul:      return STI_InstancedPosition3dVertexCxformAcEAlphaMul;
        case ST_VertexCxformAcInv:                               return STI_VertexCxformAcInv;
        case ST_BatchVertexCxformAcInv:                          return STI_BatchVertexCxformAcInv;
        case ST_InstancedVertexCxformAcInv:                      return STI_InstancedVertexCxformAcInv;
        case ST_Position3dVertexCxformAcInv:                     return STI_Position3dVertexCxformAcInv;
        case ST_BatchPosition3dVertexCxformAcInv:                return STI_BatchPosition3dVertexCxformAcInv;
        case ST_InstancedPosition3dVertexCxformAcInv:            return STI_InstancedPosition3dVertexCxformAcInv;
        case ST_VertexCxformAcEAlphaInv:                         return STI_VertexCxformAcEAlphaInv;
        case ST_BatchVertexCxformAcEAlphaInv:                    return STI_BatchVertexCxformAcEAlphaInv;
        case ST_InstancedVertexCxformAcEAlphaInv:                return STI_InstancedVertexCxformAcEAlphaInv;
        case ST_Position3dVertexCxformAcEAlphaInv:               return STI_Position3dVertexCxformAcEAlphaInv;
        case ST_BatchPosition3dVertexCxformAcEAlphaInv:          return STI_BatchPosition3dVertexCxformAcEAlphaInv;
        case ST_InstancedPosition3dVertexCxformAcEAlphaInv:      return STI_InstancedPosition3dVertexCxformAcEAlphaInv;
        case ST_TexTGTexTG:                                      return STI_TexTGTexTG;
        case ST_TexTGTexTGMul:                                   return STI_TexTGTexTGMul;
        case ST_BatchTexTGTexTG:                                 return STI_BatchTexTGTexTG;
        case ST_BatchTexTGTexTGMul:                              return STI_BatchTexTGTexTGMul;
        case ST_InstancedTexTGTexTG:                             return STI_InstancedTexTGTexTG;
        case ST_InstancedTexTGTexTGMul:                          return STI_InstancedTexTGTexTGMul;
        case ST_Position3dTexTGTexTG:                            return STI_Position3dTexTGTexTG;
        case ST_Position3dTexTGTexTGMul:                         return STI_Position3dTexTGTexTGMul;
        case ST_BatchPosition3dTexTGTexTG:                       return STI_BatchPosition3dTexTGTexTG;
        case ST_BatchPosition3dTexTGTexTGMul:                    return STI_BatchPosition3dTexTGTexTGMul;
        case ST_InstancedPosition3dTexTGTexTG:                   return STI_InstancedPosition3dTexTGTexTG;
        case ST_InstancedPosition3dTexTGTexTGMul:                return STI_InstancedPosition3dTexTGTexTGMul;
        case ST_TexTGTexTGCxform:                                return STI_TexTGTexTGCxform;
        case ST_TexTGTexTGCxformMul:                             return STI_TexTGTexTGCxformMul;
        case ST_BatchTexTGTexTGCxform:                           return STI_BatchTexTGTexTGCxform;
        case ST_BatchTexTGTexTGCxformMul:                        return STI_BatchTexTGTexTGCxformMul;
        case ST_InstancedTexTGTexTGCxform:                       return STI_InstancedTexTGTexTGCxform;
        case ST_InstancedTexTGTexTGCxformMul:                    return STI_InstancedTexTGTexTGCxformMul;
        case ST_Position3dTexTGTexTGCxform:                      return STI_Position3dTexTGTexTGCxform;
        case ST_Position3dTexTGTexTGCxformMul:                   return STI_Position3dTexTGTexTGCxformMul;
        case ST_BatchPosition3dTexTGTexTGCxform:                 return STI_BatchPosition3dTexTGTexTGCxform;
        case ST_BatchPosition3dTexTGTexTGCxformMul:              return STI_BatchPosition3dTexTGTexTGCxformMul;
        case ST_InstancedPosition3dTexTGTexTGCxform:             return STI_InstancedPosition3dTexTGTexTGCxform;
        case ST_InstancedPosition3dTexTGTexTGCxformMul:          return STI_InstancedPosition3dTexTGTexTGCxformMul;
        case ST_TexTGTexTGEAlpha:                                return STI_TexTGTexTGEAlpha;
        case ST_TexTGTexTGEAlphaMul:                             return STI_TexTGTexTGEAlphaMul;
        case ST_BatchTexTGTexTGEAlpha:                           return STI_BatchTexTGTexTGEAlpha;
        case ST_BatchTexTGTexTGEAlphaMul:                        return STI_BatchTexTGTexTGEAlphaMul;
        case ST_InstancedTexTGTexTGEAlpha:                       return STI_InstancedTexTGTexTGEAlpha;
        case ST_InstancedTexTGTexTGEAlphaMul:                    return STI_InstancedTexTGTexTGEAlphaMul;
        case ST_Position3dTexTGTexTGEAlpha:                      return STI_Position3dTexTGTexTGEAlpha;
        case ST_Position3dTexTGTexTGEAlphaMul:                   return STI_Position3dTexTGTexTGEAlphaMul;
        case ST_BatchPosition3dTexTGTexTGEAlpha:                 return STI_BatchPosition3dTexTGTexTGEAlpha;
        case ST_BatchPosition3dTexTGTexTGEAlphaMul:              return STI_BatchPosition3dTexTGTexTGEAlphaMul;
        case ST_InstancedPosition3dTexTGTexTGEAlpha:             return STI_InstancedPosition3dTexTGTexTGEAlpha;
        case ST_InstancedPosition3dTexTGTexTGEAlphaMul:          return STI_InstancedPosition3dTexTGTexTGEAlphaMul;
        case ST_TexTGTexTGCxformEAlpha:                          return STI_TexTGTexTGCxformEAlpha;
        case ST_TexTGTexTGCxformEAlphaMul:                       return STI_TexTGTexTGCxformEAlphaMul;
        case ST_BatchTexTGTexTGCxformEAlpha:                     return STI_BatchTexTGTexTGCxformEAlpha;
        case ST_BatchTexTGTexTGCxformEAlphaMul:                  return STI_BatchTexTGTexTGCxformEAlphaMul;
        case ST_InstancedTexTGTexTGCxformEAlpha:                 return STI_InstancedTexTGTexTGCxformEAlpha;
        case ST_InstancedTexTGTexTGCxformEAlphaMul:              return STI_InstancedTexTGTexTGCxformEAlphaMul;
        case ST_Position3dTexTGTexTGCxformEAlpha:                return STI_Position3dTexTGTexTGCxformEAlpha;
        case ST_Position3dTexTGTexTGCxformEAlphaMul:             return STI_Position3dTexTGTexTGCxformEAlphaMul;
        case ST_BatchPosition3dTexTGTexTGCxformEAlpha:           return STI_BatchPosition3dTexTGTexTGCxformEAlpha;
        case ST_BatchPosition3dTexTGTexTGCxformEAlphaMul:        return STI_BatchPosition3dTexTGTexTGCxformEAlphaMul;
        case ST_InstancedPosition3dTexTGTexTGCxformEAlpha:       return STI_InstancedPosition3dTexTGTexTGCxformEAlpha;
        case ST_InstancedPosition3dTexTGTexTGCxformEAlphaMul:    return STI_InstancedPosition3dTexTGTexTGCxformEAlphaMul;
        case ST_TexTGTexTGInv:                                   return STI_TexTGTexTGInv;
        case ST_BatchTexTGTexTGInv:                              return STI_BatchTexTGTexTGInv;
        case ST_InstancedTexTGTexTGInv:                          return STI_InstancedTexTGTexTGInv;
        case ST_Position3dTexTGTexTGInv:                         return STI_Position3dTexTGTexTGInv;
        case ST_BatchPosition3dTexTGTexTGInv:                    return STI_BatchPosition3dTexTGTexTGInv;
        case ST_InstancedPosition3dTexTGTexTGInv:                return STI_InstancedPosition3dTexTGTexTGInv;
        case ST_TexTGTexTGCxformInv:                             return STI_TexTGTexTGCxformInv;
        case ST_BatchTexTGTexTGCxformInv:                        return STI_BatchTexTGTexTGCxformInv;
        case ST_InstancedTexTGTexTGCxformInv:                    return STI_InstancedTexTGTexTGCxformInv;
        case ST_Position3dTexTGTexTGCxformInv:                   return STI_Position3dTexTGTexTGCxformInv;
        case ST_BatchPosition3dTexTGTexTGCxformInv:              return STI_BatchPosition3dTexTGTexTGCxformInv;
        case ST_InstancedPosition3dTexTGTexTGCxformInv:          return STI_InstancedPosition3dTexTGTexTGCxformInv;
        case ST_TexTGTexTGEAlphaInv:                             return STI_TexTGTexTGEAlphaInv;
        case ST_BatchTexTGTexTGEAlphaInv:                        return STI_BatchTexTGTexTGEAlphaInv;
        case ST_InstancedTexTGTexTGEAlphaInv:                    return STI_InstancedTexTGTexTGEAlphaInv;
        case ST_Position3dTexTGTexTGEAlphaInv:                   return STI_Position3dTexTGTexTGEAlphaInv;
        case ST_BatchPosition3dTexTGTexTGEAlphaInv:              return STI_BatchPosition3dTexTGTexTGEAlphaInv;
        case ST_InstancedPosition3dTexTGTexTGEAlphaInv:          return STI_InstancedPosition3dTexTGTexTGEAlphaInv;
        case ST_TexTGTexTGCxformEAlphaInv:                       return STI_TexTGTexTGCxformEAlphaInv;
        case ST_BatchTexTGTexTGCxformEAlphaInv:                  return STI_BatchTexTGTexTGCxformEAlphaInv;
        case ST_InstancedTexTGTexTGCxformEAlphaInv:              return STI_InstancedTexTGTexTGCxformEAlphaInv;
        case ST_Position3dTexTGTexTGCxformEAlphaInv:             return STI_Position3dTexTGTexTGCxformEAlphaInv;
        case ST_BatchPosition3dTexTGTexTGCxformEAlphaInv:        return STI_BatchPosition3dTexTGTexTGCxformEAlphaInv;
        case ST_InstancedPosition3dTexTGTexTGCxformEAlphaInv:    return STI_InstancedPosition3dTexTGTexTGCxformEAlphaInv;
        case ST_TexTGTexTGCxformAc:                              return STI_TexTGTexTGCxformAc;
        case ST_TexTGTexTGCxformAcMul:                           return STI_TexTGTexTGCxformAcMul;
        case ST_BatchTexTGTexTGCxformAc:                         return STI_BatchTexTGTexTGCxformAc;
        case ST_BatchTexTGTexTGCxformAcMul:                      return STI_BatchTexTGTexTGCxformAcMul;
        case ST_InstancedTexTGTexTGCxformAc:                     return STI_InstancedTexTGTexTGCxformAc;
        case ST_InstancedTexTGTexTGCxformAcMul:                  return STI_InstancedTexTGTexTGCxformAcMul;
        case ST_Position3dTexTGTexTGCxformAc:                    return STI_Position3dTexTGTexTGCxformAc;
        case ST_Position3dTexTGTexTGCxformAcMul:                 return STI_Position3dTexTGTexTGCxformAcMul;
        case ST_BatchPosition3dTexTGTexTGCxformAc:               return STI_BatchPosition3dTexTGTexTGCxformAc;
        case ST_BatchPosition3dTexTGTexTGCxformAcMul:            return STI_BatchPosition3dTexTGTexTGCxformAcMul;
        case ST_InstancedPosition3dTexTGTexTGCxformAc:           return STI_InstancedPosition3dTexTGTexTGCxformAc;
        case ST_InstancedPosition3dTexTGTexTGCxformAcMul:        return STI_InstancedPosition3dTexTGTexTGCxformAcMul;
        case ST_TexTGTexTGCxformAcEAlpha:                        return STI_TexTGTexTGCxformAcEAlpha;
        case ST_TexTGTexTGCxformAcEAlphaMul:                     return STI_TexTGTexTGCxformAcEAlphaMul;
        case ST_BatchTexTGTexTGCxformAcEAlpha:                   return STI_BatchTexTGTexTGCxformAcEAlpha;
        case ST_BatchTexTGTexTGCxformAcEAlphaMul:                return STI_BatchTexTGTexTGCxformAcEAlphaMul;
        case ST_InstancedTexTGTexTGCxformAcEAlpha:               return STI_InstancedTexTGTexTGCxformAcEAlpha;
        case ST_InstancedTexTGTexTGCxformAcEAlphaMul:            return STI_InstancedTexTGTexTGCxformAcEAlphaMul;
        case ST_Position3dTexTGTexTGCxformAcEAlpha:              return STI_Position3dTexTGTexTGCxformAcEAlpha;
        case ST_Position3dTexTGTexTGCxformAcEAlphaMul:           return STI_Position3dTexTGTexTGCxformAcEAlphaMul;
        case ST_BatchPosition3dTexTGTexTGCxformAcEAlpha:         return STI_BatchPosition3dTexTGTexTGCxformAcEAlpha;
        case ST_BatchPosition3dTexTGTexTGCxformAcEAlphaMul:      return STI_BatchPosition3dTexTGTexTGCxformAcEAlphaMul;
        case ST_InstancedPosition3dTexTGTexTGCxformAcEAlpha:     return STI_InstancedPosition3dTexTGTexTGCxformAcEAlpha;
        case ST_InstancedPosition3dTexTGTexTGCxformAcEAlphaMul:  return STI_InstancedPosition3dTexTGTexTGCxformAcEAlphaMul;
        case ST_TexTGTexTGCxformAcInv:                           return STI_TexTGTexTGCxformAcInv;
        case ST_BatchTexTGTexTGCxformAcInv:                      return STI_BatchTexTGTexTGCxformAcInv;
        case ST_InstancedTexTGTexTGCxformAcInv:                  return STI_InstancedTexTGTexTGCxformAcInv;
        case ST_Position3dTexTGTexTGCxformAcInv:                 return STI_Position3dTexTGTexTGCxformAcInv;
        case ST_BatchPosition3dTexTGTexTGCxformAcInv:            return STI_BatchPosition3dTexTGTexTGCxformAcInv;
        case ST_InstancedPosition3dTexTGTexTGCxformAcInv:        return STI_InstancedPosition3dTexTGTexTGCxformAcInv;
        case ST_TexTGTexTGCxformAcEAlphaInv:                     return STI_TexTGTexTGCxformAcEAlphaInv;
        case ST_BatchTexTGTexTGCxformAcEAlphaInv:                return STI_BatchTexTGTexTGCxformAcEAlphaInv;
        case ST_InstancedTexTGTexTGCxformAcEAlphaInv:            return STI_InstancedTexTGTexTGCxformAcEAlphaInv;
        case ST_Position3dTexTGTexTGCxformAcEAlphaInv:           return STI_Position3dTexTGTexTGCxformAcEAlphaInv;
        case ST_BatchPosition3dTexTGTexTGCxformAcEAlphaInv:      return STI_BatchPosition3dTexTGTexTGCxformAcEAlphaInv;
        case ST_InstancedPosition3dTexTGTexTGCxformAcEAlphaInv:  return STI_InstancedPosition3dTexTGTexTGCxformAcEAlphaInv;
        case ST_TexTGVertex:                                     return STI_TexTGVertex;
        case ST_TexTGVertexMul:                                  return STI_TexTGVertexMul;
        case ST_BatchTexTGVertex:                                return STI_BatchTexTGVertex;
        case ST_BatchTexTGVertexMul:                             return STI_BatchTexTGVertexMul;
        case ST_InstancedTexTGVertex:                            return STI_InstancedTexTGVertex;
        case ST_InstancedTexTGVertexMul:                         return STI_InstancedTexTGVertexMul;
        case ST_Position3dTexTGVertex:                           return STI_Position3dTexTGVertex;
        case ST_Position3dTexTGVertexMul:                        return STI_Position3dTexTGVertexMul;
        case ST_BatchPosition3dTexTGVertex:                      return STI_BatchPosition3dTexTGVertex;
        case ST_BatchPosition3dTexTGVertexMul:                   return STI_BatchPosition3dTexTGVertexMul;
        case ST_InstancedPosition3dTexTGVertex:                  return STI_InstancedPosition3dTexTGVertex;
        case ST_InstancedPosition3dTexTGVertexMul:               return STI_InstancedPosition3dTexTGVertexMul;
        case ST_TexTGVertexCxform:                               return STI_TexTGVertexCxform;
        case ST_TexTGVertexCxformMul:                            return STI_TexTGVertexCxformMul;
        case ST_BatchTexTGVertexCxform:                          return STI_BatchTexTGVertexCxform;
        case ST_BatchTexTGVertexCxformMul:                       return STI_BatchTexTGVertexCxformMul;
        case ST_InstancedTexTGVertexCxform:                      return STI_InstancedTexTGVertexCxform;
        case ST_InstancedTexTGVertexCxformMul:                   return STI_InstancedTexTGVertexCxformMul;
        case ST_Position3dTexTGVertexCxform:                     return STI_Position3dTexTGVertexCxform;
        case ST_Position3dTexTGVertexCxformMul:                  return STI_Position3dTexTGVertexCxformMul;
        case ST_BatchPosition3dTexTGVertexCxform:                return STI_BatchPosition3dTexTGVertexCxform;
        case ST_BatchPosition3dTexTGVertexCxformMul:             return STI_BatchPosition3dTexTGVertexCxformMul;
        case ST_InstancedPosition3dTexTGVertexCxform:            return STI_InstancedPosition3dTexTGVertexCxform;
        case ST_InstancedPosition3dTexTGVertexCxformMul:         return STI_InstancedPosition3dTexTGVertexCxformMul;
        case ST_TexTGVertexEAlpha:                               return STI_TexTGVertexEAlpha;
        case ST_TexTGVertexEAlphaMul:                            return STI_TexTGVertexEAlphaMul;
        case ST_BatchTexTGVertexEAlpha:                          return STI_BatchTexTGVertexEAlpha;
        case ST_BatchTexTGVertexEAlphaMul:                       return STI_BatchTexTGVertexEAlphaMul;
        case ST_InstancedTexTGVertexEAlpha:                      return STI_InstancedTexTGVertexEAlpha;
        case ST_InstancedTexTGVertexEAlphaMul:                   return STI_InstancedTexTGVertexEAlphaMul;
        case ST_Position3dTexTGVertexEAlpha:                     return STI_Position3dTexTGVertexEAlpha;
        case ST_Position3dTexTGVertexEAlphaMul:                  return STI_Position3dTexTGVertexEAlphaMul;
        case ST_BatchPosition3dTexTGVertexEAlpha:                return STI_BatchPosition3dTexTGVertexEAlpha;
        case ST_BatchPosition3dTexTGVertexEAlphaMul:             return STI_BatchPosition3dTexTGVertexEAlphaMul;
        case ST_InstancedPosition3dTexTGVertexEAlpha:            return STI_InstancedPosition3dTexTGVertexEAlpha;
        case ST_InstancedPosition3dTexTGVertexEAlphaMul:         return STI_InstancedPosition3dTexTGVertexEAlphaMul;
        case ST_TexTGVertexCxformEAlpha:                         return STI_TexTGVertexCxformEAlpha;
        case ST_TexTGVertexCxformEAlphaMul:                      return STI_TexTGVertexCxformEAlphaMul;
        case ST_BatchTexTGVertexCxformEAlpha:                    return STI_BatchTexTGVertexCxformEAlpha;
        case ST_BatchTexTGVertexCxformEAlphaMul:                 return STI_BatchTexTGVertexCxformEAlphaMul;
        case ST_InstancedTexTGVertexCxformEAlpha:                return STI_InstancedTexTGVertexCxformEAlpha;
        case ST_InstancedTexTGVertexCxformEAlphaMul:             return STI_InstancedTexTGVertexCxformEAlphaMul;
        case ST_Position3dTexTGVertexCxformEAlpha:               return STI_Position3dTexTGVertexCxformEAlpha;
        case ST_Position3dTexTGVertexCxformEAlphaMul:            return STI_Position3dTexTGVertexCxformEAlphaMul;
        case ST_BatchPosition3dTexTGVertexCxformEAlpha:          return STI_BatchPosition3dTexTGVertexCxformEAlpha;
        case ST_BatchPosition3dTexTGVertexCxformEAlphaMul:       return STI_BatchPosition3dTexTGVertexCxformEAlphaMul;
        case ST_InstancedPosition3dTexTGVertexCxformEAlpha:      return STI_InstancedPosition3dTexTGVertexCxformEAlpha;
        case ST_InstancedPosition3dTexTGVertexCxformEAlphaMul:   return STI_InstancedPosition3dTexTGVertexCxformEAlphaMul;
        case ST_TexTGVertexInv:                                  return STI_TexTGVertexInv;
        case ST_BatchTexTGVertexInv:                             return STI_BatchTexTGVertexInv;
        case ST_InstancedTexTGVertexInv:                         return STI_InstancedTexTGVertexInv;
        case ST_Position3dTexTGVertexInv:                        return STI_Position3dTexTGVertexInv;
        case ST_BatchPosition3dTexTGVertexInv:                   return STI_BatchPosition3dTexTGVertexInv;
        case ST_InstancedPosition3dTexTGVertexInv:               return STI_InstancedPosition3dTexTGVertexInv;
        case ST_TexTGVertexCxformInv:                            return STI_TexTGVertexCxformInv;
        case ST_BatchTexTGVertexCxformInv:                       return STI_BatchTexTGVertexCxformInv;
        case ST_InstancedTexTGVertexCxformInv:                   return STI_InstancedTexTGVertexCxformInv;
        case ST_Position3dTexTGVertexCxformInv:                  return STI_Position3dTexTGVertexCxformInv;
        case ST_BatchPosition3dTexTGVertexCxformInv:             return STI_BatchPosition3dTexTGVertexCxformInv;
        case ST_InstancedPosition3dTexTGVertexCxformInv:         return STI_InstancedPosition3dTexTGVertexCxformInv;
        case ST_TexTGVertexEAlphaInv:                            return STI_TexTGVertexEAlphaInv;
        case ST_BatchTexTGVertexEAlphaInv:                       return STI_BatchTexTGVertexEAlphaInv;
        case ST_InstancedTexTGVertexEAlphaInv:                   return STI_InstancedTexTGVertexEAlphaInv;
        case ST_Position3dTexTGVertexEAlphaInv:                  return STI_Position3dTexTGVertexEAlphaInv;
        case ST_BatchPosition3dTexTGVertexEAlphaInv:             return STI_BatchPosition3dTexTGVertexEAlphaInv;
        case ST_InstancedPosition3dTexTGVertexEAlphaInv:         return STI_InstancedPosition3dTexTGVertexEAlphaInv;
        case ST_TexTGVertexCxformEAlphaInv:                      return STI_TexTGVertexCxformEAlphaInv;
        case ST_BatchTexTGVertexCxformEAlphaInv:                 return STI_BatchTexTGVertexCxformEAlphaInv;
        case ST_InstancedTexTGVertexCxformEAlphaInv:             return STI_InstancedTexTGVertexCxformEAlphaInv;
        case ST_Position3dTexTGVertexCxformEAlphaInv:            return STI_Position3dTexTGVertexCxformEAlphaInv;
        case ST_BatchPosition3dTexTGVertexCxformEAlphaInv:       return STI_BatchPosition3dTexTGVertexCxformEAlphaInv;
        case ST_InstancedPosition3dTexTGVertexCxformEAlphaInv:   return STI_InstancedPosition3dTexTGVertexCxformEAlphaInv;
        case ST_TexTGVertexCxformAc:                             return STI_TexTGVertexCxformAc;
        case ST_TexTGVertexCxformAcMul:                          return STI_TexTGVertexCxformAcMul;
        case ST_BatchTexTGVertexCxformAc:                        return STI_BatchTexTGVertexCxformAc;
        case ST_BatchTexTGVertexCxformAcMul:                     return STI_BatchTexTGVertexCxformAcMul;
        case ST_InstancedTexTGVertexCxformAc:                    return STI_InstancedTexTGVertexCxformAc;
        case ST_InstancedTexTGVertexCxformAcMul:                 return STI_InstancedTexTGVertexCxformAcMul;
        case ST_Position3dTexTGVertexCxformAc:                   return STI_Position3dTexTGVertexCxformAc;
        case ST_Position3dTexTGVertexCxformAcMul:                return STI_Position3dTexTGVertexCxformAcMul;
        case ST_BatchPosition3dTexTGVertexCxformAc:              return STI_BatchPosition3dTexTGVertexCxformAc;
        case ST_BatchPosition3dTexTGVertexCxformAcMul:           return STI_BatchPosition3dTexTGVertexCxformAcMul;
        case ST_InstancedPosition3dTexTGVertexCxformAc:          return STI_InstancedPosition3dTexTGVertexCxformAc;
        case ST_InstancedPosition3dTexTGVertexCxformAcMul:       return STI_InstancedPosition3dTexTGVertexCxformAcMul;
        case ST_TexTGVertexCxformAcEAlpha:                       return STI_TexTGVertexCxformAcEAlpha;
        case ST_TexTGVertexCxformAcEAlphaMul:                    return STI_TexTGVertexCxformAcEAlphaMul;
        case ST_BatchTexTGVertexCxformAcEAlpha:                  return STI_BatchTexTGVertexCxformAcEAlpha;
        case ST_BatchTexTGVertexCxformAcEAlphaMul:               return STI_BatchTexTGVertexCxformAcEAlphaMul;
        case ST_InstancedTexTGVertexCxformAcEAlpha:              return STI_InstancedTexTGVertexCxformAcEAlpha;
        case ST_InstancedTexTGVertexCxformAcEAlphaMul:           return STI_InstancedTexTGVertexCxformAcEAlphaMul;
        case ST_Position3dTexTGVertexCxformAcEAlpha:             return STI_Position3dTexTGVertexCxformAcEAlpha;
        case ST_Position3dTexTGVertexCxformAcEAlphaMul:          return STI_Position3dTexTGVertexCxformAcEAlphaMul;
        case ST_BatchPosition3dTexTGVertexCxformAcEAlpha:        return STI_BatchPosition3dTexTGVertexCxformAcEAlpha;
        case ST_BatchPosition3dTexTGVertexCxformAcEAlphaMul:     return STI_BatchPosition3dTexTGVertexCxformAcEAlphaMul;
        case ST_InstancedPosition3dTexTGVertexCxformAcEAlpha:    return STI_InstancedPosition3dTexTGVertexCxformAcEAlpha;
        case ST_InstancedPosition3dTexTGVertexCxformAcEAlphaMul: return STI_InstancedPosition3dTexTGVertexCxformAcEAlphaMul;
        case ST_TexTGVertexCxformAcInv:                          return STI_TexTGVertexCxformAcInv;
        case ST_BatchTexTGVertexCxformAcInv:                     return STI_BatchTexTGVertexCxformAcInv;
        case ST_InstancedTexTGVertexCxformAcInv:                 return STI_InstancedTexTGVertexCxformAcInv;
        case ST_Position3dTexTGVertexCxformAcInv:                return STI_Position3dTexTGVertexCxformAcInv;
        case ST_BatchPosition3dTexTGVertexCxformAcInv:           return STI_BatchPosition3dTexTGVertexCxformAcInv;
        case ST_InstancedPosition3dTexTGVertexCxformAcInv:       return STI_InstancedPosition3dTexTGVertexCxformAcInv;
        case ST_TexTGVertexCxformAcEAlphaInv:                    return STI_TexTGVertexCxformAcEAlphaInv;
        case ST_BatchTexTGVertexCxformAcEAlphaInv:               return STI_BatchTexTGVertexCxformAcEAlphaInv;
        case ST_InstancedTexTGVertexCxformAcEAlphaInv:           return STI_InstancedTexTGVertexCxformAcEAlphaInv;
        case ST_Position3dTexTGVertexCxformAcEAlphaInv:          return STI_Position3dTexTGVertexCxformAcEAlphaInv;
        case ST_BatchPosition3dTexTGVertexCxformAcEAlphaInv:     return STI_BatchPosition3dTexTGVertexCxformAcEAlphaInv;
        case ST_InstancedPosition3dTexTGVertexCxformAcEAlphaInv: return STI_InstancedPosition3dTexTGVertexCxformAcEAlphaInv;
        case ST_Solid:                                           return STI_Solid;
        case ST_SolidMul:                                        return STI_SolidMul;
        case ST_BatchSolid:                                      return STI_BatchSolid;
        case ST_BatchSolidMul:                                   return STI_BatchSolidMul;
        case ST_InstancedSolid:                                  return STI_InstancedSolid;
        case ST_InstancedSolidMul:                               return STI_InstancedSolidMul;
        case ST_Position3dSolid:                                 return STI_Position3dSolid;
        case ST_Position3dSolidMul:                              return STI_Position3dSolidMul;
        case ST_BatchPosition3dSolid:                            return STI_BatchPosition3dSolid;
        case ST_BatchPosition3dSolidMul:                         return STI_BatchPosition3dSolidMul;
        case ST_InstancedPosition3dSolid:                        return STI_InstancedPosition3dSolid;
        case ST_InstancedPosition3dSolidMul:                     return STI_InstancedPosition3dSolidMul;
        case ST_SolidInv:                                        return STI_SolidInv;
        case ST_BatchSolidInv:                                   return STI_BatchSolidInv;
        case ST_InstancedSolidInv:                               return STI_InstancedSolidInv;
        case ST_Position3dSolidInv:                              return STI_Position3dSolidInv;
        case ST_BatchPosition3dSolidInv:                         return STI_BatchPosition3dSolidInv;
        case ST_InstancedPosition3dSolidInv:                     return STI_InstancedPosition3dSolidInv;
        case ST_Text:                                            return STI_Text;
        case ST_TextMul:                                         return STI_TextMul;
        case ST_BatchText:                                       return STI_BatchText;
        case ST_BatchTextMul:                                    return STI_BatchTextMul;
        case ST_InstancedText:                                   return STI_InstancedText;
        case ST_InstancedTextMul:                                return STI_InstancedTextMul;
        case ST_Position3dText:                                  return STI_Position3dText;
        case ST_Position3dTextMul:                               return STI_Position3dTextMul;
        case ST_BatchPosition3dText:                             return STI_BatchPosition3dText;
        case ST_BatchPosition3dTextMul:                          return STI_BatchPosition3dTextMul;
        case ST_InstancedPosition3dText:                         return STI_InstancedPosition3dText;
        case ST_InstancedPosition3dTextMul:                      return STI_InstancedPosition3dTextMul;
        case ST_TextInv:                                         return STI_TextInv;
        case ST_BatchTextInv:                                    return STI_BatchTextInv;
        case ST_InstancedTextInv:                                return STI_InstancedTextInv;
        case ST_Position3dTextInv:                               return STI_Position3dTextInv;
        case ST_BatchPosition3dTextInv:                          return STI_BatchPosition3dTextInv;
        case ST_InstancedPosition3dTextInv:                      return STI_InstancedPosition3dTextInv;
        case ST_TextColor:                                       return STI_TextColor;
        case ST_TextColorMul:                                    return STI_TextColorMul;
        case ST_BatchTextColor:                                  return STI_BatchTextColor;
        case ST_BatchTextColorMul:                               return STI_BatchTextColorMul;
        case ST_InstancedTextColor:                              return STI_InstancedTextColor;
        case ST_InstancedTextColorMul:                           return STI_InstancedTextColorMul;
        case ST_Position3dTextColor:                             return STI_Position3dTextColor;
        case ST_Position3dTextColorMul:                          return STI_Position3dTextColorMul;
        case ST_BatchPosition3dTextColor:                        return STI_BatchPosition3dTextColor;
        case ST_BatchPosition3dTextColorMul:                     return STI_BatchPosition3dTextColorMul;
        case ST_InstancedPosition3dTextColor:                    return STI_InstancedPosition3dTextColor;
        case ST_InstancedPosition3dTextColorMul:                 return STI_InstancedPosition3dTextColorMul;
        case ST_TextColorCxform:                                 return STI_TextColorCxform;
        case ST_TextColorCxformMul:                              return STI_TextColorCxformMul;
        case ST_BatchTextColorCxform:                            return STI_BatchTextColorCxform;
        case ST_BatchTextColorCxformMul:                         return STI_BatchTextColorCxformMul;
        case ST_InstancedTextColorCxform:                        return STI_InstancedTextColorCxform;
        case ST_InstancedTextColorCxformMul:                     return STI_InstancedTextColorCxformMul;
        case ST_Position3dTextColorCxform:                       return STI_Position3dTextColorCxform;
        case ST_Position3dTextColorCxformMul:                    return STI_Position3dTextColorCxformMul;
        case ST_BatchPosition3dTextColorCxform:                  return STI_BatchPosition3dTextColorCxform;
        case ST_BatchPosition3dTextColorCxformMul:               return STI_BatchPosition3dTextColorCxformMul;
        case ST_InstancedPosition3dTextColorCxform:              return STI_InstancedPosition3dTextColorCxform;
        case ST_InstancedPosition3dTextColorCxformMul:           return STI_InstancedPosition3dTextColorCxformMul;
        case ST_TextColorInv:                                    return STI_TextColorInv;
        case ST_BatchTextColorInv:                               return STI_BatchTextColorInv;
        case ST_InstancedTextColorInv:                           return STI_InstancedTextColorInv;
        case ST_Position3dTextColorInv:                          return STI_Position3dTextColorInv;
        case ST_BatchPosition3dTextColorInv:                     return STI_BatchPosition3dTextColorInv;
        case ST_InstancedPosition3dTextColorInv:                 return STI_InstancedPosition3dTextColorInv;
        case ST_TextColorCxformInv:                              return STI_TextColorCxformInv;
        case ST_BatchTextColorCxformInv:                         return STI_BatchTextColorCxformInv;
        case ST_InstancedTextColorCxformInv:                     return STI_InstancedTextColorCxformInv;
        case ST_Position3dTextColorCxformInv:                    return STI_Position3dTextColorCxformInv;
        case ST_BatchPosition3dTextColorCxformInv:               return STI_BatchPosition3dTextColorCxformInv;
        case ST_InstancedPosition3dTextColorCxformInv:           return STI_InstancedPosition3dTextColorCxformInv;
        case ST_YUV:                                             return STI_YUV;
        case ST_YUVMul:                                          return STI_YUVMul;
        case ST_BatchYUV:                                        return STI_BatchYUV;
        case ST_BatchYUVMul:                                     return STI_BatchYUVMul;
        case ST_InstancedYUV:                                    return STI_InstancedYUV;
        case ST_InstancedYUVMul:                                 return STI_InstancedYUVMul;
        case ST_Position3dYUV:                                   return STI_Position3dYUV;
        case ST_Position3dYUVMul:                                return STI_Position3dYUVMul;
        case ST_BatchPosition3dYUV:                              return STI_BatchPosition3dYUV;
        case ST_BatchPosition3dYUVMul:                           return STI_BatchPosition3dYUVMul;
        case ST_InstancedPosition3dYUV:                          return STI_InstancedPosition3dYUV;
        case ST_InstancedPosition3dYUVMul:                       return STI_InstancedPosition3dYUVMul;
        case ST_YUVCxform:                                       return STI_YUVCxform;
        case ST_YUVCxformMul:                                    return STI_YUVCxformMul;
        case ST_BatchYUVCxform:                                  return STI_BatchYUVCxform;
        case ST_BatchYUVCxformMul:                               return STI_BatchYUVCxformMul;
        case ST_InstancedYUVCxform:                              return STI_InstancedYUVCxform;
        case ST_InstancedYUVCxformMul:                           return STI_InstancedYUVCxformMul;
        case ST_Position3dYUVCxform:                             return STI_Position3dYUVCxform;
        case ST_Position3dYUVCxformMul:                          return STI_Position3dYUVCxformMul;
        case ST_BatchPosition3dYUVCxform:                        return STI_BatchPosition3dYUVCxform;
        case ST_BatchPosition3dYUVCxformMul:                     return STI_BatchPosition3dYUVCxformMul;
        case ST_InstancedPosition3dYUVCxform:                    return STI_InstancedPosition3dYUVCxform;
        case ST_InstancedPosition3dYUVCxformMul:                 return STI_InstancedPosition3dYUVCxformMul;
        case ST_YUVEAlpha:                                       return STI_YUVEAlpha;
        case ST_YUVEAlphaMul:                                    return STI_YUVEAlphaMul;
        case ST_BatchYUVEAlpha:                                  return STI_BatchYUVEAlpha;
        case ST_BatchYUVEAlphaMul:                               return STI_BatchYUVEAlphaMul;
        case ST_InstancedYUVEAlpha:                              return STI_InstancedYUVEAlpha;
        case ST_InstancedYUVEAlphaMul:                           return STI_InstancedYUVEAlphaMul;
        case ST_Position3dYUVEAlpha:                             return STI_Position3dYUVEAlpha;
        case ST_Position3dYUVEAlphaMul:                          return STI_Position3dYUVEAlphaMul;
        case ST_BatchPosition3dYUVEAlpha:                        return STI_BatchPosition3dYUVEAlpha;
        case ST_BatchPosition3dYUVEAlphaMul:                     return STI_BatchPosition3dYUVEAlphaMul;
        case ST_InstancedPosition3dYUVEAlpha:                    return STI_InstancedPosition3dYUVEAlpha;
        case ST_InstancedPosition3dYUVEAlphaMul:                 return STI_InstancedPosition3dYUVEAlphaMul;
        case ST_YUVCxformEAlpha:                                 return STI_YUVCxformEAlpha;
        case ST_YUVCxformEAlphaMul:                              return STI_YUVCxformEAlphaMul;
        case ST_BatchYUVCxformEAlpha:                            return STI_BatchYUVCxformEAlpha;
        case ST_BatchYUVCxformEAlphaMul:                         return STI_BatchYUVCxformEAlphaMul;
        case ST_InstancedYUVCxformEAlpha:                        return STI_InstancedYUVCxformEAlpha;
        case ST_InstancedYUVCxformEAlphaMul:                     return STI_InstancedYUVCxformEAlphaMul;
        case ST_Position3dYUVCxformEAlpha:                       return STI_Position3dYUVCxformEAlpha;
        case ST_Position3dYUVCxformEAlphaMul:                    return STI_Position3dYUVCxformEAlphaMul;
        case ST_BatchPosition3dYUVCxformEAlpha:                  return STI_BatchPosition3dYUVCxformEAlpha;
        case ST_BatchPosition3dYUVCxformEAlphaMul:               return STI_BatchPosition3dYUVCxformEAlphaMul;
        case ST_InstancedPosition3dYUVCxformEAlpha:              return STI_InstancedPosition3dYUVCxformEAlpha;
        case ST_InstancedPosition3dYUVCxformEAlphaMul:           return STI_InstancedPosition3dYUVCxformEAlphaMul;
        case ST_YUVCxformAc:                                     return STI_YUVCxformAc;
        case ST_YUVCxformAcMul:                                  return STI_YUVCxformAcMul;
        case ST_BatchYUVCxformAc:                                return STI_BatchYUVCxformAc;
        case ST_BatchYUVCxformAcMul:                             return STI_BatchYUVCxformAcMul;
        case ST_InstancedYUVCxformAc:                            return STI_InstancedYUVCxformAc;
        case ST_InstancedYUVCxformAcMul:                         return STI_InstancedYUVCxformAcMul;
        case ST_Position3dYUVCxformAc:                           return STI_Position3dYUVCxformAc;
        case ST_Position3dYUVCxformAcMul:                        return STI_Position3dYUVCxformAcMul;
        case ST_BatchPosition3dYUVCxformAc:                      return STI_BatchPosition3dYUVCxformAc;
        case ST_BatchPosition3dYUVCxformAcMul:                   return STI_BatchPosition3dYUVCxformAcMul;
        case ST_InstancedPosition3dYUVCxformAc:                  return STI_InstancedPosition3dYUVCxformAc;
        case ST_InstancedPosition3dYUVCxformAcMul:               return STI_InstancedPosition3dYUVCxformAcMul;
        case ST_YUVCxformAcEAlpha:                               return STI_YUVCxformAcEAlpha;
        case ST_YUVCxformAcEAlphaMul:                            return STI_YUVCxformAcEAlphaMul;
        case ST_BatchYUVCxformAcEAlpha:                          return STI_BatchYUVCxformAcEAlpha;
        case ST_BatchYUVCxformAcEAlphaMul:                       return STI_BatchYUVCxformAcEAlphaMul;
        case ST_InstancedYUVCxformAcEAlpha:                      return STI_InstancedYUVCxformAcEAlpha;
        case ST_InstancedYUVCxformAcEAlphaMul:                   return STI_InstancedYUVCxformAcEAlphaMul;
        case ST_Position3dYUVCxformAcEAlpha:                     return STI_Position3dYUVCxformAcEAlpha;
        case ST_Position3dYUVCxformAcEAlphaMul:                  return STI_Position3dYUVCxformAcEAlphaMul;
        case ST_BatchPosition3dYUVCxformAcEAlpha:                return STI_BatchPosition3dYUVCxformAcEAlpha;
        case ST_BatchPosition3dYUVCxformAcEAlphaMul:             return STI_BatchPosition3dYUVCxformAcEAlphaMul;
        case ST_InstancedPosition3dYUVCxformAcEAlpha:            return STI_InstancedPosition3dYUVCxformAcEAlpha;
        case ST_InstancedPosition3dYUVCxformAcEAlphaMul:         return STI_InstancedPosition3dYUVCxformAcEAlphaMul;
        case ST_YUVA:                                            return STI_YUVA;
        case ST_YUVAMul:                                         return STI_YUVAMul;
        case ST_BatchYUVA:                                       return STI_BatchYUVA;
        case ST_BatchYUVAMul:                                    return STI_BatchYUVAMul;
        case ST_InstancedYUVA:                                   return STI_InstancedYUVA;
        case ST_InstancedYUVAMul:                                return STI_InstancedYUVAMul;
        case ST_Position3dYUVA:                                  return STI_Position3dYUVA;
        case ST_Position3dYUVAMul:                               return STI_Position3dYUVAMul;
        case ST_BatchPosition3dYUVA:                             return STI_BatchPosition3dYUVA;
        case ST_BatchPosition3dYUVAMul:                          return STI_BatchPosition3dYUVAMul;
        case ST_InstancedPosition3dYUVA:                         return STI_InstancedPosition3dYUVA;
        case ST_InstancedPosition3dYUVAMul:                      return STI_InstancedPosition3dYUVAMul;
        case ST_YUVACxform:                                      return STI_YUVACxform;
        case ST_YUVACxformMul:                                   return STI_YUVACxformMul;
        case ST_BatchYUVACxform:                                 return STI_BatchYUVACxform;
        case ST_BatchYUVACxformMul:                              return STI_BatchYUVACxformMul;
        case ST_InstancedYUVACxform:                             return STI_InstancedYUVACxform;
        case ST_InstancedYUVACxformMul:                          return STI_InstancedYUVACxformMul;
        case ST_Position3dYUVACxform:                            return STI_Position3dYUVACxform;
        case ST_Position3dYUVACxformMul:                         return STI_Position3dYUVACxformMul;
        case ST_BatchPosition3dYUVACxform:                       return STI_BatchPosition3dYUVACxform;
        case ST_BatchPosition3dYUVACxformMul:                    return STI_BatchPosition3dYUVACxformMul;
        case ST_InstancedPosition3dYUVACxform:                   return STI_InstancedPosition3dYUVACxform;
        case ST_InstancedPosition3dYUVACxformMul:                return STI_InstancedPosition3dYUVACxformMul;
        case ST_YUVAEAlpha:                                      return STI_YUVAEAlpha;
        case ST_YUVAEAlphaMul:                                   return STI_YUVAEAlphaMul;
        case ST_BatchYUVAEAlpha:                                 return STI_BatchYUVAEAlpha;
        case ST_BatchYUVAEAlphaMul:                              return STI_BatchYUVAEAlphaMul;
        case ST_InstancedYUVAEAlpha:                             return STI_InstancedYUVAEAlpha;
        case ST_InstancedYUVAEAlphaMul:                          return STI_InstancedYUVAEAlphaMul;
        case ST_Position3dYUVAEAlpha:                            return STI_Position3dYUVAEAlpha;
        case ST_Position3dYUVAEAlphaMul:                         return STI_Position3dYUVAEAlphaMul;
        case ST_BatchPosition3dYUVAEAlpha:                       return STI_BatchPosition3dYUVAEAlpha;
        case ST_BatchPosition3dYUVAEAlphaMul:                    return STI_BatchPosition3dYUVAEAlphaMul;
        case ST_InstancedPosition3dYUVAEAlpha:                   return STI_InstancedPosition3dYUVAEAlpha;
        case ST_InstancedPosition3dYUVAEAlphaMul:                return STI_InstancedPosition3dYUVAEAlphaMul;
        case ST_YUVACxformEAlpha:                                return STI_YUVACxformEAlpha;
        case ST_YUVACxformEAlphaMul:                             return STI_YUVACxformEAlphaMul;
        case ST_BatchYUVACxformEAlpha:                           return STI_BatchYUVACxformEAlpha;
        case ST_BatchYUVACxformEAlphaMul:                        return STI_BatchYUVACxformEAlphaMul;
        case ST_InstancedYUVACxformEAlpha:                       return STI_InstancedYUVACxformEAlpha;
        case ST_InstancedYUVACxformEAlphaMul:                    return STI_InstancedYUVACxformEAlphaMul;
        case ST_Position3dYUVACxformEAlpha:                      return STI_Position3dYUVACxformEAlpha;
        case ST_Position3dYUVACxformEAlphaMul:                   return STI_Position3dYUVACxformEAlphaMul;
        case ST_BatchPosition3dYUVACxformEAlpha:                 return STI_BatchPosition3dYUVACxformEAlpha;
        case ST_BatchPosition3dYUVACxformEAlphaMul:              return STI_BatchPosition3dYUVACxformEAlphaMul;
        case ST_InstancedPosition3dYUVACxformEAlpha:             return STI_InstancedPosition3dYUVACxformEAlpha;
        case ST_InstancedPosition3dYUVACxformEAlphaMul:          return STI_InstancedPosition3dYUVACxformEAlphaMul;
        case ST_YUVAInv:                                         return STI_YUVAInv;
        case ST_BatchYUVAInv:                                    return STI_BatchYUVAInv;
        case ST_InstancedYUVAInv:                                return STI_InstancedYUVAInv;
        case ST_Position3dYUVAInv:                               return STI_Position3dYUVAInv;
        case ST_BatchPosition3dYUVAInv:                          return STI_BatchPosition3dYUVAInv;
        case ST_InstancedPosition3dYUVAInv:                      return STI_InstancedPosition3dYUVAInv;
        case ST_YUVACxformInv:                                   return STI_YUVACxformInv;
        case ST_BatchYUVACxformInv:                              return STI_BatchYUVACxformInv;
        case ST_InstancedYUVACxformInv:                          return STI_InstancedYUVACxformInv;
        case ST_Position3dYUVACxformInv:                         return STI_Position3dYUVACxformInv;
        case ST_BatchPosition3dYUVACxformInv:                    return STI_BatchPosition3dYUVACxformInv;
        case ST_InstancedPosition3dYUVACxformInv:                return STI_InstancedPosition3dYUVACxformInv;
        case ST_YUVAEAlphaInv:                                   return STI_YUVAEAlphaInv;
        case ST_BatchYUVAEAlphaInv:                              return STI_BatchYUVAEAlphaInv;
        case ST_InstancedYUVAEAlphaInv:                          return STI_InstancedYUVAEAlphaInv;
        case ST_Position3dYUVAEAlphaInv:                         return STI_Position3dYUVAEAlphaInv;
        case ST_BatchPosition3dYUVAEAlphaInv:                    return STI_BatchPosition3dYUVAEAlphaInv;
        case ST_InstancedPosition3dYUVAEAlphaInv:                return STI_InstancedPosition3dYUVAEAlphaInv;
        case ST_YUVACxformEAlphaInv:                             return STI_YUVACxformEAlphaInv;
        case ST_BatchYUVACxformEAlphaInv:                        return STI_BatchYUVACxformEAlphaInv;
        case ST_InstancedYUVACxformEAlphaInv:                    return STI_InstancedYUVACxformEAlphaInv;
        case ST_Position3dYUVACxformEAlphaInv:                   return STI_Position3dYUVACxformEAlphaInv;
        case ST_BatchPosition3dYUVACxformEAlphaInv:              return STI_BatchPosition3dYUVACxformEAlphaInv;
        case ST_InstancedPosition3dYUVACxformEAlphaInv:          return STI_InstancedPosition3dYUVACxformEAlphaInv;
        case ST_YUVACxformAc:                                    return STI_YUVACxformAc;
        case ST_YUVACxformAcMul:                                 return STI_YUVACxformAcMul;
        case ST_BatchYUVACxformAc:                               return STI_BatchYUVACxformAc;
        case ST_BatchYUVACxformAcMul:                            return STI_BatchYUVACxformAcMul;
        case ST_InstancedYUVACxformAc:                           return STI_InstancedYUVACxformAc;
        case ST_InstancedYUVACxformAcMul:                        return STI_InstancedYUVACxformAcMul;
        case ST_Position3dYUVACxformAc:                          return STI_Position3dYUVACxformAc;
        case ST_Position3dYUVACxformAcMul:                       return STI_Position3dYUVACxformAcMul;
        case ST_BatchPosition3dYUVACxformAc:                     return STI_BatchPosition3dYUVACxformAc;
        case ST_BatchPosition3dYUVACxformAcMul:                  return STI_BatchPosition3dYUVACxformAcMul;
        case ST_InstancedPosition3dYUVACxformAc:                 return STI_InstancedPosition3dYUVACxformAc;
        case ST_InstancedPosition3dYUVACxformAcMul:              return STI_InstancedPosition3dYUVACxformAcMul;
        case ST_YUVACxformAcEAlpha:                              return STI_YUVACxformAcEAlpha;
        case ST_YUVACxformAcEAlphaMul:                           return STI_YUVACxformAcEAlphaMul;
        case ST_BatchYUVACxformAcEAlpha:                         return STI_BatchYUVACxformAcEAlpha;
        case ST_BatchYUVACxformAcEAlphaMul:                      return STI_BatchYUVACxformAcEAlphaMul;
        case ST_InstancedYUVACxformAcEAlpha:                     return STI_InstancedYUVACxformAcEAlpha;
        case ST_InstancedYUVACxformAcEAlphaMul:                  return STI_InstancedYUVACxformAcEAlphaMul;
        case ST_Position3dYUVACxformAcEAlpha:                    return STI_Position3dYUVACxformAcEAlpha;
        case ST_Position3dYUVACxformAcEAlphaMul:                 return STI_Position3dYUVACxformAcEAlphaMul;
        case ST_BatchPosition3dYUVACxformAcEAlpha:               return STI_BatchPosition3dYUVACxformAcEAlpha;
        case ST_BatchPosition3dYUVACxformAcEAlphaMul:            return STI_BatchPosition3dYUVACxformAcEAlphaMul;
        case ST_InstancedPosition3dYUVACxformAcEAlpha:           return STI_InstancedPosition3dYUVACxformAcEAlpha;
        case ST_InstancedPosition3dYUVACxformAcEAlphaMul:        return STI_InstancedPosition3dYUVACxformAcEAlphaMul;
        case ST_YUVACxformAcInv:                                 return STI_YUVACxformAcInv;
        case ST_BatchYUVACxformAcInv:                            return STI_BatchYUVACxformAcInv;
        case ST_InstancedYUVACxformAcInv:                        return STI_InstancedYUVACxformAcInv;
        case ST_Position3dYUVACxformAcInv:                       return STI_Position3dYUVACxformAcInv;
        case ST_BatchPosition3dYUVACxformAcInv:                  return STI_BatchPosition3dYUVACxformAcInv;
        case ST_InstancedPosition3dYUVACxformAcInv:              return STI_InstancedPosition3dYUVACxformAcInv;
        case ST_YUVACxformAcEAlphaInv:                           return STI_YUVACxformAcEAlphaInv;
        case ST_BatchYUVACxformAcEAlphaInv:                      return STI_BatchYUVACxformAcEAlphaInv;
        case ST_InstancedYUVACxformAcEAlphaInv:                  return STI_InstancedYUVACxformAcEAlphaInv;
        case ST_Position3dYUVACxformAcEAlphaInv:                 return STI_Position3dYUVACxformAcEAlphaInv;
        case ST_BatchPosition3dYUVACxformAcEAlphaInv:            return STI_BatchPosition3dYUVACxformAcEAlphaInv;
        case ST_InstancedPosition3dYUVACxformAcEAlphaInv:        return STI_InstancedPosition3dYUVACxformAcEAlphaInv;
        case ST_TexTGCMatrixAc:                                  return STI_TexTGCMatrixAc;
        case ST_TexTGCMatrixAcMul:                               return STI_TexTGCMatrixAcMul;
        case ST_TexTGCMatrixAcEAlpha:                            return STI_TexTGCMatrixAcEAlpha;
        case ST_TexTGCMatrixAcEAlphaMul:                         return STI_TexTGCMatrixAcEAlphaMul;
        case ST_Box1Blur:                                        return STI_Box1Blur;
        case ST_Box1BlurMul:                                     return STI_Box1BlurMul;
        case ST_Box2Blur:                                        return STI_Box2Blur;
        case ST_Box2BlurMul:                                     return STI_Box2BlurMul;
        case ST_Box2Shadow:                                      return STI_Box2Shadow;
        case ST_Box2ShadowMul:                                   return STI_Box2ShadowMul;
        case ST_Box2ShadowKnockout:                              return STI_Box2ShadowKnockout;
        case ST_Box2ShadowKnockoutMul:                           return STI_Box2ShadowKnockoutMul;
        case ST_Box2Shadowonly:                                  return STI_Box2Shadowonly;
        case ST_Box2ShadowonlyMul:                               return STI_Box2ShadowonlyMul;
        case ST_Box2InnerShadow:                                 return STI_Box2InnerShadow;
        case ST_Box2InnerShadowMul:                              return STI_Box2InnerShadowMul;
        case ST_Box2InnerShadowKnockout:                         return STI_Box2InnerShadowKnockout;
        case ST_Box2InnerShadowKnockoutMul:                      return STI_Box2InnerShadowKnockoutMul;
        case ST_Box2ShadowonlyHighlight:                         return STI_Box2ShadowonlyHighlight;
        case ST_Box2ShadowonlyHighlightMul:                      return STI_Box2ShadowonlyHighlightMul;
        case ST_Box2FullShadowHighlight:                         return STI_Box2FullShadowHighlight;
        case ST_Box2FullShadowHighlightMul:                      return STI_Box2FullShadowHighlightMul;
        case ST_Box2InnerShadowHighlight:                        return STI_Box2InnerShadowHighlight;
        case ST_Box2InnerShadowHighlightMul:                     return STI_Box2InnerShadowHighlightMul;
        case ST_Box2InnerShadowHighlightKnockout:                return STI_Box2InnerShadowHighlightKnockout;
        case ST_Box2InnerShadowHighlightKnockoutMul:             return STI_Box2InnerShadowHighlightKnockoutMul;
        case ST_Box2ShadowHighlight:                             return STI_Box2ShadowHighlight;
        case ST_Box2ShadowHighlightMul:                          return STI_Box2ShadowHighlightMul;
        case ST_Box2ShadowHighlightKnockout:                     return STI_Box2ShadowHighlightKnockout;
        case ST_Box2ShadowHighlightKnockoutMul:                  return STI_Box2ShadowHighlightKnockoutMul;
        case ST_DrawableCopyPixels:                              return STI_DrawableCopyPixels;
        case ST_DrawableCopyPixelsNoDestAlpha:                   return STI_DrawableCopyPixelsNoDestAlpha;
        case ST_DrawableCopyPixelsMergeAlpha:                    return STI_DrawableCopyPixelsMergeAlpha;
        case ST_DrawableCopyPixelsAlpha:                         return STI_DrawableCopyPixelsAlpha;
        case ST_DrawableCopyPixelsAlphaNoDestAlpha:              return STI_DrawableCopyPixelsAlphaNoDestAlpha;
        case ST_DrawableCopyPixelsAlphaMergeAlpha:               return STI_DrawableCopyPixelsAlphaMergeAlpha;
        case ST_DrawableMerge:                                   return STI_DrawableMerge;
        case ST_DrawableCompare:                                 return STI_DrawableCompare;
        case ST_DrawablePaletteMap:                              return STI_DrawablePaletteMap;
        default: SF_DEBUG_ASSERT1(1, "Invalid ShaderType (%d)", type);
    }
    return STI_None;
}

struct ShaderIndexEntry
{
    VertexShaderDesc::ShaderIndex VertexIndex;
    FragShaderDesc::ShaderIndex FragIndex;
};

static const ShaderIndexEntry ShaderIndexingData[ShaderDesc::STI_Count][ShaderDesc::ShaderVersion_Count] = 
{
    { // ST_None
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_None,
            FragShaderDesc::FSI_None
        },
    },
    { // ST_TexTG
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTG,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTG
        }
    },
    { // ST_TexTGMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGMul
        }
    },
    { // ST_BatchTexTG
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTG,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTG
        }
    },
    { // ST_BatchTexTGMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGMul
        }
    },
    { // ST_InstancedTexTG
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTG,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTG
        }
    },
    { // ST_InstancedTexTGMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGMul
        }
    },
    { // ST_Position3dTexTG
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTG,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTG
        }
    },
    { // ST_Position3dTexTGMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGMul
        }
    },
    { // ST_BatchPosition3dTexTG
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTG,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTG
        }
    },
    { // ST_BatchPosition3dTexTGMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGMul
        }
    },
    { // ST_InstancedPosition3dTexTG
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTG,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTG
        }
    },
    { // ST_InstancedPosition3dTexTGMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGMul
        }
    },
    { // ST_TexTGCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGCxform
        }
    },
    { // ST_TexTGCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGCxformMul
        }
    },
    { // ST_BatchTexTGCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGCxform
        }
    },
    { // ST_BatchTexTGCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGCxformMul
        }
    },
    { // ST_InstancedTexTGCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGCxform
        }
    },
    { // ST_InstancedTexTGCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGCxformMul
        }
    },
    { // ST_Position3dTexTGCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGCxform
        }
    },
    { // ST_Position3dTexTGCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGCxformMul
        }
    },
    { // ST_BatchPosition3dTexTGCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxform
        }
    },
    { // ST_BatchPosition3dTexTGCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxformMul
        }
    },
    { // ST_InstancedPosition3dTexTGCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxform
        }
    },
    { // ST_InstancedPosition3dTexTGCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxformMul
        }
    },
    { // ST_TexTGEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGEAlpha
        }
    },
    { // ST_TexTGEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGEAlphaMul
        }
    },
    { // ST_BatchTexTGEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGEAlpha
        }
    },
    { // ST_BatchTexTGEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGEAlphaMul
        }
    },
    { // ST_InstancedTexTGEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGEAlpha
        }
    },
    { // ST_InstancedTexTGEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGEAlphaMul
        }
    },
    { // ST_Position3dTexTGEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGEAlpha
        }
    },
    { // ST_Position3dTexTGEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGEAlphaMul
        }
    },
    { // ST_BatchPosition3dTexTGEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGEAlpha
        }
    },
    { // ST_BatchPosition3dTexTGEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGEAlphaMul
        }
    },
    { // ST_InstancedPosition3dTexTGEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGEAlpha
        }
    },
    { // ST_InstancedPosition3dTexTGEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGEAlphaMul
        }
    },
    { // ST_TexTGCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGCxformEAlpha
        }
    },
    { // ST_TexTGCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGCxformEAlphaMul
        }
    },
    { // ST_BatchTexTGCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGCxformEAlpha
        }
    },
    { // ST_BatchTexTGCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGCxformEAlphaMul
        }
    },
    { // ST_InstancedTexTGCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGCxformEAlpha
        }
    },
    { // ST_InstancedTexTGCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGCxformEAlphaMul
        }
    },
    { // ST_Position3dTexTGCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGCxformEAlpha
        }
    },
    { // ST_Position3dTexTGCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGCxformEAlphaMul
        }
    },
    { // ST_BatchPosition3dTexTGCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxformEAlpha
        }
    },
    { // ST_BatchPosition3dTexTGCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxformEAlphaMul
        }
    },
    { // ST_InstancedPosition3dTexTGCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxformEAlpha
        }
    },
    { // ST_InstancedPosition3dTexTGCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxformEAlphaMul
        }
    },
    { // ST_TexTGInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGInv
        }
    },
    { // ST_BatchTexTGInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGInv
        }
    },
    { // ST_InstancedTexTGInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGInv
        }
    },
    { // ST_Position3dTexTGInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGInv
        }
    },
    { // ST_BatchPosition3dTexTGInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGInv
        }
    },
    { // ST_InstancedPosition3dTexTGInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGInv
        }
    },
    { // ST_TexTGCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGCxformInv
        }
    },
    { // ST_BatchTexTGCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGCxformInv
        }
    },
    { // ST_InstancedTexTGCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGCxformInv
        }
    },
    { // ST_Position3dTexTGCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGCxformInv
        }
    },
    { // ST_BatchPosition3dTexTGCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxformInv
        }
    },
    { // ST_InstancedPosition3dTexTGCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxformInv
        }
    },
    { // ST_TexTGEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGEAlphaInv
        }
    },
    { // ST_BatchTexTGEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGEAlphaInv
        }
    },
    { // ST_InstancedTexTGEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGEAlphaInv
        }
    },
    { // ST_Position3dTexTGEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGEAlphaInv
        }
    },
    { // ST_BatchPosition3dTexTGEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGEAlphaInv
        }
    },
    { // ST_InstancedPosition3dTexTGEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGEAlphaInv
        }
    },
    { // ST_TexTGCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGCxformEAlphaInv
        }
    },
    { // ST_BatchTexTGCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGCxformEAlphaInv
        }
    },
    { // ST_InstancedTexTGCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGCxformEAlphaInv
        }
    },
    { // ST_Position3dTexTGCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGCxformEAlphaInv
        }
    },
    { // ST_BatchPosition3dTexTGCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxformEAlphaInv
        }
    },
    { // ST_InstancedPosition3dTexTGCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxformEAlphaInv
        }
    },
    { // ST_TexTGCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGCxformAc
        }
    },
    { // ST_TexTGCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGCxformAcMul
        }
    },
    { // ST_BatchTexTGCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGCxformAc
        }
    },
    { // ST_BatchTexTGCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGCxformAcMul
        }
    },
    { // ST_InstancedTexTGCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGCxformAc
        }
    },
    { // ST_InstancedTexTGCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGCxformAcMul
        }
    },
    { // ST_Position3dTexTGCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGCxformAc
        }
    },
    { // ST_Position3dTexTGCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGCxformAcMul
        }
    },
    { // ST_BatchPosition3dTexTGCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxformAc
        }
    },
    { // ST_BatchPosition3dTexTGCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxformAcMul
        }
    },
    { // ST_InstancedPosition3dTexTGCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxformAc
        }
    },
    { // ST_InstancedPosition3dTexTGCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxformAcMul
        }
    },
    { // ST_TexTGCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGCxformAcEAlpha
        }
    },
    { // ST_TexTGCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGCxformAcEAlphaMul
        }
    },
    { // ST_BatchTexTGCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGCxformAcEAlpha
        }
    },
    { // ST_BatchTexTGCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGCxformAcEAlphaMul
        }
    },
    { // ST_InstancedTexTGCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGCxformAcEAlpha
        }
    },
    { // ST_InstancedTexTGCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGCxformAcEAlphaMul
        }
    },
    { // ST_Position3dTexTGCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGCxformAcEAlpha
        }
    },
    { // ST_Position3dTexTGCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGCxformAcEAlphaMul
        }
    },
    { // ST_BatchPosition3dTexTGCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxformAcEAlpha
        }
    },
    { // ST_BatchPosition3dTexTGCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxformAcEAlphaMul
        }
    },
    { // ST_InstancedPosition3dTexTGCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxformAcEAlpha
        }
    },
    { // ST_InstancedPosition3dTexTGCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxformAcEAlphaMul
        }
    },
    { // ST_TexTGCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGCxformAcInv
        }
    },
    { // ST_BatchTexTGCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGCxformAcInv
        }
    },
    { // ST_InstancedTexTGCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGCxformAcInv
        }
    },
    { // ST_Position3dTexTGCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGCxformAcInv
        }
    },
    { // ST_BatchPosition3dTexTGCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxformAcInv
        }
    },
    { // ST_InstancedPosition3dTexTGCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxformAcInv
        }
    },
    { // ST_TexTGCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGCxformAcEAlphaInv
        }
    },
    { // ST_BatchTexTGCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGCxformAcEAlphaInv
        }
    },
    { // ST_InstancedTexTGCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGCxformAcEAlphaInv
        }
    },
    { // ST_Position3dTexTGCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGCxformAcEAlphaInv
        }
    },
    { // ST_BatchPosition3dTexTGCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxformAcEAlphaInv
        }
    },
    { // ST_InstancedPosition3dTexTGCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxformAcEAlphaInv
        }
    },
    { // ST_Vertex
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VVertex,
            FragShaderDesc::FSI_Vulkan_SPIRV_FVertex
        }
    },
    { // ST_VertexMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VVertexMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FVertexMul
        }
    },
    { // ST_BatchVertex
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchVertex,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchVertex
        }
    },
    { // ST_BatchVertexMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchVertexMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchVertexMul
        }
    },
    { // ST_InstancedVertex
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedVertex,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedVertex
        }
    },
    { // ST_InstancedVertexMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedVertexMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedVertexMul
        }
    },
    { // ST_Position3dVertex
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dVertex,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dVertex
        }
    },
    { // ST_Position3dVertexMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dVertexMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dVertexMul
        }
    },
    { // ST_BatchPosition3dVertex
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dVertex,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dVertex
        }
    },
    { // ST_BatchPosition3dVertexMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dVertexMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dVertexMul
        }
    },
    { // ST_InstancedPosition3dVertex
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dVertex,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dVertex
        }
    },
    { // ST_InstancedPosition3dVertexMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dVertexMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dVertexMul
        }
    },
    { // ST_VertexCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VVertexCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FVertexCxform
        }
    },
    { // ST_VertexCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VVertexCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FVertexCxformMul
        }
    },
    { // ST_BatchVertexCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchVertexCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchVertexCxform
        }
    },
    { // ST_BatchVertexCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchVertexCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchVertexCxformMul
        }
    },
    { // ST_InstancedVertexCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedVertexCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedVertexCxform
        }
    },
    { // ST_InstancedVertexCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedVertexCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedVertexCxformMul
        }
    },
    { // ST_Position3dVertexCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dVertexCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dVertexCxform
        }
    },
    { // ST_Position3dVertexCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dVertexCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dVertexCxformMul
        }
    },
    { // ST_BatchPosition3dVertexCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxform
        }
    },
    { // ST_BatchPosition3dVertexCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxformMul
        }
    },
    { // ST_InstancedPosition3dVertexCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxform
        }
    },
    { // ST_InstancedPosition3dVertexCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxformMul
        }
    },
    { // ST_VertexEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VVertexEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FVertexEAlpha
        }
    },
    { // ST_VertexEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VVertexEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FVertexEAlphaMul
        }
    },
    { // ST_BatchVertexEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchVertexEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchVertexEAlpha
        }
    },
    { // ST_BatchVertexEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchVertexEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchVertexEAlphaMul
        }
    },
    { // ST_InstancedVertexEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedVertexEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedVertexEAlpha
        }
    },
    { // ST_InstancedVertexEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedVertexEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedVertexEAlphaMul
        }
    },
    { // ST_Position3dVertexEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dVertexEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dVertexEAlpha
        }
    },
    { // ST_Position3dVertexEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dVertexEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dVertexEAlphaMul
        }
    },
    { // ST_BatchPosition3dVertexEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dVertexEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dVertexEAlpha
        }
    },
    { // ST_BatchPosition3dVertexEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dVertexEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dVertexEAlphaMul
        }
    },
    { // ST_InstancedPosition3dVertexEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dVertexEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dVertexEAlpha
        }
    },
    { // ST_InstancedPosition3dVertexEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dVertexEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dVertexEAlphaMul
        }
    },
    { // ST_VertexCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VVertexCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FVertexCxformEAlpha
        }
    },
    { // ST_VertexCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VVertexCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FVertexCxformEAlphaMul
        }
    },
    { // ST_BatchVertexCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchVertexCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchVertexCxformEAlpha
        }
    },
    { // ST_BatchVertexCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchVertexCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchVertexCxformEAlphaMul
        }
    },
    { // ST_InstancedVertexCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedVertexCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedVertexCxformEAlpha
        }
    },
    { // ST_InstancedVertexCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedVertexCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedVertexCxformEAlphaMul
        }
    },
    { // ST_Position3dVertexCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dVertexCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dVertexCxformEAlpha
        }
    },
    { // ST_Position3dVertexCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dVertexCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dVertexCxformEAlphaMul
        }
    },
    { // ST_BatchPosition3dVertexCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxformEAlpha
        }
    },
    { // ST_BatchPosition3dVertexCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxformEAlphaMul
        }
    },
    { // ST_InstancedPosition3dVertexCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxformEAlpha
        }
    },
    { // ST_InstancedPosition3dVertexCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxformEAlphaMul
        }
    },
    { // ST_VertexInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VVertexInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FVertexInv
        }
    },
    { // ST_BatchVertexInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchVertexInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchVertexInv
        }
    },
    { // ST_InstancedVertexInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedVertexInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedVertexInv
        }
    },
    { // ST_Position3dVertexInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dVertexInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dVertexInv
        }
    },
    { // ST_BatchPosition3dVertexInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dVertexInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dVertexInv
        }
    },
    { // ST_InstancedPosition3dVertexInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dVertexInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dVertexInv
        }
    },
    { // ST_VertexCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VVertexCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FVertexCxformInv
        }
    },
    { // ST_BatchVertexCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchVertexCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchVertexCxformInv
        }
    },
    { // ST_InstancedVertexCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedVertexCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedVertexCxformInv
        }
    },
    { // ST_Position3dVertexCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dVertexCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dVertexCxformInv
        }
    },
    { // ST_BatchPosition3dVertexCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxformInv
        }
    },
    { // ST_InstancedPosition3dVertexCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxformInv
        }
    },
    { // ST_VertexEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VVertexEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FVertexEAlphaInv
        }
    },
    { // ST_BatchVertexEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchVertexEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchVertexEAlphaInv
        }
    },
    { // ST_InstancedVertexEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedVertexEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedVertexEAlphaInv
        }
    },
    { // ST_Position3dVertexEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dVertexEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dVertexEAlphaInv
        }
    },
    { // ST_BatchPosition3dVertexEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dVertexEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dVertexEAlphaInv
        }
    },
    { // ST_InstancedPosition3dVertexEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dVertexEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dVertexEAlphaInv
        }
    },
    { // ST_VertexCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VVertexCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FVertexCxformEAlphaInv
        }
    },
    { // ST_BatchVertexCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchVertexCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchVertexCxformEAlphaInv
        }
    },
    { // ST_InstancedVertexCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedVertexCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedVertexCxformEAlphaInv
        }
    },
    { // ST_Position3dVertexCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dVertexCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dVertexCxformEAlphaInv
        }
    },
    { // ST_BatchPosition3dVertexCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxformEAlphaInv
        }
    },
    { // ST_InstancedPosition3dVertexCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxformEAlphaInv
        }
    },
    { // ST_VertexCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VVertexCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FVertexCxformAc
        }
    },
    { // ST_VertexCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VVertexCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FVertexCxformAcMul
        }
    },
    { // ST_BatchVertexCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchVertexCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchVertexCxformAc
        }
    },
    { // ST_BatchVertexCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchVertexCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchVertexCxformAcMul
        }
    },
    { // ST_InstancedVertexCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedVertexCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedVertexCxformAc
        }
    },
    { // ST_InstancedVertexCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedVertexCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedVertexCxformAcMul
        }
    },
    { // ST_Position3dVertexCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dVertexCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dVertexCxformAc
        }
    },
    { // ST_Position3dVertexCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dVertexCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dVertexCxformAcMul
        }
    },
    { // ST_BatchPosition3dVertexCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxformAc
        }
    },
    { // ST_BatchPosition3dVertexCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxformAcMul
        }
    },
    { // ST_InstancedPosition3dVertexCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxformAc
        }
    },
    { // ST_InstancedPosition3dVertexCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxformAcMul
        }
    },
    { // ST_VertexCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VVertexCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FVertexCxformAcEAlpha
        }
    },
    { // ST_VertexCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VVertexCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FVertexCxformAcEAlphaMul
        }
    },
    { // ST_BatchVertexCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchVertexCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchVertexCxformAcEAlpha
        }
    },
    { // ST_BatchVertexCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchVertexCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchVertexCxformAcEAlphaMul
        }
    },
    { // ST_InstancedVertexCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedVertexCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedVertexCxformAcEAlpha
        }
    },
    { // ST_InstancedVertexCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedVertexCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedVertexCxformAcEAlphaMul
        }
    },
    { // ST_Position3dVertexCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dVertexCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dVertexCxformAcEAlpha
        }
    },
    { // ST_Position3dVertexCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dVertexCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dVertexCxformAcEAlphaMul
        }
    },
    { // ST_BatchPosition3dVertexCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxformAcEAlpha
        }
    },
    { // ST_BatchPosition3dVertexCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxformAcEAlphaMul
        }
    },
    { // ST_InstancedPosition3dVertexCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxformAcEAlpha
        }
    },
    { // ST_InstancedPosition3dVertexCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxformAcEAlphaMul
        }
    },
    { // ST_VertexCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VVertexCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FVertexCxformAcInv
        }
    },
    { // ST_BatchVertexCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchVertexCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchVertexCxformAcInv
        }
    },
    { // ST_InstancedVertexCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedVertexCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedVertexCxformAcInv
        }
    },
    { // ST_Position3dVertexCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dVertexCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dVertexCxformAcInv
        }
    },
    { // ST_BatchPosition3dVertexCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxformAcInv
        }
    },
    { // ST_InstancedPosition3dVertexCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxformAcInv
        }
    },
    { // ST_VertexCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VVertexCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FVertexCxformAcEAlphaInv
        }
    },
    { // ST_BatchVertexCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchVertexCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchVertexCxformAcEAlphaInv
        }
    },
    { // ST_InstancedVertexCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedVertexCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedVertexCxformAcEAlphaInv
        }
    },
    { // ST_Position3dVertexCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dVertexCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dVertexCxformAcEAlphaInv
        }
    },
    { // ST_BatchPosition3dVertexCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxformAcEAlphaInv
        }
    },
    { // ST_InstancedPosition3dVertexCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxformAcEAlphaInv
        }
    },
    { // ST_TexTGTexTG
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGTexTG,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGTexTG
        }
    },
    { // ST_TexTGTexTGMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGTexTGMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGTexTGMul
        }
    },
    { // ST_BatchTexTGTexTG
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGTexTG,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGTexTG
        }
    },
    { // ST_BatchTexTGTexTGMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGTexTGMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGTexTGMul
        }
    },
    { // ST_InstancedTexTGTexTG
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGTexTG,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGTexTG
        }
    },
    { // ST_InstancedTexTGTexTGMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGTexTGMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGTexTGMul
        }
    },
    { // ST_Position3dTexTGTexTG
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGTexTG,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGTexTG
        }
    },
    { // ST_Position3dTexTGTexTGMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGMul
        }
    },
    { // ST_BatchPosition3dTexTGTexTG
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTG,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTG
        }
    },
    { // ST_BatchPosition3dTexTGTexTGMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGMul
        }
    },
    { // ST_InstancedPosition3dTexTGTexTG
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTG,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTG
        }
    },
    { // ST_InstancedPosition3dTexTGTexTGMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGMul
        }
    },
    { // ST_TexTGTexTGCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGTexTGCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGTexTGCxform
        }
    },
    { // ST_TexTGTexTGCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGTexTGCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGTexTGCxformMul
        }
    },
    { // ST_BatchTexTGTexTGCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxform
        }
    },
    { // ST_BatchTexTGTexTGCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxformMul
        }
    },
    { // ST_InstancedTexTGTexTGCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxform
        }
    },
    { // ST_InstancedTexTGTexTGCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxformMul
        }
    },
    { // ST_Position3dTexTGTexTGCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxform
        }
    },
    { // ST_Position3dTexTGTexTGCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxformMul
        }
    },
    { // ST_BatchPosition3dTexTGTexTGCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxform
        }
    },
    { // ST_BatchPosition3dTexTGTexTGCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxformMul
        }
    },
    { // ST_InstancedPosition3dTexTGTexTGCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxform
        }
    },
    { // ST_InstancedPosition3dTexTGTexTGCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxformMul
        }
    },
    { // ST_TexTGTexTGEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGTexTGEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGTexTGEAlpha
        }
    },
    { // ST_TexTGTexTGEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGTexTGEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGTexTGEAlphaMul
        }
    },
    { // ST_BatchTexTGTexTGEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGTexTGEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGTexTGEAlpha
        }
    },
    { // ST_BatchTexTGTexTGEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGTexTGEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGTexTGEAlphaMul
        }
    },
    { // ST_InstancedTexTGTexTGEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGTexTGEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGTexTGEAlpha
        }
    },
    { // ST_InstancedTexTGTexTGEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGTexTGEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGTexTGEAlphaMul
        }
    },
    { // ST_Position3dTexTGTexTGEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGEAlpha
        }
    },
    { // ST_Position3dTexTGTexTGEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGEAlphaMul
        }
    },
    { // ST_BatchPosition3dTexTGTexTGEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGEAlpha
        }
    },
    { // ST_BatchPosition3dTexTGTexTGEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGEAlphaMul
        }
    },
    { // ST_InstancedPosition3dTexTGTexTGEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGEAlpha
        }
    },
    { // ST_InstancedPosition3dTexTGTexTGEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGEAlphaMul
        }
    },
    { // ST_TexTGTexTGCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGTexTGCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGTexTGCxformEAlpha
        }
    },
    { // ST_TexTGTexTGCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGTexTGCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaMul
        }
    },
    { // ST_BatchTexTGTexTGCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxformEAlpha
        }
    },
    { // ST_BatchTexTGTexTGCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxformEAlphaMul
        }
    },
    { // ST_InstancedTexTGTexTGCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxformEAlpha
        }
    },
    { // ST_InstancedTexTGTexTGCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxformEAlphaMul
        }
    },
    { // ST_Position3dTexTGTexTGCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxformEAlpha
        }
    },
    { // ST_Position3dTexTGTexTGCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxformEAlphaMul
        }
    },
    { // ST_BatchPosition3dTexTGTexTGCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxformEAlpha
        }
    },
    { // ST_BatchPosition3dTexTGTexTGCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxformEAlphaMul
        }
    },
    { // ST_InstancedPosition3dTexTGTexTGCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxformEAlpha
        }
    },
    { // ST_InstancedPosition3dTexTGTexTGCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxformEAlphaMul
        }
    },
    { // ST_TexTGTexTGInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGTexTGInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGTexTGInv
        }
    },
    { // ST_BatchTexTGTexTGInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGTexTGInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGTexTGInv
        }
    },
    { // ST_InstancedTexTGTexTGInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGTexTGInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGTexTGInv
        }
    },
    { // ST_Position3dTexTGTexTGInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGInv
        }
    },
    { // ST_BatchPosition3dTexTGTexTGInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGInv
        }
    },
    { // ST_InstancedPosition3dTexTGTexTGInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGInv
        }
    },
    { // ST_TexTGTexTGCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGTexTGCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGTexTGCxformInv
        }
    },
    { // ST_BatchTexTGTexTGCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxformInv
        }
    },
    { // ST_InstancedTexTGTexTGCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxformInv
        }
    },
    { // ST_Position3dTexTGTexTGCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxformInv
        }
    },
    { // ST_BatchPosition3dTexTGTexTGCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxformInv
        }
    },
    { // ST_InstancedPosition3dTexTGTexTGCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxformInv
        }
    },
    { // ST_TexTGTexTGEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGTexTGEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGTexTGEAlphaInv
        }
    },
    { // ST_BatchTexTGTexTGEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGTexTGEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGTexTGEAlphaInv
        }
    },
    { // ST_InstancedTexTGTexTGEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGTexTGEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGTexTGEAlphaInv
        }
    },
    { // ST_Position3dTexTGTexTGEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGEAlphaInv
        }
    },
    { // ST_BatchPosition3dTexTGTexTGEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGEAlphaInv
        }
    },
    { // ST_InstancedPosition3dTexTGTexTGEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGEAlphaInv
        }
    },
    { // ST_TexTGTexTGCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGTexTGCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaInv
        }
    },
    { // ST_BatchTexTGTexTGCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxformEAlphaInv
        }
    },
    { // ST_InstancedTexTGTexTGCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxformEAlphaInv
        }
    },
    { // ST_Position3dTexTGTexTGCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxformEAlphaInv
        }
    },
    { // ST_BatchPosition3dTexTGTexTGCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxformEAlphaInv
        }
    },
    { // ST_InstancedPosition3dTexTGTexTGCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxformEAlphaInv
        }
    },
    { // ST_TexTGTexTGCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGTexTGCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGTexTGCxformAc
        }
    },
    { // ST_TexTGTexTGCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGTexTGCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGTexTGCxformAcMul
        }
    },
    { // ST_BatchTexTGTexTGCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxformAc
        }
    },
    { // ST_BatchTexTGTexTGCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxformAcMul
        }
    },
    { // ST_InstancedTexTGTexTGCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAc
        }
    },
    { // ST_InstancedTexTGTexTGCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAcMul
        }
    },
    { // ST_Position3dTexTGTexTGCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxformAc
        }
    },
    { // ST_Position3dTexTGTexTGCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxformAcMul
        }
    },
    { // ST_BatchPosition3dTexTGTexTGCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxformAc
        }
    },
    { // ST_BatchPosition3dTexTGTexTGCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxformAcMul
        }
    },
    { // ST_InstancedPosition3dTexTGTexTGCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxformAc
        }
    },
    { // ST_InstancedPosition3dTexTGTexTGCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxformAcMul
        }
    },
    { // ST_TexTGTexTGCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGTexTGCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlpha
        }
    },
    { // ST_TexTGTexTGCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGTexTGCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaMul
        }
    },
    { // ST_BatchTexTGTexTGCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxformAcEAlpha
        }
    },
    { // ST_BatchTexTGTexTGCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxformAcEAlphaMul
        }
    },
    { // ST_InstancedTexTGTexTGCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAcEAlpha
        }
    },
    { // ST_InstancedTexTGTexTGCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAcEAlphaMul
        }
    },
    { // ST_Position3dTexTGTexTGCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxformAcEAlpha
        }
    },
    { // ST_Position3dTexTGTexTGCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxformAcEAlphaMul
        }
    },
    { // ST_BatchPosition3dTexTGTexTGCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxformAcEAlpha
        }
    },
    { // ST_BatchPosition3dTexTGTexTGCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxformAcEAlphaMul
        }
    },
    { // ST_InstancedPosition3dTexTGTexTGCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxformAcEAlpha
        }
    },
    { // ST_InstancedPosition3dTexTGTexTGCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxformAcEAlphaMul
        }
    },
    { // ST_TexTGTexTGCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGTexTGCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGTexTGCxformAcInv
        }
    },
    { // ST_BatchTexTGTexTGCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxformAcInv
        }
    },
    { // ST_InstancedTexTGTexTGCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAcInv
        }
    },
    { // ST_Position3dTexTGTexTGCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxformAcInv
        }
    },
    { // ST_BatchPosition3dTexTGTexTGCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxformAcInv
        }
    },
    { // ST_InstancedPosition3dTexTGTexTGCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxformAcInv
        }
    },
    { // ST_TexTGTexTGCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGTexTGCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaInv
        }
    },
    { // ST_BatchTexTGTexTGCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxformAcEAlphaInv
        }
    },
    { // ST_InstancedTexTGTexTGCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAcEAlphaInv
        }
    },
    { // ST_Position3dTexTGTexTGCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxformAcEAlphaInv
        }
    },
    { // ST_BatchPosition3dTexTGTexTGCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxformAcEAlphaInv
        }
    },
    { // ST_InstancedPosition3dTexTGTexTGCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxformAcEAlphaInv
        }
    },
    { // ST_TexTGVertex
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGVertex,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGVertex
        }
    },
    { // ST_TexTGVertexMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGVertexMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGVertexMul
        }
    },
    { // ST_BatchTexTGVertex
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGVertex,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGVertex
        }
    },
    { // ST_BatchTexTGVertexMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGVertexMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGVertexMul
        }
    },
    { // ST_InstancedTexTGVertex
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGVertex,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGVertex
        }
    },
    { // ST_InstancedTexTGVertexMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGVertexMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGVertexMul
        }
    },
    { // ST_Position3dTexTGVertex
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGVertex,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGVertex
        }
    },
    { // ST_Position3dTexTGVertexMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGVertexMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGVertexMul
        }
    },
    { // ST_BatchPosition3dTexTGVertex
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertex,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertex
        }
    },
    { // ST_BatchPosition3dTexTGVertexMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexMul
        }
    },
    { // ST_InstancedPosition3dTexTGVertex
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertex,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertex
        }
    },
    { // ST_InstancedPosition3dTexTGVertexMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexMul
        }
    },
    { // ST_TexTGVertexCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGVertexCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGVertexCxform
        }
    },
    { // ST_TexTGVertexCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGVertexCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGVertexCxformMul
        }
    },
    { // ST_BatchTexTGVertexCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGVertexCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGVertexCxform
        }
    },
    { // ST_BatchTexTGVertexCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGVertexCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGVertexCxformMul
        }
    },
    { // ST_InstancedTexTGVertexCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxform
        }
    },
    { // ST_InstancedTexTGVertexCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxformMul
        }
    },
    { // ST_Position3dTexTGVertexCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxform
        }
    },
    { // ST_Position3dTexTGVertexCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxformMul
        }
    },
    { // ST_BatchPosition3dTexTGVertexCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxform
        }
    },
    { // ST_BatchPosition3dTexTGVertexCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxformMul
        }
    },
    { // ST_InstancedPosition3dTexTGVertexCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxform
        }
    },
    { // ST_InstancedPosition3dTexTGVertexCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxformMul
        }
    },
    { // ST_TexTGVertexEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGVertexEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGVertexEAlpha
        }
    },
    { // ST_TexTGVertexEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGVertexEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGVertexEAlphaMul
        }
    },
    { // ST_BatchTexTGVertexEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGVertexEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGVertexEAlpha
        }
    },
    { // ST_BatchTexTGVertexEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGVertexEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGVertexEAlphaMul
        }
    },
    { // ST_InstancedTexTGVertexEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGVertexEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGVertexEAlpha
        }
    },
    { // ST_InstancedTexTGVertexEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGVertexEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGVertexEAlphaMul
        }
    },
    { // ST_Position3dTexTGVertexEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGVertexEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGVertexEAlpha
        }
    },
    { // ST_Position3dTexTGVertexEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGVertexEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGVertexEAlphaMul
        }
    },
    { // ST_BatchPosition3dTexTGVertexEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexEAlpha
        }
    },
    { // ST_BatchPosition3dTexTGVertexEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexEAlphaMul
        }
    },
    { // ST_InstancedPosition3dTexTGVertexEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexEAlpha
        }
    },
    { // ST_InstancedPosition3dTexTGVertexEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexEAlphaMul
        }
    },
    { // ST_TexTGVertexCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGVertexCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGVertexCxformEAlpha
        }
    },
    { // ST_TexTGVertexCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGVertexCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGVertexCxformEAlphaMul
        }
    },
    { // ST_BatchTexTGVertexCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGVertexCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGVertexCxformEAlpha
        }
    },
    { // ST_BatchTexTGVertexCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGVertexCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGVertexCxformEAlphaMul
        }
    },
    { // ST_InstancedTexTGVertexCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxformEAlpha
        }
    },
    { // ST_InstancedTexTGVertexCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxformEAlphaMul
        }
    },
    { // ST_Position3dTexTGVertexCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxformEAlpha
        }
    },
    { // ST_Position3dTexTGVertexCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxformEAlphaMul
        }
    },
    { // ST_BatchPosition3dTexTGVertexCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxformEAlpha
        }
    },
    { // ST_BatchPosition3dTexTGVertexCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxformEAlphaMul
        }
    },
    { // ST_InstancedPosition3dTexTGVertexCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxformEAlpha
        }
    },
    { // ST_InstancedPosition3dTexTGVertexCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxformEAlphaMul
        }
    },
    { // ST_TexTGVertexInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGVertexInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGVertexInv
        }
    },
    { // ST_BatchTexTGVertexInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGVertexInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGVertexInv
        }
    },
    { // ST_InstancedTexTGVertexInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGVertexInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGVertexInv
        }
    },
    { // ST_Position3dTexTGVertexInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGVertexInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGVertexInv
        }
    },
    { // ST_BatchPosition3dTexTGVertexInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexInv
        }
    },
    { // ST_InstancedPosition3dTexTGVertexInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexInv
        }
    },
    { // ST_TexTGVertexCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGVertexCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGVertexCxformInv
        }
    },
    { // ST_BatchTexTGVertexCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGVertexCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGVertexCxformInv
        }
    },
    { // ST_InstancedTexTGVertexCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxformInv
        }
    },
    { // ST_Position3dTexTGVertexCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxformInv
        }
    },
    { // ST_BatchPosition3dTexTGVertexCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxformInv
        }
    },
    { // ST_InstancedPosition3dTexTGVertexCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxformInv
        }
    },
    { // ST_TexTGVertexEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGVertexEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGVertexEAlphaInv
        }
    },
    { // ST_BatchTexTGVertexEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGVertexEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGVertexEAlphaInv
        }
    },
    { // ST_InstancedTexTGVertexEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGVertexEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGVertexEAlphaInv
        }
    },
    { // ST_Position3dTexTGVertexEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGVertexEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGVertexEAlphaInv
        }
    },
    { // ST_BatchPosition3dTexTGVertexEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexEAlphaInv
        }
    },
    { // ST_InstancedPosition3dTexTGVertexEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexEAlphaInv
        }
    },
    { // ST_TexTGVertexCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGVertexCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGVertexCxformEAlphaInv
        }
    },
    { // ST_BatchTexTGVertexCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGVertexCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGVertexCxformEAlphaInv
        }
    },
    { // ST_InstancedTexTGVertexCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxformEAlphaInv
        }
    },
    { // ST_Position3dTexTGVertexCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxformEAlphaInv
        }
    },
    { // ST_BatchPosition3dTexTGVertexCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxformEAlphaInv
        }
    },
    { // ST_InstancedPosition3dTexTGVertexCxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxformEAlphaInv
        }
    },
    { // ST_TexTGVertexCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGVertexCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGVertexCxformAc
        }
    },
    { // ST_TexTGVertexCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGVertexCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGVertexCxformAcMul
        }
    },
    { // ST_BatchTexTGVertexCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGVertexCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGVertexCxformAc
        }
    },
    { // ST_BatchTexTGVertexCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGVertexCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGVertexCxformAcMul
        }
    },
    { // ST_InstancedTexTGVertexCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxformAc
        }
    },
    { // ST_InstancedTexTGVertexCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxformAcMul
        }
    },
    { // ST_Position3dTexTGVertexCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxformAc
        }
    },
    { // ST_Position3dTexTGVertexCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxformAcMul
        }
    },
    { // ST_BatchPosition3dTexTGVertexCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxformAc
        }
    },
    { // ST_BatchPosition3dTexTGVertexCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxformAcMul
        }
    },
    { // ST_InstancedPosition3dTexTGVertexCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxformAc
        }
    },
    { // ST_InstancedPosition3dTexTGVertexCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxformAcMul
        }
    },
    { // ST_TexTGVertexCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGVertexCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGVertexCxformAcEAlpha
        }
    },
    { // ST_TexTGVertexCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGVertexCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaMul
        }
    },
    { // ST_BatchTexTGVertexCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGVertexCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGVertexCxformAcEAlpha
        }
    },
    { // ST_BatchTexTGVertexCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGVertexCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGVertexCxformAcEAlphaMul
        }
    },
    { // ST_InstancedTexTGVertexCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxformAcEAlpha
        }
    },
    { // ST_InstancedTexTGVertexCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxformAcEAlphaMul
        }
    },
    { // ST_Position3dTexTGVertexCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxformAcEAlpha
        }
    },
    { // ST_Position3dTexTGVertexCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxformAcEAlphaMul
        }
    },
    { // ST_BatchPosition3dTexTGVertexCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxformAcEAlpha
        }
    },
    { // ST_BatchPosition3dTexTGVertexCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxformAcEAlphaMul
        }
    },
    { // ST_InstancedPosition3dTexTGVertexCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxformAcEAlpha
        }
    },
    { // ST_InstancedPosition3dTexTGVertexCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxformAcEAlphaMul
        }
    },
    { // ST_TexTGVertexCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGVertexCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGVertexCxformAcInv
        }
    },
    { // ST_BatchTexTGVertexCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGVertexCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGVertexCxformAcInv
        }
    },
    { // ST_InstancedTexTGVertexCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxformAcInv
        }
    },
    { // ST_Position3dTexTGVertexCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxformAcInv
        }
    },
    { // ST_BatchPosition3dTexTGVertexCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxformAcInv
        }
    },
    { // ST_InstancedPosition3dTexTGVertexCxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxformAcInv
        }
    },
    { // ST_TexTGVertexCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGVertexCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaInv
        }
    },
    { // ST_BatchTexTGVertexCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTexTGVertexCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTexTGVertexCxformAcEAlphaInv
        }
    },
    { // ST_InstancedTexTGVertexCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxformAcEAlphaInv
        }
    },
    { // ST_Position3dTexTGVertexCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxformAcEAlphaInv
        }
    },
    { // ST_BatchPosition3dTexTGVertexCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxformAcEAlphaInv
        }
    },
    { // ST_InstancedPosition3dTexTGVertexCxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxformAcEAlphaInv
        }
    },
    { // ST_Solid
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VSolid,
            FragShaderDesc::FSI_Vulkan_SPIRV_FSolid
        }
    },
    { // ST_SolidMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VSolidMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FSolidMul
        }
    },
    { // ST_BatchSolid
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchSolid,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchSolid
        }
    },
    { // ST_BatchSolidMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchSolidMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchSolidMul
        }
    },
    { // ST_InstancedSolid
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedSolid,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedSolid
        }
    },
    { // ST_InstancedSolidMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedSolidMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedSolidMul
        }
    },
    { // ST_Position3dSolid
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dSolid,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dSolid
        }
    },
    { // ST_Position3dSolidMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dSolidMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dSolidMul
        }
    },
    { // ST_BatchPosition3dSolid
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dSolid,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dSolid
        }
    },
    { // ST_BatchPosition3dSolidMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dSolidMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dSolidMul
        }
    },
    { // ST_InstancedPosition3dSolid
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dSolid,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dSolid
        }
    },
    { // ST_InstancedPosition3dSolidMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dSolidMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dSolidMul
        }
    },
    { // ST_SolidInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VSolidInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FSolidInv
        }
    },
    { // ST_BatchSolidInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchSolidInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchSolidInv
        }
    },
    { // ST_InstancedSolidInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedSolidInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedSolidInv
        }
    },
    { // ST_Position3dSolidInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dSolidInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dSolidInv
        }
    },
    { // ST_BatchPosition3dSolidInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dSolidInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dSolidInv
        }
    },
    { // ST_InstancedPosition3dSolidInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dSolidInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dSolidInv
        }
    },
    { // ST_Text
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VText,
            FragShaderDesc::FSI_Vulkan_SPIRV_FText
        }
    },
    { // ST_TextMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTextMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTextMul
        }
    },
    { // ST_BatchText
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchText,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchText
        }
    },
    { // ST_BatchTextMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTextMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTextMul
        }
    },
    { // ST_InstancedText
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedText,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedText
        }
    },
    { // ST_InstancedTextMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTextMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTextMul
        }
    },
    { // ST_Position3dText
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dText,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dText
        }
    },
    { // ST_Position3dTextMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTextMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTextMul
        }
    },
    { // ST_BatchPosition3dText
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dText,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dText
        }
    },
    { // ST_BatchPosition3dTextMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTextMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTextMul
        }
    },
    { // ST_InstancedPosition3dText
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dText,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dText
        }
    },
    { // ST_InstancedPosition3dTextMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTextMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTextMul
        }
    },
    { // ST_TextInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTextInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTextInv
        }
    },
    { // ST_BatchTextInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTextInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTextInv
        }
    },
    { // ST_InstancedTextInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTextInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTextInv
        }
    },
    { // ST_Position3dTextInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTextInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTextInv
        }
    },
    { // ST_BatchPosition3dTextInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTextInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTextInv
        }
    },
    { // ST_InstancedPosition3dTextInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTextInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTextInv
        }
    },
    { // ST_TextColor
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTextColor,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTextColor
        }
    },
    { // ST_TextColorMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTextColorMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTextColorMul
        }
    },
    { // ST_BatchTextColor
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTextColor,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTextColor
        }
    },
    { // ST_BatchTextColorMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTextColorMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTextColorMul
        }
    },
    { // ST_InstancedTextColor
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTextColor,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTextColor
        }
    },
    { // ST_InstancedTextColorMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTextColorMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTextColorMul
        }
    },
    { // ST_Position3dTextColor
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTextColor,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTextColor
        }
    },
    { // ST_Position3dTextColorMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTextColorMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTextColorMul
        }
    },
    { // ST_BatchPosition3dTextColor
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTextColor,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTextColor
        }
    },
    { // ST_BatchPosition3dTextColorMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTextColorMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTextColorMul
        }
    },
    { // ST_InstancedPosition3dTextColor
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTextColor,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTextColor
        }
    },
    { // ST_InstancedPosition3dTextColorMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTextColorMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTextColorMul
        }
    },
    { // ST_TextColorCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTextColorCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTextColorCxform
        }
    },
    { // ST_TextColorCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTextColorCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTextColorCxformMul
        }
    },
    { // ST_BatchTextColorCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTextColorCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTextColorCxform
        }
    },
    { // ST_BatchTextColorCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTextColorCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTextColorCxformMul
        }
    },
    { // ST_InstancedTextColorCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTextColorCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTextColorCxform
        }
    },
    { // ST_InstancedTextColorCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTextColorCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTextColorCxformMul
        }
    },
    { // ST_Position3dTextColorCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTextColorCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTextColorCxform
        }
    },
    { // ST_Position3dTextColorCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTextColorCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTextColorCxformMul
        }
    },
    { // ST_BatchPosition3dTextColorCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTextColorCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTextColorCxform
        }
    },
    { // ST_BatchPosition3dTextColorCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTextColorCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTextColorCxformMul
        }
    },
    { // ST_InstancedPosition3dTextColorCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTextColorCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTextColorCxform
        }
    },
    { // ST_InstancedPosition3dTextColorCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTextColorCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTextColorCxformMul
        }
    },
    { // ST_TextColorInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTextColorInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTextColorInv
        }
    },
    { // ST_BatchTextColorInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTextColorInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTextColorInv
        }
    },
    { // ST_InstancedTextColorInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTextColorInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTextColorInv
        }
    },
    { // ST_Position3dTextColorInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTextColorInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTextColorInv
        }
    },
    { // ST_BatchPosition3dTextColorInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTextColorInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTextColorInv
        }
    },
    { // ST_InstancedPosition3dTextColorInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTextColorInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTextColorInv
        }
    },
    { // ST_TextColorCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTextColorCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTextColorCxformInv
        }
    },
    { // ST_BatchTextColorCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchTextColorCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchTextColorCxformInv
        }
    },
    { // ST_InstancedTextColorCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedTextColorCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedTextColorCxformInv
        }
    },
    { // ST_Position3dTextColorCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dTextColorCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dTextColorCxformInv
        }
    },
    { // ST_BatchPosition3dTextColorCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dTextColorCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dTextColorCxformInv
        }
    },
    { // ST_InstancedPosition3dTextColorCxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dTextColorCxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dTextColorCxformInv
        }
    },
    { // ST_YUV
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUV,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUV
        }
    },
    { // ST_YUVMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVMul
        }
    },
    { // ST_BatchYUV
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUV,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUV
        }
    },
    { // ST_BatchYUVMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVMul
        }
    },
    { // ST_InstancedYUV
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUV,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUV
        }
    },
    { // ST_InstancedYUVMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVMul
        }
    },
    { // ST_Position3dYUV
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUV,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUV
        }
    },
    { // ST_Position3dYUVMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVMul
        }
    },
    { // ST_BatchPosition3dYUV
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUV,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUV
        }
    },
    { // ST_BatchPosition3dYUVMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVMul
        }
    },
    { // ST_InstancedPosition3dYUV
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUV,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUV
        }
    },
    { // ST_InstancedPosition3dYUVMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVMul
        }
    },
    { // ST_YUVCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVCxform
        }
    },
    { // ST_YUVCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVCxformMul
        }
    },
    { // ST_BatchYUVCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVCxform
        }
    },
    { // ST_BatchYUVCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVCxformMul
        }
    },
    { // ST_InstancedYUVCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVCxform
        }
    },
    { // ST_InstancedYUVCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVCxformMul
        }
    },
    { // ST_Position3dYUVCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVCxform
        }
    },
    { // ST_Position3dYUVCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVCxformMul
        }
    },
    { // ST_BatchPosition3dYUVCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVCxform
        }
    },
    { // ST_BatchPosition3dYUVCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVCxformMul
        }
    },
    { // ST_InstancedPosition3dYUVCxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVCxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVCxform
        }
    },
    { // ST_InstancedPosition3dYUVCxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVCxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVCxformMul
        }
    },
    { // ST_YUVEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVEAlpha
        }
    },
    { // ST_YUVEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVEAlphaMul
        }
    },
    { // ST_BatchYUVEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVEAlpha
        }
    },
    { // ST_BatchYUVEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVEAlphaMul
        }
    },
    { // ST_InstancedYUVEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVEAlpha
        }
    },
    { // ST_InstancedYUVEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVEAlphaMul
        }
    },
    { // ST_Position3dYUVEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVEAlpha
        }
    },
    { // ST_Position3dYUVEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVEAlphaMul
        }
    },
    { // ST_BatchPosition3dYUVEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVEAlpha
        }
    },
    { // ST_BatchPosition3dYUVEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVEAlphaMul
        }
    },
    { // ST_InstancedPosition3dYUVEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVEAlpha
        }
    },
    { // ST_InstancedPosition3dYUVEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVEAlphaMul
        }
    },
    { // ST_YUVCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVCxformEAlpha
        }
    },
    { // ST_YUVCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVCxformEAlphaMul
        }
    },
    { // ST_BatchYUVCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVCxformEAlpha
        }
    },
    { // ST_BatchYUVCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVCxformEAlphaMul
        }
    },
    { // ST_InstancedYUVCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVCxformEAlpha
        }
    },
    { // ST_InstancedYUVCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVCxformEAlphaMul
        }
    },
    { // ST_Position3dYUVCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVCxformEAlpha
        }
    },
    { // ST_Position3dYUVCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVCxformEAlphaMul
        }
    },
    { // ST_BatchPosition3dYUVCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVCxformEAlpha
        }
    },
    { // ST_BatchPosition3dYUVCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVCxformEAlphaMul
        }
    },
    { // ST_InstancedPosition3dYUVCxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVCxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVCxformEAlpha
        }
    },
    { // ST_InstancedPosition3dYUVCxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVCxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVCxformEAlphaMul
        }
    },
    { // ST_YUVCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVCxformAc
        }
    },
    { // ST_YUVCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVCxformAcMul
        }
    },
    { // ST_BatchYUVCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVCxformAc
        }
    },
    { // ST_BatchYUVCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVCxformAcMul
        }
    },
    { // ST_InstancedYUVCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVCxformAc
        }
    },
    { // ST_InstancedYUVCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVCxformAcMul
        }
    },
    { // ST_Position3dYUVCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVCxformAc
        }
    },
    { // ST_Position3dYUVCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVCxformAcMul
        }
    },
    { // ST_BatchPosition3dYUVCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVCxformAc
        }
    },
    { // ST_BatchPosition3dYUVCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVCxformAcMul
        }
    },
    { // ST_InstancedPosition3dYUVCxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVCxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVCxformAc
        }
    },
    { // ST_InstancedPosition3dYUVCxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVCxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVCxformAcMul
        }
    },
    { // ST_YUVCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVCxformAcEAlpha
        }
    },
    { // ST_YUVCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVCxformAcEAlphaMul
        }
    },
    { // ST_BatchYUVCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVCxformAcEAlpha
        }
    },
    { // ST_BatchYUVCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVCxformAcEAlphaMul
        }
    },
    { // ST_InstancedYUVCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVCxformAcEAlpha
        }
    },
    { // ST_InstancedYUVCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVCxformAcEAlphaMul
        }
    },
    { // ST_Position3dYUVCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVCxformAcEAlpha
        }
    },
    { // ST_Position3dYUVCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVCxformAcEAlphaMul
        }
    },
    { // ST_BatchPosition3dYUVCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVCxformAcEAlpha
        }
    },
    { // ST_BatchPosition3dYUVCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVCxformAcEAlphaMul
        }
    },
    { // ST_InstancedPosition3dYUVCxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVCxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVCxformAcEAlpha
        }
    },
    { // ST_InstancedPosition3dYUVCxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVCxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVCxformAcEAlphaMul
        }
    },
    { // ST_YUVA
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVA,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVA
        }
    },
    { // ST_YUVAMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVAMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVAMul
        }
    },
    { // ST_BatchYUVA
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVA,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVA
        }
    },
    { // ST_BatchYUVAMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVAMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVAMul
        }
    },
    { // ST_InstancedYUVA
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVA,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVA
        }
    },
    { // ST_InstancedYUVAMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVAMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVAMul
        }
    },
    { // ST_Position3dYUVA
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVA,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVA
        }
    },
    { // ST_Position3dYUVAMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVAMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVAMul
        }
    },
    { // ST_BatchPosition3dYUVA
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVA,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVA
        }
    },
    { // ST_BatchPosition3dYUVAMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVAMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVAMul
        }
    },
    { // ST_InstancedPosition3dYUVA
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVA,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVA
        }
    },
    { // ST_InstancedPosition3dYUVAMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVAMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVAMul
        }
    },
    { // ST_YUVACxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVACxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVACxform
        }
    },
    { // ST_YUVACxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVACxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVACxformMul
        }
    },
    { // ST_BatchYUVACxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVACxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVACxform
        }
    },
    { // ST_BatchYUVACxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVACxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVACxformMul
        }
    },
    { // ST_InstancedYUVACxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVACxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVACxform
        }
    },
    { // ST_InstancedYUVACxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVACxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVACxformMul
        }
    },
    { // ST_Position3dYUVACxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVACxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVACxform
        }
    },
    { // ST_Position3dYUVACxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVACxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVACxformMul
        }
    },
    { // ST_BatchPosition3dYUVACxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxform
        }
    },
    { // ST_BatchPosition3dYUVACxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxformMul
        }
    },
    { // ST_InstancedPosition3dYUVACxform
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxform,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxform
        }
    },
    { // ST_InstancedPosition3dYUVACxformMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxformMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxformMul
        }
    },
    { // ST_YUVAEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVAEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVAEAlpha
        }
    },
    { // ST_YUVAEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVAEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVAEAlphaMul
        }
    },
    { // ST_BatchYUVAEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVAEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVAEAlpha
        }
    },
    { // ST_BatchYUVAEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVAEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVAEAlphaMul
        }
    },
    { // ST_InstancedYUVAEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVAEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVAEAlpha
        }
    },
    { // ST_InstancedYUVAEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVAEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVAEAlphaMul
        }
    },
    { // ST_Position3dYUVAEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVAEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVAEAlpha
        }
    },
    { // ST_Position3dYUVAEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVAEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVAEAlphaMul
        }
    },
    { // ST_BatchPosition3dYUVAEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVAEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVAEAlpha
        }
    },
    { // ST_BatchPosition3dYUVAEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVAEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVAEAlphaMul
        }
    },
    { // ST_InstancedPosition3dYUVAEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVAEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVAEAlpha
        }
    },
    { // ST_InstancedPosition3dYUVAEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVAEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVAEAlphaMul
        }
    },
    { // ST_YUVACxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVACxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVACxformEAlpha
        }
    },
    { // ST_YUVACxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVACxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVACxformEAlphaMul
        }
    },
    { // ST_BatchYUVACxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVACxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVACxformEAlpha
        }
    },
    { // ST_BatchYUVACxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVACxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVACxformEAlphaMul
        }
    },
    { // ST_InstancedYUVACxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVACxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVACxformEAlpha
        }
    },
    { // ST_InstancedYUVACxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVACxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVACxformEAlphaMul
        }
    },
    { // ST_Position3dYUVACxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVACxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVACxformEAlpha
        }
    },
    { // ST_Position3dYUVACxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVACxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVACxformEAlphaMul
        }
    },
    { // ST_BatchPosition3dYUVACxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxformEAlpha
        }
    },
    { // ST_BatchPosition3dYUVACxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxformEAlphaMul
        }
    },
    { // ST_InstancedPosition3dYUVACxformEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxformEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxformEAlpha
        }
    },
    { // ST_InstancedPosition3dYUVACxformEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxformEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxformEAlphaMul
        }
    },
    { // ST_YUVAInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVAInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVAInv
        }
    },
    { // ST_BatchYUVAInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVAInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVAInv
        }
    },
    { // ST_InstancedYUVAInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVAInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVAInv
        }
    },
    { // ST_Position3dYUVAInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVAInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVAInv
        }
    },
    { // ST_BatchPosition3dYUVAInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVAInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVAInv
        }
    },
    { // ST_InstancedPosition3dYUVAInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVAInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVAInv
        }
    },
    { // ST_YUVACxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVACxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVACxformInv
        }
    },
    { // ST_BatchYUVACxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVACxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVACxformInv
        }
    },
    { // ST_InstancedYUVACxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVACxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVACxformInv
        }
    },
    { // ST_Position3dYUVACxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVACxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVACxformInv
        }
    },
    { // ST_BatchPosition3dYUVACxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxformInv
        }
    },
    { // ST_InstancedPosition3dYUVACxformInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxformInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxformInv
        }
    },
    { // ST_YUVAEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVAEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVAEAlphaInv
        }
    },
    { // ST_BatchYUVAEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVAEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVAEAlphaInv
        }
    },
    { // ST_InstancedYUVAEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVAEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVAEAlphaInv
        }
    },
    { // ST_Position3dYUVAEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVAEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVAEAlphaInv
        }
    },
    { // ST_BatchPosition3dYUVAEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVAEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVAEAlphaInv
        }
    },
    { // ST_InstancedPosition3dYUVAEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVAEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVAEAlphaInv
        }
    },
    { // ST_YUVACxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVACxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVACxformEAlphaInv
        }
    },
    { // ST_BatchYUVACxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVACxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVACxformEAlphaInv
        }
    },
    { // ST_InstancedYUVACxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVACxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVACxformEAlphaInv
        }
    },
    { // ST_Position3dYUVACxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVACxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVACxformEAlphaInv
        }
    },
    { // ST_BatchPosition3dYUVACxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxformEAlphaInv
        }
    },
    { // ST_InstancedPosition3dYUVACxformEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxformEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxformEAlphaInv
        }
    },
    { // ST_YUVACxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVACxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVACxformAc
        }
    },
    { // ST_YUVACxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVACxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVACxformAcMul
        }
    },
    { // ST_BatchYUVACxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVACxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVACxformAc
        }
    },
    { // ST_BatchYUVACxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVACxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVACxformAcMul
        }
    },
    { // ST_InstancedYUVACxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVACxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVACxformAc
        }
    },
    { // ST_InstancedYUVACxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVACxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVACxformAcMul
        }
    },
    { // ST_Position3dYUVACxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVACxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVACxformAc
        }
    },
    { // ST_Position3dYUVACxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVACxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVACxformAcMul
        }
    },
    { // ST_BatchPosition3dYUVACxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxformAc
        }
    },
    { // ST_BatchPosition3dYUVACxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxformAcMul
        }
    },
    { // ST_InstancedPosition3dYUVACxformAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxformAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxformAc
        }
    },
    { // ST_InstancedPosition3dYUVACxformAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxformAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxformAcMul
        }
    },
    { // ST_YUVACxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVACxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVACxformAcEAlpha
        }
    },
    { // ST_YUVACxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVACxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVACxformAcEAlphaMul
        }
    },
    { // ST_BatchYUVACxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVACxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVACxformAcEAlpha
        }
    },
    { // ST_BatchYUVACxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVACxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVACxformAcEAlphaMul
        }
    },
    { // ST_InstancedYUVACxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVACxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVACxformAcEAlpha
        }
    },
    { // ST_InstancedYUVACxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVACxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVACxformAcEAlphaMul
        }
    },
    { // ST_Position3dYUVACxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVACxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVACxformAcEAlpha
        }
    },
    { // ST_Position3dYUVACxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVACxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVACxformAcEAlphaMul
        }
    },
    { // ST_BatchPosition3dYUVACxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxformAcEAlpha
        }
    },
    { // ST_BatchPosition3dYUVACxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxformAcEAlphaMul
        }
    },
    { // ST_InstancedPosition3dYUVACxformAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxformAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxformAcEAlpha
        }
    },
    { // ST_InstancedPosition3dYUVACxformAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxformAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxformAcEAlphaMul
        }
    },
    { // ST_YUVACxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVACxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVACxformAcInv
        }
    },
    { // ST_BatchYUVACxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVACxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVACxformAcInv
        }
    },
    { // ST_InstancedYUVACxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVACxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVACxformAcInv
        }
    },
    { // ST_Position3dYUVACxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVACxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVACxformAcInv
        }
    },
    { // ST_BatchPosition3dYUVACxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxformAcInv
        }
    },
    { // ST_InstancedPosition3dYUVACxformAcInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxformAcInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxformAcInv
        }
    },
    { // ST_YUVACxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VYUVACxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FYUVACxformAcEAlphaInv
        }
    },
    { // ST_BatchYUVACxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchYUVACxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchYUVACxformAcEAlphaInv
        }
    },
    { // ST_InstancedYUVACxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedYUVACxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedYUVACxformAcEAlphaInv
        }
    },
    { // ST_Position3dYUVACxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VPosition3dYUVACxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FPosition3dYUVACxformAcEAlphaInv
        }
    },
    { // ST_BatchPosition3dYUVACxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxformAcEAlphaInv
        }
    },
    { // ST_InstancedPosition3dYUVACxformAcEAlphaInv
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxformAcEAlphaInv,
            FragShaderDesc::FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxformAcEAlphaInv
        }
    },
    { // ST_TexTGCMatrixAc
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGCMatrixAc,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGCMatrixAc
        }
    },
    { // ST_TexTGCMatrixAcMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGCMatrixAcMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGCMatrixAcMul
        }
    },
    { // ST_TexTGCMatrixAcEAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGCMatrixAcEAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGCMatrixAcEAlpha
        }
    },
    { // ST_TexTGCMatrixAcEAlphaMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VTexTGCMatrixAcEAlphaMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FTexTGCMatrixAcEAlphaMul
        }
    },
    { // ST_Box1Blur
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox1Blur,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox1Blur
        }
    },
    { // ST_Box1BlurMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox1BlurMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox1BlurMul
        }
    },
    { // ST_Box2Blur
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2Blur,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2Blur
        }
    },
    { // ST_Box2BlurMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2BlurMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2BlurMul
        }
    },
    { // ST_Box2Shadow
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2Shadow,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2Shadow
        }
    },
    { // ST_Box2ShadowMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2ShadowMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2ShadowMul
        }
    },
    { // ST_Box2ShadowKnockout
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2ShadowKnockout,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2ShadowKnockout
        }
    },
    { // ST_Box2ShadowKnockoutMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2ShadowKnockoutMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2ShadowKnockoutMul
        }
    },
    { // ST_Box2Shadowonly
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2Shadowonly,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2Shadowonly
        }
    },
    { // ST_Box2ShadowonlyMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2ShadowonlyMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2ShadowonlyMul
        }
    },
    { // ST_Box2InnerShadow
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2InnerShadow,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2InnerShadow
        }
    },
    { // ST_Box2InnerShadowMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2InnerShadowMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2InnerShadowMul
        }
    },
    { // ST_Box2InnerShadowKnockout
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2InnerShadowKnockout,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2InnerShadowKnockout
        }
    },
    { // ST_Box2InnerShadowKnockoutMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2InnerShadowKnockoutMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2InnerShadowKnockoutMul
        }
    },
    { // ST_Box2ShadowonlyHighlight
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2ShadowonlyHighlight,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2ShadowonlyHighlight
        }
    },
    { // ST_Box2ShadowonlyHighlightMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2ShadowonlyHighlightMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2ShadowonlyHighlightMul
        }
    },
    { // ST_Box2FullShadowHighlight
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2FullShadowHighlight,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2FullShadowHighlight
        }
    },
    { // ST_Box2FullShadowHighlightMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2FullShadowHighlightMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2FullShadowHighlightMul
        }
    },
    { // ST_Box2InnerShadowHighlight
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2InnerShadowHighlight,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2InnerShadowHighlight
        }
    },
    { // ST_Box2InnerShadowHighlightMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2InnerShadowHighlightMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2InnerShadowHighlightMul
        }
    },
    { // ST_Box2InnerShadowHighlightKnockout
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2InnerShadowHighlightKnockout,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2InnerShadowHighlightKnockout
        }
    },
    { // ST_Box2InnerShadowHighlightKnockoutMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2InnerShadowHighlightKnockoutMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2InnerShadowHighlightKnockoutMul
        }
    },
    { // ST_Box2ShadowHighlight
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2ShadowHighlight,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2ShadowHighlight
        }
    },
    { // ST_Box2ShadowHighlightMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2ShadowHighlightMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2ShadowHighlightMul
        }
    },
    { // ST_Box2ShadowHighlightKnockout
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2ShadowHighlightKnockout,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2ShadowHighlightKnockout
        }
    },
    { // ST_Box2ShadowHighlightKnockoutMul
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VBox2ShadowHighlightKnockoutMul,
            FragShaderDesc::FSI_Vulkan_SPIRV_FBox2ShadowHighlightKnockoutMul
        }
    },
    { // ST_DrawableCopyPixels
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VDrawableCopyPixels,
            FragShaderDesc::FSI_Vulkan_SPIRV_FDrawableCopyPixels
        }
    },
    { // ST_DrawableCopyPixelsNoDestAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VDrawableCopyPixelsNoDestAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FDrawableCopyPixelsNoDestAlpha
        }
    },
    { // ST_DrawableCopyPixelsMergeAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VDrawableCopyPixelsMergeAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FDrawableCopyPixelsMergeAlpha
        }
    },
    { // ST_DrawableCopyPixelsAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VDrawableCopyPixelsAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FDrawableCopyPixelsAlpha
        }
    },
    { // ST_DrawableCopyPixelsAlphaNoDestAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VDrawableCopyPixelsAlphaNoDestAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FDrawableCopyPixelsAlphaNoDestAlpha
        }
    },
    { // ST_DrawableCopyPixelsAlphaMergeAlpha
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VDrawableCopyPixelsAlphaMergeAlpha,
            FragShaderDesc::FSI_Vulkan_SPIRV_FDrawableCopyPixelsAlphaMergeAlpha
        }
    },
    { // ST_DrawableMerge
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VDrawableMerge,
            FragShaderDesc::FSI_Vulkan_SPIRV_FDrawableMerge
        }
    },
    { // ST_DrawableCompare
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VDrawableCompare,
            FragShaderDesc::FSI_Vulkan_SPIRV_FDrawableCompare
        }
    },
    { // ST_DrawablePaletteMap
        { // ShaderVersion_Vulkan_SPIRV
            VertexShaderDesc::VSI_Vulkan_SPIRV_VDrawablePaletteMap,
            FragShaderDesc::FSI_Vulkan_SPIRV_FDrawablePaletteMap
        }
    },
};
extern const unsigned char pBinary_Vulkan_SPIRV_VTexTG[];
extern unsigned pBinary_Vulkan_SPIRV_VTexTG_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VTexTGEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VTexTGEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VTexTGCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VTexTGCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VTexTGCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VTexTGCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VVertex[];
extern unsigned pBinary_Vulkan_SPIRV_VVertex_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VVertexEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VVertexEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VVertexCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VVertexCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VVertexCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VVertexCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VTexTGTexTG[];
extern unsigned pBinary_Vulkan_SPIRV_VTexTGTexTG_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VTexTGTexTGCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VTexTGTexTGCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VTexTGVertex[];
extern unsigned pBinary_Vulkan_SPIRV_VTexTGVertex_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VTexTGVertexCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VTexTGVertexCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VPosition3dTexTG[];
extern unsigned pBinary_Vulkan_SPIRV_VPosition3dTexTG_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VPosition3dTexTGEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VPosition3dTexTGEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VPosition3dTexTGCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VPosition3dTexTGCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VPosition3dTexTGCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VPosition3dTexTGCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VPosition3dVertex[];
extern unsigned pBinary_Vulkan_SPIRV_VPosition3dVertex_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VPosition3dVertexEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VPosition3dVertexEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VPosition3dVertexCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VPosition3dVertexCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VPosition3dVertexCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VPosition3dVertexCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VPosition3dTexTGTexTG[];
extern unsigned pBinary_Vulkan_SPIRV_VPosition3dTexTGTexTG_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VPosition3dTexTGTexTGCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VPosition3dTexTGTexTGCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VPosition3dTexTGVertex[];
extern unsigned pBinary_Vulkan_SPIRV_VPosition3dTexTGVertex_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VPosition3dTexTGVertexCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VPosition3dTexTGVertexCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchTexTG[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchTexTG_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchTexTGEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchTexTGEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchTexTGCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchTexTGCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchTexTGCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchTexTGCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchVertex[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchVertex_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchVertexEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchVertexEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchVertexCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchVertexCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchVertexCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchVertexCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchTexTGTexTG[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchTexTGTexTG_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchTexTGTexTGCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchTexTGTexTGCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchTexTGVertex[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchTexTGVertex_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchTexTGVertexCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchTexTGVertexCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchPosition3dTexTG[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchPosition3dTexTG_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchPosition3dVertex[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchPosition3dVertex_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchPosition3dVertexEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchPosition3dVertexEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchPosition3dVertexCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchPosition3dVertexCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchPosition3dVertexCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchPosition3dVertexCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGTexTG[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGTexTG_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGVertex[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGVertex_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedTexTG[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedTexTG_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedTexTGEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedTexTGEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedTexTGCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedTexTGCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedTexTGCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedTexTGCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedVertex[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedVertex_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedVertexEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedVertexEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedVertexCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedVertexCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedVertexCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedVertexCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedTexTGTexTG[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedTexTGTexTG_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedTexTGTexTGCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedTexTGTexTGCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedTexTGVertex[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedTexTGVertex_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedTexTGVertexCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedTexTGVertexCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTG[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTG_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedPosition3dVertex[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedPosition3dVertex_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedPosition3dVertexEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedPosition3dVertexEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedPosition3dVertexCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedPosition3dVertexCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedPosition3dVertexCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedPosition3dVertexCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTG[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTG_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGVertex[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGVertex_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VSolid[];
extern unsigned pBinary_Vulkan_SPIRV_VSolid_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VText[];
extern unsigned pBinary_Vulkan_SPIRV_VText_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VTextColor[];
extern unsigned pBinary_Vulkan_SPIRV_VTextColor_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VTextColorCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VTextColorCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VPosition3dSolid[];
extern unsigned pBinary_Vulkan_SPIRV_VPosition3dSolid_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VPosition3dText[];
extern unsigned pBinary_Vulkan_SPIRV_VPosition3dText_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VPosition3dTextColor[];
extern unsigned pBinary_Vulkan_SPIRV_VPosition3dTextColor_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VPosition3dTextColorCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VPosition3dTextColorCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchSolid[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchSolid_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchText[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchText_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchTextColor[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchTextColor_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchTextColorCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchTextColorCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchPosition3dSolid[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchPosition3dSolid_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchPosition3dText[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchPosition3dText_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchPosition3dTextColor[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchPosition3dTextColor_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VBatchPosition3dTextColorCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VBatchPosition3dTextColorCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedSolid[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedSolid_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedText[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedText_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedTextColor[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedTextColor_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedTextColorCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedTextColorCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedPosition3dSolid[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedPosition3dSolid_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedPosition3dText[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedPosition3dText_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedPosition3dTextColor[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedPosition3dTextColor_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VInstancedPosition3dTextColorCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VInstancedPosition3dTextColorCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VTexTGCxform[];
extern unsigned pBinary_Vulkan_SPIRV_VTexTGCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VDrawableCopyPixels[];
extern unsigned pBinary_Vulkan_SPIRV_VDrawableCopyPixels_size;
extern const unsigned char pBinary_Vulkan_SPIRV_VDrawableCopyPixelsAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_VDrawableCopyPixelsAlpha_size;

UniformVar Uniforms_4834520059[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        {0, 0, 4, 8, 4, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        { -1, 0, 0, 0, 0, 0 },
    /* texgen*/     {2, 8, 4, 8, 4, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

BatchVar BatchUniforms_5760312302[Uniform::SU_Count] = 
{
    /* cxadd*/       {Uniform::SU_Count, -1, 0},
    /* cxmul*/       {Uniform::SU_Count, -1, 0},
    /* cxmul1*/      {Uniform::SU_Count, -1, 0},
    /* fsize*/       {Uniform::SU_Count, -1, 0},
    /* mvp*/         {Uniform::SU_Count, -1, 0},
    /* offset*/      {Uniform::SU_Count, -1, 0},
    /* scolor*/      {Uniform::SU_Count, -1, 0},
    /* scolor2*/     {Uniform::SU_Count, -1, 0},
    /* srctex*/      {Uniform::SU_Count, -1, 0},
    /* srctexscale*/ {Uniform::SU_Count, -1, 0},
    /* tex*/         {Uniform::SU_Count, -1, 0},
    /* texgen*/      {Uniform::SU_Count, -1, 0},
    /* texscale*/    {Uniform::SU_Count, -1, 0},
    /* vfmuniforms*/ {Uniform::SU_Count, -1, 0},
    /* vfuniforms*/  {Uniform::SU_Count, -1, 0},
};

UniformVar Uniforms_4798601671[Uniform::SU_Count] = 
{
    /* cxadd*/      {0, 0, 4, 4, 4, 0 },
    /* cxmul*/      {1, 4, 4, 4, 4, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        {2, 8, 4, 8, 4, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        { -1, 0, 0, 0, 0, 0 },
    /* texgen*/     {4, 16, 4, 8, 4, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_4910843176[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        {0, 0, 4, 8, 4, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        { -1, 0, 0, 0, 0, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_2165884133[Uniform::SU_Count] = 
{
    /* cxadd*/      {0, 0, 4, 4, 4, 0 },
    /* cxmul*/      {1, 4, 4, 4, 4, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        {2, 8, 4, 8, 4, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        { -1, 0, 0, 0, 0, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_5005424478[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        {0, 0, 4, 8, 4, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        { -1, 0, 0, 0, 0, 0 },
    /* texgen*/     {2, 8, 4, 16, 4, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_5693773741[Uniform::SU_Count] = 
{
    /* cxadd*/      {0, 0, 4, 4, 4, 0 },
    /* cxmul*/      {1, 4, 4, 4, 4, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        {2, 8, 4, 8, 4, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        { -1, 0, 0, 0, 0, 0 },
    /* texgen*/     {4, 16, 4, 16, 4, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_5966751480[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        {0, 0, 16, 16, 16, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        { -1, 0, 0, 0, 0, 0 },
    /* texgen*/     {4, 16, 4, 8, 4, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_2839550548[Uniform::SU_Count] = 
{
    /* cxadd*/      {0, 0, 4, 4, 4, 0 },
    /* cxmul*/      {1, 4, 4, 4, 4, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        {2, 8, 16, 16, 16, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        { -1, 0, 0, 0, 0, 0 },
    /* texgen*/     {6, 24, 4, 8, 4, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_4126105233[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        {0, 0, 16, 16, 16, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        { -1, 0, 0, 0, 0, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_2694611255[Uniform::SU_Count] = 
{
    /* cxadd*/      {0, 0, 4, 4, 4, 0 },
    /* cxmul*/      {1, 4, 4, 4, 4, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        {2, 8, 16, 16, 16, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        { -1, 0, 0, 0, 0, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_2757169187[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        {0, 0, 16, 16, 16, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        { -1, 0, 0, 0, 0, 0 },
    /* texgen*/     {4, 16, 4, 16, 4, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_4879531607[Uniform::SU_Count] = 
{
    /* cxadd*/      {0, 0, 4, 4, 4, 0 },
    /* cxmul*/      {1, 4, 4, 4, 4, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        {2, 8, 16, 16, 16, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        { -1, 0, 0, 0, 0, 0 },
    /* texgen*/     {6, 24, 4, 16, 4, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_5641797269[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        { -1, 0, 0, 0, 0, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        { -1, 0, 0, 0, 0, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ {0, 0, 4, 384, 4, 4 },
};

BatchVar BatchUniforms_3174165922[Uniform::SU_Count] = 
{
    /* cxadd*/       {Uniform::SU_Count, -1, 0},
    /* cxmul*/       {Uniform::SU_Count, -1, 0},
    /* cxmul1*/      {Uniform::SU_Count, -1, 0},
    /* fsize*/       {Uniform::SU_Count, -1, 0},
    /* mvp*/         {Uniform::SU_vfuniforms, 0, 2},
    /* offset*/      {Uniform::SU_Count, -1, 0},
    /* scolor*/      {Uniform::SU_Count, -1, 0},
    /* scolor2*/     {Uniform::SU_Count, -1, 0},
    /* srctex*/      {Uniform::SU_Count, -1, 0},
    /* srctexscale*/ {Uniform::SU_Count, -1, 0},
    /* tex*/         {Uniform::SU_Count, -1, 0},
    /* texgen*/      {Uniform::SU_vfuniforms, 2, 2},
    /* texscale*/    {Uniform::SU_Count, -1, 0},
    /* vfmuniforms*/ {Uniform::SU_Count, -1, 0},
    /* vfuniforms*/  {Uniform::SU_Count, -1, 0},
};

UniformVar Uniforms_3934214817[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        { -1, 0, 0, 0, 0, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        { -1, 0, 0, 0, 0, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ {0, 0, 4, 576, 4, 6 },
};

BatchVar BatchUniforms_2370119729[Uniform::SU_Count] = 
{
    /* cxadd*/       {Uniform::SU_vfuniforms, 0, 1},
    /* cxmul*/       {Uniform::SU_vfuniforms, 1, 1},
    /* cxmul1*/      {Uniform::SU_Count, -1, 0},
    /* fsize*/       {Uniform::SU_Count, -1, 0},
    /* mvp*/         {Uniform::SU_vfuniforms, 2, 2},
    /* offset*/      {Uniform::SU_Count, -1, 0},
    /* scolor*/      {Uniform::SU_Count, -1, 0},
    /* scolor2*/     {Uniform::SU_Count, -1, 0},
    /* srctex*/      {Uniform::SU_Count, -1, 0},
    /* srctexscale*/ {Uniform::SU_Count, -1, 0},
    /* tex*/         {Uniform::SU_Count, -1, 0},
    /* texgen*/      {Uniform::SU_vfuniforms, 4, 2},
    /* texscale*/    {Uniform::SU_Count, -1, 0},
    /* vfmuniforms*/ {Uniform::SU_Count, -1, 0},
    /* vfuniforms*/  {Uniform::SU_Count, -1, 0},
};

UniformVar Uniforms_3528194288[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        { -1, 0, 0, 0, 0, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        { -1, 0, 0, 0, 0, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ {0, 0, 4, 192, 4, 2 },
};

BatchVar BatchUniforms_3278392193[Uniform::SU_Count] = 
{
    /* cxadd*/       {Uniform::SU_Count, -1, 0},
    /* cxmul*/       {Uniform::SU_Count, -1, 0},
    /* cxmul1*/      {Uniform::SU_Count, -1, 0},
    /* fsize*/       {Uniform::SU_Count, -1, 0},
    /* mvp*/         {Uniform::SU_vfuniforms, 0, 2},
    /* offset*/      {Uniform::SU_Count, -1, 0},
    /* scolor*/      {Uniform::SU_Count, -1, 0},
    /* scolor2*/     {Uniform::SU_Count, -1, 0},
    /* srctex*/      {Uniform::SU_Count, -1, 0},
    /* srctexscale*/ {Uniform::SU_Count, -1, 0},
    /* tex*/         {Uniform::SU_Count, -1, 0},
    /* texgen*/      {Uniform::SU_Count, -1, 0},
    /* texscale*/    {Uniform::SU_Count, -1, 0},
    /* vfmuniforms*/ {Uniform::SU_Count, -1, 0},
    /* vfuniforms*/  {Uniform::SU_Count, -1, 0},
};

BatchVar BatchUniforms_2201785903[Uniform::SU_Count] = 
{
    /* cxadd*/       {Uniform::SU_vfuniforms, 0, 1},
    /* cxmul*/       {Uniform::SU_vfuniforms, 1, 1},
    /* cxmul1*/      {Uniform::SU_Count, -1, 0},
    /* fsize*/       {Uniform::SU_Count, -1, 0},
    /* mvp*/         {Uniform::SU_vfuniforms, 2, 2},
    /* offset*/      {Uniform::SU_Count, -1, 0},
    /* scolor*/      {Uniform::SU_Count, -1, 0},
    /* scolor2*/     {Uniform::SU_Count, -1, 0},
    /* srctex*/      {Uniform::SU_Count, -1, 0},
    /* srctexscale*/ {Uniform::SU_Count, -1, 0},
    /* tex*/         {Uniform::SU_Count, -1, 0},
    /* texgen*/      {Uniform::SU_Count, -1, 0},
    /* texscale*/    {Uniform::SU_Count, -1, 0},
    /* vfmuniforms*/ {Uniform::SU_Count, -1, 0},
    /* vfuniforms*/  {Uniform::SU_Count, -1, 0},
};

BatchVar BatchUniforms_4516612420[Uniform::SU_Count] = 
{
    /* cxadd*/       {Uniform::SU_Count, -1, 0},
    /* cxmul*/       {Uniform::SU_Count, -1, 0},
    /* cxmul1*/      {Uniform::SU_Count, -1, 0},
    /* fsize*/       {Uniform::SU_Count, -1, 0},
    /* mvp*/         {Uniform::SU_vfuniforms, 0, 2},
    /* offset*/      {Uniform::SU_Count, -1, 0},
    /* scolor*/      {Uniform::SU_Count, -1, 0},
    /* scolor2*/     {Uniform::SU_Count, -1, 0},
    /* srctex*/      {Uniform::SU_Count, -1, 0},
    /* srctexscale*/ {Uniform::SU_Count, -1, 0},
    /* tex*/         {Uniform::SU_Count, -1, 0},
    /* texgen*/      {Uniform::SU_vfuniforms, 2, 4},
    /* texscale*/    {Uniform::SU_Count, -1, 0},
    /* vfmuniforms*/ {Uniform::SU_Count, -1, 0},
    /* vfuniforms*/  {Uniform::SU_Count, -1, 0},
};

UniformVar Uniforms_4095865075[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        { -1, 0, 0, 0, 0, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        { -1, 0, 0, 0, 0, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ {0, 0, 4, 768, 4, 8 },
};

BatchVar BatchUniforms_4647725012[Uniform::SU_Count] = 
{
    /* cxadd*/       {Uniform::SU_vfuniforms, 0, 1},
    /* cxmul*/       {Uniform::SU_vfuniforms, 1, 1},
    /* cxmul1*/      {Uniform::SU_Count, -1, 0},
    /* fsize*/       {Uniform::SU_Count, -1, 0},
    /* mvp*/         {Uniform::SU_vfuniforms, 2, 2},
    /* offset*/      {Uniform::SU_Count, -1, 0},
    /* scolor*/      {Uniform::SU_Count, -1, 0},
    /* scolor2*/     {Uniform::SU_Count, -1, 0},
    /* srctex*/      {Uniform::SU_Count, -1, 0},
    /* srctexscale*/ {Uniform::SU_Count, -1, 0},
    /* tex*/         {Uniform::SU_Count, -1, 0},
    /* texgen*/      {Uniform::SU_vfuniforms, 4, 4},
    /* texscale*/    {Uniform::SU_Count, -1, 0},
    /* vfmuniforms*/ {Uniform::SU_Count, -1, 0},
    /* vfuniforms*/  {Uniform::SU_Count, -1, 0},
};

UniformVar Uniforms_4481420780[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        { -1, 0, 0, 0, 0, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        { -1, 0, 0, 0, 0, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{0, 0, 16, 384, 16, 1 },
    /* vfuniforms*/ {96, 384, 4, 192, 4, 2 },
};

BatchVar BatchUniforms_3714320287[Uniform::SU_Count] = 
{
    /* cxadd*/       {Uniform::SU_Count, -1, 0},
    /* cxmul*/       {Uniform::SU_Count, -1, 0},
    /* cxmul1*/      {Uniform::SU_Count, -1, 0},
    /* fsize*/       {Uniform::SU_Count, -1, 0},
    /* mvp*/         {Uniform::SU_vfmuniforms, 0, 1},
    /* offset*/      {Uniform::SU_Count, -1, 0},
    /* scolor*/      {Uniform::SU_Count, -1, 0},
    /* scolor2*/     {Uniform::SU_Count, -1, 0},
    /* srctex*/      {Uniform::SU_Count, -1, 0},
    /* srctexscale*/ {Uniform::SU_Count, -1, 0},
    /* tex*/         {Uniform::SU_Count, -1, 0},
    /* texgen*/      {Uniform::SU_vfuniforms, 0, 2},
    /* texscale*/    {Uniform::SU_Count, -1, 0},
    /* vfmuniforms*/ {Uniform::SU_Count, -1, 0},
    /* vfuniforms*/  {Uniform::SU_Count, -1, 0},
};

UniformVar Uniforms_5783854052[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        { -1, 0, 0, 0, 0, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        { -1, 0, 0, 0, 0, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{0, 0, 16, 384, 16, 1 },
    /* vfuniforms*/ {96, 384, 4, 384, 4, 4 },
};

BatchVar BatchUniforms_3271918611[Uniform::SU_Count] = 
{
    /* cxadd*/       {Uniform::SU_vfuniforms, 0, 1},
    /* cxmul*/       {Uniform::SU_vfuniforms, 1, 1},
    /* cxmul1*/      {Uniform::SU_Count, -1, 0},
    /* fsize*/       {Uniform::SU_Count, -1, 0},
    /* mvp*/         {Uniform::SU_vfmuniforms, 0, 1},
    /* offset*/      {Uniform::SU_Count, -1, 0},
    /* scolor*/      {Uniform::SU_Count, -1, 0},
    /* scolor2*/     {Uniform::SU_Count, -1, 0},
    /* srctex*/      {Uniform::SU_Count, -1, 0},
    /* srctexscale*/ {Uniform::SU_Count, -1, 0},
    /* tex*/         {Uniform::SU_Count, -1, 0},
    /* texgen*/      {Uniform::SU_vfuniforms, 2, 2},
    /* texscale*/    {Uniform::SU_Count, -1, 0},
    /* vfmuniforms*/ {Uniform::SU_Count, -1, 0},
    /* vfuniforms*/  {Uniform::SU_Count, -1, 0},
};

UniformVar Uniforms_3547624466[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        { -1, 0, 0, 0, 0, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        { -1, 0, 0, 0, 0, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{0, 0, 16, 384, 16, 1 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

BatchVar BatchUniforms_6337609321[Uniform::SU_Count] = 
{
    /* cxadd*/       {Uniform::SU_Count, -1, 0},
    /* cxmul*/       {Uniform::SU_Count, -1, 0},
    /* cxmul1*/      {Uniform::SU_Count, -1, 0},
    /* fsize*/       {Uniform::SU_Count, -1, 0},
    /* mvp*/         {Uniform::SU_vfmuniforms, 0, 1},
    /* offset*/      {Uniform::SU_Count, -1, 0},
    /* scolor*/      {Uniform::SU_Count, -1, 0},
    /* scolor2*/     {Uniform::SU_Count, -1, 0},
    /* srctex*/      {Uniform::SU_Count, -1, 0},
    /* srctexscale*/ {Uniform::SU_Count, -1, 0},
    /* tex*/         {Uniform::SU_Count, -1, 0},
    /* texgen*/      {Uniform::SU_Count, -1, 0},
    /* texscale*/    {Uniform::SU_Count, -1, 0},
    /* vfmuniforms*/ {Uniform::SU_Count, -1, 0},
    /* vfuniforms*/  {Uniform::SU_Count, -1, 0},
};

BatchVar BatchUniforms_6217350677[Uniform::SU_Count] = 
{
    /* cxadd*/       {Uniform::SU_vfuniforms, 0, 1},
    /* cxmul*/       {Uniform::SU_vfuniforms, 1, 1},
    /* cxmul1*/      {Uniform::SU_Count, -1, 0},
    /* fsize*/       {Uniform::SU_Count, -1, 0},
    /* mvp*/         {Uniform::SU_vfmuniforms, 0, 1},
    /* offset*/      {Uniform::SU_Count, -1, 0},
    /* scolor*/      {Uniform::SU_Count, -1, 0},
    /* scolor2*/     {Uniform::SU_Count, -1, 0},
    /* srctex*/      {Uniform::SU_Count, -1, 0},
    /* srctexscale*/ {Uniform::SU_Count, -1, 0},
    /* tex*/         {Uniform::SU_Count, -1, 0},
    /* texgen*/      {Uniform::SU_Count, -1, 0},
    /* texscale*/    {Uniform::SU_Count, -1, 0},
    /* vfmuniforms*/ {Uniform::SU_Count, -1, 0},
    /* vfuniforms*/  {Uniform::SU_Count, -1, 0},
};

BatchVar BatchUniforms_5466834846[Uniform::SU_Count] = 
{
    /* cxadd*/       {Uniform::SU_Count, -1, 0},
    /* cxmul*/       {Uniform::SU_Count, -1, 0},
    /* cxmul1*/      {Uniform::SU_Count, -1, 0},
    /* fsize*/       {Uniform::SU_Count, -1, 0},
    /* mvp*/         {Uniform::SU_vfmuniforms, 0, 1},
    /* offset*/      {Uniform::SU_Count, -1, 0},
    /* scolor*/      {Uniform::SU_Count, -1, 0},
    /* scolor2*/     {Uniform::SU_Count, -1, 0},
    /* srctex*/      {Uniform::SU_Count, -1, 0},
    /* srctexscale*/ {Uniform::SU_Count, -1, 0},
    /* tex*/         {Uniform::SU_Count, -1, 0},
    /* texgen*/      {Uniform::SU_vfuniforms, 0, 4},
    /* texscale*/    {Uniform::SU_Count, -1, 0},
    /* vfmuniforms*/ {Uniform::SU_Count, -1, 0},
    /* vfuniforms*/  {Uniform::SU_Count, -1, 0},
};

UniformVar Uniforms_3555133962[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        { -1, 0, 0, 0, 0, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        { -1, 0, 0, 0, 0, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{0, 0, 16, 384, 16, 1 },
    /* vfuniforms*/ {96, 384, 4, 576, 4, 6 },
};

BatchVar BatchUniforms_3343117772[Uniform::SU_Count] = 
{
    /* cxadd*/       {Uniform::SU_vfuniforms, 0, 1},
    /* cxmul*/       {Uniform::SU_vfuniforms, 1, 1},
    /* cxmul1*/      {Uniform::SU_Count, -1, 0},
    /* fsize*/       {Uniform::SU_Count, -1, 0},
    /* mvp*/         {Uniform::SU_vfmuniforms, 0, 1},
    /* offset*/      {Uniform::SU_Count, -1, 0},
    /* scolor*/      {Uniform::SU_Count, -1, 0},
    /* scolor2*/     {Uniform::SU_Count, -1, 0},
    /* srctex*/      {Uniform::SU_Count, -1, 0},
    /* srctexscale*/ {Uniform::SU_Count, -1, 0},
    /* tex*/         {Uniform::SU_Count, -1, 0},
    /* texgen*/      {Uniform::SU_vfuniforms, 2, 4},
    /* texscale*/    {Uniform::SU_Count, -1, 0},
    /* vfmuniforms*/ {Uniform::SU_Count, -1, 0},
    /* vfuniforms*/  {Uniform::SU_Count, -1, 0},
};

UniformVar Uniforms_4414783507[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        {0, 0, 4, 8, 4, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        { -1, 0, 0, 0, 0, 0 },
    /* texgen*/     {2, 8, 4, 24, 4, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VTexTG = 
{
    /* Type */          ShaderDesc::ST_TexTG,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VTexTG,
    /* pBinary */       pBinary_Vulkan_SPIRV_VTexTG_size,
    /* Uniforms */      Uniforms_4834520059,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    1,
    /* Attributes */    {
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VTexTGEAlpha = 
{
    /* Type */          ShaderDesc::ST_TexTGEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VTexTGEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VTexTGEAlpha_size,
    /* Uniforms */      Uniforms_4834520059,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VTexTGCxform = 
{
    /* Type */          ShaderDesc::ST_TexTGCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VTexTGCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VTexTGCxform_size,
    /* Uniforms */      Uniforms_4798601671,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    1,
    /* Attributes */    {
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VTexTGCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_TexTGCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VTexTGCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VTexTGCxformEAlpha_size,
    /* Uniforms */      Uniforms_4798601671,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VVertex = 
{
    /* Type */          ShaderDesc::ST_Vertex,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VVertex,
    /* pBinary */       pBinary_Vulkan_SPIRV_VVertex_size,
    /* Uniforms */      Uniforms_4910843176,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VVertexEAlpha = 
{
    /* Type */          ShaderDesc::ST_VertexEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VVertexEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VVertexEAlpha_size,
    /* Uniforms */      Uniforms_4910843176,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VVertexCxform = 
{
    /* Type */          ShaderDesc::ST_VertexCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VVertexCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VVertexCxform_size,
    /* Uniforms */      Uniforms_2165884133,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VVertexCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_VertexCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VVertexCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VVertexCxformEAlpha_size,
    /* Uniforms */      Uniforms_2165884133,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VTexTGTexTG = 
{
    /* Type */          ShaderDesc::ST_TexTGTexTG,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VTexTGTexTG,
    /* pBinary */       pBinary_Vulkan_SPIRV_VTexTGTexTG_size,
    /* Uniforms */      Uniforms_5005424478,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VTexTGTexTGCxform = 
{
    /* Type */          ShaderDesc::ST_TexTGTexTGCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VTexTGTexTGCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VTexTGTexTGCxform_size,
    /* Uniforms */      Uniforms_5693773741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VTexTGVertex = 
{
    /* Type */          ShaderDesc::ST_TexTGVertex,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VTexTGVertex,
    /* pBinary */       pBinary_Vulkan_SPIRV_VTexTGVertex_size,
    /* Uniforms */      Uniforms_4834520059,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VTexTGVertexCxform = 
{
    /* Type */          ShaderDesc::ST_TexTGVertexCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VTexTGVertexCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VTexTGVertexCxform_size,
    /* Uniforms */      Uniforms_4798601671,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VPosition3dTexTG = 
{
    /* Type */          ShaderDesc::ST_Position3dTexTG,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dTexTG,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dTexTG_size,
    /* Uniforms */      Uniforms_5966751480,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    1,
    /* Attributes */    {
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VPosition3dTexTGEAlpha = 
{
    /* Type */          ShaderDesc::ST_Position3dTexTGEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dTexTGEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dTexTGEAlpha_size,
    /* Uniforms */      Uniforms_5966751480,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VPosition3dTexTGCxform = 
{
    /* Type */          ShaderDesc::ST_Position3dTexTGCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dTexTGCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dTexTGCxform_size,
    /* Uniforms */      Uniforms_2839550548,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    1,
    /* Attributes */    {
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VPosition3dTexTGCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_Position3dTexTGCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dTexTGCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dTexTGCxformEAlpha_size,
    /* Uniforms */      Uniforms_2839550548,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VPosition3dVertex = 
{
    /* Type */          ShaderDesc::ST_Position3dVertex,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dVertex,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dVertex_size,
    /* Uniforms */      Uniforms_4126105233,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VPosition3dVertexEAlpha = 
{
    /* Type */          ShaderDesc::ST_Position3dVertexEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dVertexEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dVertexEAlpha_size,
    /* Uniforms */      Uniforms_4126105233,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VPosition3dVertexCxform = 
{
    /* Type */          ShaderDesc::ST_Position3dVertexCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dVertexCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dVertexCxform_size,
    /* Uniforms */      Uniforms_2694611255,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VPosition3dVertexCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_Position3dVertexCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dVertexCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dVertexCxformEAlpha_size,
    /* Uniforms */      Uniforms_2694611255,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VPosition3dTexTGTexTG = 
{
    /* Type */          ShaderDesc::ST_Position3dTexTGTexTG,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dTexTGTexTG,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dTexTGTexTG_size,
    /* Uniforms */      Uniforms_2757169187,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VPosition3dTexTGTexTGCxform = 
{
    /* Type */          ShaderDesc::ST_Position3dTexTGTexTGCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dTexTGTexTGCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dTexTGTexTGCxform_size,
    /* Uniforms */      Uniforms_4879531607,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VPosition3dTexTGVertex = 
{
    /* Type */          ShaderDesc::ST_Position3dTexTGVertex,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dTexTGVertex,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dTexTGVertex_size,
    /* Uniforms */      Uniforms_5966751480,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VPosition3dTexTGVertexCxform = 
{
    /* Type */          ShaderDesc::ST_Position3dTexTGVertexCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dTexTGVertexCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dTexTGVertexCxform_size,
    /* Uniforms */      Uniforms_2839550548,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchTexTG = 
{
    /* Type */          ShaderDesc::ST_BatchTexTG,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchTexTG,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchTexTG_size,
    /* Uniforms */      Uniforms_5641797269,
    /* BatchUniforms */ BatchUniforms_3174165922,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "pos",        4 | VET_Pos},
        { "vbatch",     1 | VET_Instance8},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchTexTGEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchTexTGEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchTexTGEAlpha_size,
    /* Uniforms */      Uniforms_5641797269,
    /* BatchUniforms */ BatchUniforms_3174165922,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchTexTGCxform = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchTexTGCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchTexTGCxform_size,
    /* Uniforms */      Uniforms_3934214817,
    /* BatchUniforms */ BatchUniforms_2370119729,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "pos",        4 | VET_Pos},
        { "vbatch",     1 | VET_Instance8},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchTexTGCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchTexTGCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchTexTGCxformEAlpha_size,
    /* Uniforms */      Uniforms_3934214817,
    /* BatchUniforms */ BatchUniforms_2370119729,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchVertex = 
{
    /* Type */          ShaderDesc::ST_BatchVertex,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchVertex,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchVertex_size,
    /* Uniforms */      Uniforms_3528194288,
    /* BatchUniforms */ BatchUniforms_3278392193,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "pos",        4 | VET_Pos},
        { "vbatch",     1 | VET_Instance8},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchVertexEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchVertexEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchVertexEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchVertexEAlpha_size,
    /* Uniforms */      Uniforms_3528194288,
    /* BatchUniforms */ BatchUniforms_3278392193,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchVertexCxform = 
{
    /* Type */          ShaderDesc::ST_BatchVertexCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchVertexCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchVertexCxform_size,
    /* Uniforms */      Uniforms_5641797269,
    /* BatchUniforms */ BatchUniforms_2201785903,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "pos",        4 | VET_Pos},
        { "vbatch",     1 | VET_Instance8},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchVertexCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchVertexCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchVertexCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchVertexCxformEAlpha_size,
    /* Uniforms */      Uniforms_5641797269,
    /* BatchUniforms */ BatchUniforms_2201785903,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchTexTGTexTG = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGTexTG,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchTexTGTexTG,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchTexTGTexTG_size,
    /* Uniforms */      Uniforms_3934214817,
    /* BatchUniforms */ BatchUniforms_4516612420,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchTexTGTexTGCxform = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGTexTGCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchTexTGTexTGCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchTexTGTexTGCxform_size,
    /* Uniforms */      Uniforms_4095865075,
    /* BatchUniforms */ BatchUniforms_4647725012,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchTexTGVertex = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGVertex,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchTexTGVertex,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchTexTGVertex_size,
    /* Uniforms */      Uniforms_5641797269,
    /* BatchUniforms */ BatchUniforms_3174165922,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchTexTGVertexCxform = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGVertexCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchTexTGVertexCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchTexTGVertexCxform_size,
    /* Uniforms */      Uniforms_3934214817,
    /* BatchUniforms */ BatchUniforms_2370119729,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dTexTG = 
{
    /* Type */          ShaderDesc::ST_BatchPosition3dTexTG,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dTexTG,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dTexTG_size,
    /* Uniforms */      Uniforms_4481420780,
    /* BatchUniforms */ BatchUniforms_3714320287,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "pos",        4 | VET_Pos},
        { "vbatch",     1 | VET_Instance8},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dTexTGEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchPosition3dTexTGEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGEAlpha_size,
    /* Uniforms */      Uniforms_4481420780,
    /* BatchUniforms */ BatchUniforms_3714320287,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dTexTGCxform = 
{
    /* Type */          ShaderDesc::ST_BatchPosition3dTexTGCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGCxform_size,
    /* Uniforms */      Uniforms_5783854052,
    /* BatchUniforms */ BatchUniforms_3271918611,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "pos",        4 | VET_Pos},
        { "vbatch",     1 | VET_Instance8},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dTexTGCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchPosition3dTexTGCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGCxformEAlpha_size,
    /* Uniforms */      Uniforms_5783854052,
    /* BatchUniforms */ BatchUniforms_3271918611,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dVertex = 
{
    /* Type */          ShaderDesc::ST_BatchPosition3dVertex,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dVertex,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dVertex_size,
    /* Uniforms */      Uniforms_3547624466,
    /* BatchUniforms */ BatchUniforms_6337609321,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "pos",        4 | VET_Pos},
        { "vbatch",     1 | VET_Instance8},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dVertexEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchPosition3dVertexEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dVertexEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dVertexEAlpha_size,
    /* Uniforms */      Uniforms_3547624466,
    /* BatchUniforms */ BatchUniforms_6337609321,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dVertexCxform = 
{
    /* Type */          ShaderDesc::ST_BatchPosition3dVertexCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dVertexCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dVertexCxform_size,
    /* Uniforms */      Uniforms_4481420780,
    /* BatchUniforms */ BatchUniforms_6217350677,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "pos",        4 | VET_Pos},
        { "vbatch",     1 | VET_Instance8},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dVertexCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchPosition3dVertexCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dVertexCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dVertexCxformEAlpha_size,
    /* Uniforms */      Uniforms_4481420780,
    /* BatchUniforms */ BatchUniforms_6217350677,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dTexTGTexTG = 
{
    /* Type */          ShaderDesc::ST_BatchPosition3dTexTGTexTG,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGTexTG,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGTexTG_size,
    /* Uniforms */      Uniforms_5783854052,
    /* BatchUniforms */ BatchUniforms_5466834846,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxform = 
{
    /* Type */          ShaderDesc::ST_BatchPosition3dTexTGTexTGCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxform_size,
    /* Uniforms */      Uniforms_3555133962,
    /* BatchUniforms */ BatchUniforms_3343117772,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dTexTGVertex = 
{
    /* Type */          ShaderDesc::ST_BatchPosition3dTexTGVertex,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGVertex,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGVertex_size,
    /* Uniforms */      Uniforms_4481420780,
    /* BatchUniforms */ BatchUniforms_3714320287,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxform = 
{
    /* Type */          ShaderDesc::ST_BatchPosition3dTexTGVertexCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxform_size,
    /* Uniforms */      Uniforms_5783854052,
    /* BatchUniforms */ BatchUniforms_3271918611,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedTexTG = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTG,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedTexTG,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedTexTG_size,
    /* Uniforms */      Uniforms_5641797269,
    /* BatchUniforms */ BatchUniforms_3174165922,
    /* NumAttribs */    1,
    /* Attributes */    {
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedTexTGEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedTexTGEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedTexTGEAlpha_size,
    /* Uniforms */      Uniforms_5641797269,
    /* BatchUniforms */ BatchUniforms_3174165922,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedTexTGCxform = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedTexTGCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedTexTGCxform_size,
    /* Uniforms */      Uniforms_3934214817,
    /* BatchUniforms */ BatchUniforms_2370119729,
    /* NumAttribs */    1,
    /* Attributes */    {
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedTexTGCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedTexTGCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedTexTGCxformEAlpha_size,
    /* Uniforms */      Uniforms_3934214817,
    /* BatchUniforms */ BatchUniforms_2370119729,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedVertex = 
{
    /* Type */          ShaderDesc::ST_InstancedVertex,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedVertex,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedVertex_size,
    /* Uniforms */      Uniforms_3528194288,
    /* BatchUniforms */ BatchUniforms_3278392193,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedVertexEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedVertexEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedVertexEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedVertexEAlpha_size,
    /* Uniforms */      Uniforms_3528194288,
    /* BatchUniforms */ BatchUniforms_3278392193,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedVertexCxform = 
{
    /* Type */          ShaderDesc::ST_InstancedVertexCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedVertexCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedVertexCxform_size,
    /* Uniforms */      Uniforms_5641797269,
    /* BatchUniforms */ BatchUniforms_2201785903,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedVertexCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedVertexCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedVertexCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedVertexCxformEAlpha_size,
    /* Uniforms */      Uniforms_5641797269,
    /* BatchUniforms */ BatchUniforms_2201785903,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedTexTGTexTG = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGTexTG,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedTexTGTexTG,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedTexTGTexTG_size,
    /* Uniforms */      Uniforms_3934214817,
    /* BatchUniforms */ BatchUniforms_4516612420,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedTexTGTexTGCxform = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGTexTGCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedTexTGTexTGCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedTexTGTexTGCxform_size,
    /* Uniforms */      Uniforms_4095865075,
    /* BatchUniforms */ BatchUniforms_4647725012,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedTexTGVertex = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGVertex,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedTexTGVertex,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedTexTGVertex_size,
    /* Uniforms */      Uniforms_5641797269,
    /* BatchUniforms */ BatchUniforms_3174165922,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedTexTGVertexCxform = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGVertexCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedTexTGVertexCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedTexTGVertexCxform_size,
    /* Uniforms */      Uniforms_3934214817,
    /* BatchUniforms */ BatchUniforms_2370119729,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dTexTG = 
{
    /* Type */          ShaderDesc::ST_InstancedPosition3dTexTG,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTG,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTG_size,
    /* Uniforms */      Uniforms_4481420780,
    /* BatchUniforms */ BatchUniforms_3714320287,
    /* NumAttribs */    1,
    /* Attributes */    {
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dTexTGEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedPosition3dTexTGEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGEAlpha_size,
    /* Uniforms */      Uniforms_4481420780,
    /* BatchUniforms */ BatchUniforms_3714320287,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dTexTGCxform = 
{
    /* Type */          ShaderDesc::ST_InstancedPosition3dTexTGCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGCxform_size,
    /* Uniforms */      Uniforms_5783854052,
    /* BatchUniforms */ BatchUniforms_3271918611,
    /* NumAttribs */    1,
    /* Attributes */    {
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedPosition3dTexTGCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformEAlpha_size,
    /* Uniforms */      Uniforms_5783854052,
    /* BatchUniforms */ BatchUniforms_3271918611,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dVertex = 
{
    /* Type */          ShaderDesc::ST_InstancedPosition3dVertex,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dVertex,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dVertex_size,
    /* Uniforms */      Uniforms_3547624466,
    /* BatchUniforms */ BatchUniforms_6337609321,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dVertexEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedPosition3dVertexEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dVertexEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dVertexEAlpha_size,
    /* Uniforms */      Uniforms_3547624466,
    /* BatchUniforms */ BatchUniforms_6337609321,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dVertexCxform = 
{
    /* Type */          ShaderDesc::ST_InstancedPosition3dVertexCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dVertexCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dVertexCxform_size,
    /* Uniforms */      Uniforms_4481420780,
    /* BatchUniforms */ BatchUniforms_6217350677,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dVertexCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedPosition3dVertexCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dVertexCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dVertexCxformEAlpha_size,
    /* Uniforms */      Uniforms_4481420780,
    /* BatchUniforms */ BatchUniforms_6217350677,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTG = 
{
    /* Type */          ShaderDesc::ST_InstancedPosition3dTexTGTexTG,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTG,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTG_size,
    /* Uniforms */      Uniforms_5783854052,
    /* BatchUniforms */ BatchUniforms_5466834846,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxform = 
{
    /* Type */          ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxform_size,
    /* Uniforms */      Uniforms_3555133962,
    /* BatchUniforms */ BatchUniforms_3343117772,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dTexTGVertex = 
{
    /* Type */          ShaderDesc::ST_InstancedPosition3dTexTGVertex,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGVertex,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGVertex_size,
    /* Uniforms */      Uniforms_4481420780,
    /* BatchUniforms */ BatchUniforms_3714320287,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxform = 
{
    /* Type */          ShaderDesc::ST_InstancedPosition3dTexTGVertexCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxform_size,
    /* Uniforms */      Uniforms_5783854052,
    /* BatchUniforms */ BatchUniforms_3271918611,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "afactor",    4 | VET_Color | (1 << VET_Index_Shift)},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VSolid = 
{
    /* Type */          ShaderDesc::ST_Solid,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VSolid,
    /* pBinary */       pBinary_Vulkan_SPIRV_VSolid_size,
    /* Uniforms */      Uniforms_4910843176,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    1,
    /* Attributes */    {
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VText = 
{
    /* Type */          ShaderDesc::ST_Text,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VText,
    /* pBinary */       pBinary_Vulkan_SPIRV_VText_size,
    /* Uniforms */      Uniforms_2165884133,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "atc",        2 | VET_TexCoord},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VTextColor = 
{
    /* Type */          ShaderDesc::ST_TextColor,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VTextColor,
    /* pBinary */       pBinary_Vulkan_SPIRV_VTextColor_size,
    /* Uniforms */      Uniforms_4910843176,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "atc",        2 | VET_TexCoord},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VTextColorCxform = 
{
    /* Type */          ShaderDesc::ST_TextColorCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VTextColorCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VTextColorCxform_size,
    /* Uniforms */      Uniforms_2165884133,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "atc",        2 | VET_TexCoord},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VPosition3dSolid = 
{
    /* Type */          ShaderDesc::ST_Position3dSolid,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dSolid,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dSolid_size,
    /* Uniforms */      Uniforms_4126105233,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    1,
    /* Attributes */    {
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VPosition3dText = 
{
    /* Type */          ShaderDesc::ST_Position3dText,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dText,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dText_size,
    /* Uniforms */      Uniforms_2694611255,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "atc",        2 | VET_TexCoord},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VPosition3dTextColor = 
{
    /* Type */          ShaderDesc::ST_Position3dTextColor,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dTextColor,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dTextColor_size,
    /* Uniforms */      Uniforms_4126105233,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "atc",        2 | VET_TexCoord},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VPosition3dTextColorCxform = 
{
    /* Type */          ShaderDesc::ST_Position3dTextColorCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dTextColorCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VPosition3dTextColorCxform_size,
    /* Uniforms */      Uniforms_2694611255,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "atc",        2 | VET_TexCoord},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchSolid = 
{
    /* Type */          ShaderDesc::ST_BatchSolid,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchSolid,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchSolid_size,
    /* Uniforms */      Uniforms_3528194288,
    /* BatchUniforms */ BatchUniforms_3278392193,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "pos",        4 | VET_Pos},
        { "vbatch",     1 | VET_Instance8},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchText = 
{
    /* Type */          ShaderDesc::ST_BatchText,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchText,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchText_size,
    /* Uniforms */      Uniforms_5641797269,
    /* BatchUniforms */ BatchUniforms_2201785903,
    /* NumAttribs */    4,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "atc",        2 | VET_TexCoord},
        { "pos",        4 | VET_Pos},
        { "vbatch",     1 | VET_Instance8},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchTextColor = 
{
    /* Type */          ShaderDesc::ST_BatchTextColor,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchTextColor,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchTextColor_size,
    /* Uniforms */      Uniforms_3528194288,
    /* BatchUniforms */ BatchUniforms_3278392193,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "atc",        2 | VET_TexCoord},
        { "pos",        4 | VET_Pos},
        { "vbatch",     1 | VET_Instance8},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchTextColorCxform = 
{
    /* Type */          ShaderDesc::ST_BatchTextColorCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchTextColorCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchTextColorCxform_size,
    /* Uniforms */      Uniforms_5641797269,
    /* BatchUniforms */ BatchUniforms_2201785903,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "atc",        2 | VET_TexCoord},
        { "pos",        4 | VET_Pos},
        { "vbatch",     1 | VET_Instance8},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dSolid = 
{
    /* Type */          ShaderDesc::ST_BatchPosition3dSolid,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dSolid,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dSolid_size,
    /* Uniforms */      Uniforms_3547624466,
    /* BatchUniforms */ BatchUniforms_6337609321,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "pos",        4 | VET_Pos},
        { "vbatch",     1 | VET_Instance8},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dText = 
{
    /* Type */          ShaderDesc::ST_BatchPosition3dText,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dText,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dText_size,
    /* Uniforms */      Uniforms_4481420780,
    /* BatchUniforms */ BatchUniforms_6217350677,
    /* NumAttribs */    4,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "atc",        2 | VET_TexCoord},
        { "pos",        4 | VET_Pos},
        { "vbatch",     1 | VET_Instance8},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dTextColor = 
{
    /* Type */          ShaderDesc::ST_BatchPosition3dTextColor,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dTextColor,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dTextColor_size,
    /* Uniforms */      Uniforms_3547624466,
    /* BatchUniforms */ BatchUniforms_6337609321,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "atc",        2 | VET_TexCoord},
        { "pos",        4 | VET_Pos},
        { "vbatch",     1 | VET_Instance8},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dTextColorCxform = 
{
    /* Type */          ShaderDesc::ST_BatchPosition3dTextColorCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dTextColorCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VBatchPosition3dTextColorCxform_size,
    /* Uniforms */      Uniforms_4481420780,
    /* BatchUniforms */ BatchUniforms_6217350677,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "atc",        2 | VET_TexCoord},
        { "pos",        4 | VET_Pos},
        { "vbatch",     1 | VET_Instance8},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedSolid = 
{
    /* Type */          ShaderDesc::ST_InstancedSolid,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedSolid,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedSolid_size,
    /* Uniforms */      Uniforms_3528194288,
    /* BatchUniforms */ BatchUniforms_3278392193,
    /* NumAttribs */    1,
    /* Attributes */    {
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedText = 
{
    /* Type */          ShaderDesc::ST_InstancedText,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedText,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedText_size,
    /* Uniforms */      Uniforms_5641797269,
    /* BatchUniforms */ BatchUniforms_2201785903,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "atc",        2 | VET_TexCoord},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedTextColor = 
{
    /* Type */          ShaderDesc::ST_InstancedTextColor,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedTextColor,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedTextColor_size,
    /* Uniforms */      Uniforms_3528194288,
    /* BatchUniforms */ BatchUniforms_3278392193,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "atc",        2 | VET_TexCoord},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedTextColorCxform = 
{
    /* Type */          ShaderDesc::ST_InstancedTextColorCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedTextColorCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedTextColorCxform_size,
    /* Uniforms */      Uniforms_5641797269,
    /* BatchUniforms */ BatchUniforms_2201785903,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "atc",        2 | VET_TexCoord},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dSolid = 
{
    /* Type */          ShaderDesc::ST_InstancedPosition3dSolid,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dSolid,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dSolid_size,
    /* Uniforms */      Uniforms_3547624466,
    /* BatchUniforms */ BatchUniforms_6337609321,
    /* NumAttribs */    1,
    /* Attributes */    {
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dText = 
{
    /* Type */          ShaderDesc::ST_InstancedPosition3dText,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dText,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dText_size,
    /* Uniforms */      Uniforms_4481420780,
    /* BatchUniforms */ BatchUniforms_6217350677,
    /* NumAttribs */    3,
    /* Attributes */    {
        { "acolor",     4 | VET_Color},
        { "atc",        2 | VET_TexCoord},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dTextColor = 
{
    /* Type */          ShaderDesc::ST_InstancedPosition3dTextColor,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dTextColor,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dTextColor_size,
    /* Uniforms */      Uniforms_3547624466,
    /* BatchUniforms */ BatchUniforms_6337609321,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "atc",        2 | VET_TexCoord},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dTextColorCxform = 
{
    /* Type */          ShaderDesc::ST_InstancedPosition3dTextColorCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dTextColorCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VInstancedPosition3dTextColorCxform_size,
    /* Uniforms */      Uniforms_4481420780,
    /* BatchUniforms */ BatchUniforms_6217350677,
    /* NumAttribs */    2,
    /* Attributes */    {
        { "atc",        2 | VET_TexCoord},
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VBox1Blur = 
{
    /* Type */          ShaderDesc::ST_Box1Blur,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_VTexTGCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_VTexTGCxform_size,
    /* Uniforms */      Uniforms_4798601671,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    1,
    /* Attributes */    {
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VDrawableCopyPixels = 
{
    /* Type */          ShaderDesc::ST_DrawableCopyPixels,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VDrawableCopyPixels,
    /* pBinary */       pBinary_Vulkan_SPIRV_VDrawableCopyPixels_size,
    /* Uniforms */      Uniforms_5005424478,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    1,
    /* Attributes */    {
        { "pos",        4 | VET_Pos},
    },
    
};

static VertexShaderDesc ShaderDesc_VS_Vulkan_SPIRV_VDrawableCopyPixelsAlpha = 
{
    /* Type */          ShaderDesc::ST_DrawableCopyPixelsAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_VDrawableCopyPixelsAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_VDrawableCopyPixelsAlpha_size,
    /* Uniforms */      Uniforms_4414783507,
    /* BatchUniforms */ BatchUniforms_5760312302,
    /* NumAttribs */    1,
    /* Attributes */    {
        { "pos",        4 | VET_Pos},
    },
    
};

const VertexShaderDesc* VertexShaderDesc::Descs[VSI_Count] = {
    0,
    &ShaderDesc_VS_Vulkan_SPIRV_VTexTG,                          // 1
    &ShaderDesc_VS_Vulkan_SPIRV_VTexTGEAlpha,                    // 2
    &ShaderDesc_VS_Vulkan_SPIRV_VTexTGCxform,                    // 3
    &ShaderDesc_VS_Vulkan_SPIRV_VTexTGCxformEAlpha,              // 4
    &ShaderDesc_VS_Vulkan_SPIRV_VVertex,                         // 5
    &ShaderDesc_VS_Vulkan_SPIRV_VVertexEAlpha,                   // 6
    &ShaderDesc_VS_Vulkan_SPIRV_VVertexCxform,                   // 7
    &ShaderDesc_VS_Vulkan_SPIRV_VVertexCxformEAlpha,             // 8
    &ShaderDesc_VS_Vulkan_SPIRV_VTexTGTexTG,                     // 9
    &ShaderDesc_VS_Vulkan_SPIRV_VTexTGTexTGCxform,               // 10
    &ShaderDesc_VS_Vulkan_SPIRV_VTexTGVertex,                    // 11
    &ShaderDesc_VS_Vulkan_SPIRV_VTexTGVertexCxform,              // 12
    &ShaderDesc_VS_Vulkan_SPIRV_VPosition3dTexTG,                // 13
    &ShaderDesc_VS_Vulkan_SPIRV_VPosition3dTexTGEAlpha,          // 14
    &ShaderDesc_VS_Vulkan_SPIRV_VPosition3dTexTGCxform,          // 15
    &ShaderDesc_VS_Vulkan_SPIRV_VPosition3dTexTGCxformEAlpha,    // 16
    &ShaderDesc_VS_Vulkan_SPIRV_VPosition3dVertex,               // 17
    &ShaderDesc_VS_Vulkan_SPIRV_VPosition3dVertexEAlpha,         // 18
    &ShaderDesc_VS_Vulkan_SPIRV_VPosition3dVertexCxform,         // 19
    &ShaderDesc_VS_Vulkan_SPIRV_VPosition3dVertexCxformEAlpha,   // 20
    &ShaderDesc_VS_Vulkan_SPIRV_VPosition3dTexTGTexTG,           // 21
    &ShaderDesc_VS_Vulkan_SPIRV_VPosition3dTexTGTexTGCxform,     // 22
    &ShaderDesc_VS_Vulkan_SPIRV_VPosition3dTexTGVertex,          // 23
    &ShaderDesc_VS_Vulkan_SPIRV_VPosition3dTexTGVertexCxform,    // 24
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchTexTG,                     // 25
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchTexTGEAlpha,               // 26
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchTexTGCxform,               // 27
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchTexTGCxformEAlpha,         // 28
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchVertex,                    // 29
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchVertexEAlpha,              // 30
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchVertexCxform,              // 31
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchVertexCxformEAlpha,        // 32
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchTexTGTexTG,                // 33
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchTexTGTexTGCxform,          // 34
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchTexTGVertex,               // 35
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchTexTGVertexCxform,         // 36
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dTexTG,           // 37
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dTexTGEAlpha,     // 38
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dTexTGCxform,     // 39
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dTexTGCxformEAlpha, // 40
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dVertex,          // 41
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dVertexEAlpha,    // 42
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dVertexCxform,    // 43
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dVertexCxformEAlpha, // 44
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dTexTGTexTG,      // 45
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxform, // 46
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dTexTGVertex,     // 47
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxform, // 48
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedTexTG,                 // 49
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedTexTGEAlpha,           // 50
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedTexTGCxform,           // 51
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedTexTGCxformEAlpha,     // 52
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedVertex,                // 53
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedVertexEAlpha,          // 54
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedVertexCxform,          // 55
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedVertexCxformEAlpha,    // 56
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedTexTGTexTG,            // 57
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedTexTGTexTGCxform,      // 58
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedTexTGVertex,           // 59
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedTexTGVertexCxform,     // 60
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dTexTG,       // 61
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dTexTGEAlpha, // 62
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dTexTGCxform, // 63
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformEAlpha, // 64
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dVertex,      // 65
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dVertexEAlpha, // 66
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dVertexCxform, // 67
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dVertexCxformEAlpha, // 68
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTG,  // 69
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxform, // 70
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dTexTGVertex, // 71
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxform, // 72
    &ShaderDesc_VS_Vulkan_SPIRV_VSolid,                          // 73
    &ShaderDesc_VS_Vulkan_SPIRV_VText,                           // 74
    &ShaderDesc_VS_Vulkan_SPIRV_VTextColor,                      // 75
    &ShaderDesc_VS_Vulkan_SPIRV_VTextColorCxform,                // 76
    &ShaderDesc_VS_Vulkan_SPIRV_VPosition3dSolid,                // 77
    &ShaderDesc_VS_Vulkan_SPIRV_VPosition3dText,                 // 78
    &ShaderDesc_VS_Vulkan_SPIRV_VPosition3dTextColor,            // 79
    &ShaderDesc_VS_Vulkan_SPIRV_VPosition3dTextColorCxform,      // 80
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchSolid,                     // 81
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchText,                      // 82
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchTextColor,                 // 83
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchTextColorCxform,           // 84
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dSolid,           // 85
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dText,            // 86
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dTextColor,       // 87
    &ShaderDesc_VS_Vulkan_SPIRV_VBatchPosition3dTextColorCxform, // 88
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedSolid,                 // 89
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedText,                  // 90
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedTextColor,             // 91
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedTextColorCxform,       // 92
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dSolid,       // 93
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dText,        // 94
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dTextColor,   // 95
    &ShaderDesc_VS_Vulkan_SPIRV_VInstancedPosition3dTextColorCxform, // 96
    &ShaderDesc_VS_Vulkan_SPIRV_VBox1Blur,                       // 97
    &ShaderDesc_VS_Vulkan_SPIRV_VDrawableCopyPixels,             // 98
    &ShaderDesc_VS_Vulkan_SPIRV_VDrawableCopyPixelsAlpha,        // 99
};

const VertexShaderDesc* VertexShaderDesc::GetDesc(ShaderDesc::ShaderType shader, ShaderDesc::ShaderVersion ver)
{
    return Descs[GetShaderIndex(shader, ver)];
};

VertexShaderDesc::ShaderIndex VertexShaderDesc::GetShaderIndex(ShaderDesc::ShaderType shader, ShaderDesc::ShaderVersion ver)
{
    ShaderDesc::ShaderIndex index = ShaderDesc::GetShaderIndex(shader);
    return ShaderIndexingData[index][ver]. VertexIndex;
};

VertexShaderDesc::ShaderIndex VertexShaderDesc::GetShaderIndexForComboIndex(unsigned index, ShaderDesc::ShaderVersion ver) 
{
    switch(ver)
    {
        case ShaderDesc::ShaderVersion_Vulkan_SPIRV:
        switch(index)
        {
            case 0:             return VSI_Vulkan_SPIRV_VTexTG;
            case 1:             return VSI_Vulkan_SPIRV_VTexTGMul;
            case 2:             return VSI_Vulkan_SPIRV_VTexTGInv;
            case 3:             return VSI_Vulkan_SPIRV_VTexTGEAlpha;
            case 4:             return VSI_Vulkan_SPIRV_VTexTGEAlphaMul;
            case 5:             return VSI_Vulkan_SPIRV_VTexTGEAlphaInv;
            case 6:             return VSI_Vulkan_SPIRV_VTexTGCxform;
            case 7:             return VSI_Vulkan_SPIRV_VTexTGCxformMul;
            case 8:             return VSI_Vulkan_SPIRV_VTexTGCxformInv;
            case 9:             return VSI_Vulkan_SPIRV_VTexTGCxformEAlpha;
            case 10:            return VSI_Vulkan_SPIRV_VTexTGCxformEAlphaMul;
            case 11:            return VSI_Vulkan_SPIRV_VTexTGCxformEAlphaInv;
            case 12:            return VSI_Vulkan_SPIRV_VTexTGCxformAc;
            case 13:            return VSI_Vulkan_SPIRV_VTexTGCxformAcMul;
            case 14:            return VSI_Vulkan_SPIRV_VTexTGCxformAcInv;
            case 15:            return VSI_Vulkan_SPIRV_VTexTGCxformAcEAlpha;
            case 16:            return VSI_Vulkan_SPIRV_VTexTGCxformAcEAlphaMul;
            case 17:            return VSI_Vulkan_SPIRV_VTexTGCxformAcEAlphaInv;
            case 18:            return VSI_Vulkan_SPIRV_VVertex;
            case 19:            return VSI_Vulkan_SPIRV_VVertexMul;
            case 20:            return VSI_Vulkan_SPIRV_VVertexInv;
            case 21:            return VSI_Vulkan_SPIRV_VVertexEAlpha;
            case 22:            return VSI_Vulkan_SPIRV_VVertexEAlphaMul;
            case 23:            return VSI_Vulkan_SPIRV_VVertexEAlphaInv;
            case 24:            return VSI_Vulkan_SPIRV_VVertexCxform;
            case 25:            return VSI_Vulkan_SPIRV_VVertexCxformMul;
            case 26:            return VSI_Vulkan_SPIRV_VVertexCxformInv;
            case 27:            return VSI_Vulkan_SPIRV_VVertexCxformEAlpha;
            case 28:            return VSI_Vulkan_SPIRV_VVertexCxformEAlphaMul;
            case 29:            return VSI_Vulkan_SPIRV_VVertexCxformEAlphaInv;
            case 30:            return VSI_Vulkan_SPIRV_VVertexCxformAc;
            case 31:            return VSI_Vulkan_SPIRV_VVertexCxformAcMul;
            case 32:            return VSI_Vulkan_SPIRV_VVertexCxformAcInv;
            case 33:            return VSI_Vulkan_SPIRV_VVertexCxformAcEAlpha;
            case 34:            return VSI_Vulkan_SPIRV_VVertexCxformAcEAlphaMul;
            case 35:            return VSI_Vulkan_SPIRV_VVertexCxformAcEAlphaInv;
            case 36:            return VSI_Vulkan_SPIRV_VTexTGTexTG;
            case 37:            return VSI_Vulkan_SPIRV_VTexTGTexTGMul;
            case 38:            return VSI_Vulkan_SPIRV_VTexTGTexTGInv;
            case 39:            return VSI_Vulkan_SPIRV_VTexTGTexTGEAlpha;
            case 40:            return VSI_Vulkan_SPIRV_VTexTGTexTGEAlphaMul;
            case 41:            return VSI_Vulkan_SPIRV_VTexTGTexTGEAlphaInv;
            case 42:            return VSI_Vulkan_SPIRV_VTexTGTexTGCxform;
            case 43:            return VSI_Vulkan_SPIRV_VTexTGTexTGCxformMul;
            case 44:            return VSI_Vulkan_SPIRV_VTexTGTexTGCxformInv;
            case 45:            return VSI_Vulkan_SPIRV_VTexTGTexTGCxformEAlpha;
            case 46:            return VSI_Vulkan_SPIRV_VTexTGTexTGCxformEAlphaMul;
            case 47:            return VSI_Vulkan_SPIRV_VTexTGTexTGCxformEAlphaInv;
            case 48:            return VSI_Vulkan_SPIRV_VTexTGTexTGCxformAc;
            case 49:            return VSI_Vulkan_SPIRV_VTexTGTexTGCxformAcMul;
            case 50:            return VSI_Vulkan_SPIRV_VTexTGTexTGCxformAcInv;
            case 51:            return VSI_Vulkan_SPIRV_VTexTGTexTGCxformAcEAlpha;
            case 52:            return VSI_Vulkan_SPIRV_VTexTGTexTGCxformAcEAlphaMul;
            case 53:            return VSI_Vulkan_SPIRV_VTexTGTexTGCxformAcEAlphaInv;
            case 54:            return VSI_Vulkan_SPIRV_VTexTGVertex;
            case 55:            return VSI_Vulkan_SPIRV_VTexTGVertexMul;
            case 56:            return VSI_Vulkan_SPIRV_VTexTGVertexInv;
            case 57:            return VSI_Vulkan_SPIRV_VTexTGVertexEAlpha;
            case 58:            return VSI_Vulkan_SPIRV_VTexTGVertexEAlphaMul;
            case 59:            return VSI_Vulkan_SPIRV_VTexTGVertexEAlphaInv;
            case 60:            return VSI_Vulkan_SPIRV_VTexTGVertexCxform;
            case 61:            return VSI_Vulkan_SPIRV_VTexTGVertexCxformMul;
            case 62:            return VSI_Vulkan_SPIRV_VTexTGVertexCxformInv;
            case 63:            return VSI_Vulkan_SPIRV_VTexTGVertexCxformEAlpha;
            case 64:            return VSI_Vulkan_SPIRV_VTexTGVertexCxformEAlphaMul;
            case 65:            return VSI_Vulkan_SPIRV_VTexTGVertexCxformEAlphaInv;
            case 66:            return VSI_Vulkan_SPIRV_VTexTGVertexCxformAc;
            case 67:            return VSI_Vulkan_SPIRV_VTexTGVertexCxformAcMul;
            case 68:            return VSI_Vulkan_SPIRV_VTexTGVertexCxformAcInv;
            case 69:            return VSI_Vulkan_SPIRV_VTexTGVertexCxformAcEAlpha;
            case 70:            return VSI_Vulkan_SPIRV_VTexTGVertexCxformAcEAlphaMul;
            case 71:            return VSI_Vulkan_SPIRV_VTexTGVertexCxformAcEAlphaInv;
            case 72:            return VSI_Vulkan_SPIRV_VPosition3dTexTG;
            case 73:            return VSI_Vulkan_SPIRV_VPosition3dTexTGMul;
            case 74:            return VSI_Vulkan_SPIRV_VPosition3dTexTGInv;
            case 75:            return VSI_Vulkan_SPIRV_VPosition3dTexTGEAlpha;
            case 76:            return VSI_Vulkan_SPIRV_VPosition3dTexTGEAlphaMul;
            case 77:            return VSI_Vulkan_SPIRV_VPosition3dTexTGEAlphaInv;
            case 78:            return VSI_Vulkan_SPIRV_VPosition3dTexTGCxform;
            case 79:            return VSI_Vulkan_SPIRV_VPosition3dTexTGCxformMul;
            case 80:            return VSI_Vulkan_SPIRV_VPosition3dTexTGCxformInv;
            case 81:            return VSI_Vulkan_SPIRV_VPosition3dTexTGCxformEAlpha;
            case 82:            return VSI_Vulkan_SPIRV_VPosition3dTexTGCxformEAlphaMul;
            case 83:            return VSI_Vulkan_SPIRV_VPosition3dTexTGCxformEAlphaInv;
            case 84:            return VSI_Vulkan_SPIRV_VPosition3dTexTGCxformAc;
            case 85:            return VSI_Vulkan_SPIRV_VPosition3dTexTGCxformAcMul;
            case 86:            return VSI_Vulkan_SPIRV_VPosition3dTexTGCxformAcInv;
            case 87:            return VSI_Vulkan_SPIRV_VPosition3dTexTGCxformAcEAlpha;
            case 88:            return VSI_Vulkan_SPIRV_VPosition3dTexTGCxformAcEAlphaMul;
            case 89:            return VSI_Vulkan_SPIRV_VPosition3dTexTGCxformAcEAlphaInv;
            case 90:            return VSI_Vulkan_SPIRV_VPosition3dVertex;
            case 91:            return VSI_Vulkan_SPIRV_VPosition3dVertexMul;
            case 92:            return VSI_Vulkan_SPIRV_VPosition3dVertexInv;
            case 93:            return VSI_Vulkan_SPIRV_VPosition3dVertexEAlpha;
            case 94:            return VSI_Vulkan_SPIRV_VPosition3dVertexEAlphaMul;
            case 95:            return VSI_Vulkan_SPIRV_VPosition3dVertexEAlphaInv;
            case 96:            return VSI_Vulkan_SPIRV_VPosition3dVertexCxform;
            case 97:            return VSI_Vulkan_SPIRV_VPosition3dVertexCxformMul;
            case 98:            return VSI_Vulkan_SPIRV_VPosition3dVertexCxformInv;
            case 99:            return VSI_Vulkan_SPIRV_VPosition3dVertexCxformEAlpha;
            case 100:           return VSI_Vulkan_SPIRV_VPosition3dVertexCxformEAlphaMul;
            case 101:           return VSI_Vulkan_SPIRV_VPosition3dVertexCxformEAlphaInv;
            case 102:           return VSI_Vulkan_SPIRV_VPosition3dVertexCxformAc;
            case 103:           return VSI_Vulkan_SPIRV_VPosition3dVertexCxformAcMul;
            case 104:           return VSI_Vulkan_SPIRV_VPosition3dVertexCxformAcInv;
            case 105:           return VSI_Vulkan_SPIRV_VPosition3dVertexCxformAcEAlpha;
            case 106:           return VSI_Vulkan_SPIRV_VPosition3dVertexCxformAcEAlphaMul;
            case 107:           return VSI_Vulkan_SPIRV_VPosition3dVertexCxformAcEAlphaInv;
            case 108:           return VSI_Vulkan_SPIRV_VPosition3dTexTGTexTG;
            case 109:           return VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGMul;
            case 110:           return VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGInv;
            case 111:           return VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGEAlpha;
            case 112:           return VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGEAlphaMul;
            case 113:           return VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGEAlphaInv;
            case 114:           return VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxform;
            case 115:           return VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxformMul;
            case 116:           return VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxformInv;
            case 117:           return VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxformEAlpha;
            case 118:           return VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxformEAlphaMul;
            case 119:           return VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxformEAlphaInv;
            case 120:           return VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxformAc;
            case 121:           return VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxformAcMul;
            case 122:           return VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxformAcInv;
            case 123:           return VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxformAcEAlpha;
            case 124:           return VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxformAcEAlphaMul;
            case 125:           return VSI_Vulkan_SPIRV_VPosition3dTexTGTexTGCxformAcEAlphaInv;
            case 126:           return VSI_Vulkan_SPIRV_VPosition3dTexTGVertex;
            case 127:           return VSI_Vulkan_SPIRV_VPosition3dTexTGVertexMul;
            case 128:           return VSI_Vulkan_SPIRV_VPosition3dTexTGVertexInv;
            case 129:           return VSI_Vulkan_SPIRV_VPosition3dTexTGVertexEAlpha;
            case 130:           return VSI_Vulkan_SPIRV_VPosition3dTexTGVertexEAlphaMul;
            case 131:           return VSI_Vulkan_SPIRV_VPosition3dTexTGVertexEAlphaInv;
            case 132:           return VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxform;
            case 133:           return VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxformMul;
            case 134:           return VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxformInv;
            case 135:           return VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxformEAlpha;
            case 136:           return VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxformEAlphaMul;
            case 137:           return VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxformEAlphaInv;
            case 138:           return VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxformAc;
            case 139:           return VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxformAcMul;
            case 140:           return VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxformAcInv;
            case 141:           return VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxformAcEAlpha;
            case 142:           return VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxformAcEAlphaMul;
            case 143:           return VSI_Vulkan_SPIRV_VPosition3dTexTGVertexCxformAcEAlphaInv;
            case 144:           return VSI_Vulkan_SPIRV_VBatchTexTG;
            case 145:           return VSI_Vulkan_SPIRV_VBatchTexTGMul;
            case 146:           return VSI_Vulkan_SPIRV_VBatchTexTGInv;
            case 147:           return VSI_Vulkan_SPIRV_VBatchTexTGEAlpha;
            case 148:           return VSI_Vulkan_SPIRV_VBatchTexTGEAlphaMul;
            case 149:           return VSI_Vulkan_SPIRV_VBatchTexTGEAlphaInv;
            case 150:           return VSI_Vulkan_SPIRV_VBatchTexTGCxform;
            case 151:           return VSI_Vulkan_SPIRV_VBatchTexTGCxformMul;
            case 152:           return VSI_Vulkan_SPIRV_VBatchTexTGCxformInv;
            case 153:           return VSI_Vulkan_SPIRV_VBatchTexTGCxformEAlpha;
            case 154:           return VSI_Vulkan_SPIRV_VBatchTexTGCxformEAlphaMul;
            case 155:           return VSI_Vulkan_SPIRV_VBatchTexTGCxformEAlphaInv;
            case 156:           return VSI_Vulkan_SPIRV_VBatchTexTGCxformAc;
            case 157:           return VSI_Vulkan_SPIRV_VBatchTexTGCxformAcMul;
            case 158:           return VSI_Vulkan_SPIRV_VBatchTexTGCxformAcInv;
            case 159:           return VSI_Vulkan_SPIRV_VBatchTexTGCxformAcEAlpha;
            case 160:           return VSI_Vulkan_SPIRV_VBatchTexTGCxformAcEAlphaMul;
            case 161:           return VSI_Vulkan_SPIRV_VBatchTexTGCxformAcEAlphaInv;
            case 162:           return VSI_Vulkan_SPIRV_VBatchVertex;
            case 163:           return VSI_Vulkan_SPIRV_VBatchVertexMul;
            case 164:           return VSI_Vulkan_SPIRV_VBatchVertexInv;
            case 165:           return VSI_Vulkan_SPIRV_VBatchVertexEAlpha;
            case 166:           return VSI_Vulkan_SPIRV_VBatchVertexEAlphaMul;
            case 167:           return VSI_Vulkan_SPIRV_VBatchVertexEAlphaInv;
            case 168:           return VSI_Vulkan_SPIRV_VBatchVertexCxform;
            case 169:           return VSI_Vulkan_SPIRV_VBatchVertexCxformMul;
            case 170:           return VSI_Vulkan_SPIRV_VBatchVertexCxformInv;
            case 171:           return VSI_Vulkan_SPIRV_VBatchVertexCxformEAlpha;
            case 172:           return VSI_Vulkan_SPIRV_VBatchVertexCxformEAlphaMul;
            case 173:           return VSI_Vulkan_SPIRV_VBatchVertexCxformEAlphaInv;
            case 174:           return VSI_Vulkan_SPIRV_VBatchVertexCxformAc;
            case 175:           return VSI_Vulkan_SPIRV_VBatchVertexCxformAcMul;
            case 176:           return VSI_Vulkan_SPIRV_VBatchVertexCxformAcInv;
            case 177:           return VSI_Vulkan_SPIRV_VBatchVertexCxformAcEAlpha;
            case 178:           return VSI_Vulkan_SPIRV_VBatchVertexCxformAcEAlphaMul;
            case 179:           return VSI_Vulkan_SPIRV_VBatchVertexCxformAcEAlphaInv;
            case 180:           return VSI_Vulkan_SPIRV_VBatchTexTGTexTG;
            case 181:           return VSI_Vulkan_SPIRV_VBatchTexTGTexTGMul;
            case 182:           return VSI_Vulkan_SPIRV_VBatchTexTGTexTGInv;
            case 183:           return VSI_Vulkan_SPIRV_VBatchTexTGTexTGEAlpha;
            case 184:           return VSI_Vulkan_SPIRV_VBatchTexTGTexTGEAlphaMul;
            case 185:           return VSI_Vulkan_SPIRV_VBatchTexTGTexTGEAlphaInv;
            case 186:           return VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxform;
            case 187:           return VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxformMul;
            case 188:           return VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxformInv;
            case 189:           return VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxformEAlpha;
            case 190:           return VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxformEAlphaMul;
            case 191:           return VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxformEAlphaInv;
            case 192:           return VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxformAc;
            case 193:           return VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxformAcMul;
            case 194:           return VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxformAcInv;
            case 195:           return VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxformAcEAlpha;
            case 196:           return VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxformAcEAlphaMul;
            case 197:           return VSI_Vulkan_SPIRV_VBatchTexTGTexTGCxformAcEAlphaInv;
            case 198:           return VSI_Vulkan_SPIRV_VBatchTexTGVertex;
            case 199:           return VSI_Vulkan_SPIRV_VBatchTexTGVertexMul;
            case 200:           return VSI_Vulkan_SPIRV_VBatchTexTGVertexInv;
            case 201:           return VSI_Vulkan_SPIRV_VBatchTexTGVertexEAlpha;
            case 202:           return VSI_Vulkan_SPIRV_VBatchTexTGVertexEAlphaMul;
            case 203:           return VSI_Vulkan_SPIRV_VBatchTexTGVertexEAlphaInv;
            case 204:           return VSI_Vulkan_SPIRV_VBatchTexTGVertexCxform;
            case 205:           return VSI_Vulkan_SPIRV_VBatchTexTGVertexCxformMul;
            case 206:           return VSI_Vulkan_SPIRV_VBatchTexTGVertexCxformInv;
            case 207:           return VSI_Vulkan_SPIRV_VBatchTexTGVertexCxformEAlpha;
            case 208:           return VSI_Vulkan_SPIRV_VBatchTexTGVertexCxformEAlphaMul;
            case 209:           return VSI_Vulkan_SPIRV_VBatchTexTGVertexCxformEAlphaInv;
            case 210:           return VSI_Vulkan_SPIRV_VBatchTexTGVertexCxformAc;
            case 211:           return VSI_Vulkan_SPIRV_VBatchTexTGVertexCxformAcMul;
            case 212:           return VSI_Vulkan_SPIRV_VBatchTexTGVertexCxformAcInv;
            case 213:           return VSI_Vulkan_SPIRV_VBatchTexTGVertexCxformAcEAlpha;
            case 214:           return VSI_Vulkan_SPIRV_VBatchTexTGVertexCxformAcEAlphaMul;
            case 215:           return VSI_Vulkan_SPIRV_VBatchTexTGVertexCxformAcEAlphaInv;
            case 216:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTG;
            case 217:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGMul;
            case 218:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGInv;
            case 219:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGEAlpha;
            case 220:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGEAlphaMul;
            case 221:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGEAlphaInv;
            case 222:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxform;
            case 223:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxformMul;
            case 224:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxformInv;
            case 225:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxformEAlpha;
            case 226:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxformEAlphaMul;
            case 227:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxformEAlphaInv;
            case 228:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxformAc;
            case 229:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxformAcMul;
            case 230:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxformAcInv;
            case 231:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxformAcEAlpha;
            case 232:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxformAcEAlphaMul;
            case 233:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGCxformAcEAlphaInv;
            case 234:           return VSI_Vulkan_SPIRV_VBatchPosition3dVertex;
            case 235:           return VSI_Vulkan_SPIRV_VBatchPosition3dVertexMul;
            case 236:           return VSI_Vulkan_SPIRV_VBatchPosition3dVertexInv;
            case 237:           return VSI_Vulkan_SPIRV_VBatchPosition3dVertexEAlpha;
            case 238:           return VSI_Vulkan_SPIRV_VBatchPosition3dVertexEAlphaMul;
            case 239:           return VSI_Vulkan_SPIRV_VBatchPosition3dVertexEAlphaInv;
            case 240:           return VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxform;
            case 241:           return VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxformMul;
            case 242:           return VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxformInv;
            case 243:           return VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxformEAlpha;
            case 244:           return VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxformEAlphaMul;
            case 245:           return VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxformEAlphaInv;
            case 246:           return VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxformAc;
            case 247:           return VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxformAcMul;
            case 248:           return VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxformAcInv;
            case 249:           return VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxformAcEAlpha;
            case 250:           return VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxformAcEAlphaMul;
            case 251:           return VSI_Vulkan_SPIRV_VBatchPosition3dVertexCxformAcEAlphaInv;
            case 252:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTG;
            case 253:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGMul;
            case 254:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGInv;
            case 255:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGEAlpha;
            case 256:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGEAlphaMul;
            case 257:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGEAlphaInv;
            case 258:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxform;
            case 259:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxformMul;
            case 260:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxformInv;
            case 261:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxformEAlpha;
            case 262:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxformEAlphaMul;
            case 263:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxformEAlphaInv;
            case 264:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxformAc;
            case 265:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxformAcMul;
            case 266:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxformAcInv;
            case 267:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxformAcEAlpha;
            case 268:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxformAcEAlphaMul;
            case 269:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGTexTGCxformAcEAlphaInv;
            case 270:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertex;
            case 271:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexMul;
            case 272:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexInv;
            case 273:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexEAlpha;
            case 274:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexEAlphaMul;
            case 275:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexEAlphaInv;
            case 276:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxform;
            case 277:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxformMul;
            case 278:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxformInv;
            case 279:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxformEAlpha;
            case 280:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxformEAlphaMul;
            case 281:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxformEAlphaInv;
            case 282:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxformAc;
            case 283:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxformAcMul;
            case 284:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxformAcInv;
            case 285:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxformAcEAlpha;
            case 286:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxformAcEAlphaMul;
            case 287:           return VSI_Vulkan_SPIRV_VBatchPosition3dTexTGVertexCxformAcEAlphaInv;
            case 288:           return VSI_Vulkan_SPIRV_VInstancedTexTG;
            case 289:           return VSI_Vulkan_SPIRV_VInstancedTexTGMul;
            case 290:           return VSI_Vulkan_SPIRV_VInstancedTexTGInv;
            case 291:           return VSI_Vulkan_SPIRV_VInstancedTexTGEAlpha;
            case 292:           return VSI_Vulkan_SPIRV_VInstancedTexTGEAlphaMul;
            case 293:           return VSI_Vulkan_SPIRV_VInstancedTexTGEAlphaInv;
            case 294:           return VSI_Vulkan_SPIRV_VInstancedTexTGCxform;
            case 295:           return VSI_Vulkan_SPIRV_VInstancedTexTGCxformMul;
            case 296:           return VSI_Vulkan_SPIRV_VInstancedTexTGCxformInv;
            case 297:           return VSI_Vulkan_SPIRV_VInstancedTexTGCxformEAlpha;
            case 298:           return VSI_Vulkan_SPIRV_VInstancedTexTGCxformEAlphaMul;
            case 299:           return VSI_Vulkan_SPIRV_VInstancedTexTGCxformEAlphaInv;
            case 300:           return VSI_Vulkan_SPIRV_VInstancedTexTGCxformAc;
            case 301:           return VSI_Vulkan_SPIRV_VInstancedTexTGCxformAcMul;
            case 302:           return VSI_Vulkan_SPIRV_VInstancedTexTGCxformAcInv;
            case 303:           return VSI_Vulkan_SPIRV_VInstancedTexTGCxformAcEAlpha;
            case 304:           return VSI_Vulkan_SPIRV_VInstancedTexTGCxformAcEAlphaMul;
            case 305:           return VSI_Vulkan_SPIRV_VInstancedTexTGCxformAcEAlphaInv;
            case 306:           return VSI_Vulkan_SPIRV_VInstancedVertex;
            case 307:           return VSI_Vulkan_SPIRV_VInstancedVertexMul;
            case 308:           return VSI_Vulkan_SPIRV_VInstancedVertexInv;
            case 309:           return VSI_Vulkan_SPIRV_VInstancedVertexEAlpha;
            case 310:           return VSI_Vulkan_SPIRV_VInstancedVertexEAlphaMul;
            case 311:           return VSI_Vulkan_SPIRV_VInstancedVertexEAlphaInv;
            case 312:           return VSI_Vulkan_SPIRV_VInstancedVertexCxform;
            case 313:           return VSI_Vulkan_SPIRV_VInstancedVertexCxformMul;
            case 314:           return VSI_Vulkan_SPIRV_VInstancedVertexCxformInv;
            case 315:           return VSI_Vulkan_SPIRV_VInstancedVertexCxformEAlpha;
            case 316:           return VSI_Vulkan_SPIRV_VInstancedVertexCxformEAlphaMul;
            case 317:           return VSI_Vulkan_SPIRV_VInstancedVertexCxformEAlphaInv;
            case 318:           return VSI_Vulkan_SPIRV_VInstancedVertexCxformAc;
            case 319:           return VSI_Vulkan_SPIRV_VInstancedVertexCxformAcMul;
            case 320:           return VSI_Vulkan_SPIRV_VInstancedVertexCxformAcInv;
            case 321:           return VSI_Vulkan_SPIRV_VInstancedVertexCxformAcEAlpha;
            case 322:           return VSI_Vulkan_SPIRV_VInstancedVertexCxformAcEAlphaMul;
            case 323:           return VSI_Vulkan_SPIRV_VInstancedVertexCxformAcEAlphaInv;
            case 324:           return VSI_Vulkan_SPIRV_VInstancedTexTGTexTG;
            case 325:           return VSI_Vulkan_SPIRV_VInstancedTexTGTexTGMul;
            case 326:           return VSI_Vulkan_SPIRV_VInstancedTexTGTexTGInv;
            case 327:           return VSI_Vulkan_SPIRV_VInstancedTexTGTexTGEAlpha;
            case 328:           return VSI_Vulkan_SPIRV_VInstancedTexTGTexTGEAlphaMul;
            case 329:           return VSI_Vulkan_SPIRV_VInstancedTexTGTexTGEAlphaInv;
            case 330:           return VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxform;
            case 331:           return VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxformMul;
            case 332:           return VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxformInv;
            case 333:           return VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxformEAlpha;
            case 334:           return VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxformEAlphaMul;
            case 335:           return VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxformEAlphaInv;
            case 336:           return VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxformAc;
            case 337:           return VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxformAcMul;
            case 338:           return VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxformAcInv;
            case 339:           return VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxformAcEAlpha;
            case 340:           return VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxformAcEAlphaMul;
            case 341:           return VSI_Vulkan_SPIRV_VInstancedTexTGTexTGCxformAcEAlphaInv;
            case 342:           return VSI_Vulkan_SPIRV_VInstancedTexTGVertex;
            case 343:           return VSI_Vulkan_SPIRV_VInstancedTexTGVertexMul;
            case 344:           return VSI_Vulkan_SPIRV_VInstancedTexTGVertexInv;
            case 345:           return VSI_Vulkan_SPIRV_VInstancedTexTGVertexEAlpha;
            case 346:           return VSI_Vulkan_SPIRV_VInstancedTexTGVertexEAlphaMul;
            case 347:           return VSI_Vulkan_SPIRV_VInstancedTexTGVertexEAlphaInv;
            case 348:           return VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxform;
            case 349:           return VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxformMul;
            case 350:           return VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxformInv;
            case 351:           return VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxformEAlpha;
            case 352:           return VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxformEAlphaMul;
            case 353:           return VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxformEAlphaInv;
            case 354:           return VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxformAc;
            case 355:           return VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxformAcMul;
            case 356:           return VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxformAcInv;
            case 357:           return VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxformAcEAlpha;
            case 358:           return VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxformAcEAlphaMul;
            case 359:           return VSI_Vulkan_SPIRV_VInstancedTexTGVertexCxformAcEAlphaInv;
            case 360:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTG;
            case 361:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGMul;
            case 362:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGInv;
            case 363:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGEAlpha;
            case 364:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGEAlphaMul;
            case 365:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGEAlphaInv;
            case 366:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxform;
            case 367:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformMul;
            case 368:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformInv;
            case 369:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformEAlpha;
            case 370:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformEAlphaMul;
            case 371:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformEAlphaInv;
            case 372:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformAc;
            case 373:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformAcMul;
            case 374:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformAcInv;
            case 375:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformAcEAlpha;
            case 376:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformAcEAlphaMul;
            case 377:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGCxformAcEAlphaInv;
            case 378:           return VSI_Vulkan_SPIRV_VInstancedPosition3dVertex;
            case 379:           return VSI_Vulkan_SPIRV_VInstancedPosition3dVertexMul;
            case 380:           return VSI_Vulkan_SPIRV_VInstancedPosition3dVertexInv;
            case 381:           return VSI_Vulkan_SPIRV_VInstancedPosition3dVertexEAlpha;
            case 382:           return VSI_Vulkan_SPIRV_VInstancedPosition3dVertexEAlphaMul;
            case 383:           return VSI_Vulkan_SPIRV_VInstancedPosition3dVertexEAlphaInv;
            case 384:           return VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxform;
            case 385:           return VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxformMul;
            case 386:           return VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxformInv;
            case 387:           return VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxformEAlpha;
            case 388:           return VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxformEAlphaMul;
            case 389:           return VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxformEAlphaInv;
            case 390:           return VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxformAc;
            case 391:           return VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxformAcMul;
            case 392:           return VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxformAcInv;
            case 393:           return VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxformAcEAlpha;
            case 394:           return VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxformAcEAlphaMul;
            case 395:           return VSI_Vulkan_SPIRV_VInstancedPosition3dVertexCxformAcEAlphaInv;
            case 396:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTG;
            case 397:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGMul;
            case 398:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGInv;
            case 399:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGEAlpha;
            case 400:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGEAlphaMul;
            case 401:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGEAlphaInv;
            case 402:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxform;
            case 403:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxformMul;
            case 404:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxformInv;
            case 405:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxformEAlpha;
            case 406:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxformEAlphaMul;
            case 407:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxformEAlphaInv;
            case 408:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxformAc;
            case 409:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxformAcMul;
            case 410:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxformAcInv;
            case 411:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxformAcEAlpha;
            case 412:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxformAcEAlphaMul;
            case 413:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGTexTGCxformAcEAlphaInv;
            case 414:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertex;
            case 415:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexMul;
            case 416:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexInv;
            case 417:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexEAlpha;
            case 418:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexEAlphaMul;
            case 419:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexEAlphaInv;
            case 420:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxform;
            case 421:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxformMul;
            case 422:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxformInv;
            case 423:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxformEAlpha;
            case 424:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxformEAlphaMul;
            case 425:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxformEAlphaInv;
            case 426:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxformAc;
            case 427:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxformAcMul;
            case 428:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxformAcInv;
            case 429:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxformAcEAlpha;
            case 430:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxformAcEAlphaMul;
            case 431:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTexTGVertexCxformAcEAlphaInv;
            case 432:           return VSI_Vulkan_SPIRV_VSolid;
            case 433:           return VSI_Vulkan_SPIRV_VSolidMul;
            case 434:           return VSI_Vulkan_SPIRV_VSolidInv;
            case 435:           return VSI_Vulkan_SPIRV_VText;
            case 436:           return VSI_Vulkan_SPIRV_VTextMul;
            case 437:           return VSI_Vulkan_SPIRV_VTextInv;
            case 438:           return VSI_Vulkan_SPIRV_VTextColor;
            case 439:           return VSI_Vulkan_SPIRV_VTextColorMul;
            case 440:           return VSI_Vulkan_SPIRV_VTextColorInv;
            case 441:           return VSI_Vulkan_SPIRV_VTextColorCxform;
            case 442:           return VSI_Vulkan_SPIRV_VTextColorCxformMul;
            case 443:           return VSI_Vulkan_SPIRV_VTextColorCxformInv;
            case 444:           return VSI_Vulkan_SPIRV_VPosition3dSolid;
            case 445:           return VSI_Vulkan_SPIRV_VPosition3dSolidMul;
            case 446:           return VSI_Vulkan_SPIRV_VPosition3dSolidInv;
            case 447:           return VSI_Vulkan_SPIRV_VPosition3dText;
            case 448:           return VSI_Vulkan_SPIRV_VPosition3dTextMul;
            case 449:           return VSI_Vulkan_SPIRV_VPosition3dTextInv;
            case 450:           return VSI_Vulkan_SPIRV_VPosition3dTextColor;
            case 451:           return VSI_Vulkan_SPIRV_VPosition3dTextColorMul;
            case 452:           return VSI_Vulkan_SPIRV_VPosition3dTextColorInv;
            case 453:           return VSI_Vulkan_SPIRV_VPosition3dTextColorCxform;
            case 454:           return VSI_Vulkan_SPIRV_VPosition3dTextColorCxformMul;
            case 455:           return VSI_Vulkan_SPIRV_VPosition3dTextColorCxformInv;
            case 456:           return VSI_Vulkan_SPIRV_VBatchSolid;
            case 457:           return VSI_Vulkan_SPIRV_VBatchSolidMul;
            case 458:           return VSI_Vulkan_SPIRV_VBatchSolidInv;
            case 459:           return VSI_Vulkan_SPIRV_VBatchText;
            case 460:           return VSI_Vulkan_SPIRV_VBatchTextMul;
            case 461:           return VSI_Vulkan_SPIRV_VBatchTextInv;
            case 462:           return VSI_Vulkan_SPIRV_VBatchTextColor;
            case 463:           return VSI_Vulkan_SPIRV_VBatchTextColorMul;
            case 464:           return VSI_Vulkan_SPIRV_VBatchTextColorInv;
            case 465:           return VSI_Vulkan_SPIRV_VBatchTextColorCxform;
            case 466:           return VSI_Vulkan_SPIRV_VBatchTextColorCxformMul;
            case 467:           return VSI_Vulkan_SPIRV_VBatchTextColorCxformInv;
            case 468:           return VSI_Vulkan_SPIRV_VBatchPosition3dSolid;
            case 469:           return VSI_Vulkan_SPIRV_VBatchPosition3dSolidMul;
            case 470:           return VSI_Vulkan_SPIRV_VBatchPosition3dSolidInv;
            case 471:           return VSI_Vulkan_SPIRV_VBatchPosition3dText;
            case 472:           return VSI_Vulkan_SPIRV_VBatchPosition3dTextMul;
            case 473:           return VSI_Vulkan_SPIRV_VBatchPosition3dTextInv;
            case 474:           return VSI_Vulkan_SPIRV_VBatchPosition3dTextColor;
            case 475:           return VSI_Vulkan_SPIRV_VBatchPosition3dTextColorMul;
            case 476:           return VSI_Vulkan_SPIRV_VBatchPosition3dTextColorInv;
            case 477:           return VSI_Vulkan_SPIRV_VBatchPosition3dTextColorCxform;
            case 478:           return VSI_Vulkan_SPIRV_VBatchPosition3dTextColorCxformMul;
            case 479:           return VSI_Vulkan_SPIRV_VBatchPosition3dTextColorCxformInv;
            case 480:           return VSI_Vulkan_SPIRV_VInstancedSolid;
            case 481:           return VSI_Vulkan_SPIRV_VInstancedSolidMul;
            case 482:           return VSI_Vulkan_SPIRV_VInstancedSolidInv;
            case 483:           return VSI_Vulkan_SPIRV_VInstancedText;
            case 484:           return VSI_Vulkan_SPIRV_VInstancedTextMul;
            case 485:           return VSI_Vulkan_SPIRV_VInstancedTextInv;
            case 486:           return VSI_Vulkan_SPIRV_VInstancedTextColor;
            case 487:           return VSI_Vulkan_SPIRV_VInstancedTextColorMul;
            case 488:           return VSI_Vulkan_SPIRV_VInstancedTextColorInv;
            case 489:           return VSI_Vulkan_SPIRV_VInstancedTextColorCxform;
            case 490:           return VSI_Vulkan_SPIRV_VInstancedTextColorCxformMul;
            case 491:           return VSI_Vulkan_SPIRV_VInstancedTextColorCxformInv;
            case 492:           return VSI_Vulkan_SPIRV_VInstancedPosition3dSolid;
            case 493:           return VSI_Vulkan_SPIRV_VInstancedPosition3dSolidMul;
            case 494:           return VSI_Vulkan_SPIRV_VInstancedPosition3dSolidInv;
            case 495:           return VSI_Vulkan_SPIRV_VInstancedPosition3dText;
            case 496:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTextMul;
            case 497:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTextInv;
            case 498:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTextColor;
            case 499:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTextColorMul;
            case 500:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTextColorInv;
            case 501:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTextColorCxform;
            case 502:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTextColorCxformMul;
            case 503:           return VSI_Vulkan_SPIRV_VInstancedPosition3dTextColorCxformInv;
            case 504:           return VSI_Vulkan_SPIRV_VYUV;
            case 505:           return VSI_Vulkan_SPIRV_VYUVMul;
            case 506:           return VSI_Vulkan_SPIRV_VYUVEAlpha;
            case 507:           return VSI_Vulkan_SPIRV_VYUVEAlphaMul;
            case 508:           return VSI_Vulkan_SPIRV_VYUVCxform;
            case 509:           return VSI_Vulkan_SPIRV_VYUVCxformMul;
            case 510:           return VSI_Vulkan_SPIRV_VYUVCxformEAlpha;
            case 511:           return VSI_Vulkan_SPIRV_VYUVCxformEAlphaMul;
            case 512:           return VSI_Vulkan_SPIRV_VYUVCxformAc;
            case 513:           return VSI_Vulkan_SPIRV_VYUVCxformAcMul;
            case 514:           return VSI_Vulkan_SPIRV_VYUVCxformAcEAlpha;
            case 515:           return VSI_Vulkan_SPIRV_VYUVCxformAcEAlphaMul;
            case 516:           return VSI_Vulkan_SPIRV_VYUVA;
            case 517:           return VSI_Vulkan_SPIRV_VYUVAMul;
            case 518:           return VSI_Vulkan_SPIRV_VYUVAInv;
            case 519:           return VSI_Vulkan_SPIRV_VYUVAEAlpha;
            case 520:           return VSI_Vulkan_SPIRV_VYUVAEAlphaMul;
            case 521:           return VSI_Vulkan_SPIRV_VYUVAEAlphaInv;
            case 522:           return VSI_Vulkan_SPIRV_VYUVACxform;
            case 523:           return VSI_Vulkan_SPIRV_VYUVACxformMul;
            case 524:           return VSI_Vulkan_SPIRV_VYUVACxformInv;
            case 525:           return VSI_Vulkan_SPIRV_VYUVACxformEAlpha;
            case 526:           return VSI_Vulkan_SPIRV_VYUVACxformEAlphaMul;
            case 527:           return VSI_Vulkan_SPIRV_VYUVACxformEAlphaInv;
            case 528:           return VSI_Vulkan_SPIRV_VYUVACxformAc;
            case 529:           return VSI_Vulkan_SPIRV_VYUVACxformAcMul;
            case 530:           return VSI_Vulkan_SPIRV_VYUVACxformAcInv;
            case 531:           return VSI_Vulkan_SPIRV_VYUVACxformAcEAlpha;
            case 532:           return VSI_Vulkan_SPIRV_VYUVACxformAcEAlphaMul;
            case 533:           return VSI_Vulkan_SPIRV_VYUVACxformAcEAlphaInv;
            case 534:           return VSI_Vulkan_SPIRV_VPosition3dYUV;
            case 535:           return VSI_Vulkan_SPIRV_VPosition3dYUVMul;
            case 536:           return VSI_Vulkan_SPIRV_VPosition3dYUVEAlpha;
            case 537:           return VSI_Vulkan_SPIRV_VPosition3dYUVEAlphaMul;
            case 538:           return VSI_Vulkan_SPIRV_VPosition3dYUVCxform;
            case 539:           return VSI_Vulkan_SPIRV_VPosition3dYUVCxformMul;
            case 540:           return VSI_Vulkan_SPIRV_VPosition3dYUVCxformEAlpha;
            case 541:           return VSI_Vulkan_SPIRV_VPosition3dYUVCxformEAlphaMul;
            case 542:           return VSI_Vulkan_SPIRV_VPosition3dYUVCxformAc;
            case 543:           return VSI_Vulkan_SPIRV_VPosition3dYUVCxformAcMul;
            case 544:           return VSI_Vulkan_SPIRV_VPosition3dYUVCxformAcEAlpha;
            case 545:           return VSI_Vulkan_SPIRV_VPosition3dYUVCxformAcEAlphaMul;
            case 546:           return VSI_Vulkan_SPIRV_VPosition3dYUVA;
            case 547:           return VSI_Vulkan_SPIRV_VPosition3dYUVAMul;
            case 548:           return VSI_Vulkan_SPIRV_VPosition3dYUVAInv;
            case 549:           return VSI_Vulkan_SPIRV_VPosition3dYUVAEAlpha;
            case 550:           return VSI_Vulkan_SPIRV_VPosition3dYUVAEAlphaMul;
            case 551:           return VSI_Vulkan_SPIRV_VPosition3dYUVAEAlphaInv;
            case 552:           return VSI_Vulkan_SPIRV_VPosition3dYUVACxform;
            case 553:           return VSI_Vulkan_SPIRV_VPosition3dYUVACxformMul;
            case 554:           return VSI_Vulkan_SPIRV_VPosition3dYUVACxformInv;
            case 555:           return VSI_Vulkan_SPIRV_VPosition3dYUVACxformEAlpha;
            case 556:           return VSI_Vulkan_SPIRV_VPosition3dYUVACxformEAlphaMul;
            case 557:           return VSI_Vulkan_SPIRV_VPosition3dYUVACxformEAlphaInv;
            case 558:           return VSI_Vulkan_SPIRV_VPosition3dYUVACxformAc;
            case 559:           return VSI_Vulkan_SPIRV_VPosition3dYUVACxformAcMul;
            case 560:           return VSI_Vulkan_SPIRV_VPosition3dYUVACxformAcInv;
            case 561:           return VSI_Vulkan_SPIRV_VPosition3dYUVACxformAcEAlpha;
            case 562:           return VSI_Vulkan_SPIRV_VPosition3dYUVACxformAcEAlphaMul;
            case 563:           return VSI_Vulkan_SPIRV_VPosition3dYUVACxformAcEAlphaInv;
            case 564:           return VSI_Vulkan_SPIRV_VBatchYUV;
            case 565:           return VSI_Vulkan_SPIRV_VBatchYUVMul;
            case 566:           return VSI_Vulkan_SPIRV_VBatchYUVEAlpha;
            case 567:           return VSI_Vulkan_SPIRV_VBatchYUVEAlphaMul;
            case 568:           return VSI_Vulkan_SPIRV_VBatchYUVCxform;
            case 569:           return VSI_Vulkan_SPIRV_VBatchYUVCxformMul;
            case 570:           return VSI_Vulkan_SPIRV_VBatchYUVCxformEAlpha;
            case 571:           return VSI_Vulkan_SPIRV_VBatchYUVCxformEAlphaMul;
            case 572:           return VSI_Vulkan_SPIRV_VBatchYUVCxformAc;
            case 573:           return VSI_Vulkan_SPIRV_VBatchYUVCxformAcMul;
            case 574:           return VSI_Vulkan_SPIRV_VBatchYUVCxformAcEAlpha;
            case 575:           return VSI_Vulkan_SPIRV_VBatchYUVCxformAcEAlphaMul;
            case 576:           return VSI_Vulkan_SPIRV_VBatchYUVA;
            case 577:           return VSI_Vulkan_SPIRV_VBatchYUVAMul;
            case 578:           return VSI_Vulkan_SPIRV_VBatchYUVAInv;
            case 579:           return VSI_Vulkan_SPIRV_VBatchYUVAEAlpha;
            case 580:           return VSI_Vulkan_SPIRV_VBatchYUVAEAlphaMul;
            case 581:           return VSI_Vulkan_SPIRV_VBatchYUVAEAlphaInv;
            case 582:           return VSI_Vulkan_SPIRV_VBatchYUVACxform;
            case 583:           return VSI_Vulkan_SPIRV_VBatchYUVACxformMul;
            case 584:           return VSI_Vulkan_SPIRV_VBatchYUVACxformInv;
            case 585:           return VSI_Vulkan_SPIRV_VBatchYUVACxformEAlpha;
            case 586:           return VSI_Vulkan_SPIRV_VBatchYUVACxformEAlphaMul;
            case 587:           return VSI_Vulkan_SPIRV_VBatchYUVACxformEAlphaInv;
            case 588:           return VSI_Vulkan_SPIRV_VBatchYUVACxformAc;
            case 589:           return VSI_Vulkan_SPIRV_VBatchYUVACxformAcMul;
            case 590:           return VSI_Vulkan_SPIRV_VBatchYUVACxformAcInv;
            case 591:           return VSI_Vulkan_SPIRV_VBatchYUVACxformAcEAlpha;
            case 592:           return VSI_Vulkan_SPIRV_VBatchYUVACxformAcEAlphaMul;
            case 593:           return VSI_Vulkan_SPIRV_VBatchYUVACxformAcEAlphaInv;
            case 594:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUV;
            case 595:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVMul;
            case 596:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVEAlpha;
            case 597:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVEAlphaMul;
            case 598:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVCxform;
            case 599:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVCxformMul;
            case 600:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVCxformEAlpha;
            case 601:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVCxformEAlphaMul;
            case 602:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVCxformAc;
            case 603:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVCxformAcMul;
            case 604:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVCxformAcEAlpha;
            case 605:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVCxformAcEAlphaMul;
            case 606:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVA;
            case 607:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVAMul;
            case 608:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVAInv;
            case 609:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVAEAlpha;
            case 610:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVAEAlphaMul;
            case 611:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVAEAlphaInv;
            case 612:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxform;
            case 613:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxformMul;
            case 614:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxformInv;
            case 615:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxformEAlpha;
            case 616:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxformEAlphaMul;
            case 617:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxformEAlphaInv;
            case 618:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxformAc;
            case 619:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxformAcMul;
            case 620:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxformAcInv;
            case 621:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxformAcEAlpha;
            case 622:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxformAcEAlphaMul;
            case 623:           return VSI_Vulkan_SPIRV_VBatchPosition3dYUVACxformAcEAlphaInv;
            case 624:           return VSI_Vulkan_SPIRV_VInstancedYUV;
            case 625:           return VSI_Vulkan_SPIRV_VInstancedYUVMul;
            case 626:           return VSI_Vulkan_SPIRV_VInstancedYUVEAlpha;
            case 627:           return VSI_Vulkan_SPIRV_VInstancedYUVEAlphaMul;
            case 628:           return VSI_Vulkan_SPIRV_VInstancedYUVCxform;
            case 629:           return VSI_Vulkan_SPIRV_VInstancedYUVCxformMul;
            case 630:           return VSI_Vulkan_SPIRV_VInstancedYUVCxformEAlpha;
            case 631:           return VSI_Vulkan_SPIRV_VInstancedYUVCxformEAlphaMul;
            case 632:           return VSI_Vulkan_SPIRV_VInstancedYUVCxformAc;
            case 633:           return VSI_Vulkan_SPIRV_VInstancedYUVCxformAcMul;
            case 634:           return VSI_Vulkan_SPIRV_VInstancedYUVCxformAcEAlpha;
            case 635:           return VSI_Vulkan_SPIRV_VInstancedYUVCxformAcEAlphaMul;
            case 636:           return VSI_Vulkan_SPIRV_VInstancedYUVA;
            case 637:           return VSI_Vulkan_SPIRV_VInstancedYUVAMul;
            case 638:           return VSI_Vulkan_SPIRV_VInstancedYUVAInv;
            case 639:           return VSI_Vulkan_SPIRV_VInstancedYUVAEAlpha;
            case 640:           return VSI_Vulkan_SPIRV_VInstancedYUVAEAlphaMul;
            case 641:           return VSI_Vulkan_SPIRV_VInstancedYUVAEAlphaInv;
            case 642:           return VSI_Vulkan_SPIRV_VInstancedYUVACxform;
            case 643:           return VSI_Vulkan_SPIRV_VInstancedYUVACxformMul;
            case 644:           return VSI_Vulkan_SPIRV_VInstancedYUVACxformInv;
            case 645:           return VSI_Vulkan_SPIRV_VInstancedYUVACxformEAlpha;
            case 646:           return VSI_Vulkan_SPIRV_VInstancedYUVACxformEAlphaMul;
            case 647:           return VSI_Vulkan_SPIRV_VInstancedYUVACxformEAlphaInv;
            case 648:           return VSI_Vulkan_SPIRV_VInstancedYUVACxformAc;
            case 649:           return VSI_Vulkan_SPIRV_VInstancedYUVACxformAcMul;
            case 650:           return VSI_Vulkan_SPIRV_VInstancedYUVACxformAcInv;
            case 651:           return VSI_Vulkan_SPIRV_VInstancedYUVACxformAcEAlpha;
            case 652:           return VSI_Vulkan_SPIRV_VInstancedYUVACxformAcEAlphaMul;
            case 653:           return VSI_Vulkan_SPIRV_VInstancedYUVACxformAcEAlphaInv;
            case 654:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUV;
            case 655:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVMul;
            case 656:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVEAlpha;
            case 657:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVEAlphaMul;
            case 658:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVCxform;
            case 659:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVCxformMul;
            case 660:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVCxformEAlpha;
            case 661:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVCxformEAlphaMul;
            case 662:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVCxformAc;
            case 663:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVCxformAcMul;
            case 664:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVCxformAcEAlpha;
            case 665:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVCxformAcEAlphaMul;
            case 666:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVA;
            case 667:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVAMul;
            case 668:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVAInv;
            case 669:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVAEAlpha;
            case 670:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVAEAlphaMul;
            case 671:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVAEAlphaInv;
            case 672:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxform;
            case 673:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxformMul;
            case 674:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxformInv;
            case 675:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxformEAlpha;
            case 676:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxformEAlphaMul;
            case 677:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxformEAlphaInv;
            case 678:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxformAc;
            case 679:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxformAcMul;
            case 680:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxformAcInv;
            case 681:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxformAcEAlpha;
            case 682:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxformAcEAlphaMul;
            case 683:           return VSI_Vulkan_SPIRV_VInstancedPosition3dYUVACxformAcEAlphaInv;
            case 684:           return VSI_Vulkan_SPIRV_VTexTGCMatrixAc;
            case 685:           return VSI_Vulkan_SPIRV_VTexTGCMatrixAcMul;
            case 686:           return VSI_Vulkan_SPIRV_VTexTGCMatrixAcEAlpha;
            case 687:           return VSI_Vulkan_SPIRV_VTexTGCMatrixAcEAlphaMul;
            case 688:           return VSI_Vulkan_SPIRV_VBox1Blur;
            case 689:           return VSI_Vulkan_SPIRV_VBox1BlurMul;
            case 690:           return VSI_Vulkan_SPIRV_VBox2Blur;
            case 691:           return VSI_Vulkan_SPIRV_VBox2BlurMul;
            case 692:           return VSI_Vulkan_SPIRV_VBox2Shadow;
            case 693:           return VSI_Vulkan_SPIRV_VBox2ShadowMul;
            case 694:           return VSI_Vulkan_SPIRV_VBox2ShadowKnockout;
            case 695:           return VSI_Vulkan_SPIRV_VBox2ShadowKnockoutMul;
            case 696:           return VSI_Vulkan_SPIRV_VBox2InnerShadow;
            case 697:           return VSI_Vulkan_SPIRV_VBox2InnerShadowMul;
            case 698:           return VSI_Vulkan_SPIRV_VBox2InnerShadowKnockout;
            case 699:           return VSI_Vulkan_SPIRV_VBox2InnerShadowKnockoutMul;
            case 700:           return VSI_Vulkan_SPIRV_VBox2Shadowonly;
            case 701:           return VSI_Vulkan_SPIRV_VBox2ShadowonlyMul;
            case 702:           return VSI_Vulkan_SPIRV_VBox2ShadowHighlight;
            case 703:           return VSI_Vulkan_SPIRV_VBox2ShadowHighlightMul;
            case 704:           return VSI_Vulkan_SPIRV_VBox2ShadowHighlightKnockout;
            case 705:           return VSI_Vulkan_SPIRV_VBox2ShadowHighlightKnockoutMul;
            case 706:           return VSI_Vulkan_SPIRV_VBox2InnerShadowHighlight;
            case 707:           return VSI_Vulkan_SPIRV_VBox2InnerShadowHighlightMul;
            case 708:           return VSI_Vulkan_SPIRV_VBox2InnerShadowHighlightKnockout;
            case 709:           return VSI_Vulkan_SPIRV_VBox2InnerShadowHighlightKnockoutMul;
            case 710:           return VSI_Vulkan_SPIRV_VBox2FullShadowHighlight;
            case 711:           return VSI_Vulkan_SPIRV_VBox2FullShadowHighlightMul;
            case 712:           return VSI_Vulkan_SPIRV_VBox2ShadowonlyHighlight;
            case 713:           return VSI_Vulkan_SPIRV_VBox2ShadowonlyHighlightMul;
            case 714:           return VSI_Vulkan_SPIRV_VDrawableCopyPixels;
            case 715:           return VSI_Vulkan_SPIRV_VDrawableCopyPixelsMergeAlpha;
            case 716:           return VSI_Vulkan_SPIRV_VDrawableCopyPixelsNoDestAlpha;
            case 717:           return VSI_Vulkan_SPIRV_VDrawableCopyPixelsAlpha;
            case 718:           return VSI_Vulkan_SPIRV_VDrawableCopyPixelsAlphaMergeAlpha;
            case 719:           return VSI_Vulkan_SPIRV_VDrawableCopyPixelsAlphaNoDestAlpha;
            case 720:           return VSI_Vulkan_SPIRV_VDrawableMerge;
            case 721:           return VSI_Vulkan_SPIRV_VDrawableCompare;
            case 722:           return VSI_Vulkan_SPIRV_VDrawablePaletteMap;
            default: SF_ASSERT(0); return VSI_None;
        }
        default: SF_ASSERT(0); return VSI_None;
    }
}

unsigned VertexShaderDesc::GetShaderComboIndex(ShaderDesc::ShaderType shader, ShaderDesc::ShaderVersion ver)
{
    switch(ver)
    {
        case ShaderDesc::ShaderVersion_Vulkan_SPIRV:
        switch(shader)
        {
            case ShaderDesc::ST_TexTG:                                       return 0;
            case ShaderDesc::ST_TexTGMul:                                    return 1;
            case ShaderDesc::ST_BatchTexTG:                                  return 144;
            case ShaderDesc::ST_BatchTexTGMul:                               return 145;
            case ShaderDesc::ST_InstancedTexTG:                              return 288;
            case ShaderDesc::ST_InstancedTexTGMul:                           return 289;
            case ShaderDesc::ST_Position3dTexTG:                             return 72;
            case ShaderDesc::ST_Position3dTexTGMul:                          return 73;
            case ShaderDesc::ST_BatchPosition3dTexTG:                        return 216;
            case ShaderDesc::ST_BatchPosition3dTexTGMul:                     return 217;
            case ShaderDesc::ST_InstancedPosition3dTexTG:                    return 360;
            case ShaderDesc::ST_InstancedPosition3dTexTGMul:                 return 361;
            case ShaderDesc::ST_TexTGCxform:                                 return 6;
            case ShaderDesc::ST_TexTGCxformMul:                              return 7;
            case ShaderDesc::ST_BatchTexTGCxform:                            return 150;
            case ShaderDesc::ST_BatchTexTGCxformMul:                         return 151;
            case ShaderDesc::ST_InstancedTexTGCxform:                        return 294;
            case ShaderDesc::ST_InstancedTexTGCxformMul:                     return 295;
            case ShaderDesc::ST_Position3dTexTGCxform:                       return 78;
            case ShaderDesc::ST_Position3dTexTGCxformMul:                    return 79;
            case ShaderDesc::ST_BatchPosition3dTexTGCxform:                  return 222;
            case ShaderDesc::ST_BatchPosition3dTexTGCxformMul:               return 223;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxform:              return 366;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxformMul:           return 367;
            case ShaderDesc::ST_TexTGEAlpha:                                 return 3;
            case ShaderDesc::ST_TexTGEAlphaMul:                              return 4;
            case ShaderDesc::ST_BatchTexTGEAlpha:                            return 147;
            case ShaderDesc::ST_BatchTexTGEAlphaMul:                         return 148;
            case ShaderDesc::ST_InstancedTexTGEAlpha:                        return 291;
            case ShaderDesc::ST_InstancedTexTGEAlphaMul:                     return 292;
            case ShaderDesc::ST_Position3dTexTGEAlpha:                       return 75;
            case ShaderDesc::ST_Position3dTexTGEAlphaMul:                    return 76;
            case ShaderDesc::ST_BatchPosition3dTexTGEAlpha:                  return 219;
            case ShaderDesc::ST_BatchPosition3dTexTGEAlphaMul:               return 220;
            case ShaderDesc::ST_InstancedPosition3dTexTGEAlpha:              return 363;
            case ShaderDesc::ST_InstancedPosition3dTexTGEAlphaMul:           return 364;
            case ShaderDesc::ST_TexTGCxformEAlpha:                           return 9;
            case ShaderDesc::ST_TexTGCxformEAlphaMul:                        return 10;
            case ShaderDesc::ST_BatchTexTGCxformEAlpha:                      return 153;
            case ShaderDesc::ST_BatchTexTGCxformEAlphaMul:                   return 154;
            case ShaderDesc::ST_InstancedTexTGCxformEAlpha:                  return 297;
            case ShaderDesc::ST_InstancedTexTGCxformEAlphaMul:               return 298;
            case ShaderDesc::ST_Position3dTexTGCxformEAlpha:                 return 81;
            case ShaderDesc::ST_Position3dTexTGCxformEAlphaMul:              return 82;
            case ShaderDesc::ST_BatchPosition3dTexTGCxformEAlpha:            return 225;
            case ShaderDesc::ST_BatchPosition3dTexTGCxformEAlphaMul:         return 226;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxformEAlpha:        return 369;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxformEAlphaMul:     return 370;
            case ShaderDesc::ST_TexTGInv:                                    return 2;
            case ShaderDesc::ST_BatchTexTGInv:                               return 146;
            case ShaderDesc::ST_InstancedTexTGInv:                           return 290;
            case ShaderDesc::ST_Position3dTexTGInv:                          return 74;
            case ShaderDesc::ST_BatchPosition3dTexTGInv:                     return 218;
            case ShaderDesc::ST_InstancedPosition3dTexTGInv:                 return 362;
            case ShaderDesc::ST_TexTGCxformInv:                              return 8;
            case ShaderDesc::ST_BatchTexTGCxformInv:                         return 152;
            case ShaderDesc::ST_InstancedTexTGCxformInv:                     return 296;
            case ShaderDesc::ST_Position3dTexTGCxformInv:                    return 80;
            case ShaderDesc::ST_BatchPosition3dTexTGCxformInv:               return 224;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxformInv:           return 368;
            case ShaderDesc::ST_TexTGEAlphaInv:                              return 5;
            case ShaderDesc::ST_BatchTexTGEAlphaInv:                         return 149;
            case ShaderDesc::ST_InstancedTexTGEAlphaInv:                     return 293;
            case ShaderDesc::ST_Position3dTexTGEAlphaInv:                    return 77;
            case ShaderDesc::ST_BatchPosition3dTexTGEAlphaInv:               return 221;
            case ShaderDesc::ST_InstancedPosition3dTexTGEAlphaInv:           return 365;
            case ShaderDesc::ST_TexTGCxformEAlphaInv:                        return 11;
            case ShaderDesc::ST_BatchTexTGCxformEAlphaInv:                   return 155;
            case ShaderDesc::ST_InstancedTexTGCxformEAlphaInv:               return 299;
            case ShaderDesc::ST_Position3dTexTGCxformEAlphaInv:              return 83;
            case ShaderDesc::ST_BatchPosition3dTexTGCxformEAlphaInv:         return 227;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxformEAlphaInv:     return 371;
            case ShaderDesc::ST_TexTGCxformAc:                               return 12;
            case ShaderDesc::ST_TexTGCxformAcMul:                            return 13;
            case ShaderDesc::ST_BatchTexTGCxformAc:                          return 156;
            case ShaderDesc::ST_BatchTexTGCxformAcMul:                       return 157;
            case ShaderDesc::ST_InstancedTexTGCxformAc:                      return 300;
            case ShaderDesc::ST_InstancedTexTGCxformAcMul:                   return 301;
            case ShaderDesc::ST_Position3dTexTGCxformAc:                     return 84;
            case ShaderDesc::ST_Position3dTexTGCxformAcMul:                  return 85;
            case ShaderDesc::ST_BatchPosition3dTexTGCxformAc:                return 228;
            case ShaderDesc::ST_BatchPosition3dTexTGCxformAcMul:             return 229;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxformAc:            return 372;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxformAcMul:         return 373;
            case ShaderDesc::ST_TexTGCxformAcEAlpha:                         return 15;
            case ShaderDesc::ST_TexTGCxformAcEAlphaMul:                      return 16;
            case ShaderDesc::ST_BatchTexTGCxformAcEAlpha:                    return 159;
            case ShaderDesc::ST_BatchTexTGCxformAcEAlphaMul:                 return 160;
            case ShaderDesc::ST_InstancedTexTGCxformAcEAlpha:                return 303;
            case ShaderDesc::ST_InstancedTexTGCxformAcEAlphaMul:             return 304;
            case ShaderDesc::ST_Position3dTexTGCxformAcEAlpha:               return 87;
            case ShaderDesc::ST_Position3dTexTGCxformAcEAlphaMul:            return 88;
            case ShaderDesc::ST_BatchPosition3dTexTGCxformAcEAlpha:          return 231;
            case ShaderDesc::ST_BatchPosition3dTexTGCxformAcEAlphaMul:       return 232;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxformAcEAlpha:      return 375;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxformAcEAlphaMul:   return 376;
            case ShaderDesc::ST_TexTGCxformAcInv:                            return 14;
            case ShaderDesc::ST_BatchTexTGCxformAcInv:                       return 158;
            case ShaderDesc::ST_InstancedTexTGCxformAcInv:                   return 302;
            case ShaderDesc::ST_Position3dTexTGCxformAcInv:                  return 86;
            case ShaderDesc::ST_BatchPosition3dTexTGCxformAcInv:             return 230;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxformAcInv:         return 374;
            case ShaderDesc::ST_TexTGCxformAcEAlphaInv:                      return 17;
            case ShaderDesc::ST_BatchTexTGCxformAcEAlphaInv:                 return 161;
            case ShaderDesc::ST_InstancedTexTGCxformAcEAlphaInv:             return 305;
            case ShaderDesc::ST_Position3dTexTGCxformAcEAlphaInv:            return 89;
            case ShaderDesc::ST_BatchPosition3dTexTGCxformAcEAlphaInv:       return 233;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxformAcEAlphaInv:   return 377;
            case ShaderDesc::ST_Vertex:                                      return 18;
            case ShaderDesc::ST_VertexMul:                                   return 19;
            case ShaderDesc::ST_BatchVertex:                                 return 162;
            case ShaderDesc::ST_BatchVertexMul:                              return 163;
            case ShaderDesc::ST_InstancedVertex:                             return 306;
            case ShaderDesc::ST_InstancedVertexMul:                          return 307;
            case ShaderDesc::ST_Position3dVertex:                            return 90;
            case ShaderDesc::ST_Position3dVertexMul:                         return 91;
            case ShaderDesc::ST_BatchPosition3dVertex:                       return 234;
            case ShaderDesc::ST_BatchPosition3dVertexMul:                    return 235;
            case ShaderDesc::ST_InstancedPosition3dVertex:                   return 378;
            case ShaderDesc::ST_InstancedPosition3dVertexMul:                return 379;
            case ShaderDesc::ST_VertexCxform:                                return 24;
            case ShaderDesc::ST_VertexCxformMul:                             return 25;
            case ShaderDesc::ST_BatchVertexCxform:                           return 168;
            case ShaderDesc::ST_BatchVertexCxformMul:                        return 169;
            case ShaderDesc::ST_InstancedVertexCxform:                       return 312;
            case ShaderDesc::ST_InstancedVertexCxformMul:                    return 313;
            case ShaderDesc::ST_Position3dVertexCxform:                      return 96;
            case ShaderDesc::ST_Position3dVertexCxformMul:                   return 97;
            case ShaderDesc::ST_BatchPosition3dVertexCxform:                 return 240;
            case ShaderDesc::ST_BatchPosition3dVertexCxformMul:              return 241;
            case ShaderDesc::ST_InstancedPosition3dVertexCxform:             return 384;
            case ShaderDesc::ST_InstancedPosition3dVertexCxformMul:          return 385;
            case ShaderDesc::ST_VertexEAlpha:                                return 21;
            case ShaderDesc::ST_VertexEAlphaMul:                             return 22;
            case ShaderDesc::ST_BatchVertexEAlpha:                           return 165;
            case ShaderDesc::ST_BatchVertexEAlphaMul:                        return 166;
            case ShaderDesc::ST_InstancedVertexEAlpha:                       return 309;
            case ShaderDesc::ST_InstancedVertexEAlphaMul:                    return 310;
            case ShaderDesc::ST_Position3dVertexEAlpha:                      return 93;
            case ShaderDesc::ST_Position3dVertexEAlphaMul:                   return 94;
            case ShaderDesc::ST_BatchPosition3dVertexEAlpha:                 return 237;
            case ShaderDesc::ST_BatchPosition3dVertexEAlphaMul:              return 238;
            case ShaderDesc::ST_InstancedPosition3dVertexEAlpha:             return 381;
            case ShaderDesc::ST_InstancedPosition3dVertexEAlphaMul:          return 382;
            case ShaderDesc::ST_VertexCxformEAlpha:                          return 27;
            case ShaderDesc::ST_VertexCxformEAlphaMul:                       return 28;
            case ShaderDesc::ST_BatchVertexCxformEAlpha:                     return 171;
            case ShaderDesc::ST_BatchVertexCxformEAlphaMul:                  return 172;
            case ShaderDesc::ST_InstancedVertexCxformEAlpha:                 return 315;
            case ShaderDesc::ST_InstancedVertexCxformEAlphaMul:              return 316;
            case ShaderDesc::ST_Position3dVertexCxformEAlpha:                return 99;
            case ShaderDesc::ST_Position3dVertexCxformEAlphaMul:             return 100;
            case ShaderDesc::ST_BatchPosition3dVertexCxformEAlpha:           return 243;
            case ShaderDesc::ST_BatchPosition3dVertexCxformEAlphaMul:        return 244;
            case ShaderDesc::ST_InstancedPosition3dVertexCxformEAlpha:       return 387;
            case ShaderDesc::ST_InstancedPosition3dVertexCxformEAlphaMul:    return 388;
            case ShaderDesc::ST_VertexInv:                                   return 20;
            case ShaderDesc::ST_BatchVertexInv:                              return 164;
            case ShaderDesc::ST_InstancedVertexInv:                          return 308;
            case ShaderDesc::ST_Position3dVertexInv:                         return 92;
            case ShaderDesc::ST_BatchPosition3dVertexInv:                    return 236;
            case ShaderDesc::ST_InstancedPosition3dVertexInv:                return 380;
            case ShaderDesc::ST_VertexCxformInv:                             return 26;
            case ShaderDesc::ST_BatchVertexCxformInv:                        return 170;
            case ShaderDesc::ST_InstancedVertexCxformInv:                    return 314;
            case ShaderDesc::ST_Position3dVertexCxformInv:                   return 98;
            case ShaderDesc::ST_BatchPosition3dVertexCxformInv:              return 242;
            case ShaderDesc::ST_InstancedPosition3dVertexCxformInv:          return 386;
            case ShaderDesc::ST_VertexEAlphaInv:                             return 23;
            case ShaderDesc::ST_BatchVertexEAlphaInv:                        return 167;
            case ShaderDesc::ST_InstancedVertexEAlphaInv:                    return 311;
            case ShaderDesc::ST_Position3dVertexEAlphaInv:                   return 95;
            case ShaderDesc::ST_BatchPosition3dVertexEAlphaInv:              return 239;
            case ShaderDesc::ST_InstancedPosition3dVertexEAlphaInv:          return 383;
            case ShaderDesc::ST_VertexCxformEAlphaInv:                       return 29;
            case ShaderDesc::ST_BatchVertexCxformEAlphaInv:                  return 173;
            case ShaderDesc::ST_InstancedVertexCxformEAlphaInv:              return 317;
            case ShaderDesc::ST_Position3dVertexCxformEAlphaInv:             return 101;
            case ShaderDesc::ST_BatchPosition3dVertexCxformEAlphaInv:        return 245;
            case ShaderDesc::ST_InstancedPosition3dVertexCxformEAlphaInv:    return 389;
            case ShaderDesc::ST_VertexCxformAc:                              return 30;
            case ShaderDesc::ST_VertexCxformAcMul:                           return 31;
            case ShaderDesc::ST_BatchVertexCxformAc:                         return 174;
            case ShaderDesc::ST_BatchVertexCxformAcMul:                      return 175;
            case ShaderDesc::ST_InstancedVertexCxformAc:                     return 318;
            case ShaderDesc::ST_InstancedVertexCxformAcMul:                  return 319;
            case ShaderDesc::ST_Position3dVertexCxformAc:                    return 102;
            case ShaderDesc::ST_Position3dVertexCxformAcMul:                 return 103;
            case ShaderDesc::ST_BatchPosition3dVertexCxformAc:               return 246;
            case ShaderDesc::ST_BatchPosition3dVertexCxformAcMul:            return 247;
            case ShaderDesc::ST_InstancedPosition3dVertexCxformAc:           return 390;
            case ShaderDesc::ST_InstancedPosition3dVertexCxformAcMul:        return 391;
            case ShaderDesc::ST_VertexCxformAcEAlpha:                        return 33;
            case ShaderDesc::ST_VertexCxformAcEAlphaMul:                     return 34;
            case ShaderDesc::ST_BatchVertexCxformAcEAlpha:                   return 177;
            case ShaderDesc::ST_BatchVertexCxformAcEAlphaMul:                return 178;
            case ShaderDesc::ST_InstancedVertexCxformAcEAlpha:               return 321;
            case ShaderDesc::ST_InstancedVertexCxformAcEAlphaMul:            return 322;
            case ShaderDesc::ST_Position3dVertexCxformAcEAlpha:              return 105;
            case ShaderDesc::ST_Position3dVertexCxformAcEAlphaMul:           return 106;
            case ShaderDesc::ST_BatchPosition3dVertexCxformAcEAlpha:         return 249;
            case ShaderDesc::ST_BatchPosition3dVertexCxformAcEAlphaMul:      return 250;
            case ShaderDesc::ST_InstancedPosition3dVertexCxformAcEAlpha:     return 393;
            case ShaderDesc::ST_InstancedPosition3dVertexCxformAcEAlphaMul:  return 394;
            case ShaderDesc::ST_VertexCxformAcInv:                           return 32;
            case ShaderDesc::ST_BatchVertexCxformAcInv:                      return 176;
            case ShaderDesc::ST_InstancedVertexCxformAcInv:                  return 320;
            case ShaderDesc::ST_Position3dVertexCxformAcInv:                 return 104;
            case ShaderDesc::ST_BatchPosition3dVertexCxformAcInv:            return 248;
            case ShaderDesc::ST_InstancedPosition3dVertexCxformAcInv:        return 392;
            case ShaderDesc::ST_VertexCxformAcEAlphaInv:                     return 35;
            case ShaderDesc::ST_BatchVertexCxformAcEAlphaInv:                return 179;
            case ShaderDesc::ST_InstancedVertexCxformAcEAlphaInv:            return 323;
            case ShaderDesc::ST_Position3dVertexCxformAcEAlphaInv:           return 107;
            case ShaderDesc::ST_BatchPosition3dVertexCxformAcEAlphaInv:      return 251;
            case ShaderDesc::ST_InstancedPosition3dVertexCxformAcEAlphaInv:  return 395;
            case ShaderDesc::ST_TexTGTexTG:                                  return 36;
            case ShaderDesc::ST_TexTGTexTGMul:                               return 37;
            case ShaderDesc::ST_BatchTexTGTexTG:                             return 180;
            case ShaderDesc::ST_BatchTexTGTexTGMul:                          return 181;
            case ShaderDesc::ST_InstancedTexTGTexTG:                         return 324;
            case ShaderDesc::ST_InstancedTexTGTexTGMul:                      return 325;
            case ShaderDesc::ST_Position3dTexTGTexTG:                        return 108;
            case ShaderDesc::ST_Position3dTexTGTexTGMul:                     return 109;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTG:                   return 252;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGMul:                return 253;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTG:               return 396;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGMul:            return 397;
            case ShaderDesc::ST_TexTGTexTGCxform:                            return 42;
            case ShaderDesc::ST_TexTGTexTGCxformMul:                         return 43;
            case ShaderDesc::ST_BatchTexTGTexTGCxform:                       return 186;
            case ShaderDesc::ST_BatchTexTGTexTGCxformMul:                    return 187;
            case ShaderDesc::ST_InstancedTexTGTexTGCxform:                   return 330;
            case ShaderDesc::ST_InstancedTexTGTexTGCxformMul:                return 331;
            case ShaderDesc::ST_Position3dTexTGTexTGCxform:                  return 114;
            case ShaderDesc::ST_Position3dTexTGTexTGCxformMul:               return 115;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxform:             return 258;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxformMul:          return 259;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxform:         return 402;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxformMul:      return 403;
            case ShaderDesc::ST_TexTGTexTGEAlpha:                            return 39;
            case ShaderDesc::ST_TexTGTexTGEAlphaMul:                         return 40;
            case ShaderDesc::ST_BatchTexTGTexTGEAlpha:                       return 183;
            case ShaderDesc::ST_BatchTexTGTexTGEAlphaMul:                    return 184;
            case ShaderDesc::ST_InstancedTexTGTexTGEAlpha:                   return 327;
            case ShaderDesc::ST_InstancedTexTGTexTGEAlphaMul:                return 328;
            case ShaderDesc::ST_Position3dTexTGTexTGEAlpha:                  return 111;
            case ShaderDesc::ST_Position3dTexTGTexTGEAlphaMul:               return 112;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGEAlpha:             return 255;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGEAlphaMul:          return 256;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGEAlpha:         return 399;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGEAlphaMul:      return 400;
            case ShaderDesc::ST_TexTGTexTGCxformEAlpha:                      return 45;
            case ShaderDesc::ST_TexTGTexTGCxformEAlphaMul:                   return 46;
            case ShaderDesc::ST_BatchTexTGTexTGCxformEAlpha:                 return 189;
            case ShaderDesc::ST_BatchTexTGTexTGCxformEAlphaMul:              return 190;
            case ShaderDesc::ST_InstancedTexTGTexTGCxformEAlpha:             return 333;
            case ShaderDesc::ST_InstancedTexTGTexTGCxformEAlphaMul:          return 334;
            case ShaderDesc::ST_Position3dTexTGTexTGCxformEAlpha:            return 117;
            case ShaderDesc::ST_Position3dTexTGTexTGCxformEAlphaMul:         return 118;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxformEAlpha:       return 261;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxformEAlphaMul:    return 262;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxformEAlpha:   return 405;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxformEAlphaMul: return 406;
            case ShaderDesc::ST_TexTGTexTGInv:                               return 38;
            case ShaderDesc::ST_BatchTexTGTexTGInv:                          return 182;
            case ShaderDesc::ST_InstancedTexTGTexTGInv:                      return 326;
            case ShaderDesc::ST_Position3dTexTGTexTGInv:                     return 110;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGInv:                return 254;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGInv:            return 398;
            case ShaderDesc::ST_TexTGTexTGCxformInv:                         return 44;
            case ShaderDesc::ST_BatchTexTGTexTGCxformInv:                    return 188;
            case ShaderDesc::ST_InstancedTexTGTexTGCxformInv:                return 332;
            case ShaderDesc::ST_Position3dTexTGTexTGCxformInv:               return 116;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxformInv:          return 260;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxformInv:      return 404;
            case ShaderDesc::ST_TexTGTexTGEAlphaInv:                         return 41;
            case ShaderDesc::ST_BatchTexTGTexTGEAlphaInv:                    return 185;
            case ShaderDesc::ST_InstancedTexTGTexTGEAlphaInv:                return 329;
            case ShaderDesc::ST_Position3dTexTGTexTGEAlphaInv:               return 113;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGEAlphaInv:          return 257;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGEAlphaInv:      return 401;
            case ShaderDesc::ST_TexTGTexTGCxformEAlphaInv:                   return 47;
            case ShaderDesc::ST_BatchTexTGTexTGCxformEAlphaInv:              return 191;
            case ShaderDesc::ST_InstancedTexTGTexTGCxformEAlphaInv:          return 335;
            case ShaderDesc::ST_Position3dTexTGTexTGCxformEAlphaInv:         return 119;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxformEAlphaInv:    return 263;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxformEAlphaInv: return 407;
            case ShaderDesc::ST_TexTGTexTGCxformAc:                          return 48;
            case ShaderDesc::ST_TexTGTexTGCxformAcMul:                       return 49;
            case ShaderDesc::ST_BatchTexTGTexTGCxformAc:                     return 192;
            case ShaderDesc::ST_BatchTexTGTexTGCxformAcMul:                  return 193;
            case ShaderDesc::ST_InstancedTexTGTexTGCxformAc:                 return 336;
            case ShaderDesc::ST_InstancedTexTGTexTGCxformAcMul:              return 337;
            case ShaderDesc::ST_Position3dTexTGTexTGCxformAc:                return 120;
            case ShaderDesc::ST_Position3dTexTGTexTGCxformAcMul:             return 121;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxformAc:           return 264;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxformAcMul:        return 265;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxformAc:       return 408;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxformAcMul:    return 409;
            case ShaderDesc::ST_TexTGTexTGCxformAcEAlpha:                    return 51;
            case ShaderDesc::ST_TexTGTexTGCxformAcEAlphaMul:                 return 52;
            case ShaderDesc::ST_BatchTexTGTexTGCxformAcEAlpha:               return 195;
            case ShaderDesc::ST_BatchTexTGTexTGCxformAcEAlphaMul:            return 196;
            case ShaderDesc::ST_InstancedTexTGTexTGCxformAcEAlpha:           return 339;
            case ShaderDesc::ST_InstancedTexTGTexTGCxformAcEAlphaMul:        return 340;
            case ShaderDesc::ST_Position3dTexTGTexTGCxformAcEAlpha:          return 123;
            case ShaderDesc::ST_Position3dTexTGTexTGCxformAcEAlphaMul:       return 124;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxformAcEAlpha:     return 267;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxformAcEAlphaMul:  return 268;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxformAcEAlpha: return 411;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxformAcEAlphaMul: return 412;
            case ShaderDesc::ST_TexTGTexTGCxformAcInv:                       return 50;
            case ShaderDesc::ST_BatchTexTGTexTGCxformAcInv:                  return 194;
            case ShaderDesc::ST_InstancedTexTGTexTGCxformAcInv:              return 338;
            case ShaderDesc::ST_Position3dTexTGTexTGCxformAcInv:             return 122;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxformAcInv:        return 266;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxformAcInv:    return 410;
            case ShaderDesc::ST_TexTGTexTGCxformAcEAlphaInv:                 return 53;
            case ShaderDesc::ST_BatchTexTGTexTGCxformAcEAlphaInv:            return 197;
            case ShaderDesc::ST_InstancedTexTGTexTGCxformAcEAlphaInv:        return 341;
            case ShaderDesc::ST_Position3dTexTGTexTGCxformAcEAlphaInv:       return 125;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxformAcEAlphaInv:  return 269;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxformAcEAlphaInv: return 413;
            case ShaderDesc::ST_TexTGVertex:                                 return 54;
            case ShaderDesc::ST_TexTGVertexMul:                              return 55;
            case ShaderDesc::ST_BatchTexTGVertex:                            return 198;
            case ShaderDesc::ST_BatchTexTGVertexMul:                         return 199;
            case ShaderDesc::ST_InstancedTexTGVertex:                        return 342;
            case ShaderDesc::ST_InstancedTexTGVertexMul:                     return 343;
            case ShaderDesc::ST_Position3dTexTGVertex:                       return 126;
            case ShaderDesc::ST_Position3dTexTGVertexMul:                    return 127;
            case ShaderDesc::ST_BatchPosition3dTexTGVertex:                  return 270;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexMul:               return 271;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertex:              return 414;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexMul:           return 415;
            case ShaderDesc::ST_TexTGVertexCxform:                           return 60;
            case ShaderDesc::ST_TexTGVertexCxformMul:                        return 61;
            case ShaderDesc::ST_BatchTexTGVertexCxform:                      return 204;
            case ShaderDesc::ST_BatchTexTGVertexCxformMul:                   return 205;
            case ShaderDesc::ST_InstancedTexTGVertexCxform:                  return 348;
            case ShaderDesc::ST_InstancedTexTGVertexCxformMul:               return 349;
            case ShaderDesc::ST_Position3dTexTGVertexCxform:                 return 132;
            case ShaderDesc::ST_Position3dTexTGVertexCxformMul:              return 133;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxform:            return 276;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxformMul:         return 277;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxform:        return 420;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxformMul:     return 421;
            case ShaderDesc::ST_TexTGVertexEAlpha:                           return 57;
            case ShaderDesc::ST_TexTGVertexEAlphaMul:                        return 58;
            case ShaderDesc::ST_BatchTexTGVertexEAlpha:                      return 201;
            case ShaderDesc::ST_BatchTexTGVertexEAlphaMul:                   return 202;
            case ShaderDesc::ST_InstancedTexTGVertexEAlpha:                  return 345;
            case ShaderDesc::ST_InstancedTexTGVertexEAlphaMul:               return 346;
            case ShaderDesc::ST_Position3dTexTGVertexEAlpha:                 return 129;
            case ShaderDesc::ST_Position3dTexTGVertexEAlphaMul:              return 130;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexEAlpha:            return 273;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexEAlphaMul:         return 274;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexEAlpha:        return 417;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexEAlphaMul:     return 418;
            case ShaderDesc::ST_TexTGVertexCxformEAlpha:                     return 63;
            case ShaderDesc::ST_TexTGVertexCxformEAlphaMul:                  return 64;
            case ShaderDesc::ST_BatchTexTGVertexCxformEAlpha:                return 207;
            case ShaderDesc::ST_BatchTexTGVertexCxformEAlphaMul:             return 208;
            case ShaderDesc::ST_InstancedTexTGVertexCxformEAlpha:            return 351;
            case ShaderDesc::ST_InstancedTexTGVertexCxformEAlphaMul:         return 352;
            case ShaderDesc::ST_Position3dTexTGVertexCxformEAlpha:           return 135;
            case ShaderDesc::ST_Position3dTexTGVertexCxformEAlphaMul:        return 136;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxformEAlpha:      return 279;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxformEAlphaMul:   return 280;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxformEAlpha:  return 423;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxformEAlphaMul: return 424;
            case ShaderDesc::ST_TexTGVertexInv:                              return 56;
            case ShaderDesc::ST_BatchTexTGVertexInv:                         return 200;
            case ShaderDesc::ST_InstancedTexTGVertexInv:                     return 344;
            case ShaderDesc::ST_Position3dTexTGVertexInv:                    return 128;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexInv:               return 272;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexInv:           return 416;
            case ShaderDesc::ST_TexTGVertexCxformInv:                        return 62;
            case ShaderDesc::ST_BatchTexTGVertexCxformInv:                   return 206;
            case ShaderDesc::ST_InstancedTexTGVertexCxformInv:               return 350;
            case ShaderDesc::ST_Position3dTexTGVertexCxformInv:              return 134;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxformInv:         return 278;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxformInv:     return 422;
            case ShaderDesc::ST_TexTGVertexEAlphaInv:                        return 59;
            case ShaderDesc::ST_BatchTexTGVertexEAlphaInv:                   return 203;
            case ShaderDesc::ST_InstancedTexTGVertexEAlphaInv:               return 347;
            case ShaderDesc::ST_Position3dTexTGVertexEAlphaInv:              return 131;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexEAlphaInv:         return 275;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexEAlphaInv:     return 419;
            case ShaderDesc::ST_TexTGVertexCxformEAlphaInv:                  return 65;
            case ShaderDesc::ST_BatchTexTGVertexCxformEAlphaInv:             return 209;
            case ShaderDesc::ST_InstancedTexTGVertexCxformEAlphaInv:         return 353;
            case ShaderDesc::ST_Position3dTexTGVertexCxformEAlphaInv:        return 137;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxformEAlphaInv:   return 281;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxformEAlphaInv: return 425;
            case ShaderDesc::ST_TexTGVertexCxformAc:                         return 66;
            case ShaderDesc::ST_TexTGVertexCxformAcMul:                      return 67;
            case ShaderDesc::ST_BatchTexTGVertexCxformAc:                    return 210;
            case ShaderDesc::ST_BatchTexTGVertexCxformAcMul:                 return 211;
            case ShaderDesc::ST_InstancedTexTGVertexCxformAc:                return 354;
            case ShaderDesc::ST_InstancedTexTGVertexCxformAcMul:             return 355;
            case ShaderDesc::ST_Position3dTexTGVertexCxformAc:               return 138;
            case ShaderDesc::ST_Position3dTexTGVertexCxformAcMul:            return 139;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxformAc:          return 282;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxformAcMul:       return 283;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxformAc:      return 426;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxformAcMul:   return 427;
            case ShaderDesc::ST_TexTGVertexCxformAcEAlpha:                   return 69;
            case ShaderDesc::ST_TexTGVertexCxformAcEAlphaMul:                return 70;
            case ShaderDesc::ST_BatchTexTGVertexCxformAcEAlpha:              return 213;
            case ShaderDesc::ST_BatchTexTGVertexCxformAcEAlphaMul:           return 214;
            case ShaderDesc::ST_InstancedTexTGVertexCxformAcEAlpha:          return 357;
            case ShaderDesc::ST_InstancedTexTGVertexCxformAcEAlphaMul:       return 358;
            case ShaderDesc::ST_Position3dTexTGVertexCxformAcEAlpha:         return 141;
            case ShaderDesc::ST_Position3dTexTGVertexCxformAcEAlphaMul:      return 142;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxformAcEAlpha:    return 285;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxformAcEAlphaMul: return 286;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxformAcEAlpha: return 429;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxformAcEAlphaMul: return 430;
            case ShaderDesc::ST_TexTGVertexCxformAcInv:                      return 68;
            case ShaderDesc::ST_BatchTexTGVertexCxformAcInv:                 return 212;
            case ShaderDesc::ST_InstancedTexTGVertexCxformAcInv:             return 356;
            case ShaderDesc::ST_Position3dTexTGVertexCxformAcInv:            return 140;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxformAcInv:       return 284;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxformAcInv:   return 428;
            case ShaderDesc::ST_TexTGVertexCxformAcEAlphaInv:                return 71;
            case ShaderDesc::ST_BatchTexTGVertexCxformAcEAlphaInv:           return 215;
            case ShaderDesc::ST_InstancedTexTGVertexCxformAcEAlphaInv:       return 359;
            case ShaderDesc::ST_Position3dTexTGVertexCxformAcEAlphaInv:      return 143;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxformAcEAlphaInv: return 287;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxformAcEAlphaInv: return 431;
            case ShaderDesc::ST_Solid:                                       return 432;
            case ShaderDesc::ST_SolidMul:                                    return 433;
            case ShaderDesc::ST_BatchSolid:                                  return 456;
            case ShaderDesc::ST_BatchSolidMul:                               return 457;
            case ShaderDesc::ST_InstancedSolid:                              return 480;
            case ShaderDesc::ST_InstancedSolidMul:                           return 481;
            case ShaderDesc::ST_Position3dSolid:                             return 444;
            case ShaderDesc::ST_Position3dSolidMul:                          return 445;
            case ShaderDesc::ST_BatchPosition3dSolid:                        return 468;
            case ShaderDesc::ST_BatchPosition3dSolidMul:                     return 469;
            case ShaderDesc::ST_InstancedPosition3dSolid:                    return 492;
            case ShaderDesc::ST_InstancedPosition3dSolidMul:                 return 493;
            case ShaderDesc::ST_SolidInv:                                    return 434;
            case ShaderDesc::ST_BatchSolidInv:                               return 458;
            case ShaderDesc::ST_InstancedSolidInv:                           return 482;
            case ShaderDesc::ST_Position3dSolidInv:                          return 446;
            case ShaderDesc::ST_BatchPosition3dSolidInv:                     return 470;
            case ShaderDesc::ST_InstancedPosition3dSolidInv:                 return 494;
            case ShaderDesc::ST_Text:                                        return 435;
            case ShaderDesc::ST_TextMul:                                     return 436;
            case ShaderDesc::ST_BatchText:                                   return 459;
            case ShaderDesc::ST_BatchTextMul:                                return 460;
            case ShaderDesc::ST_InstancedText:                               return 483;
            case ShaderDesc::ST_InstancedTextMul:                            return 484;
            case ShaderDesc::ST_Position3dText:                              return 447;
            case ShaderDesc::ST_Position3dTextMul:                           return 448;
            case ShaderDesc::ST_BatchPosition3dText:                         return 471;
            case ShaderDesc::ST_BatchPosition3dTextMul:                      return 472;
            case ShaderDesc::ST_InstancedPosition3dText:                     return 495;
            case ShaderDesc::ST_InstancedPosition3dTextMul:                  return 496;
            case ShaderDesc::ST_TextInv:                                     return 437;
            case ShaderDesc::ST_BatchTextInv:                                return 461;
            case ShaderDesc::ST_InstancedTextInv:                            return 485;
            case ShaderDesc::ST_Position3dTextInv:                           return 449;
            case ShaderDesc::ST_BatchPosition3dTextInv:                      return 473;
            case ShaderDesc::ST_InstancedPosition3dTextInv:                  return 497;
            case ShaderDesc::ST_TextColor:                                   return 438;
            case ShaderDesc::ST_TextColorMul:                                return 439;
            case ShaderDesc::ST_BatchTextColor:                              return 462;
            case ShaderDesc::ST_BatchTextColorMul:                           return 463;
            case ShaderDesc::ST_InstancedTextColor:                          return 486;
            case ShaderDesc::ST_InstancedTextColorMul:                       return 487;
            case ShaderDesc::ST_Position3dTextColor:                         return 450;
            case ShaderDesc::ST_Position3dTextColorMul:                      return 451;
            case ShaderDesc::ST_BatchPosition3dTextColor:                    return 474;
            case ShaderDesc::ST_BatchPosition3dTextColorMul:                 return 475;
            case ShaderDesc::ST_InstancedPosition3dTextColor:                return 498;
            case ShaderDesc::ST_InstancedPosition3dTextColorMul:             return 499;
            case ShaderDesc::ST_TextColorCxform:                             return 441;
            case ShaderDesc::ST_TextColorCxformMul:                          return 442;
            case ShaderDesc::ST_BatchTextColorCxform:                        return 465;
            case ShaderDesc::ST_BatchTextColorCxformMul:                     return 466;
            case ShaderDesc::ST_InstancedTextColorCxform:                    return 489;
            case ShaderDesc::ST_InstancedTextColorCxformMul:                 return 490;
            case ShaderDesc::ST_Position3dTextColorCxform:                   return 453;
            case ShaderDesc::ST_Position3dTextColorCxformMul:                return 454;
            case ShaderDesc::ST_BatchPosition3dTextColorCxform:              return 477;
            case ShaderDesc::ST_BatchPosition3dTextColorCxformMul:           return 478;
            case ShaderDesc::ST_InstancedPosition3dTextColorCxform:          return 501;
            case ShaderDesc::ST_InstancedPosition3dTextColorCxformMul:       return 502;
            case ShaderDesc::ST_TextColorInv:                                return 440;
            case ShaderDesc::ST_BatchTextColorInv:                           return 464;
            case ShaderDesc::ST_InstancedTextColorInv:                       return 488;
            case ShaderDesc::ST_Position3dTextColorInv:                      return 452;
            case ShaderDesc::ST_BatchPosition3dTextColorInv:                 return 476;
            case ShaderDesc::ST_InstancedPosition3dTextColorInv:             return 500;
            case ShaderDesc::ST_TextColorCxformInv:                          return 443;
            case ShaderDesc::ST_BatchTextColorCxformInv:                     return 467;
            case ShaderDesc::ST_InstancedTextColorCxformInv:                 return 491;
            case ShaderDesc::ST_Position3dTextColorCxformInv:                return 455;
            case ShaderDesc::ST_BatchPosition3dTextColorCxformInv:           return 479;
            case ShaderDesc::ST_InstancedPosition3dTextColorCxformInv:       return 503;
            case ShaderDesc::ST_YUV:                                         return 504;
            case ShaderDesc::ST_YUVMul:                                      return 505;
            case ShaderDesc::ST_BatchYUV:                                    return 564;
            case ShaderDesc::ST_BatchYUVMul:                                 return 565;
            case ShaderDesc::ST_InstancedYUV:                                return 624;
            case ShaderDesc::ST_InstancedYUVMul:                             return 625;
            case ShaderDesc::ST_Position3dYUV:                               return 534;
            case ShaderDesc::ST_Position3dYUVMul:                            return 535;
            case ShaderDesc::ST_BatchPosition3dYUV:                          return 594;
            case ShaderDesc::ST_BatchPosition3dYUVMul:                       return 595;
            case ShaderDesc::ST_InstancedPosition3dYUV:                      return 654;
            case ShaderDesc::ST_InstancedPosition3dYUVMul:                   return 655;
            case ShaderDesc::ST_YUVCxform:                                   return 508;
            case ShaderDesc::ST_YUVCxformMul:                                return 509;
            case ShaderDesc::ST_BatchYUVCxform:                              return 568;
            case ShaderDesc::ST_BatchYUVCxformMul:                           return 569;
            case ShaderDesc::ST_InstancedYUVCxform:                          return 628;
            case ShaderDesc::ST_InstancedYUVCxformMul:                       return 629;
            case ShaderDesc::ST_Position3dYUVCxform:                         return 538;
            case ShaderDesc::ST_Position3dYUVCxformMul:                      return 539;
            case ShaderDesc::ST_BatchPosition3dYUVCxform:                    return 598;
            case ShaderDesc::ST_BatchPosition3dYUVCxformMul:                 return 599;
            case ShaderDesc::ST_InstancedPosition3dYUVCxform:                return 658;
            case ShaderDesc::ST_InstancedPosition3dYUVCxformMul:             return 659;
            case ShaderDesc::ST_YUVEAlpha:                                   return 506;
            case ShaderDesc::ST_YUVEAlphaMul:                                return 507;
            case ShaderDesc::ST_BatchYUVEAlpha:                              return 566;
            case ShaderDesc::ST_BatchYUVEAlphaMul:                           return 567;
            case ShaderDesc::ST_InstancedYUVEAlpha:                          return 626;
            case ShaderDesc::ST_InstancedYUVEAlphaMul:                       return 627;
            case ShaderDesc::ST_Position3dYUVEAlpha:                         return 536;
            case ShaderDesc::ST_Position3dYUVEAlphaMul:                      return 537;
            case ShaderDesc::ST_BatchPosition3dYUVEAlpha:                    return 596;
            case ShaderDesc::ST_BatchPosition3dYUVEAlphaMul:                 return 597;
            case ShaderDesc::ST_InstancedPosition3dYUVEAlpha:                return 656;
            case ShaderDesc::ST_InstancedPosition3dYUVEAlphaMul:             return 657;
            case ShaderDesc::ST_YUVCxformEAlpha:                             return 510;
            case ShaderDesc::ST_YUVCxformEAlphaMul:                          return 511;
            case ShaderDesc::ST_BatchYUVCxformEAlpha:                        return 570;
            case ShaderDesc::ST_BatchYUVCxformEAlphaMul:                     return 571;
            case ShaderDesc::ST_InstancedYUVCxformEAlpha:                    return 630;
            case ShaderDesc::ST_InstancedYUVCxformEAlphaMul:                 return 631;
            case ShaderDesc::ST_Position3dYUVCxformEAlpha:                   return 540;
            case ShaderDesc::ST_Position3dYUVCxformEAlphaMul:                return 541;
            case ShaderDesc::ST_BatchPosition3dYUVCxformEAlpha:              return 600;
            case ShaderDesc::ST_BatchPosition3dYUVCxformEAlphaMul:           return 601;
            case ShaderDesc::ST_InstancedPosition3dYUVCxformEAlpha:          return 660;
            case ShaderDesc::ST_InstancedPosition3dYUVCxformEAlphaMul:       return 661;
            case ShaderDesc::ST_YUVCxformAc:                                 return 512;
            case ShaderDesc::ST_YUVCxformAcMul:                              return 513;
            case ShaderDesc::ST_BatchYUVCxformAc:                            return 572;
            case ShaderDesc::ST_BatchYUVCxformAcMul:                         return 573;
            case ShaderDesc::ST_InstancedYUVCxformAc:                        return 632;
            case ShaderDesc::ST_InstancedYUVCxformAcMul:                     return 633;
            case ShaderDesc::ST_Position3dYUVCxformAc:                       return 542;
            case ShaderDesc::ST_Position3dYUVCxformAcMul:                    return 543;
            case ShaderDesc::ST_BatchPosition3dYUVCxformAc:                  return 602;
            case ShaderDesc::ST_BatchPosition3dYUVCxformAcMul:               return 603;
            case ShaderDesc::ST_InstancedPosition3dYUVCxformAc:              return 662;
            case ShaderDesc::ST_InstancedPosition3dYUVCxformAcMul:           return 663;
            case ShaderDesc::ST_YUVCxformAcEAlpha:                           return 514;
            case ShaderDesc::ST_YUVCxformAcEAlphaMul:                        return 515;
            case ShaderDesc::ST_BatchYUVCxformAcEAlpha:                      return 574;
            case ShaderDesc::ST_BatchYUVCxformAcEAlphaMul:                   return 575;
            case ShaderDesc::ST_InstancedYUVCxformAcEAlpha:                  return 634;
            case ShaderDesc::ST_InstancedYUVCxformAcEAlphaMul:               return 635;
            case ShaderDesc::ST_Position3dYUVCxformAcEAlpha:                 return 544;
            case ShaderDesc::ST_Position3dYUVCxformAcEAlphaMul:              return 545;
            case ShaderDesc::ST_BatchPosition3dYUVCxformAcEAlpha:            return 604;
            case ShaderDesc::ST_BatchPosition3dYUVCxformAcEAlphaMul:         return 605;
            case ShaderDesc::ST_InstancedPosition3dYUVCxformAcEAlpha:        return 664;
            case ShaderDesc::ST_InstancedPosition3dYUVCxformAcEAlphaMul:     return 665;
            case ShaderDesc::ST_YUVA:                                        return 516;
            case ShaderDesc::ST_YUVAMul:                                     return 517;
            case ShaderDesc::ST_BatchYUVA:                                   return 576;
            case ShaderDesc::ST_BatchYUVAMul:                                return 577;
            case ShaderDesc::ST_InstancedYUVA:                               return 636;
            case ShaderDesc::ST_InstancedYUVAMul:                            return 637;
            case ShaderDesc::ST_Position3dYUVA:                              return 546;
            case ShaderDesc::ST_Position3dYUVAMul:                           return 547;
            case ShaderDesc::ST_BatchPosition3dYUVA:                         return 606;
            case ShaderDesc::ST_BatchPosition3dYUVAMul:                      return 607;
            case ShaderDesc::ST_InstancedPosition3dYUVA:                     return 666;
            case ShaderDesc::ST_InstancedPosition3dYUVAMul:                  return 667;
            case ShaderDesc::ST_YUVACxform:                                  return 522;
            case ShaderDesc::ST_YUVACxformMul:                               return 523;
            case ShaderDesc::ST_BatchYUVACxform:                             return 582;
            case ShaderDesc::ST_BatchYUVACxformMul:                          return 583;
            case ShaderDesc::ST_InstancedYUVACxform:                         return 642;
            case ShaderDesc::ST_InstancedYUVACxformMul:                      return 643;
            case ShaderDesc::ST_Position3dYUVACxform:                        return 552;
            case ShaderDesc::ST_Position3dYUVACxformMul:                     return 553;
            case ShaderDesc::ST_BatchPosition3dYUVACxform:                   return 612;
            case ShaderDesc::ST_BatchPosition3dYUVACxformMul:                return 613;
            case ShaderDesc::ST_InstancedPosition3dYUVACxform:               return 672;
            case ShaderDesc::ST_InstancedPosition3dYUVACxformMul:            return 673;
            case ShaderDesc::ST_YUVAEAlpha:                                  return 519;
            case ShaderDesc::ST_YUVAEAlphaMul:                               return 520;
            case ShaderDesc::ST_BatchYUVAEAlpha:                             return 579;
            case ShaderDesc::ST_BatchYUVAEAlphaMul:                          return 580;
            case ShaderDesc::ST_InstancedYUVAEAlpha:                         return 639;
            case ShaderDesc::ST_InstancedYUVAEAlphaMul:                      return 640;
            case ShaderDesc::ST_Position3dYUVAEAlpha:                        return 549;
            case ShaderDesc::ST_Position3dYUVAEAlphaMul:                     return 550;
            case ShaderDesc::ST_BatchPosition3dYUVAEAlpha:                   return 609;
            case ShaderDesc::ST_BatchPosition3dYUVAEAlphaMul:                return 610;
            case ShaderDesc::ST_InstancedPosition3dYUVAEAlpha:               return 669;
            case ShaderDesc::ST_InstancedPosition3dYUVAEAlphaMul:            return 670;
            case ShaderDesc::ST_YUVACxformEAlpha:                            return 525;
            case ShaderDesc::ST_YUVACxformEAlphaMul:                         return 526;
            case ShaderDesc::ST_BatchYUVACxformEAlpha:                       return 585;
            case ShaderDesc::ST_BatchYUVACxformEAlphaMul:                    return 586;
            case ShaderDesc::ST_InstancedYUVACxformEAlpha:                   return 645;
            case ShaderDesc::ST_InstancedYUVACxformEAlphaMul:                return 646;
            case ShaderDesc::ST_Position3dYUVACxformEAlpha:                  return 555;
            case ShaderDesc::ST_Position3dYUVACxformEAlphaMul:               return 556;
            case ShaderDesc::ST_BatchPosition3dYUVACxformEAlpha:             return 615;
            case ShaderDesc::ST_BatchPosition3dYUVACxformEAlphaMul:          return 616;
            case ShaderDesc::ST_InstancedPosition3dYUVACxformEAlpha:         return 675;
            case ShaderDesc::ST_InstancedPosition3dYUVACxformEAlphaMul:      return 676;
            case ShaderDesc::ST_YUVAInv:                                     return 518;
            case ShaderDesc::ST_BatchYUVAInv:                                return 578;
            case ShaderDesc::ST_InstancedYUVAInv:                            return 638;
            case ShaderDesc::ST_Position3dYUVAInv:                           return 548;
            case ShaderDesc::ST_BatchPosition3dYUVAInv:                      return 608;
            case ShaderDesc::ST_InstancedPosition3dYUVAInv:                  return 668;
            case ShaderDesc::ST_YUVACxformInv:                               return 524;
            case ShaderDesc::ST_BatchYUVACxformInv:                          return 584;
            case ShaderDesc::ST_InstancedYUVACxformInv:                      return 644;
            case ShaderDesc::ST_Position3dYUVACxformInv:                     return 554;
            case ShaderDesc::ST_BatchPosition3dYUVACxformInv:                return 614;
            case ShaderDesc::ST_InstancedPosition3dYUVACxformInv:            return 674;
            case ShaderDesc::ST_YUVAEAlphaInv:                               return 521;
            case ShaderDesc::ST_BatchYUVAEAlphaInv:                          return 581;
            case ShaderDesc::ST_InstancedYUVAEAlphaInv:                      return 641;
            case ShaderDesc::ST_Position3dYUVAEAlphaInv:                     return 551;
            case ShaderDesc::ST_BatchPosition3dYUVAEAlphaInv:                return 611;
            case ShaderDesc::ST_InstancedPosition3dYUVAEAlphaInv:            return 671;
            case ShaderDesc::ST_YUVACxformEAlphaInv:                         return 527;
            case ShaderDesc::ST_BatchYUVACxformEAlphaInv:                    return 587;
            case ShaderDesc::ST_InstancedYUVACxformEAlphaInv:                return 647;
            case ShaderDesc::ST_Position3dYUVACxformEAlphaInv:               return 557;
            case ShaderDesc::ST_BatchPosition3dYUVACxformEAlphaInv:          return 617;
            case ShaderDesc::ST_InstancedPosition3dYUVACxformEAlphaInv:      return 677;
            case ShaderDesc::ST_YUVACxformAc:                                return 528;
            case ShaderDesc::ST_YUVACxformAcMul:                             return 529;
            case ShaderDesc::ST_BatchYUVACxformAc:                           return 588;
            case ShaderDesc::ST_BatchYUVACxformAcMul:                        return 589;
            case ShaderDesc::ST_InstancedYUVACxformAc:                       return 648;
            case ShaderDesc::ST_InstancedYUVACxformAcMul:                    return 649;
            case ShaderDesc::ST_Position3dYUVACxformAc:                      return 558;
            case ShaderDesc::ST_Position3dYUVACxformAcMul:                   return 559;
            case ShaderDesc::ST_BatchPosition3dYUVACxformAc:                 return 618;
            case ShaderDesc::ST_BatchPosition3dYUVACxformAcMul:              return 619;
            case ShaderDesc::ST_InstancedPosition3dYUVACxformAc:             return 678;
            case ShaderDesc::ST_InstancedPosition3dYUVACxformAcMul:          return 679;
            case ShaderDesc::ST_YUVACxformAcEAlpha:                          return 531;
            case ShaderDesc::ST_YUVACxformAcEAlphaMul:                       return 532;
            case ShaderDesc::ST_BatchYUVACxformAcEAlpha:                     return 591;
            case ShaderDesc::ST_BatchYUVACxformAcEAlphaMul:                  return 592;
            case ShaderDesc::ST_InstancedYUVACxformAcEAlpha:                 return 651;
            case ShaderDesc::ST_InstancedYUVACxformAcEAlphaMul:              return 652;
            case ShaderDesc::ST_Position3dYUVACxformAcEAlpha:                return 561;
            case ShaderDesc::ST_Position3dYUVACxformAcEAlphaMul:             return 562;
            case ShaderDesc::ST_BatchPosition3dYUVACxformAcEAlpha:           return 621;
            case ShaderDesc::ST_BatchPosition3dYUVACxformAcEAlphaMul:        return 622;
            case ShaderDesc::ST_InstancedPosition3dYUVACxformAcEAlpha:       return 681;
            case ShaderDesc::ST_InstancedPosition3dYUVACxformAcEAlphaMul:    return 682;
            case ShaderDesc::ST_YUVACxformAcInv:                             return 530;
            case ShaderDesc::ST_BatchYUVACxformAcInv:                        return 590;
            case ShaderDesc::ST_InstancedYUVACxformAcInv:                    return 650;
            case ShaderDesc::ST_Position3dYUVACxformAcInv:                   return 560;
            case ShaderDesc::ST_BatchPosition3dYUVACxformAcInv:              return 620;
            case ShaderDesc::ST_InstancedPosition3dYUVACxformAcInv:          return 680;
            case ShaderDesc::ST_YUVACxformAcEAlphaInv:                       return 533;
            case ShaderDesc::ST_BatchYUVACxformAcEAlphaInv:                  return 593;
            case ShaderDesc::ST_InstancedYUVACxformAcEAlphaInv:              return 653;
            case ShaderDesc::ST_Position3dYUVACxformAcEAlphaInv:             return 563;
            case ShaderDesc::ST_BatchPosition3dYUVACxformAcEAlphaInv:        return 623;
            case ShaderDesc::ST_InstancedPosition3dYUVACxformAcEAlphaInv:    return 683;
            case ShaderDesc::ST_TexTGCMatrixAc:                              return 684;
            case ShaderDesc::ST_TexTGCMatrixAcMul:                           return 685;
            case ShaderDesc::ST_TexTGCMatrixAcEAlpha:                        return 686;
            case ShaderDesc::ST_TexTGCMatrixAcEAlphaMul:                     return 687;
            case ShaderDesc::ST_Box1Blur:                                    return 688;
            case ShaderDesc::ST_Box1BlurMul:                                 return 689;
            case ShaderDesc::ST_Box2Blur:                                    return 690;
            case ShaderDesc::ST_Box2BlurMul:                                 return 691;
            case ShaderDesc::ST_Box2Shadow:                                  return 692;
            case ShaderDesc::ST_Box2ShadowMul:                               return 693;
            case ShaderDesc::ST_Box2ShadowKnockout:                          return 694;
            case ShaderDesc::ST_Box2ShadowKnockoutMul:                       return 695;
            case ShaderDesc::ST_Box2Shadowonly:                              return 700;
            case ShaderDesc::ST_Box2ShadowonlyMul:                           return 701;
            case ShaderDesc::ST_Box2InnerShadow:                             return 696;
            case ShaderDesc::ST_Box2InnerShadowMul:                          return 697;
            case ShaderDesc::ST_Box2InnerShadowKnockout:                     return 698;
            case ShaderDesc::ST_Box2InnerShadowKnockoutMul:                  return 699;
            case ShaderDesc::ST_Box2ShadowonlyHighlight:                     return 712;
            case ShaderDesc::ST_Box2ShadowonlyHighlightMul:                  return 713;
            case ShaderDesc::ST_Box2FullShadowHighlight:                     return 710;
            case ShaderDesc::ST_Box2FullShadowHighlightMul:                  return 711;
            case ShaderDesc::ST_Box2InnerShadowHighlight:                    return 706;
            case ShaderDesc::ST_Box2InnerShadowHighlightMul:                 return 707;
            case ShaderDesc::ST_Box2InnerShadowHighlightKnockout:            return 708;
            case ShaderDesc::ST_Box2InnerShadowHighlightKnockoutMul:         return 709;
            case ShaderDesc::ST_Box2ShadowHighlight:                         return 702;
            case ShaderDesc::ST_Box2ShadowHighlightMul:                      return 703;
            case ShaderDesc::ST_Box2ShadowHighlightKnockout:                 return 704;
            case ShaderDesc::ST_Box2ShadowHighlightKnockoutMul:              return 705;
            case ShaderDesc::ST_DrawableCopyPixels:                          return 714;
            case ShaderDesc::ST_DrawableCopyPixelsNoDestAlpha:               return 716;
            case ShaderDesc::ST_DrawableCopyPixelsMergeAlpha:                return 715;
            case ShaderDesc::ST_DrawableCopyPixelsAlpha:                     return 717;
            case ShaderDesc::ST_DrawableCopyPixelsAlphaNoDestAlpha:          return 719;
            case ShaderDesc::ST_DrawableCopyPixelsAlphaMergeAlpha:           return 718;
            case ShaderDesc::ST_DrawableMerge:                               return 720;
            case ShaderDesc::ST_DrawableCompare:                             return 721;
            case ShaderDesc::ST_DrawablePaletteMap:                          return 722;
            default: SF_ASSERT(0); return 0;
        }
        default: SF_ASSERT(0); return 0;
    }
}

extern const unsigned char pBinary_Vulkan_SPIRV_FTexTG[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTG_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxform[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformAc[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformAc_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformAcMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformAcMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformAcInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformAcInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertex[];
extern unsigned pBinary_Vulkan_SPIRV_FVertex_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexMul[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexInv[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxform[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformMul[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformInv[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformAc[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformAc_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformAcMul[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformAcMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformAcInv[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformAcInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformAcEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformAcEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTG[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTG_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxform[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAc[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAc_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertex[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertex_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxform[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformAc[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformAc_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTG[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTG_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxform[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformAc[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformAc_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformAcMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformAcMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformAcInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformAcInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertex[];
extern unsigned pBinary_Vulkan_SPIRV_FVertex_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexMul[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexInv[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxform[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformMul[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformInv[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformAc[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformAc_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformAcMul[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformAcMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformAcInv[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformAcInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformAcEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformAcEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTG[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTG_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxform[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAc[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAc_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertex[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertex_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxform[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformAc[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformAc_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTG[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTG_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxform[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformAc[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformAc_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformAcMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformAcMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformAcInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformAcInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertex[];
extern unsigned pBinary_Vulkan_SPIRV_FVertex_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexMul[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexInv[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxform[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformMul[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformInv[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformAc[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformAc_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformAcMul[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformAcMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformAcInv[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformAcInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformAcEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformAcEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTG[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTG_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxform[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAc[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAc_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertex[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertex_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxform[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformAc[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformAc_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FSolid[];
extern unsigned pBinary_Vulkan_SPIRV_FSolid_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FSolidMul[];
extern unsigned pBinary_Vulkan_SPIRV_FSolidMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FSolidInv[];
extern unsigned pBinary_Vulkan_SPIRV_FSolidInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FText[];
extern unsigned pBinary_Vulkan_SPIRV_FText_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTextMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTextMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTextInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTextInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FSolid[];
extern unsigned pBinary_Vulkan_SPIRV_FSolid_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FSolidMul[];
extern unsigned pBinary_Vulkan_SPIRV_FSolidMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FSolidInv[];
extern unsigned pBinary_Vulkan_SPIRV_FSolidInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FText[];
extern unsigned pBinary_Vulkan_SPIRV_FText_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTextMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTextMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTextInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTextInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FSolid[];
extern unsigned pBinary_Vulkan_SPIRV_FSolid_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FSolidMul[];
extern unsigned pBinary_Vulkan_SPIRV_FSolidMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FSolidInv[];
extern unsigned pBinary_Vulkan_SPIRV_FSolidInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FText[];
extern unsigned pBinary_Vulkan_SPIRV_FText_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTextMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTextMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTextInv[];
extern unsigned pBinary_Vulkan_SPIRV_FTextInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUV[];
extern unsigned pBinary_Vulkan_SPIRV_FYUV_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxform[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxformMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxformMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxformEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxformEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxformAc[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxformAc_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxformAcMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxformAcMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxformAcEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxformAcEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxformAcEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxformAcEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVA[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVA_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVAMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVAMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVAInv[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVAInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVAEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVAEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVAEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVAEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVAEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVAEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxform[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformInv[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformAc[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformAc_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformAcMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformAcMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformAcInv[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformAcInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformAcEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformAcEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUV[];
extern unsigned pBinary_Vulkan_SPIRV_FYUV_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxform[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxformMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxformMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxformEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxformEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxformAc[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxformAc_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxformAcMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxformAcMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxformAcEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxformAcEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxformAcEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxformAcEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVA[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVA_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVAMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVAMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVAInv[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVAInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVAEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVAEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVAEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVAEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVAEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVAEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxform[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformInv[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformAc[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformAc_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformAcMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformAcMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformAcInv[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformAcInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformAcEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformAcEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUV[];
extern unsigned pBinary_Vulkan_SPIRV_FYUV_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxform[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxformMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxformMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxformEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxformEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxformAc[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxformAc_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxformAcMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxformAcMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxformAcEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxformAcEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVCxformAcEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVCxformAcEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVA[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVA_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVAMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVAMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVAInv[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVAInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVAEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVAEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVAEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVAEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVAEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVAEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxform[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxform_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformInv[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformAc[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformAc_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformAcMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformAcMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformAcInv[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformAcInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformAcEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformAcEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaInv[];
extern unsigned pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaInv_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCMatrixAc[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCMatrixAc_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCMatrixAcMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCMatrixAcMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCMatrixAcEAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCMatrixAcEAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FTexTGCMatrixAcEAlphaMul[];
extern unsigned pBinary_Vulkan_SPIRV_FTexTGCMatrixAcEAlphaMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox1Blur[];
extern unsigned pBinary_Vulkan_SPIRV_FBox1Blur_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox1BlurMul[];
extern unsigned pBinary_Vulkan_SPIRV_FBox1BlurMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2Blur[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2Blur_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2BlurMul[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2BlurMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2Shadow[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2Shadow_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2ShadowMul[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2ShadowMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2ShadowKnockout[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2ShadowKnockout_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2ShadowKnockoutMul[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2ShadowKnockoutMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2InnerShadow[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2InnerShadow_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2InnerShadowMul[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2InnerShadowMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2InnerShadowKnockout[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2InnerShadowKnockout_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2InnerShadowKnockoutMul[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2InnerShadowKnockoutMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2Shadowonly[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2Shadowonly_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2ShadowonlyMul[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2ShadowonlyMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2ShadowHighlight[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2ShadowHighlight_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2ShadowHighlightMul[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2ShadowHighlightMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2ShadowHighlightKnockout[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2ShadowHighlightKnockout_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2ShadowHighlightKnockoutMul[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2ShadowHighlightKnockoutMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2InnerShadowHighlight[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2InnerShadowHighlight_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2InnerShadowHighlightMul[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2InnerShadowHighlightMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2InnerShadowHighlightKnockout[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2InnerShadowHighlightKnockout_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2InnerShadowHighlightKnockoutMul[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2InnerShadowHighlightKnockoutMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2FullShadowHighlight[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2FullShadowHighlight_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2FullShadowHighlightMul[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2FullShadowHighlightMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2ShadowonlyHighlight[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2ShadowonlyHighlight_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FBox2ShadowonlyHighlightMul[];
extern unsigned pBinary_Vulkan_SPIRV_FBox2ShadowonlyHighlightMul_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FDrawableCopyPixels[];
extern unsigned pBinary_Vulkan_SPIRV_FDrawableCopyPixels_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FDrawableCopyPixelsMergeAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FDrawableCopyPixelsMergeAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FDrawableCopyPixelsNoDestAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FDrawableCopyPixelsNoDestAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FDrawableCopyPixelsAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FDrawableCopyPixelsAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FDrawableCopyPixelsAlphaMergeAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FDrawableCopyPixelsAlphaMergeAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FDrawableCopyPixelsAlphaNoDestAlpha[];
extern unsigned pBinary_Vulkan_SPIRV_FDrawableCopyPixelsAlphaNoDestAlpha_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FDrawableMerge[];
extern unsigned pBinary_Vulkan_SPIRV_FDrawableMerge_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FDrawableCompare[];
extern unsigned pBinary_Vulkan_SPIRV_FDrawableCompare_size;
extern const unsigned char pBinary_Vulkan_SPIRV_FDrawablePaletteMap[];
extern unsigned pBinary_Vulkan_SPIRV_FDrawablePaletteMap_size;

UniformVar Uniforms_4535377741[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        { -1, 0, 0, 0, 0, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        {0, 1032, 1, 1, 1, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_3756130650[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        { -1, 0, 0, 0, 0, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        { -1, 0, 0, 0, 0, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_6117461306[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        { -1, 0, 0, 0, 0, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        {0, 1032, 1, 2, 1, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_5650485972[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      {0, 1032, 4, 4, 4, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        { -1, 0, 0, 0, 0, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        { -1, 0, 0, 0, 0, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_3186954237[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        { -1, 0, 0, 0, 0, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        {0, 1032, 1, 3, 1, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_4602762762[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        { -1, 0, 0, 0, 0, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        {0, 1032, 1, 4, 1, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_3124591169[Uniform::SU_Count] = 
{
    /* cxadd*/      {0, 1032, 4, 4, 4, 0 },
    /* cxmul*/      {1, 1036, 16, 16, 16, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        { -1, 0, 0, 0, 0, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        {0, 1032, 1, 1, 1, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_2460454664[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      {0, 1032, 4, 4, 4, 0 },
    /* mvp*/        { -1, 0, 0, 0, 0, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        {0, 1032, 1, 1, 1, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   {1, 1036, 4, 4, 4, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_4719056760[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      {0, 1032, 4, 4, 4, 0 },
    /* mvp*/        { -1, 0, 0, 0, 0, 0 },
    /* offset*/     {1, 1036, 4, 4, 4, 0 },
    /* scolor*/     {2, 1040, 4, 4, 4, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     {0, 1032, 1, 1, 1, 0 },
    /* srctexscale*/{3, 1044, 4, 4, 4, 0 },
    /* tex*/        {1, 1036, 1, 1, 1, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   {4, 1048, 4, 4, 4, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_5169239271[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      {0, 1032, 4, 4, 4, 0 },
    /* mvp*/        { -1, 0, 0, 0, 0, 0 },
    /* offset*/     {1, 1036, 4, 4, 4, 0 },
    /* scolor*/     {2, 1040, 4, 4, 4, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        {0, 1032, 1, 1, 1, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   {3, 1044, 4, 4, 4, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_4912805460[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      {0, 1032, 4, 4, 4, 0 },
    /* mvp*/        { -1, 0, 0, 0, 0, 0 },
    /* offset*/     {1, 1036, 4, 4, 4, 0 },
    /* scolor*/     {2, 1040, 4, 4, 4, 0 },
    /* scolor2*/    {3, 1044, 4, 4, 4, 0 },
    /* srctex*/     {0, 1032, 1, 1, 1, 0 },
    /* srctexscale*/{4, 1048, 4, 4, 4, 0 },
    /* tex*/        {1, 1036, 1, 1, 1, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   {5, 1052, 4, 4, 4, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_3390122391[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      {0, 1032, 4, 4, 4, 0 },
    /* mvp*/        { -1, 0, 0, 0, 0, 0 },
    /* offset*/     {1, 1036, 4, 4, 4, 0 },
    /* scolor*/     {2, 1040, 4, 4, 4, 0 },
    /* scolor2*/    {3, 1044, 4, 4, 4, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        {0, 1032, 1, 1, 1, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   {4, 1048, 4, 4, 4, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_6098560083[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      {0, 1032, 16, 16, 16, 0 },
    /* cxmul1*/     {4, 1048, 16, 16, 16, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        { -1, 0, 0, 0, 0, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     { -1, 0, 0, 0, 0, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        {0, 1032, 1, 2, 1, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

UniformVar Uniforms_2402564022[Uniform::SU_Count] = 
{
    /* cxadd*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul*/      { -1, 0, 0, 0, 0, 0 },
    /* cxmul1*/     { -1, 0, 0, 0, 0, 0 },
    /* fsize*/      { -1, 0, 0, 0, 0, 0 },
    /* mvp*/        { -1, 0, 0, 0, 0, 0 },
    /* offset*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor*/     { -1, 0, 0, 0, 0, 0 },
    /* scolor2*/    { -1, 0, 0, 0, 0, 0 },
    /* srctex*/     {0, 1032, 1, 1, 1, 0 },
    /* srctexscale*/{ -1, 0, 0, 0, 0, 0 },
    /* tex*/        {1, 1036, 1, 1, 1, 0 },
    /* texgen*/     { -1, 0, 0, 0, 0, 0 },
    /* texscale*/   { -1, 0, 0, 0, 0, 0 },
    /* vfmuniforms*/{ -1, 0, 0, 0, 0, 0 },
    /* vfuniforms*/ { -1, 0, 0, 0, 0, 0 },
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTG = 
{
    /* Type */          ShaderDesc::ST_TexTG,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTG,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTG_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGMul = 
{
    /* Type */          ShaderDesc::ST_TexTGMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGInv = 
{
    /* Type */          ShaderDesc::ST_TexTGInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGEAlpha = 
{
    /* Type */          ShaderDesc::ST_TexTGEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGEAlpha_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_TexTGEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGEAlphaMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_TexTGEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGEAlphaInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxform = 
{
    /* Type */          ShaderDesc::ST_TexTGCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxform_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxformMul = 
{
    /* Type */          ShaderDesc::ST_TexTGCxformMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxformInv = 
{
    /* Type */          ShaderDesc::ST_TexTGCxformInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_TexTGCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformEAlpha_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxformEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_TexTGCxformEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxformEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_TexTGCxformEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxformAc = 
{
    /* Type */          ShaderDesc::ST_TexTGCxformAc,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAc,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAc_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxformAcMul = 
{
    /* Type */          ShaderDesc::ST_TexTGCxformAcMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxformAcInv = 
{
    /* Type */          ShaderDesc::ST_TexTGCxformAcInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxformAcEAlpha = 
{
    /* Type */          ShaderDesc::ST_TexTGCxformAcEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlpha_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxformAcEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_TexTGCxformAcEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxformAcEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_TexTGCxformAcEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FVertex = 
{
    /* Type */          ShaderDesc::ST_Vertex,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertex,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertex_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FVertexMul = 
{
    /* Type */          ShaderDesc::ST_VertexMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexMul_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FVertexInv = 
{
    /* Type */          ShaderDesc::ST_VertexInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexInv_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FVertexEAlpha = 
{
    /* Type */          ShaderDesc::ST_VertexEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexEAlpha_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FVertexEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_VertexEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexEAlphaMul_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FVertexEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_VertexEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexEAlphaInv_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FVertexCxform = 
{
    /* Type */          ShaderDesc::ST_VertexCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxform_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FVertexCxformMul = 
{
    /* Type */          ShaderDesc::ST_VertexCxformMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformMul_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FVertexCxformInv = 
{
    /* Type */          ShaderDesc::ST_VertexCxformInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformInv_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FVertexCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_VertexCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformEAlpha_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FVertexCxformEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_VertexCxformEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformEAlphaMul_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FVertexCxformEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_VertexCxformEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformEAlphaInv_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FVertexCxformAc = 
{
    /* Type */          ShaderDesc::ST_VertexCxformAc,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAc,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAc_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FVertexCxformAcMul = 
{
    /* Type */          ShaderDesc::ST_VertexCxformAcMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcMul_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FVertexCxformAcInv = 
{
    /* Type */          ShaderDesc::ST_VertexCxformAcInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcInv_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FVertexCxformAcEAlpha = 
{
    /* Type */          ShaderDesc::ST_VertexCxformAcEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcEAlpha_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FVertexCxformAcEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_VertexCxformAcEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaMul_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FVertexCxformAcEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_VertexCxformAcEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaInv_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTG = 
{
    /* Type */          ShaderDesc::ST_TexTGTexTG,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTG,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTG_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGMul = 
{
    /* Type */          ShaderDesc::ST_TexTGTexTGMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGMul_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGInv = 
{
    /* Type */          ShaderDesc::ST_TexTGTexTGInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGInv_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGEAlpha = 
{
    /* Type */          ShaderDesc::ST_TexTGTexTGEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGEAlpha_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_TexTGTexTGEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaMul_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_TexTGTexTGEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaInv_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxform = 
{
    /* Type */          ShaderDesc::ST_TexTGTexTGCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxform_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxformMul = 
{
    /* Type */          ShaderDesc::ST_TexTGTexTGCxformMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformMul_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxformInv = 
{
    /* Type */          ShaderDesc::ST_TexTGTexTGCxformInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformInv_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_TexTGTexTGCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlpha_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_TexTGTexTGCxformEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaMul_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_TexTGTexTGCxformEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaInv_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxformAc = 
{
    /* Type */          ShaderDesc::ST_TexTGTexTGCxformAc,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAc,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAc_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxformAcMul = 
{
    /* Type */          ShaderDesc::ST_TexTGTexTGCxformAcMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcMul_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxformAcInv = 
{
    /* Type */          ShaderDesc::ST_TexTGTexTGCxformAcInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcInv_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlpha = 
{
    /* Type */          ShaderDesc::ST_TexTGTexTGCxformAcEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlpha_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_TexTGTexTGCxformAcEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaMul_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_TexTGTexTGCxformAcEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaInv_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertex = 
{
    /* Type */          ShaderDesc::ST_TexTGVertex,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertex,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertex_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexMul = 
{
    /* Type */          ShaderDesc::ST_TexTGVertexMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexInv = 
{
    /* Type */          ShaderDesc::ST_TexTGVertexInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexEAlpha = 
{
    /* Type */          ShaderDesc::ST_TexTGVertexEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexEAlpha_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_TexTGVertexEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_TexTGVertexEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxform = 
{
    /* Type */          ShaderDesc::ST_TexTGVertexCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxform_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxformMul = 
{
    /* Type */          ShaderDesc::ST_TexTGVertexCxformMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxformInv = 
{
    /* Type */          ShaderDesc::ST_TexTGVertexCxformInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_TexTGVertexCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlpha_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxformEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_TexTGVertexCxformEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxformEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_TexTGVertexCxformEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxformAc = 
{
    /* Type */          ShaderDesc::ST_TexTGVertexCxformAc,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAc,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAc_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxformAcMul = 
{
    /* Type */          ShaderDesc::ST_TexTGVertexCxformAcMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxformAcInv = 
{
    /* Type */          ShaderDesc::ST_TexTGVertexCxformAcInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxformAcEAlpha = 
{
    /* Type */          ShaderDesc::ST_TexTGVertexCxformAcEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlpha_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_TexTGVertexCxformAcEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_TexTGVertexCxformAcEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTG = 
{
    /* Type */          ShaderDesc::ST_BatchTexTG,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTG,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTG_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGMul = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGInv = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGEAlpha_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGEAlphaMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGEAlphaInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxform = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxform_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxformMul = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGCxformMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxformInv = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGCxformInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformEAlpha_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxformEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGCxformEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxformEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGCxformEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxformAc = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGCxformAc,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAc,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAc_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxformAcMul = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGCxformAcMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxformAcInv = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGCxformAcInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxformAcEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGCxformAcEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlpha_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxformAcEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGCxformAcEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxformAcEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGCxformAcEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchVertex = 
{
    /* Type */          ShaderDesc::ST_BatchVertex,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertex,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertex_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexMul = 
{
    /* Type */          ShaderDesc::ST_BatchVertexMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexMul_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexInv = 
{
    /* Type */          ShaderDesc::ST_BatchVertexInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexInv_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchVertexEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexEAlpha_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_BatchVertexEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexEAlphaMul_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_BatchVertexEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexEAlphaInv_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxform = 
{
    /* Type */          ShaderDesc::ST_BatchVertexCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxform_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxformMul = 
{
    /* Type */          ShaderDesc::ST_BatchVertexCxformMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformMul_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxformInv = 
{
    /* Type */          ShaderDesc::ST_BatchVertexCxformInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformInv_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchVertexCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformEAlpha_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxformEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_BatchVertexCxformEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformEAlphaMul_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxformEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_BatchVertexCxformEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformEAlphaInv_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxformAc = 
{
    /* Type */          ShaderDesc::ST_BatchVertexCxformAc,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAc,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAc_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxformAcMul = 
{
    /* Type */          ShaderDesc::ST_BatchVertexCxformAcMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcMul_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxformAcInv = 
{
    /* Type */          ShaderDesc::ST_BatchVertexCxformAcInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcInv_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxformAcEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchVertexCxformAcEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcEAlpha_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxformAcEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_BatchVertexCxformAcEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaMul_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxformAcEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_BatchVertexCxformAcEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaInv_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTG = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGTexTG,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTG,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTG_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGMul = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGTexTGMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGMul_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGInv = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGTexTGInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGInv_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGTexTGEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGEAlpha_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGTexTGEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaMul_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGTexTGEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaInv_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxform = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGTexTGCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxform_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxformMul = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGTexTGCxformMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformMul_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxformInv = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGTexTGCxformInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformInv_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGTexTGCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlpha_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxformEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGTexTGCxformEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaMul_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxformEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGTexTGCxformEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaInv_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxformAc = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGTexTGCxformAc,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAc,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAc_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxformAcMul = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGTexTGCxformAcMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcMul_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxformAcInv = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGTexTGCxformAcInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcInv_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxformAcEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGTexTGCxformAcEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlpha_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxformAcEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGTexTGCxformAcEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaMul_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxformAcEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGTexTGCxformAcEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaInv_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertex = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGVertex,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertex,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertex_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexMul = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGVertexMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexInv = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGVertexInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGVertexEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexEAlpha_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGVertexEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGVertexEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxform = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGVertexCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxform_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxformMul = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGVertexCxformMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxformInv = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGVertexCxformInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGVertexCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlpha_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxformEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGVertexCxformEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxformEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGVertexCxformEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxformAc = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGVertexCxformAc,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAc,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAc_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxformAcMul = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGVertexCxformAcMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxformAcInv = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGVertexCxformAcInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxformAcEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGVertexCxformAcEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlpha_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxformAcEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGVertexCxformAcEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxformAcEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_BatchTexTGVertexCxformAcEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTG = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTG,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTG,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTG_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGMul = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGInv = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGEAlpha_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGEAlphaMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGEAlphaInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxform = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxform_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxformMul = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGCxformMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxformInv = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGCxformInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformEAlpha_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxformEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGCxformEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxformEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGCxformEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformEAlphaInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxformAc = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGCxformAc,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAc,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAc_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxformAcMul = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGCxformAcMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxformAcInv = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGCxformAcInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxformAcEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGCxformAcEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlpha_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxformAcEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGCxformAcEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxformAcEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGCxformAcEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCxformAcEAlphaInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertex = 
{
    /* Type */          ShaderDesc::ST_InstancedVertex,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertex,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertex_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexMul = 
{
    /* Type */          ShaderDesc::ST_InstancedVertexMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexMul_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexInv = 
{
    /* Type */          ShaderDesc::ST_InstancedVertexInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexInv_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedVertexEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexEAlpha_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_InstancedVertexEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexEAlphaMul_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_InstancedVertexEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexEAlphaInv_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxform = 
{
    /* Type */          ShaderDesc::ST_InstancedVertexCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxform_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxformMul = 
{
    /* Type */          ShaderDesc::ST_InstancedVertexCxformMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformMul_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxformInv = 
{
    /* Type */          ShaderDesc::ST_InstancedVertexCxformInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformInv_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedVertexCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformEAlpha_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxformEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_InstancedVertexCxformEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformEAlphaMul_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxformEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_InstancedVertexCxformEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformEAlphaInv_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxformAc = 
{
    /* Type */          ShaderDesc::ST_InstancedVertexCxformAc,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAc,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAc_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxformAcMul = 
{
    /* Type */          ShaderDesc::ST_InstancedVertexCxformAcMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcMul_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxformAcInv = 
{
    /* Type */          ShaderDesc::ST_InstancedVertexCxformAcInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcInv_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxformAcEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedVertexCxformAcEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcEAlpha_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxformAcEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_InstancedVertexCxformAcEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaMul_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxformAcEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_InstancedVertexCxformAcEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FVertexCxformAcEAlphaInv_size,
    /* Uniforms */      Uniforms_3756130650,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTG = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGTexTG,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTG,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTG_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGMul = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGTexTGMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGMul_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGInv = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGTexTGInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGInv_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGTexTGEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGEAlpha_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGTexTGEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaMul_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGTexTGEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGEAlphaInv_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxform = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGTexTGCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxform_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxformMul = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGTexTGCxformMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformMul_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxformInv = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGTexTGCxformInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformInv_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGTexTGCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlpha_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxformEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGTexTGCxformEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaMul_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxformEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGTexTGCxformEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaInv_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAc = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGTexTGCxformAc,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAc,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAc_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAcMul = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGTexTGCxformAcMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcMul_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAcInv = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGTexTGCxformAcInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcInv_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAcEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGTexTGCxformAcEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlpha_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAcEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGTexTGCxformAcEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaMul_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAcEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGTexTGCxformAcEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaInv_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertex = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGVertex,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertex,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertex_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexMul = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGVertexMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexInv = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGVertexInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGVertexEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexEAlpha_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGVertexEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGVertexEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexEAlphaInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxform = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGVertexCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxform_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxformMul = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGVertexCxformMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxformInv = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGVertexCxformInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGVertexCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlpha_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxformEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGVertexCxformEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxformEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGVertexCxformEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformEAlphaInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxformAc = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGVertexCxformAc,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAc,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAc_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxformAcMul = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGVertexCxformAcMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxformAcInv = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGVertexCxformAcInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxformAcEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGVertexCxformAcEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlpha_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxformAcEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGVertexCxformAcEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxformAcEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_InstancedTexTGVertexCxformAcEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FSolid = 
{
    /* Type */          ShaderDesc::ST_Solid,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FSolid,
    /* pBinary */       pBinary_Vulkan_SPIRV_FSolid_size,
    /* Uniforms */      Uniforms_5650485972,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FSolidMul = 
{
    /* Type */          ShaderDesc::ST_SolidMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FSolidMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FSolidMul_size,
    /* Uniforms */      Uniforms_5650485972,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FSolidInv = 
{
    /* Type */          ShaderDesc::ST_SolidInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FSolidInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FSolidInv_size,
    /* Uniforms */      Uniforms_5650485972,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FText = 
{
    /* Type */          ShaderDesc::ST_Text,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FText,
    /* pBinary */       pBinary_Vulkan_SPIRV_FText_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTextMul = 
{
    /* Type */          ShaderDesc::ST_TextMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTextMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTextMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTextInv = 
{
    /* Type */          ShaderDesc::ST_TextInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTextInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTextInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchSolid = 
{
    /* Type */          ShaderDesc::ST_BatchSolid,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FSolid,
    /* pBinary */       pBinary_Vulkan_SPIRV_FSolid_size,
    /* Uniforms */      Uniforms_5650485972,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchSolidMul = 
{
    /* Type */          ShaderDesc::ST_BatchSolidMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FSolidMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FSolidMul_size,
    /* Uniforms */      Uniforms_5650485972,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchSolidInv = 
{
    /* Type */          ShaderDesc::ST_BatchSolidInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FSolidInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FSolidInv_size,
    /* Uniforms */      Uniforms_5650485972,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchText = 
{
    /* Type */          ShaderDesc::ST_BatchText,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FText,
    /* pBinary */       pBinary_Vulkan_SPIRV_FText_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTextMul = 
{
    /* Type */          ShaderDesc::ST_BatchTextMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTextMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTextMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchTextInv = 
{
    /* Type */          ShaderDesc::ST_BatchTextInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTextInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTextInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedSolid = 
{
    /* Type */          ShaderDesc::ST_InstancedSolid,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FSolid,
    /* pBinary */       pBinary_Vulkan_SPIRV_FSolid_size,
    /* Uniforms */      Uniforms_5650485972,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedSolidMul = 
{
    /* Type */          ShaderDesc::ST_InstancedSolidMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FSolidMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FSolidMul_size,
    /* Uniforms */      Uniforms_5650485972,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedSolidInv = 
{
    /* Type */          ShaderDesc::ST_InstancedSolidInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FSolidInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FSolidInv_size,
    /* Uniforms */      Uniforms_5650485972,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedText = 
{
    /* Type */          ShaderDesc::ST_InstancedText,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FText,
    /* pBinary */       pBinary_Vulkan_SPIRV_FText_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTextMul = 
{
    /* Type */          ShaderDesc::ST_InstancedTextMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTextMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTextMul_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedTextInv = 
{
    /* Type */          ShaderDesc::ST_InstancedTextInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTextInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTextInv_size,
    /* Uniforms */      Uniforms_4535377741,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUV = 
{
    /* Type */          ShaderDesc::ST_YUV,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUV,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUV_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVMul = 
{
    /* Type */          ShaderDesc::ST_YUVMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVMul_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVEAlpha = 
{
    /* Type */          ShaderDesc::ST_YUVEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVEAlpha_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_YUVEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVEAlphaMul_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVCxform = 
{
    /* Type */          ShaderDesc::ST_YUVCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxform_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVCxformMul = 
{
    /* Type */          ShaderDesc::ST_YUVCxformMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformMul_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_YUVCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformEAlpha_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVCxformEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_YUVCxformEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformEAlphaMul_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVCxformAc = 
{
    /* Type */          ShaderDesc::ST_YUVCxformAc,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAc,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAc_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVCxformAcMul = 
{
    /* Type */          ShaderDesc::ST_YUVCxformAcMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAcMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAcMul_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVCxformAcEAlpha = 
{
    /* Type */          ShaderDesc::ST_YUVCxformAcEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAcEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAcEAlpha_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVCxformAcEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_YUVCxformAcEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAcEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAcEAlphaMul_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVA = 
{
    /* Type */          ShaderDesc::ST_YUVA,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVA,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVA_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVAMul = 
{
    /* Type */          ShaderDesc::ST_YUVAMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAMul_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVAInv = 
{
    /* Type */          ShaderDesc::ST_YUVAInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAInv_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVAEAlpha = 
{
    /* Type */          ShaderDesc::ST_YUVAEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAEAlpha_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVAEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_YUVAEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAEAlphaMul_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVAEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_YUVAEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAEAlphaInv_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVACxform = 
{
    /* Type */          ShaderDesc::ST_YUVACxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxform_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVACxformMul = 
{
    /* Type */          ShaderDesc::ST_YUVACxformMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformMul_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVACxformInv = 
{
    /* Type */          ShaderDesc::ST_YUVACxformInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformInv_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVACxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_YUVACxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformEAlpha_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVACxformEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_YUVACxformEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformEAlphaMul_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVACxformEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_YUVACxformEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformEAlphaInv_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVACxformAc = 
{
    /* Type */          ShaderDesc::ST_YUVACxformAc,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAc,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAc_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVACxformAcMul = 
{
    /* Type */          ShaderDesc::ST_YUVACxformAcMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcMul_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVACxformAcInv = 
{
    /* Type */          ShaderDesc::ST_YUVACxformAcInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcInv_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVACxformAcEAlpha = 
{
    /* Type */          ShaderDesc::ST_YUVACxformAcEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcEAlpha_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVACxformAcEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_YUVACxformAcEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaMul_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FYUVACxformAcEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_YUVACxformAcEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaInv_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUV = 
{
    /* Type */          ShaderDesc::ST_BatchYUV,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUV,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUV_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVMul = 
{
    /* Type */          ShaderDesc::ST_BatchYUVMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVMul_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchYUVEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVEAlpha_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_BatchYUVEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVEAlphaMul_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVCxform = 
{
    /* Type */          ShaderDesc::ST_BatchYUVCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxform_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVCxformMul = 
{
    /* Type */          ShaderDesc::ST_BatchYUVCxformMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformMul_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchYUVCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformEAlpha_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVCxformEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_BatchYUVCxformEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformEAlphaMul_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVCxformAc = 
{
    /* Type */          ShaderDesc::ST_BatchYUVCxformAc,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAc,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAc_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVCxformAcMul = 
{
    /* Type */          ShaderDesc::ST_BatchYUVCxformAcMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAcMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAcMul_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVCxformAcEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchYUVCxformAcEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAcEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAcEAlpha_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVCxformAcEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_BatchYUVCxformAcEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAcEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAcEAlphaMul_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVA = 
{
    /* Type */          ShaderDesc::ST_BatchYUVA,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVA,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVA_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVAMul = 
{
    /* Type */          ShaderDesc::ST_BatchYUVAMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAMul_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVAInv = 
{
    /* Type */          ShaderDesc::ST_BatchYUVAInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAInv_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVAEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchYUVAEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAEAlpha_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVAEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_BatchYUVAEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAEAlphaMul_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVAEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_BatchYUVAEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAEAlphaInv_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxform = 
{
    /* Type */          ShaderDesc::ST_BatchYUVACxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxform_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxformMul = 
{
    /* Type */          ShaderDesc::ST_BatchYUVACxformMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformMul_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxformInv = 
{
    /* Type */          ShaderDesc::ST_BatchYUVACxformInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformInv_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchYUVACxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformEAlpha_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxformEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_BatchYUVACxformEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformEAlphaMul_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxformEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_BatchYUVACxformEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformEAlphaInv_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxformAc = 
{
    /* Type */          ShaderDesc::ST_BatchYUVACxformAc,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAc,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAc_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxformAcMul = 
{
    /* Type */          ShaderDesc::ST_BatchYUVACxformAcMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcMul_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxformAcInv = 
{
    /* Type */          ShaderDesc::ST_BatchYUVACxformAcInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcInv_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxformAcEAlpha = 
{
    /* Type */          ShaderDesc::ST_BatchYUVACxformAcEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcEAlpha_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxformAcEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_BatchYUVACxformAcEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaMul_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxformAcEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_BatchYUVACxformAcEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Batch,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaInv_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUV = 
{
    /* Type */          ShaderDesc::ST_InstancedYUV,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUV,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUV_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVMul = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVMul_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVEAlpha_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVEAlphaMul_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVCxform = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVCxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxform_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVCxformMul = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVCxformMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformMul_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVCxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVCxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformEAlpha_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVCxformEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVCxformEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformEAlphaMul_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVCxformAc = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVCxformAc,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAc,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAc_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVCxformAcMul = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVCxformAcMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAcMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAcMul_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVCxformAcEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVCxformAcEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAcEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAcEAlpha_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVCxformAcEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVCxformAcEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAcEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVCxformAcEAlphaMul_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVA = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVA,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVA,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVA_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVAMul = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVAMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAMul_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVAInv = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVAInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAInv_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVAEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVAEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAEAlpha_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVAEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVAEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAEAlphaMul_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVAEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVAEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVAEAlphaInv_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxform = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVACxform,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxform,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxform_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxformMul = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVACxformMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformMul_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxformInv = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVACxformInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformInv_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxformEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVACxformEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformEAlpha_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxformEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVACxformEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformEAlphaMul_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxformEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVACxformEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformEAlphaInv_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxformAc = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVACxformAc,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAc,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAc_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxformAcMul = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVACxformAcMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcMul_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxformAcInv = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVACxformAcInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcInv_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxformAcEAlpha = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVACxformAcEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcEAlpha_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxformAcEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVACxformAcEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaMul_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxformAcEAlphaInv = 
{
    /* Type */          ShaderDesc::ST_InstancedYUVACxformAcEAlphaInv,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_Instanced,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaInv,
    /* pBinary */       pBinary_Vulkan_SPIRV_FYUVACxformAcEAlphaInv_size,
    /* Uniforms */      Uniforms_4602762762,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGCMatrixAc = 
{
    /* Type */          ShaderDesc::ST_TexTGCMatrixAc,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCMatrixAc,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCMatrixAc_size,
    /* Uniforms */      Uniforms_3124591169,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGCMatrixAcMul = 
{
    /* Type */          ShaderDesc::ST_TexTGCMatrixAcMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCMatrixAcMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCMatrixAcMul_size,
    /* Uniforms */      Uniforms_3124591169,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGCMatrixAcEAlpha = 
{
    /* Type */          ShaderDesc::ST_TexTGCMatrixAcEAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCMatrixAcEAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCMatrixAcEAlpha_size,
    /* Uniforms */      Uniforms_3124591169,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FTexTGCMatrixAcEAlphaMul = 
{
    /* Type */          ShaderDesc::ST_TexTGCMatrixAcEAlphaMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCMatrixAcEAlphaMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FTexTGCMatrixAcEAlphaMul_size,
    /* Uniforms */      Uniforms_3124591169,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox1Blur = 
{
    /* Type */          ShaderDesc::ST_Box1Blur,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox1Blur,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox1Blur_size,
    /* Uniforms */      Uniforms_2460454664,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox1BlurMul = 
{
    /* Type */          ShaderDesc::ST_Box1BlurMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox1BlurMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox1BlurMul_size,
    /* Uniforms */      Uniforms_2460454664,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2Blur = 
{
    /* Type */          ShaderDesc::ST_Box2Blur,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2Blur,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2Blur_size,
    /* Uniforms */      Uniforms_2460454664,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2BlurMul = 
{
    /* Type */          ShaderDesc::ST_Box2BlurMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2BlurMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2BlurMul_size,
    /* Uniforms */      Uniforms_2460454664,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2Shadow = 
{
    /* Type */          ShaderDesc::ST_Box2Shadow,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2Shadow,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2Shadow_size,
    /* Uniforms */      Uniforms_4719056760,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2ShadowMul = 
{
    /* Type */          ShaderDesc::ST_Box2ShadowMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2ShadowMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2ShadowMul_size,
    /* Uniforms */      Uniforms_4719056760,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2ShadowKnockout = 
{
    /* Type */          ShaderDesc::ST_Box2ShadowKnockout,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2ShadowKnockout,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2ShadowKnockout_size,
    /* Uniforms */      Uniforms_4719056760,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2ShadowKnockoutMul = 
{
    /* Type */          ShaderDesc::ST_Box2ShadowKnockoutMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2ShadowKnockoutMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2ShadowKnockoutMul_size,
    /* Uniforms */      Uniforms_4719056760,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2InnerShadow = 
{
    /* Type */          ShaderDesc::ST_Box2InnerShadow,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2InnerShadow,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2InnerShadow_size,
    /* Uniforms */      Uniforms_4719056760,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2InnerShadowMul = 
{
    /* Type */          ShaderDesc::ST_Box2InnerShadowMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2InnerShadowMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2InnerShadowMul_size,
    /* Uniforms */      Uniforms_4719056760,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2InnerShadowKnockout = 
{
    /* Type */          ShaderDesc::ST_Box2InnerShadowKnockout,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2InnerShadowKnockout,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2InnerShadowKnockout_size,
    /* Uniforms */      Uniforms_4719056760,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2InnerShadowKnockoutMul = 
{
    /* Type */          ShaderDesc::ST_Box2InnerShadowKnockoutMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2InnerShadowKnockoutMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2InnerShadowKnockoutMul_size,
    /* Uniforms */      Uniforms_4719056760,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2Shadowonly = 
{
    /* Type */          ShaderDesc::ST_Box2Shadowonly,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2Shadowonly,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2Shadowonly_size,
    /* Uniforms */      Uniforms_5169239271,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2ShadowonlyMul = 
{
    /* Type */          ShaderDesc::ST_Box2ShadowonlyMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2ShadowonlyMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2ShadowonlyMul_size,
    /* Uniforms */      Uniforms_5169239271,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2ShadowHighlight = 
{
    /* Type */          ShaderDesc::ST_Box2ShadowHighlight,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2ShadowHighlight,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2ShadowHighlight_size,
    /* Uniforms */      Uniforms_4912805460,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2ShadowHighlightMul = 
{
    /* Type */          ShaderDesc::ST_Box2ShadowHighlightMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2ShadowHighlightMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2ShadowHighlightMul_size,
    /* Uniforms */      Uniforms_4912805460,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2ShadowHighlightKnockout = 
{
    /* Type */          ShaderDesc::ST_Box2ShadowHighlightKnockout,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2ShadowHighlightKnockout,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2ShadowHighlightKnockout_size,
    /* Uniforms */      Uniforms_4912805460,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2ShadowHighlightKnockoutMul = 
{
    /* Type */          ShaderDesc::ST_Box2ShadowHighlightKnockoutMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2ShadowHighlightKnockoutMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2ShadowHighlightKnockoutMul_size,
    /* Uniforms */      Uniforms_4912805460,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2InnerShadowHighlight = 
{
    /* Type */          ShaderDesc::ST_Box2InnerShadowHighlight,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2InnerShadowHighlight,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2InnerShadowHighlight_size,
    /* Uniforms */      Uniforms_4912805460,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2InnerShadowHighlightMul = 
{
    /* Type */          ShaderDesc::ST_Box2InnerShadowHighlightMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2InnerShadowHighlightMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2InnerShadowHighlightMul_size,
    /* Uniforms */      Uniforms_4912805460,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2InnerShadowHighlightKnockout = 
{
    /* Type */          ShaderDesc::ST_Box2InnerShadowHighlightKnockout,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2InnerShadowHighlightKnockout,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2InnerShadowHighlightKnockout_size,
    /* Uniforms */      Uniforms_4912805460,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2InnerShadowHighlightKnockoutMul = 
{
    /* Type */          ShaderDesc::ST_Box2InnerShadowHighlightKnockoutMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2InnerShadowHighlightKnockoutMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2InnerShadowHighlightKnockoutMul_size,
    /* Uniforms */      Uniforms_4912805460,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2FullShadowHighlight = 
{
    /* Type */          ShaderDesc::ST_Box2FullShadowHighlight,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2FullShadowHighlight,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2FullShadowHighlight_size,
    /* Uniforms */      Uniforms_4912805460,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2FullShadowHighlightMul = 
{
    /* Type */          ShaderDesc::ST_Box2FullShadowHighlightMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2FullShadowHighlightMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2FullShadowHighlightMul_size,
    /* Uniforms */      Uniforms_4912805460,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2ShadowonlyHighlight = 
{
    /* Type */          ShaderDesc::ST_Box2ShadowonlyHighlight,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2ShadowonlyHighlight,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2ShadowonlyHighlight_size,
    /* Uniforms */      Uniforms_3390122391,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FBox2ShadowonlyHighlightMul = 
{
    /* Type */          ShaderDesc::ST_Box2ShadowonlyHighlightMul,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         Shader_DynamicLoop,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2ShadowonlyHighlightMul,
    /* pBinary */       pBinary_Vulkan_SPIRV_FBox2ShadowonlyHighlightMul_size,
    /* Uniforms */      Uniforms_3390122391,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FDrawableCopyPixels = 
{
    /* Type */          ShaderDesc::ST_DrawableCopyPixels,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FDrawableCopyPixels,
    /* pBinary */       pBinary_Vulkan_SPIRV_FDrawableCopyPixels_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FDrawableCopyPixelsMergeAlpha = 
{
    /* Type */          ShaderDesc::ST_DrawableCopyPixelsMergeAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FDrawableCopyPixelsMergeAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FDrawableCopyPixelsMergeAlpha_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FDrawableCopyPixelsNoDestAlpha = 
{
    /* Type */          ShaderDesc::ST_DrawableCopyPixelsNoDestAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FDrawableCopyPixelsNoDestAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FDrawableCopyPixelsNoDestAlpha_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FDrawableCopyPixelsAlpha = 
{
    /* Type */          ShaderDesc::ST_DrawableCopyPixelsAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FDrawableCopyPixelsAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FDrawableCopyPixelsAlpha_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FDrawableCopyPixelsAlphaMergeAlpha = 
{
    /* Type */          ShaderDesc::ST_DrawableCopyPixelsAlphaMergeAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FDrawableCopyPixelsAlphaMergeAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FDrawableCopyPixelsAlphaMergeAlpha_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FDrawableCopyPixelsAlphaNoDestAlpha = 
{
    /* Type */          ShaderDesc::ST_DrawableCopyPixelsAlphaNoDestAlpha,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FDrawableCopyPixelsAlphaNoDestAlpha,
    /* pBinary */       pBinary_Vulkan_SPIRV_FDrawableCopyPixelsAlphaNoDestAlpha_size,
    /* Uniforms */      Uniforms_3186954237,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FDrawableMerge = 
{
    /* Type */          ShaderDesc::ST_DrawableMerge,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FDrawableMerge,
    /* pBinary */       pBinary_Vulkan_SPIRV_FDrawableMerge_size,
    /* Uniforms */      Uniforms_6098560083,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FDrawableCompare = 
{
    /* Type */          ShaderDesc::ST_DrawableCompare,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FDrawableCompare,
    /* pBinary */       pBinary_Vulkan_SPIRV_FDrawableCompare_size,
    /* Uniforms */      Uniforms_6117461306,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

static FragShaderDesc ShaderDesc_FS_Vulkan_SPIRV_FDrawablePaletteMap = 
{
    /* Type */          ShaderDesc::ST_DrawablePaletteMap,
    /* Version */       ShaderDesc::ShaderVersion_Vulkan_SPIRV,
    /* Flags */         0,
    /* pBinary */       pBinary_Vulkan_SPIRV_FDrawablePaletteMap,
    /* pBinary */       pBinary_Vulkan_SPIRV_FDrawablePaletteMap_size,
    /* Uniforms */      Uniforms_2402564022,
    /* BatchUniforms */ BatchUniforms_5760312302,
    
};

const FragShaderDesc* FragShaderDesc::Descs[FSI_Count] = {
    0,
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTG,                          // 1
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGMul,                       // 2
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGInv,                       // 3
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGEAlpha,                    // 4
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGEAlphaMul,                 // 5
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGEAlphaInv,                 // 6
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxform,                    // 7
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxformMul,                 // 8
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxformInv,                 // 9
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxformEAlpha,              // 10
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxformEAlphaMul,           // 11
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxformEAlphaInv,           // 12
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxformAc,                  // 13
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxformAcMul,               // 14
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxformAcInv,               // 15
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxformAcEAlpha,            // 16
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxformAcEAlphaMul,         // 17
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGCxformAcEAlphaInv,         // 18
    &ShaderDesc_FS_Vulkan_SPIRV_FVertex,                         // 19
    &ShaderDesc_FS_Vulkan_SPIRV_FVertexMul,                      // 20
    &ShaderDesc_FS_Vulkan_SPIRV_FVertexInv,                      // 21
    &ShaderDesc_FS_Vulkan_SPIRV_FVertexEAlpha,                   // 22
    &ShaderDesc_FS_Vulkan_SPIRV_FVertexEAlphaMul,                // 23
    &ShaderDesc_FS_Vulkan_SPIRV_FVertexEAlphaInv,                // 24
    &ShaderDesc_FS_Vulkan_SPIRV_FVertexCxform,                   // 25
    &ShaderDesc_FS_Vulkan_SPIRV_FVertexCxformMul,                // 26
    &ShaderDesc_FS_Vulkan_SPIRV_FVertexCxformInv,                // 27
    &ShaderDesc_FS_Vulkan_SPIRV_FVertexCxformEAlpha,             // 28
    &ShaderDesc_FS_Vulkan_SPIRV_FVertexCxformEAlphaMul,          // 29
    &ShaderDesc_FS_Vulkan_SPIRV_FVertexCxformEAlphaInv,          // 30
    &ShaderDesc_FS_Vulkan_SPIRV_FVertexCxformAc,                 // 31
    &ShaderDesc_FS_Vulkan_SPIRV_FVertexCxformAcMul,              // 32
    &ShaderDesc_FS_Vulkan_SPIRV_FVertexCxformAcInv,              // 33
    &ShaderDesc_FS_Vulkan_SPIRV_FVertexCxformAcEAlpha,           // 34
    &ShaderDesc_FS_Vulkan_SPIRV_FVertexCxformAcEAlphaMul,        // 35
    &ShaderDesc_FS_Vulkan_SPIRV_FVertexCxformAcEAlphaInv,        // 36
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTG,                     // 37
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGMul,                  // 38
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGInv,                  // 39
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGEAlpha,               // 40
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGEAlphaMul,            // 41
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGEAlphaInv,            // 42
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxform,               // 43
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxformMul,            // 44
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxformInv,            // 45
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxformEAlpha,         // 46
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaMul,      // 47
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaInv,      // 48
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxformAc,             // 49
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxformAcMul,          // 50
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxformAcInv,          // 51
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlpha,       // 52
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaMul,    // 53
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaInv,    // 54
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertex,                    // 55
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexMul,                 // 56
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexInv,                 // 57
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexEAlpha,              // 58
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexEAlphaMul,           // 59
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexEAlphaInv,           // 60
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxform,              // 61
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxformMul,           // 62
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxformInv,           // 63
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxformEAlpha,        // 64
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxformEAlphaMul,     // 65
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxformEAlphaInv,     // 66
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxformAc,            // 67
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxformAcMul,         // 68
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxformAcInv,         // 69
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxformAcEAlpha,      // 70
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaMul,   // 71
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaInv,   // 72
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTG,                     // 73
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGMul,                  // 74
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGInv,                  // 75
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGEAlpha,               // 76
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGEAlphaMul,            // 77
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGEAlphaInv,            // 78
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxform,               // 79
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxformMul,            // 80
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxformInv,            // 81
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxformEAlpha,         // 82
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxformEAlphaMul,      // 83
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxformEAlphaInv,      // 84
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxformAc,             // 85
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxformAcMul,          // 86
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxformAcInv,          // 87
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxformAcEAlpha,       // 88
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxformAcEAlphaMul,    // 89
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGCxformAcEAlphaInv,    // 90
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchVertex,                    // 91
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexMul,                 // 92
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexInv,                 // 93
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexEAlpha,              // 94
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexEAlphaMul,           // 95
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexEAlphaInv,           // 96
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxform,              // 97
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxformMul,           // 98
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxformInv,           // 99
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxformEAlpha,        // 100
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxformEAlphaMul,     // 101
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxformEAlphaInv,     // 102
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxformAc,            // 103
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxformAcMul,         // 104
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxformAcInv,         // 105
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxformAcEAlpha,      // 106
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxformAcEAlphaMul,   // 107
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchVertexCxformAcEAlphaInv,   // 108
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTG,                // 109
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGMul,             // 110
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGInv,             // 111
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGEAlpha,          // 112
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGEAlphaMul,       // 113
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGEAlphaInv,       // 114
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxform,          // 115
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxformMul,       // 116
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxformInv,       // 117
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxformEAlpha,    // 118
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxformEAlphaMul, // 119
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxformEAlphaInv, // 120
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxformAc,        // 121
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxformAcMul,     // 122
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxformAcInv,     // 123
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxformAcEAlpha,  // 124
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxformAcEAlphaMul, // 125
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGTexTGCxformAcEAlphaInv, // 126
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertex,               // 127
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexMul,            // 128
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexInv,            // 129
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexEAlpha,         // 130
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexEAlphaMul,      // 131
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexEAlphaInv,      // 132
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxform,         // 133
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxformMul,      // 134
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxformInv,      // 135
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxformEAlpha,   // 136
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxformEAlphaMul, // 137
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxformEAlphaInv, // 138
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxformAc,       // 139
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxformAcMul,    // 140
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxformAcInv,    // 141
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxformAcEAlpha, // 142
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxformAcEAlphaMul, // 143
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTexTGVertexCxformAcEAlphaInv, // 144
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTG,                 // 145
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGMul,              // 146
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGInv,              // 147
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGEAlpha,           // 148
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGEAlphaMul,        // 149
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGEAlphaInv,        // 150
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxform,           // 151
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxformMul,        // 152
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxformInv,        // 153
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxformEAlpha,     // 154
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxformEAlphaMul,  // 155
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxformEAlphaInv,  // 156
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxformAc,         // 157
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxformAcMul,      // 158
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxformAcInv,      // 159
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxformAcEAlpha,   // 160
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxformAcEAlphaMul, // 161
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGCxformAcEAlphaInv, // 162
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertex,                // 163
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexMul,             // 164
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexInv,             // 165
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexEAlpha,          // 166
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexEAlphaMul,       // 167
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexEAlphaInv,       // 168
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxform,          // 169
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxformMul,       // 170
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxformInv,       // 171
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxformEAlpha,    // 172
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxformEAlphaMul, // 173
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxformEAlphaInv, // 174
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxformAc,        // 175
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxformAcMul,     // 176
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxformAcInv,     // 177
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxformAcEAlpha,  // 178
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxformAcEAlphaMul, // 179
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedVertexCxformAcEAlphaInv, // 180
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTG,            // 181
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGMul,         // 182
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGInv,         // 183
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGEAlpha,      // 184
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGEAlphaMul,   // 185
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGEAlphaInv,   // 186
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxform,      // 187
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxformMul,   // 188
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxformInv,   // 189
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxformEAlpha, // 190
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxformEAlphaMul, // 191
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxformEAlphaInv, // 192
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAc,    // 193
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAcMul, // 194
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAcInv, // 195
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAcEAlpha, // 196
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAcEAlphaMul, // 197
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAcEAlphaInv, // 198
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertex,           // 199
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexMul,        // 200
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexInv,        // 201
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexEAlpha,     // 202
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexEAlphaMul,  // 203
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexEAlphaInv,  // 204
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxform,     // 205
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxformMul,  // 206
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxformInv,  // 207
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxformEAlpha, // 208
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxformEAlphaMul, // 209
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxformEAlphaInv, // 210
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxformAc,   // 211
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxformAcMul, // 212
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxformAcInv, // 213
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxformAcEAlpha, // 214
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxformAcEAlphaMul, // 215
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTexTGVertexCxformAcEAlphaInv, // 216
    &ShaderDesc_FS_Vulkan_SPIRV_FSolid,                          // 217
    &ShaderDesc_FS_Vulkan_SPIRV_FSolidMul,                       // 218
    &ShaderDesc_FS_Vulkan_SPIRV_FSolidInv,                       // 219
    &ShaderDesc_FS_Vulkan_SPIRV_FText,                           // 220
    &ShaderDesc_FS_Vulkan_SPIRV_FTextMul,                        // 221
    &ShaderDesc_FS_Vulkan_SPIRV_FTextInv,                        // 222
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchSolid,                     // 223
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchSolidMul,                  // 224
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchSolidInv,                  // 225
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchText,                      // 226
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTextMul,                   // 227
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchTextInv,                   // 228
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedSolid,                 // 229
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedSolidMul,              // 230
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedSolidInv,              // 231
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedText,                  // 232
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTextMul,               // 233
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedTextInv,               // 234
    &ShaderDesc_FS_Vulkan_SPIRV_FYUV,                            // 235
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVMul,                         // 236
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVEAlpha,                      // 237
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVEAlphaMul,                   // 238
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVCxform,                      // 239
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVCxformMul,                   // 240
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVCxformEAlpha,                // 241
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVCxformEAlphaMul,             // 242
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVCxformAc,                    // 243
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVCxformAcMul,                 // 244
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVCxformAcEAlpha,              // 245
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVCxformAcEAlphaMul,           // 246
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVA,                           // 247
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVAMul,                        // 248
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVAInv,                        // 249
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVAEAlpha,                     // 250
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVAEAlphaMul,                  // 251
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVAEAlphaInv,                  // 252
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVACxform,                     // 253
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVACxformMul,                  // 254
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVACxformInv,                  // 255
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVACxformEAlpha,               // 256
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVACxformEAlphaMul,            // 257
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVACxformEAlphaInv,            // 258
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVACxformAc,                   // 259
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVACxformAcMul,                // 260
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVACxformAcInv,                // 261
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVACxformAcEAlpha,             // 262
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVACxformAcEAlphaMul,          // 263
    &ShaderDesc_FS_Vulkan_SPIRV_FYUVACxformAcEAlphaInv,          // 264
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUV,                       // 265
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVMul,                    // 266
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVEAlpha,                 // 267
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVEAlphaMul,              // 268
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVCxform,                 // 269
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVCxformMul,              // 270
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVCxformEAlpha,           // 271
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVCxformEAlphaMul,        // 272
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVCxformAc,               // 273
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVCxformAcMul,            // 274
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVCxformAcEAlpha,         // 275
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVCxformAcEAlphaMul,      // 276
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVA,                      // 277
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVAMul,                   // 278
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVAInv,                   // 279
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVAEAlpha,                // 280
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVAEAlphaMul,             // 281
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVAEAlphaInv,             // 282
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxform,                // 283
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxformMul,             // 284
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxformInv,             // 285
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxformEAlpha,          // 286
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxformEAlphaMul,       // 287
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxformEAlphaInv,       // 288
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxformAc,              // 289
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxformAcMul,           // 290
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxformAcInv,           // 291
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxformAcEAlpha,        // 292
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxformAcEAlphaMul,     // 293
    &ShaderDesc_FS_Vulkan_SPIRV_FBatchYUVACxformAcEAlphaInv,     // 294
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUV,                   // 295
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVMul,                // 296
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVEAlpha,             // 297
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVEAlphaMul,          // 298
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVCxform,             // 299
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVCxformMul,          // 300
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVCxformEAlpha,       // 301
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVCxformEAlphaMul,    // 302
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVCxformAc,           // 303
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVCxformAcMul,        // 304
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVCxformAcEAlpha,     // 305
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVCxformAcEAlphaMul,  // 306
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVA,                  // 307
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVAMul,               // 308
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVAInv,               // 309
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVAEAlpha,            // 310
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVAEAlphaMul,         // 311
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVAEAlphaInv,         // 312
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxform,            // 313
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxformMul,         // 314
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxformInv,         // 315
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxformEAlpha,      // 316
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxformEAlphaMul,   // 317
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxformEAlphaInv,   // 318
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxformAc,          // 319
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxformAcMul,       // 320
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxformAcInv,       // 321
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxformAcEAlpha,    // 322
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxformAcEAlphaMul, // 323
    &ShaderDesc_FS_Vulkan_SPIRV_FInstancedYUVACxformAcEAlphaInv, // 324
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGCMatrixAc,                 // 325
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGCMatrixAcMul,              // 326
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGCMatrixAcEAlpha,           // 327
    &ShaderDesc_FS_Vulkan_SPIRV_FTexTGCMatrixAcEAlphaMul,        // 328
    &ShaderDesc_FS_Vulkan_SPIRV_FBox1Blur,                       // 329
    &ShaderDesc_FS_Vulkan_SPIRV_FBox1BlurMul,                    // 330
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2Blur,                       // 331
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2BlurMul,                    // 332
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2Shadow,                     // 333
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2ShadowMul,                  // 334
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2ShadowKnockout,             // 335
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2ShadowKnockoutMul,          // 336
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2InnerShadow,                // 337
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2InnerShadowMul,             // 338
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2InnerShadowKnockout,        // 339
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2InnerShadowKnockoutMul,     // 340
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2Shadowonly,                 // 341
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2ShadowonlyMul,              // 342
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2ShadowHighlight,            // 343
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2ShadowHighlightMul,         // 344
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2ShadowHighlightKnockout,    // 345
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2ShadowHighlightKnockoutMul, // 346
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2InnerShadowHighlight,       // 347
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2InnerShadowHighlightMul,    // 348
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2InnerShadowHighlightKnockout, // 349
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2InnerShadowHighlightKnockoutMul, // 350
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2FullShadowHighlight,        // 351
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2FullShadowHighlightMul,     // 352
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2ShadowonlyHighlight,        // 353
    &ShaderDesc_FS_Vulkan_SPIRV_FBox2ShadowonlyHighlightMul,     // 354
    &ShaderDesc_FS_Vulkan_SPIRV_FDrawableCopyPixels,             // 355
    &ShaderDesc_FS_Vulkan_SPIRV_FDrawableCopyPixelsMergeAlpha,   // 356
    &ShaderDesc_FS_Vulkan_SPIRV_FDrawableCopyPixelsNoDestAlpha,  // 357
    &ShaderDesc_FS_Vulkan_SPIRV_FDrawableCopyPixelsAlpha,        // 358
    &ShaderDesc_FS_Vulkan_SPIRV_FDrawableCopyPixelsAlphaMergeAlpha, // 359
    &ShaderDesc_FS_Vulkan_SPIRV_FDrawableCopyPixelsAlphaNoDestAlpha, // 360
    &ShaderDesc_FS_Vulkan_SPIRV_FDrawableMerge,                  // 361
    &ShaderDesc_FS_Vulkan_SPIRV_FDrawableCompare,                // 362
    &ShaderDesc_FS_Vulkan_SPIRV_FDrawablePaletteMap,             // 363
};

const FragShaderDesc* FragShaderDesc::GetDesc(ShaderDesc::ShaderType shader, ShaderDesc::ShaderVersion ver)
{
    return Descs[GetShaderIndex(shader, ver)];
};

FragShaderDesc::ShaderIndex FragShaderDesc::GetShaderIndex(ShaderDesc::ShaderType shader, ShaderDesc::ShaderVersion ver)
{
    ShaderDesc::ShaderIndex index = ShaderDesc::GetShaderIndex(shader);
    return ShaderIndexingData[index][ver]. FragIndex;
};

FragShaderDesc::ShaderIndex FragShaderDesc::GetShaderIndexForComboIndex(unsigned index, ShaderDesc::ShaderVersion ver) 
{
    switch(ver)
    {
        case ShaderDesc::ShaderVersion_Vulkan_SPIRV:
        switch(index)
        {
            case 0:             return FSI_Vulkan_SPIRV_FTexTG;
            case 1:             return FSI_Vulkan_SPIRV_FTexTGMul;
            case 2:             return FSI_Vulkan_SPIRV_FTexTGInv;
            case 3:             return FSI_Vulkan_SPIRV_FTexTGEAlpha;
            case 4:             return FSI_Vulkan_SPIRV_FTexTGEAlphaMul;
            case 5:             return FSI_Vulkan_SPIRV_FTexTGEAlphaInv;
            case 6:             return FSI_Vulkan_SPIRV_FTexTGCxform;
            case 7:             return FSI_Vulkan_SPIRV_FTexTGCxformMul;
            case 8:             return FSI_Vulkan_SPIRV_FTexTGCxformInv;
            case 9:             return FSI_Vulkan_SPIRV_FTexTGCxformEAlpha;
            case 10:            return FSI_Vulkan_SPIRV_FTexTGCxformEAlphaMul;
            case 11:            return FSI_Vulkan_SPIRV_FTexTGCxformEAlphaInv;
            case 12:            return FSI_Vulkan_SPIRV_FTexTGCxformAc;
            case 13:            return FSI_Vulkan_SPIRV_FTexTGCxformAcMul;
            case 14:            return FSI_Vulkan_SPIRV_FTexTGCxformAcInv;
            case 15:            return FSI_Vulkan_SPIRV_FTexTGCxformAcEAlpha;
            case 16:            return FSI_Vulkan_SPIRV_FTexTGCxformAcEAlphaMul;
            case 17:            return FSI_Vulkan_SPIRV_FTexTGCxformAcEAlphaInv;
            case 18:            return FSI_Vulkan_SPIRV_FVertex;
            case 19:            return FSI_Vulkan_SPIRV_FVertexMul;
            case 20:            return FSI_Vulkan_SPIRV_FVertexInv;
            case 21:            return FSI_Vulkan_SPIRV_FVertexEAlpha;
            case 22:            return FSI_Vulkan_SPIRV_FVertexEAlphaMul;
            case 23:            return FSI_Vulkan_SPIRV_FVertexEAlphaInv;
            case 24:            return FSI_Vulkan_SPIRV_FVertexCxform;
            case 25:            return FSI_Vulkan_SPIRV_FVertexCxformMul;
            case 26:            return FSI_Vulkan_SPIRV_FVertexCxformInv;
            case 27:            return FSI_Vulkan_SPIRV_FVertexCxformEAlpha;
            case 28:            return FSI_Vulkan_SPIRV_FVertexCxformEAlphaMul;
            case 29:            return FSI_Vulkan_SPIRV_FVertexCxformEAlphaInv;
            case 30:            return FSI_Vulkan_SPIRV_FVertexCxformAc;
            case 31:            return FSI_Vulkan_SPIRV_FVertexCxformAcMul;
            case 32:            return FSI_Vulkan_SPIRV_FVertexCxformAcInv;
            case 33:            return FSI_Vulkan_SPIRV_FVertexCxformAcEAlpha;
            case 34:            return FSI_Vulkan_SPIRV_FVertexCxformAcEAlphaMul;
            case 35:            return FSI_Vulkan_SPIRV_FVertexCxformAcEAlphaInv;
            case 36:            return FSI_Vulkan_SPIRV_FTexTGTexTG;
            case 37:            return FSI_Vulkan_SPIRV_FTexTGTexTGMul;
            case 38:            return FSI_Vulkan_SPIRV_FTexTGTexTGInv;
            case 39:            return FSI_Vulkan_SPIRV_FTexTGTexTGEAlpha;
            case 40:            return FSI_Vulkan_SPIRV_FTexTGTexTGEAlphaMul;
            case 41:            return FSI_Vulkan_SPIRV_FTexTGTexTGEAlphaInv;
            case 42:            return FSI_Vulkan_SPIRV_FTexTGTexTGCxform;
            case 43:            return FSI_Vulkan_SPIRV_FTexTGTexTGCxformMul;
            case 44:            return FSI_Vulkan_SPIRV_FTexTGTexTGCxformInv;
            case 45:            return FSI_Vulkan_SPIRV_FTexTGTexTGCxformEAlpha;
            case 46:            return FSI_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaMul;
            case 47:            return FSI_Vulkan_SPIRV_FTexTGTexTGCxformEAlphaInv;
            case 48:            return FSI_Vulkan_SPIRV_FTexTGTexTGCxformAc;
            case 49:            return FSI_Vulkan_SPIRV_FTexTGTexTGCxformAcMul;
            case 50:            return FSI_Vulkan_SPIRV_FTexTGTexTGCxformAcInv;
            case 51:            return FSI_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlpha;
            case 52:            return FSI_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaMul;
            case 53:            return FSI_Vulkan_SPIRV_FTexTGTexTGCxformAcEAlphaInv;
            case 54:            return FSI_Vulkan_SPIRV_FTexTGVertex;
            case 55:            return FSI_Vulkan_SPIRV_FTexTGVertexMul;
            case 56:            return FSI_Vulkan_SPIRV_FTexTGVertexInv;
            case 57:            return FSI_Vulkan_SPIRV_FTexTGVertexEAlpha;
            case 58:            return FSI_Vulkan_SPIRV_FTexTGVertexEAlphaMul;
            case 59:            return FSI_Vulkan_SPIRV_FTexTGVertexEAlphaInv;
            case 60:            return FSI_Vulkan_SPIRV_FTexTGVertexCxform;
            case 61:            return FSI_Vulkan_SPIRV_FTexTGVertexCxformMul;
            case 62:            return FSI_Vulkan_SPIRV_FTexTGVertexCxformInv;
            case 63:            return FSI_Vulkan_SPIRV_FTexTGVertexCxformEAlpha;
            case 64:            return FSI_Vulkan_SPIRV_FTexTGVertexCxformEAlphaMul;
            case 65:            return FSI_Vulkan_SPIRV_FTexTGVertexCxformEAlphaInv;
            case 66:            return FSI_Vulkan_SPIRV_FTexTGVertexCxformAc;
            case 67:            return FSI_Vulkan_SPIRV_FTexTGVertexCxformAcMul;
            case 68:            return FSI_Vulkan_SPIRV_FTexTGVertexCxformAcInv;
            case 69:            return FSI_Vulkan_SPIRV_FTexTGVertexCxformAcEAlpha;
            case 70:            return FSI_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaMul;
            case 71:            return FSI_Vulkan_SPIRV_FTexTGVertexCxformAcEAlphaInv;
            case 72:            return FSI_Vulkan_SPIRV_FPosition3dTexTG;
            case 73:            return FSI_Vulkan_SPIRV_FPosition3dTexTGMul;
            case 74:            return FSI_Vulkan_SPIRV_FPosition3dTexTGInv;
            case 75:            return FSI_Vulkan_SPIRV_FPosition3dTexTGEAlpha;
            case 76:            return FSI_Vulkan_SPIRV_FPosition3dTexTGEAlphaMul;
            case 77:            return FSI_Vulkan_SPIRV_FPosition3dTexTGEAlphaInv;
            case 78:            return FSI_Vulkan_SPIRV_FPosition3dTexTGCxform;
            case 79:            return FSI_Vulkan_SPIRV_FPosition3dTexTGCxformMul;
            case 80:            return FSI_Vulkan_SPIRV_FPosition3dTexTGCxformInv;
            case 81:            return FSI_Vulkan_SPIRV_FPosition3dTexTGCxformEAlpha;
            case 82:            return FSI_Vulkan_SPIRV_FPosition3dTexTGCxformEAlphaMul;
            case 83:            return FSI_Vulkan_SPIRV_FPosition3dTexTGCxformEAlphaInv;
            case 84:            return FSI_Vulkan_SPIRV_FPosition3dTexTGCxformAc;
            case 85:            return FSI_Vulkan_SPIRV_FPosition3dTexTGCxformAcMul;
            case 86:            return FSI_Vulkan_SPIRV_FPosition3dTexTGCxformAcInv;
            case 87:            return FSI_Vulkan_SPIRV_FPosition3dTexTGCxformAcEAlpha;
            case 88:            return FSI_Vulkan_SPIRV_FPosition3dTexTGCxformAcEAlphaMul;
            case 89:            return FSI_Vulkan_SPIRV_FPosition3dTexTGCxformAcEAlphaInv;
            case 90:            return FSI_Vulkan_SPIRV_FPosition3dVertex;
            case 91:            return FSI_Vulkan_SPIRV_FPosition3dVertexMul;
            case 92:            return FSI_Vulkan_SPIRV_FPosition3dVertexInv;
            case 93:            return FSI_Vulkan_SPIRV_FPosition3dVertexEAlpha;
            case 94:            return FSI_Vulkan_SPIRV_FPosition3dVertexEAlphaMul;
            case 95:            return FSI_Vulkan_SPIRV_FPosition3dVertexEAlphaInv;
            case 96:            return FSI_Vulkan_SPIRV_FPosition3dVertexCxform;
            case 97:            return FSI_Vulkan_SPIRV_FPosition3dVertexCxformMul;
            case 98:            return FSI_Vulkan_SPIRV_FPosition3dVertexCxformInv;
            case 99:            return FSI_Vulkan_SPIRV_FPosition3dVertexCxformEAlpha;
            case 100:           return FSI_Vulkan_SPIRV_FPosition3dVertexCxformEAlphaMul;
            case 101:           return FSI_Vulkan_SPIRV_FPosition3dVertexCxformEAlphaInv;
            case 102:           return FSI_Vulkan_SPIRV_FPosition3dVertexCxformAc;
            case 103:           return FSI_Vulkan_SPIRV_FPosition3dVertexCxformAcMul;
            case 104:           return FSI_Vulkan_SPIRV_FPosition3dVertexCxformAcInv;
            case 105:           return FSI_Vulkan_SPIRV_FPosition3dVertexCxformAcEAlpha;
            case 106:           return FSI_Vulkan_SPIRV_FPosition3dVertexCxformAcEAlphaMul;
            case 107:           return FSI_Vulkan_SPIRV_FPosition3dVertexCxformAcEAlphaInv;
            case 108:           return FSI_Vulkan_SPIRV_FPosition3dTexTGTexTG;
            case 109:           return FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGMul;
            case 110:           return FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGInv;
            case 111:           return FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGEAlpha;
            case 112:           return FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGEAlphaMul;
            case 113:           return FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGEAlphaInv;
            case 114:           return FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxform;
            case 115:           return FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxformMul;
            case 116:           return FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxformInv;
            case 117:           return FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxformEAlpha;
            case 118:           return FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxformEAlphaMul;
            case 119:           return FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxformEAlphaInv;
            case 120:           return FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxformAc;
            case 121:           return FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxformAcMul;
            case 122:           return FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxformAcInv;
            case 123:           return FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxformAcEAlpha;
            case 124:           return FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxformAcEAlphaMul;
            case 125:           return FSI_Vulkan_SPIRV_FPosition3dTexTGTexTGCxformAcEAlphaInv;
            case 126:           return FSI_Vulkan_SPIRV_FPosition3dTexTGVertex;
            case 127:           return FSI_Vulkan_SPIRV_FPosition3dTexTGVertexMul;
            case 128:           return FSI_Vulkan_SPIRV_FPosition3dTexTGVertexInv;
            case 129:           return FSI_Vulkan_SPIRV_FPosition3dTexTGVertexEAlpha;
            case 130:           return FSI_Vulkan_SPIRV_FPosition3dTexTGVertexEAlphaMul;
            case 131:           return FSI_Vulkan_SPIRV_FPosition3dTexTGVertexEAlphaInv;
            case 132:           return FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxform;
            case 133:           return FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxformMul;
            case 134:           return FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxformInv;
            case 135:           return FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxformEAlpha;
            case 136:           return FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxformEAlphaMul;
            case 137:           return FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxformEAlphaInv;
            case 138:           return FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxformAc;
            case 139:           return FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxformAcMul;
            case 140:           return FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxformAcInv;
            case 141:           return FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxformAcEAlpha;
            case 142:           return FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxformAcEAlphaMul;
            case 143:           return FSI_Vulkan_SPIRV_FPosition3dTexTGVertexCxformAcEAlphaInv;
            case 144:           return FSI_Vulkan_SPIRV_FBatchTexTG;
            case 145:           return FSI_Vulkan_SPIRV_FBatchTexTGMul;
            case 146:           return FSI_Vulkan_SPIRV_FBatchTexTGInv;
            case 147:           return FSI_Vulkan_SPIRV_FBatchTexTGEAlpha;
            case 148:           return FSI_Vulkan_SPIRV_FBatchTexTGEAlphaMul;
            case 149:           return FSI_Vulkan_SPIRV_FBatchTexTGEAlphaInv;
            case 150:           return FSI_Vulkan_SPIRV_FBatchTexTGCxform;
            case 151:           return FSI_Vulkan_SPIRV_FBatchTexTGCxformMul;
            case 152:           return FSI_Vulkan_SPIRV_FBatchTexTGCxformInv;
            case 153:           return FSI_Vulkan_SPIRV_FBatchTexTGCxformEAlpha;
            case 154:           return FSI_Vulkan_SPIRV_FBatchTexTGCxformEAlphaMul;
            case 155:           return FSI_Vulkan_SPIRV_FBatchTexTGCxformEAlphaInv;
            case 156:           return FSI_Vulkan_SPIRV_FBatchTexTGCxformAc;
            case 157:           return FSI_Vulkan_SPIRV_FBatchTexTGCxformAcMul;
            case 158:           return FSI_Vulkan_SPIRV_FBatchTexTGCxformAcInv;
            case 159:           return FSI_Vulkan_SPIRV_FBatchTexTGCxformAcEAlpha;
            case 160:           return FSI_Vulkan_SPIRV_FBatchTexTGCxformAcEAlphaMul;
            case 161:           return FSI_Vulkan_SPIRV_FBatchTexTGCxformAcEAlphaInv;
            case 162:           return FSI_Vulkan_SPIRV_FBatchVertex;
            case 163:           return FSI_Vulkan_SPIRV_FBatchVertexMul;
            case 164:           return FSI_Vulkan_SPIRV_FBatchVertexInv;
            case 165:           return FSI_Vulkan_SPIRV_FBatchVertexEAlpha;
            case 166:           return FSI_Vulkan_SPIRV_FBatchVertexEAlphaMul;
            case 167:           return FSI_Vulkan_SPIRV_FBatchVertexEAlphaInv;
            case 168:           return FSI_Vulkan_SPIRV_FBatchVertexCxform;
            case 169:           return FSI_Vulkan_SPIRV_FBatchVertexCxformMul;
            case 170:           return FSI_Vulkan_SPIRV_FBatchVertexCxformInv;
            case 171:           return FSI_Vulkan_SPIRV_FBatchVertexCxformEAlpha;
            case 172:           return FSI_Vulkan_SPIRV_FBatchVertexCxformEAlphaMul;
            case 173:           return FSI_Vulkan_SPIRV_FBatchVertexCxformEAlphaInv;
            case 174:           return FSI_Vulkan_SPIRV_FBatchVertexCxformAc;
            case 175:           return FSI_Vulkan_SPIRV_FBatchVertexCxformAcMul;
            case 176:           return FSI_Vulkan_SPIRV_FBatchVertexCxformAcInv;
            case 177:           return FSI_Vulkan_SPIRV_FBatchVertexCxformAcEAlpha;
            case 178:           return FSI_Vulkan_SPIRV_FBatchVertexCxformAcEAlphaMul;
            case 179:           return FSI_Vulkan_SPIRV_FBatchVertexCxformAcEAlphaInv;
            case 180:           return FSI_Vulkan_SPIRV_FBatchTexTGTexTG;
            case 181:           return FSI_Vulkan_SPIRV_FBatchTexTGTexTGMul;
            case 182:           return FSI_Vulkan_SPIRV_FBatchTexTGTexTGInv;
            case 183:           return FSI_Vulkan_SPIRV_FBatchTexTGTexTGEAlpha;
            case 184:           return FSI_Vulkan_SPIRV_FBatchTexTGTexTGEAlphaMul;
            case 185:           return FSI_Vulkan_SPIRV_FBatchTexTGTexTGEAlphaInv;
            case 186:           return FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxform;
            case 187:           return FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxformMul;
            case 188:           return FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxformInv;
            case 189:           return FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxformEAlpha;
            case 190:           return FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxformEAlphaMul;
            case 191:           return FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxformEAlphaInv;
            case 192:           return FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxformAc;
            case 193:           return FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxformAcMul;
            case 194:           return FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxformAcInv;
            case 195:           return FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxformAcEAlpha;
            case 196:           return FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxformAcEAlphaMul;
            case 197:           return FSI_Vulkan_SPIRV_FBatchTexTGTexTGCxformAcEAlphaInv;
            case 198:           return FSI_Vulkan_SPIRV_FBatchTexTGVertex;
            case 199:           return FSI_Vulkan_SPIRV_FBatchTexTGVertexMul;
            case 200:           return FSI_Vulkan_SPIRV_FBatchTexTGVertexInv;
            case 201:           return FSI_Vulkan_SPIRV_FBatchTexTGVertexEAlpha;
            case 202:           return FSI_Vulkan_SPIRV_FBatchTexTGVertexEAlphaMul;
            case 203:           return FSI_Vulkan_SPIRV_FBatchTexTGVertexEAlphaInv;
            case 204:           return FSI_Vulkan_SPIRV_FBatchTexTGVertexCxform;
            case 205:           return FSI_Vulkan_SPIRV_FBatchTexTGVertexCxformMul;
            case 206:           return FSI_Vulkan_SPIRV_FBatchTexTGVertexCxformInv;
            case 207:           return FSI_Vulkan_SPIRV_FBatchTexTGVertexCxformEAlpha;
            case 208:           return FSI_Vulkan_SPIRV_FBatchTexTGVertexCxformEAlphaMul;
            case 209:           return FSI_Vulkan_SPIRV_FBatchTexTGVertexCxformEAlphaInv;
            case 210:           return FSI_Vulkan_SPIRV_FBatchTexTGVertexCxformAc;
            case 211:           return FSI_Vulkan_SPIRV_FBatchTexTGVertexCxformAcMul;
            case 212:           return FSI_Vulkan_SPIRV_FBatchTexTGVertexCxformAcInv;
            case 213:           return FSI_Vulkan_SPIRV_FBatchTexTGVertexCxformAcEAlpha;
            case 214:           return FSI_Vulkan_SPIRV_FBatchTexTGVertexCxformAcEAlphaMul;
            case 215:           return FSI_Vulkan_SPIRV_FBatchTexTGVertexCxformAcEAlphaInv;
            case 216:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTG;
            case 217:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGMul;
            case 218:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGInv;
            case 219:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGEAlpha;
            case 220:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGEAlphaMul;
            case 221:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGEAlphaInv;
            case 222:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxform;
            case 223:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxformMul;
            case 224:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxformInv;
            case 225:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxformEAlpha;
            case 226:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxformEAlphaMul;
            case 227:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxformEAlphaInv;
            case 228:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxformAc;
            case 229:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxformAcMul;
            case 230:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxformAcInv;
            case 231:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxformAcEAlpha;
            case 232:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxformAcEAlphaMul;
            case 233:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGCxformAcEAlphaInv;
            case 234:           return FSI_Vulkan_SPIRV_FBatchPosition3dVertex;
            case 235:           return FSI_Vulkan_SPIRV_FBatchPosition3dVertexMul;
            case 236:           return FSI_Vulkan_SPIRV_FBatchPosition3dVertexInv;
            case 237:           return FSI_Vulkan_SPIRV_FBatchPosition3dVertexEAlpha;
            case 238:           return FSI_Vulkan_SPIRV_FBatchPosition3dVertexEAlphaMul;
            case 239:           return FSI_Vulkan_SPIRV_FBatchPosition3dVertexEAlphaInv;
            case 240:           return FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxform;
            case 241:           return FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxformMul;
            case 242:           return FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxformInv;
            case 243:           return FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxformEAlpha;
            case 244:           return FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxformEAlphaMul;
            case 245:           return FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxformEAlphaInv;
            case 246:           return FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxformAc;
            case 247:           return FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxformAcMul;
            case 248:           return FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxformAcInv;
            case 249:           return FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxformAcEAlpha;
            case 250:           return FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxformAcEAlphaMul;
            case 251:           return FSI_Vulkan_SPIRV_FBatchPosition3dVertexCxformAcEAlphaInv;
            case 252:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTG;
            case 253:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGMul;
            case 254:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGInv;
            case 255:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGEAlpha;
            case 256:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGEAlphaMul;
            case 257:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGEAlphaInv;
            case 258:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxform;
            case 259:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxformMul;
            case 260:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxformInv;
            case 261:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxformEAlpha;
            case 262:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxformEAlphaMul;
            case 263:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxformEAlphaInv;
            case 264:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxformAc;
            case 265:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxformAcMul;
            case 266:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxformAcInv;
            case 267:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxformAcEAlpha;
            case 268:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxformAcEAlphaMul;
            case 269:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGTexTGCxformAcEAlphaInv;
            case 270:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertex;
            case 271:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexMul;
            case 272:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexInv;
            case 273:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexEAlpha;
            case 274:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexEAlphaMul;
            case 275:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexEAlphaInv;
            case 276:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxform;
            case 277:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxformMul;
            case 278:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxformInv;
            case 279:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxformEAlpha;
            case 280:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxformEAlphaMul;
            case 281:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxformEAlphaInv;
            case 282:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxformAc;
            case 283:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxformAcMul;
            case 284:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxformAcInv;
            case 285:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxformAcEAlpha;
            case 286:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxformAcEAlphaMul;
            case 287:           return FSI_Vulkan_SPIRV_FBatchPosition3dTexTGVertexCxformAcEAlphaInv;
            case 288:           return FSI_Vulkan_SPIRV_FInstancedTexTG;
            case 289:           return FSI_Vulkan_SPIRV_FInstancedTexTGMul;
            case 290:           return FSI_Vulkan_SPIRV_FInstancedTexTGInv;
            case 291:           return FSI_Vulkan_SPIRV_FInstancedTexTGEAlpha;
            case 292:           return FSI_Vulkan_SPIRV_FInstancedTexTGEAlphaMul;
            case 293:           return FSI_Vulkan_SPIRV_FInstancedTexTGEAlphaInv;
            case 294:           return FSI_Vulkan_SPIRV_FInstancedTexTGCxform;
            case 295:           return FSI_Vulkan_SPIRV_FInstancedTexTGCxformMul;
            case 296:           return FSI_Vulkan_SPIRV_FInstancedTexTGCxformInv;
            case 297:           return FSI_Vulkan_SPIRV_FInstancedTexTGCxformEAlpha;
            case 298:           return FSI_Vulkan_SPIRV_FInstancedTexTGCxformEAlphaMul;
            case 299:           return FSI_Vulkan_SPIRV_FInstancedTexTGCxformEAlphaInv;
            case 300:           return FSI_Vulkan_SPIRV_FInstancedTexTGCxformAc;
            case 301:           return FSI_Vulkan_SPIRV_FInstancedTexTGCxformAcMul;
            case 302:           return FSI_Vulkan_SPIRV_FInstancedTexTGCxformAcInv;
            case 303:           return FSI_Vulkan_SPIRV_FInstancedTexTGCxformAcEAlpha;
            case 304:           return FSI_Vulkan_SPIRV_FInstancedTexTGCxformAcEAlphaMul;
            case 305:           return FSI_Vulkan_SPIRV_FInstancedTexTGCxformAcEAlphaInv;
            case 306:           return FSI_Vulkan_SPIRV_FInstancedVertex;
            case 307:           return FSI_Vulkan_SPIRV_FInstancedVertexMul;
            case 308:           return FSI_Vulkan_SPIRV_FInstancedVertexInv;
            case 309:           return FSI_Vulkan_SPIRV_FInstancedVertexEAlpha;
            case 310:           return FSI_Vulkan_SPIRV_FInstancedVertexEAlphaMul;
            case 311:           return FSI_Vulkan_SPIRV_FInstancedVertexEAlphaInv;
            case 312:           return FSI_Vulkan_SPIRV_FInstancedVertexCxform;
            case 313:           return FSI_Vulkan_SPIRV_FInstancedVertexCxformMul;
            case 314:           return FSI_Vulkan_SPIRV_FInstancedVertexCxformInv;
            case 315:           return FSI_Vulkan_SPIRV_FInstancedVertexCxformEAlpha;
            case 316:           return FSI_Vulkan_SPIRV_FInstancedVertexCxformEAlphaMul;
            case 317:           return FSI_Vulkan_SPIRV_FInstancedVertexCxformEAlphaInv;
            case 318:           return FSI_Vulkan_SPIRV_FInstancedVertexCxformAc;
            case 319:           return FSI_Vulkan_SPIRV_FInstancedVertexCxformAcMul;
            case 320:           return FSI_Vulkan_SPIRV_FInstancedVertexCxformAcInv;
            case 321:           return FSI_Vulkan_SPIRV_FInstancedVertexCxformAcEAlpha;
            case 322:           return FSI_Vulkan_SPIRV_FInstancedVertexCxformAcEAlphaMul;
            case 323:           return FSI_Vulkan_SPIRV_FInstancedVertexCxformAcEAlphaInv;
            case 324:           return FSI_Vulkan_SPIRV_FInstancedTexTGTexTG;
            case 325:           return FSI_Vulkan_SPIRV_FInstancedTexTGTexTGMul;
            case 326:           return FSI_Vulkan_SPIRV_FInstancedTexTGTexTGInv;
            case 327:           return FSI_Vulkan_SPIRV_FInstancedTexTGTexTGEAlpha;
            case 328:           return FSI_Vulkan_SPIRV_FInstancedTexTGTexTGEAlphaMul;
            case 329:           return FSI_Vulkan_SPIRV_FInstancedTexTGTexTGEAlphaInv;
            case 330:           return FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxform;
            case 331:           return FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxformMul;
            case 332:           return FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxformInv;
            case 333:           return FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxformEAlpha;
            case 334:           return FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxformEAlphaMul;
            case 335:           return FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxformEAlphaInv;
            case 336:           return FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAc;
            case 337:           return FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAcMul;
            case 338:           return FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAcInv;
            case 339:           return FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAcEAlpha;
            case 340:           return FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAcEAlphaMul;
            case 341:           return FSI_Vulkan_SPIRV_FInstancedTexTGTexTGCxformAcEAlphaInv;
            case 342:           return FSI_Vulkan_SPIRV_FInstancedTexTGVertex;
            case 343:           return FSI_Vulkan_SPIRV_FInstancedTexTGVertexMul;
            case 344:           return FSI_Vulkan_SPIRV_FInstancedTexTGVertexInv;
            case 345:           return FSI_Vulkan_SPIRV_FInstancedTexTGVertexEAlpha;
            case 346:           return FSI_Vulkan_SPIRV_FInstancedTexTGVertexEAlphaMul;
            case 347:           return FSI_Vulkan_SPIRV_FInstancedTexTGVertexEAlphaInv;
            case 348:           return FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxform;
            case 349:           return FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxformMul;
            case 350:           return FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxformInv;
            case 351:           return FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxformEAlpha;
            case 352:           return FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxformEAlphaMul;
            case 353:           return FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxformEAlphaInv;
            case 354:           return FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxformAc;
            case 355:           return FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxformAcMul;
            case 356:           return FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxformAcInv;
            case 357:           return FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxformAcEAlpha;
            case 358:           return FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxformAcEAlphaMul;
            case 359:           return FSI_Vulkan_SPIRV_FInstancedTexTGVertexCxformAcEAlphaInv;
            case 360:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTG;
            case 361:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGMul;
            case 362:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGInv;
            case 363:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGEAlpha;
            case 364:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGEAlphaMul;
            case 365:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGEAlphaInv;
            case 366:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxform;
            case 367:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxformMul;
            case 368:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxformInv;
            case 369:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxformEAlpha;
            case 370:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxformEAlphaMul;
            case 371:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxformEAlphaInv;
            case 372:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxformAc;
            case 373:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxformAcMul;
            case 374:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxformAcInv;
            case 375:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxformAcEAlpha;
            case 376:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxformAcEAlphaMul;
            case 377:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGCxformAcEAlphaInv;
            case 378:           return FSI_Vulkan_SPIRV_FInstancedPosition3dVertex;
            case 379:           return FSI_Vulkan_SPIRV_FInstancedPosition3dVertexMul;
            case 380:           return FSI_Vulkan_SPIRV_FInstancedPosition3dVertexInv;
            case 381:           return FSI_Vulkan_SPIRV_FInstancedPosition3dVertexEAlpha;
            case 382:           return FSI_Vulkan_SPIRV_FInstancedPosition3dVertexEAlphaMul;
            case 383:           return FSI_Vulkan_SPIRV_FInstancedPosition3dVertexEAlphaInv;
            case 384:           return FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxform;
            case 385:           return FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxformMul;
            case 386:           return FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxformInv;
            case 387:           return FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxformEAlpha;
            case 388:           return FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxformEAlphaMul;
            case 389:           return FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxformEAlphaInv;
            case 390:           return FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxformAc;
            case 391:           return FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxformAcMul;
            case 392:           return FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxformAcInv;
            case 393:           return FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxformAcEAlpha;
            case 394:           return FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxformAcEAlphaMul;
            case 395:           return FSI_Vulkan_SPIRV_FInstancedPosition3dVertexCxformAcEAlphaInv;
            case 396:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTG;
            case 397:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGMul;
            case 398:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGInv;
            case 399:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGEAlpha;
            case 400:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGEAlphaMul;
            case 401:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGEAlphaInv;
            case 402:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxform;
            case 403:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxformMul;
            case 404:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxformInv;
            case 405:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxformEAlpha;
            case 406:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxformEAlphaMul;
            case 407:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxformEAlphaInv;
            case 408:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxformAc;
            case 409:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxformAcMul;
            case 410:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxformAcInv;
            case 411:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxformAcEAlpha;
            case 412:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxformAcEAlphaMul;
            case 413:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGTexTGCxformAcEAlphaInv;
            case 414:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertex;
            case 415:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexMul;
            case 416:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexInv;
            case 417:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexEAlpha;
            case 418:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexEAlphaMul;
            case 419:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexEAlphaInv;
            case 420:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxform;
            case 421:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxformMul;
            case 422:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxformInv;
            case 423:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxformEAlpha;
            case 424:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxformEAlphaMul;
            case 425:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxformEAlphaInv;
            case 426:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxformAc;
            case 427:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxformAcMul;
            case 428:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxformAcInv;
            case 429:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxformAcEAlpha;
            case 430:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxformAcEAlphaMul;
            case 431:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTexTGVertexCxformAcEAlphaInv;
            case 432:           return FSI_Vulkan_SPIRV_FSolid;
            case 433:           return FSI_Vulkan_SPIRV_FSolidMul;
            case 434:           return FSI_Vulkan_SPIRV_FSolidInv;
            case 435:           return FSI_Vulkan_SPIRV_FText;
            case 436:           return FSI_Vulkan_SPIRV_FTextMul;
            case 437:           return FSI_Vulkan_SPIRV_FTextInv;
            case 438:           return FSI_Vulkan_SPIRV_FTextColor;
            case 439:           return FSI_Vulkan_SPIRV_FTextColorMul;
            case 440:           return FSI_Vulkan_SPIRV_FTextColorInv;
            case 441:           return FSI_Vulkan_SPIRV_FTextColorCxform;
            case 442:           return FSI_Vulkan_SPIRV_FTextColorCxformMul;
            case 443:           return FSI_Vulkan_SPIRV_FTextColorCxformInv;
            case 444:           return FSI_Vulkan_SPIRV_FPosition3dSolid;
            case 445:           return FSI_Vulkan_SPIRV_FPosition3dSolidMul;
            case 446:           return FSI_Vulkan_SPIRV_FPosition3dSolidInv;
            case 447:           return FSI_Vulkan_SPIRV_FPosition3dText;
            case 448:           return FSI_Vulkan_SPIRV_FPosition3dTextMul;
            case 449:           return FSI_Vulkan_SPIRV_FPosition3dTextInv;
            case 450:           return FSI_Vulkan_SPIRV_FPosition3dTextColor;
            case 451:           return FSI_Vulkan_SPIRV_FPosition3dTextColorMul;
            case 452:           return FSI_Vulkan_SPIRV_FPosition3dTextColorInv;
            case 453:           return FSI_Vulkan_SPIRV_FPosition3dTextColorCxform;
            case 454:           return FSI_Vulkan_SPIRV_FPosition3dTextColorCxformMul;
            case 455:           return FSI_Vulkan_SPIRV_FPosition3dTextColorCxformInv;
            case 456:           return FSI_Vulkan_SPIRV_FBatchSolid;
            case 457:           return FSI_Vulkan_SPIRV_FBatchSolidMul;
            case 458:           return FSI_Vulkan_SPIRV_FBatchSolidInv;
            case 459:           return FSI_Vulkan_SPIRV_FBatchText;
            case 460:           return FSI_Vulkan_SPIRV_FBatchTextMul;
            case 461:           return FSI_Vulkan_SPIRV_FBatchTextInv;
            case 462:           return FSI_Vulkan_SPIRV_FBatchTextColor;
            case 463:           return FSI_Vulkan_SPIRV_FBatchTextColorMul;
            case 464:           return FSI_Vulkan_SPIRV_FBatchTextColorInv;
            case 465:           return FSI_Vulkan_SPIRV_FBatchTextColorCxform;
            case 466:           return FSI_Vulkan_SPIRV_FBatchTextColorCxformMul;
            case 467:           return FSI_Vulkan_SPIRV_FBatchTextColorCxformInv;
            case 468:           return FSI_Vulkan_SPIRV_FBatchPosition3dSolid;
            case 469:           return FSI_Vulkan_SPIRV_FBatchPosition3dSolidMul;
            case 470:           return FSI_Vulkan_SPIRV_FBatchPosition3dSolidInv;
            case 471:           return FSI_Vulkan_SPIRV_FBatchPosition3dText;
            case 472:           return FSI_Vulkan_SPIRV_FBatchPosition3dTextMul;
            case 473:           return FSI_Vulkan_SPIRV_FBatchPosition3dTextInv;
            case 474:           return FSI_Vulkan_SPIRV_FBatchPosition3dTextColor;
            case 475:           return FSI_Vulkan_SPIRV_FBatchPosition3dTextColorMul;
            case 476:           return FSI_Vulkan_SPIRV_FBatchPosition3dTextColorInv;
            case 477:           return FSI_Vulkan_SPIRV_FBatchPosition3dTextColorCxform;
            case 478:           return FSI_Vulkan_SPIRV_FBatchPosition3dTextColorCxformMul;
            case 479:           return FSI_Vulkan_SPIRV_FBatchPosition3dTextColorCxformInv;
            case 480:           return FSI_Vulkan_SPIRV_FInstancedSolid;
            case 481:           return FSI_Vulkan_SPIRV_FInstancedSolidMul;
            case 482:           return FSI_Vulkan_SPIRV_FInstancedSolidInv;
            case 483:           return FSI_Vulkan_SPIRV_FInstancedText;
            case 484:           return FSI_Vulkan_SPIRV_FInstancedTextMul;
            case 485:           return FSI_Vulkan_SPIRV_FInstancedTextInv;
            case 486:           return FSI_Vulkan_SPIRV_FInstancedTextColor;
            case 487:           return FSI_Vulkan_SPIRV_FInstancedTextColorMul;
            case 488:           return FSI_Vulkan_SPIRV_FInstancedTextColorInv;
            case 489:           return FSI_Vulkan_SPIRV_FInstancedTextColorCxform;
            case 490:           return FSI_Vulkan_SPIRV_FInstancedTextColorCxformMul;
            case 491:           return FSI_Vulkan_SPIRV_FInstancedTextColorCxformInv;
            case 492:           return FSI_Vulkan_SPIRV_FInstancedPosition3dSolid;
            case 493:           return FSI_Vulkan_SPIRV_FInstancedPosition3dSolidMul;
            case 494:           return FSI_Vulkan_SPIRV_FInstancedPosition3dSolidInv;
            case 495:           return FSI_Vulkan_SPIRV_FInstancedPosition3dText;
            case 496:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTextMul;
            case 497:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTextInv;
            case 498:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTextColor;
            case 499:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTextColorMul;
            case 500:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTextColorInv;
            case 501:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTextColorCxform;
            case 502:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTextColorCxformMul;
            case 503:           return FSI_Vulkan_SPIRV_FInstancedPosition3dTextColorCxformInv;
            case 504:           return FSI_Vulkan_SPIRV_FYUV;
            case 505:           return FSI_Vulkan_SPIRV_FYUVMul;
            case 506:           return FSI_Vulkan_SPIRV_FYUVEAlpha;
            case 507:           return FSI_Vulkan_SPIRV_FYUVEAlphaMul;
            case 508:           return FSI_Vulkan_SPIRV_FYUVCxform;
            case 509:           return FSI_Vulkan_SPIRV_FYUVCxformMul;
            case 510:           return FSI_Vulkan_SPIRV_FYUVCxformEAlpha;
            case 511:           return FSI_Vulkan_SPIRV_FYUVCxformEAlphaMul;
            case 512:           return FSI_Vulkan_SPIRV_FYUVCxformAc;
            case 513:           return FSI_Vulkan_SPIRV_FYUVCxformAcMul;
            case 514:           return FSI_Vulkan_SPIRV_FYUVCxformAcEAlpha;
            case 515:           return FSI_Vulkan_SPIRV_FYUVCxformAcEAlphaMul;
            case 516:           return FSI_Vulkan_SPIRV_FYUVA;
            case 517:           return FSI_Vulkan_SPIRV_FYUVAMul;
            case 518:           return FSI_Vulkan_SPIRV_FYUVAInv;
            case 519:           return FSI_Vulkan_SPIRV_FYUVAEAlpha;
            case 520:           return FSI_Vulkan_SPIRV_FYUVAEAlphaMul;
            case 521:           return FSI_Vulkan_SPIRV_FYUVAEAlphaInv;
            case 522:           return FSI_Vulkan_SPIRV_FYUVACxform;
            case 523:           return FSI_Vulkan_SPIRV_FYUVACxformMul;
            case 524:           return FSI_Vulkan_SPIRV_FYUVACxformInv;
            case 525:           return FSI_Vulkan_SPIRV_FYUVACxformEAlpha;
            case 526:           return FSI_Vulkan_SPIRV_FYUVACxformEAlphaMul;
            case 527:           return FSI_Vulkan_SPIRV_FYUVACxformEAlphaInv;
            case 528:           return FSI_Vulkan_SPIRV_FYUVACxformAc;
            case 529:           return FSI_Vulkan_SPIRV_FYUVACxformAcMul;
            case 530:           return FSI_Vulkan_SPIRV_FYUVACxformAcInv;
            case 531:           return FSI_Vulkan_SPIRV_FYUVACxformAcEAlpha;
            case 532:           return FSI_Vulkan_SPIRV_FYUVACxformAcEAlphaMul;
            case 533:           return FSI_Vulkan_SPIRV_FYUVACxformAcEAlphaInv;
            case 534:           return FSI_Vulkan_SPIRV_FPosition3dYUV;
            case 535:           return FSI_Vulkan_SPIRV_FPosition3dYUVMul;
            case 536:           return FSI_Vulkan_SPIRV_FPosition3dYUVEAlpha;
            case 537:           return FSI_Vulkan_SPIRV_FPosition3dYUVEAlphaMul;
            case 538:           return FSI_Vulkan_SPIRV_FPosition3dYUVCxform;
            case 539:           return FSI_Vulkan_SPIRV_FPosition3dYUVCxformMul;
            case 540:           return FSI_Vulkan_SPIRV_FPosition3dYUVCxformEAlpha;
            case 541:           return FSI_Vulkan_SPIRV_FPosition3dYUVCxformEAlphaMul;
            case 542:           return FSI_Vulkan_SPIRV_FPosition3dYUVCxformAc;
            case 543:           return FSI_Vulkan_SPIRV_FPosition3dYUVCxformAcMul;
            case 544:           return FSI_Vulkan_SPIRV_FPosition3dYUVCxformAcEAlpha;
            case 545:           return FSI_Vulkan_SPIRV_FPosition3dYUVCxformAcEAlphaMul;
            case 546:           return FSI_Vulkan_SPIRV_FPosition3dYUVA;
            case 547:           return FSI_Vulkan_SPIRV_FPosition3dYUVAMul;
            case 548:           return FSI_Vulkan_SPIRV_FPosition3dYUVAInv;
            case 549:           return FSI_Vulkan_SPIRV_FPosition3dYUVAEAlpha;
            case 550:           return FSI_Vulkan_SPIRV_FPosition3dYUVAEAlphaMul;
            case 551:           return FSI_Vulkan_SPIRV_FPosition3dYUVAEAlphaInv;
            case 552:           return FSI_Vulkan_SPIRV_FPosition3dYUVACxform;
            case 553:           return FSI_Vulkan_SPIRV_FPosition3dYUVACxformMul;
            case 554:           return FSI_Vulkan_SPIRV_FPosition3dYUVACxformInv;
            case 555:           return FSI_Vulkan_SPIRV_FPosition3dYUVACxformEAlpha;
            case 556:           return FSI_Vulkan_SPIRV_FPosition3dYUVACxformEAlphaMul;
            case 557:           return FSI_Vulkan_SPIRV_FPosition3dYUVACxformEAlphaInv;
            case 558:           return FSI_Vulkan_SPIRV_FPosition3dYUVACxformAc;
            case 559:           return FSI_Vulkan_SPIRV_FPosition3dYUVACxformAcMul;
            case 560:           return FSI_Vulkan_SPIRV_FPosition3dYUVACxformAcInv;
            case 561:           return FSI_Vulkan_SPIRV_FPosition3dYUVACxformAcEAlpha;
            case 562:           return FSI_Vulkan_SPIRV_FPosition3dYUVACxformAcEAlphaMul;
            case 563:           return FSI_Vulkan_SPIRV_FPosition3dYUVACxformAcEAlphaInv;
            case 564:           return FSI_Vulkan_SPIRV_FBatchYUV;
            case 565:           return FSI_Vulkan_SPIRV_FBatchYUVMul;
            case 566:           return FSI_Vulkan_SPIRV_FBatchYUVEAlpha;
            case 567:           return FSI_Vulkan_SPIRV_FBatchYUVEAlphaMul;
            case 568:           return FSI_Vulkan_SPIRV_FBatchYUVCxform;
            case 569:           return FSI_Vulkan_SPIRV_FBatchYUVCxformMul;
            case 570:           return FSI_Vulkan_SPIRV_FBatchYUVCxformEAlpha;
            case 571:           return FSI_Vulkan_SPIRV_FBatchYUVCxformEAlphaMul;
            case 572:           return FSI_Vulkan_SPIRV_FBatchYUVCxformAc;
            case 573:           return FSI_Vulkan_SPIRV_FBatchYUVCxformAcMul;
            case 574:           return FSI_Vulkan_SPIRV_FBatchYUVCxformAcEAlpha;
            case 575:           return FSI_Vulkan_SPIRV_FBatchYUVCxformAcEAlphaMul;
            case 576:           return FSI_Vulkan_SPIRV_FBatchYUVA;
            case 577:           return FSI_Vulkan_SPIRV_FBatchYUVAMul;
            case 578:           return FSI_Vulkan_SPIRV_FBatchYUVAInv;
            case 579:           return FSI_Vulkan_SPIRV_FBatchYUVAEAlpha;
            case 580:           return FSI_Vulkan_SPIRV_FBatchYUVAEAlphaMul;
            case 581:           return FSI_Vulkan_SPIRV_FBatchYUVAEAlphaInv;
            case 582:           return FSI_Vulkan_SPIRV_FBatchYUVACxform;
            case 583:           return FSI_Vulkan_SPIRV_FBatchYUVACxformMul;
            case 584:           return FSI_Vulkan_SPIRV_FBatchYUVACxformInv;
            case 585:           return FSI_Vulkan_SPIRV_FBatchYUVACxformEAlpha;
            case 586:           return FSI_Vulkan_SPIRV_FBatchYUVACxformEAlphaMul;
            case 587:           return FSI_Vulkan_SPIRV_FBatchYUVACxformEAlphaInv;
            case 588:           return FSI_Vulkan_SPIRV_FBatchYUVACxformAc;
            case 589:           return FSI_Vulkan_SPIRV_FBatchYUVACxformAcMul;
            case 590:           return FSI_Vulkan_SPIRV_FBatchYUVACxformAcInv;
            case 591:           return FSI_Vulkan_SPIRV_FBatchYUVACxformAcEAlpha;
            case 592:           return FSI_Vulkan_SPIRV_FBatchYUVACxformAcEAlphaMul;
            case 593:           return FSI_Vulkan_SPIRV_FBatchYUVACxformAcEAlphaInv;
            case 594:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUV;
            case 595:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVMul;
            case 596:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVEAlpha;
            case 597:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVEAlphaMul;
            case 598:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVCxform;
            case 599:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVCxformMul;
            case 600:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVCxformEAlpha;
            case 601:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVCxformEAlphaMul;
            case 602:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVCxformAc;
            case 603:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVCxformAcMul;
            case 604:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVCxformAcEAlpha;
            case 605:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVCxformAcEAlphaMul;
            case 606:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVA;
            case 607:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVAMul;
            case 608:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVAInv;
            case 609:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVAEAlpha;
            case 610:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVAEAlphaMul;
            case 611:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVAEAlphaInv;
            case 612:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxform;
            case 613:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxformMul;
            case 614:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxformInv;
            case 615:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxformEAlpha;
            case 616:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxformEAlphaMul;
            case 617:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxformEAlphaInv;
            case 618:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxformAc;
            case 619:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxformAcMul;
            case 620:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxformAcInv;
            case 621:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxformAcEAlpha;
            case 622:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxformAcEAlphaMul;
            case 623:           return FSI_Vulkan_SPIRV_FBatchPosition3dYUVACxformAcEAlphaInv;
            case 624:           return FSI_Vulkan_SPIRV_FInstancedYUV;
            case 625:           return FSI_Vulkan_SPIRV_FInstancedYUVMul;
            case 626:           return FSI_Vulkan_SPIRV_FInstancedYUVEAlpha;
            case 627:           return FSI_Vulkan_SPIRV_FInstancedYUVEAlphaMul;
            case 628:           return FSI_Vulkan_SPIRV_FInstancedYUVCxform;
            case 629:           return FSI_Vulkan_SPIRV_FInstancedYUVCxformMul;
            case 630:           return FSI_Vulkan_SPIRV_FInstancedYUVCxformEAlpha;
            case 631:           return FSI_Vulkan_SPIRV_FInstancedYUVCxformEAlphaMul;
            case 632:           return FSI_Vulkan_SPIRV_FInstancedYUVCxformAc;
            case 633:           return FSI_Vulkan_SPIRV_FInstancedYUVCxformAcMul;
            case 634:           return FSI_Vulkan_SPIRV_FInstancedYUVCxformAcEAlpha;
            case 635:           return FSI_Vulkan_SPIRV_FInstancedYUVCxformAcEAlphaMul;
            case 636:           return FSI_Vulkan_SPIRV_FInstancedYUVA;
            case 637:           return FSI_Vulkan_SPIRV_FInstancedYUVAMul;
            case 638:           return FSI_Vulkan_SPIRV_FInstancedYUVAInv;
            case 639:           return FSI_Vulkan_SPIRV_FInstancedYUVAEAlpha;
            case 640:           return FSI_Vulkan_SPIRV_FInstancedYUVAEAlphaMul;
            case 641:           return FSI_Vulkan_SPIRV_FInstancedYUVAEAlphaInv;
            case 642:           return FSI_Vulkan_SPIRV_FInstancedYUVACxform;
            case 643:           return FSI_Vulkan_SPIRV_FInstancedYUVACxformMul;
            case 644:           return FSI_Vulkan_SPIRV_FInstancedYUVACxformInv;
            case 645:           return FSI_Vulkan_SPIRV_FInstancedYUVACxformEAlpha;
            case 646:           return FSI_Vulkan_SPIRV_FInstancedYUVACxformEAlphaMul;
            case 647:           return FSI_Vulkan_SPIRV_FInstancedYUVACxformEAlphaInv;
            case 648:           return FSI_Vulkan_SPIRV_FInstancedYUVACxformAc;
            case 649:           return FSI_Vulkan_SPIRV_FInstancedYUVACxformAcMul;
            case 650:           return FSI_Vulkan_SPIRV_FInstancedYUVACxformAcInv;
            case 651:           return FSI_Vulkan_SPIRV_FInstancedYUVACxformAcEAlpha;
            case 652:           return FSI_Vulkan_SPIRV_FInstancedYUVACxformAcEAlphaMul;
            case 653:           return FSI_Vulkan_SPIRV_FInstancedYUVACxformAcEAlphaInv;
            case 654:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUV;
            case 655:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVMul;
            case 656:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVEAlpha;
            case 657:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVEAlphaMul;
            case 658:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVCxform;
            case 659:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVCxformMul;
            case 660:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVCxformEAlpha;
            case 661:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVCxformEAlphaMul;
            case 662:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVCxformAc;
            case 663:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVCxformAcMul;
            case 664:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVCxformAcEAlpha;
            case 665:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVCxformAcEAlphaMul;
            case 666:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVA;
            case 667:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVAMul;
            case 668:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVAInv;
            case 669:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVAEAlpha;
            case 670:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVAEAlphaMul;
            case 671:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVAEAlphaInv;
            case 672:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxform;
            case 673:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxformMul;
            case 674:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxformInv;
            case 675:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxformEAlpha;
            case 676:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxformEAlphaMul;
            case 677:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxformEAlphaInv;
            case 678:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxformAc;
            case 679:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxformAcMul;
            case 680:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxformAcInv;
            case 681:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxformAcEAlpha;
            case 682:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxformAcEAlphaMul;
            case 683:           return FSI_Vulkan_SPIRV_FInstancedPosition3dYUVACxformAcEAlphaInv;
            case 684:           return FSI_Vulkan_SPIRV_FTexTGCMatrixAc;
            case 685:           return FSI_Vulkan_SPIRV_FTexTGCMatrixAcMul;
            case 686:           return FSI_Vulkan_SPIRV_FTexTGCMatrixAcEAlpha;
            case 687:           return FSI_Vulkan_SPIRV_FTexTGCMatrixAcEAlphaMul;
            case 688:           return FSI_Vulkan_SPIRV_FBox1Blur;
            case 689:           return FSI_Vulkan_SPIRV_FBox1BlurMul;
            case 690:           return FSI_Vulkan_SPIRV_FBox2Blur;
            case 691:           return FSI_Vulkan_SPIRV_FBox2BlurMul;
            case 692:           return FSI_Vulkan_SPIRV_FBox2Shadow;
            case 693:           return FSI_Vulkan_SPIRV_FBox2ShadowMul;
            case 694:           return FSI_Vulkan_SPIRV_FBox2ShadowKnockout;
            case 695:           return FSI_Vulkan_SPIRV_FBox2ShadowKnockoutMul;
            case 696:           return FSI_Vulkan_SPIRV_FBox2InnerShadow;
            case 697:           return FSI_Vulkan_SPIRV_FBox2InnerShadowMul;
            case 698:           return FSI_Vulkan_SPIRV_FBox2InnerShadowKnockout;
            case 699:           return FSI_Vulkan_SPIRV_FBox2InnerShadowKnockoutMul;
            case 700:           return FSI_Vulkan_SPIRV_FBox2Shadowonly;
            case 701:           return FSI_Vulkan_SPIRV_FBox2ShadowonlyMul;
            case 702:           return FSI_Vulkan_SPIRV_FBox2ShadowHighlight;
            case 703:           return FSI_Vulkan_SPIRV_FBox2ShadowHighlightMul;
            case 704:           return FSI_Vulkan_SPIRV_FBox2ShadowHighlightKnockout;
            case 705:           return FSI_Vulkan_SPIRV_FBox2ShadowHighlightKnockoutMul;
            case 706:           return FSI_Vulkan_SPIRV_FBox2InnerShadowHighlight;
            case 707:           return FSI_Vulkan_SPIRV_FBox2InnerShadowHighlightMul;
            case 708:           return FSI_Vulkan_SPIRV_FBox2InnerShadowHighlightKnockout;
            case 709:           return FSI_Vulkan_SPIRV_FBox2InnerShadowHighlightKnockoutMul;
            case 710:           return FSI_Vulkan_SPIRV_FBox2FullShadowHighlight;
            case 711:           return FSI_Vulkan_SPIRV_FBox2FullShadowHighlightMul;
            case 712:           return FSI_Vulkan_SPIRV_FBox2ShadowonlyHighlight;
            case 713:           return FSI_Vulkan_SPIRV_FBox2ShadowonlyHighlightMul;
            case 714:           return FSI_Vulkan_SPIRV_FDrawableCopyPixels;
            case 715:           return FSI_Vulkan_SPIRV_FDrawableCopyPixelsMergeAlpha;
            case 716:           return FSI_Vulkan_SPIRV_FDrawableCopyPixelsNoDestAlpha;
            case 717:           return FSI_Vulkan_SPIRV_FDrawableCopyPixelsAlpha;
            case 718:           return FSI_Vulkan_SPIRV_FDrawableCopyPixelsAlphaMergeAlpha;
            case 719:           return FSI_Vulkan_SPIRV_FDrawableCopyPixelsAlphaNoDestAlpha;
            case 720:           return FSI_Vulkan_SPIRV_FDrawableMerge;
            case 721:           return FSI_Vulkan_SPIRV_FDrawableCompare;
            case 722:           return FSI_Vulkan_SPIRV_FDrawablePaletteMap;
            default: SF_ASSERT(0); return FSI_None;
        }
        default: SF_ASSERT(0); return FSI_None;
    }
}

unsigned FragShaderDesc::GetShaderComboIndex(ShaderDesc::ShaderType shader, ShaderDesc::ShaderVersion ver)
{
    switch(ver)
    {
        case ShaderDesc::ShaderVersion_Vulkan_SPIRV:
        switch(shader)
        {
            case ShaderDesc::ST_TexTG:                                       return 0;
            case ShaderDesc::ST_TexTGMul:                                    return 1;
            case ShaderDesc::ST_BatchTexTG:                                  return 144;
            case ShaderDesc::ST_BatchTexTGMul:                               return 145;
            case ShaderDesc::ST_InstancedTexTG:                              return 288;
            case ShaderDesc::ST_InstancedTexTGMul:                           return 289;
            case ShaderDesc::ST_Position3dTexTG:                             return 72;
            case ShaderDesc::ST_Position3dTexTGMul:                          return 73;
            case ShaderDesc::ST_BatchPosition3dTexTG:                        return 216;
            case ShaderDesc::ST_BatchPosition3dTexTGMul:                     return 217;
            case ShaderDesc::ST_InstancedPosition3dTexTG:                    return 360;
            case ShaderDesc::ST_InstancedPosition3dTexTGMul:                 return 361;
            case ShaderDesc::ST_TexTGCxform:                                 return 6;
            case ShaderDesc::ST_TexTGCxformMul:                              return 7;
            case ShaderDesc::ST_BatchTexTGCxform:                            return 150;
            case ShaderDesc::ST_BatchTexTGCxformMul:                         return 151;
            case ShaderDesc::ST_InstancedTexTGCxform:                        return 294;
            case ShaderDesc::ST_InstancedTexTGCxformMul:                     return 295;
            case ShaderDesc::ST_Position3dTexTGCxform:                       return 78;
            case ShaderDesc::ST_Position3dTexTGCxformMul:                    return 79;
            case ShaderDesc::ST_BatchPosition3dTexTGCxform:                  return 222;
            case ShaderDesc::ST_BatchPosition3dTexTGCxformMul:               return 223;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxform:              return 366;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxformMul:           return 367;
            case ShaderDesc::ST_TexTGEAlpha:                                 return 3;
            case ShaderDesc::ST_TexTGEAlphaMul:                              return 4;
            case ShaderDesc::ST_BatchTexTGEAlpha:                            return 147;
            case ShaderDesc::ST_BatchTexTGEAlphaMul:                         return 148;
            case ShaderDesc::ST_InstancedTexTGEAlpha:                        return 291;
            case ShaderDesc::ST_InstancedTexTGEAlphaMul:                     return 292;
            case ShaderDesc::ST_Position3dTexTGEAlpha:                       return 75;
            case ShaderDesc::ST_Position3dTexTGEAlphaMul:                    return 76;
            case ShaderDesc::ST_BatchPosition3dTexTGEAlpha:                  return 219;
            case ShaderDesc::ST_BatchPosition3dTexTGEAlphaMul:               return 220;
            case ShaderDesc::ST_InstancedPosition3dTexTGEAlpha:              return 363;
            case ShaderDesc::ST_InstancedPosition3dTexTGEAlphaMul:           return 364;
            case ShaderDesc::ST_TexTGCxformEAlpha:                           return 9;
            case ShaderDesc::ST_TexTGCxformEAlphaMul:                        return 10;
            case ShaderDesc::ST_BatchTexTGCxformEAlpha:                      return 153;
            case ShaderDesc::ST_BatchTexTGCxformEAlphaMul:                   return 154;
            case ShaderDesc::ST_InstancedTexTGCxformEAlpha:                  return 297;
            case ShaderDesc::ST_InstancedTexTGCxformEAlphaMul:               return 298;
            case ShaderDesc::ST_Position3dTexTGCxformEAlpha:                 return 81;
            case ShaderDesc::ST_Position3dTexTGCxformEAlphaMul:              return 82;
            case ShaderDesc::ST_BatchPosition3dTexTGCxformEAlpha:            return 225;
            case ShaderDesc::ST_BatchPosition3dTexTGCxformEAlphaMul:         return 226;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxformEAlpha:        return 369;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxformEAlphaMul:     return 370;
            case ShaderDesc::ST_TexTGInv:                                    return 2;
            case ShaderDesc::ST_BatchTexTGInv:                               return 146;
            case ShaderDesc::ST_InstancedTexTGInv:                           return 290;
            case ShaderDesc::ST_Position3dTexTGInv:                          return 74;
            case ShaderDesc::ST_BatchPosition3dTexTGInv:                     return 218;
            case ShaderDesc::ST_InstancedPosition3dTexTGInv:                 return 362;
            case ShaderDesc::ST_TexTGCxformInv:                              return 8;
            case ShaderDesc::ST_BatchTexTGCxformInv:                         return 152;
            case ShaderDesc::ST_InstancedTexTGCxformInv:                     return 296;
            case ShaderDesc::ST_Position3dTexTGCxformInv:                    return 80;
            case ShaderDesc::ST_BatchPosition3dTexTGCxformInv:               return 224;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxformInv:           return 368;
            case ShaderDesc::ST_TexTGEAlphaInv:                              return 5;
            case ShaderDesc::ST_BatchTexTGEAlphaInv:                         return 149;
            case ShaderDesc::ST_InstancedTexTGEAlphaInv:                     return 293;
            case ShaderDesc::ST_Position3dTexTGEAlphaInv:                    return 77;
            case ShaderDesc::ST_BatchPosition3dTexTGEAlphaInv:               return 221;
            case ShaderDesc::ST_InstancedPosition3dTexTGEAlphaInv:           return 365;
            case ShaderDesc::ST_TexTGCxformEAlphaInv:                        return 11;
            case ShaderDesc::ST_BatchTexTGCxformEAlphaInv:                   return 155;
            case ShaderDesc::ST_InstancedTexTGCxformEAlphaInv:               return 299;
            case ShaderDesc::ST_Position3dTexTGCxformEAlphaInv:              return 83;
            case ShaderDesc::ST_BatchPosition3dTexTGCxformEAlphaInv:         return 227;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxformEAlphaInv:     return 371;
            case ShaderDesc::ST_TexTGCxformAc:                               return 12;
            case ShaderDesc::ST_TexTGCxformAcMul:                            return 13;
            case ShaderDesc::ST_BatchTexTGCxformAc:                          return 156;
            case ShaderDesc::ST_BatchTexTGCxformAcMul:                       return 157;
            case ShaderDesc::ST_InstancedTexTGCxformAc:                      return 300;
            case ShaderDesc::ST_InstancedTexTGCxformAcMul:                   return 301;
            case ShaderDesc::ST_Position3dTexTGCxformAc:                     return 84;
            case ShaderDesc::ST_Position3dTexTGCxformAcMul:                  return 85;
            case ShaderDesc::ST_BatchPosition3dTexTGCxformAc:                return 228;
            case ShaderDesc::ST_BatchPosition3dTexTGCxformAcMul:             return 229;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxformAc:            return 372;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxformAcMul:         return 373;
            case ShaderDesc::ST_TexTGCxformAcEAlpha:                         return 15;
            case ShaderDesc::ST_TexTGCxformAcEAlphaMul:                      return 16;
            case ShaderDesc::ST_BatchTexTGCxformAcEAlpha:                    return 159;
            case ShaderDesc::ST_BatchTexTGCxformAcEAlphaMul:                 return 160;
            case ShaderDesc::ST_InstancedTexTGCxformAcEAlpha:                return 303;
            case ShaderDesc::ST_InstancedTexTGCxformAcEAlphaMul:             return 304;
            case ShaderDesc::ST_Position3dTexTGCxformAcEAlpha:               return 87;
            case ShaderDesc::ST_Position3dTexTGCxformAcEAlphaMul:            return 88;
            case ShaderDesc::ST_BatchPosition3dTexTGCxformAcEAlpha:          return 231;
            case ShaderDesc::ST_BatchPosition3dTexTGCxformAcEAlphaMul:       return 232;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxformAcEAlpha:      return 375;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxformAcEAlphaMul:   return 376;
            case ShaderDesc::ST_TexTGCxformAcInv:                            return 14;
            case ShaderDesc::ST_BatchTexTGCxformAcInv:                       return 158;
            case ShaderDesc::ST_InstancedTexTGCxformAcInv:                   return 302;
            case ShaderDesc::ST_Position3dTexTGCxformAcInv:                  return 86;
            case ShaderDesc::ST_BatchPosition3dTexTGCxformAcInv:             return 230;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxformAcInv:         return 374;
            case ShaderDesc::ST_TexTGCxformAcEAlphaInv:                      return 17;
            case ShaderDesc::ST_BatchTexTGCxformAcEAlphaInv:                 return 161;
            case ShaderDesc::ST_InstancedTexTGCxformAcEAlphaInv:             return 305;
            case ShaderDesc::ST_Position3dTexTGCxformAcEAlphaInv:            return 89;
            case ShaderDesc::ST_BatchPosition3dTexTGCxformAcEAlphaInv:       return 233;
            case ShaderDesc::ST_InstancedPosition3dTexTGCxformAcEAlphaInv:   return 377;
            case ShaderDesc::ST_Vertex:                                      return 18;
            case ShaderDesc::ST_VertexMul:                                   return 19;
            case ShaderDesc::ST_BatchVertex:                                 return 162;
            case ShaderDesc::ST_BatchVertexMul:                              return 163;
            case ShaderDesc::ST_InstancedVertex:                             return 306;
            case ShaderDesc::ST_InstancedVertexMul:                          return 307;
            case ShaderDesc::ST_Position3dVertex:                            return 90;
            case ShaderDesc::ST_Position3dVertexMul:                         return 91;
            case ShaderDesc::ST_BatchPosition3dVertex:                       return 234;
            case ShaderDesc::ST_BatchPosition3dVertexMul:                    return 235;
            case ShaderDesc::ST_InstancedPosition3dVertex:                   return 378;
            case ShaderDesc::ST_InstancedPosition3dVertexMul:                return 379;
            case ShaderDesc::ST_VertexCxform:                                return 24;
            case ShaderDesc::ST_VertexCxformMul:                             return 25;
            case ShaderDesc::ST_BatchVertexCxform:                           return 168;
            case ShaderDesc::ST_BatchVertexCxformMul:                        return 169;
            case ShaderDesc::ST_InstancedVertexCxform:                       return 312;
            case ShaderDesc::ST_InstancedVertexCxformMul:                    return 313;
            case ShaderDesc::ST_Position3dVertexCxform:                      return 96;
            case ShaderDesc::ST_Position3dVertexCxformMul:                   return 97;
            case ShaderDesc::ST_BatchPosition3dVertexCxform:                 return 240;
            case ShaderDesc::ST_BatchPosition3dVertexCxformMul:              return 241;
            case ShaderDesc::ST_InstancedPosition3dVertexCxform:             return 384;
            case ShaderDesc::ST_InstancedPosition3dVertexCxformMul:          return 385;
            case ShaderDesc::ST_VertexEAlpha:                                return 21;
            case ShaderDesc::ST_VertexEAlphaMul:                             return 22;
            case ShaderDesc::ST_BatchVertexEAlpha:                           return 165;
            case ShaderDesc::ST_BatchVertexEAlphaMul:                        return 166;
            case ShaderDesc::ST_InstancedVertexEAlpha:                       return 309;
            case ShaderDesc::ST_InstancedVertexEAlphaMul:                    return 310;
            case ShaderDesc::ST_Position3dVertexEAlpha:                      return 93;
            case ShaderDesc::ST_Position3dVertexEAlphaMul:                   return 94;
            case ShaderDesc::ST_BatchPosition3dVertexEAlpha:                 return 237;
            case ShaderDesc::ST_BatchPosition3dVertexEAlphaMul:              return 238;
            case ShaderDesc::ST_InstancedPosition3dVertexEAlpha:             return 381;
            case ShaderDesc::ST_InstancedPosition3dVertexEAlphaMul:          return 382;
            case ShaderDesc::ST_VertexCxformEAlpha:                          return 27;
            case ShaderDesc::ST_VertexCxformEAlphaMul:                       return 28;
            case ShaderDesc::ST_BatchVertexCxformEAlpha:                     return 171;
            case ShaderDesc::ST_BatchVertexCxformEAlphaMul:                  return 172;
            case ShaderDesc::ST_InstancedVertexCxformEAlpha:                 return 315;
            case ShaderDesc::ST_InstancedVertexCxformEAlphaMul:              return 316;
            case ShaderDesc::ST_Position3dVertexCxformEAlpha:                return 99;
            case ShaderDesc::ST_Position3dVertexCxformEAlphaMul:             return 100;
            case ShaderDesc::ST_BatchPosition3dVertexCxformEAlpha:           return 243;
            case ShaderDesc::ST_BatchPosition3dVertexCxformEAlphaMul:        return 244;
            case ShaderDesc::ST_InstancedPosition3dVertexCxformEAlpha:       return 387;
            case ShaderDesc::ST_InstancedPosition3dVertexCxformEAlphaMul:    return 388;
            case ShaderDesc::ST_VertexInv:                                   return 20;
            case ShaderDesc::ST_BatchVertexInv:                              return 164;
            case ShaderDesc::ST_InstancedVertexInv:                          return 308;
            case ShaderDesc::ST_Position3dVertexInv:                         return 92;
            case ShaderDesc::ST_BatchPosition3dVertexInv:                    return 236;
            case ShaderDesc::ST_InstancedPosition3dVertexInv:                return 380;
            case ShaderDesc::ST_VertexCxformInv:                             return 26;
            case ShaderDesc::ST_BatchVertexCxformInv:                        return 170;
            case ShaderDesc::ST_InstancedVertexCxformInv:                    return 314;
            case ShaderDesc::ST_Position3dVertexCxformInv:                   return 98;
            case ShaderDesc::ST_BatchPosition3dVertexCxformInv:              return 242;
            case ShaderDesc::ST_InstancedPosition3dVertexCxformInv:          return 386;
            case ShaderDesc::ST_VertexEAlphaInv:                             return 23;
            case ShaderDesc::ST_BatchVertexEAlphaInv:                        return 167;
            case ShaderDesc::ST_InstancedVertexEAlphaInv:                    return 311;
            case ShaderDesc::ST_Position3dVertexEAlphaInv:                   return 95;
            case ShaderDesc::ST_BatchPosition3dVertexEAlphaInv:              return 239;
            case ShaderDesc::ST_InstancedPosition3dVertexEAlphaInv:          return 383;
            case ShaderDesc::ST_VertexCxformEAlphaInv:                       return 29;
            case ShaderDesc::ST_BatchVertexCxformEAlphaInv:                  return 173;
            case ShaderDesc::ST_InstancedVertexCxformEAlphaInv:              return 317;
            case ShaderDesc::ST_Position3dVertexCxformEAlphaInv:             return 101;
            case ShaderDesc::ST_BatchPosition3dVertexCxformEAlphaInv:        return 245;
            case ShaderDesc::ST_InstancedPosition3dVertexCxformEAlphaInv:    return 389;
            case ShaderDesc::ST_VertexCxformAc:                              return 30;
            case ShaderDesc::ST_VertexCxformAcMul:                           return 31;
            case ShaderDesc::ST_BatchVertexCxformAc:                         return 174;
            case ShaderDesc::ST_BatchVertexCxformAcMul:                      return 175;
            case ShaderDesc::ST_InstancedVertexCxformAc:                     return 318;
            case ShaderDesc::ST_InstancedVertexCxformAcMul:                  return 319;
            case ShaderDesc::ST_Position3dVertexCxformAc:                    return 102;
            case ShaderDesc::ST_Position3dVertexCxformAcMul:                 return 103;
            case ShaderDesc::ST_BatchPosition3dVertexCxformAc:               return 246;
            case ShaderDesc::ST_BatchPosition3dVertexCxformAcMul:            return 247;
            case ShaderDesc::ST_InstancedPosition3dVertexCxformAc:           return 390;
            case ShaderDesc::ST_InstancedPosition3dVertexCxformAcMul:        return 391;
            case ShaderDesc::ST_VertexCxformAcEAlpha:                        return 33;
            case ShaderDesc::ST_VertexCxformAcEAlphaMul:                     return 34;
            case ShaderDesc::ST_BatchVertexCxformAcEAlpha:                   return 177;
            case ShaderDesc::ST_BatchVertexCxformAcEAlphaMul:                return 178;
            case ShaderDesc::ST_InstancedVertexCxformAcEAlpha:               return 321;
            case ShaderDesc::ST_InstancedVertexCxformAcEAlphaMul:            return 322;
            case ShaderDesc::ST_Position3dVertexCxformAcEAlpha:              return 105;
            case ShaderDesc::ST_Position3dVertexCxformAcEAlphaMul:           return 106;
            case ShaderDesc::ST_BatchPosition3dVertexCxformAcEAlpha:         return 249;
            case ShaderDesc::ST_BatchPosition3dVertexCxformAcEAlphaMul:      return 250;
            case ShaderDesc::ST_InstancedPosition3dVertexCxformAcEAlpha:     return 393;
            case ShaderDesc::ST_InstancedPosition3dVertexCxformAcEAlphaMul:  return 394;
            case ShaderDesc::ST_VertexCxformAcInv:                           return 32;
            case ShaderDesc::ST_BatchVertexCxformAcInv:                      return 176;
            case ShaderDesc::ST_InstancedVertexCxformAcInv:                  return 320;
            case ShaderDesc::ST_Position3dVertexCxformAcInv:                 return 104;
            case ShaderDesc::ST_BatchPosition3dVertexCxformAcInv:            return 248;
            case ShaderDesc::ST_InstancedPosition3dVertexCxformAcInv:        return 392;
            case ShaderDesc::ST_VertexCxformAcEAlphaInv:                     return 35;
            case ShaderDesc::ST_BatchVertexCxformAcEAlphaInv:                return 179;
            case ShaderDesc::ST_InstancedVertexCxformAcEAlphaInv:            return 323;
            case ShaderDesc::ST_Position3dVertexCxformAcEAlphaInv:           return 107;
            case ShaderDesc::ST_BatchPosition3dVertexCxformAcEAlphaInv:      return 251;
            case ShaderDesc::ST_InstancedPosition3dVertexCxformAcEAlphaInv:  return 395;
            case ShaderDesc::ST_TexTGTexTG:                                  return 36;
            case ShaderDesc::ST_TexTGTexTGMul:                               return 37;
            case ShaderDesc::ST_BatchTexTGTexTG:                             return 180;
            case ShaderDesc::ST_BatchTexTGTexTGMul:                          return 181;
            case ShaderDesc::ST_InstancedTexTGTexTG:                         return 324;
            case ShaderDesc::ST_InstancedTexTGTexTGMul:                      return 325;
            case ShaderDesc::ST_Position3dTexTGTexTG:                        return 108;
            case ShaderDesc::ST_Position3dTexTGTexTGMul:                     return 109;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTG:                   return 252;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGMul:                return 253;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTG:               return 396;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGMul:            return 397;
            case ShaderDesc::ST_TexTGTexTGCxform:                            return 42;
            case ShaderDesc::ST_TexTGTexTGCxformMul:                         return 43;
            case ShaderDesc::ST_BatchTexTGTexTGCxform:                       return 186;
            case ShaderDesc::ST_BatchTexTGTexTGCxformMul:                    return 187;
            case ShaderDesc::ST_InstancedTexTGTexTGCxform:                   return 330;
            case ShaderDesc::ST_InstancedTexTGTexTGCxformMul:                return 331;
            case ShaderDesc::ST_Position3dTexTGTexTGCxform:                  return 114;
            case ShaderDesc::ST_Position3dTexTGTexTGCxformMul:               return 115;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxform:             return 258;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxformMul:          return 259;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxform:         return 402;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxformMul:      return 403;
            case ShaderDesc::ST_TexTGTexTGEAlpha:                            return 39;
            case ShaderDesc::ST_TexTGTexTGEAlphaMul:                         return 40;
            case ShaderDesc::ST_BatchTexTGTexTGEAlpha:                       return 183;
            case ShaderDesc::ST_BatchTexTGTexTGEAlphaMul:                    return 184;
            case ShaderDesc::ST_InstancedTexTGTexTGEAlpha:                   return 327;
            case ShaderDesc::ST_InstancedTexTGTexTGEAlphaMul:                return 328;
            case ShaderDesc::ST_Position3dTexTGTexTGEAlpha:                  return 111;
            case ShaderDesc::ST_Position3dTexTGTexTGEAlphaMul:               return 112;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGEAlpha:             return 255;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGEAlphaMul:          return 256;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGEAlpha:         return 399;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGEAlphaMul:      return 400;
            case ShaderDesc::ST_TexTGTexTGCxformEAlpha:                      return 45;
            case ShaderDesc::ST_TexTGTexTGCxformEAlphaMul:                   return 46;
            case ShaderDesc::ST_BatchTexTGTexTGCxformEAlpha:                 return 189;
            case ShaderDesc::ST_BatchTexTGTexTGCxformEAlphaMul:              return 190;
            case ShaderDesc::ST_InstancedTexTGTexTGCxformEAlpha:             return 333;
            case ShaderDesc::ST_InstancedTexTGTexTGCxformEAlphaMul:          return 334;
            case ShaderDesc::ST_Position3dTexTGTexTGCxformEAlpha:            return 117;
            case ShaderDesc::ST_Position3dTexTGTexTGCxformEAlphaMul:         return 118;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxformEAlpha:       return 261;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxformEAlphaMul:    return 262;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxformEAlpha:   return 405;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxformEAlphaMul: return 406;
            case ShaderDesc::ST_TexTGTexTGInv:                               return 38;
            case ShaderDesc::ST_BatchTexTGTexTGInv:                          return 182;
            case ShaderDesc::ST_InstancedTexTGTexTGInv:                      return 326;
            case ShaderDesc::ST_Position3dTexTGTexTGInv:                     return 110;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGInv:                return 254;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGInv:            return 398;
            case ShaderDesc::ST_TexTGTexTGCxformInv:                         return 44;
            case ShaderDesc::ST_BatchTexTGTexTGCxformInv:                    return 188;
            case ShaderDesc::ST_InstancedTexTGTexTGCxformInv:                return 332;
            case ShaderDesc::ST_Position3dTexTGTexTGCxformInv:               return 116;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxformInv:          return 260;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxformInv:      return 404;
            case ShaderDesc::ST_TexTGTexTGEAlphaInv:                         return 41;
            case ShaderDesc::ST_BatchTexTGTexTGEAlphaInv:                    return 185;
            case ShaderDesc::ST_InstancedTexTGTexTGEAlphaInv:                return 329;
            case ShaderDesc::ST_Position3dTexTGTexTGEAlphaInv:               return 113;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGEAlphaInv:          return 257;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGEAlphaInv:      return 401;
            case ShaderDesc::ST_TexTGTexTGCxformEAlphaInv:                   return 47;
            case ShaderDesc::ST_BatchTexTGTexTGCxformEAlphaInv:              return 191;
            case ShaderDesc::ST_InstancedTexTGTexTGCxformEAlphaInv:          return 335;
            case ShaderDesc::ST_Position3dTexTGTexTGCxformEAlphaInv:         return 119;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxformEAlphaInv:    return 263;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxformEAlphaInv: return 407;
            case ShaderDesc::ST_TexTGTexTGCxformAc:                          return 48;
            case ShaderDesc::ST_TexTGTexTGCxformAcMul:                       return 49;
            case ShaderDesc::ST_BatchTexTGTexTGCxformAc:                     return 192;
            case ShaderDesc::ST_BatchTexTGTexTGCxformAcMul:                  return 193;
            case ShaderDesc::ST_InstancedTexTGTexTGCxformAc:                 return 336;
            case ShaderDesc::ST_InstancedTexTGTexTGCxformAcMul:              return 337;
            case ShaderDesc::ST_Position3dTexTGTexTGCxformAc:                return 120;
            case ShaderDesc::ST_Position3dTexTGTexTGCxformAcMul:             return 121;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxformAc:           return 264;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxformAcMul:        return 265;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxformAc:       return 408;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxformAcMul:    return 409;
            case ShaderDesc::ST_TexTGTexTGCxformAcEAlpha:                    return 51;
            case ShaderDesc::ST_TexTGTexTGCxformAcEAlphaMul:                 return 52;
            case ShaderDesc::ST_BatchTexTGTexTGCxformAcEAlpha:               return 195;
            case ShaderDesc::ST_BatchTexTGTexTGCxformAcEAlphaMul:            return 196;
            case ShaderDesc::ST_InstancedTexTGTexTGCxformAcEAlpha:           return 339;
            case ShaderDesc::ST_InstancedTexTGTexTGCxformAcEAlphaMul:        return 340;
            case ShaderDesc::ST_Position3dTexTGTexTGCxformAcEAlpha:          return 123;
            case ShaderDesc::ST_Position3dTexTGTexTGCxformAcEAlphaMul:       return 124;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxformAcEAlpha:     return 267;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxformAcEAlphaMul:  return 268;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxformAcEAlpha: return 411;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxformAcEAlphaMul: return 412;
            case ShaderDesc::ST_TexTGTexTGCxformAcInv:                       return 50;
            case ShaderDesc::ST_BatchTexTGTexTGCxformAcInv:                  return 194;
            case ShaderDesc::ST_InstancedTexTGTexTGCxformAcInv:              return 338;
            case ShaderDesc::ST_Position3dTexTGTexTGCxformAcInv:             return 122;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxformAcInv:        return 266;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxformAcInv:    return 410;
            case ShaderDesc::ST_TexTGTexTGCxformAcEAlphaInv:                 return 53;
            case ShaderDesc::ST_BatchTexTGTexTGCxformAcEAlphaInv:            return 197;
            case ShaderDesc::ST_InstancedTexTGTexTGCxformAcEAlphaInv:        return 341;
            case ShaderDesc::ST_Position3dTexTGTexTGCxformAcEAlphaInv:       return 125;
            case ShaderDesc::ST_BatchPosition3dTexTGTexTGCxformAcEAlphaInv:  return 269;
            case ShaderDesc::ST_InstancedPosition3dTexTGTexTGCxformAcEAlphaInv: return 413;
            case ShaderDesc::ST_TexTGVertex:                                 return 54;
            case ShaderDesc::ST_TexTGVertexMul:                              return 55;
            case ShaderDesc::ST_BatchTexTGVertex:                            return 198;
            case ShaderDesc::ST_BatchTexTGVertexMul:                         return 199;
            case ShaderDesc::ST_InstancedTexTGVertex:                        return 342;
            case ShaderDesc::ST_InstancedTexTGVertexMul:                     return 343;
            case ShaderDesc::ST_Position3dTexTGVertex:                       return 126;
            case ShaderDesc::ST_Position3dTexTGVertexMul:                    return 127;
            case ShaderDesc::ST_BatchPosition3dTexTGVertex:                  return 270;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexMul:               return 271;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertex:              return 414;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexMul:           return 415;
            case ShaderDesc::ST_TexTGVertexCxform:                           return 60;
            case ShaderDesc::ST_TexTGVertexCxformMul:                        return 61;
            case ShaderDesc::ST_BatchTexTGVertexCxform:                      return 204;
            case ShaderDesc::ST_BatchTexTGVertexCxformMul:                   return 205;
            case ShaderDesc::ST_InstancedTexTGVertexCxform:                  return 348;
            case ShaderDesc::ST_InstancedTexTGVertexCxformMul:               return 349;
            case ShaderDesc::ST_Position3dTexTGVertexCxform:                 return 132;
            case ShaderDesc::ST_Position3dTexTGVertexCxformMul:              return 133;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxform:            return 276;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxformMul:         return 277;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxform:        return 420;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxformMul:     return 421;
            case ShaderDesc::ST_TexTGVertexEAlpha:                           return 57;
            case ShaderDesc::ST_TexTGVertexEAlphaMul:                        return 58;
            case ShaderDesc::ST_BatchTexTGVertexEAlpha:                      return 201;
            case ShaderDesc::ST_BatchTexTGVertexEAlphaMul:                   return 202;
            case ShaderDesc::ST_InstancedTexTGVertexEAlpha:                  return 345;
            case ShaderDesc::ST_InstancedTexTGVertexEAlphaMul:               return 346;
            case ShaderDesc::ST_Position3dTexTGVertexEAlpha:                 return 129;
            case ShaderDesc::ST_Position3dTexTGVertexEAlphaMul:              return 130;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexEAlpha:            return 273;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexEAlphaMul:         return 274;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexEAlpha:        return 417;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexEAlphaMul:     return 418;
            case ShaderDesc::ST_TexTGVertexCxformEAlpha:                     return 63;
            case ShaderDesc::ST_TexTGVertexCxformEAlphaMul:                  return 64;
            case ShaderDesc::ST_BatchTexTGVertexCxformEAlpha:                return 207;
            case ShaderDesc::ST_BatchTexTGVertexCxformEAlphaMul:             return 208;
            case ShaderDesc::ST_InstancedTexTGVertexCxformEAlpha:            return 351;
            case ShaderDesc::ST_InstancedTexTGVertexCxformEAlphaMul:         return 352;
            case ShaderDesc::ST_Position3dTexTGVertexCxformEAlpha:           return 135;
            case ShaderDesc::ST_Position3dTexTGVertexCxformEAlphaMul:        return 136;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxformEAlpha:      return 279;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxformEAlphaMul:   return 280;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxformEAlpha:  return 423;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxformEAlphaMul: return 424;
            case ShaderDesc::ST_TexTGVertexInv:                              return 56;
            case ShaderDesc::ST_BatchTexTGVertexInv:                         return 200;
            case ShaderDesc::ST_InstancedTexTGVertexInv:                     return 344;
            case ShaderDesc::ST_Position3dTexTGVertexInv:                    return 128;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexInv:               return 272;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexInv:           return 416;
            case ShaderDesc::ST_TexTGVertexCxformInv:                        return 62;
            case ShaderDesc::ST_BatchTexTGVertexCxformInv:                   return 206;
            case ShaderDesc::ST_InstancedTexTGVertexCxformInv:               return 350;
            case ShaderDesc::ST_Position3dTexTGVertexCxformInv:              return 134;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxformInv:         return 278;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxformInv:     return 422;
            case ShaderDesc::ST_TexTGVertexEAlphaInv:                        return 59;
            case ShaderDesc::ST_BatchTexTGVertexEAlphaInv:                   return 203;
            case ShaderDesc::ST_InstancedTexTGVertexEAlphaInv:               return 347;
            case ShaderDesc::ST_Position3dTexTGVertexEAlphaInv:              return 131;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexEAlphaInv:         return 275;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexEAlphaInv:     return 419;
            case ShaderDesc::ST_TexTGVertexCxformEAlphaInv:                  return 65;
            case ShaderDesc::ST_BatchTexTGVertexCxformEAlphaInv:             return 209;
            case ShaderDesc::ST_InstancedTexTGVertexCxformEAlphaInv:         return 353;
            case ShaderDesc::ST_Position3dTexTGVertexCxformEAlphaInv:        return 137;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxformEAlphaInv:   return 281;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxformEAlphaInv: return 425;
            case ShaderDesc::ST_TexTGVertexCxformAc:                         return 66;
            case ShaderDesc::ST_TexTGVertexCxformAcMul:                      return 67;
            case ShaderDesc::ST_BatchTexTGVertexCxformAc:                    return 210;
            case ShaderDesc::ST_BatchTexTGVertexCxformAcMul:                 return 211;
            case ShaderDesc::ST_InstancedTexTGVertexCxformAc:                return 354;
            case ShaderDesc::ST_InstancedTexTGVertexCxformAcMul:             return 355;
            case ShaderDesc::ST_Position3dTexTGVertexCxformAc:               return 138;
            case ShaderDesc::ST_Position3dTexTGVertexCxformAcMul:            return 139;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxformAc:          return 282;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxformAcMul:       return 283;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxformAc:      return 426;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxformAcMul:   return 427;
            case ShaderDesc::ST_TexTGVertexCxformAcEAlpha:                   return 69;
            case ShaderDesc::ST_TexTGVertexCxformAcEAlphaMul:                return 70;
            case ShaderDesc::ST_BatchTexTGVertexCxformAcEAlpha:              return 213;
            case ShaderDesc::ST_BatchTexTGVertexCxformAcEAlphaMul:           return 214;
            case ShaderDesc::ST_InstancedTexTGVertexCxformAcEAlpha:          return 357;
            case ShaderDesc::ST_InstancedTexTGVertexCxformAcEAlphaMul:       return 358;
            case ShaderDesc::ST_Position3dTexTGVertexCxformAcEAlpha:         return 141;
            case ShaderDesc::ST_Position3dTexTGVertexCxformAcEAlphaMul:      return 142;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxformAcEAlpha:    return 285;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxformAcEAlphaMul: return 286;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxformAcEAlpha: return 429;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxformAcEAlphaMul: return 430;
            case ShaderDesc::ST_TexTGVertexCxformAcInv:                      return 68;
            case ShaderDesc::ST_BatchTexTGVertexCxformAcInv:                 return 212;
            case ShaderDesc::ST_InstancedTexTGVertexCxformAcInv:             return 356;
            case ShaderDesc::ST_Position3dTexTGVertexCxformAcInv:            return 140;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxformAcInv:       return 284;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxformAcInv:   return 428;
            case ShaderDesc::ST_TexTGVertexCxformAcEAlphaInv:                return 71;
            case ShaderDesc::ST_BatchTexTGVertexCxformAcEAlphaInv:           return 215;
            case ShaderDesc::ST_InstancedTexTGVertexCxformAcEAlphaInv:       return 359;
            case ShaderDesc::ST_Position3dTexTGVertexCxformAcEAlphaInv:      return 143;
            case ShaderDesc::ST_BatchPosition3dTexTGVertexCxformAcEAlphaInv: return 287;
            case ShaderDesc::ST_InstancedPosition3dTexTGVertexCxformAcEAlphaInv: return 431;
            case ShaderDesc::ST_Solid:                                       return 432;
            case ShaderDesc::ST_SolidMul:                                    return 433;
            case ShaderDesc::ST_BatchSolid:                                  return 456;
            case ShaderDesc::ST_BatchSolidMul:                               return 457;
            case ShaderDesc::ST_InstancedSolid:                              return 480;
            case ShaderDesc::ST_InstancedSolidMul:                           return 481;
            case ShaderDesc::ST_Position3dSolid:                             return 444;
            case ShaderDesc::ST_Position3dSolidMul:                          return 445;
            case ShaderDesc::ST_BatchPosition3dSolid:                        return 468;
            case ShaderDesc::ST_BatchPosition3dSolidMul:                     return 469;
            case ShaderDesc::ST_InstancedPosition3dSolid:                    return 492;
            case ShaderDesc::ST_InstancedPosition3dSolidMul:                 return 493;
            case ShaderDesc::ST_SolidInv:                                    return 434;
            case ShaderDesc::ST_BatchSolidInv:                               return 458;
            case ShaderDesc::ST_InstancedSolidInv:                           return 482;
            case ShaderDesc::ST_Position3dSolidInv:                          return 446;
            case ShaderDesc::ST_BatchPosition3dSolidInv:                     return 470;
            case ShaderDesc::ST_InstancedPosition3dSolidInv:                 return 494;
            case ShaderDesc::ST_Text:                                        return 435;
            case ShaderDesc::ST_TextMul:                                     return 436;
            case ShaderDesc::ST_BatchText:                                   return 459;
            case ShaderDesc::ST_BatchTextMul:                                return 460;
            case ShaderDesc::ST_InstancedText:                               return 483;
            case ShaderDesc::ST_InstancedTextMul:                            return 484;
            case ShaderDesc::ST_Position3dText:                              return 447;
            case ShaderDesc::ST_Position3dTextMul:                           return 448;
            case ShaderDesc::ST_BatchPosition3dText:                         return 471;
            case ShaderDesc::ST_BatchPosition3dTextMul:                      return 472;
            case ShaderDesc::ST_InstancedPosition3dText:                     return 495;
            case ShaderDesc::ST_InstancedPosition3dTextMul:                  return 496;
            case ShaderDesc::ST_TextInv:                                     return 437;
            case ShaderDesc::ST_BatchTextInv:                                return 461;
            case ShaderDesc::ST_InstancedTextInv:                            return 485;
            case ShaderDesc::ST_Position3dTextInv:                           return 449;
            case ShaderDesc::ST_BatchPosition3dTextInv:                      return 473;
            case ShaderDesc::ST_InstancedPosition3dTextInv:                  return 497;
            case ShaderDesc::ST_TextColor:                                   return 438;
            case ShaderDesc::ST_TextColorMul:                                return 439;
            case ShaderDesc::ST_BatchTextColor:                              return 462;
            case ShaderDesc::ST_BatchTextColorMul:                           return 463;
            case ShaderDesc::ST_InstancedTextColor:                          return 486;
            case ShaderDesc::ST_InstancedTextColorMul:                       return 487;
            case ShaderDesc::ST_Position3dTextColor:                         return 450;
            case ShaderDesc::ST_Position3dTextColorMul:                      return 451;
            case ShaderDesc::ST_BatchPosition3dTextColor:                    return 474;
            case ShaderDesc::ST_BatchPosition3dTextColorMul:                 return 475;
            case ShaderDesc::ST_InstancedPosition3dTextColor:                return 498;
            case ShaderDesc::ST_InstancedPosition3dTextColorMul:             return 499;
            case ShaderDesc::ST_TextColorCxform:                             return 441;
            case ShaderDesc::ST_TextColorCxformMul:                          return 442;
            case ShaderDesc::ST_BatchTextColorCxform:                        return 465;
            case ShaderDesc::ST_BatchTextColorCxformMul:                     return 466;
            case ShaderDesc::ST_InstancedTextColorCxform:                    return 489;
            case ShaderDesc::ST_InstancedTextColorCxformMul:                 return 490;
            case ShaderDesc::ST_Position3dTextColorCxform:                   return 453;
            case ShaderDesc::ST_Position3dTextColorCxformMul:                return 454;
            case ShaderDesc::ST_BatchPosition3dTextColorCxform:              return 477;
            case ShaderDesc::ST_BatchPosition3dTextColorCxformMul:           return 478;
            case ShaderDesc::ST_InstancedPosition3dTextColorCxform:          return 501;
            case ShaderDesc::ST_InstancedPosition3dTextColorCxformMul:       return 502;
            case ShaderDesc::ST_TextColorInv:                                return 440;
            case ShaderDesc::ST_BatchTextColorInv:                           return 464;
            case ShaderDesc::ST_InstancedTextColorInv:                       return 488;
            case ShaderDesc::ST_Position3dTextColorInv:                      return 452;
            case ShaderDesc::ST_BatchPosition3dTextColorInv:                 return 476;
            case ShaderDesc::ST_InstancedPosition3dTextColorInv:             return 500;
            case ShaderDesc::ST_TextColorCxformInv:                          return 443;
            case ShaderDesc::ST_BatchTextColorCxformInv:                     return 467;
            case ShaderDesc::ST_InstancedTextColorCxformInv:                 return 491;
            case ShaderDesc::ST_Position3dTextColorCxformInv:                return 455;
            case ShaderDesc::ST_BatchPosition3dTextColorCxformInv:           return 479;
            case ShaderDesc::ST_InstancedPosition3dTextColorCxformInv:       return 503;
            case ShaderDesc::ST_YUV:                                         return 504;
            case ShaderDesc::ST_YUVMul:                                      return 505;
            case ShaderDesc::ST_BatchYUV:                                    return 564;
            case ShaderDesc::ST_BatchYUVMul:                                 return 565;
            case ShaderDesc::ST_InstancedYUV:                                return 624;
            case ShaderDesc::ST_InstancedYUVMul:                             return 625;
            case ShaderDesc::ST_Position3dYUV:                               return 534;
            case ShaderDesc::ST_Position3dYUVMul:                            return 535;
            case ShaderDesc::ST_BatchPosition3dYUV:                          return 594;
            case ShaderDesc::ST_BatchPosition3dYUVMul:                       return 595;
            case ShaderDesc::ST_InstancedPosition3dYUV:                      return 654;
            case ShaderDesc::ST_InstancedPosition3dYUVMul:                   return 655;
            case ShaderDesc::ST_YUVCxform:                                   return 508;
            case ShaderDesc::ST_YUVCxformMul:                                return 509;
            case ShaderDesc::ST_BatchYUVCxform:                              return 568;
            case ShaderDesc::ST_BatchYUVCxformMul:                           return 569;
            case ShaderDesc::ST_InstancedYUVCxform:                          return 628;
            case ShaderDesc::ST_InstancedYUVCxformMul:                       return 629;
            case ShaderDesc::ST_Position3dYUVCxform:                         return 538;
            case ShaderDesc::ST_Position3dYUVCxformMul:                      return 539;
            case ShaderDesc::ST_BatchPosition3dYUVCxform:                    return 598;
            case ShaderDesc::ST_BatchPosition3dYUVCxformMul:                 return 599;
            case ShaderDesc::ST_InstancedPosition3dYUVCxform:                return 658;
            case ShaderDesc::ST_InstancedPosition3dYUVCxformMul:             return 659;
            case ShaderDesc::ST_YUVEAlpha:                                   return 506;
            case ShaderDesc::ST_YUVEAlphaMul:                                return 507;
            case ShaderDesc::ST_BatchYUVEAlpha:                              return 566;
            case ShaderDesc::ST_BatchYUVEAlphaMul:                           return 567;
            case ShaderDesc::ST_InstancedYUVEAlpha:                          return 626;
            case ShaderDesc::ST_InstancedYUVEAlphaMul:                       return 627;
            case ShaderDesc::ST_Position3dYUVEAlpha:                         return 536;
            case ShaderDesc::ST_Position3dYUVEAlphaMul:                      return 537;
            case ShaderDesc::ST_BatchPosition3dYUVEAlpha:                    return 596;
            case ShaderDesc::ST_BatchPosition3dYUVEAlphaMul:                 return 597;
            case ShaderDesc::ST_InstancedPosition3dYUVEAlpha:                return 656;
            case ShaderDesc::ST_InstancedPosition3dYUVEAlphaMul:             return 657;
            case ShaderDesc::ST_YUVCxformEAlpha:                             return 510;
            case ShaderDesc::ST_YUVCxformEAlphaMul:                          return 511;
            case ShaderDesc::ST_BatchYUVCxformEAlpha:                        return 570;
            case ShaderDesc::ST_BatchYUVCxformEAlphaMul:                     return 571;
            case ShaderDesc::ST_InstancedYUVCxformEAlpha:                    return 630;
            case ShaderDesc::ST_InstancedYUVCxformEAlphaMul:                 return 631;
            case ShaderDesc::ST_Position3dYUVCxformEAlpha:                   return 540;
            case ShaderDesc::ST_Position3dYUVCxformEAlphaMul:                return 541;
            case ShaderDesc::ST_BatchPosition3dYUVCxformEAlpha:              return 600;
            case ShaderDesc::ST_BatchPosition3dYUVCxformEAlphaMul:           return 601;
            case ShaderDesc::ST_InstancedPosition3dYUVCxformEAlpha:          return 660;
            case ShaderDesc::ST_InstancedPosition3dYUVCxformEAlphaMul:       return 661;
            case ShaderDesc::ST_YUVCxformAc:                                 return 512;
            case ShaderDesc::ST_YUVCxformAcMul:                              return 513;
            case ShaderDesc::ST_BatchYUVCxformAc:                            return 572;
            case ShaderDesc::ST_BatchYUVCxformAcMul:                         return 573;
            case ShaderDesc::ST_InstancedYUVCxformAc:                        return 632;
            case ShaderDesc::ST_InstancedYUVCxformAcMul:                     return 633;
            case ShaderDesc::ST_Position3dYUVCxformAc:                       return 542;
            case ShaderDesc::ST_Position3dYUVCxformAcMul:                    return 543;
            case ShaderDesc::ST_BatchPosition3dYUVCxformAc:                  return 602;
            case ShaderDesc::ST_BatchPosition3dYUVCxformAcMul:               return 603;
            case ShaderDesc::ST_InstancedPosition3dYUVCxformAc:              return 662;
            case ShaderDesc::ST_InstancedPosition3dYUVCxformAcMul:           return 663;
            case ShaderDesc::ST_YUVCxformAcEAlpha:                           return 514;
            case ShaderDesc::ST_YUVCxformAcEAlphaMul:                        return 515;
            case ShaderDesc::ST_BatchYUVCxformAcEAlpha:                      return 574;
            case ShaderDesc::ST_BatchYUVCxformAcEAlphaMul:                   return 575;
            case ShaderDesc::ST_InstancedYUVCxformAcEAlpha:                  return 634;
            case ShaderDesc::ST_InstancedYUVCxformAcEAlphaMul:               return 635;
            case ShaderDesc::ST_Position3dYUVCxformAcEAlpha:                 return 544;
            case ShaderDesc::ST_Position3dYUVCxformAcEAlphaMul:              return 545;
            case ShaderDesc::ST_BatchPosition3dYUVCxformAcEAlpha:            return 604;
            case ShaderDesc::ST_BatchPosition3dYUVCxformAcEAlphaMul:         return 605;
            case ShaderDesc::ST_InstancedPosition3dYUVCxformAcEAlpha:        return 664;
            case ShaderDesc::ST_InstancedPosition3dYUVCxformAcEAlphaMul:     return 665;
            case ShaderDesc::ST_YUVA:                                        return 516;
            case ShaderDesc::ST_YUVAMul:                                     return 517;
            case ShaderDesc::ST_BatchYUVA:                                   return 576;
            case ShaderDesc::ST_BatchYUVAMul:                                return 577;
            case ShaderDesc::ST_InstancedYUVA:                               return 636;
            case ShaderDesc::ST_InstancedYUVAMul:                            return 637;
            case ShaderDesc::ST_Position3dYUVA:                              return 546;
            case ShaderDesc::ST_Position3dYUVAMul:                           return 547;
            case ShaderDesc::ST_BatchPosition3dYUVA:                         return 606;
            case ShaderDesc::ST_BatchPosition3dYUVAMul:                      return 607;
            case ShaderDesc::ST_InstancedPosition3dYUVA:                     return 666;
            case ShaderDesc::ST_InstancedPosition3dYUVAMul:                  return 667;
            case ShaderDesc::ST_YUVACxform:                                  return 522;
            case ShaderDesc::ST_YUVACxformMul:                               return 523;
            case ShaderDesc::ST_BatchYUVACxform:                             return 582;
            case ShaderDesc::ST_BatchYUVACxformMul:                          return 583;
            case ShaderDesc::ST_InstancedYUVACxform:                         return 642;
            case ShaderDesc::ST_InstancedYUVACxformMul:                      return 643;
            case ShaderDesc::ST_Position3dYUVACxform:                        return 552;
            case ShaderDesc::ST_Position3dYUVACxformMul:                     return 553;
            case ShaderDesc::ST_BatchPosition3dYUVACxform:                   return 612;
            case ShaderDesc::ST_BatchPosition3dYUVACxformMul:                return 613;
            case ShaderDesc::ST_InstancedPosition3dYUVACxform:               return 672;
            case ShaderDesc::ST_InstancedPosition3dYUVACxformMul:            return 673;
            case ShaderDesc::ST_YUVAEAlpha:                                  return 519;
            case ShaderDesc::ST_YUVAEAlphaMul:                               return 520;
            case ShaderDesc::ST_BatchYUVAEAlpha:                             return 579;
            case ShaderDesc::ST_BatchYUVAEAlphaMul:                          return 580;
            case ShaderDesc::ST_InstancedYUVAEAlpha:                         return 639;
            case ShaderDesc::ST_InstancedYUVAEAlphaMul:                      return 640;
            case ShaderDesc::ST_Position3dYUVAEAlpha:                        return 549;
            case ShaderDesc::ST_Position3dYUVAEAlphaMul:                     return 550;
            case ShaderDesc::ST_BatchPosition3dYUVAEAlpha:                   return 609;
            case ShaderDesc::ST_BatchPosition3dYUVAEAlphaMul:                return 610;
            case ShaderDesc::ST_InstancedPosition3dYUVAEAlpha:               return 669;
            case ShaderDesc::ST_InstancedPosition3dYUVAEAlphaMul:            return 670;
            case ShaderDesc::ST_YUVACxformEAlpha:                            return 525;
            case ShaderDesc::ST_YUVACxformEAlphaMul:                         return 526;
            case ShaderDesc::ST_BatchYUVACxformEAlpha:                       return 585;
            case ShaderDesc::ST_BatchYUVACxformEAlphaMul:                    return 586;
            case ShaderDesc::ST_InstancedYUVACxformEAlpha:                   return 645;
            case ShaderDesc::ST_InstancedYUVACxformEAlphaMul:                return 646;
            case ShaderDesc::ST_Position3dYUVACxformEAlpha:                  return 555;
            case ShaderDesc::ST_Position3dYUVACxformEAlphaMul:               return 556;
            case ShaderDesc::ST_BatchPosition3dYUVACxformEAlpha:             return 615;
            case ShaderDesc::ST_BatchPosition3dYUVACxformEAlphaMul:          return 616;
            case ShaderDesc::ST_InstancedPosition3dYUVACxformEAlpha:         return 675;
            case ShaderDesc::ST_InstancedPosition3dYUVACxformEAlphaMul:      return 676;
            case ShaderDesc::ST_YUVAInv:                                     return 518;
            case ShaderDesc::ST_BatchYUVAInv:                                return 578;
            case ShaderDesc::ST_InstancedYUVAInv:                            return 638;
            case ShaderDesc::ST_Position3dYUVAInv:                           return 548;
            case ShaderDesc::ST_BatchPosition3dYUVAInv:                      return 608;
            case ShaderDesc::ST_InstancedPosition3dYUVAInv:                  return 668;
            case ShaderDesc::ST_YUVACxformInv:                               return 524;
            case ShaderDesc::ST_BatchYUVACxformInv:                          return 584;
            case ShaderDesc::ST_InstancedYUVACxformInv:                      return 644;
            case ShaderDesc::ST_Position3dYUVACxformInv:                     return 554;
            case ShaderDesc::ST_BatchPosition3dYUVACxformInv:                return 614;
            case ShaderDesc::ST_InstancedPosition3dYUVACxformInv:            return 674;
            case ShaderDesc::ST_YUVAEAlphaInv:                               return 521;
            case ShaderDesc::ST_BatchYUVAEAlphaInv:                          return 581;
            case ShaderDesc::ST_InstancedYUVAEAlphaInv:                      return 641;
            case ShaderDesc::ST_Position3dYUVAEAlphaInv:                     return 551;
            case ShaderDesc::ST_BatchPosition3dYUVAEAlphaInv:                return 611;
            case ShaderDesc::ST_InstancedPosition3dYUVAEAlphaInv:            return 671;
            case ShaderDesc::ST_YUVACxformEAlphaInv:                         return 527;
            case ShaderDesc::ST_BatchYUVACxformEAlphaInv:                    return 587;
            case ShaderDesc::ST_InstancedYUVACxformEAlphaInv:                return 647;
            case ShaderDesc::ST_Position3dYUVACxformEAlphaInv:               return 557;
            case ShaderDesc::ST_BatchPosition3dYUVACxformEAlphaInv:          return 617;
            case ShaderDesc::ST_InstancedPosition3dYUVACxformEAlphaInv:      return 677;
            case ShaderDesc::ST_YUVACxformAc:                                return 528;
            case ShaderDesc::ST_YUVACxformAcMul:                             return 529;
            case ShaderDesc::ST_BatchYUVACxformAc:                           return 588;
            case ShaderDesc::ST_BatchYUVACxformAcMul:                        return 589;
            case ShaderDesc::ST_InstancedYUVACxformAc:                       return 648;
            case ShaderDesc::ST_InstancedYUVACxformAcMul:                    return 649;
            case ShaderDesc::ST_Position3dYUVACxformAc:                      return 558;
            case ShaderDesc::ST_Position3dYUVACxformAcMul:                   return 559;
            case ShaderDesc::ST_BatchPosition3dYUVACxformAc:                 return 618;
            case ShaderDesc::ST_BatchPosition3dYUVACxformAcMul:              return 619;
            case ShaderDesc::ST_InstancedPosition3dYUVACxformAc:             return 678;
            case ShaderDesc::ST_InstancedPosition3dYUVACxformAcMul:          return 679;
            case ShaderDesc::ST_YUVACxformAcEAlpha:                          return 531;
            case ShaderDesc::ST_YUVACxformAcEAlphaMul:                       return 532;
            case ShaderDesc::ST_BatchYUVACxformAcEAlpha:                     return 591;
            case ShaderDesc::ST_BatchYUVACxformAcEAlphaMul:                  return 592;
            case ShaderDesc::ST_InstancedYUVACxformAcEAlpha:                 return 651;
            case ShaderDesc::ST_InstancedYUVACxformAcEAlphaMul:              return 652;
            case ShaderDesc::ST_Position3dYUVACxformAcEAlpha:                return 561;
            case ShaderDesc::ST_Position3dYUVACxformAcEAlphaMul:             return 562;
            case ShaderDesc::ST_BatchPosition3dYUVACxformAcEAlpha:           return 621;
            case ShaderDesc::ST_BatchPosition3dYUVACxformAcEAlphaMul:        return 622;
            case ShaderDesc::ST_InstancedPosition3dYUVACxformAcEAlpha:       return 681;
            case ShaderDesc::ST_InstancedPosition3dYUVACxformAcEAlphaMul:    return 682;
            case ShaderDesc::ST_YUVACxformAcInv:                             return 530;
            case ShaderDesc::ST_BatchYUVACxformAcInv:                        return 590;
            case ShaderDesc::ST_InstancedYUVACxformAcInv:                    return 650;
            case ShaderDesc::ST_Position3dYUVACxformAcInv:                   return 560;
            case ShaderDesc::ST_BatchPosition3dYUVACxformAcInv:              return 620;
            case ShaderDesc::ST_InstancedPosition3dYUVACxformAcInv:          return 680;
            case ShaderDesc::ST_YUVACxformAcEAlphaInv:                       return 533;
            case ShaderDesc::ST_BatchYUVACxformAcEAlphaInv:                  return 593;
            case ShaderDesc::ST_InstancedYUVACxformAcEAlphaInv:              return 653;
            case ShaderDesc::ST_Position3dYUVACxformAcEAlphaInv:             return 563;
            case ShaderDesc::ST_BatchPosition3dYUVACxformAcEAlphaInv:        return 623;
            case ShaderDesc::ST_InstancedPosition3dYUVACxformAcEAlphaInv:    return 683;
            case ShaderDesc::ST_TexTGCMatrixAc:                              return 684;
            case ShaderDesc::ST_TexTGCMatrixAcMul:                           return 685;
            case ShaderDesc::ST_TexTGCMatrixAcEAlpha:                        return 686;
            case ShaderDesc::ST_TexTGCMatrixAcEAlphaMul:                     return 687;
            case ShaderDesc::ST_Box1Blur:                                    return 688;
            case ShaderDesc::ST_Box1BlurMul:                                 return 689;
            case ShaderDesc::ST_Box2Blur:                                    return 690;
            case ShaderDesc::ST_Box2BlurMul:                                 return 691;
            case ShaderDesc::ST_Box2Shadow:                                  return 692;
            case ShaderDesc::ST_Box2ShadowMul:                               return 693;
            case ShaderDesc::ST_Box2ShadowKnockout:                          return 694;
            case ShaderDesc::ST_Box2ShadowKnockoutMul:                       return 695;
            case ShaderDesc::ST_Box2Shadowonly:                              return 700;
            case ShaderDesc::ST_Box2ShadowonlyMul:                           return 701;
            case ShaderDesc::ST_Box2InnerShadow:                             return 696;
            case ShaderDesc::ST_Box2InnerShadowMul:                          return 697;
            case ShaderDesc::ST_Box2InnerShadowKnockout:                     return 698;
            case ShaderDesc::ST_Box2InnerShadowKnockoutMul:                  return 699;
            case ShaderDesc::ST_Box2ShadowonlyHighlight:                     return 712;
            case ShaderDesc::ST_Box2ShadowonlyHighlightMul:                  return 713;
            case ShaderDesc::ST_Box2FullShadowHighlight:                     return 710;
            case ShaderDesc::ST_Box2FullShadowHighlightMul:                  return 711;
            case ShaderDesc::ST_Box2InnerShadowHighlight:                    return 706;
            case ShaderDesc::ST_Box2InnerShadowHighlightMul:                 return 707;
            case ShaderDesc::ST_Box2InnerShadowHighlightKnockout:            return 708;
            case ShaderDesc::ST_Box2InnerShadowHighlightKnockoutMul:         return 709;
            case ShaderDesc::ST_Box2ShadowHighlight:                         return 702;
            case ShaderDesc::ST_Box2ShadowHighlightMul:                      return 703;
            case ShaderDesc::ST_Box2ShadowHighlightKnockout:                 return 704;
            case ShaderDesc::ST_Box2ShadowHighlightKnockoutMul:              return 705;
            case ShaderDesc::ST_DrawableCopyPixels:                          return 714;
            case ShaderDesc::ST_DrawableCopyPixelsNoDestAlpha:               return 716;
            case ShaderDesc::ST_DrawableCopyPixelsMergeAlpha:                return 715;
            case ShaderDesc::ST_DrawableCopyPixelsAlpha:                     return 717;
            case ShaderDesc::ST_DrawableCopyPixelsAlphaNoDestAlpha:          return 719;
            case ShaderDesc::ST_DrawableCopyPixelsAlphaMergeAlpha:           return 718;
            case ShaderDesc::ST_DrawableMerge:                               return 720;
            case ShaderDesc::ST_DrawableCompare:                             return 721;
            case ShaderDesc::ST_DrawablePaletteMap:                          return 722;
            default: SF_ASSERT(0); return 0;
        }
        default: SF_ASSERT(0); return 0;
    }
}

}}} // Scaleform::Render::Vulkan

