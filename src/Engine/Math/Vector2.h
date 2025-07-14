#pragma once

namespace Engine
{
    namespace Math
    {
        struct Vector2
        {
            float x;
            float y;

            Vector2(float x, float y) :x(x), y(y) {}
            Vector2(float scalar) :x(scalar), y(scalar) {}
        };
    }
}

