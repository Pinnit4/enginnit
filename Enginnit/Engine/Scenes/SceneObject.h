#ifndef ENGINNIT_SCENEOBJECT
#define ENGINNIT_SCENEOBJECT

#include <string>
#include <map>
#include <vector>

using namespace std;

class SceneObject {
public:
	SceneObject();

	vector<map<string, vector<string>>> sceneVariables;

	virtual void Start();
	virtual void Tick(double deltaTime);
};

#endif