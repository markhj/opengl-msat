#include "animation_tests.hpp"

void AnimationTest::validateInterval()
{
    Vec3 a(0.0);
    AnimationBlueprint<Vec3> blueprint;
    blueprint.step(20.0, 30.0, Vec3(5.0));

    assertFalse(blueprint.isIntervalOccupied(0.0, 19.0));
    assertTrue(blueprint.isIntervalOccupied(0.0, 20.0));
    assertTrue(blueprint.isIntervalOccupied(0.0, 25.0));
    assertTrue(blueprint.isIntervalOccupied(0.0, 35.0));
    assertTrue(blueprint.isIntervalOccupied(25.0, 35.0));
    assertTrue(blueprint.isIntervalOccupied(30.0, 35.0));
    assertFalse(blueprint.isIntervalOccupied(31.0, 40.0));
}

