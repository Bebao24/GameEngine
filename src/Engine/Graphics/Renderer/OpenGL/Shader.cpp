#include "Shader.h"
#include <glad/glad.h>
#include <Engine/Core/File.h>
#include <Engine/Core/Log.h>

namespace Engine
{
    Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
    {
        // Read the vertex & fragment shaders files
        std::string vertexContent = File::ReadFile(vertexPath);
        std::string fragmentContent = File::ReadFile(fragmentPath);

        if (vertexContent.empty())
        {
            return;
        }

        if (fragmentContent.empty())
        {
            return;
        }

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

        // Error handling
        int success;
        glGetShaderiv(id, GL_COMPILE_STATUS, &success);

        if (!success)
        {
            // Get the error message's length
            int len;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);

            // Allocate memory for the buffer
            char* messageBuffer = (char*)malloc(len * sizeof(char));
            // Copy the error message
            glGetShaderInfoLog(id, len, &len, messageBuffer);
            ENGINE_LOG_ERROR("Failed to compile %s shader!\n", (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment"));
            ENGINE_LOG_ERROR("Error: %s", messageBuffer);
            glDeleteShader(id);
            return 0;
        }

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

