#include "Engine.h"
#include "IO/Mouse.h"
#include "IO/Keyboard.h"
#include "Graphics/Graphics.h"

int Engine::SCREEN_WIDTH = 1024;
int Engine::SCREEN_HEIGHT = 768;

GLFWwindow* Engine::window = NULL;

double Engine::deltaTime = 0;

Engine::Engine() {

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
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);
	if (window == NULL) {
		cout << "Error creating window" << endl;
		return false;
	}

	graphics = Graphics(window);

	// Set window at the center of the screen
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int xPos = (mode->width - SCREEN_WIDTH) / 2;
	int yPos = (mode->height - SCREEN_HEIGHT) / 2;
	glfwSetWindowPos(window, xPos, yPos);

	graphics.Set2DViewport(10);
	graphics.EnableAlphaBlending();

	physics = Physics2D();
	
	Mouse::SetCallbacks(window);
	Keyboard::SetCallbacks(window);

	lastTime = glfwGetTime();

	return true;
}

void Engine::Update() 
{ 
	double now = glfwGetTime();
	deltaTime = now - lastTime;
	lastTime = now;

	glfwPollEvents(); 

	physics.Tick(deltaTime);
}

void Engine::Render() { graphics.Render(); }