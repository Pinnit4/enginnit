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
#include <vector>
#include <functional>

using namespace std;

class Graphics {
public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;

	static vector<function<void()>> onBeginRender;
	static vector<function<void()>> onEndRender;

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

	static void MoveCamera(Vector2f delta);
	static void SetCameraPosition(Vector2f newPos);
	static Vector2f GetCameraPosition();

private:
	static GLFWwindow* window;
	UIHandler uiHandler;

	static int width;
	static int height;
	static int depth;

	static Vector2f camPos;

	static std::list<Sprite*> rgSp;

	void BeginRender();
	void EndRender();
	void RenderSprites();
};

#endif