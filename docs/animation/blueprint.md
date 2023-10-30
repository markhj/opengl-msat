# Animation blueprint

In this article, we will dig a bit more into the ``AnimationBlueprint`` class.

## Prerequisites
* [Animation](animation.md)

## Steps
As explained in the introduction article, blueprints are defined by one or more steps.

All steps take effect within a percentile range (0-100).

Steps can be defined with one of these three methods:

````c++
AnimationBlueprint<T>& step(float pctFrom, float pctTo, T to);

AnimationBlueprint<T>& step(float pctFrom, float pctTo, T from, T to);

AnimationBlueprint<T>& step(float pctFrom, float pctTo, std::function<T(float)> func);
````

Examples for ``Vec3``:

````c++
blueprint.step(0, 20, Vec3(2.0));
````