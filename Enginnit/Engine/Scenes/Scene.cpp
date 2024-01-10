#include "Scene.h"
#include "SceneAsset.h"

Scene::Scene() {
	objects.clear();
}

Scene::Scene(string filePath) {
	objects.clear();
	SceneAsset::LoadFromFile(this, filePath);
}

void Scene::Start() {
	for (auto obj : objects)
		obj->Start();
}

void Scene::Tick(double deltaTime) {
	for (auto obj : objects)
		obj->Tick(deltaTime);
}