#include "opengl_msat/geometry/rectangle.hpp"
#include "opengl_msat/math/math.hpp"

void Rectangle3D::construct()
{
    if (b.y == a.y) {
        Vec3 d = {b.x, a.y, a.z};
        Vec3 e = {a.x, b.y, b.z};

        addVertex({.position = a, .color = Color(1.0, 1.0, 1.0), .normal = normal});
        addVertex({.position = d, .color = Color(1.0, 0.0, 1.0), .normal = normal});
        addVertex({.position = b, .color = Color(0.0, 0.0, 1.0), .normal = normal});

        addVertex({.position = a, .color = Color(1.0, 1.0, 1.0), .normal = normal});
        addVertex({.position = e, .color = Color(1.0, 0.0, 1.0), .normal = normal});
        addVertex({.position = b, .color = Color(0.0, 0.0, 1.0), .normal = normal});
    } else {
        Vec3 c = {a.x, b.y, a.z};
        Vec3 e = {b.x, a.y, b.z};

        addVertex({.position = Vec3(a), .color = Color(1.0, 1.0, 1.0), .normal = normal});
        addVertex({.position = Vec3(c), .color = Color(1.0, 0.0, 1.0), .normal = normal});
        addVertex({.position = Vec3(b), .color = Color(0.0, 0.0, 1.0), .normal = normal});

        addVertex({.position = Vec3(a), .color = Color(1.0, 1.0, 1.0), .normal = normal});
        addVertex({.position = Vec3(e), .color = Color(1.0, 0.0, 1.0), .normal = normal});
        addVertex({.position = Vec3(b), .color = Color(0.0, 0.0, 1.0), .normal = normal});
    }
}

Rectangle3D& Rectangle3D::setNormal(Vec3 value)
{
    normal = value;
    return *this;
}

Rectangle2D &Rectangle2D::setNormal(Vec2 value)
{
    normal = value;
    return *this;
}

void Rectangle2D::construct()
{
    addVertex({.position = a, .color = Color(1.0, 1.0, 1.0), .normal = normal});
    addVertex({.position = { b.x, a.y }, .color = Color(1.0, 1.0, 1.0), .normal = normal});
    addVertex({.position = b, .color = Color(1.0, 1.0, 1.0), .normal = normal});

    addVertex({.position = a, .color = Color(1.0, 1.0, 1.0), .normal = normal});
    addVertex({.position = b, .color = Color(1.0, 1.0, 1.0), .normal = normal});
    addVertex({.position = { a.x, b.y }, .color = Color(1.0, 1.0, 1.0), .normal = normal});
}
