#pragma once
#include <glm/glm.hpp>

enum Axis {
    NoAxis = -1,
    XAxis,
    YAxis
};

class GridMarch {
public:
    GridMarch(glm::vec2 origin, glm::vec2 direction);
    float march();
    glm::vec2 get_point() const {return m_point;}
    glm::ivec2 get_curr_cell() const {return m_cell;}
    glm::ivec2 get_prev_cell() const;

private:
    glm::vec2 m_point;
    glm::vec2 m_direction;
    glm::ivec2 m_cell;
    Axis m_interfaceAxis;
};