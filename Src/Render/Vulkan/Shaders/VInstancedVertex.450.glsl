#version 450
layout(set=0, binding=0) uniform UniformBlock { vec4 vfuniforms[48]; };
layout(location=0) in vec4 acolor;
layout(location=1) in vec4 pos;
layout(location=0) out vec4 color;
void main() { 

    gl_Position = vec4(0.0,0,0.0,1);
    gl_Position.x = dot(pos, vfuniforms[int(gl_InstanceIndex * 2.0 + 0.0+ 0.1 + 0.0)]);
    gl_Position.y = dot(pos, vfuniforms[int(gl_InstanceIndex * 2.0 + 0.0+ 0.1 + 1.0)]);
    

    color = acolor;
    
}
