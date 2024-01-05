#ifndef TILESET_ASSET
#define TILESET_ASSET

#include "Tileset.h"

#include "../../IO/AssetFile.h"
#include "../TextureAsset.h"

#include <string>
#include <vector>

using namespace std;

class TilesetAsset {
public:
	static void SaveToFile(Tileset* ts, string filePath) {
		vector<vector<string>> v = {
			{"type", "Tileset"},
			{"tile_width", to_string(ts->GetWidth()) },
			{"tile_height", to_string(ts->GetHeight()) }
		};

		for (auto i = ts->tiles.begin(); i != ts->tiles.end(); i++)
			v.push_back(TextureAsset::SaveAsLine((*i).second, to_string((*i).first)));

		AssetFile::WriteAssetFile(filePath, v);
	}

	static void LoadFromFile(Tileset* ts, string filePath) {
		AssetFile::ReadAssetFile(filePath, [&](string id, vector<string> values) {
			if (id == "type") {} // Do nothing
			else if (id == "tile_width") {
				ts->tileWidth = stoi(values[0]);
			}
			else if (id == "tile_height") {
				ts->tileHeight = stoi(values[0]);
			}
			else {
				ts->tiles[id.at(0)] = TextureAsset::LoadFromLine(values);
			}
			});

		ts->path = filePath;
	}
};
#endif