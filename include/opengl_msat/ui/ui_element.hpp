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
    std::vector<GLfloat> getVertices() override
    {
        float progressWidth = width * std::clamp(progress, 0.0f, 100.0f) / 100,
            z1 = 0.0,
            z2 = 0.1;

        Vec2 topLeft(position.x, position.y),
            bottomRight(position.x + width, position.y + height),
            progressCoord(position.x + progressWidth, position.y + height);

        ColorRGBA bg = background,
            fg = foreground;

        return {
            topLeft.x, topLeft.y, z1,               bg.r, bg.g, bg.b, bg.a,
            topLeft.x, bottomRight.y, z1,           bg.r, bg.g, bg.b, bg.a,
            bottomRight.x, bottomRight.y, z1,       bg.r, bg.g, bg.b, bg.a,

            topLeft.x, topLeft.y,  z1,              bg.r, bg.g, bg.b, bg.a,
            bottomRight.x, bottomRight.y,  z1,      bg.r, bg.g, bg.b, bg.a,
            bottomRight.x, topLeft.y,  z1,          bg.r, bg.g, bg.b, bg.a,

            topLeft.x, topLeft.y, z2,               fg.r, fg.g, fg.b, fg.a,
            topLeft.x, progressCoord.y, z2,         fg.r, fg.g, fg.b, fg.a,
            progressCoord.x, progressCoord.y, z2,   fg.r, fg.g, fg.b, fg.a,

            topLeft.x, topLeft.y, z2,               fg.r, fg.g, fg.b, fg.a,
            progressCoord.x, progressCoord.y, z2,   fg.r, fg.g, fg.b, fg.a,
            progressCoord.x, topLeft.y, z2,         fg.r, fg.g, fg.b, fg.a,
        };
    }

    float progress = 0.0,
        width = 200.0,
        height = 30.0;

    ColorRGBA background = ColorRGBA(1.0, 1.0, 1.0, 0.5),
        foreground = ColorRGBA(1.0);

};

class UIElementManager {
public:
    void attach(UIElement* element)
    {
        elements.push_back(element);
    }

    std::vector<GLfloat> getVertices()
    {
        std::vector<GLfloat> result;
        for (UIElement* elm : elements) {
            std::vector<GLfloat> output = elm->getVertices();
            result.insert(result.end(), output.begin(), output.end());
        }
        return result;
    }

private:
    std::vector<UIElement*> elements;

};

#endif
