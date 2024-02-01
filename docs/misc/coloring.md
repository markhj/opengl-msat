# 🎨 Coloring

``Coloring`` is a specialized class which can provide multiple colors, often used
in conjunction with ``ObjectWrapper::colorize``.

## Example
````c++
Coloring coloring({
    Color(1.0, 0.0, 0.0),
    Color(0.0, 1.0, 0.0),
    Color(0.0, 0.0, 1.0)
});

Object2D rectangle = Rectangle2D(Vec2(0.0), Vec2(b.x, b.y));
rectangle.colorize(coloring);
````

## Properties
| Property   | Data type | Default | Description                                                                                                                                                           |
|------------| --- | --- |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| ``repeat`` | ``bool`` | ``true`` | When ``get`` receives an index out of bounds, will start over in the list of colors when ``repeat`` is ``true``, otherwise it will return the last color in the list. |
