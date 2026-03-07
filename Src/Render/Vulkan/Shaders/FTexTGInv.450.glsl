#version 450
layout(binding=1) uniform sampler2D tex;
layout(location=0) in vec2 tc;
layout(location=0) out vec4 fcolor;
void main() { 

    fcolor = texture(tex,tc);
    

    fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);
    
}
