#version 450
layout(binding=1) uniform sampler2D tex;
layout(location=0) in vec4 factor;
layout(location=1) in vec2 tc;
layout(location=0) out vec4 fcolor;
void main() { 

    fcolor = texture(tex,tc);
    

    fcolor.a *= factor.a;
    
}
