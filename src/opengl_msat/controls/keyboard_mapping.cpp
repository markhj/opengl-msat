#include <iostream>
#include "opengl_msat/controls/keyboard_mapping.hpp"

KeyboardMapping* keyboardMapping = nullptr;

void KeyboardMapping::onKeyPress(Key key, unsigned int action)
{
    addEvent(key, action, KeyState::Press);
}

void KeyboardMapping::onKeyRelease(Key key, unsigned int action)
{
    addEvent(key, action, KeyState::Release);
}

void KeyboardMapping::onKeyDown(Key key, unsigned int action)
{
    addEvent(key, action, KeyState::Down);
}

std::optional<unsigned int> KeyboardMapping::getHandle(KeyboardEvent ev)
{
    auto handle = mapping.find(ev);
    if (handle == mapping.end()) {
        return std::optional<unsigned int>{std::nullopt};
    }
    return handle->second;
}

void KeyboardMapping::addEvent(Key key, unsigned int action, KeyState state)
{
    mapping.insert(std::make_pair(
        KeyboardEvent {
            .key = key,
            .event = state
        },
        action
    ));
}
