#include "Rigidbody2D.h"
#include "Physics2D.h"

Rigidbody2D::Rigidbody2D() : Spatial2D() {
	velocity = Vector2::Zero();
	Physics2D::RegisterRigidbody(this);

}
Rigidbody2D::Rigidbody2D(Vector2 position) : Spatial2D(position) {
	velocity = Vector2::Zero();
	Physics2D::RegisterRigidbody(this);

}
Rigidbody2D::Rigidbody2D(Vector2 position, float rotation) : Spatial2D(position, rotation) {
	velocity = Vector2::Zero();
	Physics2D::RegisterRigidbody(this);
}

void Rigidbody2D::PhysicsTick(float deltaTime) {
	if (useGravity) {
		velocity += Vector2::Down() * 9.81f * 30 * deltaTime;
		position += velocity * 30 * deltaTime;
	}
}