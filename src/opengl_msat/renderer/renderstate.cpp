#include "opengl_msat/renderer/renderstate.hpp"

void RenderState::reset()
{
    for (auto item : mapping) {
        set(item.first, getDefault(item.first));
    }
}

void RenderState::set(RenderOption option, bool value)
{
    current[option] = value;

    if (value) {
        glEnable(mapping[option]);
    } else {
        glDisable(mapping[option]);
    }
}

void RenderState::setDefault(RenderOption option, bool value)
{
    defaults[option] = value;
}

void RenderState::enable(RenderOption option)
{
    set(option, true);
}

void RenderState::disable(RenderOption option)
{
    set(option, false);
}

bool RenderState::isEnabled(RenderOption option)
{
    return glIsEnabled(mapping[option]);
}

bool RenderState::getDefault(RenderOption option)
{
    return defaults[option];
}

RenderState::RenderState()
{
    reset();
}
