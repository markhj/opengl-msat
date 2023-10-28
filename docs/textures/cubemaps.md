# Cubemaps

To create a cubemap, simply use:

````c++
CubeMap cubemap({
    "./assets/textures/skybox/right.jpg",
    "./assets/textures/skybox/left.jpg",
    "./assets/textures/skybox/top.jpg",
    "./assets/textures/skybox/bottom.jpg",
    "./assets/textures/skybox/front.jpg",
    "./assets/textures/skybox/back.jpg"
});
````

## Texture units

You can bind it to a texture unit in the same way you would with 2D textures:

````c++
textureUnitManager.bindTextureTo(4, &cubemap);
````

In this example the cubemap will be bound on texture unit 5's cubemap slot.

And in the same way, you can check a texture's binding to a unit with:

````c++
if (cubemap.boundToUnit.has_value()) {
    // Action when cubemap is bound
} else {
    // ... Action if not
}
````

## Next steps

The next step is applying the cubemap in a shader.

That will not be covered in this article. We suggest exploring the [Skybox](skybox.md) 
implementation for inspiration.