#ifndef OPENGL_MSAT_TEXTURE_TESTS_HPP
#define OPENGL_MSAT_TEXTURE_TESTS_HPP

#include "bbunit.hpp"
#include "opengl_msat/public.hpp"

class TextureBindingTest : public BBUnit::TestCase {
public:
    /**
     * Tests that the TextureUnitManager correctly sets and
     * tracks when textures are bound to various slots
     */
    void textureToUnitBinding();

};


#endif
