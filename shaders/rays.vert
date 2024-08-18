#version 330 core

layout (location = 0) in vec2 vs_pos;

uniform vec2 u_zoom_over_dims;

void main() {
    gl_Position = vec4(vs_pos * u_zoom_over_dims, 0.0, 1.0);
}