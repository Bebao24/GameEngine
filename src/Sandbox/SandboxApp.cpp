#include "SandboxApp.h"

void SandboxApp::Start()
{
    // Load in a texture
    m_Texture.Load("Assets/Textures/OpenGL.png");

    // Get the camera
    m_Camera = Application::Get().GetCamera();
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
    if (event.GetEventType() == Engine::EventType::KeyPressed)
    {
        auto& keyEvent = static_cast<Engine::KeyPressedEvent&>(event);
        (void)keyEvent;

        // ENGINE_LOG_TRACE("Key code: %d", keyEvent.GetKeyCode());
    }

    if (event.GetEventType() == Engine::EventType::MouseMoved)
    {
        auto& mouseEvent = static_cast<Engine::MouseMovedEvent&>(event);
        (void)mouseEvent;

        // ENGINE_LOG_TRACE("Mouse x: %f, y: %f", mouseEvent.GetMouseX(), mouseEvent.GetMouseY());
    }

    if (event.GetEventType() == Engine::EventType::MouseButtonPressed)
    {
        auto& mouseEvent = static_cast<Engine::MouseButtonPressedEvent&>(event);
        switch (mouseEvent.GetMouseButton())
        {
        case ENGINE_MOUSE_BUTTON_LEFT:
            ENGINE_LOG_TRACE("Mouse button left pressed!");
            break;
        case ENGINE_MOUSE_BUTTON_RIGHT:
            ENGINE_LOG_TRACE("Mouse button right pressed!");
            break;
        }
    }

    if (event.GetEventType() == Engine::EventType::MouseScrolled)
    {
        auto& mouseEvent = static_cast<Engine::MouseScrolledEvent&>(event);
        ENGINE_LOG_TRACE("Scrolled! X offset: %f, Y: %f", mouseEvent.GetXOffset(), mouseEvent.GetYOffset());
    }

    if (event.GetEventType() == Engine::EventType::WindowResized)
    {
        auto& windowEvent = static_cast<Engine::WindowResizedEvent&>(event);

        // Set the camera projection
        float windowWidth = (float)windowEvent.GetWidth();
        float windowHeight = (float)windowEvent.GetHeight();
        m_Camera.SetProjection(0, windowWidth, 0, windowHeight);

        ENGINE_LOG_TRACE("Window resized! New resolution: %dx%d", windowEvent.GetWidth(), windowEvent.GetHeight());
    }
}

