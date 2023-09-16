#ifndef OPENGL_MSAT_RENDERSTATE_HPP
#define OPENGL_MSAT_RENDERSTATE_HPP

#include <map>
#include <iostream>
#include "opengl_msat/shared/render_types.hpp"

class RenderState {
public:
    RenderState();

    void reset();

    void set(RenderOption option, bool value);

    void setDefault(RenderOption option, bool value);

    void enable(RenderOption option);

    void disable(RenderOption option);

    bool isEnabled(RenderOption option);

    bool getDefault(RenderOption option);
private:
    std::map<RenderOption, bool> current;

    std::map<RenderOption, bool> defaults = {
        {RenderOption::DepthTesting, true},
        {RenderOption::StencilTesting, false},
        {RenderOption::Blend, false},
        {RenderOption::FaceCulling, false}
    };

    std::map<RenderOption, GLenum> mapping = {
        {RenderOption::DepthTesting, GL_DEPTH_TEST},
        {RenderOption::StencilTesting, GL_STENCIL_TEST},
        {RenderOption::Blend, GL_BLEND},
        {RenderOption::FaceCulling, GL_CULL_FACE}
    };
};

#endif
