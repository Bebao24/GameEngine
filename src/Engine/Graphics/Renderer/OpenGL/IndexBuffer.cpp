#include "IndexBuffer.h"
#include <glad/glad.h>

namespace Engine
{
    IndexBuffer::IndexBuffer(const uint32_t* data, uint32_t count)
    {
        glGenBuffers(1, &m_BufferId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * count, data, GL_STATIC_DRAW);
    }

    IndexBuffer::~IndexBuffer()
    {
        glDeleteBuffers(1, &m_BufferId);
    }

    void IndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferId);
    }

    void IndexBuffer::Unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}

