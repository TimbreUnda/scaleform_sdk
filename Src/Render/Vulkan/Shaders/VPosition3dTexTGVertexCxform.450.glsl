#version 450
layout(set=0, binding=0) uniform UniformBlock { vec4 cxadd; vec4 cxmul; mat4 mvp; vec4 texgen[2]; };
layout(location=0) in vec4 acolor;
layout(location=1) in vec4 afactor;
layout(location=2) in vec4 pos;
layout(location=0) out vec4 color;
layout(location=1) out vec4 factor;
layout(location=2) out vec4 fucxadd;
layout(location=3) out vec4 fucxmul;
layout(location=4) out vec2 tc;
void main() { 

    gl_Position = (pos) * ( mvp);
    

    color = acolor;
    tc.x = dot(pos, texgen[int(0.0)]);
    tc.y = dot(pos, texgen[int(1.0)]);
    

    fucxadd = cxadd;
    fucxmul = cxmul;
    

      factor = afactor;
    
}
