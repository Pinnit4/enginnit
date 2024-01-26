#ifndef ENGINNIT_NODE_LOADER
#define ENGINNIT_NODE_LOADER

#include "Node.h"
#include "../Assets/AssetLoader.h"

#include <string>
#include <vector>
#include <list>
#include <map>

using namespace std;

class NodeLoader : public AssetLoader {
public:
	NodeLoader();
protected:
	Node* obj;

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