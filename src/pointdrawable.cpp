#include "pointdrawable.h"
#include <iostream>

PointDrawable::PointDrawable(glm::vec2 point) :
    m_point(point),
    m_shader("point.vert", "point.frag"),
    u_position(m_shader.get_uniform_location("u_position"))
{}

void PointDrawable::draw(float screenWidth, float screenHeight, float zoom)
{
    glPointSize(zoom / 10);
    m_shader.use_me();
    glm::vec2 ndc = m_point * zoom / glm::vec2(screenWidth, screenHeight);
    glUniform2f(u_position, ndc.x, ndc.y);
    glDrawArrays(GL_POINTS, 0, 1);
}
