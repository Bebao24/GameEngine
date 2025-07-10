#include "log.h"
#include <cstdarg>
#include <cstdio>
#include <iostream>

namespace Engine
{
    static bool loggerInitialized = false;

    void Logger::Init()
    {
        if (loggerInitialized) return;

        // Functions like Log() will check if logger is initialized
        // If not, it will not print anything
        loggerInitialized = true;
    }

    const char* Logger::LevelToString(LogLevel level)
    {
        switch (level)
        {
            case LogLevel::Trace:    return "TRACE";
            case LogLevel::Info:     return "INFO";
            case LogLevel::Warn:     return "WARN";
            case LogLevel::Error:    return "ERROR";
            case LogLevel::Critical: return "CRITICAL";
            default: return "UNKNOWN";
        }
    }

    void Logger::Log(LogLevel level, const char* fmt, ...)
    {
        if (!loggerInitialized) return;

        char message[1024];

        va_list args;
        va_start(args, fmt);
        vsnprintf(message, 1024, fmt, args);
        va_end(args);

        // Print the final message
        std::cout << "[" << LevelToString(level) << "] " << message << std::endl;
    }
}

