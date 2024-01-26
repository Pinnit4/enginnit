#ifndef ENGINNIT_GRAPHICS_MANAGER
#define ENGINNIT_GRAPHICS_MANAGER

#define GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WGL

#include "GraphicsInternal.h"
#include "Sprites/Sprite.h"
#include "UI/UI.h"

#include <list>
#include <vector>
#include <functional>

using namespace std;

class GraphicsManager {
public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;

	static vector<function<void()>> onBeginRender;

	static vector<function<void()>> beforeUiRender;
	static vector<function<void()>> afterUiRender;

	static vector<function<void()>> onEndRender;

	GraphicsManager();
	void Initialize(GLFWwindow* _window);

	void Set2DViewport(int depth);
	void EnableAlphaBlending();

	static Vector2i GetScreenSize();
	static int GetWidth();
	static int GetHeight();

	static float GetProjectionScale();

	void Render();
	void Shutdown();

	static void RegisterSprite(Sprite* sp);
	static void UnregisterSprite(Sprite* sp);

	static void MoveCamera(Vector2f delta);
	static void SetCameraPosition(Vector2f newPos);
	static Vector2f GetCameraPosition();

private:
	static GLFWwindow* window;
	UIManager uiManager;

	static int width;
	static int height;
	static int depth;

	static float projectionScale;

	static Vector2f camPos;

	static list<Sprite*> rgSp;

	void BeginRender();
	void EndRender();
	void RenderSprites();
};

#endif