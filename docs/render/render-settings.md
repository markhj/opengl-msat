# Render settings

General rendering settings such as point and line sizes are managed
in the ``RenderSettings`` struct, found in the ``include/shared/render_types.hpp`` file.

## Structure

You create the ``RenderSettings`` struct before creating the ``Renderer``.
The renderer takes the render settings as one of its parameters. It takes it by reference,
so the render settings can be changed at any point, and shared with other
objects.

````c++
// Initialize Window and Timer

RenderSettings settings;
Renderer renderer(window, timer, settings);
````

## Applying settings
However, just changing the properties of the struct isn't enough to apply the settings.
You must call the ``Renderer::applySettings`` method, when you're ready to apply them.

````c++
settings.pointSize = 10.0;
renderer.applySettings();
````

## Available options

| Struct property | Description                           | OpenGL function invoked |
|-----------------|---------------------------------------|-------------------------|
| ``pointSize``   | The pixel size of points | ``glPointSize``         |
| ``lineSize``    | The pixel width of lines | ``glLineWidth``         |