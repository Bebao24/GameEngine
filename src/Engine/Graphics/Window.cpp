#include "Window.h"
#include <Engine/Core/Log.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Engine
{
    static bool s_GLFWInitialized = false;

    Window::Window(int width, int height, std::string title)
    {
        // Create the window
        CreateWindow(width, height, title);

        // Assigning the window data
        m_Data.width = width;
        m_Data.height = height;
        m_Data.title = title;
    }

    Window::~Window()
    {
        // Exit GLFW
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

    void Window::CreateWindow(int width, int height, std::string title)
    {
        // Initialize GLFW if not already
        if (!s_GLFWInitialized)
        {
            if (!glfwInit())
            {
                ENGINE_LOG_ERROR("Failed to initialize GLFW!");
                exit(1);
            }

            ENGINE_LOG_INFO("GLFW initialized!");
        }

        // Create the window
        m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (!m_Window)
        {
            ENGINE_LOG_ERROR("Failed to create GLFW window!");
            glfwTerminate();
            exit(1);
        }

        ENGINE_LOG_INFO("Created a GLFW window");

        // Make the window's context
        glfwMakeContextCurrent(m_Window);

        // Initialize GLAD
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            ENGINE_LOG_ERROR("Failed to initialize GLAD!\n");
            glfwTerminate();
            exit(1);
        }

        ENGINE_LOG_INFO("GLAD initialized!");

        // Store the window's data into the window ptr
        glfwSetWindowUserPointer(m_Window, &m_Data);

        // Enable Vsync
        SetVsync(true);

        // Create window event callback
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
            glViewport(0, 0, width, height);

            // Update our width and height info
            // Get the window's data first
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            data.width = width;
            data.height = height;
        });
    }

    void Window::ClearColor(float r, float g, float b, float a) const
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(r, g, b, a);
    }

    void Window::PollEvents() const
    {
        glfwPollEvents();
    }

    void Window::SwapBuffers() const
    {
        glfwSwapBuffers(m_Window);
    }

    bool Window::WindowShouldClose() const
    {
        return glfwWindowShouldClose(m_Window);
    }

    void Window::SetVsync(bool enabled)
    {
        glfwSwapInterval(enabled ? 1 : 0);
        m_Data.Vsync = enabled;
    }

    bool Window::IsVsync()
    {
        return m_Data.Vsync;
    }
}

