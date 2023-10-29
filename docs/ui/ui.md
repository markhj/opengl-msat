# UI

The ``UI`` class is the first step to managing user interface
with OpenGL MSAT.

## Setting up

Initialize with:
````c++
UI ui(&window, &camera);
````

Somewhere in your render loop:

````c++
ui.render(renderer);
````

## Usage

For the ``UI`` to render anything it must be provided vertices.
This is achieved with ``setVertices``.

````c++
ui.setVertices({...})
````

This is most commonly used in conjunction with the [UI Element Manager](ui-elements.md)
and the pre-fabricated UI elements.