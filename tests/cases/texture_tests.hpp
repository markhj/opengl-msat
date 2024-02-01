#ifndef OPENGL_MSAT_TEXTURE_TESTS_HPP
#define OPENGL_MSAT_TEXTURE_TESTS_HPP

#include <bbunit/bbunit.hpp>
#include "opengl_msat/public.hpp"

class TextureBindingTest : public BBUnit::TestCase {
public:
    /**
     * Tests that the TextureUnitManager correctly sets and
     * tracks when textures are bound to various slots
     */
    void textureToUnitBinding();

    /**
     * Test of the lock, unlock and isLocked methods
     */
    void lockUnlock();

    /**
     * A test to ensure that a unit cannot be overwritten while
     * it is locked
     */
    void lock();

};


#endif
