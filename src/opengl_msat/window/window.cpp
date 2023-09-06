#include <iostream>
#include "opengl_msat/window/window.hpp"

void Window::generate()
{
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
    }

    glfwWindowHint(GLFW_SAMPLES, msaaSamples);

    glfwWindow = createWindow();

    if (!glfwWindow) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(glfwWindow);

    // Load OpenGL function pointers using GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
    }

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
//    monitorWidth = mode->width;
//    monitorHeight = mode->height;

}

bool Window::keepOpen() const
{
    return !shouldClose;
}

void Window::close()
{
    shouldClose = true;
}

GLFWwindow *Window::createWindow() {
    if (fullScreenMode) {
        glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);
        return glfwCreateWindow(mode->width, mode->height, title, nullptr, nullptr);
    }

    return glfwCreateWindow(windowWidth, windowHeight, title, nullptr, nullptr);
}
