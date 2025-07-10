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

        void Bind() const;
        void Unbind() const;
    private:
        uint32_t CompileShader(uint32_t type, const std::string& shaderSrc);
        uint32_t CreateShader(const std::string& vertexSrc, const std::string& fragmentSrc);

        uint32_t m_ProgramId;
    };
}

