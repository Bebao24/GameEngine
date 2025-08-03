#include "Number.h"
#include <cmath>
#include <algorithm>

namespace Engine
{
    namespace Math
    {
        double Sqrt(double value)
        {
            return std::sqrt(value);
        }

        double Abs(double value)
        {
            return std::abs(value);
        }

        double Pow(double x, double y)
        {
            return std::pow(x, y);
        }

        double Min(double x, double y)
        {
            return std::min(x, y);
        }

        double Max(double x, double y)
        {
            return std::max(x, y);
        }
    }
}

