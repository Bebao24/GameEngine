#pragma once
#include <Engine/Graphics/Window.h>

namespace Engine
{
    class Input
    {
    public:
        static void Init(Window* window);

        static bool IsKeyPressed(int keycode);
        static bool IsMouseButtonPressed(int button);
        static float GetMouseX();
        static float GetMouseY();

    private:
        static GLFWwindow* GetNativeWindow();

        static Window* m_Window;
    };
}

