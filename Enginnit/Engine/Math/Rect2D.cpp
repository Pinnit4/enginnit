#include "Rect2D.h"

#include "../Graphics/Graphics.h"
#include "../Graphics/Debug/DebugDrawer.h"

Rect2D::Rect2D() {
	center = Vector2::Zero();
	size = Vector2::Zero();
	UpdateVertices();
}

Rect2D::Rect2D(Vector2 _size) {
	center = Vector2::Zero();
	size = _size;
	UpdateVertices();
}

Rect2D::Rect2D(Vector2 _center, Vector2 _size) {
	center = _center;
	size = _size;
	UpdateVertices();
}

void Rect2D::SetCenter(Vector2 _center) {
	center = _center;
	UpdateVertices();
	lastRotation = 0;
}
void Rect2D::SetSize(Vector2 _size) {
	size = _size;
	UpdateVertices();
	lastRotation = 0;
}

Vector2 Rect2D::GetCenter() { return center; }
Vector2 Rect2D::GetSize() { return size; }

void Rect2D::UpdateVertices() {
	lowerLeftVertex = Vector2(center.x - (size.x / 2), center.y - (size.y / 2));
	lowerRightVertex = Vector2(center.x + (size.x / 2), center.y - (size.y / 2));
	upperLeftVertex = Vector2(center.x - (size.x / 2), center.y + (size.y / 2));
	upperRightVertex = Vector2(center.x + (size.x / 2), center.y + (size.y / 2));
}

void Rect2D::DebugRender(TransformData data, Color color) {
	Vector2 pivotDiff = Graphics::GetCameraPosition();

	DebugDrawer::Initialize(data.position - pivotDiff, 0, data.scale);
	DebugDrawer::SetColor(color);
	DebugDrawer::DrawWireCube(lowerLeftVertex, lowerRightVertex, upperLeftVertex, upperRightVertex);
}

void Rect2D::RefreshRotation(float rotation) {
	float rotDelta = rotation - lastRotation;
	if (rotDelta == 0) return;

	lowerLeftVertex = Math::RotatePoint(lowerLeftVertex, Vector2::Zero(), rotDelta);
	lowerRightVertex = Math::RotatePoint(lowerRightVertex, Vector2::Zero(), rotDelta);
	upperLeftVertex = Math::RotatePoint(upperLeftVertex, Vector2::Zero(), rotDelta);
	upperRightVertex = Math::RotatePoint(upperRightVertex, Vector2::Zero(), rotDelta);

	lastRotation = rotation;
}