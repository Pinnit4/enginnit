#ifndef ENGINNIT_UI_ELEMENT
#define ENGINNIT_UI_ELEMENT

using namespace std;

class UIElement {
public:
	UIElement();

	int sortingOrder;

	virtual void Render();
	void Destroy();
private:
};

#endif