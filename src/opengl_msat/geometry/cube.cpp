#include "opengl_msat/geometry/cube.hpp"
#include "opengl_msat/geometry/rectangle.hpp"

void Cube::construct()
{
    // Front:
    addVertices(Rectangle3D(a, Vec3(b.x, b.y, a.z))
        .setNormal(Vec3(0.0, 0.0, -1.0))
        .getVertices());

    // Back:
    addVertices(Rectangle3D(b, Vec3(a.x, a.y, b.z))
        .setNormal(Vec3(0.0, 0.0, 1.0))
        .getVertices());

    // Left:
    addVertices(Rectangle3D(a, Vec3(a.x, b.y, b.z))
        .setNormal(Vec3(-1.0, 0.0, 0.0))
        .getVertices());

    // Right:
    addVertices(Rectangle3D(b, Vec3(b.x, a.y, a.z))
        .setNormal(Vec3(1.0, 0.0, 0.0))
        .getVertices());

    // Bottom:
    addVertices(Rectangle3D(a, Vec3(b.x, a.y, b.z))
        .setNormal(Vec3(0.0, -1.0, 0.0))
        .getVertices());

    // Top:
    addVertices(Rectangle3D(b, Vec3(a.x, b.y, a.z))
        .setNormal(Vec3(0.0, 1.0, 0.0))
        .getVertices());
}
