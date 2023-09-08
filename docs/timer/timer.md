# Timer

The ``Timer`` class a simple utility to assist with calculating delta time and frames per second (FPS).

## Include

Start off by including the ``timer.hpp`` file:

````c++
#include <opengl_msat/timer/timer.hpp>
````

## Instantiation

Instantiate ``Timer``:

````c++
Timer timer();
````

## Setup

For proper usage, you put ``Timer::start`` at the very beginning of your render loop,
and ``Timer::end`` at the very end.

It's important that ``end`` follows [Window](/window/window) class'es
``swapBuffers`` and ``pollEvents`` functions, otherwise it can produce wildly
incorrect results, especially when vertical sync. is enabled.

Your code should look something like this:

````c++
while (window.keepOpen()) {
    timer.start();
    
    // Render the scene
    
    window.swapBuffers();
    window.pollEvents();
    
    timer.end();
}
````

## Delta time

You retrieve the current delta time with ``Timer::getDeltaTime``.

````c++
float moveCharacterX = speed * timer.getDeltaTime();
````

## Frames per second (FPS)

You can retrieve the frames per second (FPS) with:

````c++
int FPS = timer.getFramesPerSecond();
````

Frames per second is calculated based on the most
recent delta time value.

This means it can vary greatly within a single second, because
the render speed isn't consistent.

The resulting value is rounded down (floor) to nearest integer.