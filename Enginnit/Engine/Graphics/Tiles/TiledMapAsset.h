#ifndef TILED_MAP_ASSET
#define TILED_MAP_ASSET

#include "TiledMap.h"

#include <string>
#include <map>
#include <vector>

using namespace std;

class TiledMapAsset {
public:
	static void SaveToFile(TiledMap* tm, string filePath);
	static void LoadFromFile(TiledMap* tm, string filePath);
private:

};
#endif