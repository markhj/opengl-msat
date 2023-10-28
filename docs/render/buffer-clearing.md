# Clearing the buffer

The ``Renderer::loop`` method automatically clears the color, depth and stencil buffer for each
iteration.

If you aren't using the ``loop`` method and want manual control, you can
clear it using ``Renderer::clear``, like:

````c++
while (renderLoopIsRunning) {
    // ...
    
    renderer.clear();
    
    // ...
}
````
