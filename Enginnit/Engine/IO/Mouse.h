#ifndef ENGINNIT_MOUSE
#define ENGINNIT_MOUSE

#include "GLFW/glfw3.h"

class Mouse {
public:
	static void SetCallbacks(GLFWwindow* window);

	static double GetXPos();
	static double GetYPos();

	static bool GetButton(int button);
	static bool GetButtonDown(int button);
	static bool GetButtonUp(int button);
private:
	static double x;
	static double y;

	static bool buttons[];
	static bool buttonsDown[];
	static bool buttonsUp[];

	static void MousePosCallback(GLFWwindow* window, double _x, double _y);
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
};

#endif