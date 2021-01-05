#ifndef SCENEBLUR_H
#define SCENEBLUR_H

#include "ingredients/scene.h"
#include "ingredients/glslprogram.h"
#include "ingredients/plane.h"
#include "ingredients/cube.h"
#include "ingredients/torus.h"
#include "ingredients/teapot.h"

#include "ingredients/cookbookogl.h"

#include <glm/glm.hpp>

class SceneBlur : public Scene
{
private:
    GLSLProgram prog;

    GLuint fsQuad, pass1Index, pass2Index, pass3Index;
    GLuint renderFBO, intermediateFBO;
    GLuint renderTex, intermediateTex;

    Plane plane;
    Torus torus;
    Teapot teapot;
    Cube cube;

    float angle, tPrev, rotSpeed;

    void setMatrices();
    void compileAndLinkShader();
    void setupFBO();
    void pass1();
    void pass2();
    void pass3();
    float gauss(float, float);

public:
    SceneBlur();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};

#endif // SCENEBLUR_H
