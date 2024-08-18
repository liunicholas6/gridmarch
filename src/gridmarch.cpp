#include "gridmarch.h"
#include <initializer_list>
#include <stdexcept>

GridMarch::GridMarch() : GridMarch(glm::vec2(0, 0), glm::vec2(1, 0)) {}

GridMarch::GridMarch(glm::vec2 origin, glm::vec2 direction)
    : m_point(origin), m_direction(glm::normalize(direction)), m_cell(glm::ivec2(glm::floor(origin)))
    , m_interfaceAxis(NoAxis)
{}

float GridMarch::march()
{
    float minT = std::numeric_limits<float>::max();
    Axis interfaceAxis = NoAxis;
    for (Axis axis : {XAxis, YAxis}) {
        if (m_direction[axis] == 0) {
            continue;
        }
        int nextIntercept = m_cell[axis];
        if (m_direction[axis] > 0) {
            nextIntercept++;
        }
        float axisT = (nextIntercept - m_point[axis]) / m_direction[axis];
        if (axisT < minT) {
            minT = axisT;
            interfaceAxis = axis;
        }
    }
    m_point += m_direction * minT;
    m_cell[interfaceAxis] += glm::sign(m_direction[interfaceAxis]);
    return minT;
}

glm::ivec2 GridMarch::get_prev_cell() const {
    if (m_interfaceAxis == NoAxis) {
        throw std::runtime_error("get_prev_cell() : No previous cell exists");
    }
    glm::ivec2 prev_cell = m_cell;
    prev_cell[m_interfaceAxis] -= glm::sign(m_direction[m_interfaceAxis]);
    return prev_cell;
}