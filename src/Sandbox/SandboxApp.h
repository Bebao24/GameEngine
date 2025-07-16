#pragma once
#include <Engine/Engine.h>

class SandboxApp
{
public:
    SandboxApp();
    ~SandboxApp();

    void Start();
    void Update();

    Engine::Window& GetWindow() { return m_Window; }

private:
    Engine::Window m_Window;
};


