#ifndef OPENGL_MSAT_WINDOW_HPP
#define OPENGL_MSAT_WINDOW_HPP

#include "opengl_msat/common.h"

class Window {
public:
    Window() { }

    Window(unsigned int width, unsigned int height) : windowWidth(width), windowHeight(height) {}

    Window(const char* title) : title(title) { }

    Window(unsigned int width, unsigned int height, const char* title)
        : windowWidth(width), windowHeight(height), title(title)
    {}

    void generate();

    void regenerate();

    GLFWwindow* getGlfwWindow() const {
        return glfwWindow;
    }

    void swapBuffers();

    void pollEvents();

    void swapAndPoll();

    void setSize(unsigned int width, unsigned int height);

    [[nodiscard]] bool keepOpen() const;

    void close();

    // Window decoration is the title bar with minimize, maximize and close buttons
    // The setting of this value in practice is overruled by fullScreenMode (if true)
    // NOTE: Requires the window to be re-generated when changed after initialization
    bool decoration = true;

    // MSAA sampling (anti-alias)
    // NOTE: Requires the window to be re-generated when changed after initialization
    int msaaSamples = 4;

    // Indicates if the window should go in full-screen mode upon generation
    // When setting of decoration conflicts with full screen mode, this mode takes priority
    // NOTE: Requires the window to be re-generated when changed after initialization
    bool fullScreenMode = false;
private:
    GLFWwindow* glfwWindow;

    bool instantiated = false;

    bool glfwInitiated = false;

    bool shouldClose = false;

    unsigned int windowWidth = 800,
        windowHeight = 600,
        monitorWidth,
        monitorHeight;

    const char* title = "OpenGL MSAT";

    GLFWwindow* createWindow();

    void destroy();

    [[nodiscard]] int getDecoration() const;
};

#endif
