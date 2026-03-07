#version 450
layout(set=0, binding=0) uniform UniformBlock { mat4 cxmul; mat4 cxmul1; };
layout(binding=1) uniform sampler2D tex[2];
layout(location=0) in vec2 tc0;
layout(location=1) in vec2 tc1;
layout(location=0) out vec4 fcolor;
void main() { 

    vec4 fcolor_original = texture(tex[int(0.0)], tc0);
    vec4 fcolor_source   = texture(tex[int(1.0)], tc1);
    fcolor = (fcolor_original) * ( cxmul) + (fcolor_source) * ( cxmul1);
    
}
