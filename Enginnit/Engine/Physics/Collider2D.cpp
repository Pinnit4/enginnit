#include "Collider2D.h"

#include "Physics2D.h"
#include "../Graphics/Drawer.h"

Collider2D::Collider2D() {
	spatial = new Spatial2D();
	rect = new Rect2D();
	Physics2D::RegisterCollider(this);
	enabled = true;
	debugColor = Color(0.5, 1, 0.5);
	isTrigger = false;
}
Collider2D::Collider2D(Vector2f position) {
	spatial = new Spatial2D(position);
	rect = new Rect2D();
	Physics2D::RegisterCollider(this);
	enabled = true;
	debugColor = Color(0.5, 1, 0.5);
	isTrigger = false;
}
Collider2D::Collider2D(Vector2f position, float rotation) {
	spatial = new Spatial2D(position, rotation);
	rect = new Rect2D();
	Physics2D::RegisterCollider(this);
	enabled = true;
	debugColor = Color(0.5, 1, 0.5);
	isTrigger = false;
}
Collider2D::Collider2D(Spatial2D* _spatial) {
	spatial = _spatial;
	rect = new Rect2D();
	Physics2D::RegisterCollider(this);
	enabled = true;
	debugColor = Color(0.5, 1, 0.5);
	isTrigger = false;
}

void Collider2D::Enable() {
	if (enabled) return;
	enabled = true;
	EnableInternal();
}

void Collider2D::Disable() {
	if (!enabled) return;
	enabled = false;
	DisableInternal();
}

void Collider2D::EnableInternal() { Physics2D::RegisterCollider(this); }
void Collider2D::DisableInternal() { Physics2D::UnregisterCollider(this); }

void Collider2D::Destroy() { Disable(); }

Rect2D* Collider2D::GetRect() { return rect; }
void Collider2D::DebugRender() {
	Spatial2D sp = Spatial2D(spatial->position - GraphicsManager::GetCameraPosition(), 0, spatial->scale);
	Drawer::DrawWirePolygon(rect, sp, debugColor);
}

bool Collider2D::AreColliding(const Collider2D& a, const Collider2D& b) {
	Rect2D ar = Rect2D(a.spatial->position + a.rect->GetCenter(), a.rect->GetSize());
	ar.RefreshRotation(a.spatial->rotation);

	Rect2D br = Rect2D(b.spatial->position + b.rect->GetCenter(), b.rect->GetSize());
	br.RefreshRotation(a.spatial->rotation);

	bool intersection = ar.Intersects(br);
	if (intersection) return true;

	bool contains = ar.Contains(br);
	if (contains) return true;

	contains = br.Contains(ar);
	return contains;
}