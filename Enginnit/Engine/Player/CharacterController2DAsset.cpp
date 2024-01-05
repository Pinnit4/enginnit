#include "CharacterController2DAsset.h"
#include "../IO/AssetFile.h"

#include <string>
#include <vector>
#include "../Graphics/TextureAsset.h"

using namespace std;

void CharacterController2DAsset::SaveToFile(CharacterController2D* cc, string filePath) {
	vector<vector<string>> v = {
		{"type", "CharacterController2D"},
		{"speed", to_string(cc->movementSpeed)},
		TextureAsset::SaveAsLine(cc->upTexture, "u_tx"),
		TextureAsset::SaveAsLine(cc->downTexture, "d_tx"),
		TextureAsset::SaveAsLine(cc->leftTexture, "l_tx"),
		TextureAsset::SaveAsLine(cc->rightTexture, "r_tx"),
		{"depth", to_string(cc->depthLayer)}
	};

	AssetFile::WriteAssetFile(filePath, v);
}

void CharacterController2DAsset::LoadFromFile(CharacterController2D* cc, string filePath) {
	AssetFile::ReadAssetFile(filePath, [&](string id, vector<string> values) {
		if (id == "speed")
			cc->movementSpeed = stof(values[0]);
		else if (id == "u_tx")
			cc->upTexture = TextureAsset::LoadFromLine(values);
		else if (id == "d_tx")
			cc->downTexture = TextureAsset::LoadFromLine(values);
		else if (id == "l_tx")
			cc->leftTexture = TextureAsset::LoadFromLine(values);
		else if (id == "r_tx")
			cc->rightTexture = TextureAsset::LoadFromLine(values);
		else if (id == "depth")
			cc->depthLayer = stoi(values[0]);
		});

	cc->SetTexture(cc->downTexture);
}