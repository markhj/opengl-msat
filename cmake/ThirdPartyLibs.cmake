find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)
find_package(Freetype REQUIRED)
find_package(assimp REQUIRED)

target_link_libraries(opengl_msat PRIVATE glfw opengl32 assimp glm freetype)
