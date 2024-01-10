#ifndef ENGINNIT_TILED_MAP_COLLIDER
#define ENGINNIT_TILED_MAP_COLLIDER

#include "../../Physics/Collider2D.h"

using namespace std;

class TiledMapCollider : public Collider2D {
public:
	char tileId;

	int x;
	int y;

	TiledMapCollider(char _tileId, int _x, int _y, float width, float height) : Collider2D() {
		tileId = _tileId;
		x = _x;
		y = _y;

		Vector2f size = Vector2f(width, height);
		rect->SetCenter(Vector2f(width / 2, -height / 2));
		rect->SetSize(size);
	}
};
#endif
