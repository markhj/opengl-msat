#ifndef OPENGL_MSAT_OBJECT3D_HPP
#define OPENGL_MSAT_OBJECT3D_HPP

#include <iostream>
#include "object_wrapper.hpp"

class Object3D : public ObjectWrapper<VertexElement3D, Vec3> {
public:
    std::vector<VertexElement3D> getVertices() override
    {
        std::vector<VertexElement3D> list;
        for (VertexElement3D v : vertices) {
            v.position.x += translation.x;
            v.position.y += translation.y;
            v.position.z += translation.z;
            list.push_back(v);
        }
        return list;
    }

    std::vector<GLfloat> getVerticesFlattened(std::vector<VertexAttribute> attributes) override
    {
        std::vector<GLfloat> list = {};
        for (VertexElement3D vertex : getVertices()) {
            for (VertexAttribute attr : attributes) {
                switch (attr) {
                    case VertexAttribute::Position3D:
                        list.insert(list.end(), {vertex.position.x, vertex.position.y, vertex.position.z});
                        break;
                    case VertexAttribute::Normal3D:
                        if (vertex.normal.has_value()) {
                            list.insert(list.end(), {vertex.normal.value().x,
                                                     vertex.normal.value().y,
                                                     vertex.normal.value().z});
                        } else {
                            list.insert(list.end(), {0.0, 0.0, 0.0});
                        }
                        break;
                    case VertexAttribute::ColorRGB:
                        list.insert(list.end(), {vertex.color.r, vertex.color.g, vertex.color.b});
                        break;
                    default:
                        std::cout << "WARNING: Implementation missing in Object3D::getVerticesFlattened: "
                            << getVertexAttributeVarName(attr)
                            << std::endl;
                }
            }
        }
        return list;
    }
};

#endif
