#ifndef OPENGL_MSAT_WINDOW_HPP
#define OPENGL_MSAT_WINDOW_HPP

#include "glad/glad.h"
#include <GLFW/glfw3.h>

class Window {
public:
    Window() { }

    Window(unsigned int width, unsigned int height) : windowWidth(width), windowHeight(height) {}

    Window(const char* title) : title(title) { }

    Window(unsigned int width, unsigned int height, const char* title)
        : windowWidth(width), windowHeight(height), title(title)
    {}

    void generate();

    [[nodiscard]] bool keepOpen() const;

    void close();
private:
    GLFWwindow* glfwWindow;

    bool shouldClose = false;

    bool fullScreenMode = false;

    int msaaSamples = 4;

    unsigned int windowWidth = 800;
    unsigned int windowHeight = 600;
    const char* title = "OpenGL MSAT";

    GLFWwindow* createWindow();
};

#endif
