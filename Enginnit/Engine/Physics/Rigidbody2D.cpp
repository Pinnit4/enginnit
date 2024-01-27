#include "Rigidbody2D.h"

#include "Physics2D.h"
#include "../Debug/DebugConsole.h"

Rigidbody2D::Rigidbody2D() : Collider2D() {
	velocity = Vector2f(0);
	Physics2D::RegisterRigidbody(this);
	previousPos = spatial->position;
	useGravity = true;
	isTrigger = false;
	debugColor = Color(0.5, 0.5, 1);
}
Rigidbody2D::Rigidbody2D(Vector2f position) : Collider2D(position) {
	velocity = Vector2f(0);
	Physics2D::RegisterRigidbody(this);
	previousPos = position;
	useGravity = true;
	isTrigger = false;
	debugColor = Color(0.5, 0.5, 1);
}
Rigidbody2D::Rigidbody2D(Vector2f position, float rotation) : Collider2D(position, rotation) {
	velocity = Vector2f(0);
	Physics2D::RegisterRigidbody(this);
	previousPos = position;
	useGravity = true;
	isTrigger = false;
	debugColor = Color(0.5, 0.5, 1);
}
Rigidbody2D::Rigidbody2D(Spatial2D* spatial) : Collider2D(spatial) {
	velocity = Vector2f(0);
	Physics2D::RegisterRigidbody(this);
	previousPos = spatial->position;
	useGravity = true;
	isTrigger = false;
	debugColor = Color(0.5, 0.5, 1);
}

void Rigidbody2D::EnableInternal() {
	Collider2D::EnableInternal();
	Physics2D::RegisterRigidbody(this);
}

void Rigidbody2D::DisableInternal() {
	Collider2D::DisableInternal();
	Physics2D::UnregisterRigidbody(this);
}

void Rigidbody2D::Preprocess(double deltaTime) {
	if (useGravity) {
		velocity += Vector2f::Down() * 9.81f * 30 * deltaTime;
		spatial->position += velocity * 30 * deltaTime;
	}

	rect->RefreshRotation(spatial->rotation);
}

void Rigidbody2D::ProcessCollision(Collider2D* other) {
	if (other->isTrigger || isTrigger) {
		// TODO - Process as trigger
		return;
	}

	// Custom stepped method: first trying rollback on each axis separately, then both of them if unsuccesful
	Vector2f auxPos = spatial->position;

	bool success = CollisionSteppedRollback(other, true, false);
	if (success) return;

	spatial->position = auxPos;
	success = CollisionSteppedRollback(other, false, true);
	if (success) return;

	spatial->position = auxPos;
	success = CollisionSteppedRollback(other, true, true);

	// Stepped method, as Mario64
	/*Vector2f direction = (position - previousPos);

	double steps = 5;

	double multiplier = 1;
	double stepDecrease = 1 / steps;

	for (int i = 0; i < steps; i++) {
		multiplier -= stepDecrease;
		Vector2f newPos = Vector2f(previousPos);
		newPos += (direction * multiplier);
		position = newPos;

		if (!Collider2D::AreColliding(*this, *other))
			return;
	}*/

	// Full force method
	//position = previousPos;
}

void Rigidbody2D::Postprocess(double deltaTime) {
	previousPos = spatial->position;
}

bool Rigidbody2D::CollisionSteppedRollback(Collider2D* other, bool useX, bool useY) {
	Vector2f direction = (previousPos - spatial->position);

	if (!useX) direction.x = 0; // Don't rollback on X axis
	if (!useY) direction.y = 0;	// Don't rollback on Y axis

	double steps = 5;
	double stepDecrease = 1 / steps;

	for (int i = 0; i < steps; i++) {
		spatial->position += (direction * stepDecrease);

		if (!Collider2D::AreColliding(*this, *other))
			return true;
	}

	return false;
}