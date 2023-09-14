#include "opengl_msat/context/context.hpp"

void Context::with(Bindable &bindable, const std::function<void()> &callable)
{
    bindable.bind();
    callable();
    bindable.unbind();
}
