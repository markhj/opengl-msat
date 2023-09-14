#include "opengl_msat/controls/keyboard_mapping.hpp"

KeyboardMapping* keyboardMapping = nullptr;

void KeyboardMapping::onPress(Key key, std::function<void()> action)
{
    addEvent(key, action, KeyState::Press);
}

void KeyboardMapping::onRelease(Key key, std::function<void()> action)
{
    addEvent(key, action, KeyState::Release);
}

std::optional<std::function<void()>> KeyboardMapping::getHandle(KeyboardEvent ev)
{
    auto handle = mapping.find(ev);
    if (handle == mapping.end()) {
        return std::optional<std::function<void()>>{std::nullopt};
    }
    return handle->second;
}

void KeyboardMapping::addEvent(Key key, std::function<void()> action, KeyState state)
{
    mapping.insert(std::make_pair(
        KeyboardEvent {
            .key = key,
            .event = state
        },
        action
    ));
}
