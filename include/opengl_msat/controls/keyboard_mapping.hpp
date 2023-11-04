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
    void onKeyPress(Key key, unsigned int signal);

    void onKeyRelease(Key key, unsigned int signal);

    void onKeyDown(Key key, unsigned int signal);

    std::optional<unsigned int> getHandle(KeyboardEvent ev);

private:
    std::map<KeyboardEvent, unsigned int> mapping;

    void addEvent(Key key, unsigned int action, KeyState state);

};

#endif
