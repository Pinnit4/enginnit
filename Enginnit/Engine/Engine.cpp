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

	graphics = new GraphicsManager();
	graphics->Initialize(window);

	CenterOnScreen(window);

	graphics->Set2DViewport(10);
	graphics->EnableAlphaBlending();

	physics = new Physics2D();
	physics->Initialize();

	nodes = new NodeManager();

	Mouse::SetCallbacks(window);
	Keyboard::SetCallbacks(window);

	lastTime = glfwGetTime();

#ifdef _DEBUG
	console = new DebugConsole();
#endif

	return true;
}

void Engine::Shutdown() {
#ifdef _DEBUG
	console->Destroy();
#endif
	graphics->Shutdown();
	physics->Shutdown();
}

void Engine::Update() {
	double now = glfwGetTime();
	deltaTime = now - lastTime;
	lastTime = now;

	glfwPollEvents();

	nodes->PhysicsTick(deltaTime);
	physics->Tick(deltaTime);

	nodes->Tick(deltaTime);

#ifdef _DEBUG
	console->Tick(deltaTime);
#endif
}

bool Engine::ShouldShutdown() {
	return glfwWindowShouldClose(window);
}

void Engine::Render() {
	graphics->Render();
}

void Engine::LateUpdate() {
	nodes->LateTick(deltaTime);
}

void CenterOnScreen(GLFWwindow* window) {
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int xPos = (mode->width - GraphicsManager::SCREEN_WIDTH) / 2;
	int yPos = (mode->height - GraphicsManager::SCREEN_HEIGHT) / 2;
	glfwSetWindowPos(window, xPos, yPos);
}
