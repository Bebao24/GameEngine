#include <Sandbox/SandboxApp.h>
#include <GLFW/glfw3.h>

int main()
{
    Engine::Logger::Init();

    // Create a sandbox app
    SandboxApp* app = new SandboxApp();

    app->Start();
    Engine::Window& window = app->GetWindow();

    float deltaTime = 0.0f; // Time between last frame and current frame
    float lastFrame = 0.0f; // Time of last frame

    while (!window.WindowShouldClose())
    {
        // Calculate the delta time
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        Engine::Renderer::Clear(0.0f, 0.0f, 0.0f);

        // Render...
        app->Update(deltaTime);

        window.SwapBuffers();
        window.PollEvents();
    }

    Engine::Renderer::Shutdown();
    delete app;
    return 0;
}



