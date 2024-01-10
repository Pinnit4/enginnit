#include "TiledMap.h"
#include "TiledMapAsset.h"

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

	TiledMapAsset::LoadFromFile(this, filePath);
}

void TiledMap::Start() {
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
			sp->position = currentPos;
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
			sp->position = currentPos;
			sp->enabled = id == 'X';
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
		cout << "ERROR: Couldn't find sprite (" << x << "," << y << "), map size is (" << GetWidth() << "," << GetHeight() << ")" << endl;
		return NULL;
	}
	return spriteGrid[y][x];
}

Vector2f TiledMap::GetWorldPosition(int x, int y) {
	if (x >= GetWidth() || y >= GetHeight()) {
		cout << "ERROR: Couldn't find grid position (" << x << "," << y << "), map size is (" << GetWidth() << "," << GetHeight() << ")" << endl;
		return Vector2f::Zero();
	}

	auto sprite = spriteGrid[y][x];
	cout << "sprite grid pos: " << sprite->position.ToString() << endl;
	return (spriteGrid[y][x]->position);
}

int TiledMap::GetWidth() {
	return spriteGrid[0].size();
}

int TiledMap::GetHeight() {
	return spriteGrid.size();
}