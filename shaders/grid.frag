#version 330 core

uniform vec2 u_dimensions;
in vec2 world_pos;

out vec4 frag_col;
void main()
{
   vec2 frac = fract(world_pos);
   if ((frac.x > 0.025 && frac.x < 0.975) && (frac.y > 0.025 && frac.y < 0.975)) {
      discard;
   }
   frag_col = vec4(abs(world_pos.x) < 0.025 ? 1.0 : 0.0, abs(world_pos.y) < 0.025 ? 1.0 : 0.0, 0.0, 0.0);
}