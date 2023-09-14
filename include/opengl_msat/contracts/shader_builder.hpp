#ifndef OPENGL_MSAT_SHADER_BUILDER_HPP
#define OPENGL_MSAT_SHADER_BUILDER_HPP

#include <iostream>

class ShaderBuilder {
public:
    virtual std::string build() = 0;
};

#endif
