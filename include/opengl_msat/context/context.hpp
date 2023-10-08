#ifndef OPENGL_MSAT_CONTEXT_HPP
#define OPENGL_MSAT_CONTEXT_HPP

#include <functional>
#include "opengl_msat/traits/bindable.hpp"
#include "opengl_msat/traits/binding_mng.hpp"

class Context {
public:
    static void with(Bindable& bindable, const std::function<void()>& callable);

    static void safeWith(Bindable& bindable, const std::function<void()>& callable);
};

#endif
