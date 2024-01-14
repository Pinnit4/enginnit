#include "Rigidbody2D.h"

#include "Physics2D.h"

Rigidbody2D::Rigidbody2D() : Collider2D() {
	velocity = Vector2f::Zero();
	Physics2D::RegisterRigidbody(this);
	previousPos = position;
	useGravity = true;
	debugColor = Color(0.5, 0.5, 1);
}
Rigidbody2D::Rigidbody2D(Vector2f position) : Collider2D(position) {
	velocity = Vector2f::Zero();
	Physics2D::RegisterRigidbody(this);
	previousPos = position;
	useGravity = true;
	debugColor = Color(0.5, 0.5, 1);
}
Rigidbody2D::Rigidbody2D(Vector2f position, float rotation) : Collider2D(position, rotation) {
	velocity = Vector2f::Zero();
	Physics2D::RegisterRigidbody(this);
	previousPos = position;
	useGravity = true;
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

void Rigidbody2D::PhysicsTick(double deltaTime) {
	previousPos = position;

	if (useGravity) {
		velocity += Vector2f::Down() * 9.81f * 30 * deltaTime;
		position += velocity * 30 * deltaTime;
	}

	rect->RefreshRotation(rotation);
}

void Rigidbody2D::ProcessCollision(Collider2D* other) {
	// Custom stepped method: first trying rollback on each axis separately, then both of them if unsuccesful
	Vector2f auxPos = position;

	bool success = CollisionSteppedRollback(other, true, false);
	if (success) return;

	position = auxPos;
	success = CollisionSteppedRollback(other, false, true);
	if (success) return;

	position = auxPos;
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

bool Rigidbody2D::CollisionSteppedRollback(Collider2D* other, bool useX, bool useY) {
	Vector2f direction = (previousPos - position);

	if (!useX) direction.x = 0; // Don't rollback on X axis
	if (!useY) direction.y = 0;	// Don't rollback on Y axis

	double steps = 5;
	double stepDecrease = 1 / steps;

	for (int i = 0; i < steps; i++) {
		position += (direction * stepDecrease);

		if (!Collider2D::AreColliding(*this, *other))
			return true;
	}

	return false;
}