#ifndef ENGINNIT_UI_HANDLER
#define ENGINNIT_UI_HANDLER

#include "GLFW/glfw3.h"
#include "GLFW/glfw3native.h"

#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_opengl3.h"
#include "../imgui/imgui_impl_glfw.h"

#pragma comment(lib, "opengl32.lib")

#include <iostream>

using namespace std;

class UIHandler {
public:
	UIHandler();

	void Initialize(GLFWwindow* _window);
	void Render();
	void Shutdown();
private:
	GLFWwindow* window;
};

#endif