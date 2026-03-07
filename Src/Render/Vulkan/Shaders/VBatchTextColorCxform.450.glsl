#version 450
layout(set=0, binding=0) uniform UniformBlock { vec4 vfuniforms[96]; };
layout(location=0) in vec2 atc;
layout(location=1) in vec4 pos;
layout(location=2) in float vbatch;
layout(location=0) out vec4 fucxadd;
layout(location=1) out vec4 fucxmul;
layout(location=2) out vec2 tc;
void main() { 

    gl_Position = vec4(0.0,0,0.0,1);
    gl_Position.x = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 0.0)]);
    gl_Position.y = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 1.0)]);
    

      tc = atc;
    

    fucxadd = vfuniforms[int(vbatch * 4.0 + 0.0+ 0.1)];
    fucxmul = vfuniforms[int(vbatch * 4.0 + 1.0+ 0.1)];
    
}
