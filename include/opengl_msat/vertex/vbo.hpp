#ifndef OPENGL_MSAT_VBO_HPP
#define OPENGL_MSAT_VBO_HPP

#include <utility>
#include <vector>
#include "opengl_msat/common.h"
#include "opengl_msat/contracts/bindable.hpp"

class VBO : public Bindable {
public:
    VBO(std::vector<GLfloat>& values) : vertices(values)
    {
        glGenBuffers(1, &vbo);
    }

    void bind() override
    {
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
    }

    void unbind() override
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void setVertices(std::vector<GLfloat>& values)
    {
        vertices = values;
    }

    void upload() const
    {
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), draw);
    }
private:
    GLuint vbo;

    std::vector<GLfloat>& vertices;

    GLenum draw = GL_DYNAMIC_DRAW;
};

#endif
