#pragma once

namespace Engine
{
    enum class EventType
    {
        None = 0,
        WindowClose,
        KeyPressed,
        MouseMoved,
        MouseButton,
        MouseScrolled
    };

    class Event
    {
    public:
        virtual EventType GetEventType() const = 0;
        virtual const char* GetEventName() const = 0;
        virtual ~Event() = default;
    };
}

