#pragma once

namespace Engine
{
    namespace Math
    {
        struct Vector4
        {
            float x;
            float y;
            float z;
            float w;

            Vector4(float x, float y, float z, float w) :x(x), y(y), z(z), w(w) {}
            Vector4(float scalar) :x(scalar), y(scalar), z(scalar), w(scalar) {}
        };
    }
}


