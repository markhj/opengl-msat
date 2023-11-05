# Mouse

To incorporate with the mouse, you create an instance of ``Mouse``
and bind it to the [Window instance](../window/window.md).

## Prerequisites
* Understanding of the [control design](controls.md)
* [InputController](input-controller.md)

## Setting up
Initialize with:
````c++
Mouse mouse;
````

And connect it with the window using:
````c++
window.setMouse(&mouse);
````

### Mapping
Just like with the [keyboard](keyboard.md), the mouse must also have a mapping.

````c++
MouseMapping mouseMapping;
mouse.mouseMapping = &mouseMapping;
````

You can toggle the mapping during runtime, if needed. This could be useful, for instance
if you have a game with a menu. In the game itself the mouse has one set of actions, while in the menu
it would be a completely different set. This is easily managed by creating two mappings, and control
which one is active.

See how to define the mapping: [Mouse mapping](mouse-mapping.md).

## Mouse button down
If you're not using the [Renderer](../render/render.md), you have to call
the ``Window::handleInputs`` method to make the "down" state for controls work.

See more: [Window](../window/window.md)