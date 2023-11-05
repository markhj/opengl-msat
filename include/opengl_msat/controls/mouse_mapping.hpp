#ifndef OPENGL_MSAT_MOUSE_MAPPING_HPP
#define OPENGL_MSAT_MOUSE_MAPPING_HPP

#include <optional>
#include <functional>
#include "control_types.hpp"

/**
 * Mouse
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/controls/mouse-mapping/
 */
class MouseMapping {
public:
    void onButtonPress(MouseButton button, unsigned int signal);

    void onButtonRelease(MouseButton button, unsigned int signal);

    void onButtonDown(MouseButton button, unsigned int signal);

    void onMove(std::function<void(CursorMoved cursorMoved)> func);

    std::optional<std::function<void(CursorMoved cursorMoved)>> getOnMove();

    std::optional<unsigned int> getHandle(MouseButtonEvent ev);

private:
    std::map<MouseButtonEvent, unsigned int> mapping;

    void addEvent(MouseButton button, unsigned int action, MouseButtonState state);

    std::optional<std::function<void(CursorMoved cursorMoved)>> onMoveFunc = std::nullopt;

};

#endif
