#ifndef ENGINNIT_SCENE_LOADER
#define ENGINNIT_SCENE_LOADER

#include "Scene.h"
#include "../Nodes/NodeLoader.h"

class SceneLoader : public NodeLoader {
public:
	SceneLoader() : NodeLoader() { }
protected:
	string GetType() override { return "Scene"; }
};
#endif