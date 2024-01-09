#ifndef COLLIDER2DHEADER
#define COLLIDER2DHEADER

#include "../Math/Vector2.h"
#include "../Math/Spatial2D.h"
#include "../Math/Rect2D.h"

class Collider2D : virtual public Spatial2D {
public:
	Collider2D();
	Collider2D(Vector2f position);
	Collider2D(Vector2f position, float rotation);

	Rect2D* GetRect();
	void DebugRender(Color color);

	static bool AreColliding(const Collider2D& a, const Collider2D& b);
protected:
	Rect2D* rect;
};

#endif
