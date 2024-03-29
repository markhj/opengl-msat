#ifndef OPENGL_MSAT_VAO_HPP
#define OPENGL_MSAT_VAO_HPP

#include <vector>
#include <memory>
#include "opengl_msat/traits/bindable.hpp"
#include "opengl_msat/common.h"
#include "opengl_msat/types/vertex_types.hpp"
#include "vbo.hpp"
#include "opengl_msat/context/context.hpp"
#include "opengl_msat/contracts/vao_associable.hpp"

/**
 * VAO
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/vertex/vao/
 */
class VAO : public Bindable {
public:
    VAO();

    void doBind() override;

    void doUnbind() override;

    void associate(VAOAssociable& vbo, std::vector<VertexAttribute> attributes);

    std::vector<std::reference_wrapper<VAOAssociable>> getAssociatedVBOs();

    std::optional<std::vector<VertexAttribute>> getAttributesForVBO(VAOAssociable* vbo);

private:
    GLuint vao;

    std::vector<std::reference_wrapper<VAOAssociable>> associatedVBOs = {};

    std::map<VAOAssociable*, std::vector<VertexAttribute>> vboAttributeAssociations = {};

};

#endif
