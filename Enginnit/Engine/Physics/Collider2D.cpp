#include "Collider2D.h"

Collider2D::Collider2D() : Spatial2D() {

}
Collider2D::Collider2D(Vector2 position) : Spatial2D(position) {

}
Collider2D::Collider2D(Vector2 position, float rotation) : Spatial2D(position, rotation) {

}

Rect2D Collider2D::GetRect() { return rect; }
void Collider2D::DebugRender(Color color) {
	rect.DebugRender(TransformData::FromSpatial2D(*this), color);
}