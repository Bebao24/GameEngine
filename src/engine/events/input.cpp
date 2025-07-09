#include "input.h"
#include <engine/graphics/window.h>
#include <GLFW/glfw3.h>

namespace Engine
{
    // Define the static variable
    Window* Input::m_Window = nullptr;

    void Input::Init(Window* window)
    {
        m_Window = window;
    }

    bool Input::IsKeyPressed(int keycode)
    {
        // Get native window
        GLFWwindow* nativeWindow = GetNativeWindow();
        int state = glfwGetKey(nativeWindow, keycode);

        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool Input::IsMouseButtonPressed(int button)
    {
        GLFWwindow* nativeWindow = GetNativeWindow();
        int state = glfwGetMouseButton(nativeWindow, button);
        
        return state == GLFW_PRESS;
    }

    float Input::GetMouseX()
    {
        GLFWwindow* nativeWindow = GetNativeWindow();
        
        // We're getting X, Y coordinates of the mouse
        // Although we're only returning one of them
        double mouseX, mouseY;
        glfwGetCursorPos(nativeWindow, &mouseX, &mouseY);

        return mouseX;
    }

    float Input::GetMouseY()
    {
        GLFWwindow* nativeWindow = GetNativeWindow();
        
        // We're getting X, Y coordinates of the mouse
        // Although we're only returning one of them
        double mouseX, mouseY;
        glfwGetCursorPos(nativeWindow, &mouseX, &mouseY);

        return mouseY;
    }

    GLFWwindow* Input::GetNativeWindow()
    {
        GLFWwindow* nativeWindow = static_cast<GLFWwindow*>(m_Window->GetNativeWindow());
        return nativeWindow;
    }
}

