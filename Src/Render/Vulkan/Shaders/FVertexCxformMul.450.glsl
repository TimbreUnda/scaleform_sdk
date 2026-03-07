#version 450
layout(location=0) in vec4 color;
layout(location=1) in vec4 fucxadd;
layout(location=2) in vec4 fucxmul;
layout(location=0) out vec4 fcolor;
void main() { 

  fcolor = color;
  

    fcolor = fcolor * fucxmul + fucxadd;
    

    fcolor.rgb = fcolor.rgb * fcolor.a;
    
}
