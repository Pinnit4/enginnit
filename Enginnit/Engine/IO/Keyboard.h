#ifndef ENGINNIT_KEYBOARD
#define ENGINNIT_KEYBOARD

#include "GLFW/glfw3.h"
#include "KeyCode.h"

class Keyboard {
public:
	static void SetCallbacks(GLFWwindow* window);

	static bool GetKey(KeyCode key);
	static bool GetKeyDown(KeyCode key);
	static bool GetKeyUp(KeyCode key);
private:
	static bool keys[];
	static bool keysDown[];
	static bool keysUp[];

	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

#endif