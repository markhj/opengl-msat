#ifndef OPENGL_MSAT_VAO_HPP
#define OPENGL_MSAT_VAO_HPP

#include <vector>
#include <memory>
#include "opengl_msat/contracts/bindable.hpp"
#include "opengl_msat/common.h"
#include "opengl_msat/shared/vertex_types.hpp"
#include "vbo.hpp"
#include "opengl_msat/context/context.hpp"

class VAO : public Bindable {
public:
    VAO();

    void bind() override;

    void unbind() override;

    void associate(VBO& vbo, std::vector<VertexAttribute> attributes);

    std::vector<std::reference_wrapper<VBO>> getAssociatedVBOs();
private:
    GLuint vao;

    std::vector<std::reference_wrapper<VBO>> associatedVBOs = {};
};

#endif
