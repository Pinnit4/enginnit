#define GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WGL

#ifndef ENGINNIT_GRAPHICS
#define ENGINNIT_GRAPHICS

#include "GLFW/glfw3.h"
#include "GLFW/glfw3native.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"

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
	void Shutdown();

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