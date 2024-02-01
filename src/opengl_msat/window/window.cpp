#include <iostream>
#include "opengl_msat/window/window.hpp"

bool Window::shouldClose = false;

void Window::generate()
{
    initializeGLFW();

    glfwWindowHint(GLFW_SAMPLES, 1);
    glfwWindowHint(GLFW_DECORATED, getDecoration());

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    monitorWidth = mode->width;
    monitorHeight = mode->height;

    glfwWindow = createWindow();

    if (!glfwWindow) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(glfwWindow);

    initializeGLAD();

    glfwSetWindowCloseCallback(glfwWindow, windowCloseCallback);

    instantiated = true;
}

void Window::initializeGLFW()
{
    if (!glfwInitiated) {
        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW" << std::endl;
        }
    }
}

void Window::initializeGLAD()
{
    if (glfwInitiated) {
        return;
    }
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
    }
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

    // We will only store the new window size, when we're in full screen
    // mode, but not actually resize the window, as this may cause
    // the window to behave as in full-screen mode, but not actually
    // fill out the entire screen space
    if (!fullScreenMode) {
        glfwSetWindowSize(glfwWindow, width, height);
    }
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

GLFWwindow *Window::getGlfwWindow() const
{
    return glfwWindow;
}

void Window::setFullScreenMode(bool mode)
{
    fullScreenMode = mode;
}

void Window::setMsaaSampling(int samples)
{
    msaaSamples = samples;
}

unsigned int Window::getWidth() const
{
    return fullScreenMode ? monitorWidth : windowWidth;
}

unsigned int Window::getHeight() const
{
    return fullScreenMode ? monitorHeight : windowHeight;
}

float Window::getAspectRatio() const
{
    return static_cast<float>(getWidth()) / getHeight();
}

void Window::windowCloseCallback(GLFWwindow *window)
{
    shouldClose = true;
}
