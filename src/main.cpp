#include <iostream>
#include <Engine/Engine.h>

#include <Engine/Graphics/Renderer/OpenGL/VertexArray.h>
#include <Engine/Graphics/Renderer/OpenGL/VertexBuffer.h>
#include <Engine/Graphics/Renderer/OpenGL/IndexBuffer.h>
#include <Engine/Graphics/Renderer/OpenGL/Shader.h>
#include <glm/glm.hpp>

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

    uint32_t indices[] = {
        1, 2, 3
    };

    Engine::VertexArray VAO;
    VAO.Bind();
    
    Engine::VertexBuffer VBO(vertices, sizeof(vertices));
    
    Engine::VertexBufferLayout layout;
    layout.AddElement(Engine::DataType::Float, 3, "a_Pos");
    
    VAO.AddVertexBuffer(VBO, layout);

    Engine::IndexBuffer IBO(indices, 3);
    VAO.SetIndexBuffer(IBO);

    Engine::Shader Shader("Assets/Shaders/shader.vert", "Assets/Shaders/shader.frag");
    Shader.Bind();
    
    float color = 0.0f;
    float increment = 0.05f;

    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));

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
        
        Engine::Renderer::Clear(0.0f, 0.0f, 0.0f);

        Shader.SetUniformMat4f("u_transformMatrix", trans);
        Shader.SetUniform4f("u_Color", color, 0.5f, 0.7f, 1.0f);
        Engine::Renderer::Draw(VAO, Shader);

        if (color > 1.0f)
        {
            increment = -0.05f;
        }
        else if (color <= 0.0f)
        {
            increment = 0.05f;
        }

        color += increment;

        window.SwapBuffers();

        window.PollEvents();
    }

    return 0;
}