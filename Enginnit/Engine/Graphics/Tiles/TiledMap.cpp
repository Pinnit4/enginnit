#include "TiledMap.h"
#include "TiledMapAsset.h"

TiledMap::TiledMap() {
	tileset = new Tileset();
	spriteGrid.clear();
	tileGrid.clear();
}

TiledMap::TiledMap(string filePath) {
	tileset = new Tileset();
	spriteGrid.clear();
	tileGrid.clear();
	TiledMapAsset::LoadFromFile(this, filePath);
}

void TiledMap::DrawSpriteGrid(Vector2f position) {
	for (unsigned int i = 0; i < spriteGrid.size(); i++) {
		vector<TiledMapSprite*> spriteLine = vector<TiledMapSprite*>();
		for (unsigned int j = 0; j < spriteLine.size(); j++) {
			spriteLine[j]->Destroy();
		}
	}

	spriteGrid.clear();

	Vector2f currentPos = position;
	float deltaX = tileset->GetWidth();
	float deltaY = -tileset->GetHeight();

	for (unsigned int y = 0; y < tileGrid.size(); y++) {
		vector<char> tileLine = tileGrid[y];
		vector<TiledMapSprite*> spriteLine = vector<TiledMapSprite*>();

		for (unsigned int x = 0; x < tileLine.size(); x++) {
			char id = tileLine[x];
			Texture tx = tileset->GetTexture(id);
			TiledMapSprite* sp = new TiledMapSprite(tx, id, x, y);
			sp->position = currentPos;
			spriteLine.push_back(sp);
			currentPos.x += deltaX;
		}

		spriteGrid.push_back(spriteLine);
		currentPos.y += deltaY;
		currentPos.x = position.x;
	}
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