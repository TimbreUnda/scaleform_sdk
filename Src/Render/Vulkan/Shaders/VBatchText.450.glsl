#version 450
layout(set=0, binding=0) uniform UniformBlock { vec4 vfuniforms[96]; };
layout(location=0) in vec4 acolor;
layout(location=1) in vec2 atc;
layout(location=2) in vec4 pos;
layout(location=3) in float vbatch;
layout(location=0) out vec2 tc;
layout(location=1) out vec4 vcolor;
void main() { 

    gl_Position = vec4(0.0,0,0.0,1);
    gl_Position.x = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 0.0)]);
    gl_Position.y = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 1.0)]);
    

    vcolor = acolor * vfuniforms[int(vbatch * 4.0 + 1.0+ 0.1)] + vfuniforms[int(vbatch * 4.0 + 0.0+ 0.1)];
    tc = atc;
    
}
