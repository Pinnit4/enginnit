#include "Tileset.h"

Tileset::Tileset() {
	tileWidth = 0;
	tileHeight = 0;

	tiles.clear();
}

int Tileset::GetWidth() { return tileWidth; }
int Tileset::GetHeight() { return tileHeight; }

Texture Tileset::GetTexture(char id) { return tiles[id]; }
char Tileset::GetTileID(Texture tx) {
	//map <char, Texture> ::iterator i;
	for (map <char, Texture> ::iterator i = tiles.begin(); i != tiles.end(); i++)
	{
		if (((*i).second).GetPath() == tx.GetPath())
			return (*i).first;
	}
	return '0';
}
