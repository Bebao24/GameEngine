#pragma once
#include "Event.h"

namespace Engine
{
    class WindowResizedEvent : public Event
    {
    public:
    WindowResizedEvent(int width, int height)
            :m_Width(width), m_Height(height) {}

        int GetWidth() const { return m_Width; }
        int GetHeight() const { return m_Height; }

        EventType GetEventType() const override { return EventType::WindowResized; }
        const char* GetEventName() const override { return "WindowResizedEvent"; }

    private:
        int m_Width, m_Height;
    };
};
