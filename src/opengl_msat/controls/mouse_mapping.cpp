#include "opengl_msat/controls/mouse_mapping.hpp"

void MouseMapping::onButtonPress(MouseButton button, unsigned int signal)
{
    addEvent(button, signal, MouseButtonState::Press);
}

void MouseMapping::onButtonRelease(MouseButton button, unsigned int signal)
{
    addEvent(button, signal, MouseButtonState::Release);
}

void MouseMapping::onButtonDown(MouseButton button, unsigned int signal)
{
    addEvent(button, signal, MouseButtonState::Down);
}

std::optional<unsigned int> MouseMapping::getHandle(MouseButtonEvent ev)
{
    auto handle = mapping.find(ev);
    if (handle == mapping.end()) {
        return std::optional<unsigned int>{std::nullopt};
    }
    return handle->second;
}

void MouseMapping::addEvent(MouseButton button, unsigned int action, MouseButtonState state)
{
    mapping.insert(std::make_pair(
        MouseButtonEvent {
            .button = button,
            .event = state
        },
        action
    ));
}
