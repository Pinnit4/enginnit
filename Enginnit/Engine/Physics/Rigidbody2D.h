#ifndef ENGINNIT_RIGIDBODY2D
#define ENGINNIT_RIGIDBODY2D

#include "../Math/Spatial2D.h"

class Rigidbody2D : virtual public Spatial2D {
public:
	Rigidbody2D();
	Rigidbody2D(Vector2 position);
	Rigidbody2D(Vector2 position, float rotation);

	bool useGravity;

	void PhysicsTick(float deltaTime);
private:
	Vector2 velocity;
};

#endif
