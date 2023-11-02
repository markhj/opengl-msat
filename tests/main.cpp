#include "bbunit.hpp"
#include "opengl_msat/public.hpp"

#include "cases/texture_tests.hpp"
#include "cases/math_tests.hpp"

/**
 * @todo Figure out if it's possible to initialize GLAD and GLFW
 *      without generating a window
 */
int main()
{
    Window window(100, 100, "Test");
    window.generate();

    BBUnit::TestSuite<TextureBindingTest> textureBindings(&TextureBindingTest::textureToUnitBinding);
    BBUnit::TestSuite<MathTest> math(&MathTest::tangent,
                                     &MathTest::bitangent);

    BBUnit::TestRunner().run(textureBindings, math);

    return 0;
}
