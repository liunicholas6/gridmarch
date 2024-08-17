#version 330 core
layout (location = 0) in vec3 aPos;

uniform vec2 u_dimensions;
out vec2 world_pos;

void main()
{
    world_pos = u_dimensions * aPos.xy;
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}