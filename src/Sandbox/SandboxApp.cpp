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

    [[maybe_unused]] int windowWidth = m_Window.GetWidth();
    [[maybe_unused]] int windowHeight = m_Window.GetHeight();

    // Create a camera
    m_Camera = Engine::Camera(0.0f, (float)windowWidth, 0.0f, (float)windowHeight);

    // Load in a texture
    m_Texture.Load("Assets/Textures/OpenGL.png");
}

void SandboxApp::Update(float deltaTime)
{
    Engine::Math::Vector2 cameraPos = m_Camera.GetPosition();
    if (Engine::Input::IsKeyPressed(ENGINE_KEY_W))
    {
        cameraPos.y -= 200.0f * deltaTime;
    }
    if (Engine::Input::IsKeyPressed(ENGINE_KEY_S))
    {
        cameraPos.y += 200.0f * deltaTime;
    }
    if (Engine::Input::IsKeyPressed(ENGINE_KEY_A))
    {
        cameraPos.x -= 200.0f * deltaTime;
    }
    if (Engine::Input::IsKeyPressed(ENGINE_KEY_D))
    {
        cameraPos.x += 200.0f * deltaTime;
    }

    m_Camera.SetPosition(cameraPos);

    Engine::Renderer2D::BeginScene(m_Camera);

    Engine::Renderer2D::DrawCircle({50.0f}, 25.0f, {1.0f, 0.0f, 0.0f, 1.0f});
    Engine::Renderer2D::DrawQuad({100.0f}, {50.0f}, {1.0f, 1.0f, 0.0f, 1.0f});
    Engine::Renderer2D::DrawQuad({400.0f}, {150.0f}, m_Texture);

    Engine::Renderer2D::EndScene();
}

void SandboxApp::OnEvent(Engine::Event& event)
{

}

