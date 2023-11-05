# Keyboard mapping

## Relevant methods
````c++
void onKeyPress(Key key, unsigned int signal);
void onKeyRelease(Key key, unsigned int signal);
void onKeyDown(Key key, unsigned int signal);
````

## Example
When using one of the premade [signals](../lists/signals.md):
````c++
keyboardMapping.onKeyPress(Key::W, ControlSignals::MoveForward);
````

Or just a custom signal as an ``unsigned int``:
````c++
keyboardMapping.onKeyPress(Key::J, 900);
````

## See also
[See full list of keys](key-enum.md)