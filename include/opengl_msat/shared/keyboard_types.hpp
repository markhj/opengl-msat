#ifndef OPENGL_MSAT_KEYBOARD_TYPES_HPP
#define OPENGL_MSAT_KEYBOARD_TYPES_HPP

#include <string>
#include <map>
#include "opengl_msat/common.h"

enum KeyState {
    Press,
    Down,
    Release
};

struct KeyboardEvent {
    int key;
    KeyState event;

    bool operator<(const KeyboardEvent& other) const {
        if (key < other.key) return true;
        if (key > other.key) return false;
        return event < other.event;
    }

    bool operator==(const KeyboardEvent& other) const {
        return key == other.key && event == other.event;
    }
};

enum Key {
    // Controls
    Esc = GLFW_KEY_ESCAPE,
    Alt = GLFW_KEY_LEFT_ALT,
    AltRight = GLFW_KEY_RIGHT_ALT,
    Shift = GLFW_KEY_LEFT_SHIFT,
    ShiftRight = GLFW_KEY_RIGHT_SHIFT,
    Ctrl = GLFW_KEY_LEFT_CONTROL,
    CtrlRight = GLFW_KEY_RIGHT_CONTROL,
    Tab = GLFW_KEY_TAB,

    // Misc
    Space = GLFW_KEY_SPACE,
    Enter = GLFW_KEY_ENTER,
    Backspace = GLFW_KEY_BACKSPACE,
    Delete = GLFW_KEY_DELETE,

    // Arrow keys
    ArrowUp = GLFW_KEY_UP,
    ArrowDown = GLFW_KEY_DOWN,
    ArrowLeft = GLFW_KEY_LEFT,
    ArrowRight = GLFW_KEY_RIGHT,

    // F keys
    F1 = GLFW_KEY_F1,
    F2 = GLFW_KEY_F2,
    F3 = GLFW_KEY_F3,
    F4 = GLFW_KEY_F4,
    F5 = GLFW_KEY_F5,
    F6 = GLFW_KEY_F6,
    F7 = GLFW_KEY_F7,
    F8 = GLFW_KEY_F8,
    F9 = GLFW_KEY_F9,
    F10 = GLFW_KEY_F10,
    F11 = GLFW_KEY_F11,
    F12 = GLFW_KEY_F12,

    // Numeric
    No0 = GLFW_KEY_0,
    No1 = GLFW_KEY_1,
    No2 = GLFW_KEY_2,
    No3 = GLFW_KEY_3,
    No4 = GLFW_KEY_4,
    No5 = GLFW_KEY_5,
    No6 = GLFW_KEY_6,
    No7 = GLFW_KEY_7,
    No8 = GLFW_KEY_8,
    No9 = GLFW_KEY_9,

    // Letters
    A = GLFW_KEY_A,
    B = GLFW_KEY_B,
    C = GLFW_KEY_C,
    D = GLFW_KEY_D,
    E = GLFW_KEY_E,
    F = GLFW_KEY_F,
    G = GLFW_KEY_G,
    H = GLFW_KEY_H,
    I = GLFW_KEY_I,
    J = GLFW_KEY_J,
    K = GLFW_KEY_K,
    L = GLFW_KEY_L,
    M = GLFW_KEY_M,
    N = GLFW_KEY_N,
    O = GLFW_KEY_O,
    P = GLFW_KEY_P,
    Q = GLFW_KEY_Q,
    R = GLFW_KEY_R,
    S = GLFW_KEY_S,
    T = GLFW_KEY_T,
    U = GLFW_KEY_U,
    V = GLFW_KEY_V,
    W = GLFW_KEY_W,
    X = GLFW_KEY_X,
    Y = GLFW_KEY_Y,
    Z = GLFW_KEY_Z,
};

/**
 * We need to keep a "reversed map" of the keys for look-ups.
 * But it will have to do until we come up with a better solution.
 *
 * NOTE: Do NOT use the reverse map in your code
 *
 * NOTE: Keep the reverse map undocumented to avoid unintended usage
 *
 * @todo Better solution for reversed look-ups so we don't have to maintain two enums
 *      with essentially the same data
 */
extern std::map<int, Key> keyGlfwLookup;

#endif
