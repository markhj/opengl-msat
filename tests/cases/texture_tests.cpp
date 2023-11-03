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

void TextureBindingTest::lockUnlock()
{
    SystemInfo systemInfo {
            .maxTextureUnits = 20,
    };

    // Set up the texture manager
    TextureUnitManager tum(&systemInfo);

    // Initial integrity check:
    assertFalse(tum.isLocked(5));
    assertFalse(tum.isLocked(10));

    // Test that locking slot 5 means only slot 5
    // reports to be locked
    tum.lock(5);
    assertTrue(tum.isLocked(5));
    assertFalse(tum.isLocked(10));

    // Assert that the unlocking function works
    tum.unlock(5);
    assertFalse(tum.isLocked(5));
    assertFalse(tum.isLocked(10));
}

void TextureBindingTest::lock()
{
    SystemInfo systemInfo {
            .maxTextureUnits = 20,
    };

    int testSlot = 12;

    // Create two textures
    Texture2D a(100, 100);
    Texture2D b(100, 100);

    // Set up the texture manager
    TextureUnitManager tum(&systemInfo);

    tum.bindTextureTo(testSlot, &a);

    tum.lock(testSlot);

    assertFalse(b.boundToUnit.has_value());
    assertEquals(testSlot, a.boundToUnit.value());
    assertEquals(static_cast<int>(a.getTextureId()),
                 static_cast<int>(tum.get(testSlot).value()->getTextureId()),
                 "Texture A must be bound to slot after locking"
                 );

    // Attempt to bind texture B to the now locked slot
    tum.bindTextureTo(testSlot, &b);

    assertFalse(b.boundToUnit.has_value());
    assertEquals(testSlot, a.boundToUnit.value());
    assertEquals(static_cast<int>(a.getTextureId()),
                 static_cast<int>(tum.get(testSlot).value()->getTextureId()),
                 "Texture A must be bound to unit after attempting to bind Texture B"
    );

    // Unlock the slot and ensure that Texture B can now be bound to the texture unit
    tum.unlock(testSlot);
    tum.bindTextureTo(testSlot, &b);

    assertFalse(a.boundToUnit.has_value());
    assertEquals(testSlot, b.boundToUnit.value());
    assertEquals(static_cast<int>(b.getTextureId()),
                 static_cast<int>(tum.get(testSlot).value()->getTextureId()),
                 "Texture B must be bound after unlocking"
    );
}
