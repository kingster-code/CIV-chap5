#ifndef SCENEEDGE_H
#define SCENEEDGE_H

#include "ingredients/scene.h"
#include "ingredients/glslprogram.h"
#include "ingredients/plane.h"
#include "ingredients/torus.h"
#include "ingredients/teapot.h"
#include "ingredients/cube.h"

#include "ingredients/cookbookogl.h"

#include <glm/glm.hpp>

class SceneEdge : public Scene
{
private:
	GLSLProgram prog;

	GLuint fsQuad, pass1Index, pass2Index, fboHandle, renderTex;

	Plane plane;
	Torus torus;
	Teapot teapot;
	Cube cube1;
	Cube cube2;

	float angle, tPrev, rotSpeed;

	void setMatrices();
	void compileAndLinkShader();
	void setupFBO();
	void pass1();
	void pass2();

public:
	SceneEdge();

	void initScene();
	void update(float t);
	void render();
	void resize(int, int);
};

#endif // SCENEEDGE_H
