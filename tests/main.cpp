#include "bbunit.hpp"
#include "opengl_msat/public.hpp"

#include "cases/texture_tests.hpp"
#include "cases/math_tests.hpp"
#include "cases/animation_tests.hpp"

/**
 * It's not possible to initialize GLAD without a GLFW context,
 * which means a window must be created to perform these tests.
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
