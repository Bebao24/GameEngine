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
        void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);

        void Bind() const;
        void Unbind() const;
    private:
        uint32_t CompileShader(uint32_t type, const std::string& shaderSrc);
        uint32_t CreateShader(const std::string& vertexSrc, const std::string& fragmentSrc);
        
        uint32_t GetUniformLocation(const std::string& name);

        uint32_t m_ProgramId;
    };
}

