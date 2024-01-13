#ifndef ENGINNIT_ENGINE
#define ENGINNIT_ENGINE

#include "Graphics/Graphics.h"
#include "Physics/Physics2D.h"
#include "Debug/DebugConsole.h"

#include <iostream>

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

	GraphicsManager* graphics;
	Physics2D* physics;
	DebugConsole* console;
};

#endif
