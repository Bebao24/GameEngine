#include "Texture.h"
#include <glad/glad.h>
#include <stb_image.h>

namespace Engine
{
    Texture::Texture(const std::string& path)
        :m_TextureId(0), m_Path(path), m_TextureBuffer(nullptr), m_Width(0), m_Height(0), m_BPP(0)
    {
        stbi_set_flip_vertically_on_load(1);
        // Load the texture
        m_TextureBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4);

        glGenTextures(1, &m_TextureId);
        glBindTexture(GL_TEXTURE_2D, m_TextureId);

        // Setup texture parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_TextureBuffer);
        glBindTexture(GL_TEXTURE_2D, 0);

        // Finally, free the texture buffer
        if (m_TextureBuffer)
        {
            stbi_image_free(m_TextureBuffer);
        }
    }

    Texture::~Texture()
    {
        glDeleteTextures(1, &m_TextureId);
    }

    void Texture::Bind(uint32_t slot) const
    {
        glActiveTexture(GL_TEXTURE0 + slot); // Active the texture slot
        glBindTexture(GL_TEXTURE_2D, m_TextureId);
    }

    void Texture::Unbind() const
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}

