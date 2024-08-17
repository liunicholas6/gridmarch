#pragma once
#include <string>
#include <glad/glad.h>

class ShaderProgram;

template<GLenum ShaderType>
class Shader {
friend class ShaderProgram;

private:
    GLuint m_handle;

public:
    Shader(std::string filePath);
    ~Shader();
};

extern template class Shader<GL_VERTEX_SHADER>;
extern template class Shader<GL_FRAGMENT_SHADER>;