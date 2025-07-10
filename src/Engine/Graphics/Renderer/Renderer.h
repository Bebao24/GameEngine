#pragma once
#include "OpenGL/VertexArray.h"
#include "OpenGL/VertexBuffer.h"
#include "OpenGL/Shader.h"

namespace Engine
{
    class Renderer
    {
    public:
        static void Init();

        static void Clear(float r, float g, float b, float a = 1.0f);
        static void Draw(const VertexArray& vao, const Shader& shader);

    private:
        
    };
}

