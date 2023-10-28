# Texture unit manager

The ``TextureUnitManager`` is used to orchestrate and organize the binding of textures to texture units.

## Instantiate

Initialize the texture unit manager like:

````c++
SystemInfo systemInfo = System::getSystemInfo(&window);

// ...

TextureUnitManager tum(&systemInfo);
````

## Max. texture units

You (unforuntately) can't assume that two machines have the same number
of texture units. So you will usually have to incorporate some type of management
and for this you need to know the system-specific maximum.

Retrieve this with:

````c++
unsigned int maxTextureUnits = tum.getAvailableSlots();
````

## Binding

To bind a texture to a unit, simply use the ``bindTextureTo``.

````c++
Texture2D myTexture("...");

tum.bindTextureTo(10, &myTexture);
````

In this example ``myTexture`` is bound to texture unit 11.

### Alternative method

You can achieve the same with:

````c++
tum.bindTo(10);
myTexture.bind();
````

But the first method is a bit more readable.

## Unbinding

You can unbind from the current texture unit with ``unbind``.

Keep in mind that "unbinding" is the same as binding to the 0th unit.

## Attaching a shader

If you want a shader to automatically have its ``textures`` uniform array populated,
you can attach it to the Texture Unit Manager.

````c++
tum.attachShader(&shader);
````

## Getting currently bound

You can figure out which texture is currently bound on a unit  with:

````c++
tum.getTextureBinding(&myTextture);
````

This returns ``std::optional<unsigned int>``.

If the texture isn't bound, the optional won't have a value (i.e. ``has_value`` will be false).

If it does, it will return the index of the unit it is bound to.

> **Warning:** This feature may not work, if you modify the texture
> bindings with plain OpenGL functions (i.e. by not using OpenGL MSAT functions).

### On the texture

An alternative to figure out which texture unit a texture is bound to is using 
the ``boundToUnit`` property.

Like before it will be a ``std::optional<unsigned int>``.

Example:
````c++
if (myTexture.boundToUnit.has_value()) {
    std::cout << "Texture is bound to unit <<  myTexture.boundToUnit.value() << std::endl;
} else {
    std::cout << "Texture is not bound to a unit" << std::endl;
}
````
