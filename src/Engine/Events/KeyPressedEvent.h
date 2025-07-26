#pragma once
#include "Event.h"

namespace Engine
{
    class KeyPressedEvent : public Event
    {
    public:

        KeyPressedEvent(int keyCode)
            :keyCode(keyCode) {}

        EventType GetEventType() const override { return EventType::KeyPressed; }
        const char* GetEventName() const override { return "KeyPressedEvent"; }

        int GetKeyCode() const { return keyCode; }
        
    private:
        int keyCode;
    };
};
