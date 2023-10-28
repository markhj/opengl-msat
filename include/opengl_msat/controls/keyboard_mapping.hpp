#ifndef OPENGL_MSAT_KEYBOARD_MAPPING_HPP
#define OPENGL_MSAT_KEYBOARD_MAPPING_HPP

#include <map>
#include <functional>
#include <string>
#include <memory>
#include <optional>
#include "opengl_msat/common.h"
#include "keyboard_types.hpp"

/**
 * Keyboard mapping
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/controls/keyboard/
 */
class KeyboardMapping {
public:
    void onPress(Key key, std::function<void()> action);

    void onRelease(Key key, std::function<void()> action);

    std::optional<std::function<void()>> getHandle(KeyboardEvent ev);
private:
    std::map<KeyboardEvent, std::function<void()>> mapping;

    void addEvent(Key key, std::function<void()> action, KeyState state);
};

#endif
