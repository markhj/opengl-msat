
#include "opengl_msat/vertex/vao.hpp"

VAO::VAO()
{
    glGenVertexArrays(1, &vao);
}
