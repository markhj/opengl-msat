#ifndef OPENGL_MSAT_MOUSE_MAPPING_HPP
#define OPENGL_MSAT_MOUSE_MAPPING_HPP

#include <optional>
#include "control_types.hpp"

class MouseMapping {
public:
    void onButtonPress(MouseButton button, unsigned int signal);

    void onButtonRelease(MouseButton button, unsigned int signal);

    void onButtonDown(MouseButton button, unsigned int signal);

    std::optional<unsigned int> getHandle(MouseButtonEvent ev);

private:
    std::map<MouseButtonEvent, unsigned int> mapping;

    void addEvent(MouseButton button, unsigned int action, MouseButtonState state);

};

#endif
