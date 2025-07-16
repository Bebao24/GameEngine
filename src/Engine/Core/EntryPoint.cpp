#include <Sandbox/SandboxApp.h>

int main()
{
    // Create a sandbox app
    SandboxApp* app = new SandboxApp();

    app->Start();
    Engine::Window& window = app->GetWindow();

    while (!window.WindowShouldClose())
    {
        Engine::Renderer::Clear(0.0f, 0.0f, 0.0f);

        // Render...
        app->Update();

        window.SwapBuffers();
        window.PollEvents();
    }

    Engine::Renderer::Shutdown();
    delete app;
    return 0;
}



