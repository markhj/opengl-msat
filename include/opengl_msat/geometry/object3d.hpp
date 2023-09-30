#ifndef OPENGL_MSAT_OBJECT3D_HPP
#define OPENGL_MSAT_OBJECT3D_HPP

#include <iostream>
#include "object_wrapper.hpp"

class Object3D : public ObjectWrapper<VertexElement3D> {
public:
    std::vector<GLfloat> getVerticesFlattened(std::vector<VertexAttribute> attributes) override
    {
        std::vector<GLfloat> list = {};
        for (VertexElement3D vertex : vertices) {
            for (VertexAttribute attr : attributes) {
                switch (attr) {
                    case VertexAttribute::Position3D:
                        list.push_back(vertex.position.x);
                        list.push_back(vertex.position.y);
                        list.push_back(vertex.position.z);
                        break;
                    case VertexAttribute::Normal3D:
                        if (vertex.normal.has_value()) {
                            list.push_back(vertex.normal.value().x);
                            list.push_back(vertex.normal.value().y);
                            list.push_back(vertex.normal.value().z);
                        } else {
                            list.push_back(0.0);
                            list.push_back(0.0);
                            list.push_back(0.0);
                        }
                        break;
                    case VertexAttribute::ColorRGB:
                        list.push_back(vertex.color.r);
                        list.push_back(vertex.color.g);
                        list.push_back(vertex.color.b);
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
