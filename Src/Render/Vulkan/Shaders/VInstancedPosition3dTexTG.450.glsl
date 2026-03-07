#version 450
layout(set=0, binding=0) uniform UniformBlock { mat4 vfmuniforms[24]; vec4 vfuniforms[48]; };
layout(location=0) in vec4 pos;
layout(location=0) out vec2 tc;
void main() { 

    gl_Position = (pos) * ( vfmuniforms[int(gl_InstanceIndex * 1.0 + 0.0+ 0.1)]);
    

    tc.x = dot(pos, vfuniforms[int(gl_InstanceIndex * 2.0 + 0.0+ 0.1 + 0.0)]);
    tc.y = dot(pos, vfuniforms[int(gl_InstanceIndex * 2.0 + 0.0+ 0.1 + 1.0)]);
    
}
