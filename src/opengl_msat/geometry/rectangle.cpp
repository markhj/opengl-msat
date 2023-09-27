#include "opengl_msat/geometry/rectangle.hpp"

void Rectangle::construct()
{
    if (b.y == a.y) {
        Vec3 d = {b.x, a.y, a.z};
        Vec3 e = {a.x, b.y, b.z};

        addVertex({.position = a, .color = Color(1.0, 1.0, 1.0)});
        addVertex({.position = d, .color = Color(1.0, 0.0, 1.0)});
        addVertex({.position = b, .color = Color(0.0, 0.0, 1.0)});

        addVertex({.position = a, .color = Color(1.0, 1.0, 1.0)});
        addVertex({.position = e, .color = Color(1.0, 0.0, 1.0)});
        addVertex({.position = b, .color = Color(0.0, 0.0, 1.0)});
    } else {
        Vec3 c = {a.x, b.y, a.z};
        Vec3 e = {b.x, a.y, b.z};

        addVertex({.position = Vec3(a), .color = Color(1.0, 1.0, 1.0)});
        addVertex({.position = Vec3(c), .color = Color(1.0, 0.0, 1.0)});
        addVertex({.position = Vec3(b), .color = Color(0.0, 0.0, 1.0)});

        addVertex({.position = Vec3(a), .color = Color(1.0, 1.0, 1.0)});
        addVertex({.position = Vec3(e), .color = Color(1.0, 0.0, 1.0)});
        addVertex({.position = Vec3(b), .color = Color(0.0, 0.0, 1.0)});
    }
}
