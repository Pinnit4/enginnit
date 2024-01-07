#ifndef ENGINNIT_RIGIDBODY2D
#define ENGINNIT_RIGIDBODY2D

#include "Collider2D.h"

#include "../Graphics/Color.h"
#include "../Math/Rect2D.h"

class Rigidbody2D : virtual public Collider2D {
public:
	Rigidbody2D();
	Rigidbody2D(Vector2 position);
	Rigidbody2D(Vector2 position, float rotation);

	bool useGravity;

	void PhysicsTick(float deltaTime);
	void DebugRender(Color color);
protected:
	Vector2 velocity;
};

#endif
