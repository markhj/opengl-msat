#ifndef OPENGL_MSAT_VAO_HPP
#define OPENGL_MSAT_VAO_HPP

#include <vector>
#include "opengl_msat/contracts/bindable.hpp"
#include "opengl_msat/common.h"
#include "opengl_msat/shared/vertex_types.hpp"
#include "vbo.hpp"
#include "opengl_msat/context/context.hpp"

class VAO : public Bindable {
public:
    VAO();

    void bind() override
    {
        glBindVertexArray(vao);
    }

    void unbind() override
    {
        glBindVertexArray(0);
    }

    void associate(VBO& vbo, std::vector<VertexAttribute> attributes)
    {
        bind();
        associatedVBOs.push_back(vbo);
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
private:
    GLuint vao;

    std::vector<VBO> associatedVBOs = {};
};

#endif
