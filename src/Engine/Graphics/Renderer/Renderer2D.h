#pragma once
#include "../Window.h"
#include <Engine/Math/Math.h>
#include "OpenGL/Texture.h"
#include "Camera.h"

namespace Engine
{
    class Renderer2D
    {
    public:
        static void Init(Window* window);
        static void Shutdown();

        static void BeginScene(const Camera& camera);
        static void EndScene();

        static void DrawTriangle(const Math::Vector2& position, const Math::Vector2& size, const Math::Vector4& color);

        static void DrawQuad(const Math::Vector2& position, const Math::Vector2& size, const Math::Vector4& color);
        static void DrawQuad(const Math::Vector2& position, const Math::Vector2& size, const Texture& texture);
        
        static void DrawCircle(const Math::Vector2& position, float radius, const Math::Vector4& color);
    };
}


