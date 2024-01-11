#include "Rect2D.h"

Rect2D::Rect2D() : Polygon() {
	SetSize(Vector2f::Zero());

}

Rect2D::Rect2D(Vector2f size) : Polygon() {
	SetSize(size);
}

Rect2D::Rect2D(Vector2f center, Vector2f size) : Polygon(center) {
	SetSize(size);
}

void Rect2D::SetSize(Vector2f _size) {
	size = _size;
	UpdateVertices();
}

Vector2f Rect2D::GetSize() { return size; }


void Rect2D::CreateVertices() {
	points.push_back(Vector2f(center.x - (size.x / 2), center.y + (size.y / 2)));
	points.push_back(Vector2f(center.x + (size.x / 2), center.y + (size.y / 2)));
	points.push_back(Vector2f(center.x + (size.x / 2), center.y - (size.y / 2)));
	points.push_back(Vector2f(center.x - (size.x / 2), center.y - (size.y / 2)));
}