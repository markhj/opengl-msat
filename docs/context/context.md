# Context

In OpenGL, we frequently bind and unbind objects. To structure this more clearly,
and ensure unbinding isn't forgotten, we've added the ``Context`` class.

It works on classes which inherit the ``Bindable`` class (acting as an interface/contract).

It works like this:

## Include
````c++
#include "opengl_msat/context/context.hpp"
````

## Usage
````c++
VAO vao;

Context::with(vao, [&vao]() {
    // Carry out actions for VAO
});
````

What happens behind the scenes:

- VAO's ``bind`` method is called
- The lambda function is executed
- VAO's ``unbind`` is called

## Classes supporting ``Bindable``

For the full list of classes inheriting ``Bindable`` (i.e. list of classes
which can be used with ``Context::with``), see:
[List of Bindable classes](/lists/bindable-classes)