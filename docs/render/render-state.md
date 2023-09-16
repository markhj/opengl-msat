# Render state

The **render(er) state** class is used to manage render options such
as depth testing, stencil testing, blending and more.

The render state automatically restores to defaults when a new [render loop](/render/render) iteration begins.
This is predicated on using ``Renderer::loop``.

````c++
renderer.loop([&](Renderer* renderer) {
    // Depth testing is automatically back at true (default)
    
    renderer->state()->disable(RenderOption::DepthTesting);
    
    // From now on, depth testing is disabled
});
````

## Enable or disable
You can enable of disable properties with:

````c++
renderer->state()->enable(RenderOption::XXX);

renderer->state()->disable(RenderOption::XXX);
````

Replace ``RenderOption::XXX`` with a property from [the list of render options](/lists/render-option).

You can also use the direct ``set`` function:
````c++
renderer->state()->set(RenderOption::XXX, true); // Enable

renderer->state()->set(RenderOption::XXX, false); // Disable
````

## Is enabled
If needed, you can check if a render option is enabled with ``isEnabled``.

````c++
renderer->state()->isEnabled(RenderOption::StencilTesting);
````

The method returns ``true``, if a property is enabled.

## Change default
Whenever the ``reset`` function is manually called, or the render loop
start over, the properties are returned to their default state.

You can modify what a default is with ``setDefault``.

````c++
renderer->state()->setDefault(RenderOption::Blend, true);
````

In the example above, blending will be enabled upon reset.

## Disable resetting
If you don't want to make use of the automatic resetting, you can disable
it:

````c++
renderer.setResetState(false);
````

## Default values
All render options not listed below are by default false.
These are by default true:

- ``RenderOption::DepthTesting``

## Manual reset
If you aren't using the ``Renderer::loop``, you can use the ``reset`` method.

````c++
while (window.keepOpen()) {
    renderer.state()->reset();
    
    // Render
}
````

## Temporary swap
For temporary swapping render state see [Renderer](/render/render).