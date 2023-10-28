#ifndef OPENGL_MSAT_KEYBOARD_HPP
#define OPENGL_MSAT_KEYBOARD_HPP

#include "opengl_msat/common.h"
#include "keyboard_mapping.hpp"

/**
 * Keyboard
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/controls/keyboard/
 */
class Keyboard {
public:
    Keyboard() = default;

    explicit Keyboard(KeyboardMapping* kbm) : keyboardMapping(kbm) {}

    void setKeyboardMapping(KeyboardMapping* kbm);

    KeyboardMapping* getKeyboardMapping();
private:
    KeyboardMapping* keyboardMapping{};
};

#endif
