#ifndef OPENGL_MSAT_WINDOW_HPP
#define OPENGL_MSAT_WINDOW_HPP

#include "opengl_msat/common.h"
#include "opengl_msat/controls/keyboard.hpp"
#include "opengl_msat/controls/keyboard_types.hpp"

/**
 * Window
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/window/window/
 */
class Window {
public:
    Window(unsigned int width, unsigned int height, const char* title)
        : windowWidth(width), windowHeight(height), title(title)
    {}

    void generate();

    void regenerate();

    [[nodiscard]] GLFWwindow* getGlfwWindow() const;

    void swapBuffers();

    void pollEvents();

    void swapAndPoll();

    void setSize(unsigned int width, unsigned int height);

    [[nodiscard]] bool keepOpen() const;

    void close();

    void setKeyboard(Keyboard* kb);

    void setFullScreenMode(bool mode);

    void setMsaaSampling(int samples);

    [[nodiscard]] unsigned int getWidth() const;

    [[nodiscard]] unsigned int getHeight() const;

    [[nodiscard]] float getAspectRatio() const;
private:
    GLFWwindow* glfwWindow;

    static Keyboard* keyboard;

    bool instantiated = false;

    bool glfwInitiated = false;

    bool shouldClose = false;

    unsigned int windowWidth,
        windowHeight,
        monitorWidth,
        monitorHeight;

    const char* title;

    GLFWwindow* createWindow();

    void destroy();

    [[nodiscard]] int getDecoration() const;

    static void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

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
};

#endif
