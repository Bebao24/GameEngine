#pragma once
#include <Engine/Engine.h>

class SandboxApp
{
public:
    SandboxApp();
    ~SandboxApp();

    void Start();
    void Update(float deltaTime);

    Engine::Window& GetWindow() { return m_Window; }

private:
    Engine::Window m_Window;
    Engine::Camera m_Camera;
};


