#include "Shader.h"
#include <glad/glad.h>
#include <Engine/Core/File.h>

namespace Engine
{
    Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
    {
        // Read the vertex & fragment shaders files
        std::string vertexContent = File::ReadFile(vertexPath);
        std::string fragmentContent = File::ReadFile(fragmentPath);
        // TODO: Error handling if failed to open vertex & fragment shaders files

        // Create the shader program
        uint32_t programId = CreateShader(vertexContent, fragmentContent);
        m_ProgramId = programId;
    }

    Shader::~Shader()
    {
        glDeleteProgram(m_ProgramId);
    }

    uint32_t Shader::CompileShader(uint32_t type, const std::string& shaderSrc)
    {
        uint32_t id = glCreateShader(type);
        const char* src = shaderSrc.c_str(); // Get the actual string from shaderSrc
        glShaderSource(id, 1, &src, nullptr);
        glCompileShader(id);

        // TODO: Error handling

        return id;
    }

    void Shader::Bind() const
    {
        glUseProgram(m_ProgramId);
    }

    void Shader::Unbind() const
    {
        glUseProgram(0);
    }

    uint32_t Shader::CreateShader(const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        // Create the shader program
        uint32_t program = glCreateProgram();

        // Create vertex, fragment shaders
        uint32_t vertexShaderId = CompileShader(GL_VERTEX_SHADER, vertexSrc);
        uint32_t fragmentShaderId = CompileShader(GL_FRAGMENT_SHADER, fragmentSrc);

        glAttachShader(program, vertexShaderId);
        glAttachShader(program, fragmentShaderId);
        glLinkProgram(program);
        glValidateProgram(program);

        // We don't need the shaders anymore
        glDeleteShader(vertexShaderId);
        glDeleteShader(fragmentShaderId);

        return program;
    }
}

