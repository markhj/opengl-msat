# Animation iterations

By default an [animation](animation.md) will run only once.

You use the [rewind function](control.md) in certain scenarios, but you can also
automatically iterate an animation a certain number of times, or let it run indefinitely.

## Specify fixed number of iterations
Simply call ``setIterations``:
````c++
animation.setIterations(5);
````

### Rewinding behavior
If ``Animation::rewind`` is called before an iteration has completed, it will _not_ count.
In other words: Only completed iterations count toward the defined maximum.

## Indefinite
If you want your animation to run forever, you can call ``infinite``:

````c++
animation.infinite();
````
