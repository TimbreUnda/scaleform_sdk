#version 450
layout(set=0, binding=0) uniform UniformBlock { vec4 vfuniforms[192]; };
layout(location=0) in vec4 afactor;
layout(location=1) in vec4 pos;
layout(location=0) out vec4 factor;
layout(location=1) out vec4 fucxadd;
layout(location=2) out vec4 fucxmul;
layout(location=3) out vec2 tc0;
layout(location=4) out vec2 tc1;
void main() { 

    gl_Position = vec4(0.0,0,0.0,1);
    gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 2.0+ 0.1 + 0.0)]);
    gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 2.0+ 0.1 + 1.0)]);
    

    tc0.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 4.0+ 0.1 + 0.0)]);
    tc0.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 4.0+ 0.1 + 1.0)]);
    tc1.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 4.0+ 0.1 + 2.0)]);
    tc1.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 4.0+ 0.1 + 3.0)]);
    

    fucxadd = vfuniforms[int(afactor.b*255.01 * 8.0 + 0.0+ 0.1)];
    fucxmul = vfuniforms[int(afactor.b*255.01 * 8.0 + 1.0+ 0.1)];
    

      factor = afactor;
    
}
