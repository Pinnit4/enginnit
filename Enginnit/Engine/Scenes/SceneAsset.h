#ifndef SCENE_ASSET
#define SCENE_ASSET

#include "Scene.h"
#include "../IO/AssetFile.h"
#include "../Graphics/Tiles/TilesetAsset.h"

#include <string>
#include <map>
#include <vector>
#include "../Player/CharacterController2D.h"
#include "../Player/CharacterController2DAsset.h"

#include "../Maps/Maps.h"

using namespace std;

class SceneAsset {
public:
	static void SaveToFile(Scene* tm, string filePath) {
		vector<vector<string>> v = {
			{"type", "Scene"},
		};

		AssetFile::WriteAssetFile(filePath, v);
	}

	static void LoadFromFile(Scene* tm, string filePath) {
		currentScene = tm;
		nestedObjectData = vector<map<string, vector<string>>>();
		savingNestedObject = false;

		AssetFile::ReadAssetFile(filePath, [&](string id, vector<string> values) {
			if (savingNestedObject) {
				ProcessNestedObjectLine(id, values);
				return;
			}

			if (id == "type") {} // Do nothing
			else if (id == "start_obj")
				StartNestedObjectLoad(values[0]);
			});

		currentScene = NULL;
	}

private:
	static vector<map<string, vector<string>>> nestedObjectData;
	static bool savingNestedObject;
	static int nestingIndent;
	static string nestedObjectType;
	static string filePath;
	static Scene* currentScene;

	static void ProcessNestedObjectLine(string id, vector<string> values) {
		if (id == "start_obj")
			nestingIndent++;
		else if (id == "end_obj") {
			if (nestingIndent == 0) {
				FinishNestedObjectLoad();
				return;
			}

			nestingIndent--;
		}
		else if (id == "file")
			filePath = values[0];

		map<string, vector<string>> line = map<string, vector<string>>();
		line.insert({ id,values });
		nestedObjectData.push_back(line);
	}

	static void StartNestedObjectLoad(string type) {
		savingNestedObject = true;
		nestingIndent = 0;
		nestedObjectData.clear();
		nestedObjectType = type;
		filePath = "";
	}

	static void FinishNestedObjectLoad() {
		savingNestedObject = false;

		SceneObject* obj = NULL;

		if (nestedObjectType == "CharacterController2D")
			obj = LoadAsCharacterController2D();
		else if (nestedObjectType == "TiledMap")
			obj = LoadAsTiledMap();

		if (obj != NULL) {
			currentScene->objects.push_back(obj);
		}
	}

	static SceneObject* LoadAsCharacterController2D() {
		CharacterController2D* cc;

		if (filePath != "")
			cc = new CharacterController2D(filePath);
		else
			cc = new CharacterController2D();

		CharacterController2DAsset::LoadExtraLines(cc, nestedObjectData);
		cc->sceneVariables = nestedObjectData;

		return cc;
	}

	static SceneObject* LoadAsTiledMap() {
		TiledMap* tm;

		if (filePath != "")
			tm = new TiledMap(filePath);
		else
			tm = new TiledMap();

		TiledMapAsset::LoadExtraLines(tm, nestedObjectData);
		tm->sceneVariables = nestedObjectData;

		return tm;
	}
};
#endif