#version 450
layout(binding=1) uniform sampler2D tex;
layout(location=0) in vec2 tc;
layout(location=1) in vec4 vcolor;
layout(location=0) out vec4 fcolor;
void main() { 

    vec4 c = vcolor;
    c.a = c.a * texture(tex, tc).r;
    fcolor = c;
    
}
