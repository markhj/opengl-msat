#ifndef OPENGL_MSAT_MODEL_HPP
#define OPENGL_MSAT_MODEL_HPP

#include <iostream>
#include "opengl_msat/geometry/object3d.hpp"
#include "opengl_msat/traits/dev_messaging.hpp"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

/**
 * 3D Model
 *
 * @see https://opengl-msat.readthedocs.io/en/latest/models/models/
 */
class Model : public DeveloperMessaging {
public:
    explicit Model(const std::string& filename);

    Model& load();

    Object3D toObject();

protected:
    void processNode(aiNode *node, const aiScene *scene);

    void processMesh(aiMesh *mesh, const aiScene *scene);

    std::string filename;

    Object3D object;

};

#endif
