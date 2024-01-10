#include "SceneAsset.h"

vector<map<string, vector<string>>> SceneAsset::nestedObjectData = vector<map<string, vector<string>>>();

bool SceneAsset::savingNestedObject = false;
int SceneAsset::nestingIndent = 0;
string SceneAsset::nestedObjectType = "";
string SceneAsset::filePath = "";

Scene* SceneAsset::currentScene = NULL;