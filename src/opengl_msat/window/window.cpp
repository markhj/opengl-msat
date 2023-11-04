#include <iostream>
#include "opengl_msat/window/window.hpp"

Keyboard* Window::keyboard = nullptr;
Mouse* Window::mouse = nullptr;
bool Window::shouldClose = false;
InputController* Window::inputController = nullptr;
std::map<Key, bool> Window::pressedKeys = {};
std::map<MouseButton, bool> Window::pressedMouseButtons = {};

std::optional<float> Window::mouseLastX = std::nullopt, Window::mouseLastY = std::nullopt;

void Window::generate()
{
    initializeGLFW();

    glfwWindowHint(GLFW_SAMPLES, 1);
    glfwWindowHint(GLFW_DECORATED, getDecoration());

    glfwWindow = createWindow();

    if (!glfwWindow) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(glfwWindow);

    initializeGLAD();

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    monitorWidth = mode->width;
    monitorHeight = mode->height;

    glfwSetKeyCallback(glfwWindow, keyboardCallback);
    glfwSetCursorPosCallback(glfwWindow, mouseCallback);
    glfwSetWindowCloseCallback(glfwWindow, windowCloseCallback);
    glfwSetMouseButtonCallback(glfwWindow, mouseButtonCallback);

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

void Window::keyboardCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (!keyboard) {
        return;
    }

    if (!keyboard->keyboardMapping) {
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
            pressedKeys[glfwToKey->second] = true;
            break;
        case GLFW_RELEASE:
            state = KeyState::Release;
            pressedKeys[glfwToKey->second] = false;
            break;
        default:
            return;
    }

    KeyboardEvent kbEvent {
        .key = glfwToKey->second,
        .event = state
    };

    auto handle = keyboard->keyboardMapping->getHandle(kbEvent);
    if (handle.has_value() && inputController != nullptr) {
        inputController->process({ handle.value() });
    }
}

GLFWwindow *Window::getGlfwWindow() const
{
    return glfwWindow;
}

void Window::setKeyboard(Keyboard *kb)
{
    keyboard = kb;
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

void Window::mouseCallback(GLFWwindow *glfwWindow, double x, double y)
{
    if (!mouse) {
        return;
    }

    if (!mouseLastX.has_value()) {
        mouseLastX = x;
    }

    if (!mouseLastY.has_value()) {
        mouseLastY = y;
    }

    float diffX = x - mouseLastX.value(),
        diffY = y - mouseLastY.value();

    mouseLastX = x;
    mouseLastY = y;

    mouse->moved({static_cast<float>(x), static_cast<float>(y)},
                 {diffX, diffY});
}

void Window::setMouse(Mouse *ms)
{
    mouse = ms;
}

void Window::windowCloseCallback(GLFWwindow *window)
{
    shouldClose = true;
}

void Window::setInputController(InputController *ic)
{
    inputController = ic;
}

void Window::handleInputs()
{
    if (!inputController) {
        return;
    }

    std::vector<unsigned int> list;

    if (keyboard && keyboard->keyboardMapping) {
        for (auto k: pressedKeys) {
            if (!k.second) {
                continue;
            }

            KeyboardEvent kbEvent{
                .key = k.first,
                .event = KeyState::Down,
            };

            auto handle = keyboard->keyboardMapping->getHandle(kbEvent);
            if (handle.has_value()) {
                list.push_back(handle.value());
            }
        }
    }

    if (mouse) {
        for (auto k: pressedMouseButtons) {
            if (!k.second) {
                continue;
            }

            auto handle = mouse->mouseMapping->getHandle({
                .button = k.first,
                .event = MouseButtonState::Down,
            });

            if (handle.has_value()) {
                list.push_back(handle.value());
            }
        }
    }

    inputController->process(list);
}

void Window::mouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
{
    if (!mouse) {
        return;
    }

    if (!mouse->mouseMapping) {
        return;
    }

    // Currently, we only support primary and secondary buttons
    if (button != 0 && button != 1) {
        return;
    }

    MouseButtonState state;
    MouseButton mouseButton((button == 0 ? MouseButton::Primary : MouseButton::Secondary));

    switch (action) {
        case GLFW_PRESS:
            state = MouseButtonState::Press;
            pressedMouseButtons[mouseButton] = true;
            break;
        case GLFW_RELEASE:
            state = MouseButtonState::Release;
            pressedMouseButtons[mouseButton] = false;
            break;
        default:
            return;
    }

    MouseButtonEvent kbEvent {
        .button = mouseButton,
        .event = state
    };

    auto handle = mouse->mouseMapping->getHandle(kbEvent);
    if (handle.has_value() && inputController != nullptr) {
        inputController->process({ handle.value() });
    }
}
