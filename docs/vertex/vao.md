# VAO (Vertex Array Object)

The ``VAO`` is [Bindable class](../context/context.md) representing a Vertex Array Object.

## Initialization
After including ``vao.hpp`` you can instantiate a VAO with:

````c++
VAO vao;
````

## Binding
You can bind and unbind VAOs in two, depending on your preference.

````c++
vao.bind();

// Actions for VAO

// vao.unbind();
````

Or with our [Context](../context/context.md) class:

````c++
Context(vao, [&]() {
    // Actions for VAO
});
````

## Associating with VBO
See [VBO chapter](vbo.md)