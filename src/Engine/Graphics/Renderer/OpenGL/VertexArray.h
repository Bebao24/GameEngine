#pragma once
#include "VertexBufferLayout.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include <memory>

namespace Engine
{
    class VertexArray
    {
    public:
        VertexArray();
        ~VertexArray();

        void AddVertexBuffer(const VertexBuffer& buffer, const VertexBufferLayout& layout);
        void SetIndexBuffer(const IndexBuffer& buffer);

        const std::shared_ptr<IndexBuffer> GetIndexBuffer() const { return m_IndexBuffer; }
        
        void Bind() const;
        void Unbind() const;

    private:
        uint32_t m_ArrayId;
        std::shared_ptr<IndexBuffer> m_IndexBuffer;
    };    
}

