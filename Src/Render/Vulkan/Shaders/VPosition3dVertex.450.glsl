#version 450
layout(set=0, binding=0) uniform UniformBlock { mat4 mvp; };
layout(location=0) in vec4 acolor;
layout(location=1) in vec4 pos;
layout(location=0) out vec4 color;
void main() { 

    gl_Position = (pos) * ( mvp);
    

    color = acolor;
    
}
