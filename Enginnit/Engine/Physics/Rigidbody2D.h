#ifndef ENGINNIT_RIGIDBODY2D
#define ENGINNIT_RIGIDBODY2D

#include "Collider2D.h"

class Rigidbody2D : virtual public Collider2D {
public:
	Rigidbody2D();
	Rigidbody2D(Vector2f position);
	Rigidbody2D(Vector2f position, float rotation);
	Rigidbody2D(Spatial2D* spatial);

	bool useGravity;

	virtual void Preprocess(double deltaTime);
	void ProcessCollision(Collider2D* other);
	virtual void Postprocess(double deltaTime);
protected:
	Vector2f velocity;
	Vector2f previousPos;

	bool CollisionSteppedRollback(Collider2D* other, bool useX, bool useY);
	
	void EnableInternal() override;
	void DisableInternal() override;
};

#endif
