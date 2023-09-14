#ifndef OPENGL_MSAT_MATRICES_HPP
#define OPENGL_MSAT_MATRICES_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "opengl_msat/contracts/glm_derivative.hpp"

template <typename GlmMatrixType>
class Matrix : public GlmDerivative<GlmMatrixType> {

};

class Mat4 : public glm::mat4, public Matrix<glm::mat4> {
public:
    explicit Mat4(float val) : glm::mat4(val) { }

    Mat4(const glm::mat4& other) : glm::mat4(other) { }

    [[nodiscard]] glm::mat4 toGlm() const override;
};

#endif
