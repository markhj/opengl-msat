#ifndef OPENGL_MSAT_WINDOW_HPP
#define OPENGL_MSAT_WINDOW_HPP

#include "opengl_msat/common.h"
#include "opengl_msat/controls/keyboard.hpp"
#include "opengl_msat/controls/control_types.hpp"
#include "opengl_msat/controls/mouse.hpp"
#include "opengl_msat/controls/input_controller.hpp"

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

    void handleInputs();

    void setSize(unsigned int width, unsigned int height);

    [[nodiscard]] bool keepOpen() const;

    void close();

    void setKeyboard(Keyboard* kb);

    void setMouse(Mouse* ms);

    void setInputController(InputController* ic);

    void setFullScreenMode(bool mode);

    void setMsaaSampling(int samples);

    [[nodiscard]] unsigned int getWidth() const;

    [[nodiscard]] unsigned int getHeight() const;

    [[nodiscard]] float getAspectRatio() const;

private:
    GLFWwindow* glfwWindow;

    static Keyboard* keyboard;

    static Mouse* mouse;

    static InputController* inputController;

    static std::optional<float> mouseLastX, mouseLastY;

    static std::map<Key, bool> pressedKeys;

    static std::map<MouseButton, bool> pressedMouseButtons;

    bool instantiated = false;

    bool glfwInitiated = false;

    static bool shouldClose;

    unsigned int windowWidth,
        windowHeight,
        monitorWidth,
        monitorHeight;

    const char* title;

    GLFWwindow* createWindow();

    void destroy();

    void initializeGLFW();

    void initializeGLAD();

    [[nodiscard]] int getDecoration() const;

    static void windowCloseCallback(GLFWwindow* window);

    static void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

    static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

    static void mouseCallback(GLFWwindow* glfwWindow, double x, double y);

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
