#version 450
layout(set=0, binding=0) uniform UniformBlock { vec4 mvp[2]; vec4 texgen[6]; };
layout(location=0) in vec4 pos;
layout(location=0) out vec2 tc0;
layout(location=1) out vec2 tc1;
layout(location=2) out vec2 tc2;
void main() { 

    gl_Position = vec4(0.0,0,0.0,1);
    gl_Position.x = dot(pos, mvp[int(0.0)]);
    gl_Position.y = dot(pos, mvp[int(1.0)]);
    

    tc0.x = dot(pos, texgen[int(0.0)]);
    tc0.y = dot(pos, texgen[int(1.0)]);
    tc1.x = dot(pos, texgen[int(2.0)]);
    tc1.y = dot(pos, texgen[int(3.0)]);
    tc2.x = dot(pos, texgen[int(4.0)]);
    tc2.y = dot(pos, texgen[int(5.0)]);
    
}
