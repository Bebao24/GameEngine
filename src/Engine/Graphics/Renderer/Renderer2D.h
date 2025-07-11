#pragma once
#include "../Window.h"

namespace Engine
{
    class Renderer2D
    {
    public:
        static void Init(Window* window);
        static void Shutdown();

        static void DrawTriangle(float x, float y, float width, float height);
    };
}


