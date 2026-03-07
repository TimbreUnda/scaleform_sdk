#version 450
layout(set=0, binding=0) uniform UniformBlock { vec4 mvp[2]; };
layout(location=0) in vec4 pos;
void main() { 

    gl_Position = vec4(0.0,0,0.0,1);
    gl_Position.x = dot(pos, mvp[int(0.0)]);
    gl_Position.y = dot(pos, mvp[int(1.0)]);
    
}
