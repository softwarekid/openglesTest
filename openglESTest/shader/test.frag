#ifdef GL_FRAGMENT_PRECISION_HIGH
precision highp float;
#else
precision mediump float;
#endif

uniform sampler2D albedo;
varying vec2 v2fTexCoord;
uniform int rowFrameNum;
uniform int colFrameNum;
uniform float speed;
uniform float time_;

void main()
{
    int numFrame = rowFrameNum * colFrameNum;
    float rowDelta = 1.0 / float(rowFrameNum);
    float colDelta = 1.0 / float(colFrameNum);

    int frameIndex = int(mod(speed * time_, float(numFrame)));
    int rowIndex = frameIndex / rowFrameNum;
    int colIndex = frameIndex - rowIndex * rowFrameNum;
    vec2 offset = vec2(float(colIndex) * rowDelta, float(rowIndex) * colDelta);
    gl_FragColor = texture2D(albedo, offset + vec2(v2fTexCoord.x / float(rowFrameNum), v2fTexCoord.y / float(colFrameNum)));
}
