#version 450
layout(set=0, binding=0) uniform UniformBlock { vec4 vfuniforms[48]; };
layout(location=0) in vec4 pos;
layout(location=1) in float vbatch;
void main() { 

    gl_Position = vec4(0.0,0,0.0,1);
    gl_Position.x = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 0.0)]);
    gl_Position.y = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 1.0)]);
    
}
