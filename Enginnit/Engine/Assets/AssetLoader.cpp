#include "AssetLoader.h"

#include "../Debug/DebugConsole.h"

AssetLoader::AssetLoader() {
	asset = NULL;
}

void AssetLoader::LoadFromFile(Asset* _asset, string filePath) {
	asset = _asset;
	OnLoadStart();

	AssetFile::ReadAssetFile(filePath, [&](string id, vector<string> values) { ProcessLine(id, values); });

	OnLoadFinish();
	asset = NULL;
}

void AssetLoader::SaveToFile(Asset* _asset, string filePath) {
	asset = _asset;
	OnSaveStart();

	vector<vector<string>> v = { { "type", GetType() }, };
	v = SaveToFileInternal(v);
	AssetFile::WriteAssetFile(filePath, v);

	OnSaveFinish();
	asset = NULL;
}

vector<vector<string>> AssetLoader::SaveToFileInternal(vector<vector<string>> currentValues) { return currentValues; }

void AssetLoader::LoadExtraLines(Asset* _asset, vector<map<string, vector<string>>> lines) {
	asset = _asset;
	OnLoadStart();

	for (auto line : lines) {
		for (auto kvp : line) ProcessLine(kvp.first, kvp.second);
	}

	OnLoadFinish();
	asset = NULL;
}

void AssetLoader::ProcessLine(string id, vector<string> values) {
	if (id == "type") {} // Do nothing
	else
		ProcessLineInternal(id, values);
}

bool AssetLoader::ProcessLineInternal(string id, vector<string> values) { return true; }

string AssetLoader::GetType() { return "Asset"; }

void AssetLoader::OnLoadStart() {}
void AssetLoader::OnLoadFinish() {}

void AssetLoader::OnSaveStart() {}
void AssetLoader::OnSaveFinish() {}