#ifndef ENGINNIT_ASSET_LOADER
#define ENGINNIT_ASSET_LOADER

#include "Asset.h"
#include "AssetFile.h"

#include <string>
#include <vector>
#include <list>
#include <map>

using namespace std;

class AssetLoader {
public:
	AssetLoader();

	void LoadFromFile(Asset* asset, string filePath);
	void SaveToFile(Asset* asset, string filePath);

	void LoadExtraLines(Asset* asset, vector<map<string, vector<string>>> lines);

protected:
	Asset* asset;

	virtual void OnLoadStart();
	virtual void OnLoadFinish();

	virtual void OnSaveStart();
	virtual void OnSaveFinish();

	virtual vector<vector<string>> SaveToFileInternal(vector<vector<string>> currentValues);
	virtual string GetType();

	void ProcessLine(string id, vector<string> values);
	virtual bool ProcessLineInternal(string id, vector<string> values);
};
#endif