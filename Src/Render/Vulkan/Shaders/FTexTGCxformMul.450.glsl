#version 450
layout(binding=1) uniform sampler2D tex;
layout(location=0) in vec4 fucxadd;
layout(location=1) in vec4 fucxmul;
layout(location=2) in vec2 tc;
layout(location=0) out vec4 fcolor;
void main() { 

    fcolor = texture(tex,tc);
    

    fcolor = fcolor * fucxmul + fucxadd;
    

    fcolor.rgb = fcolor.rgb * fcolor.a;
    
}
