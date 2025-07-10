#pragma once
#include <cstdint>

namespace Engine
{
    class IndexBuffer
    {
    public:
        IndexBuffer(const uint32_t* data, uint32_t count);
        ~IndexBuffer();

        uint32_t GetCount() const { return m_Count; }

        void Bind() const;
        void Unbind() const;
    private:
        uint32_t m_BufferId;
        uint32_t m_Count;
    };
}


