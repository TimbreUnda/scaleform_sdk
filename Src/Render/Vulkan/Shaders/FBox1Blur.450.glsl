#version 450
layout(set=0, binding=0) uniform UniformBlock { vec4 fsize; vec4 texscale; };
layout(binding=1) uniform sampler2D tex;
layout(location=0) in vec4 fucxadd;
layout(location=1) in vec4 fucxmul;
layout(location=2) in vec2 tc;
layout(location=0) out vec4 fcolor;
void main() { 

      fcolor       = vec4(0.0, 0.0, 0.0, 0.0);
      vec4 color = vec4(0.0, 0.0, 0.0, 0.0);
      float  i = 0.0;
      for (i = -fsize.x; i <= fsize.x; i++)
      {{
    

    color += textureLod(tex, tc + i * texscale.xy, 0.0);
    }} // EndBox1/2.
    fcolor = color * fsize.w;
    

      fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;
      fcolor += fucxadd * fcolor.a;
    
}
