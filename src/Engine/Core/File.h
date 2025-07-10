#pragma once
#include <string>

namespace Engine
{
    class File
    {
    public:
        static std::string ReadFile(const std::string& filePath);
    };
}

