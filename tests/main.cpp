#include "bbunit.hpp"
#include "opengl_msat/public.hpp"

#include "cases/texture_tests.hpp"
#include "cases/math_tests.hpp"
#include "cases/animation_tests.hpp"

/**
 * @todo Figure out if it's possible to initialize GLAD and GLFW
 *      without generating a window
 */
int main()
{
    Window window(100, 100, "Test");
    window.generate();

    DeveloperMessaging::warningBehavior = MessagingBehavior::Silent;

    BBUnit::TestSuite<TextureBindingTest> textureBindings(
            &TextureBindingTest::textureToUnitBinding,
            &TextureBindingTest::lockUnlock,
            &TextureBindingTest::lock
            );

    BBUnit::TestSuite<MathTest> math(
            &MathTest::tangent,
            &MathTest::bitangent
            );
    
    BBUnit::TestSuite<AnimationTest> animation(
            &AnimationTest::validateInterval
            );

    BBUnit::TestRunner().run(textureBindings, math, animation);

    return 0;
}
