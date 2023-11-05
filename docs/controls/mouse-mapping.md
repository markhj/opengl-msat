# Mouse mapping

## Method overview

````c++
void onButtonPress(MouseButton button, unsigned int signal);
void onButtonRelease(MouseButton button, unsigned int signal);
void onButtonDown(MouseButton button, unsigned int signal);
void onMove(std::function<void(CursorMoved cursorMoved)> func);
````

## Button actions

To emit a signal with a mouse button:

````c++
mouseMapping.onButtonPress(MouseButton::Primary, 300);
````

In this example signal 300 is emitted by the click of the system's
primary mouse button (typically left).

See list of mouse options: [Mouse enumerations](../lists/mouse-enums.md)

## Cursor movement
To handle cursor movement use the ``onMove`` method:

````c++
mouseMapping.onMove([&](CursorMoved cursorMoved) {
    // ...
});
````

The parameter passed into the lamdba function is the _[CursorMoved](cursor-moved.md)_ struct, which
contains the absolute coordinate of the cursor, as well as the change in cursor position.

