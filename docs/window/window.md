# Window

The first step to coding OpenGL is creating a (GLFW) window.
With OpenGL MSAT, this is relatively easy.

## Instantiating
Instantiate the ``Window`` with width, height and window title.

````c++
Window window(800, 600, "My OpenGL App");
````

## Generate the window
Once you're ready to open the window you call the ``Window::generate`` method.
In some cases you may want to adjust some settings before this, but it's not required if you're just
want to get started as quickly as possible.

````c++
window.generate();
````

Once this method is called, the window will appear.

## Lifetime
However, if you do nothing else in your code, the window will disappear as quickly as it showed up.

We normally need to run a render loop which keeps the window open. The basic structure to do this is:

````c++
while (window.keepOpen()) {
    // Render the scene
}
````

### Closing the window
At some point, you'll want to close the (GLFW) window. In simple applications, it could be by pressing the _ESC_ button.

````c++
while (window.keepOpen()) {
    // Render the scene
    
    if (escIsPressed) {
        window.close();
    }
}
````

Note: We will address how to actually map the ESC button in the [Keyboard chapter](../controls/keyboard.md).
This code only demonstrates the idea of calling the ``Window::close`` method.

## Swap buffers and poll events
In OpenGL, we generally do two things at the end of a render loop iteration:

- Swap buffers
- Poll events

**Swapping buffers** means you replace the currently displayed frame with the newly rendered.
There's a bit more going on here, for example when you work with vertical sync., but this is the gist of it.

**Polling events:**: If you run the code in the current shape, you will see that the window is probably unresponsive.
To give the window some "breathing room" to take user inputs and carry out a number of other actions, you "poll events".

This all in all combines to:

````c++
while (window.keepOpen()) {
    // Render the scene
    
    if (escIsPressed) {
        window.close();
    }
    
    window.swapBuffers();
    window.pollEvents();
}
````

### Combined method
We have included a short-hand method which swaps the buffers and polls events in a single function. 

````c++
window.swapAndPoll();
````

## Regenerate the window
Sometimes you need to destroy the GLFW window instance and recreate it.

This process is handled by the ``Window`` class, simply by calling ``Window::regenerate``.

The settings which require regeneration are those normally set with ``glfwWindowHint``.
If you're not familiar with this function, then no need to worry.

Among the settings in our library it concerns:

- Toggling between window and full screen mode
- Changing MSAA sampling after instantiation

The function used to regenerate the GLFW window instance is:

````c++
window.regenerate();
````

### Why not regenerate automatically when a setting that requires it has been changed?

A very valid question! The idea of leveraging this control to the programmer, is for scenarios
in which multiple settings that require window regeneration are changed at the same time.

Otherwise you could end up with:

1. Change MSAA sampling
2. _Wait for window to regenerate_
3. Change to full screen mode
4. _Wait for window to regenerate_

Instead, with the current implementation it works like:

1. Change MSAA sampling
2. Change to full screen mode
3. _Wait for window to regenerate_

## Change size

You can change the window size with ``Window::setSize``.

````c++
window.setSize(1024, 768);
````

Note: Resizing the window does **not** require regenerating the window.

Resizing has no effect in full screen mode. But the new size will be saved, for when/if
you return to windowed mode, and _then_ it will apply.

## Full screen
To switch to (or out of) full screen mode, simply use ``Window::setFullScreenMode``.

**Important**: You need to regenerate the window when going in and out of full screen.
This is required because we utilize ``glfwWindowHint`` to turn window decoration on and off.
Window decoration is a term for the title bar, borders and buttons to minimize, maximize and close.

````c++
window.setFullScreenMode(true);
window.regenerate();
````

And to exit full screen mode:

````c++
window.setFullScreenMode(false);
window.regenerate();
````

When you exit full screen mode it returns to the original size from
just before full screen mode was entered.

## MSAA sampling
**MSAA sampling** is also known as **anti-alias**.

You can modify this setting with:

````c++
window.setMsaaSampling(8);
window.regenerate();
````

This setting requires regeneration.

The default value is 4.

## Width, height and aspect ratio

You can retrieve width, height and aspect radio with these methods:

````c++
int width = window.getWidth();
int height = window.getHeight();
float aspectRatio = window.getAspectRatio();
````

When the window is in full screen mode the returned width and height values are equal to the display resolution, even if the underlying window width and height settings are different.
If you generate a 800x600 window on a 1920x1080 monitor, then the following applies:

- Window mode: ``getWidth`` and ``getHeight`` return 800 and 600.
- Full screen mode: ``getWidth`` and ``getHeight`` return 1920 and 1080.

## Handle inputs
Some controllers have a "down" mode, for instance a keyboard's keys
can be held down.

GLFW doesn't have built-in functions to manage this state. It detects press and release.

To seamlessly implement the possibility of using "down" state with our [keyboard](../controls/keyboard-mapping.md)
and [mouse mapping](../controls/mouse-mapping.md), the window must be instructed to "handle inputs".

````c++
while (window.keepOpen()) {
    window.handleInputs();
    
    // Render code
    
    window.swapBuffers();
    window.pollEvents();
}
````

This is automatically taken care of when you use the [Renderer](../render/render.md)'s ``loop`` function.
Meaning, it's _not_ required here:

````c++
renderer.loop([](Renderer* renderer) {
    // No need to call the "handleInputs", this is done automatically
    
    // ...
    
    // Render code
});
````

## Center cursor
When a mouse is provided to the window and you're in full screen mode, you can call ``centerCursor``.

````c++
window.centerCursor();
````
