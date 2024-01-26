#ifndef ENGINNIT_SCENE_LOADER
#define ENGINNIT_SCENE_LOADER

#include "Scene.h"
#include "Objects/SceneObjectLoader.h"

class SceneLoader : public SceneObjectLoader {
public:
	SceneLoader() : SceneObjectLoader() { }
protected:
	string GetType() override { return "Scene"; }
};
#endif