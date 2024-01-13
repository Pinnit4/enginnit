#ifndef ENGINNIT_UI_MANAGER
#define ENGINNIT_UI_MANAGER

#include "UI.h"

#include <list>
#include <vector>
#include <functional>

using namespace std;

class UIManager {
public:
	UIManager();

	void Initialize(GLFWwindow* _window);
	void Render();
	void Shutdown();

	static void RegisterUIElement(UIElement* element);
	static void UnregisterUIElement(UIElement* element);
private:
	static list<UIElement*> rgEl;

	GLFWwindow* window;

	void RenderUIElements();
};

#endif