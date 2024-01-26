#ifndef ENGINNIT_SCENEOBJECT
#define ENGINNIT_SCENEOBJECT

#include "../../Assets/Asset.h"

#include <string>
#include <list>
#include <map>
#include <vector>

using namespace std;

class SceneObject : public Asset {
public:
	SceneObject();

	vector<map<string, vector<string>>> inParentVariables;

	void Start();
	void Tick(double deltaTime);

	void SetParent(SceneObject* parent);
protected:
	SceneObject* parent;
	list<SceneObject*> children;

	virtual void StartInternal();

	virtual void TickInternal(double deltaTime);

	void AddChild(SceneObject* child);
	void RemoveChild(SceneObject* child);
};

#endif