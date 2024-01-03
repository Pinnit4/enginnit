#ifndef ENGINNIT_GRAPHICS
#define ENGINNIT_GRAPHICS

#include "GLFW/glfw3.h"
#pragma comment(lib, "opengl32.lib")

#include "Sprite.h"
#include <list>

#include <iostream>
using namespace std;

class Graphics {
public:
	Graphics();
	Graphics(GLFWwindow* _window);

	void Set2DViewport(int depth);
	void EnableAlphaBlending();

	int GetWidth();
	int GetHeight();

	void Render();

	static void RegisterSprite(Sprite* sp);
	static void UnregisterSprite(Sprite* sp);

private:
	static GLFWwindow* window;

	int width;
	int height;

	static std::list<Sprite*> rgSp;

	void BeginRender();
	void EndRender();
	void RenderSprites();
};

#endif