#pragma once
#include "../shaderprogram.h"
#include <glm/glm.hpp>

class RaysDrawable {
public:
    RaysDrawable();
    void set_rays(const std::vector<glm::vec2>& polyline);
    void draw(float screenWidth, float screenHeight, float zoom);
private:
    ShaderProgram m_shaderProgram;
    GLuint m_vao;
    GLuint m_vbo;
    GLuint m_ebo;
    GLuint m_u_zoom_over_dims;
    size_t m_numNumVerts;
};