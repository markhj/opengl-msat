#include "opengl_msat/model/model.hpp"

#include <filesystem>

Model::Model(const std::string& filename) : filename(filename)
{
    if (!std::filesystem::exists(filename)) {
        critical("File not found: " + filename);
    }
}

Model& Model::load()
{
    Assimp::Importer import;
    const aiScene *scene = import.ReadFile(filename, aiProcess_Triangulate | aiProcess_FlipUVs);

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::string msg = import.GetErrorString();
        critical("Assimp error: " + msg);
    }

    processNode(scene->mRootNode, scene);

    return *this;
}

Object3D Model::toObject()
{
    return object;
}

void Model::processNode(aiNode *node, const aiScene *scene)
{
    for (unsigned int i = 0; i < node->mNumMeshes; i++) {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];

        processMesh(mesh, scene);
    }

    for (unsigned int i = 0; i < node->mNumChildren; i++) {
        processNode(node->mChildren[i], scene);
    }
}

void Model::processMesh(aiMesh *mesh, const aiScene *scene)
{
    std::vector<VertexElement3D> vertices;
    for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        VertexElement3D vertexElement {
            .position = Vec3(
                mesh->mVertices[i].x,
                mesh->mVertices[i].y,
                mesh->mVertices[i].z
                ),
            .color = Color(1.0)
        };

        if (mesh->HasNormals()) {
            vertexElement.normal = {
                mesh->mNormals[i].x,
                mesh->mNormals[i].y,
                mesh->mNormals[i].z
            };
        }

        vertices.push_back(vertexElement);
    }

    for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];

        for (unsigned int j = 0; j < face.mNumIndices; j++) {
            object.add({vertices[face.mIndices[j]]});
        }
    }
}


