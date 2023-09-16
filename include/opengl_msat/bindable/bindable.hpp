#ifndef OPENGL_MSAT_BINDABLE_HPP
#define OPENGL_MSAT_BINDABLE_HPP

/**
 * Bindable contract
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/lists/bindable-classes/
 */
class Bindable {
public:
    void bind();

    void unbind();

    virtual void doBind() = 0;

    virtual void doUnbind() = 0;
};

#endif
