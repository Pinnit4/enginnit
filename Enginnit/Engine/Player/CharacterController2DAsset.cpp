#include "CharacterController2DAsset.h"
#include "../IO/AssetFile.h"

#include <string>
#include <vector>

using namespace std;

void CharacterController2DAsset::SaveToFile(CharacterController2D* cc, string filePath) {
	vector<vector<string>> v = {
		{"type", "CharacterController2D"},
		{"speed", to_string(cc->movementSpeed)},
		{"u_tx", cc->upTexture.GetPath()},
		{"d_tx", cc->downTexture.GetPath()},
		{"l_tx", cc->leftTexture.GetPath()},
		{"r_tx", cc->rightTexture.GetPath()},
		{"depth", to_string(cc->depthLayer)}
	};

	AssetFile::WriteAssetFile(filePath, v);
}

void CharacterController2DAsset::LoadFromFile(CharacterController2D* cc, string filePath) {
	AssetFile::ReadAssetFile(filePath, [&](string id, string value) {
		if (id == "speed")
			cc->movementSpeed = stof(value);
		else if (id == "u_tx")
			cc->upTexture = Texture(value);
		else if (id == "d_tx")
			cc->downTexture = Texture(value);
		else if (id == "l_tx")
			cc->leftTexture = Texture(value);
		else if (id == "r_tx")
			cc->rightTexture = Texture(value);
		else if (id == "depth")
			cc->depthLayer = stoi(value);
		});

	cc->SetTexture(cc->downTexture);
}