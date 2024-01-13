#include "Mouse.h"

#include "../Graphics/imgui/imgui.h"
#include "../Graphics/imgui/imgui_impl_opengl3.h"
#include "../Graphics/imgui/imgui_impl_glfw.h"

double Mouse::x = 0;
double Mouse::y = 0;

bool Mouse::buttons[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsDown[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsUp[GLFW_MOUSE_BUTTON_LAST] = { 0 };

void Mouse::SetCallbacks(GLFWwindow* window) {
	glfwSetCursorPosCallback(window, MousePosCallback);
	glfwSetMouseButtonCallback(window, MouseButtonCallback);
}

void Mouse::MousePosCallback(GLFWwindow* window, double _x, double _y) {
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	ImGuiIO& io = ImGui::GetIO();
	io.MousePos = ImVec2(_x, _y);

	x = _x;
	y = height - _y;
}

void Mouse::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (button < 0)
		return;

	ImGuiIO& io = ImGui::GetIO();
	io.AddMouseButtonEvent(button, action == GLFW_PRESS);

	if (io.WantCaptureMouse) action == GLFW_RELEASE;

	if (action != GLFW_RELEASE && buttons[button] == false) {
		buttonsUp[button] = false;
		buttonsDown[button] = true;
	}
	if (action == GLFW_RELEASE && buttons[button] == true) {
		buttonsDown[button] = false;
		buttonsUp[button] = true;
	}

	buttons[button] = action != GLFW_RELEASE;
}

double Mouse::GetXPos() { return x; }
double Mouse::GetYPos() { return y; }

bool Mouse::GetButtonDown(int button)
{
	bool x = buttonsDown[button];
	buttonsDown[button] = false;
	return x;
}
bool Mouse::GetButton(int button)
{
	return buttons[button];
}
bool Mouse::GetButtonUp(int button)
{
	bool x = buttonsUp[button];
	buttonsUp[button] = false;
	return x;
}