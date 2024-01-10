#include "Collider2D.h"

#include "Physics2D.h"

Vector2f GetProjectionMinMaxOnAxis(Rect2D rect, Vector2f axis);
float GetProjectionScalarOnAxis(Vector2f vertex, Vector2f axis);

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
	if (enabled)
		rect->DebugRender(TransformData::FromSpatial2D(*this), debugColor);
	else
		rect->DebugRender(TransformData::FromSpatial2D(*this), debugColor * 0.25);

}

bool Collider2D::AreColliding(const Collider2D& a, const Collider2D& b) {
	Rect2D ar = Rect2D(a.position + a.rect->GetCenter(), a.rect->GetSize());
	ar.RefreshRotation(a.rotation);

	Rect2D br = Rect2D(b.position + b.rect->GetCenter(), b.rect->GetSize());
	br.RefreshRotation(a.rotation);

	float aMax = 0, aMin = 0;
	float bMax = 0, bMin = 0;

	Vector2f axes[4] = {
		 (ar.GetUpperRightVertex()) - (ar.GetUpperLeftVertex()),
		 (ar.GetLowerRightVertex()) - (ar.GetUpperRightVertex()),
		 (br.GetUpperLeftVertex()) - (br.GetLowerLeftVertex()),
		 (br.GetUpperLeftVertex()) - (br.GetUpperRightVertex())
	};

	for (unsigned int i = 0; i < 4; i++) {
		auto axis = axes[i];
		Vector2f aMinMax = GetProjectionMinMaxOnAxis(ar, axis);
		Vector2f bMinMax = GetProjectionMinMaxOnAxis(br, axis);

		if (!(bMinMax.x <= aMinMax.y && bMinMax.y >= aMinMax.x))
			return false;
	}

	return true;
}

Vector2f GetProjectionMinMaxOnAxis(Rect2D rect, Vector2f axis) {
	float aURScalar = GetProjectionScalarOnAxis(rect.GetUpperRightVertex(), axis);
	float aULScalar = GetProjectionScalarOnAxis(rect.GetUpperLeftVertex(), axis);
	float aLRScalar = GetProjectionScalarOnAxis(rect.GetLowerRightVertex(), axis);
	float aLLScalar = GetProjectionScalarOnAxis(rect.GetLowerLeftVertex(), axis);

	vector<float> values = { aURScalar, aULScalar, aLRScalar, aLLScalar };
	return Vector2f(Math::Min(values), Math::Max(values));
}

float GetProjectionScalarOnAxis(Vector2f vertex, Vector2f axis) {
	Vector2f projection = Vector2f::Project(vertex, axis);
	float scalar = Vector2f::Dot(projection, axis);
	return scalar;
}