#include "bbunit.hpp"
#include "opengl_msat/public.hpp"

#include "cases/texture_tests.hpp"

/**
 * @todo Figure out if it's possible to initialize GLAD and GLFW
 *      without generating a window
 */
int main()
{
    Window window(100, 100, "Test");
    window.generate();

    BBUnit::TestSuite<TextureBindingTest> mySuite(&TextureBindingTest::textureToUnitBinding);

    BBUnit::TestRunner().run(mySuite);

    return 0;
}
