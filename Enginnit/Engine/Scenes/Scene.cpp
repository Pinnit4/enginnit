#include "Scene.h"
#include "SceneLoader.h"

Scene::Scene() : SceneObject() {
}

Scene::Scene(string filePath) : SceneObject() {
	SceneLoader loader = SceneLoader();
	loader.LoadFromFile(this, filePath);
}