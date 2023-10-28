#ifndef OPENGL_MSAT_UI_ELEMENT_HPP
#define OPENGL_MSAT_UI_ELEMENT_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include "opengl_msat/common.h"
#include "opengl_msat/geometry/vectors.hpp"
#include "opengl_msat/types/color.hpp"
#include "opengl_msat/geometry/rectangle.hpp"

class UIElement {
public:
    virtual std::vector<GLfloat> getVertices() = 0;

    Vec2 position = Vec2(0.0);
};

class ProgressBar : public UIElement {
public:
    std::vector<GLfloat> getVertices() override;

    float progress = 0.0,
        width = 200.0,
        height = 30.0;

    ColorRGBA background = ColorRGBA(1.0, 1.0, 1.0, 0.5),
        foreground = ColorRGBA(1.0);

};

class UIElementManager {
public:
    void attach(UIElement* element);

    std::vector<GLfloat> getVertices();

private:
    std::vector<UIElement*> elements;

};

#endif
