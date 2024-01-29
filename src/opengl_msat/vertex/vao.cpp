
#include "opengl_msat/vertex/vao.hpp"

VAO::VAO()
{
    glGenVertexArrays(1, &vao);
}

void VAO::doBind()
{
    glBindVertexArray(vao);
}

void VAO::doUnbind()
{
    glBindVertexArray(0);
}

void VAO::associate(VAOAssociable &vbo, std::vector<VertexAttribute> attributes)
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

            glVertexAttribPointer(i, size, getVertexAttributeDataType(attr), GL_FALSE, totalSize * sizeof(float), (void*)(pos * sizeof(GLfloat)));
            glEnableVertexAttribArray(i);

            i++;
            pos += size;
        }
    });

    vboAttributeAssociations[&vbo] = attributes;

    unbind();
}

std::vector<std::reference_wrapper<VAOAssociable>> VAO::getAssociatedVBOs()
{
    return associatedVBOs;
}

std::optional<std::vector<VertexAttribute>> VAO::getAttributesForVBO(VAOAssociable *vbo)
{
    auto it = vboAttributeAssociations.find(vbo);
    if (it != vboAttributeAssociations.end()) {
        return it->second;
    }
    return std::nullopt;
}
