#include "VertexBuffer.h"
#include <glad/glad.h>

namespace Engine
{
    VertexBuffer::VertexBuffer(const void* data, uint32_t size)
    {
        glGenBuffers(1, &m_BufferId);
        glBindBuffer(GL_ARRAY_BUFFER, m_BufferId);
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }

    VertexBuffer::~VertexBuffer()
    {
        glDeleteBuffers(1, &m_BufferId);
    }

    void VertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_BufferId);
    }

    void VertexBuffer::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}

