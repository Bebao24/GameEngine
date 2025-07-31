#pragma once
#include <string>
#include <cstdint>
#include <vector>

namespace Engine
{
    class File
    {
    public:
        static std::string ReadFile(const std::string& filePath);
        static uint64_t GetFileSize(const std::string& filePath);
        static std::vector<uint8_t> ReadBinaryFile(const std::string& filePath);
    };
}

