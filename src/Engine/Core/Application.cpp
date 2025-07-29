#include "Application.h"

namespace Engine
{
    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
        // TODO: Assert if application already exist

        // Assign the instance to this instance
        s_Instance = this;

        // Create a window
        m_Window = new Window(640, 480, "Engine");
    }

    Application::~Application()
    {
        delete m_Window;
        s_Instance = nullptr;
    }
};

