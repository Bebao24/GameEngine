#include "Application.h"

namespace Engine
{
    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
        // TODO: Assert if application already exist

        // Assign the instance to this instance
        s_Instance = this;
    }

    Application::~Application()
    {
        s_Instance = nullptr;
    }
};

