#ifndef ENGINNIT_COLLIDER2D
#define ENGINNIT_COLLIDER2D

#include "../Math/Math.h"
#include "../Graphics/Graphics.h"

class Collider2D {
public:
	Collider2D();
	Collider2D(Vector2f position);
	Collider2D(Vector2f position, float rotation);
	Collider2D(Spatial2D* spatial);

	bool isTrigger;
	Spatial2D* spatial;

	Rect2D* GetRect();
	void DebugRender();

	static bool AreColliding(const Collider2D& a, const Collider2D& b);

	void Enable();
	void Disable();

	virtual void Destroy();
protected:
	Rect2D* rect;

	bool enabled;
	Color debugColor;

	virtual void EnableInternal();
	virtual void DisableInternal();
};

#endif
