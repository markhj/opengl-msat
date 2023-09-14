
#include "opengl_msat/vertex/vao.hpp"

VAO::VAO()
{
    glGenVertexArrays(1, &vao);
}

void VAO::bind()
{
    glBindVertexArray(vao);
}

void VAO::unbind()
{
    glBindVertexArray(0);
}

void VAO::associate(VBO &vbo, std::vector<VertexAttribute> attributes)
{
    bind();

    associatedVBOs.emplace_back(vbo);

    Context::with(vbo, [&vbo, &attributes]() {
        vbo.upload();

        // Determine total vertex size
        unsigned int totalSize = 0;
        for (VertexAttribute attr : attributes) {
            totalSize += getVertexAttributeSize(attr);
        }

        int i = 0;
        int pos = 0;
        for (VertexAttribute attr : attributes) {
            unsigned int size = getVertexAttributeSize(attr);

            glVertexAttribPointer(i, size, GL_FLOAT, GL_FALSE, totalSize * sizeof(float), (void*)(pos * sizeof(GLfloat)));
            glEnableVertexAttribArray(i);

            i++;
            pos += size;
        }
    });
    unbind();
}

std::vector<std::reference_wrapper<VBO>> VAO::getAssociatedVBOs()
{
    return associatedVBOs;
}
