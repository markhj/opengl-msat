# Grid

Sometimes it's easier to understand the geometry of a scene by adding
a 2-dimensional grid. This is especially true when you're rendering a single
or few objects.

## Setting up
Initialize the ``Grid`` as:

````c++
Grid grid(&window, &camera);
````

Somewhere in your render loop, add:

````c++
grid.render(renderer);
````

## Properties

You can modify the look of the grid by adjusting these properties:

| Property         | Data type       | Default  | Description                                                 |
|------------------|-----------------|----------|-------------------------------------------------------------|
| ``lines``        | ``float``       | ``10``   | Total number of lines to be drawn in each direction         |
| ``lineWidth``    | ``float``       | ``4.0``  | Width/thickness of the individual lines                     |
| ``spacing``      | ``float``       | ``0.5``  | The space between each line                                 |
| ``center``       | ``bool`` | ``true`` | Display the red/green/blue center axis indicator            |
| ``centerMargin`` | ``float``       | ``0.1``  | The space between the center axis lines and the white lines |

To apply a change, do something like this:

````c++
grid.lines = 20;
````

The change will take effect from next render call.