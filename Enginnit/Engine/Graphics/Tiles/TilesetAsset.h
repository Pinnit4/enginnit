#ifndef TILESET_ASSET
#define TILESET_ASSET

#include "Tileset.h"

#include <string>
#include <map>
#include <vector>

using namespace std;

class TilesetAsset {
public:
	static void SaveToFile(Tileset* ts, string filePath);
	static void LoadFromFile(Tileset* ts, string filePath);
private:

};
#endif