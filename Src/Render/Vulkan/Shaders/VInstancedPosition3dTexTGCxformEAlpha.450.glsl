#version 450
layout(set=0, binding=0) uniform UniformBlock { mat4 vfmuniforms[24]; vec4 vfuniforms[96]; };
layout(location=0) in vec4 afactor;
layout(location=1) in vec4 pos;
layout(location=0) out vec4 factor;
layout(location=1) out vec4 fucxadd;
layout(location=2) out vec4 fucxmul;
layout(location=3) out vec2 tc;
void main() { 

    gl_Position = (pos) * ( vfmuniforms[int(gl_InstanceIndex * 1.0 + 0.0+ 0.1)]);
    

    tc.x = dot(pos, vfuniforms[int(gl_InstanceIndex * 4.0 + 2.0+ 0.1 + 0.0)]);
    tc.y = dot(pos, vfuniforms[int(gl_InstanceIndex * 4.0 + 2.0+ 0.1 + 1.0)]);
    

    fucxadd = vfuniforms[int(gl_InstanceIndex * 4.0 + 0.0+ 0.1)];
    fucxmul = vfuniforms[int(gl_InstanceIndex * 4.0 + 1.0+ 0.1)];
    

      factor = afactor;
    
}
