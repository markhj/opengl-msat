# Input controller roles

You can attach multiple "roles" to the _[InputController](input-controller.md)_.
A role can control various aspects of the scene based on [signals](controls.md).
This is commonly used to manage the camera behavior.

## Creating the role
To create a new role, create a class which extends ``InputControllerRole``.

````c++
class MyCustomInputRole : public InputControllerRole {
public:
    void handle(SignalList signals) override;

};
````

You are required to define the ``handle`` method.

An example of that implementation could be:

````c++
void handle(SignalList signals)
{
    if (signals.has(ControlSignals::MoveForward)) {
        // Move forward
    } else if (signals.has(ControlSignals::MoveBackward)) {
        // Move backward
    }
}
````

### Cursor movement
Optionally, you can override this method to handle movements
of the cursor.

````c++
void onMouseMove(CursorMoved cursorMoved);
````

Example:

````c++
void onMouseMove(CursorMoved cursorMoved)
{
    if (cursorMoved.diffX < 0) {
        // Cursor moved left
    } else if (cursorMoved.diffY > 0) {
        // Cursor moved right
    }
}
````

This allows you to work with the cursor in the input controller role. 

## Attach to ``InputController``
To attach the custom role to the ``InputController``, simply call the ``attach`` method.

````c++
InputController inputController;
MyCustomInputRole customRole;

inputController.attach(&customRole);
````
