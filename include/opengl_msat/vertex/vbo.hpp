#ifndef OPENGL_MSAT_VBO_HPP
#define OPENGL_MSAT_VBO_HPP

#include <utility>
#include <vector>
#include "opengl_msat/common.h"
#include "opengl_msat/contracts/bindable.hpp"

class VBO : public Bindable {
public:
    VBO();

    VBO(std::vector<GLfloat> vertices);

    void bind() override;

    void unbind() override;

    void setVertices(std::vector<GLfloat> values);

    void upload() const;

    [[nodiscard]] unsigned int count() const;

    [[nodiscard]] unsigned int byteSize() const;
private:
    GLuint vbo;

    std::vector<GLfloat> vertices;

    GLenum draw = GL_DYNAMIC_DRAW;
};

#endif
