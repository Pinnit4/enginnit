#include "UIElement.h"

#include "UIManager.h"
#include "../GraphicsInternal.h"
#include "../GraphicsManager.h"

void BeginRender();
void EndRender();

UIElement::UIElement() {
	sortingOrder = 0;
	rect = new Rect2D();

	UIManager::RegisterUIElement(this);
	parent = NULL;
	children = {};

	anchorMin = Vector2f::Zero();
	anchorMax = Vector2f::One();

	lowerLeftCorner = Vector2f::Zero();
	upperRightCorner = Vector2f::Zero();

	RefreshRect();
}

void UIElement::Render() {

}

void UIElement::Destroy() {
	UIManager::UnregisterUIElement(this);
}

void UIElement::SetParent(UIElement* _parent) {
	if (parent != _parent) {
		if (parent != NULL) {
			parent->RemoveChild(this);
		}
		parent = _parent;
		parent->AddChild(this);
		RefreshRect();
	}
}

void UIElement::AddChild(UIElement* _child) {
	children.push_back(_child);
	_child->RefreshRect();
}

void UIElement::RemoveChild(UIElement* _child) {
	if (children.size() > 0) {
		children.remove_if([&](UIElement* x) -> bool {return x == _child; });
	}
	_child->RefreshRect();
}

void UIElement::SetAnchors(Vector2f _anchorMin, Vector2f _anchorMax) {
	anchorMin = _anchorMin;
	anchorMax = _anchorMax;
	RefreshRect();
}

void UIElement::SetCorners(Vector2f _lowerLeftCorner, Vector2f _upperRightCorner) {
	lowerLeftCorner = _lowerLeftCorner;
	upperRightCorner = _upperRightCorner;
	RefreshRect();
}

Rect2D* UIElement::GetRect() { return rect; }

void UIElement::RefreshRect() {
	vector<Vector2f> parentCorners = {};
	Vector2f screenSize = (Vector2f)GraphicsManager::GetScreenSize();

	if (parent == NULL) {
		Vector2f halfSize = screenSize / (GraphicsManager::GetProjectionScale() * 2.0);
		parentCorners = { Vector2f(-halfSize.x, -halfSize.y), Vector2f(-halfSize.x,halfSize.y), Vector2f(halfSize.x, halfSize.y), Vector2f(halfSize.x,-halfSize.y) };
	}
	else {
		parentCorners = parent->GetRect()->GetPoints();
	}

	Vector2f ll = Vector2f(
		Math::Lerp(parentCorners[0].x, parentCorners[2].x, anchorMin.x) + lowerLeftCorner.x,
		Math::Lerp(parentCorners[0].y, parentCorners[2].y, anchorMin.y) + lowerLeftCorner.y
	);

	Vector2f ur = Vector2f(
		Math::Lerp(parentCorners[0].x, parentCorners[2].x, anchorMax.x) + upperRightCorner.x,
		Math::Lerp(parentCorners[0].y, parentCorners[2].y, anchorMax.y) + upperRightCorner.y
	);

	Vector2f ul = Vector2f(ll.x, ur.y);
	Vector2f lr = Vector2f(ur.x, ll.x);

	rect->SetSize(Vector2f(ur.x - ll.x, ur.y - ll.y));
	rect->SetCenter(Vector2f((ur.x + ll.x) / 2.0, (ur.y + ll.y) / 2.0));

	for (auto c : children) {
		c->RefreshRect();
	}
}