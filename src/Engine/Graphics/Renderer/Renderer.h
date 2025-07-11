#pragma once
#include "OpenGL/VertexArray.h"
#include "OpenGL/VertexBuffer.h"
#include "OpenGL/Shader.h"

#include "../Window.h"

namespace Engine
{
    class Renderer
    {
    public:
        static void Init(Window* window);
        static void Shutdown();

        static void Clear(float r, float g, float b, float a = 1.0f);
        static void Draw(const VertexArray& vao, const Shader& shader);
    };
}

