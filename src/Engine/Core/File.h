#pragma once
#include <string>
#include <cstdint>

namespace Engine
{
    class File
    {
    public:
        static std::string ReadFile(const std::string& filePath);
        static uint64_t GetFileSize(const std::string& filePath);
    };
}

