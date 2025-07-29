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

        // Initialize everything
        Engine::Input::Init(m_Window);
        Engine::Renderer::Init(m_Window);

        // Create a camera
        int windowWidth = m_Window->GetWidth();
        int windowHeight = m_Window->GetHeight();
        m_Camera = new Camera(0.0f, (float)windowWidth, 0.0f, (float)windowHeight);
    }

    Application::~Application()
    {
        delete m_Window;
        s_Instance = nullptr;
    }
};

