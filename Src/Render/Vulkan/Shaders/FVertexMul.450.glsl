#version 450
layout(location=0) in vec4 color;
layout(location=0) out vec4 fcolor;
void main() { 

  fcolor = color;
  

    fcolor.rgb = fcolor.rgb * fcolor.a;
    
}
