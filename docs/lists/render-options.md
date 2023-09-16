# Render options

Enumerations contained in the ``RenderOption`` enum in ``shared/render_types.hpp``.

These properties are used by the [renderer state](/render/render-state).

## Enumerations

| Enumeration                      | Description     | OpenGL/GLAD property |
|----------------------------------|-----------------|----------------------|
| ``RenderOption::DepthTesting``   | Depth testing   | ``GL_DEPTH_TEST``    |
| ``RenderOption::StencilTesting`` | Stencil testing | ``GL_STENCIL_TEST``  |
| ``RenderOption::Blend``          | Blend           | ``GL_BLEND``         |
| ``RenderOption::FaceCulling``    | Face culling    | ``GL_CULL_FACE``     |