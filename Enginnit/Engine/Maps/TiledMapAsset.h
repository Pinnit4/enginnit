#ifndef TILED_MAP_ASSET
#define TILED_MAP_ASSET

#include "TiledMap.h"
#include "../IO/AssetFile.h"
#include "../Graphics/Tiles/TilesetAsset.h"

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

		for (unsigned int i = 0; i < tm->spriteGridIds.size(); i++) {
			vector<char> tileLine = tm->spriteGridIds[i];

			string st = "";
			for (unsigned int j = 0; j < tileLine.size(); j++)
				st += tileLine[j];

			v.push_back({ "tile_line", st });
		}

		for (unsigned int i = 0; i < tm->colliderGridIds.size(); i++) {
			vector<char> collLine = tm->colliderGridIds[i];

			string st = "";
			for (unsigned int j = 0; j < collLine.size(); j++)
				st += collLine[j];

			v.push_back({ "coll_line", st });
		}

		AssetFile::WriteAssetFile(filePath, v);
	}

	static void LoadFromFile(TiledMap* _tm, string filePath) {
		tm = _tm;

		AssetFile::ReadAssetFile(filePath, [&](string id, vector<string> values) {
			ProcessLine(id, values);
			});

		tm = NULL;
	}

	static void LoadExtraLines(TiledMap* _tm, vector<map<string, vector<string>>> lines) {
		tm = _tm;

		for (auto line : lines) {
			for (auto kvp : line)
				ProcessLine(kvp.first, kvp.second);
		}

		tm = NULL;
	}

private:
	static TiledMap* tm;

	static void ProcessLine(string id, vector<string> values) {
		if (id == "type") {} // Do nothing
		else if (id == "tileset")
			TilesetAsset::LoadFromFile(tm->tileset, values[0]);
		else if (id == "tile_line") {
			vector<char> tileLine = vector<char>();

			for (unsigned int i = 0; i < values[0].size(); i++)
				tileLine.push_back(values[0].at(i));

			tm->spriteGridIds.push_back(tileLine);
		}
		else if (id == "coll_line") {
			vector<char> tileLine = vector<char>();

			for (unsigned int i = 0; i < values[0].size(); i++)
				tileLine.push_back(values[0].at(i));

			tm->colliderGridIds.push_back(tileLine);
		}
		else if (id == "position")
			tm->position = Vector2f(stof(values[0]), stof(values[1]));
	}
};
#endif