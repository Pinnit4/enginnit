#ifndef ENGINNIT_UI_ELEMENT
#define ENGINNIT_UI_ELEMENT

using namespace std;

class UIElement {
public:
	UIElement();

	int sortingOrder;

	virtual void Render();
	virtual void Destroy();
private:
};

#endif