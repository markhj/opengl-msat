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

It's important that ``end`` follows [Window](../window/window.md) class'es
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

## Total elapsed time
You can retrieve the total time elapsed since ``start`` was called the first time
with ``Timer::getElapsedTime``.

If this method is called before ``start``, it will just return 0.

## True render time
You can track true render time separately from the delta time by adding
``Timer::endRenderTime`` just before polling events and swapping buffers.

So, typically, something like:

````c++
while (window.keepOpen())
{
    timer.start();

    // Rendering

    timer.endRenderTime();

    window.swapBuffers();
    window.pollEvents();

    timer.end();
}
````

You retrieve the render time with ``Timer::getRenderTime``.

The advantage of doing this is that you get a more clear picture of the cost
of your rendering. The ``swapBuffers`` is for example affected by enabling vertical sync,
which may give a distorted image of how well your render logic actually performs.

You can get the value in frames per second (FPS) with:

````c++
float trueRenderTimeFPS = timer.getFramesPerSecond(true);
````

The [Renderer](../render/render.md) keeps track of the true render time,
as well as the regular delta time.