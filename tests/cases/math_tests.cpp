#include "math_tests.hpp"

void MathTest::tangent()
{
    Vec3 tan = Math::calculateTangent(a, b, c);

    assertEquals(1.0, tan.x);
    assertEquals(0.0, tan.y);
    assertEquals(0.0, tan.z);
}

void MathTest::bitangent()
{
    Vec3 btan = Math::calculateBitangent(a, b, c);

    assertEquals(-1.0, btan.x);
    assertEquals(0.0, btan.y);
    assertEquals(0.0, btan.z);
}
