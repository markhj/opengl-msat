# VBO (Vertex Buffer Object)

A **Vertex Buffer Object** (VBO) contains the actual vertex data.

## Include
````c++
#include "opengl_msat/vertex/vbo.hpp"
````

## Setup
You instantiate a VBO like this:

````c++
VBO vbo;
````

## Setting vertices
You can set the (entire) content of the VBO with the ``VBO::setVertices`` method:

````c++
vbo.setVertices({
    0.0, 1.0, 0.0,
    -1.0, 0.0, 0.0,
    1.0, 0.0, 0.0
});
````

## Upload data
Whenever you want to upload the (entire) VBO to the buffer, you use the
``VBO::upload`` method:

````c++
vbo.setVertices({
    // Vertex data
});
vbo.upload();
````

Note: When you use the ``VAO::associate`` method, which we'll look at in a moment,
it's not required to upload, as that method will also do it.

## Associate with VAO

You can associate the VBO with a VAO with relative ease:

````c++
VAO vao;
VBO vbo;

vbo.setVertices({
    // Vertex data 
});

vao.associate(vbo, { VertexAttribute::Position3D });
````

The second parameter of the ``associate`` method takes a vector of
[Vertex attributes](/vertex/vertex-attribute). Click on the link to learn
which are available.

The ``associate`` will create an association between the VAO and VBO.
It also defines the vertex attribute structure and enable the pointers.
So quite a bit of work is saved using this method.