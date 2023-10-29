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

| Property | Default | Description |
| --- | --- | --- |
| ``lines`` | ``10`` | Total number of lines to be drawn in each direction |
| ``spacing`` | ``0.5`` | The space between each line |

To apply a change, do something like this:

````c++
grid.lines = 20;
````

The change will take effect from next render call.