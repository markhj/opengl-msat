#ifndef OPENGL_MSAT_GLM_DERIVATIVE_HPP
#define OPENGL_MSAT_GLM_DERIVATIVE_HPP

template <typename GlmType>
class GlmDerivative {
public:
    virtual GlmType toGlm() const = 0;
};

#endif
