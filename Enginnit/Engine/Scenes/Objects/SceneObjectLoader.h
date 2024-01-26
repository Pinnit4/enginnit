#ifndef ENGINNIT_SCENEOBJECT_LOADER
#define ENGINNIT_SCENEOBJECT_LOADER

#include "SceneObject.h"
#include "../../Assets/AssetLoader.h"

#include <string>
#include <vector>
#include <list>
#include <map>

using namespace std;

class SceneObjectLoader : public AssetLoader {
public:
	SceneObjectLoader();
protected:
	SceneObject* obj;

	vector<map<string, vector<string>>> childObjectData;
	bool savingChildObject;
	int childIndent;
	string childObjectType;
	string childFilePath;

	virtual void OnLoadStart() override;
	virtual void OnLoadFinish() override;
	virtual void OnSaveStart() override;
	virtual void OnSaveFinish() override;

	virtual vector<vector<string>> SaveToFileInternal(vector<vector<string>> currentValues) override;
	virtual string GetType() override;

	virtual bool ProcessLineInternal(string id, vector<string> values) override;

	void ProcessChildObjectLine(string id, vector<string> values);

	void StartChildObjectLoad(string type);
	void FinishChildObjectLoad();

};
#endif