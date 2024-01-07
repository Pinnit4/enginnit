#ifndef COLLIDER2DHEADER
#define COLLIDER2DHEADER

#include "../Math/Vector2.h"
#include "../Math/Spatial2D.h"
#include "../Math/Rect2D.h"

class Collider2D : virtual public Spatial2D {
public:
	Collider2D();
	Collider2D(Vector2 position);
	Collider2D(Vector2 position, float rotation);

	Rect2D GetRect();
	void DebugRender(Color color);
protected:
	Rect2D rect;
};

#endif
