# Creating a UI

Creating and managing a user interface with OpenGL MSAT is fairly easy.

It works by creating a [UI](../ui/ui.md) object which is main driver,
and then a [UI Element Manager](../ui/ui-elements.md), which technically
is an optional tool, by highly recommended.

## Setting up
First, create the ``UI``:

````c++
UI ui(&window, &camera);
````

And then the ``UIElementManager``:

````c++
UIElementManager uiem;
````

## Adding elements
Now you can start adding UI elements, such as the [Progress Bar](../ui/progress-bar.md).

````c++
ProgressBar healthBar;
healthBar.position = Vec2(15, 15);
healthBar.progress = 100;
````

## Attaching elements
Remember to attach the UI elements to the manager:

````c++
uiem.attach(&healthBar);
````

## Rendering
In your render loop, remember to add:

````c++
renderer.loop([&](Renderer* renderer) {
    // Primary rendering logic
    
    ui.setVertices(uiem.getVertices());
    ui.render(renderer);
}
````

Now, whenever you make updates to the progress bar it's automatically applied.
For instance:

````c++
renderer.loop([&](Renderer* renderer) {
    // Primary rendering logic
    
    // ...
    
    healthBar.progress = 75;
    
    // ...
    
    ui.setVertices(uiem.getVertices());
    ui.render(renderer);
}
````

## That's it!

You can add as many UI elements as needed.
