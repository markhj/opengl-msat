#include "opengl_msat/types/scenes.hpp"

Scene2D::Scene2D(const std::vector<Object2D *> &objects)
{
    for (Object2D* obj : objects) {
        add(obj);
    }
}

Scene3D::Scene3D(const std::vector<Object3D *> &objects)
{
    for (Object3D* obj : objects) {
        add(obj);
    }
}
