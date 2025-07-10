#include "VertexArray.h"
#include <glad/glad.h>

namespace Engine
{
    static GLenum GetOpenGLType(DataType type)
    {
        switch (type)
        {
            case DataType::Float: return GL_FLOAT;
            case DataType::Int: return GL_INT;
            case DataType::Bool: return GL_BOOL;
            default: return 0;
        }
    }

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

    void VertexArray::Bind() const
    {
        glBindVertexArray(m_ArrayId);
    }

    void VertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }
}
