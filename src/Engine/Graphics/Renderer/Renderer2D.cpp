#include "Renderer2D.h"
#include "OpenGL/VertexArray.h"
#include "OpenGL/VertexBuffer.h"
#include "OpenGL/IndexBuffer.h"
#include "OpenGL/Shader.h"

#include "Renderer.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Engine
{
    struct Vertex
    {
        glm::vec3 position;
    };

    // Renderer 2D data
    struct Renderer2DData
    {
        VertexArray* triangleVAO;
        VertexBuffer* triangleVBO;
        IndexBuffer* triangleIBO;
        
        Vertex triangleVertex[3];
        uint32_t triangleIndices[3];

        VertexArray* quadVAO;
        VertexBuffer* quadVBO;
        IndexBuffer* quadIBO;

        Vertex quadVertex[4];
        uint32_t quadIndices[6];

        Shader* shader;

        Window* window;
        
        glm::mat4 projection;
    };

    static Renderer2DData s_Data;

    void Renderer2D::Init(Window* window)
    {
        // Setup vertex
        s_Data.triangleVertex[0] = {{0.0f, 0.0f, 0.0f}};
        s_Data.triangleVertex[1] = {{ 1.0f, 0.0f, 0.0f}};
        s_Data.triangleVertex[2] = {{ 0.5f, 1.0f, 0.0f}};

        s_Data.triangleIndices[0] = 0;
        s_Data.triangleIndices[1] = 1;
        s_Data.triangleIndices[2] = 2;

        s_Data.quadVertex[0] = {{ 0.0f, 0.0f, 0.0f }};
        s_Data.quadVertex[1] = {{ 1.0f, 0.0f, 0.0f }};
        s_Data.quadVertex[2] = {{ 1.0f, 1.0f, 0.0f }};
        s_Data.quadVertex[3] = {{ 0.0f, 1.0f, 0.0f }};

        // First triangle
        s_Data.quadIndices[0] = 0;
        s_Data.quadIndices[1] = 1;
        s_Data.quadIndices[2] = 3;

        // Second triangle
        s_Data.quadIndices[3] = 1;
        s_Data.quadIndices[4] = 2;
        s_Data.quadIndices[5] = 3;

        // Create VAO
        s_Data.triangleVAO = new VertexArray();
        s_Data.triangleVBO = new VertexBuffer(s_Data.triangleVertex, sizeof(s_Data.triangleVertex));

        s_Data.quadVAO = new VertexArray();
        s_Data.quadVBO = new VertexBuffer(s_Data.quadVertex, sizeof(s_Data.quadVertex));

        // Setup buffer layout
        VertexBufferLayout triangleLayout;
        triangleLayout.AddElement(DataType::Float, 3, "Position");

        VertexBufferLayout quadLayout;
        quadLayout.AddElement(DataType::Float, 3, "Position");

        s_Data.triangleVAO->Bind();
        s_Data.triangleVAO->AddVertexBuffer(*s_Data.triangleVBO, triangleLayout);

        s_Data.quadVAO->Bind();
        s_Data.quadVAO->AddVertexBuffer(*s_Data.quadVBO, quadLayout);

        // Create IBO
        s_Data.triangleVAO->Bind();
        s_Data.triangleIBO = new IndexBuffer(s_Data.triangleIndices, 3);
        s_Data.triangleVAO->SetIndexBuffer(*s_Data.triangleIBO);

        s_Data.quadVAO->Bind();
        s_Data.quadIBO = new IndexBuffer(s_Data.quadIndices, 6);
        s_Data.quadVAO->SetIndexBuffer(*s_Data.quadIBO);

        // Create the Orthographic matrix
        int windowWidth = window->GetWidth();
        int windowHeight = window->GetHeight();
        s_Data.window = window;

        s_Data.projection = glm::ortho(0.0f, (float)windowWidth, 0.0f, (float)windowHeight);

        // Load in the shader
        s_Data.shader = new Shader("Assets/Shaders/shader.vert", "Assets/Shaders/shader.frag");

        s_Data.quadVAO->Unbind();
    }

    void Renderer2D::DrawTriangle(const Math::Vector2& position, const Math::Vector2& size)
    {
        glm::mat4 transform = glm::translate(glm::mat4(1.0f), glm::vec3(position.x, position.y, 0.0f)); // Move
        transform *= glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, 1.0f));

        // TODO: Pass in a color from the user
        
        glm::vec4 color(1.0f, 0.0f, 0.0f, 1.0f);

        // Setup the shader
        s_Data.shader->Bind();
        s_Data.shader->SetUniform4f("u_Color", color.x, color.y, color.z, color.w);
        s_Data.shader->SetUniformMat4f("u_projectionMatrix", s_Data.projection);
        s_Data.shader->SetUniformMat4f("u_transformMatrix", transform);

        // Draw it
        Renderer::Draw(*s_Data.triangleVAO, *s_Data.shader);
    }

    void Renderer2D::DrawQuad(const Math::Vector2& position, const Math::Vector2& size)
    {
        glm::mat4 transform = glm::translate(glm::mat4(1.0f), glm::vec3(position.x, position.y, 0.0f)); // Move
        transform *= glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, 1.0f));

        // TODO: Pass in a color from the user
        
        glm::vec4 color(1.0f, 0.0f, 0.0f, 1.0f);

        // Setup the shader
        s_Data.shader->Bind();
        s_Data.shader->SetUniform4f("u_Color", color.x, color.y, color.z, color.w);
        s_Data.shader->SetUniformMat4f("u_projectionMatrix", s_Data.projection);
        s_Data.shader->SetUniformMat4f("u_transformMatrix", transform);

        // Draw it
        Renderer::Draw(*s_Data.quadVAO, *s_Data.shader);
    }

    void Renderer2D::Shutdown()
    {
        delete s_Data.triangleVAO;
        delete s_Data.triangleVBO;
        delete s_Data.triangleIBO;

        delete s_Data.quadVAO;
        delete s_Data.quadVBO;
        delete s_Data.quadIBO;

        delete s_Data.shader;
    }
}


