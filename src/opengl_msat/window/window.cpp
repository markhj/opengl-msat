#include <iostream>
#include "opengl_msat/window/window.hpp"

Keyboard* Window::keyboard = nullptr;

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

    glfwSetKeyCallback(glfwWindow, keyboardCallback);

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

void Window::keyboardCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (!keyboard) {
        return;
    }

    auto glfwToKey = keyGlfwLookup.find(key);
    if (!glfwToKey->first) {
        return;
    }

    KeyState state;
    switch (action) {
        case GLFW_PRESS:
            state = KeyState::Press;
            break;
        case GLFW_RELEASE:
            state = KeyState::Release;
            break;
        default:
            return;
    }

    KeyboardEvent kbEvent {
        .key = glfwToKey->second,
        .event = state
    };

    auto handle = keyboard->getKeyboardMapping()->getHandle(kbEvent);
    if (handle.has_value()) {
        handle.value()();
    }
}
