#version 330 core
uniform vec2 u_position;

void main() {
    gl_Position = vec4(u_position, -0.5, 1.0);
}