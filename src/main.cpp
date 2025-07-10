#include <iostream>
#include <Engine/Engine.h>

#include <Engine/Graphics/Renderer/OpenGL/VertexArray.h>
#include <Engine/Graphics/Renderer/OpenGL/VertexBuffer.h>
#include <Engine/Graphics/Renderer/OpenGL/IndexBuffer.h>
#include <Engine/Graphics/Renderer/OpenGL/Shader.h>

#include <glad/glad.h>

int main()
{
    Engine::Logger::Init();

    // Create the window
    Engine::Window window(640, 480, "Engine");

    Engine::Input::Init(&window);

    // Create a triangle

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

    Engine::VertexArray VAO;
    VAO.Bind();
    
    Engine::VertexBuffer VBO(vertices, sizeof(vertices));
    
    Engine::VertexBufferLayout layout;
    layout.AddElement(Engine::DataType::Float, 3, "a_Pos");
    
    VAO.AddVertexBuffer(VBO, layout);

    Engine::Shader Shader("Assets/Shaders/shader.vert", "Assets/Shaders/shader.frag");
    Shader.Bind();

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

        // Later, we will add a renderer so that we don't need glad.h
        glDrawArrays(GL_TRIANGLES, 0, 3);

        window.SwapBuffers();

        window.PollEvents();
    }

    return 0;
}