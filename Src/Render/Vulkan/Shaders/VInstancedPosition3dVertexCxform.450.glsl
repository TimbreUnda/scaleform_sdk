#version 450
layout(set=0, binding=0) uniform UniformBlock { mat4 vfmuniforms[24]; vec4 vfuniforms[48]; };
layout(location=0) in vec4 acolor;
layout(location=1) in vec4 pos;
layout(location=0) out vec4 color;
layout(location=1) out vec4 fucxadd;
layout(location=2) out vec4 fucxmul;
void main() { 

    gl_Position = (pos) * ( vfmuniforms[int(gl_InstanceIndex * 1.0 + 0.0+ 0.1)]);
    

    color = acolor;
    

    fucxadd = vfuniforms[int(gl_InstanceIndex * 2.0 + 0.0+ 0.1)];
    fucxmul = vfuniforms[int(gl_InstanceIndex * 2.0 + 1.0+ 0.1)];
    
}
