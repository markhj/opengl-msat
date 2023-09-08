#ifndef OPENGL_MSAT_KEYBOARD_MAPPING_HPP
#define OPENGL_MSAT_KEYBOARD_MAPPING_HPP

#include <map>
#include <functional>
#include <string>
#include <memory>
#include <optional>
#include "opengl_msat/common.h"
#include "opengl_msat/shared/keyboard_types.hpp"

class KeyboardMapping {
public:
    void onPress(Key key, std::function<void()> action) {
        addEvent(key, action, KeyState::Press);
    }

    void onRelease(Key key, std::function<void()> action) {
        addEvent(key, action, KeyState::Release);
    }

    void whileDown(Key key, std::function<void()> action) {
        addEvent(key, action, KeyState::Down);
    }

    std::optional<std::function<void()>> getHandle(KeyboardEvent ev) {
        auto handle = mapping.find(ev);
        if (handle == mapping.end()) {
            return std::optional<std::function<void()>>{std::nullopt};
        }
        return handle->second;
    }
private:
    std::map<KeyboardEvent, std::function<void()>> mapping;

    void addEvent(Key key, std::function<void()> action, KeyState state)
    {
        mapping.insert(std::make_pair(
            KeyboardEvent {
                .key = key,
                .event = state
            },
            action
        ));
    }
};

#endif
