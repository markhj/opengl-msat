#include "opengl_msat/ui/ui_element.hpp"

std::vector<GLfloat> ProgressBar::getVertices()
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

void UIElementManager::attach(UIElement *element)
{
    elements.push_back(element);
}

std::vector<GLfloat> UIElementManager::getVertices()
{
    std::vector<GLfloat> result;
    for (UIElement* elm : elements) {
        std::vector<GLfloat> output = elm->getVertices();
        result.insert(result.end(), output.begin(), output.end());
    }
    return result;
}
