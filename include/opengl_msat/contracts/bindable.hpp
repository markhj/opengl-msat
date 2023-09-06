#ifndef OPENGL_MSAT_BINDABLE_HPP
#define OPENGL_MSAT_BINDABLE_HPP

class Bindable {
public:
    virtual void bind() = 0;

    virtual void unbind() = 0;
};

#endif
