#ifndef OPENGL_MSAT_CONTEXT_HPP
#define OPENGL_MSAT_CONTEXT_HPP

#include <functional>
#include "opengl_msat/contracts/bindable.hpp"

class Context {
public:
    static void with(Bindable& bindable, const std::function<void()>& callable) {
        bindable.bind();
        callable();
        bindable.unbind();
    }
};

#endif
