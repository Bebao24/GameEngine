#pragma once

namespace Engine
{
    namespace Math
    {
        struct Vector3
        {
            float x;
            float y;
            float z;

            Vector3(float x, float y, float z) :x(x), y(y), z(z) {}
            Vector3(float scalar) :x(scalar), y(scalar), z(scalar) {}
        };
    }
}


