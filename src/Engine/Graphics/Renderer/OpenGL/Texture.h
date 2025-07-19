#pragma once
#include <string>
#include <cstdint>

namespace Engine
{
    class Texture
    {
    public:
        Texture(const std::string& path);
        ~Texture();

        void Bind(uint32_t slot = 0) const;
        void Unbind() const;

        inline int GetWidth() { return m_Width; }
        inline int GetHeight() { return m_Height; }

    private:
        uint32_t m_TextureId;
        std::string m_Path; // For debugging
        uint8_t* m_TextureBuffer; // Store all the texture's pixels
        int m_Width, m_Height, m_BPP;
    };
}

