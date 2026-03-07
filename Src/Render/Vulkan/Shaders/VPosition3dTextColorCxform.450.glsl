#version 450
layout(set=0, binding=0) uniform UniformBlock { vec4 cxadd; vec4 cxmul; mat4 mvp; };
layout(location=0) in vec2 atc;
layout(location=1) in vec4 pos;
layout(location=0) out vec4 fucxadd;
layout(location=1) out vec4 fucxmul;
layout(location=2) out vec2 tc;
void main() { 

    gl_Position = (pos) * ( mvp);
    

      tc = atc;
    

    fucxadd = cxadd;
    fucxmul = cxmul;
    
}
