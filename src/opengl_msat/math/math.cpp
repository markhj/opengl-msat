#include <glm/geometric.hpp>
#include "opengl_msat/math/math.hpp"

Vec3 Math::calculateNormal(Vec3 a, Vec3 b, Vec3 c)
{
    return glm::normalize(glm::cross(b - a, c - a));
}

Vec3 Math::calculateTangent(VertexElement3D a, VertexElement3D b, VertexElement3D c)
{
    return calcBiAndTan(a, b, c, 1);
}

Vec3 Math::calculateBitangent(VertexElement3D a, VertexElement3D b, VertexElement3D c)
{
    return calcBiAndTan(a, b, c, -1);
}

Vec3 Math::calcBiAndTan(VertexElement3D a, VertexElement3D b, VertexElement3D c, float factor)
{
    if (
        !a.textureCoords.has_value()
        || !b.textureCoords.has_value()
        || !c.textureCoords.has_value()
    ) {
        warn("Cannot calculate (bi-)tangent without texture coordinate.");
        return Vec3(0.0);
    }

    glm::vec3 edge1 = b.position - a.position;
    glm::vec3 edge2 = c.position - a.position;
    glm::vec2 deltaUV1 = b.textureCoords.value() - a.textureCoords.value();
    glm::vec2 deltaUV2 = c.textureCoords.value() - a.textureCoords.value();

    float f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);

    glm::vec3 result;
    result.x = f * (factor * deltaUV2.y * edge1.x - factor * deltaUV1.y * edge2.x);
    result.y = f * (factor * deltaUV2.y * edge1.y - factor * deltaUV1.y * edge2.y);
    result.z = f * (factor * deltaUV2.y * edge1.z - factor * deltaUV1.y * edge2.z);

    return Vec3(result);
}
