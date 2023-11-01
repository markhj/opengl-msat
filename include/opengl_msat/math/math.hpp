#ifndef OPENGL_MSAT_MATH_HPP
#define OPENGL_MSAT_MATH_HPP

#include "opengl_msat/geometry/vectors.hpp"
#include "opengl_msat/types/vertex_types.hpp"
#include "opengl_msat/traits/dev_messaging.hpp"

/**
 * Math
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/misc/math/
 */
class Math : DeveloperMessaging {
public:
    [[nodiscard]] static Vec3 calculateNormal(Vec3 a, Vec3 b, Vec3 c);

    [[nodiscard]] static Vec3 calculateTangent(VertexElement3D a,
                                               VertexElement3D b,
                                               VertexElement3D c);

    [[nodiscard]] static Vec3 calculateBitangent(VertexElement3D a,
                                               VertexElement3D b,
                                               VertexElement3D c);
private:
    static Vec3 calcBiAndTan(VertexElement3D a,
                             VertexElement3D b,
                             VertexElement3D c,
                             float factor);

};

#endif
