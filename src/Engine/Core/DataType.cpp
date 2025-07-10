#include "DataType.h"
#include <glad/glad.h>

namespace Engine
{
    uint32_t GetDataTypeSize(DataType type)
    {
        switch (type)
        {
            case DataType::Float: return 4;
            case DataType::Int: return 4;
            case DataType::Bool: return 1;
            default: return 0;
        }
    }

    uint32_t GetOpenGLType(DataType type)
    {
        switch (type)
        {
            case DataType::Float: return GL_FLOAT;
            case DataType::Int: return GL_INT;
            case DataType::Bool: return GL_BOOL;
            default: return 0;
        }
    }
}

