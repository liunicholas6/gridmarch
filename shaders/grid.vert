#version 330 core
layout (location = 0) in vec3 ndc_pos;

uniform vec2 u_dims_over_zoom;
out vec2 world_pos;

void main()
{
    world_pos = u_dims_over_zoom * ndc_pos.xy;
    gl_Position = vec4(ndc_pos.x, ndc_pos.y, ndc_pos.z, 1.0);
}