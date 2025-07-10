#pragma once
#include "VertexBufferLayout.h"
#include "VertexBuffer.h"

namespace Engine
{
    class VertexArray
    {
    public:
        VertexArray();
        ~VertexArray();

        void AddVertexBuffer(const VertexBuffer& buffer, const VertexBufferLayout& layout);
        
        void Bind() const;
        void Unbind() const;

    private:
        uint32_t m_ArrayId;
    };
    
}

