#pragma once
#include <cstdint>
#include <string>

namespace Engine
{
    class Shader
    {
    public:
        Shader(const std::string& vertexPath, const std::string& fragmentPath);
        ~Shader();

        // Modifying Uniform functions
        // Floats
        void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
        void SetUniform3f(const std::string& name, float v0, float v1, float v2);
        void SetUniform2f(const std::string& name, float v0, float v1);
        void SetUniform1f(const std::string& name, float v0);

        // Integers
        void SetUniform4i(const std::string& name, int v0, int v1, int v2, int v3);
        void SetUniform3i(const std::string& name, int v0, int v1, int v2);
        void SetUniform2i(const std::string& name, int v0, int v1);
        void SetUniform1i(const std::string& name, int v0);
        

        void Bind() const;
        void Unbind() const;
    private:
        uint32_t CompileShader(uint32_t type, const std::string& shaderSrc);
        uint32_t CreateShader(const std::string& vertexSrc, const std::string& fragmentSrc);
        
        uint32_t GetUniformLocation(const std::string& name);

        uint32_t m_ProgramId;
    };
}

