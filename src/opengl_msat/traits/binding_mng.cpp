#include "opengl_msat/traits/binding_mng.hpp"

void ManagesMultipleBindings::bindTo(unsigned int target)
{
    if (target > getAvailableSlots()) {
        warn("You are binding a higher slot number than what the current system has available");
    }

    doBindTo(target);
}

void ManagesMultipleBindings::unbind()
{
    bindTo(0);
}

void ManagesMultipleBindings::with(unsigned int slot, const std::function<void()> &callable)
{
    bindTo(slot);
    callable();
    unbind();
}
