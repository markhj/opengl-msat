# Input controller

The ``InputController`` is responsible for receiving signals, and converting those signals into tangible
actions.

## Instantiation
````c++
InputController inputController;
````

Next, attach it to the window:

````c++
window.setInputController(&inputController);
````

## Methods
### ``onSignal``
````c++
void onSignal(unsigned int signal, std::function<void()> func)
````
Handle a specific signal.

Example:
````c++
inputController.onSignal(ControlSignals::ExitProgram, [&]() {
    window.close();
});
````

## ``attach``
````c++
void attach(InputControllerRole* role);
````

See more under [input controller roles](input-controller-roles.md).