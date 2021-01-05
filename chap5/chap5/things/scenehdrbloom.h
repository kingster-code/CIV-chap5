#ifndef SCENEHDRBLOOM_H
#define SCENEHDRBLOOM_H

#include "ingredients/scene.h"
#include "ingredients/glslprogram.h"
#include "ingredients/plane.h"
#include "ingredients/teapot.h"
#include "ingredients/sphere.h"

#include "ingredients/cookbookogl.h"

#include <glm/glm.hpp>

class SceneHdrBloom : public Scene
{
private:
    GLSLProgram prog;

    GLuint fsQuad, pass1Index, pass2Index, pass3Index, pass4Index, pass5Index;
    GLuint hdrFbo, blurFbo;
    GLuint hdrTex, tex1, tex2;
    GLuint linearSampler, nearestSampler;

    Plane plane;
    Teapot teapot;
    Sphere sphere;

    float angle, tPrev, rotSpeed;
    int bloomBufWidth, bloomBufHeight;

    void setMatrices();
    void compileAndLinkShader();
    void setupFBO();
    void pass1();
    void pass2();
    void pass3();
    void pass4();
    void pass5();
    float gauss(float, float);
    void drawScene();
    void computeLogAveLuminance();

public:
    SceneHdrBloom();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};

#endif // SCENEHDRBLOOM_H
