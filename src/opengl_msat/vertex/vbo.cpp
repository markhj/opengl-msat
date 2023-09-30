
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

unsigned int VBO::count() const
{
    return vertices.size();
}

unsigned int VBO::byteSize() const
{
    return count() * sizeof(GLfloat);
}
