#include "SceneObjectLoader.h"

#include "../../Assets/Factories/AssetFactory.h"
#include "../../Assets/Factories/AssetLoaderFactory.h"
#include "../../Assets/AssetFile.h"

#include "../../Debug/DebugConsole.h"

SceneObjectLoader::SceneObjectLoader() : AssetLoader() {
	obj = NULL;
	childObjectData = {};
	savingChildObject = false;
	childIndent = 0;
	childObjectType = "";
	childFilePath = "";
}

vector<vector<string>> SceneObjectLoader::SaveToFileInternal(vector<vector<string>> currentValues) { return AssetLoader::SaveToFileInternal(currentValues); }

bool SceneObjectLoader::ProcessLineInternal(string id, vector<string> values)
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

void SceneObjectLoader::StartChildObjectLoad(string type) {
	childObjectData.clear();
	savingChildObject = true;
	childIndent = 0;
	childObjectType = type;
	childFilePath = "";
}

void SceneObjectLoader::ProcessChildObjectLine(string id, vector<string> values) {
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

void SceneObjectLoader::FinishChildObjectLoad() {
	savingChildObject = false;

	SceneObject* child = (SceneObject*)AssetFactory::CreateAsset(childObjectType, childFilePath);

	if (child != NULL) {
		AssetLoader* childLoader = AssetLoaderFactory::GetAssetLoader(childObjectType);

		childLoader->LoadExtraLines(child, childObjectData);
		child->inParentVariables = childObjectData;

		child->SetParent(obj);
	}
}

string SceneObjectLoader::GetType() { return "SceneObject"; }

void SceneObjectLoader::OnLoadStart() {
	AssetLoader::OnLoadStart();
	obj = (SceneObject*)asset;
}
void SceneObjectLoader::OnLoadFinish() {
	obj = NULL;
	AssetLoader::OnLoadFinish();
}

void SceneObjectLoader::OnSaveStart() {
	AssetLoader::OnSaveStart();
	obj = (SceneObject*)asset;
}
void SceneObjectLoader::OnSaveFinish() {
	obj = NULL;
	AssetLoader::OnSaveFinish();
}