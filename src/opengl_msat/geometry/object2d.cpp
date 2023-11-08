#include "opengl_msat/geometry/object2d.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

std::optional<Vec2> rotateVec2IfApplicable(std::optional<Vec2> value, float rotate)
{
    if (!value.has_value()) {
        return value;
    }

    glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), rotate, glm::vec3(0.0f, 0.0f, 1.0f));
    glm::vec2 rotated = glm::vec2(rotationMatrix * glm::vec4(value.value(), 0.0f, 1.0f));
    return Vec2(rotated.x, rotated.y);
}

std::vector <VertexElement2D> Object2D::getVertices()
{
    std::vector<VertexElement2D> list;
    Vec2 center = findCenter2D(vertices);

    for (VertexElement2D v : vertices) {
        if (autoCenter) {
            v.position.x -= center.x;
            v.position.y -= center.y;
        }

        glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), rotate, glm::vec3(0.0f, 0.0f, 1.0f));
        glm::vec2 rotated = glm::vec2(rotationMatrix * glm::vec4(v.position, 0.0f, 1.0f));
        v.position = Vec2(rotated.x, rotated.y);

        v.position *= scale;

        v.position.x += translate.x;
        v.position.y += translate.y;

        v.normal = rotateVec2IfApplicable(v.normal, rotate);
        v.tangent = rotateVec2IfApplicable(v.tangent, rotate);
        v.bitangent = rotateVec2IfApplicable(v.bitangent, rotate);

        list.push_back(v);
    }
    return list;
}

std::vector<GLfloat> Object2D::getVerticesFlattened(std::vector<VertexAttribute> attributes)
{
    return flattenVertices2D(getVertices(), attributes);
}
