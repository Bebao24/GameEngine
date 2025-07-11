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

    void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
    {
        glUniform4f(GetUniformLocation(name), v0, v1, v2, v3);
    }

    void Shader::SetUniform3f(const std::string& name, float v0, float v1, float v2)
    {
        glUniform3f(GetUniformLocation(name), v0, v1, v2);
    }

    void Shader::SetUniform2f(const std::string& name, float v0, float v1)
    {
        glUniform2f(GetUniformLocation(name), v0, v1);
    }

    void Shader::SetUniform1f(const std::string& name, float v0)
    {
        glUniform1f(GetUniformLocation(name), v0);
    }

    void Shader::SetUniform4i(const std::string& name, int v0, int v1, int v2, int v3)
    {
        glUniform4i(GetUniformLocation(name), v0, v1, v2, v3);
    }

    void Shader::SetUniform3i(const std::string& name, int v0, int v1, int v2)
    {
        glUniform3i(GetUniformLocation(name), v0, v1, v2);
    }

    void Shader::SetUniform2i(const std::string& name, int v0, int v1)
    {
        glUniform2i(GetUniformLocation(name), v0, v1);
    }

    void Shader::SetUniform1i(const std::string& name, int v0)
    {
        glUniform1i(GetUniformLocation(name), v0);
    }

    void Shader::SetUniformMat4f(const std::string& name, const glm::mat4& trans)
    {
        // glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &trans[0][0]);
        glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(trans));
    }

    uint32_t Shader::GetUniformLocation(const std::string& name)
    {
        // Check for the name location in the cache
        if (m_UniformCache.find(name) != m_UniformCache.end())
        {
            return m_UniformCache[name];
        }

        int location = glGetUniformLocation(m_ProgramId, name.c_str());
        if (location == -1)
        {
            ENGINE_LOG_WARN("Uniform %s doesn't exist!");
        }

        // Add the name in the cache
        m_UniformCache[name] = location;
        return location;
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

