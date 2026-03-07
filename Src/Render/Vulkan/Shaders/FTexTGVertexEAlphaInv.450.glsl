#version 450
layout(binding=1) uniform sampler2D tex;
layout(location=0) in vec4 color;
layout(location=1) in vec4 factor;
layout(location=2) in vec2 tc;
layout(location=0) out vec4 fcolor;
void main() { 

    vec4 fcolor0 = texture(tex,tc);
    vec4 fcolor1 = color;
    fcolor = mix(fcolor1, fcolor0, factor.r);
    

    fcolor.a *= factor.a;
    

    fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);
    
}
