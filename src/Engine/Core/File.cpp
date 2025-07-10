#include "File.h"
#include <fstream>
#include <Engine/Core/Log.h>

namespace Engine
{
    std::string File::ReadFile(const std::string& filePath)
    {
        // Open the file
        std::ifstream file(filePath);

        // Check for errors
        if (!file.is_open())
        {
            ENGINE_LOG_ERROR("Failed to open file %s", filePath);
            return 0;
        }

        // Read the contentn
        std::string line;
        std::string content;
        while (std::getline(file, line))
        {
            content.append(line);
            content.append("\n");
        }

        // Close the file
        file.close();
        return content;
    }
}

