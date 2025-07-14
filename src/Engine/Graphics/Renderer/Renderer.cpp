#include "Renderer.h"
#include <Engine/Core/Log.h>
#include <glad/glad.h>
#include "Renderer2D.h"

namespace Engine
{
    void Renderer::Init(Window* window)
    {
        // Enable OpenGL features (e.g blending, culling, etc)
        // Initialize Renderer2D
        Renderer2D::Init(window);
    }

    void Renderer::Clear(float r, float g, float b, float a)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(r, g, b, a);
    }

    void Renderer::Draw(const VertexArray& vao, const Shader& shader)
    {
        shader.Bind();
        vao.Bind();

        if (vao.GetIndexBuffer() != nullptr)
        {
            glDrawElements(GL_TRIANGLES, vao.GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
        }
        else
        {
            ENGINE_LOG_WARN("No index buffer found!");
        }
    }

    void Renderer::Shutdown()
    {
        Renderer2D::Shutdown();
    }
}


