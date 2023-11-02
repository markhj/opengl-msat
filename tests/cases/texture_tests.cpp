#include "texture_tests.hpp"

void TextureBindingTest::textureToUnitBinding()
{
    SystemInfo systemInfo {
        .maxTextureUnits = 20,
    };

    // Create two textures
    Texture2D a(100, 100);
    Texture2D b(100, 100);

    // Set up the texture manager
    TextureUnitManager tum(&systemInfo);

    // Bind to texture A and verify that it's reflected,
    // as well as texture B being unaffected
    tum.bindTextureTo(10, &a);
    assertEquals(10, a.boundToUnit.value());
    assertFalse(b.boundToUnit.has_value());

    // Now we bind to texture B to assert that texture A
    // is properly deregistered and texture B has fully "taken over"
    tum.bindTextureTo(10, &b);
    assertFalse(a.boundToUnit.has_value());
    assertEquals(10, b.boundToUnit.value());
}
