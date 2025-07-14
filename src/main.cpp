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

    float quadX = 100.0f;
    float quadY = 100.0f;

    float velocity = 1.5f;

    while (!window.WindowShouldClose())
    {
        if (Engine::Input::IsKeyPressed(ENGINE_KEY_W))
        {
            quadY += velocity;
        }
        if (Engine::Input::IsKeyPressed(ENGINE_KEY_S))
        {
            quadY -= velocity;
        }
        if (Engine::Input::IsKeyPressed(ENGINE_KEY_A))
        {
            quadX -= velocity;
        }
        if (Engine::Input::IsKeyPressed(ENGINE_KEY_D))
        {
            quadX += velocity;
        }
        
        Engine::Renderer::Clear(0.0f, 0.0f, 0.0f);

        Engine::Renderer2D::DrawQuad(quadX, quadY, 100.0f, 100.0f);

        window.SwapBuffers();

        window.PollEvents();
    }

    // Clean up
    Engine::Renderer::Shutdown();

    return 0;
}