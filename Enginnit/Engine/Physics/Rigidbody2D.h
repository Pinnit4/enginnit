#ifndef ENGINNIT_RIGIDBODY2D
#define ENGINNIT_RIGIDBODY2D

#include "Collider2D.h"

#include "../Graphics/Color.h"
#include "../Math/Rect2D.h"

class Rigidbody2D : virtual public Collider2D {
public:
	Rigidbody2D();
	Rigidbody2D(Vector2f position);
	Rigidbody2D(Vector2f position, float rotation);

	bool useGravity;

	virtual void PhysicsTick(double deltaTime);
	void ProcessCollision(Collider2D* other);

	void DebugRender(Color color);

	void Destroy() override;
protected:
	Vector2f velocity;
	Vector2f previousPos;

	bool CollisionSteppedRollback(Collider2D* other, bool useX, bool useY);
};

#endif
