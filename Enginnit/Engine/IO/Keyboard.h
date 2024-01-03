#ifndef ENGINNIT_KEYBOARD
#define ENGINNIT_KEYBOARD

#include "GLFW/glfw3.h"

class Keyboard {
public:
	static void SetCallbacks(GLFWwindow* window);

	static bool GetKey(int key);
	static bool GetKeyDown(int key);
	static bool GetKeyUp(int key);
private:
	static bool keys[];
	static bool keysDown[];
	static bool keysUp[];

	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

#endif