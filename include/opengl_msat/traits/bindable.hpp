#ifndef OPENGL_MSAT_BINDABLE_HPP
#define OPENGL_MSAT_BINDABLE_HPP

#include <map>

/**
 * Bindable contract
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
//    static unsigned int id;

//    static Bindable *current, *restoreTo;

    static std::map<const char*, Bindable*> bindMap, restoreTo;

//    bool boundSafely = false;

//    unsigned int localId;

//    unsigned int getInstanceId();

    [[nodiscard]] const char* getClassName() const;
};

#endif
