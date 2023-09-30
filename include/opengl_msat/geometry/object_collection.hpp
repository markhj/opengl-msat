#ifndef OPENGL_MSAT_OBJECT_COLLECTION_HPP
#define OPENGL_MSAT_OBJECT_COLLECTION_HPP

#include "opengl_msat/contracts/exports_vertices.hpp"

template <typename ObjectXD, typename VertexElementXD>
class ObjectCollection :
        public ExportsVertices<VertexElementXD> {
public:
    std::vector<VertexElementXD> getVertices() override
    {
        std::vector<VertexElementXD> list;
        for (ObjectXD obj : objects) {
            std::vector<VertexElementXD> vs = obj.getVertices();
            list.insert(list.end(), vs.begin(), vs.end());
        }
        return list;
    }

    std::vector<GLfloat> getVerticesFlattened(std::vector<VertexAttribute> attributes) override
    {
        std::vector<GLfloat> list;
        for (ObjectXD obj : objects) {
            std::vector<GLfloat> vs = obj.getVerticesFlattened(attributes);
            list.insert(list.end(), vs.begin(), vs.end());
        }
        return list;
    }

    void add(ObjectXD obj)
    {
        objects.push_back(obj);
    }

private:
    std::vector<ObjectXD> objects;
};

#endif
