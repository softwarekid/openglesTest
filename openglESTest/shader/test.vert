uniform mat4 MVP;
attribute vec3 vPos;
attribute vec2 vTex;

varying vec2 v2fTexCoord;

void main()
{
    gl_Position = MVP * vec4(vPos,  1.0);
    v2fTexCoord = vec2(1.0 - vTex);
}
