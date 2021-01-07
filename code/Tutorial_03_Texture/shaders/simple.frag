#version 330 core

// fragment shader
uniform sampler2D texture;

in vec4 fragColor;    // input: interpolated color as rgba-value
in vec2 texCoord;
out vec4 finalColor;  // output: final color value as rgba-value

void main() {
  //finalColor = fragColor;
  finalColor = texture(texture, texCoord);
}
