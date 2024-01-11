#include "Collider2D.h"

#include "Physics2D.h"
#include "../Debug/DebugDrawer.h"

Collider2D::Collider2D() : Spatial2D() {
	rect = new Rect2D();
	Physics2D::RegisterCollider(this);
	enabled = true;
	debugColor = Color(0.5, 1, 0.5);
}
Collider2D::Collider2D(Vector2f position) : Spatial2D(position) {
	rect = new Rect2D();
	Physics2D::RegisterCollider(this);
	enabled = true;
	debugColor = Color(0.5, 1, 0.5);
}
Collider2D::Collider2D(Vector2f position, float rotation) : Spatial2D(position, rotation) {
	rect = new Rect2D();
	Physics2D::RegisterCollider(this);
	enabled = true;
	debugColor = Color(0.5, 1, 0.5);
}

void Collider2D::Destroy() {
	Physics2D::UnregisterCollider(this);
}

Rect2D* Collider2D::GetRect() { return rect; }
void Collider2D::DebugRender() {
	Vector2f pivotDiff = GraphicsManager::GetCameraPosition();
	DebugDrawer::Initialize(position - pivotDiff, 0, scale);

	if (enabled)
		DebugDrawer::SetColor(debugColor);
	else
		DebugDrawer::SetColor(debugColor * 0.25);

	DebugDrawer::DrawWirePolygon(rect->GetPoints());
}

bool Collider2D::AreColliding(const Collider2D& a, const Collider2D& b) {
	Rect2D ar = Rect2D(a.position + a.rect->GetCenter(), a.rect->GetSize());
	ar.RefreshRotation(a.rotation);

	Rect2D br = Rect2D(b.position + b.rect->GetCenter(), b.rect->GetSize());
	br.RefreshRotation(a.rotation);

	bool intersection = ar.Intersects(br);
	if (intersection) return true;

	bool contains = ar.Contains(br);
	if (contains) return true;

	contains = br.Contains(ar);
	return contains;
}