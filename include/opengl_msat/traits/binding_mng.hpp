#ifndef OPENGL_MSAT_BINDING_MNG_HPP
#define OPENGL_MSAT_BINDING_MNG_HPP

#include <optional>
#include <functional>
#include <iostream>

/**
 * Trait for classes which handles bindings of "slot based" concepts
 * such as texture units
 *
 * This trait assumes the concept cannot be completely unbound, and that
 * "unbinding" will resort to the first/default of its kind. For example,
 * when unbinding a texture unit (glActiveTexture(0)) it returns to
 * GL_TEXTURE0 rather than "nothing"
 */

template <typename T>
class ManagesMultipleBindings {
public:
    void bindTo(T target)
    {
        doBindTo(target);
    }

    void unbind()
    {
        bindTo(0);
    }

    void with(unsigned int slot, const std::function<void()>& callable)
    {
        bindTo(slot);
        callable();
        unbind();
    }

    virtual unsigned int getAvailableSlots() const = 0;

    virtual T getBoundTo() const = 0;

protected:
    virtual void doBindTo(T target) = 0;

};

#endif
