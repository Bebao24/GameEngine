#pragma once
#include <cstdint>

namespace Engine
{
    enum class DataType
    {
        None = 0,
        Float,
        Int,
        Bool
    };

    uint32_t GetDataTypeSize(DataType type);
    uint32_t GetOpenGLType(DataType type);
}

