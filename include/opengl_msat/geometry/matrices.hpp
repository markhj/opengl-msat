#ifndef OPENGL_MSAT_MATRICES_HPP
#define OPENGL_MSAT_MATRICES_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "opengl_msat/contracts/glm_derivative.hpp"

class Matrix : public GlmDerivative {

};

class Mat4 : public glm::mat4, public Matrix {
public:
    explicit Mat4(float val) : glm::mat4(val) { }

    Mat4(const glm::mat4& other) : glm::mat4(other) { }

    glm::mat4 toGlm() const;
};

#endif
