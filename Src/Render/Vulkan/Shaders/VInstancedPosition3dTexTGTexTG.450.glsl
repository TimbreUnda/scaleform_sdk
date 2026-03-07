#version 450
layout(set=0, binding=0) uniform UniformBlock { mat4 vfmuniforms[24]; vec4 vfuniforms[96]; };
layout(location=0) in vec4 afactor;
layout(location=1) in vec4 pos;
layout(location=0) out vec4 factor;
layout(location=1) out vec2 tc0;
layout(location=2) out vec2 tc1;
void main() { 

    gl_Position = (pos) * ( vfmuniforms[int(gl_InstanceIndex * 1.0 + 0.0+ 0.1)]);
    

    tc0.x = dot(pos, vfuniforms[int(gl_InstanceIndex * 4.0 + 0.0+ 0.1 + 0.0)]);
    tc0.y = dot(pos, vfuniforms[int(gl_InstanceIndex * 4.0 + 0.0+ 0.1 + 1.0)]);
    tc1.x = dot(pos, vfuniforms[int(gl_InstanceIndex * 4.0 + 0.0+ 0.1 + 2.0)]);
    tc1.y = dot(pos, vfuniforms[int(gl_InstanceIndex * 4.0 + 0.0+ 0.1 + 3.0)]);
    

      factor = afactor;
    
}
