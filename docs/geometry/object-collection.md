# Object collection

An ``ObjectCollection``, as the name implies, collects a number of [ObjectXD elements](object-xd.md), and
provides a series of functions to organize and manage them.

The ``ObjectCollection`` serves as a basis (parent class) for a number of OpenGL MSAT features, such as
the [Scene manager](../render/scene-management.md).

You can build custom object collections which extend this class.

## Methods
### ``getVertices`` and ``getVerticesFlattened``
````c++
std::vector<VertexElementXD> getVertices();
````
Gets the vertices of all objects in one long list.
````c++
std::vector<GLfloat> getVerticesFlattened(std::vector<VertexAttribute> attributes);
````
Gets the all vertices of all objects, flattened to a list of floats, and with the
respect to the specified attributes.

This enables you to collect for instance just position and color.

### Adding
````c++
void add(ObjectXD* obj);
````
Adds a single object to the collection.

````c++
void add(std::vector<ObjectXD*> objs);
````
Adds a vector of objects to the collection.

### Getters
````c++
std::optional<unsigned int> getVertexIndex(ObjectXD* obj);
````
Gets the position of an object in the collection.
Returns ``std::nullopt`` if object isn't part of it.

````c++
std::vector<ObjectXD*> getObjects();
````
Returns the full list of objects.