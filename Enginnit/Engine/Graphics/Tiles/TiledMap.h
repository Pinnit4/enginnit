#ifndef ENGINNIT_TILED_MAP
#define ENGINNIT_TILED_MAP

#include "Tileset.h"
#include "TiledMapSprite.h"

#include "../Texture.h"

#include <map>
#include <vector>

using namespace std;

class TiledMap {
public:
	TiledMap();
	TiledMap(string filePath);

	Tileset* tileset;

	vector<vector<char>> tileGrid;
	vector<vector<TiledMapSprite*>> spriteGrid;

	void DrawSpriteGrid(Vector2 position);
	TiledMapSprite* GetSprite(int x, int y);

	Vector2 GetWorldPosition(int x, int y);

	int GetWidth();
	int GetHeight();
private:
};
#endif#pragma once
