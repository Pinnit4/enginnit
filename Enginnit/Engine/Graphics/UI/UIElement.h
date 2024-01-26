#ifndef ENGINNIT_UI_ELEMENT
#define ENGINNIT_UI_ELEMENT

#include "../../Math/Math.h"
#include <list>
#include <vector>

using namespace std;

class UIElement {
public:
	UIElement();

	int sortingOrder;

	virtual void Render();
	virtual void Destroy();

	void SetParent(UIElement* parent);

	void SetAnchors(Vector2f anchorMin, Vector2f anchorMax);
	void SetCorners(Vector2f lowerLeftCorner, Vector2f upperRightCorner);

	Rect2D* GetRect();
protected:
	UIElement* parent;
	list<UIElement*> children;

	Rect2D* rect;

	Vector2f anchorMin;
	Vector2f anchorMax;

	Vector2f lowerLeftCorner;
	Vector2f upperRightCorner;

	void RefreshRect();

	void AddChild(UIElement* child);
	void RemoveChild(UIElement* child);
};

#endif