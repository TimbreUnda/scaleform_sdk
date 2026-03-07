#version 450
layout(set=0, binding=0) uniform UniformBlock { vec4 vfuniforms[144]; };
layout(location=0) in vec4 acolor;
layout(location=1) in vec4 afactor;
layout(location=2) in vec4 pos;
layout(location=0) out vec4 color;
layout(location=1) out vec4 factor;
layout(location=2) out vec4 fucxadd;
layout(location=3) out vec4 fucxmul;
layout(location=4) out vec2 tc;
void main() { 

    gl_Position = vec4(0.0,0,0.0,1);
    gl_Position.x = dot(pos, vfuniforms[int(gl_InstanceIndex * 6.0 + 2.0+ 0.1 + 0.0)]);
    gl_Position.y = dot(pos, vfuniforms[int(gl_InstanceIndex * 6.0 + 2.0+ 0.1 + 1.0)]);
    

    color = acolor;
    tc.x = dot(pos, vfuniforms[int(gl_InstanceIndex * 6.0 + 4.0+ 0.1 + 0.0)]);
    tc.y = dot(pos, vfuniforms[int(gl_InstanceIndex * 6.0 + 4.0+ 0.1 + 1.0)]);
    

    fucxadd = vfuniforms[int(gl_InstanceIndex * 6.0 + 0.0+ 0.1)];
    fucxmul = vfuniforms[int(gl_InstanceIndex * 6.0 + 1.0+ 0.1)];
    

      factor = afactor;
    
}
