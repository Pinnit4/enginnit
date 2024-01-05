#ifndef SPRITE_ANIMATION_ASSET
#define SPRITE_ANIMATION_ASSET

#include "SpriteAnimation.h"
#include "../IO/AssetFile.h"
#include "../Graphics/Tiles/TilesetAsset.h"

#include <string>
#include <map>
#include <vector>

using namespace std;

class SpriteAnimationAsset {
public:
	static void SaveToFile(SpriteAnimation* sa, string filePath) {
		vector<vector<string>> v = {
			{"type", "SpriteAnimation"},
			{"fps", to_string(sa->fps)},
			{"tileset", sa->tileset->path}
		};

		string st = "";
		for (unsigned int i = 0; i < sa->frameIds.size(); i++)
			st += sa->frameIds[i];

		v.push_back({ "sequence", st });

		AssetFile::WriteAssetFile(filePath, v);
	}

	static void LoadFromFile(SpriteAnimation* sa, string filePath) {
		AssetFile::ReadAssetFile(filePath, [&](string id, vector<string> values) {
			if (id == "type") {} // Do nothing
			else if (id == "tileset")
				TilesetAsset::LoadFromFile(sa->tileset, values[0]);
			else if (id == "fps")
				sa->fps = stod(values[0]);
			else if (id == "sequence") {
				sa->frameIds.clear();
				sa->frames.clear();

				for (unsigned int i = 0; i < values[0].size(); i++) {
					char id = values[0].at(i);
					sa->frameIds.push_back(id);
					sa->frames.push_back(sa->tileset->GetTexture(id));
				}
			}
			});
		sa->path = filePath;
	}
};
#endif