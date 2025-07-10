#pragma once
#include <cstdint>
#include <string>
#include <vector>

#include <glad/glad.h>
#include <Engine/Core/DataType.h>

namespace Engine
{
    struct VertexBufferElement
    {
        DataType type; // Data type
        uint32_t count;
        bool normalized;

        // Just for debugging and to make it readable
        std::string name;
    };

    class VertexBufferLayout
    {
    public:
        VertexBufferLayout();
        ~VertexBufferLayout() = default;

        void AddElement(DataType type, uint32_t count, std::string name);

        inline const std::vector<VertexBufferElement>& GetElementsArray() const { return m_Elements; }
        inline uint32_t GetStride() const { return m_Stride; }

    private:
        std::vector<VertexBufferElement> m_Elements;
        uint32_t m_Stride;
    };
}

