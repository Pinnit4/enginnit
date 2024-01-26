#ifndef ENGINNIT_TILED_MAP_SPRITE
#define ENGINNIT_TILED_MAP_SPRITE

#include "../Graphics/Sprites/Sprite.h"

using namespace std;

class TiledMapSprite : public Sprite {
public:
	char tileId;

	int x;
	int y;

	TiledMapSprite(Texture _texture, char _tileId, int _x, int _y) : Sprite(_texture) {
		tileId = _tileId;
		x = _x;
		y = _y;
	}
};
#endif
