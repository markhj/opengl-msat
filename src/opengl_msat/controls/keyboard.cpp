
#include "opengl_msat/controls/keyboard.hpp"

void Keyboard::setKeyboardMapping(KeyboardMapping *kbm)
{
    keyboardMapping = kbm;
}

KeyboardMapping *Keyboard::getKeyboardMapping()
{
    return keyboardMapping;
}

bool Keyboard::isDown(Key key)
{
    auto iter = pressedKeys.find(key);
    if (iter == pressedKeys.end()) {
        return false;
    }
    return iter->second;
}

void Keyboard::keyPressed(Key key)
{
    pressedKeys[key] = true;
}

void Keyboard::keyReleased(Key key)
{
    pressedKeys[key] = false;
}
