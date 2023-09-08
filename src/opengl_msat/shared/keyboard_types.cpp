#include "opengl_msat/shared/keyboard_types.hpp"

#include <map>

std::map<int, Key> keyGlfwLookup {
    // Controls
    {GLFW_KEY_ESCAPE, Key::Esc},
    {GLFW_KEY_LEFT_ALT, Key::Alt},
    {GLFW_KEY_RIGHT_ALT, Key::AltRight},
    {GLFW_KEY_LEFT_SHIFT, Key::Shift},
    {GLFW_KEY_RIGHT_SHIFT, Key::ShiftRight},
    {GLFW_KEY_LEFT_CONTROL, Key::Ctrl},
    {GLFW_KEY_RIGHT_CONTROL, Key::CtrlRight},
    {GLFW_KEY_TAB, Key::Tab},

    // Misc
    {GLFW_KEY_SPACE, Key::Space},
    {GLFW_KEY_ENTER, Key::Enter},
    {GLFW_KEY_BACKSPACE, Key::Backspace},
    {GLFW_KEY_DELETE, Key::Delete},

    // Arrow keys
    {GLFW_KEY_UP, Key::ArrowUp},
    {GLFW_KEY_DOWN, Key::ArrowDown},
    {GLFW_KEY_LEFT, Key::ArrowLeft},
    {GLFW_KEY_RIGHT, Key::ArrowRight},

    // F keys
    {GLFW_KEY_F1, Key::F1},
    {GLFW_KEY_F2, Key::F2},
    {GLFW_KEY_F3, Key::F3},
    {GLFW_KEY_F4, Key::F4},
    {GLFW_KEY_F5, Key::F5},
    {GLFW_KEY_F6, Key::F6},
    {GLFW_KEY_F7, Key::F7},
    {GLFW_KEY_F8, Key::F8},
    {GLFW_KEY_F9, Key::F9},
    {GLFW_KEY_F10, Key::F10},
    {GLFW_KEY_F11, Key::F11},
    {GLFW_KEY_F12, Key::F12},

    // Numeric
    {GLFW_KEY_0, Key::No0},
    {GLFW_KEY_1, Key::No1},
    {GLFW_KEY_2, Key::No2},
    {GLFW_KEY_3, Key::No3},
    {GLFW_KEY_4, Key::No4},
    {GLFW_KEY_5, Key::No5},
    {GLFW_KEY_6, Key::No6},
    {GLFW_KEY_7, Key::No7},
    {GLFW_KEY_8, Key::No8},
    {GLFW_KEY_9, Key::No9},

    // Letters
    {GLFW_KEY_A, Key::A},
    {GLFW_KEY_B, Key::B},
    {GLFW_KEY_C, Key::C},
    {GLFW_KEY_D, Key::D},
    {GLFW_KEY_E, Key::E},
    {GLFW_KEY_F, Key::F},
    {GLFW_KEY_G, Key::G},
    {GLFW_KEY_H, Key::H},
    {GLFW_KEY_I, Key::I},
    {GLFW_KEY_J, Key::J},
    {GLFW_KEY_K, Key::K},
    {GLFW_KEY_L, Key::L},
    {GLFW_KEY_M, Key::M},
    {GLFW_KEY_N, Key::N},
    {GLFW_KEY_O, Key::O},
    {GLFW_KEY_P, Key::P},
    {GLFW_KEY_Q, Key::Q},
    {GLFW_KEY_R, Key::R},
    {GLFW_KEY_S, Key::S},
    {GLFW_KEY_T, Key::T},
    {GLFW_KEY_U, Key::U},
    {GLFW_KEY_V, Key::V},
    {GLFW_KEY_W, Key::W},
    {GLFW_KEY_X, Key::X},
    {GLFW_KEY_Y, Key::Y},
    {GLFW_KEY_Z, Key::Z},
};