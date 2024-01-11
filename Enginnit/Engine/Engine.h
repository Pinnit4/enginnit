#ifndef ENGINNIT_ENGINE
#define ENGINNIT_ENGINE

#include "GLFW/glfw3.h"
#pragma comment(lib, "opengl32.lib")

#include "Graphics/Graphics.h"
#include "Graphics/GraphicsManager.h"

#include <iostream>
#include "Physics/Physics2D.h"

using namespace std;

class Engine {
public:
	static double deltaTime;

	Engine();
	~Engine();

	bool Initialize(char* windowTitle);

	bool ShouldShutdown();
	void Shutdown();

	void Update();
	void Render();
private:
	static GLFWwindow* window;

	double lastTime;

	GraphicsManager graphics;
	Physics2D physics;
};

#endif
