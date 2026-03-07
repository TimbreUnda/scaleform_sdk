#version 450
layout(set=0, binding=0) uniform UniformBlock { vec4 cxadd; vec4 cxmul; vec4 mvp[2]; vec4 texgen[4]; };
layout(location=0) in vec4 afactor;
layout(location=1) in vec4 pos;
layout(location=0) out vec4 factor;
layout(location=1) out vec4 fucxadd;
layout(location=2) out vec4 fucxmul;
layout(location=3) out vec2 tc0;
layout(location=4) out vec2 tc1;
void main() { 

    gl_Position = vec4(0.0,0,0.0,1);
    gl_Position.x = dot(pos, mvp[int(0.0)]);
    gl_Position.y = dot(pos, mvp[int(1.0)]);
    

    tc0.x = dot(pos, texgen[int(0.0)]);
    tc0.y = dot(pos, texgen[int(1.0)]);
    tc1.x = dot(pos, texgen[int(2.0)]);
    tc1.y = dot(pos, texgen[int(3.0)]);
    

    fucxadd = cxadd;
    fucxmul = cxmul;
    

      factor = afactor;
    
}
