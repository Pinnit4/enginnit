#include "Graphics.h"

#ifdef PROFILER_ENABLED
#include "../Profiling/TimeProfiler.h"
#endif

std::list<Sprite*> Graphics::rgSp = {};
GLFWwindow* Graphics::window = NULL;

int Graphics::SCREEN_WIDTH = 1024;
int Graphics::SCREEN_HEIGHT = 768;

int Graphics::width = 0;
int Graphics::height = 0;
int Graphics::depth = 0;

Vector2 Graphics::camPos = Vector2::Zero();

Graphics::Graphics() {
	window = NULL;
	uiHandler = UIHandler();

	rgSp.clear();
}

void Graphics::Initialize(GLFWwindow* _window) {
	window = _window;

	glfwMakeContextCurrent(window);
	glfwGetFramebufferSize(window, &width, &height);
	glfwSwapInterval(1);

	rgSp.clear();

	uiHandler.Initialize(window);
}

void Graphics::Set2DViewport(int _depth) {
	depth = _depth;
	glViewport(0, 0, width, height); // Set the viewport
	glMatrixMode(GL_PROJECTION); // Set the matrix mode (projection for 2D, investigate more for 3D)
	glLoadIdentity(); // Load a blank matrix
	int w = width / 3;
	int h = height / 3;
	glOrtho(-w / 2, w / 2, -h / 2, h / 2, -depth, depth); // Set an orthographic camera and its bounds
	//SetCameraPosition(Vector2(100,-50));
	//glOrtho(0, width / 3, 0, height / 3, -depth, depth); // Set an orthographic camera and its bounds
	glDepthRange(-depth, depth); // Set the depth range to the same as the near-far bounds of the camera
	glMatrixMode(GL_MODELVIEW);
}

void Graphics::EnableAlphaBlending() {
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

int Graphics::GetWidth() { return width; }
int Graphics::GetHeight() { return height; }

void Graphics::Render() {
	BeginRender();

	RenderSprites();
	uiHandler.Render();

	EndRender();
}

void Graphics::Shutdown() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();
}

void Graphics::BeginRender() {
	// Clear the previous rendered frame
	glClearColor(0.4f, 0.3f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Graphics::EndRender() {
	// After drawing, swap the buffers to show the new rendered frame
	glfwSwapBuffers(window);
}

void Graphics::RegisterSprite(Sprite* sp) {
	if (rgSp.size() > 0) {
		list<Sprite*>::iterator findIt = find(rgSp.begin(), rgSp.end(), sp);
		if ((findIt) != rgSp.end()) return;
	}
	else if (rgSp.size() > 0) {
		if (rgSp.front() != sp) return;
	}
	rgSp.push_back(sp);
}

void Graphics::UnregisterSprite(Sprite* sp) {
	if (rgSp.size() > 0) {
		rgSp.remove_if([&](Sprite* x) -> bool {return x == sp; });
	}
}

void Graphics::RenderSprites() {
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
	//cout << "Finished sprite rendering in " << duration << "s" << endl;
#endif
}

void Graphics::MoveCamera(Vector2 delta) { camPos += delta; }

void Graphics::SetCameraPosition(Vector2 newPos) { camPos = newPos; }

Vector2 Graphics::GetCameraPosition() { return camPos; }