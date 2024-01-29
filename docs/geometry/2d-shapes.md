# 2D shapes

## Regular polygon

The ``RegularPolygon2D`` is used to form hexagons, octagons and similar shapes. It can also be used to
approximate a circle.

It's constructor method signature is:

````c++
RegularPolygon2D(unsigned int sides, double radius)
````

### Example
````c++
RegularPolygon2D hexagon(6, 3.0);
````