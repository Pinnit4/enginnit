#include "GraphicsManager.h"

#ifdef PROFILER_ENABLED
#include "../Profiling/TimeProfiler.h"
#endif
#include "../Debug/DebugConsole.h"

std::list<Sprite*> GraphicsManager::rgSp = {};
GLFWwindow* GraphicsManager::window = NULL;

int GraphicsManager::SCREEN_WIDTH = 1024;
int GraphicsManager::SCREEN_HEIGHT = 768;

int GraphicsManager::width = 0;
int GraphicsManager::height = 0;
int GraphicsManager::depth = 0;

float GraphicsManager::projectionScale = 4.0;

vector<function<void()>> GraphicsManager::onBeginRender = vector<function<void()>>();

vector<function<void()>> GraphicsManager::beforeUiRender = vector<function<void()>>();
vector<function<void()>> GraphicsManager::afterUiRender = vector<function<void()>>();

vector<function<void()>> GraphicsManager::onEndRender = vector<function<void()>>();

Vector2f GraphicsManager::camPos = Vector2f::Zero();

GraphicsManager::GraphicsManager() {
	window = NULL;
	uiManager = UIManager();

	rgSp.clear();
}

void GraphicsManager::Initialize(GLFWwindow* _window) {
	window = _window;

	glfwMakeContextCurrent(window);
	glfwGetFramebufferSize(window, &width, &height);
	glfwSwapInterval(1);

	rgSp.clear();

	uiManager.Initialize(window);
}

void GraphicsManager::Set2DViewport(int _depth) {
	depth = _depth;
	glViewport(0, 0, width, height); // Set the viewport
	glMatrixMode(GL_PROJECTION); // Set the matrix mode (projection for 2D, investigate more for 3D)
	glLoadIdentity(); // Load a blank matrix
	int w = width / projectionScale;
	int h = height / projectionScale;
	glOrtho(-w / 2, w / 2, -h / 2, h / 2, -depth, depth); // Set an orthographic camera and its bounds
	//SetCameraPosition(Vector2(100,-50));
	//glOrtho(0, width / 3, 0, height / 3, -depth, depth); // Set an orthographic camera and its bounds
	glDepthRange(-depth, depth); // Set the depth range to the same as the near-far bounds of the camera
	glMatrixMode(GL_MODELVIEW);
}

void GraphicsManager::EnableAlphaBlending() {
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

Vector2i GraphicsManager::GetScreenSize() { return Vector2i(width, height); }
int GraphicsManager::GetWidth() { return width; }
int GraphicsManager::GetHeight() { return height; }

float GraphicsManager::GetProjectionScale() { return projectionScale; }

void GraphicsManager::Render() {
	BeginRender();

	RenderSprites();

	for (auto& callback : beforeUiRender) callback();
	uiManager.Render();
	for (auto& callback : afterUiRender) callback();

	EndRender();
}

void GraphicsManager::Shutdown() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();
}

void GraphicsManager::BeginRender() {
	// Clear the previous rendered frame
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (auto& callback : onBeginRender) callback();
}

void GraphicsManager::EndRender() {

	for (auto& callback : onEndRender) callback();

	// After drawing, swap the buffers to show the new rendered frame
	glfwSwapBuffers(window);
}

void GraphicsManager::RegisterSprite(Sprite* sp) {
	if (rgSp.size() > 0) {
		list<Sprite*>::iterator findIt = find(rgSp.begin(), rgSp.end(), sp);
		if ((findIt) != rgSp.end()) return;
	}
	else if (rgSp.size() > 0) {
		if (rgSp.front() != sp) return;
	}
	rgSp.push_back(sp);
}

void GraphicsManager::UnregisterSprite(Sprite* sp) {
	if (rgSp.size() > 0) {
		rgSp.remove_if([&](Sprite* x) -> bool {return x == sp; });
	}
}

void GraphicsManager::RenderSprites() {
	if (rgSp.size() == 0)
		return;

#ifdef PROFILER_ENABLED
	int pId = TimeProfiler::StartProfiler();
#endif

	if (rgSp.size() > 1) {
		rgSp.sort(
			[&](Sprite* a, Sprite* b) -> bool
			{
				if (a->depthLayer == b->depthLayer) {
					return (a->position.y > b->position.y);
				}

				return (a->depthLayer < b->depthLayer);
			});
	}

	for (list<Sprite*>::iterator it = rgSp.begin(); it != rgSp.end(); it++) {
		(*it)->Render();
	}

#ifdef PROFILER_ENABLED
	double duration = TimeProfiler::StopProfiler(pId);
	//DebugConsole::Log("Finished sprite rendering in " + to_string(duration) + "s");
#endif
}

void GraphicsManager::MoveCamera(Vector2f delta) { camPos += delta; }

void GraphicsManager::SetCameraPosition(Vector2f newPos) { camPos = newPos; }

Vector2f GraphicsManager::GetCameraPosition() { return camPos; }