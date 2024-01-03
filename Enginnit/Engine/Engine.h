#ifndef ENGINNIT_ENGINE
#define ENGINNIT_ENGINE

#include "GLFW/glfw3.h"
#pragma comment(lib, "opengl32.lib")

#include "Graphics/Graphics.h"

#include <iostream>
#include "Physics/Physics2D.h"
using namespace std;

class Engine {
public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;

	static double deltaTime;

	Engine();
	~Engine();

	bool Initialize(char* windowTitle);
	
	void Update();
	void Render();
private:
	static GLFWwindow* window;

	double lastTime;

	Graphics graphics;
	Physics2D physics;
};

#endif
