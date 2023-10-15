#ifndef OPENGL_MSAT_VECTORS_HPP
#define OPENGL_MSAT_VECTORS_HPP

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include "opengl_msat/contracts/glm_derivative.hpp"
#include "opengl_msat/contracts/animateable.hpp"

template <typename GlmVectorType>
class Vector : public GlmDerivative<GlmVectorType> {

};

class Vec2 : public glm::vec2,
        public Vector<glm::vec2>,
        public Animateable<Vec2> {
public:
    explicit Vec2(float scalar) : glm::vec2(scalar) { }

    Vec2() : Vec2(0.0) { }

    Vec2(float x, float y) : glm::vec2(x, y) { }

    Vec2(const glm::vec3& other) : glm::vec2(other) { }

    [[nodiscard]] glm::vec2 toGlm() const override;

    void animate(float pct, Vec2 from, Vec2 to) override;

    void animate(Vec2 value) override;
};

class Vec3 : public glm::vec3,
        public Vector<glm::vec3>,
        public Animateable<Vec3> {
public:
    explicit Vec3(float scalar) : glm::vec3(scalar) { }

    Vec3() : Vec3(0.0) { }

    Vec3(float x, float y, float z) : glm::vec3(x, y, z) { }

    Vec3(const glm::vec3& other) : glm::vec3(other) { }

    [[nodiscard]] glm::vec3 toGlm() const override;

    void animate(float pct, Vec3 from, Vec3 to) override;

    void animate(Vec3 value) override;
};

class Vec4 : public glm::vec4,
             public Vector<glm::vec4>,
             public Animateable<Vec4> {
public:
    explicit Vec4(float scalar) : glm::vec4(scalar) { }

    Vec4() : Vec4(0.0) { }

    Vec4(float x, float y, float z, float w) : glm::vec4(x, y, z, w) { }

    Vec4(const glm::vec4& other) : glm::vec4(other) { }

    [[nodiscard]] glm::vec4 toGlm() const override;

    void animate(float pct, Vec4 from, Vec4 to) override;

    void animate(Vec4 value) override;
};

#endif
