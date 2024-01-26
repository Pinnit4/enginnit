#include "NodeLoader.h"

#include "../Assets/Factories/AssetFactory.h"
#include "../Assets/Factories/AssetLoaderFactory.h"
#include "../Assets/AssetFile.h"

#include "../Debug/DebugConsole.h"

NodeLoader::NodeLoader() : AssetLoader() {
	obj = NULL;
	childObjectData = {};
	savingChildObject = false;
	childIndent = 0;
	childObjectType = "";
	childFilePath = "";
}

vector<vector<string>> NodeLoader::SaveToFileInternal(vector<vector<string>> currentValues) { return AssetLoader::SaveToFileInternal(currentValues); }

bool NodeLoader::ProcessLineInternal(string id, vector<string> values)
{
	if (!AssetLoader::ProcessLineInternal(id, values))
		return false;

	if (savingChildObject) {
		ProcessChildObjectLine(id, values);
		return false;
	}

	if (id == "start_child")
		StartChildObjectLoad(values[0]);
	else
		return true;

	return false;
}

void NodeLoader::StartChildObjectLoad(string type) {
	childObjectData.clear();
	savingChildObject = true;
	childIndent = 0;
	childObjectType = type;
	childFilePath = "";
}

void NodeLoader::ProcessChildObjectLine(string id, vector<string> values) {
	if (id == "start_child")
		childIndent++;
	else if (id == "end_child") {
		if (childIndent == 0) {
			FinishChildObjectLoad();
			return;
		}

		childIndent--;
	}
	else if (id == "file")
		childFilePath = values[0];

	map<string, vector<string>> line = map<string, vector<string>>();
	line.insert({ id,values });
	childObjectData.push_back(line);
}

void NodeLoader::FinishChildObjectLoad() {
	savingChildObject = false;

	Node* child = (Node*)AssetFactory::CreateAsset(childObjectType, childFilePath);

	if (child != NULL) {
		AssetLoader* childLoader = AssetLoaderFactory::GetAssetLoader(childObjectType);

		childLoader->LoadExtraLines(child, childObjectData);
		child->inParentVariables = childObjectData;

		child->SetParent(obj);
	}
}

string NodeLoader::GetType() { return "Node"; }

void NodeLoader::OnLoadStart() {
	AssetLoader::OnLoadStart();
	obj = (Node*)asset;
}
void NodeLoader::OnLoadFinish() {
	obj = NULL;
	AssetLoader::OnLoadFinish();
}

void NodeLoader::OnSaveStart() {
	AssetLoader::OnSaveStart();
	obj = (Node*)asset;
}
void NodeLoader::OnSaveFinish() {
	obj = NULL;
	AssetLoader::OnSaveFinish();
}