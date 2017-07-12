#ifdef GL_FRAGMENT_PRECISION_HIGH
precision highp float;
#else
precision mediump float;
#endif

varying vec2 v2fTexCoord;

uniform sampler2D albedo;
uniform vec4 oriTexSize;
uniform vec4 downTexSize;

vec4 DownSample(vec2 uv)
{
    vec4 offset = oriTexSize.xyxy * vec4(-1, -1, 1, 1);
    vec4 color1 = texture2D(albedo, uv + offset.xy);
    vec4 color2 = texture2D(albedo, uv + offset.xy);
    vec4 color3 = texture2D(albedo, uv + offset.xy);
    vec4 color4 = texture2D(albedo, uv + offset.xy);

    return (color1 + color2 + color3 + color4) / 4.0;
}

void main()
{
    gl_FragColor =  DownSample(v2fTexCoord);
}
