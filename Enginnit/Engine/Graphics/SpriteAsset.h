#ifndef SPRITE_ASSET
#define SPRITE_ASSET

#include <string>
#include <vector>

#include "Sprite.h"
#include "../IO/AssetFile.h"
#include "TextureAsset.h"

using namespace std;

class SpriteAsset {
public:
	static void SaveToFile(Sprite* sp, string filePath) {
		vector<vector<string>> v = { {"type", "Sprite"}, };

		v.push_back(TextureAsset::SaveAsLine(sp->GetTexture(), "texture"));

		vector<string> margins = { "margins" };

		for (float i : sp->GetMargins()) 
			margins.push_back(to_string(i));

		AssetFile::WriteAssetFile(filePath, v);
	}

	static void LoadFromFile(Sprite* sp, string filePath) {
		AssetFile::ReadAssetFile(filePath, [&](string id, vector<string> values) {
			if (id == "type") {} // Do nothing
			else if (id == "texture") 
				sp->SetTexture(TextureAsset::LoadFromLine(values));
			else if (id == "margins") {
				vector<int> margins = {};
				for (auto i : values)
					margins.push_back(stoi(i));

				sp->SetMargins(margins);
			}
			});
		sp->path = filePath;
	}
};
#endif
