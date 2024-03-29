#include "TiledMap.h"

#include "../Debug/DebugConsole.h"
#include "TiledMapLoader.h"

TiledMap::TiledMap() {
	tileset = new Tileset();

	spriteGrid.clear();
	spriteGridIds.clear();

	colliderGrid.clear();
	colliderGridIds.clear();
}

TiledMap::TiledMap(string filePath) {
	tileset = new Tileset();

	spriteGrid.clear();
	spriteGridIds.clear();

	colliderGrid.clear();
	colliderGridIds.clear();

	TiledMapLoader loader = TiledMapLoader();
	loader.LoadFromFile(this, filePath);
}

void TiledMap::StartInternal() {
	DrawMap();
}

void TiledMap::DrawMap() {
	DeleteSpriteGrid();
	DeleteColliderGrid();

	DrawSpriteGrid();
	DrawColliderGrid();
}

void TiledMap::DrawSpriteGrid() {
	Vector2f currentPos = position;
	float tileWidth = tileset->GetWidth();
	float tileHeight = -tileset->GetHeight();

	for (unsigned int y = 0; y < spriteGridIds.size(); y++) {
		vector<char> lineIds = spriteGridIds[y];
		vector<TiledMapSprite*> spriteLine = vector<TiledMapSprite*>();

		for (unsigned int x = 0; x < lineIds.size(); x++) {
			char id = lineIds[x];
			Texture tx = tileset->GetTexture(id);
			TiledMapSprite* sp = new TiledMapSprite(tx, id, x, y);
			sp->spatial->position = currentPos;
			spriteLine.push_back(sp);
			currentPos.x += tileWidth;
		}

		spriteGrid.push_back(spriteLine);
		currentPos.y += tileHeight;
		currentPos.x = position.x;
	}
}

void TiledMap::DrawColliderGrid() {
	Vector2f currentPos = position;
	float tileWidth = tileset->GetWidth();
	float tileHeight = -tileset->GetHeight();

	for (unsigned int y = 0; y < colliderGridIds.size(); y++) {
		vector<char> lineIds = colliderGridIds[y];
		vector<TiledMapCollider*> colliderLine = vector<TiledMapCollider*>();

		for (unsigned int x = 0; x < lineIds.size(); x++) {
			char id = lineIds[x];
			TiledMapCollider* sp = new TiledMapCollider(id, x, y, tileWidth, tileHeight);
			sp->spatial->position = currentPos;
			if (id == 'X')
				sp->Enable();
			else
				sp->Disable();
			colliderLine.push_back(sp);
			currentPos.x += tileWidth;
		}

		colliderGrid.push_back(colliderLine);
		currentPos.y += tileHeight;
		currentPos.x = position.x;
	}
}

void TiledMap::DeleteSpriteGrid() {
	for (unsigned int i = 0; i < spriteGrid.size(); i++) {
		vector<TiledMapSprite*> spriteLine = spriteGrid[i];
		for (unsigned int j = 0; j < spriteLine.size(); j++) {
			spriteLine[j]->Destroy();
		}
	}

	spriteGrid.clear();
}

void TiledMap::DeleteColliderGrid() {
	for (unsigned int i = 0; i < colliderGrid.size(); i++) {
		vector<TiledMapCollider*> colliderLine = colliderGrid[i];
		for (unsigned int j = 0; j < colliderLine.size(); j++) {
			colliderLine[j]->Destroy();
		}
	}

	colliderGrid.clear();
}

TiledMapSprite* TiledMap::GetSprite(int x, int y) {
	if (x >= GetWidth() || y >= GetHeight()) {
		Vector2i pos = Vector2i(x, y);
		Vector2i size = Vector2i(GetWidth(), GetHeight());
		DebugConsole::LogError("ERROR: Couldn't find position " + pos.ToString() + ", map size is " + size.ToString());
		return NULL;
	}
	return spriteGrid[y][x];
}

Vector2f TiledMap::GetWorldPosition(int x, int y) {
	auto sprite = GetSprite(x, y);
	if (sprite == NULL)return Vector2f(0);

	DebugConsole::Log("sprite grid pos: " + sprite->spatial->position.ToString());
	return (sprite->spatial->position);
}

int TiledMap::GetWidth() {
	return spriteGrid[0].size();
}

int TiledMap::GetHeight() {
	return spriteGrid.size();
}