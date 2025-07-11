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

    float squareX = 100.0f;
    float squareY = 100.0f;

    float velocity = 1.5f;

    while (!window.WindowShouldClose())
    {
        if (Engine::Input::IsKeyPressed(ENGINE_KEY_W))
        {
            squareY += velocity;
        }
        if (Engine::Input::IsKeyPressed(ENGINE_KEY_S))
        {
            squareY -= velocity;
        }
        if (Engine::Input::IsKeyPressed(ENGINE_KEY_A))
        {
            squareX -= velocity;
        }
        if (Engine::Input::IsKeyPressed(ENGINE_KEY_D))
        {
            squareX += velocity;
        }
        
        Engine::Renderer::Clear(0.0f, 0.0f, 0.0f);

        Engine::Renderer2D::DrawTriangle(squareX, squareY, 100.0f, 100.0f);

        window.SwapBuffers();

        window.PollEvents();
    }

    // Clean up
    Engine::Renderer::Shutdown();

    return 0;
}