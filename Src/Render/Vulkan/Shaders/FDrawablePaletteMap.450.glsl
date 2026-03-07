#version 450
layout(binding=1) uniform sampler2D srctex;
layout(binding=2) uniform sampler2D tex;
layout(location=0) in vec2 tc;
layout(location=0) out vec4 fcolor;
void main() { 

    vec4 fchannels = texture(tex, tc);
    fcolor  = texture(srctex, vec2(fchannels.r, 0.125));
    fcolor += texture(srctex, vec2(fchannels.g, 0.375));
    fcolor += texture(srctex, vec2(fchannels.b, 0.625));
    fcolor += texture(srctex, vec2(fchannels.a, 0.875));
    
}
