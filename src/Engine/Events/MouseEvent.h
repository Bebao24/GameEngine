#pragma once
#include "Event.h"

namespace Engine
{
    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(float x, float y)
            :m_mouseX(x), m_mouseY(y) {}
            
        float GetMouseX() const { return m_mouseX; }
        float GetMouseY() const { return m_mouseY; }
        
        EventType GetEventType() const override { return EventType::MouseMoved; }
        const char* GetEventName() const override { return "MousedMovedEvent"; }

    private:
        float m_mouseX, m_mouseY;
    };
};

