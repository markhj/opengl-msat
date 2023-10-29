# Progress bar

The ``ProgressBar`` class creates a simple progress bar from 0-100% in the UI.

## Prerequisites
* [UI](ui.md)
* [UI elements](ui-elements.md)

## Usage

Initialize with:

````c++
ProgressBar progressBar;
````

Attach it to the UI element manager:

````c++
UIElementManager uiem;

uiem.attach(&progressBar);
````

> Please read the chapter on [UI elements](ui-elements.md) if this looks unfamiliar to you.

## Properties

Use these properties to define the position, size, look and progress value of the bar:

| Property | Data type | Default      | Description                    |
| --- |-----------|--------------|--------------------------------|
| ``position`` | ``Vec2``  | ``0.0, 0.0`` | Position of bottom-left corner |
| ``progress`` | ``float``  | ``0.0``      | Progress (0 to 100)            |
| ``width`` | ``float``  | ``200.0``    | Width in pixels                |
| ``height`` | ``float``  | ``30.0``     | Height in pixels               |
| ``background`` | ``ColorRGBA``  | ``(1.0, 1.0, 1.0, 0.5)``      | Background color               |
| ``foreground`` | ``ColorRGBA``  | ``(1.0)``      | Background of the bar itself   |

