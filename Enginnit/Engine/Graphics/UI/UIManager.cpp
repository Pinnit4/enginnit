#include "UIManager.h"

std::list<UIElement*> UIManager::rgEl = {};

void BeginRender();
void EndRender();

UIManager::UIManager() {
	window = NULL;
}

void UIManager::Initialize(GLFWwindow* _window) {
	window = _window;

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

void UIManager::Render() {
	BeginRender();

	RenderUIElements();
	//ImGui::ShowDemoWindow();

	EndRender();
}

void BeginRender() {
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void EndRender() {
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UIManager::Shutdown() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();
}

void UIManager::RegisterUIElement(UIElement* element) {
	if (rgEl.size() > 0) {
		auto findIt = find(rgEl.begin(), rgEl.end(), element);
		if ((findIt) != rgEl.end()) return;
	}
	else if (rgEl.size() > 0) {
		if (rgEl.front() != element) return;
	}
	rgEl.push_back(element);
}

void UIManager::UnregisterUIElement(UIElement* element) {
	if (rgEl.size() > 0) {
		rgEl.remove_if([&](UIElement* x) -> bool {return x == element; });
	}
}

void UIManager::RenderUIElements() {
	if (rgEl.size() == 0)
		return;

	if (rgEl.size() > 1) {
		rgEl.sort(
			[&](UIElement* a, UIElement* b) -> bool
			{
				return (a->sortingOrder < b->sortingOrder);
			});
	}

	for (auto el : rgEl) el->Render();
}