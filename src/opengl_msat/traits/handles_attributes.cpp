#include "opengl_msat/traits/handles_attributes.hpp"

unsigned int HandlesAttributes::getSizeOfAttributes(std::vector<VertexAttribute>& attributes) const
{
    unsigned int size = 0;
    for (VertexAttribute attr : attributes) {
        size += getVertexAttributeSize(attr);
    }
    return size;
}
