#version 450
layout(location=0) in vec4 color;
layout(location=1) in vec4 factor;
layout(location=0) out vec4 fcolor;
void main() { 

  fcolor = color;
  

    fcolor.a *= factor.a;
    
}
