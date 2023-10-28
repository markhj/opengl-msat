#ifndef OPENGL_MSAT_SHADER_BUILDER_HPP
#define OPENGL_MSAT_SHADER_BUILDER_HPP

#include <iostream>
#include "opengl_msat/types/vertex_types.hpp"

class ShaderBuilder {
public:
    virtual void buildSource() = 0;

    std::string build();

    void addLine(const std::string& line);

    void in(VertexAttribute attribute);

    void out(VertexAttribute attribute);

    void print();

protected:
    std::string lines = "#version 330 core\n";

};

#endif
