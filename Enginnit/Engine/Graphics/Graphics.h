#define GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WGL

#ifndef ENGINNIT_GRAPHICS
#define ENGINNIT_GRAPHICS

#include "GLFW/glfw3.h"
#include "GLFW/glfw3native.h"

#pragma comment(lib, "opengl32.lib")

#include "Sprite.h"
#include "UI/UIHandler.h"

#include <list>
#include <iostream>

using namespace std;

class Graphics {
public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;

	Graphics();
	void Initialize(GLFWwindow* _window);

	void Set2DViewport(int depth);
	void EnableAlphaBlending();

	int GetWidth();
	int GetHeight();

	void Render();
	void Shutdown();

	static void RegisterSprite(Sprite* sp);
	static void UnregisterSprite(Sprite* sp);

	static void MoveCamera(Vector2 delta);
	static void SetCameraPosition(Vector2 newPos);
	static Vector2 GetCameraPosition();

private:
	static GLFWwindow* window;
	UIHandler uiHandler;

	static int width;
	static int height;
	static int depth;

	static Vector2 camPos;

	static std::list<Sprite*> rgSp;

	void BeginRender();
	void EndRender();
	void RenderSprites();
};

#endif