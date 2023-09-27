#include "opengl_msat/geometry/cube.hpp"
#include "opengl_msat/geometry/rectangle.hpp"

void Cube::construct()
{
    // Front:
    addVertices(Rectangle(a, Vec3(b.x, b.y, a.z)).getVertices());

    // Back:
    addVertices(Rectangle(b, Vec3(a.x, a.y, b.z)).getVertices());

    // Left:
    addVertices(Rectangle(a, Vec3(a.x, b.y, b.z)).getVertices());

    // Right:
    addVertices(Rectangle(b, Vec3(b.x, a.y, a.z)).getVertices());

    // Bottom:
    addVertices(Rectangle(a, Vec3(b.x, a.y, b.z)).getVertices());

    // Top:
    addVertices(Rectangle(b, Vec3(a.x, b.y, a.z)).getVertices());
}
