#ifndef OPENGL_MSAT_VAO_ASSOCIABLE_HPP
#define OPENGL_MSAT_VAO_ASSOCIABLE_HPP


#include "opengl_msat/traits/bindable.hpp"

class VAOAssociable : public Bindable {
public:
    virtual void upload() = 0;

    virtual unsigned int count() = 0;

    virtual unsigned int byteSize() = 0;
};

#endif
