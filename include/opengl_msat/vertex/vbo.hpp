#ifndef OPENGL_MSAT_VBO_HPP
#define OPENGL_MSAT_VBO_HPP

#include <utility>
#include <vector>
#include "opengl_msat/common.h"
#include "opengl_msat/bindable/bindable.hpp"
#include "opengl_msat/shared/vertex_types.hpp"
#include "opengl_msat/contracts/exports_vertices.hpp"

class VBO : public Bindable {
public:
    VBO();

    explicit VBO(std::vector<GLfloat> vertices);

    void doBind() override;

    void doUnbind() override;

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
