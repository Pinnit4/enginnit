#ifndef COLLIDER2DHEADER
#define COLLIDER2DHEADER

#include "../Math/Math.h"
#include "../Graphics/Graphics.h"

class Collider2D : virtual public Spatial2D {
public:
	Collider2D();
	Collider2D(Vector2f position);
	Collider2D(Vector2f position, float rotation);

	bool enabled;

	Rect2D* GetRect();
	void DebugRender();

	static bool AreColliding(const Collider2D& a, const Collider2D& b);

	virtual void Destroy();
protected:
	Rect2D* rect;

	Color debugColor;
};

#endif
