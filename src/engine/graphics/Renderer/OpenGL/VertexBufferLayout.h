#pragma once
#include <cstdint>
#include <string>
#include <vector>

namespace Engine
{
    // TODO: Maybe move this into another file since it doesn't belong here!
    enum class DataType
    {
        None = 0,
        Float,
        Int,
        Bool
    };

    static uint32_t GetDataTypeSize(DataType type)
    {
        switch (type)
        {
            case DataType::Float: return 4;
            case DataType::Int: return 4;
            case DataType::Bool: return 1;
            default: return 0;
        }
    }

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

        inline std::vector<VertexBufferElement> GetElementsArray() const { return m_Elements; }
        inline uint32_t GetStride() const { return m_Stride; }

    private:
        std::vector<VertexBufferElement> m_Elements;
        uint32_t m_Stride;
    };
}

