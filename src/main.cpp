#include <iostream>
#include <engine/engine.h>

int main()
{
    Engine::Logger::Init();

    // Create the window
    Engine::Window window(640, 480, "Engine");

    Engine::Input::Init(&window);

    while (!window.WindowShouldClose())
    {
        if (Engine::Input::IsMouseButtonPressed(ENGINE_MOUSE_BUTTON_1))
        {
            // Print out the coordinate of the mouse
            ENGINE_LOG_TRACE("X: %f, Y: %f", Engine::Input::GetMouseX(), Engine::Input::GetMouseY());
        }

        if (Engine::Input::IsKeyPressed(ENGINE_KEY_S))
        {
            ENGINE_LOG_TRACE("S key pressed!");
        }
        
        window.ClearColor(0.0f, 0.0f, 0.0f, 0.0f);

        window.SwapBuffers();

        window.PollEvents();
    }

    return 0;
}