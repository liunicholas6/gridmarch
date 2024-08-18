#include "raysdrawable.h"
#include <iostream>

RaysDrawable::RaysDrawable() : m_shaderProgram("rays.vert", "rays.frag"), m_numNumVerts(0)
{
    glGenVertexArrays(1, &m_vao);
    glGenBuffers(1, &m_vbo);
    glGenBuffers(1, &m_ebo);

    glBindVertexArray(m_vao);
    glEnableVertexAttribArray(0);

    m_u_zoom_over_dims = m_shaderProgram.get_uniform_location("u_zoom_over_dims");
}

void RaysDrawable::set_rays(const std::vector<glm::vec2>& polyline) {
    glBindVertexArray(m_vao);

    const float width = 0.05;
    const float arrowHeadWidth = 0.15;
    const float arrowHeadLength = 0.2;
    std::vector<glm::vec2> vertices;
    for (size_t i = 0; i < polyline.size() - 1; i++) {
        glm::vec2 a = polyline[i];
        glm::vec2 b = polyline[i + 1];
        glm::vec2 tangent = glm::normalize(b - a);
        glm::vec2 normal(-tangent.y, tangent.x);

        glm::vec2 widthNormal = width * normal;
        vertices.push_back(a + widthNormal);
        vertices.push_back(a - widthNormal);

        glm::vec2 c = b - arrowHeadLength * tangent;
        vertices.push_back(c + widthNormal);
        vertices.push_back(c - widthNormal);

        glm::vec2 headWidthNormal = arrowHeadWidth * normal;
        vertices.push_back(c + headWidthNormal);
        vertices.push_back(c - headWidthNormal);
        vertices.push_back(b);
    }

    std::initializer_list<GLuint> arrowIxs = {0, 1, 2, 2, 1, 3, 4, 5, 6};

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * vertices.size(), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

    std::vector<GLuint> ixs;
    for (size_t i = 0; i < polyline.size() - 1; i++) {
        for (GLuint ix : arrowIxs) {
            ixs.push_back(i * 6 + ix);
        }
    }
    m_numNumVerts = ixs.size();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * ixs.size(), ixs.data(), GL_STATIC_DRAW);
}

void RaysDrawable::draw(float screenWidth, float screenHeight, float zoom)
{
    m_shaderProgram.use_me();
    glLineWidth(100);
    glUniform2f(m_u_zoom_over_dims, zoom / screenWidth, zoom / screenHeight);
    glBindVertexArray(m_vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glDrawElements(GL_TRIANGLES, m_numNumVerts, GL_UNSIGNED_INT, 0);
}
