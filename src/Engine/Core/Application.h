#pragma once
#include <Engine/Engine.h>

namespace Engine
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        static Application& Get() { return *s_Instance; }

        virtual void OnEvent(Event& event) = 0;

        Window& GetWindow() const { return *m_Window; }
        Camera& GetCamera() const { return *m_Camera; }

    private:
        static Application* s_Instance;

        Window* m_Window;
        Camera* m_Camera;
    };
};

