#ifndef OPENGL_MSAT_VBO_HPP
#define OPENGL_MSAT_VBO_HPP

#include <utility>
#include <vector>
#include "opengl_msat/common.h"
#include "opengl_msat/traits/bindable.hpp"
#include "opengl_msat/types/vertex_types.hpp"
#include "opengl_msat/contracts/exports_vertices.hpp"
#include "opengl_msat/contracts/vao_associable.hpp"

/**
 * VBO
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/vertex/vbo/
 */
class VBO : public VAOAssociable {
public:
    VBO();

    explicit VBO(std::vector<GLfloat> vertices);

    void doBind() override;

    void doUnbind() override;

    void setVertices(std::vector<GLfloat> values);

    void substitute(std::vector<GLfloat> values, unsigned int from);

    void upload() override;

    /**
     * Returns the total number of float values (irrespective of how they are sorted
     * into vertices)
     *
     * @return unsigned int
     */
    [[nodiscard]] unsigned int count() override;

    [[nodiscard]] unsigned int byteSize() override;

    /**
     * Returns the total number of vertices according to the
     * size of the provided attributes
     *
     * @param std::vector<VertexAttribute> attributes
     * @return unsigned int
     */
    [[nodiscard]] unsigned int countVertices(std::vector<VertexAttribute> attributes) override;

private:
    GLuint vbo;

    std::vector<GLfloat> vertices;

    GLenum draw = GL_DYNAMIC_DRAW;
};

#endif
