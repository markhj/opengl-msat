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

## Locking
Sometimes you'll want to bind a texture to a unit and keep it that way for your
entire application. This could be useful with fonts, for instance.

To ensure you don't accidentally overwrite a texture unit you can lock it.

When attempting to set a texture to a locked unit, the process will simply be ignored.

### Relevant methods
````c++
void lock(unsigned int slot);
void unlock(unsigned int slot);
bool isLocked(unsigned int slot);
````

#### Example
In this example texture unit 6 will be locked, until you may free it back up
with ``unlock``.
````c++
tum.lock(5);
````
It means that if you try to bind a texture to unit 5 after this point,
nothing will happen.

### Warning
During your development process you may be interested to know when you try to 
bind a texture to a locked unit.

This happens by default. If you want to turn this off, set ``warnWhenBindingToLockedUnit``
to ``false``.