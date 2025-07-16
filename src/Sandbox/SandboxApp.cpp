#include "SandboxApp.h"

SandboxApp::SandboxApp()
    :m_Window(640, 480, "Engine")
{

}

SandboxApp::~SandboxApp()
{

}

void SandboxApp::Start()
{
    // Initialize everything

    Engine::Input::Init(&m_Window);
    Engine::Renderer::Init(&m_Window);
}

void SandboxApp::Update(float deltaTime)
{
    (void)deltaTime;
    Engine::Renderer2D::DrawCircle({50.0f}, 25.0f, {1.0f, 0.0f, 0.0f, 1.0f});
}

