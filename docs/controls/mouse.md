# Mouse

To incorporate with the mouse, you create an instance of ``Mouse``
and bind it to the [Window instance](../window/window.md).

## Setting up
Initialize with:
````c++
Mouse mouse;
````

And connect it with the window using:
````c++
window.setMouse(&mouse);
````

## Tracking movements

To track when the mouse moves, you'll set up a lambda function with ``Mouse::onMove``:

The lambda function must take two parameters:

- ``std::array<float, 2>`` which gives the absolute position of the cursor (in the window)
- ``std::array<float, 2>`` which gives the difference the mouse has moved since the callback function was last run

````c++
mouse.onMove([](std::array<float, 2> position, std::array<float, 2> diff) {
    // Put actions here
});
````