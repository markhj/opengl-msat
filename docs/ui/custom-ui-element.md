# Creating a custom UI element

In this article we'll review how to create a custom UI element which can be used with the
_[UIElementManager](ui-elements.md)_.

## Creating the class
Step 1 is to create a class which extends ``UIElement``.

````c++
class MyCustomElement : public UIElement {

};
````

This class has one abstract method:

````c++
std::vector<GLfloat> getVertices();
````

So the final class should look like this:

````c++
class MyCustomElement : public UIElement {
public:
    std::vector<GLfloat> getVertices() override;
};
````

## Populating the class

The ``getVertices`` returns a set of ``GLfloat`` fitted
so that each vertex has 7 values:

- 3D position (X, Y, Z)
- RGBA color (R, G, B, A)

This will be used by the ``UIElementManager`` to draw
how your specific element should look.
