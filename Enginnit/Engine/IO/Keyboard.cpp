#include "Keyboard.h"

#include "../Graphics/imgui/imgui.h"
#include "../Graphics/imgui/imgui_impl_opengl3.h"
#include "../Graphics/imgui/imgui_impl_glfw.h"
#include <iostream>

bool Keyboard::keys[GLFW_KEY_LAST] = { 0 };
bool Keyboard::keysDown[GLFW_KEY_LAST] = { 0 };
bool Keyboard::keysUp[GLFW_KEY_LAST] = { 0 };

void Keyboard::SetCallbacks(GLFWwindow* window) {
	glfwSetKeyCallback(window, KeyCallback);
}

void Keyboard::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key < 0)
		return;

	ImGuiIO& io = ImGui::GetIO();
	ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);

	if (io.WantCaptureKeyboard) action == GLFW_RELEASE;

	if (action != GLFW_RELEASE && keys[key] == false) {
		keysUp[key] = false;
		keysDown[key] = true;
	}
	if (action == GLFW_RELEASE && keys[key] == true) {
		keysDown[key] = false;
		keysUp[key] = true;
	}

	keys[key] = action != GLFW_RELEASE;
}

bool Keyboard::GetKeyDown(KeyCode key)
{
	int keyInt = KeyCodeHelper::ToGLFW(key);
	bool x = keysDown[keyInt];
	keysDown[keyInt] = false;
	return x;
}
bool Keyboard::GetKey(KeyCode key)
{
	return keys[KeyCodeHelper::ToGLFW(key)];
}
bool Keyboard::GetKeyUp(KeyCode key)
{
	int keyInt = KeyCodeHelper::ToGLFW(key);
	bool x = keysUp[keyInt];
	keysUp[keyInt] = false;
	return x;
}