#ifndef ENGINNIT_TILED_MAP_SPRITE
#define ENGINNIT_TILED_MAP_SPRITE

#include "../Sprite.h"

using namespace std;

class TiledMapSprite : public Sprite {
public:
	char tileId;

	int x;
	int y;

	TiledMapSprite(Texture texture, char tileId, int x, int y);
private:

};
#endif#pragma once
