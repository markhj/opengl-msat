#include <cmath>
#include "opengl_msat/geometry/regular_polygon.hpp"

void RegularPolygon2D::construct()
{
    double currentAngle = 0.0;
    for (unsigned int i = 1; i <= sides; i++) {
        double nextAngle = i * 2 * M_PI / sides;
        addVertex({
            .position = Vec2(radius * sin(nextAngle), radius * cos(nextAngle)),
            .color = Color(1.0, 1.0, 1.0),
        });
        addVertex({
            .position = Vec2(radius * sin(currentAngle), radius * cos(currentAngle)),
            .color = Color(1.0, 1.0, 1.0),
        });
        addVertex({
            .position = Vec2(0.0),
            .color = Color(1.0, 1.0, 1.0),
        });
        currentAngle = nextAngle;
    }
}
