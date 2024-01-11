#include "Engine.h"
#include "IO/Mouse.h"
#include "IO/Keyboard.h"
#include "Graphics/Graphics.h"

GLFWwindow* Engine::window = NULL;

double Engine::deltaTime = 0;
void CenterOnScreen(GLFWwindow* window);

Engine::Engine() {
	lastTime = 0;
}

Engine::~Engine() {

}

bool Engine::Initialize(char* windowTitle) {
	// Initialize GLFW
	if (!glfwInit()) {
		cout << "Error initializing GLFW" << endl;
		return false;
	}

	// Create a window
	window = glfwCreateWindow(GraphicsManager::SCREEN_WIDTH, GraphicsManager::SCREEN_HEIGHT, windowTitle, NULL, NULL);
	if (window == NULL) {
		cout << "Error creating window" << endl;
		return false;
	}

	graphics = GraphicsManager();
	graphics.Initialize(window);

	CenterOnScreen(window);

	graphics.Set2DViewport(10);
	graphics.EnableAlphaBlending();

	physics = Physics2D();
	physics.Initialize();

	Mouse::SetCallbacks(window);
	Keyboard::SetCallbacks(window);

	lastTime = glfwGetTime();

	return true;
}

void Engine::Shutdown() {
	graphics.Shutdown();
	physics.Shutdown();
}

void Engine::Update() {
	double now = glfwGetTime();
	deltaTime = now - lastTime;
	lastTime = now;

	glfwPollEvents();

	physics.Tick(deltaTime);
}

bool Engine::ShouldShutdown() {
	return glfwWindowShouldClose(window);
}

void Engine::Render() {
	graphics.Render();
}

void CenterOnScreen(GLFWwindow* window) {
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int xPos = (mode->width - GraphicsManager::SCREEN_WIDTH) / 2;
	int yPos = (mode->height - GraphicsManager::SCREEN_HEIGHT) / 2;
	glfwSetWindowPos(window, xPos, yPos);
}
