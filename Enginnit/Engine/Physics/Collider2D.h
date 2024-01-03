#ifndef COLLIDER2DHEADER
#define COLLIDER2DHEADER

#include "../Math/Vector2.h"
#include "../Math/Spatial2D.h"

class Collider2D : virtual public Spatial2D {
public:
	Collider2D();
	Collider2D(Vector2 position);
	Collider2D(Vector2 position, float rotation);
private:

};

#endif
