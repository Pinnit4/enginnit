#include "TiledMapSprite.h"

#include <string>

using namespace std;

TiledMapSprite::TiledMapSprite(Texture texture, char _tileId, int _x, int _y) : Sprite(texture) {
	tileId = _tileId;
	x = _x;
	y = _y;
}