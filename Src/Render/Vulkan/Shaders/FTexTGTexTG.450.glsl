#version 450
layout(binding=1) uniform sampler2D tex[2];
layout(location=0) in vec4 factor;
layout(location=1) in vec2 tc0;
layout(location=2) in vec2 tc1;
layout(location=0) out vec4 fcolor;
void main() { 

    vec4 fcolor0 = texture(tex[int(0.0)], tc0);
    vec4 fcolor1 = texture(tex[int(1.0)], tc1);
    fcolor = mix(fcolor1, fcolor0, factor.r);
    
}
