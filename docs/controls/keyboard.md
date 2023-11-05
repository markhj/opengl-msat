# Keyboard

The ``Keyboard`` and related classes provide an easy way to bind keyboard events to actions in your program.

## Prerequisites
* Understanding of the [control design](controls.md)
* [InputController](input-controller.md)

## Setting up
Create a ``Keyboard`` instance and connect it to the window.

````c++
Keyboard keyboard;

window.setKeyboard(&keyboard);
````

## Mapping
Next, create a ``KeyboardMapping`` instance and bind it to the keyboard.
````c++
KeyboardMapping keyboardMapping;
Keyboard keyboard(&keyboardMapping);
````

Read more about: [Keyboard mapping](keyboard-mapping.md)

You can swap the keyboard mapping as you please.

You can modify the keyboard binding (deciding what each key does) at any stage.
It's not required to be done before instantiation of the ``Keyboard``.

Naturally, you may want to have completed it by the time you launch your render loop. But it's not a strict requirement either.

### Example
You have a game with a main menu. In the main menu you need completely
different controls from the game.

You could solve this by creating two ``KeyboardMapping`` instances. One for the game, one for the menu.

When the menu is open you assign that particular keyboard mapping to the ``Keyboard``. Similarly, you assign the other keyboard mapping while the game is running.

## Key down
If you're not using the [Renderer](../render/render.md), you have to call
the ``Window::handleInputs`` method to make the "down" state for controls work.

See more: [Window](../window/window.md)