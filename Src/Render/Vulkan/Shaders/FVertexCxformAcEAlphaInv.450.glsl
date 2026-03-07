#version 450
layout(location=0) in vec4 color;
layout(location=1) in vec4 factor;
layout(location=2) in vec4 fucxadd;
layout(location=3) in vec4 fucxmul;
layout(location=0) out vec4 fcolor;
void main() { 

  fcolor = color;
  

      fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;
      fcolor += fucxadd * fcolor.a;
    

    fcolor.a *= factor.a;
    

    fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);
    
}
