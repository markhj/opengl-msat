# Projections

The ``Projection`` class is important in many rendering use cases.
It uses the window, camera and instructions to calculate the projection-view-model which
is needed in many shader calculations.

## Setting up
You initialize a projection with:

````c++
Projection projection(&window, &camera);
````

## Types
Next, you will typically need to specify it to be in either
perspective or orthographic mode.

Setting it to perspective:
````c++
projection.perspective();
````

Setting it to orthographic:
````c++
projection.orthographic();
````

## Shader
The projection is accepted directly into the ``ShaderProgram::uniform``
method.

````c++
shader.uniform(projection);
````

In this instance, it will apply the calculated projection-view-model
into the shader as ``projection``.

## Getting calculations
You can also retrieve various calculations directly in code:

* ``calculate`` returns the final combined calculation of projection, view and model
* ``getProjection`` returns only the projection part
* ``getView`` returns the view calculation ("look at")
* ``getModel`` returns the model