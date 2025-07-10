#include "VertexBufferLayout.h"

namespace Engine
{
    VertexBufferLayout::VertexBufferLayout()
    {
        // Resetting the stride
        m_Stride = 0;
    }

    void VertexBufferLayout::AddElement(DataType type, uint32_t count, std::string name)
    {
        m_Elements.push_back({ type, count, false, name });
        m_Stride += GetDataTypeSize(type);
    }
}

