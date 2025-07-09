#pragma once
#include <string>

// Just to get the GLFWwindow without including glfw3.h
struct GLFWwindow;

namespace Engine
{
    struct WindowData
    {
        int width;
        int height;
        std::string title;

        bool Vsync;
    };

    class Window
    {
    public:
        Window(int width, int height, std::string title);
        ~Window();

        void ClearColor(float r, float g, float b, float a) const;
        void PollEvents() const;
        void SwapBuffers() const;

        bool WindowShouldClose() const;

        void* GetNativeWindow() const { return m_Window; }

        inline int GetWidth() { return m_Data.width; }
        inline int GetHeight() { return m_Data.height; }

        void SetVsync(bool enabled);
        bool IsVsync();

    private:
        void CreateWindow(int width, int height, std::string title);
    private:
        GLFWwindow* m_Window;
        WindowData m_Data;
    };
}


