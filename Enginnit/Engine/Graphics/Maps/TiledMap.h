#ifndef ENGINNIT_TILED_MAP
#define ENGINNIT_TILED_MAP

#include "../Tiles/Tileset.h"
#include "TiledMapSprite.h"
#include "TiledMapCollider.h"

#include "../Texture.h"

#include <map>
#include <vector>

using namespace std;

class TiledMap {
public:
	TiledMap();
	TiledMap(string filePath);

	Tileset* tileset;

	vector<vector<char>> spriteGridIds;
	vector<vector<TiledMapSprite*>> spriteGrid;

	vector<vector<char>> colliderGridIds;
	vector<vector<TiledMapCollider*>> colliderGrid;

	void DrawMap(Vector2f position);
	TiledMapSprite* GetSprite(int x, int y);

	Vector2f GetWorldPosition(int x, int y);

	int GetWidth();
	int GetHeight();
private:

	void DrawSpriteGrid(Vector2f position);
	void DeleteSpriteGrid();

	void DrawColliderGrid(Vector2f position);
	void DeleteColliderGrid();
};
#endif#pragma once
