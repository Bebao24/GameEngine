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

        s_Data.triangleIndices[0] = 1;
        s_Data.triangleIndices[1] = 2;
        s_Data.triangleIndices[2] = 3;

        // Create a triangle VAO
        s_Data.triangleVAO = new VertexArray();
        s_Data.triangleVBO = new VertexBuffer(s_Data.triangleVertex, sizeof(s_Data.triangleVertex));

        // Setup buffer layout
        VertexBufferLayout triangleLayout;
        triangleLayout.AddElement(DataType::Float, 3, "Position");

        s_Data.triangleVAO->AddVertexBuffer(*s_Data.triangleVBO, triangleLayout);

        // Create a triangle IBO
        s_Data.triangleIBO = new IndexBuffer(s_Data.triangleIndices, 3);

        s_Data.triangleVAO->SetIndexBuffer(*s_Data.triangleIBO);

        // Create the Orthographic matrix
        int windowWidth = window->GetWidth();
        int windowHeight = window->GetHeight();
        s_Data.window = window;

        s_Data.projection = glm::ortho(0.0f, (float)windowWidth, 0.0f, (float)windowHeight);

        // Load in the shader
        s_Data.shader = new Shader("Assets/Shaders/shader.vert", "Assets/Shaders/shader.frag");
    }

    void Renderer2D::DrawTriangle(float x, float y, float width, float height)
    {
        glm::mat4 transform = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0.0f)); // Move
        transform *= glm::scale(glm::mat4(1.0f), glm::vec3(width, height, 1.0f));

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

    void Renderer2D::Shutdown()
    {
        delete s_Data.triangleVAO;
        delete s_Data.triangleVBO;
        delete s_Data.triangleIBO;
        delete s_Data.shader;
    }
}


