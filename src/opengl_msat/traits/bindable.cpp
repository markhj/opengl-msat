#include "opengl_msat/traits/bindable.hpp"

#include <iostream>

std::map<const char*, Bindable*> Bindable::bindMap = {};

std::map<const char*, Bindable*> Bindable::restoreTo = {};

void Bindable::bind()
{
    bindMap[getClassName()] = this;
    doBind();
}

void Bindable::unbind()
{
    bindMap.erase(getClassName());
    restoreTo.erase(getClassName());
    doUnbind();
}

void Bindable::safeBind()
{
    auto current = bindMap.find(getClassName());
    if (current != restoreTo.end()) {
        restoreTo[getClassName()] = current->second;
    }

    bind();
}

void Bindable::safeUnbind()
{
    auto r = restoreTo.find(getClassName());
    Bindable* target = nullptr;
    if (r != restoreTo.end()) {
        target = r->second;
    }

    unbind();

    if (target != nullptr) {
        target->bind();
    }
}

const char *Bindable::getClassName() const
{
    return typeid(*this).name();
}

bool Bindable::isBound()
{
    auto current = bindMap.find(getClassName());

    return current != bindMap.end() && current->second == this;
}
