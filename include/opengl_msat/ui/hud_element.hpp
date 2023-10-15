#ifndef OPENGL_MSAT_HUD_ELEMENT_HPP
#define OPENGL_MSAT_HUD_ELEMENT_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include "opengl_msat/common.h"
#include "opengl_msat/geometry/vectors.hpp"
#include "opengl_msat/types/color.hpp"

class HUDElement {
public:
    virtual std::vector<GLfloat> getVertices() = 0;

    Vec2 position = Vec2(0.0);
};

class ProgressBar : public HUDElement {
public:
    std::vector<GLfloat> getVertices() override
    {
        float progressWidth = width * std::clamp(progress, 0.0f, 100.0f) / 100,
            z1 = 0.0,
            z2 = 0.1;

        Vec2 topLeft(position.x, position.y),
            bottomRight(position.x + width, position.y + height),
            progressCoord(position.x + progressWidth, position.y + height);

        Color bg = background,
            fg = foreground;

        return {
            topLeft.x, topLeft.y, z1,               bg.r, bg.g, bg.b, 1.0,
            topLeft.x, bottomRight.y, z1,           bg.r, bg.g, bg.b, 1.0,
            bottomRight.x, bottomRight.y, z1,       bg.r, bg.g, bg.b, 1.0,

            topLeft.x, topLeft.y,  z1,              bg.r, bg.g, bg.b, 1.0,
            bottomRight.x, bottomRight.y,  z1,      bg.r, bg.g, bg.b, 1.0,
            bottomRight.x, topLeft.y,  z1,          bg.r, bg.g, bg.b, 1.0,

            topLeft.x, topLeft.y, z2,               fg.r, fg.g, fg.b, 1.0,
            topLeft.x, progressCoord.y, z2,         fg.r, fg.g, fg.b, 1.0,
            progressCoord.x, progressCoord.y, z2,   fg.r, fg.g, fg.b, 1.0,

            topLeft.x, topLeft.y, z2,               fg.r, fg.g, fg.b, 1.0,
            progressCoord.x, progressCoord.y, z2,   fg.r, fg.g, fg.b, 1.0,
            progressCoord.x, topLeft.y, z2,         fg.r, fg.g, fg.b, 1.0,
        };
    }

    float progress = 0.0,
        width = 200.0,
        height = 30.0;

    Color background = Color(0.5),
        foreground = Color(1.0);

};

class HUDElementManager {
public:
    void attach(HUDElement* element)
    {
        elements.push_back(element);
    }

    std::vector<GLfloat> getVertices()
    {
        std::vector<GLfloat> result;
        for (HUDElement* elm : elements) {
            std::vector<GLfloat> output = elm->getVertices();
            result.insert(result.end(), output.begin(), output.end());
        }
        return result;
    }

private:
    std::vector<HUDElement*> elements;

};

#endif
