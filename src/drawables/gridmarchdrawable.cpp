#include "gridmarchdrawable.h"

GridMarchDrawable::GridMarchDrawable() {
    set_render_data();
}

void GridMarchDrawable::set_point(glm::vec2 point)
{
    m_gridMarch = GridMarch(point, m_gridMarch.get_direction());
    set_render_data();
}

void GridMarchDrawable::set_direction(glm::vec2 direction)
{
    m_gridMarch = GridMarch(m_gridMarch.get_point(), direction);
    set_render_data();
}

void GridMarchDrawable::set_render_data() {
    m_pointDrawable.set_point(m_gridMarch.get_point());
    std::vector<glm::vec2> polyline({m_gridMarch.get_point(), m_gridMarch.get_point() + m_gridMarch.get_direction()});
    m_raysDrawable.set_rays(polyline);
}

void GridMarchDrawable::march() {
    m_gridMarch.march();
    set_render_data();
}

void GridMarchDrawable::draw(float screenWidth, float screenHeight, float zoom) {
    m_pointDrawable.draw(screenWidth, screenHeight, zoom);
    m_raysDrawable.draw(screenWidth, screenHeight, zoom);
}