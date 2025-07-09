#pragma once

namespace Engine
{
    enum class LogLevel
    {
        Trace,
        Info,
        Warn,
        Error,
        Critical
    };

    class Logger
    {
    public:
        static void Init();
        static void Log(LogLevel level, const char* fmt, ...);
    private:
        static const char* LevelToString(LogLevel level);
    };
}

#define ENGINE_LOG_TRACE(...) ::Engine::Logger::Log(::Engine::LogLevel::Trace, __VA_ARGS__)
#define ENGINE_LOG_INFO(...) ::Engine::Logger::Log(::Engine::LogLevel::Info, __VA_ARGS__)
#define ENGINE_LOG_WARN(...) ::Engine::Logger::Log(::Engine::LogLevel::Warn, __VA_ARGS__)
#define ENGINE_LOG_ERROR(...) ::Engine::Logger::Log(::Engine::LogLevel::Error, __VA_ARGS__)
#define ENGINE_LOG_CRITICAL(...) ::Engine::Logger::Log(::Engine::LogLevel::Critical, __VA_ARGS__)


