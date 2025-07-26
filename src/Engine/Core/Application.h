#pragma once
#include <Engine/Events/Event.h>

namespace Engine
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        static Application& Get() { return *s_Instance; }

        virtual void OnEvent(Event& event) = 0;

    private:
        static Application* s_Instance;
    };
};

