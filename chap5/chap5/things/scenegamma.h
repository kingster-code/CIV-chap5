#ifndef SCENEGAMMA_H
#define SCENEGAMMA_H

#include "ingredients/scene.h"
#include "ingredients/glslprogram.h"
#include "ingredients/plane.h"
#include "ingredients/torus.h"
#include "ingredients/objmesh.h"

#include "ingredients/cookbookogl.h"

#include <glm/glm.hpp>

class SceneGamma : public Scene
{
private:
    GLSLProgram prog;

    Plane plane;
    Torus torus;
    std::unique_ptr<ObjMesh> ogre;

    float angle, tPrev, rotSpeed;

    void setMatrices();
    void compileAndLinkShader();
    void setupFBO();

public:
    SceneGamma();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};

#endif // SCENEGAMMA_H
