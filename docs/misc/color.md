# Color

The ``ColorRGB`` and ``ColorRGBA`` are used in various parts of the library, such
as the [UI elements](../ui/ui.md).

The color classes expand on [Vec3](../getting-started/vectors-matrices.md) and ``Vec4`` respectively.

## Initialization
### RGB color
````c++
ColorRGB red(1.0, 0.0, 0.0);
ColorRGB white(1.0);
````

### RGBA color
````c++
ColorRGBA halfTransparentRed(1.0, 0.0, 0.0, 0.5);
````
