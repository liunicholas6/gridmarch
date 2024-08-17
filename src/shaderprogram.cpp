#include "shaderprogram.h"
#include <iostream>

ShaderProgram::ShaderProgram(const char* vertexFile, const char* fragmentFile)
    : ShaderProgram(Shader<GL_VERTEX_SHADER>(vertexFile), Shader<GL_FRAGMENT_SHADER>(fragmentFile)) {

}

ShaderProgram::ShaderProgram(const Shader<GL_VERTEX_SHADER>& vertexShader, const Shader<GL_FRAGMENT_SHADER>& fragmentShader)
{
    m_handle = glCreateProgram();
    glAttachShader(m_handle, vertexShader.m_handle);
    glAttachShader(m_handle, fragmentShader.m_handle);
    glLinkProgram(m_handle);
    // check for linking errors
    int success;
    char infoLog[512];
    glGetProgramiv(m_handle, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(m_handle, 512, NULL, infoLog);
        std::cerr << "Failed to link shader program\n" << infoLog << std::endl;
    }
}

void ShaderProgram::use_me() const {
    glUseProgram(m_handle);
}

GLuint ShaderProgram::get_uniform_location(const char *s) const {
    return glGetUniformLocation(m_handle, s);
}