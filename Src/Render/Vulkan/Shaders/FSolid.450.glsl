#version 450
layout(set=0, binding=0) uniform UniformBlock { vec4 cxmul; };
layout(location=0) out vec4 fcolor;
void main() { 

    fcolor = cxmul;
    
}
