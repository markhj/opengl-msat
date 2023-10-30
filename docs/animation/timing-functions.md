# Animation timing functions

Normally, an animation will run with a linear timing function where the distance
between each percent is the exact same. You can modify this behavior, if needed.

## Normal timing functions
````c++
Animation<T> setTimingFunction(TimingFunction func);
````

You can set the timinig function to a pre-fabricated OpenGL MSAT timing function.

See the list at: [Animation enumerations](../lists/animation-enums.md).

Example:
````c++
animation.setTimingFunction(TimingFunction::Easing);
````

## Custom timing function
````c++
Animation<T> setTimingFunction(std::function<float(float)> func);
````

You can create a custom timing function with a lambda.

An example of a linear timing function would just be:
````c++
animation.setTimingFunction([](float x) {
    return x;    
});
````

> A warning is shown, if ``func`` doesn't return ``100`` when the input float value
> is ``100``. This is tested when setting the timing function.