#include <iostream>
#include "opengl_msat/window/window.hpp"

void Window::generate()
{
    if (!glfwInitiated) {
        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW" << std::endl;
        }
    }

    glfwWindowHint(GLFW_SAMPLES, msaaSamples);
    glfwWindowHint(GLFW_DECORATED, getDecoration());

    glfwWindow = createWindow();

    if (!glfwWindow) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(glfwWindow);

    if (!glfwInitiated) {
        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            std::cerr << "Failed to initialize GLAD" << std::endl;
            glfwTerminate();
        }
    }

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    monitorWidth = mode->width;
    monitorHeight = mode->height;

    instantiated = true;
    glfwInitiated = true;
}

bool Window::keepOpen() const
{
    return !shouldClose;
}

void Window::close()
{
    shouldClose = true;
}

GLFWwindow *Window::createWindow()
{
    return glfwCreateWindow(
            fullScreenMode ? monitorWidth : windowWidth,
            fullScreenMode ? monitorHeight : windowHeight,
            title,
            nullptr,
            nullptr
            );
}

void Window::swapBuffers()
{
    glfwSwapBuffers(glfwWindow);
}

void Window::pollEvents()
{
    glfwPollEvents();
}

void Window::swapAndPoll()
{
    swapBuffers();
    pollEvents();
}

void Window::setSize(unsigned int width, unsigned int height)
{
    windowWidth = width;
    windowHeight = height;
    glfwSetWindowSize(glfwWindow, width, height);
}

void Window::regenerate()
{
    destroy();
    generate();
}

void Window::destroy()
{
    glfwDestroyWindow(glfwWindow);

    instantiated = false;
}

int Window::getDecoration() const
{
    if (fullScreenMode) {
        return 0;
    }

    return decoration ? 1 : 0;
}
