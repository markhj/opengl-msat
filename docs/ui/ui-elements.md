# UI elements

The ``UIElementManager`` makes it easier and more convenient to
organize several UI elements.

## Prerequisites
* [UI](ui.md)

## Setting up

````c++
UI ui(&window, &camera);
UIElementManager uiem;
````

From this point on you attach the various elements.
An element is required to inherit ``UIElement``.

## Attaching elements
To attach an element call ``attach``. For example:

````c++
ProgressBar healthBar;
ProgressBar speedBar;

uiem.attach(&healthBar);
uiem.attach(&speedBar);
````

## Rendering
Somewhere in your render loop, you provide the ``UI``
with the vertices calculated by the objects contained in
``UIElementManager``:

````c++
ui.setVertices(uiem.getVertices());
ui.render(renderer);
````
