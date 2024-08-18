#include "grid.h"
#include "quad.h"

Grid::Grid() : m_shaderProgram("grid.vert", "grid.frag")
{
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);

    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quad::vertices), &quad::vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &m_ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(quad::indices), &quad::indices, GL_STATIC_DRAW);

    m_u_dimensions = m_shaderProgram.get_uniform_location("u_dimensions");
}

void Grid::draw(float width, float height, float zoom) const
{
    m_shaderProgram.use_me();
    glBindVertexArray(m_vao);
    glUniform2f(m_u_dimensions, width / zoom, height / zoom);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

Grid::~Grid()
{
    glDeleteBuffers(1, &m_vbo);
    glDeleteBuffers(1, &m_ebo);
    glDeleteVertexArrays(1, &m_vao);
}