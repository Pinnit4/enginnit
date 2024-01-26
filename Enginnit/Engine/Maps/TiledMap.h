#ifndef ENGINNIT_TILED_MAP
#define ENGINNIT_TILED_MAP

#include "../Graphics/Tiles/Tileset.h"
#include "../Graphics/Textures/Texture.h"
#include "../Nodes/Node.h"

#include "TiledMapSprite.h"
#include "TiledMapCollider.h"

#include <map>
#include <vector>

using namespace std;

class TiledMap : public Node {
public:
	TiledMap();
	TiledMap(string filePath);

	Tileset* tileset;
	Vector2f position;

	vector<vector<char>> spriteGridIds;
	vector<vector<TiledMapSprite*>> spriteGrid;

	vector<vector<char>> colliderGridIds;
	vector<vector<TiledMapCollider*>> colliderGrid;

	void DrawMap();
	TiledMapSprite* GetSprite(int x, int y);

	Vector2f GetWorldPosition(int x, int y);

	int GetWidth();
	int GetHeight();
protected:
	void StartInternal() override;

	void DrawSpriteGrid();
	void DeleteSpriteGrid();

	void DrawColliderGrid();
	void DeleteColliderGrid();
};
#endif#pragma once
