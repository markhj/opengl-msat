
#include "opengl_msat/controls/keyboard.hpp"

void Keyboard::setKeyboardMapping(KeyboardMapping *kbm)
{
    keyboardMapping = kbm;
}

KeyboardMapping *Keyboard::getKeyboardMapping()
{
    return keyboardMapping;
}
