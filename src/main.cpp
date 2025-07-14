#include <iostream>
#include <Engine/Engine.h>

int main()
{
    Engine::Logger::Init();

    // Create the window
    Engine::Window window(640, 480, "Engine");

    Engine::Input::Init(&window);

    // Initialize Renderer
    Engine::Renderer::Init(&window);

    Engine::Math::Vector2 quadPos(100.0f);

    float velocity = 1.5f;

    while (!window.WindowShouldClose())
    {
        if (Engine::Input::IsKeyPressed(ENGINE_KEY_W))
        {
            quadPos.y += velocity;
        }
        if (Engine::Input::IsKeyPressed(ENGINE_KEY_S))
        {
            quadPos.y -= velocity;
        }
        if (Engine::Input::IsKeyPressed(ENGINE_KEY_A))
        {
            quadPos.x -= velocity;
        }
        if (Engine::Input::IsKeyPressed(ENGINE_KEY_D))
        {
            quadPos.x += velocity;
        }
        
        Engine::Renderer::Clear(0.0f, 0.0f, 0.0f);

        Engine::Renderer2D::DrawQuad(quadPos, {100.0f}, {1.0f, 1.0f, 0.0f, 1.0f});

        window.SwapBuffers();

        window.PollEvents();
    }

    // Clean up
    Engine::Renderer::Shutdown();

    return 0;
}