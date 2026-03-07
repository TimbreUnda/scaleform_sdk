#version 450
layout(set=0, binding=0) uniform UniformBlock { mat4 mvp; };
layout(location=0) in vec4 pos;
void main() { 

    gl_Position = (pos) * ( mvp);
    
}
