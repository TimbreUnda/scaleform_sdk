#version 450
layout(set=0, binding=0) uniform UniformBlock { mat4 vfmuniforms[24]; vec4 vfuniforms[48]; };
layout(location=0) in vec4 afactor;
layout(location=1) in vec4 pos;
layout(location=0) out vec4 factor;
layout(location=1) out vec2 tc;
void main() { 

    gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);
    

    tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 2.0 + 0.0+ 0.1 + 0.0)]);
    tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 2.0 + 0.0+ 0.1 + 1.0)]);
    

      factor = afactor;
    
}
