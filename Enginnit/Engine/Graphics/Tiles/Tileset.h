#ifndef ENGINNIT_TILESET
#define ENGINNIT_TILESET

#include "../Textures/Texture.h"

#include <map>

using namespace std;

class Tileset {
public:
	Tileset();

	int tileHeight;
	int tileWidth;

	string path;

	map<char, Texture> tiles;

	int GetHeight();
	int GetWidth();

	Texture GetTexture(char id);
	char GetTileID(Texture tx);

private:

};
#endif