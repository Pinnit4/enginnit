#include "Rect2D.h"

#include "../Graphics/Graphics.h"
#include "../Graphics/Debug/DebugDrawer.h"

Rect2D::Rect2D() {
	center = Vector2f::Zero();
	size = Vector2f::Zero();
	UpdateVertices();
}

Rect2D::Rect2D(Vector2f _size) {
	center = Vector2f::Zero();
	size = _size;
	UpdateVertices();
}

Rect2D::Rect2D(Vector2f _center, Vector2f _size) {
	center = _center;
	size = _size;
	UpdateVertices();
}

void Rect2D::SetCenter(Vector2f _center) {
	center = _center;
	UpdateVertices();
}
void Rect2D::SetSize(Vector2f _size) {
	size = _size;
	UpdateVertices();
}

Vector2f Rect2D::GetCenter() { return center; }
Vector2f Rect2D::GetSize() { return size; }

Vector2f Rect2D::GetUpperLeftVertex() { return upperLeftVertex; }
Vector2f Rect2D::GetUpperRightVertex() { return upperRightVertex; }
Vector2f Rect2D::GetLowerLeftVertex() { return lowerLeftVertex; }
Vector2f Rect2D::GetLowerRightVertex() { return lowerRightVertex; }

void Rect2D::UpdateVertices() {
	lowerLeftVertex = Vector2f(center.x - (size.x / 2), center.y - (size.y / 2));
	lowerRightVertex = Vector2f(center.x + (size.x / 2), center.y - (size.y / 2));
	upperLeftVertex = Vector2f(center.x - (size.x / 2), center.y + (size.y / 2));
	upperRightVertex = Vector2f(center.x + (size.x / 2), center.y + (size.y / 2));

	lastRotation = 0;
}

void Rect2D::DebugRender(TransformData data, Color color) {
	Vector2f pivotDiff = Graphics::GetCameraPosition();

	DebugDrawer::Initialize(data.position - pivotDiff, 0, data.scale);
	DebugDrawer::SetColor(color);
	DebugDrawer::DrawWireCube(lowerLeftVertex, lowerRightVertex, upperLeftVertex, upperRightVertex);
}

void Rect2D::RefreshRotation(float rotation) {
	float rotDelta = rotation - lastRotation;
	if (rotDelta == 0) return;

	lowerLeftVertex = Math::RotatePoint(lowerLeftVertex, Vector2f::Zero(), rotDelta);
	lowerRightVertex = Math::RotatePoint(lowerRightVertex, Vector2f::Zero(), rotDelta);
	upperLeftVertex = Math::RotatePoint(upperLeftVertex, Vector2f::Zero(), rotDelta);
	upperRightVertex = Math::RotatePoint(upperRightVertex, Vector2f::Zero(), rotDelta);

	lastRotation = rotation;
}