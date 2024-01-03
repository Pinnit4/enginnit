#include "Graphics.h"

std::list<Sprite*> Graphics::rgSp = {};
GLFWwindow* Graphics::window = NULL;

Graphics::Graphics() {
	window = NULL;

	rgSp.clear();
}

Graphics::Graphics(GLFWwindow* _window) {
	window = _window;

	glfwMakeContextCurrent(window);
	glfwGetFramebufferSize(window, &width, &height);
	glfwSwapInterval(1);

	rgSp.clear();

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
	//io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
	
	ImGui::StyleColorsDark();

	// Setup Platform/Renderer backends
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init();
}

void Graphics::Set2DViewport(int depth) {
	glViewport(0, 0, width, height); // Set the viewport
	glMatrixMode(GL_PROJECTION); // Set the matrix mode (projection for 2D, investigate more for 3D)
	glLoadIdentity(); // Load a blank matrix
	glOrtho(0, width, 0, height, -depth, depth); // Set an orthographic camera and its bounds
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

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	ImGui::ShowDemoWindow();
}

void Graphics::EndRender() {
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	// After drawing, swap the buffers to show the new rendered frame
	glfwSwapBuffers(window);
}

void Graphics::RegisterSprite(Sprite* sp) {
	if (rgSp.size() > 0) {
		std::list<Sprite*>::iterator findIt = std::find(rgSp.begin(), rgSp.end(), sp);
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

	for (std::list<Sprite*>::iterator it = rgSp.begin(); it != rgSp.end(); it++) {
		(*it)->Render();
	}
}