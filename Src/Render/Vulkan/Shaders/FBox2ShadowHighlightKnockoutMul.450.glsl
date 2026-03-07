#version 450
layout(set=0, binding=0) uniform UniformBlock { vec4 fsize; vec4 offset; vec4 scolor; vec4 scolor2; vec4 srctexscale; vec4 texscale; };
layout(binding=1) uniform sampler2D srctex;
layout(binding=2) uniform sampler2D tex;
layout(location=0) in vec4 fucxadd;
layout(location=1) in vec4 fucxmul;
layout(location=2) in vec2 tc;
layout(location=0) out vec4 fcolor;
void main() { 

    fcolor       = vec4(0.0, 0.0, 0.0, 0.0);
    vec4 color = vec4(0.0, 0.0, 0.0, 0.0);
    vec2 i = vec2(0.0, 0.0);
    for (i.x = -fsize.x; i.x <= fsize.x; i.x++)
    {
      for (i.y = -fsize.y; i.y <= fsize.y; i.y++)
      {
    

    color.a += textureLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;
    color.r += textureLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;
    }
    } // EndBox2.
    fcolor = color * fsize.w;
    

    vec4 base = textureLod(srctex, tc * srctexscale.xy, 0.0);
    fcolor.ar = clamp((1.0 - fcolor.ar * fsize.z) - (1.0 - fcolor.ra * fsize.z), 0.0, 1.0);
    vec4 knockout = base;
    fcolor = ((scolor * fcolor.a + scolor2 * fcolor.r)*(1.0-base.a) + base);
    

    fcolor -= knockout;
    

      fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;
      fcolor += fucxadd * fcolor.a;
    

    fcolor.rgb = fcolor.rgb * fcolor.a;
    
}
