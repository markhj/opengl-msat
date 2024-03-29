
#include <iostream>
#include <cmath>
#include "opengl_msat/vertex/vbo.hpp"


VBO::VBO()
{
    glGenBuffers(1, &vbo);
}

VBO::VBO(std::vector<GLfloat> vertices)
{
    setVertices(vertices);
    glGenBuffers(1, &vbo);
}

void VBO::doBind()
{
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
}

void VBO::doUnbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::setVertices(std::vector<GLfloat> values)
{
    vertices = std::move(values);
}

void VBO::upload()
{
    safeBind();
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), draw);
    safeUnbind();
}

unsigned int VBO::count()
{
    return vertices.size();
}

unsigned int VBO::byteSize()
{
    return count() * sizeof(GLfloat);
}

void VBO::substitute(std::vector<GLfloat> values, unsigned int from)
{
    safeBind();
    glBufferSubData(GL_ARRAY_BUFFER,
                    from * sizeof(GLfloat),
                    values.size() * sizeof(GLfloat),
                    values.data());
    safeUnbind();
}

unsigned int VBO::countVertices(std::vector<VertexAttribute> attributes)
{
    unsigned int sizeOfAttribs = 0;
    for (VertexAttribute attribute : attributes) {
        sizeOfAttribs += getVertexAttributeSize(attribute);
    }
    return floor(count() / sizeOfAttribs);
}
