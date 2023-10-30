# Textures

The ``Texture`` class can be used independently or in the derived versions, such as
[Texture2D](texture-2d.md) or [Cubemap](cubemaps.md).

## Constructors
````c++
Texture(TextureType type, unsigned int width, unsigned int height);

Texture(TextureType type, unsigned int width, unsigned int height, TextureOptions options);

Texture(TextureType type, std::string filename);

Texture(TextureType type, std::string filename, TextureOptions options);

Texture(TextureType type, std::vector<std::string> files, TextureOptions options);
````

When you create a ``Texture`` without a ``filename`` a blank texture with the
specified dimensions is initialized.

The versions with a ``filename`` will attempt to load an image file relative
to the executeable's path.

## Texture load status
You can retrieve the load status of a texture with ``isLoaded``.

````c++
Texture myTexture(TextureType::Texture2D, "./assets/textures/my-texture.jpg");
````

See the possible values at: [Texture enumerations](../lists/texture-enums.md).

## Texture ID
````c++
unsigned int getTextureId();
````

Retrieve the texture's assigned ID (by OpenGL).

## Binding
``Texture`` is a [bindable class](../context/bindable.md), which means you can use
``bind`` and ``unbind`` on it.

### ``boundToUnit``
When you're using [TextureUnitManager](tum.md), the property ``boundToUnit`` can tell you
whether a texture is currently bound to any unit, and if so, which one.

``boundToUnit`` is a ``std::optional<unsigned int>``. If it doesn't have a value, then it's
not bound to a unit.

````c++
if (texture.boundToUnit.has_value()) {
    // Texture is bound to a texture unit retrievable with texture.boundToUnit.value()
} else {
    // Texture isn't bound to a unit
}
````

## Options
You can specify a texture's options, either as part of its constructor or
on-the-fly.

Read more under: [Texture options](texture-options.md).
