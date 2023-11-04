# Keyboard

The ``Keyboard`` and related classes provide an easy way to bind keyboard events to actions in your program.

## Setting up
### Include
Start by including the ``keyboard.hpp`` and ``keyboard_mapping.hpp`` files:

````c++
#include <opengl_msat/controls/keyboard.hpp>
#include <opengl_msat/controls/keyboard_mapping.hpp>
````

Note that ``keyboard_types.hpp`` is implicitly included. It contains the ``Key`` enum and other important components.

### Instantiating
Start by instantiating a ``KeyboardMapping`` instance, and then a ``Keyboard`` object
which contains the keyboard mapping in the constructor.
````c++
KeyboardMapping keyboardMapping();
Keyboard keyboard(&keyboardMapping);
````

You can swap the keyboard mapping as you please.

You can modify the keyboard binding (deciding what each key does) at any stage.
It's not required to be done before instantiation of the ``Keyboard``.

Naturally, you may want to have completed it by the time you launch your render loop. But it's not a strict requirement either.

#### Example
You have a game with a main menu. In the main menu you need completely
different controls from the game.

You could solve this by creating two ``KeyboardMapping`` instances. One for the game, one for the menu.

When the menu is open you assign that particular keyboard mapping to the ``Keyboard``. Similarly, you assign the other keyboard mapping while the game is running.

### Assign to ``Window``
Optional step, but one you most likely want to take, is assigning the keyboard to
the ``Window`` instance.

````c++
Window window();
window.setKeyboard(&keyboard);
window.generate();
````

You can set the keyboard retroactively, it doesn't have to be set at the time of window generation.

The reason is that the ``Window`` has bound a private callback, which is always called when
keyboard events take place. The ``Window`` class then checks if there's an assigned keyboard.

## Mapping keys
We track two keyboard states: Press and release.

The mapping of the actual keys come from the ``Key`` enum.
[See full list of keys](key-enum.md)

````c++
keyboardMapping.onPress(Key::A, []() {
    std::cout << "A was pressed" << std::endl;
});

keyboardMapping.onRelease(Key::A, []() {
    std::cout << "A was released" << std::endl;
});
````

### Key held down
#### Implementation 1
You can implement this on your own by storing the state of the key in a variable accessible to you.

Here's a simple example, where the ``W`` key makes the character move forward.

````c++
bool characterMovingForward = false;

keyboardMapping.onPress(Key::W, [&characterMovingForward]() {
    characterMovingForward = true;
});

keyboardMapping.onRelease(Key::W, [&characterMovingForward]() {
    characterMovingForward = false;
});
````

This is just an example. Obviously, you may want to approach this differently in an actual
implementation of character controls.

#### Implementation 2
The ``Keyboard`` class keeps track of the key states. You can use ``isDown`` for this purpose.

````c++
if (keyboard.isDown(Key::W)) {
    // When W is down
}
````
