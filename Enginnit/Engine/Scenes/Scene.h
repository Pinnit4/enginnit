#ifndef ENGINNIT_SCENE
#define ENGINNIT_SCENE

#include <string>
#include "Objects/SceneObject.h"

using namespace std;

class Scene : public SceneObject {
public:
	Scene();
	Scene(string filePath);
private:
};
#endif
