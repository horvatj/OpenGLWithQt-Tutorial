#version 330 core

// vertex shader
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texCoords;

out vec4 fragColor;
out vec2 texCoord;

void main() {
  gl_Position = vec4(position, 1.0);
  fragColor = vec4(color, 1.0);
  texCoord = texCoords;
}
