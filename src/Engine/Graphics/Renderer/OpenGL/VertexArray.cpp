#include "VertexArray.h"
#include <glad/glad.h>
#include <Engine/Core/DataType.h>

namespace Engine
{
    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &m_ArrayId);
        glBindVertexArray(m_ArrayId);
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &m_ArrayId);
    }

    void VertexArray::AddVertexBuffer(const VertexBuffer& buffer, const VertexBufferLayout& layout)
    {
        buffer.Bind();

        const auto& elements = layout.GetElementsArray(); // Elements array
        uint64_t offset = 0;

        for (uint32_t i = 0; i < elements.size(); i++)
        {
            const auto& element = elements[i];
            
            // Setup the vertex buffer layout
            glEnableVertexAttribArray(i);
            glVertexAttribPointer(i, element.count, GetOpenGLType(element.type), element.normalized, layout.GetStride(), (const void*)offset);
            offset += element.count * GetDataTypeSize(element.type);
        }

        buffer.Unbind();
    }

    void VertexArray::SetIndexBuffer(const IndexBuffer& buffer)
    {
        Bind();

        buffer.Bind();
        m_IndexBuffer = std::make_shared<IndexBuffer>(buffer);
    }

    void VertexArray::Bind() const
    {
        glBindVertexArray(m_ArrayId);
    }

    void VertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }
}
