#ifndef OPENGL_MSAT_BINDABLE_HPP
#define OPENGL_MSAT_BINDABLE_HPP

#include <map>

/**
 * Bindable trait
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/lists/bindable-classes/
 */
class Bindable {
public:
    void bind();

    void unbind();

    void safeBind();

    void safeUnbind();

    bool isBound();

    virtual void doBind() = 0;

    virtual void doUnbind() = 0;

protected:
    static std::map<const char*, Bindable*> bindMap, restoreTo;

    [[nodiscard]] const char* getClassName() const;

};

#endif
