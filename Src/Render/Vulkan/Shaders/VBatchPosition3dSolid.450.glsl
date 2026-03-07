#version 450
layout(set=0, binding=0) uniform UniformBlock { mat4 vfmuniforms[24]; };
layout(location=0) in vec4 pos;
layout(location=1) in float vbatch;
void main() { 

    gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);
    
}
