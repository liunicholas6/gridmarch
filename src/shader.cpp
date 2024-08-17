#include "shader.h"
#include <fstream>
#include <iostream>

template<GLenum ShaderType>
Shader<ShaderType>::Shader(std::string filePath)
{
    m_handle = glCreateShader(ShaderType);
    std::ifstream file("../shaders/" + filePath);
    std::string contents((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    char* shaderSource = contents.data();
    glShaderSource(m_handle, 1, &shaderSource, NULL);
    glCompileShader(m_handle);
    
    int success;
    char infoLog[512];
    glGetShaderiv(m_handle, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(m_handle, 512, NULL, infoLog);
        std::cerr << "Failed to compile shader " << filePath << "\n" << infoLog << std::endl;
    }
}

template<GLenum ShaderType>
Shader<ShaderType>::~Shader()
{
    glDeleteShader(m_handle);
}

template class Shader<GL_VERTEX_SHADER>;
template class Shader<GL_FRAGMENT_SHADER>;
