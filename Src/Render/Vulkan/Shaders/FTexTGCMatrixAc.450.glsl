#version 450
layout(set=0, binding=0) uniform UniformBlock { vec4 cxadd; mat4 cxmul; };
layout(binding=1) uniform sampler2D tex;
layout(location=0) in vec2 tc;
layout(location=0) out vec4 fcolor;
void main() { 

    fcolor = texture(tex,tc);
    

    fcolor = (fcolor) * (cxmul) + cxadd * (fcolor.a + cxadd.a);
    
}
