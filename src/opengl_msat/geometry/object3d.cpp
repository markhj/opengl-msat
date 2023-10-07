#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "opengl_msat/geometry/object3d.hpp"

std::vector<VertexElement3D> Object3D::getVertices()
{
    std::vector<VertexElement3D> list;
    Vec3 center = findCenter3D(vertices);

    for (VertexElement3D v : vertices) {
        // Simulate moving the object to the center
        v.position.x -= center.x;
        v.position.y -= center.y;
        v.position.z -= center.z;

        glm::mat4 rx = glm::rotate(glm::mat4(1.0f), rotate.x, glm::vec3(1.0f, 0.0f, 0.0f));
        glm::mat4 ry = glm::rotate(glm::mat4(1.0f), rotate.y, glm::vec3(0.0f, 1.0f, 0.0f));
        glm::mat4 rz = glm::rotate(glm::mat4(1.0f), rotate.z, glm::vec3(0.0f, 0.0f, 1.0f));
        v.position = glm::vec3(rx * ry * rz * glm::vec4(v.position, 1.0f));

        v.position *= scale;

        v.position.x += translate.x;
        v.position.y += translate.y;
        v.position.z += translate.z;

        list.push_back(v);
    }
    return list;
}

std::vector<GLfloat> Object3D::getVerticesFlattened(std::vector<VertexAttribute> attributes)
{
    return flattenVertices3D(getVertices(), attributes);
}
