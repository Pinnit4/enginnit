#ifndef ENGINNIT_SCENE
#define ENGINNIT_SCENE

#include <string>
#include "SceneObject.h"

using namespace std;

class Scene {
public:
	Scene();
	Scene(string filePath);

	vector<SceneObject*> objects;

	void Start();
	void Tick(double deltaTime);
private:
};
#endif#pragma once
