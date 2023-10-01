#ifndef OPENGL_MSAT_HANDLES_ATTRIBUTES_HPP
#define OPENGL_MSAT_HANDLES_ATTRIBUTES_HPP

#include <vector>
#include "opengl_msat/shared/vertex_types.hpp"

class HandlesAttributes {
protected:
    unsigned int getSizeOfAttributes(std::vector<VertexAttribute>& attributes) const;

};

#endif
