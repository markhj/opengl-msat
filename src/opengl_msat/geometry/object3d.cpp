#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "opengl_msat/geometry/object3d.hpp"

std::optional<Vec3> rotateVec3IfApplicable(std::optional<Vec3> value, Vec3 rotate)
{
    if (!value.has_value()) {
        return value;
    }

    glm::mat4 rx = glm::rotate(glm::mat4(1.0f), rotate.x, glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 ry = glm::rotate(glm::mat4(1.0f), rotate.y, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 rz = glm::rotate(glm::mat4(1.0f), rotate.z, glm::vec3(0.0f, 0.0f, 1.0f));

    return glm::vec3(rx * ry * rz * glm::vec4(value.value(), 1.0f));
}

std::vector<VertexElement3D> Object3D::getVertices()
{
    std::vector<VertexElement3D> list;
    Vec3 center = findCenter3D(vertices);

    for (VertexElement3D v : vertices) {
        // Simulate moving the object to the center
        if (autoCenter) {
            v.position.x -= center.x;
            v.position.y -= center.y;
            v.position.z -= center.z;
        }

        glm::mat4 rx = glm::rotate(glm::mat4(1.0f), rotate.x, glm::vec3(1.0f, 0.0f, 0.0f));
        glm::mat4 ry = glm::rotate(glm::mat4(1.0f), rotate.y, glm::vec3(0.0f, 1.0f, 0.0f));
        glm::mat4 rz = glm::rotate(glm::mat4(1.0f), rotate.z, glm::vec3(0.0f, 0.0f, 1.0f));
        v.position = glm::vec3(rx * ry * rz * glm::vec4(v.position, 1.0f));

        v.position *= scale;

        v.position.x += translate.x;
        v.position.y += translate.y;
        v.position.z += translate.z;

        v.normal = rotateVec3IfApplicable(v.normal, rotate);
        v.tangent = rotateVec3IfApplicable(v.tangent, rotate);
        v.bitangent = rotateVec3IfApplicable(v.bitangent, rotate);

        list.push_back(v);
    }
    return list;
}

std::vector<GLfloat> Object3D::getVerticesFlattened(const std::vector<VertexAttribute>& attributes)
{
    return flattenVertices3D(getVertices(), attributes);
}
