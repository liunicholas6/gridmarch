#pragma once
#include <glad/glad.h>
#include "shaderprogram.h"

class Grid {
public:
    Grid();
    ~Grid();
    void draw(float width, float height, float zoom) const;

private:
    ShaderProgram m_shaderProgram;
    GLuint m_vao;
    GLuint m_vbo;
    GLuint m_ebo;
    GLuint m_u_dimensions;
};