# Understanding how controls work

The pipeline for handling control inputs in OpenGL MSAT is:

- Define a mapping (for instance map a key press or mouse button down)
- Assign a mapping to the control (e.g. keyboard)
- Define an _[InputController](input-controller.md)_ which receives "signals" and carries out the desired actions

As you can see, it's not as simple as "When W is pressed do this". This is a design decision to ensure
separation between the physical control unit (for instance the keyboard, the mouse or the joystick) and
the handler of the actual action (for example moving the camera forward or sideways).

## Mapping and signals

Every type of control has a mapping, where you bind events to so-called "signals".

An "event" could be a click on the mouse or a press on a key. This event emits a "signal"
to the ``InputController`` whose purpose then is to carry out the actual action.

## Signals
Signals are of the type ``unsigned int``.

There are some pre-defined signals in the list [Signals](../lists/signals.md),
but this enables you to structure your own signals into something more readable.

For instance:

````c++
const unsigned int MY_CUSTOM_SIGNAL = 50000
````

It's recommended that you set your signals above 10,000 to avoid
collision with the pre-made signals.

