#pragma once
#include <cstdint>

namespace Engine
{
    class IndexBuffer
    {
    public:
        IndexBuffer(const uint32_t* data, uint32_t count);
        ~IndexBuffer();

        void Bind() const;
        void Unbind() const;
    private:
        uint32_t m_BufferId;
    };
}


