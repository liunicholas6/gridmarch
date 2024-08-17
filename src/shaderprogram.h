#pragma once
#include "shader.h"

class ShaderProgram {
    private:
        GLuint m_handle;
    public:
        ShaderProgram(const char *, const char*);
        ShaderProgram(const Shader<GL_VERTEX_SHADER> &vertexShader, const Shader<GL_FRAGMENT_SHADER> &fragmentShader);
        void use_me() const;
        GLuint get_uniform_location(const char *) const;
};