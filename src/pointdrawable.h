#pragma once
#include <glm/glm.hpp>
#include "shaderprogram.h"

class PointDrawable {
public:
    PointDrawable() : PointDrawable(glm::vec2()) {};
    PointDrawable(glm::vec2 point);
    void draw(float screenWidth, float screenHeight);
    glm::vec2& get_point() {return m_point; }

private:
    glm::vec2 m_point;
    ShaderProgram m_shader;
    GLuint u_position;
};