#pragma once

namespace Engine
{
    enum class EventType
    {
        None = 0,
        WindowResized,
        KeyPressed,
        MouseMoved,
        MouseButtonPressed,
        MouseButtonReleased,
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

