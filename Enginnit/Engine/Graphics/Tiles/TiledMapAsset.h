#ifndef TILED_MAP_ASSET
#define TILED_MAP_ASSET

#include "TiledMap.h"
#include "../../IO/AssetFile.h"
#include "TilesetAsset.h"

#include <string>
#include <map>
#include <vector>

using namespace std;

class TiledMapAsset {
public:
	static void SaveToFile(TiledMap* tm, string filePath) {
		vector<vector<string>> v = {
			{"type", "TiledMap"},
			{"tileset", tm->tileset->path },
		};

		for (unsigned int i = 0; i < tm->tileGrid.size(); i++) {
			vector<char> tileLine = tm->tileGrid[i];

			string st = "";
			for (unsigned int j = 0; j < tileLine.size(); j++)
				st += tileLine[j];

			v.push_back({ "tile_line", st });
		}

		AssetFile::WriteAssetFile(filePath, v);
	}

	static void LoadFromFile(TiledMap* tm, string filePath) {
		AssetFile::ReadAssetFile(filePath, [&](string id, vector<string> values) {
			if (id == "type") {} // Do nothing
			else if (id == "tileset")
				TilesetAsset::LoadFromFile(tm->tileset, values[0]);
			else if (id == "tile_line") {
				vector<char> tileLine = vector<char>();

				for (unsigned int i = 0; i < values[0].size(); i++)
					tileLine.push_back(values[0].at(i));

				tm->tileGrid.push_back(tileLine);
			}
			});
	}
};
#endif