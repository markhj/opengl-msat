# Bindable

As mentioned in the [Context](/context/context) chapter, some classes
are bindable, which means there are features to aid in keeping control of what is and isn't currently bound.

In this chapter, we're going to introduce some additional features.

## ``IsBound``

You can check if a specific object is currently bound. For example a shader.

````c++
if (shader.isBound()) {
    // Do something
} else {
    // Do something else
}
````

## Safe binding

Picture the two following scenarios:

- You're bound to shader A and change a uniform in shader B. Because of how the implementation works, the method will bind to B, set the uniform, and then unbind. This means you're no longer bound to A. But from your code this is not an intuitive effect.
- You're bound to shader A and set a uniform in shader A. For the same reason, you would have unbound from shader A, after setting the uniform.

To account for these scenarios, there's the option of doing **safe binding**.

When ``safeBind`` is invoked, it will remember which (if any) instance of the
same class is currently bound. ``safeUnbind`` will bind to the other target.

An example originates from the ``Shader`` class'es ``uniform`` methods:

````c++
void ShaderProgram::uniform(const char *name, int value)
{
    safeBind();
    glUniform1i(getLocation(name), value);
    safeUnbind();
}
````
