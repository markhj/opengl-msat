#include "opengl_msat/shader/shader_builder.hpp"

std::string ShaderBuilder::build()
{
    buildSource();

    return lines;
}
