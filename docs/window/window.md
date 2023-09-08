# Window

The first step to coding OpenGL is creating a (GLFW) window.
With OpenGL MSAT, this is relatively easy.

## Include
Start by including the ``Window`` class:

````c++
#include "opengl_msat/window/window.hpp"
````

## Instantiating
Next, instantiate the ``Window`` with width, height and window title.

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

Note: We will address how to actually map the ESC button in the [Keyboard chapter](/controls/keyboard).
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

- Toggling between window and full-screen mode
- Changing MSAA sampling after instantiation

The function used to regenerate the GLFW window instance is:

````c++
window.regenerate();
````

## Change size

You can change the window size with ``Window::setSize``.

````c++
window.setSize(1024, 768);
````

Note: Resizing the window does **not** require regenerating the window.

## Fullscreen

## MSAA sampling