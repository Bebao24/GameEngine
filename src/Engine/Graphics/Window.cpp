#include "Window.h"
#include <Engine/Core/Log.h>
#include <Engine/Events/KeyPressedEvent.h>
#include <Engine/Events/MouseEvent.h>
#include <Engine/Events/WindowEvent.h>
#include <Engine/Core/Application.h>

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

        // Set OpenGL version
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // For MacOS X
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

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

        // Print out OpenGL info
        ENGINE_LOG_INFO("OpenGL version: %s", glGetString(GL_VERSION));
        ENGINE_LOG_INFO("OpenGL vendor: %s", glGetString(GL_VENDOR));
        ENGINE_LOG_INFO("OpenGL renderer: %s", glGetString(GL_RENDERER));

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

            // Window resized event
            WindowResizedEvent event(width, height);
            Application::Get().OnEvent(event);
        });

        // Handle events
        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            // Prevent unused warnings
            (void)window;
            (void)scancode;
            (void)action;
            (void)mods;

            KeyPressedEvent event(key);
            Application::Get().OnEvent(event);
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double mouseX, double mouseY)
        {
            (void)window;

            MouseMovedEvent event((float)mouseX, (float)mouseY);
            Application::Get().OnEvent(event);
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int actions, int mods)
        {
            (void)window;
            (void)mods;

            switch (actions)
            {
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent mousePressedEvent(button);
                    Application::Get().OnEvent(mousePressedEvent);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonReleasedEvent mouseReleasedEvent(button);
                    Application::Get().OnEvent(mouseReleasedEvent);
                    break;
                }
            }
        });

        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
        {
            (void)window;
            
            MouseScrolledEvent event((float)xOffset, (float)yOffset);
            Application::Get().OnEvent(event);
        });
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

