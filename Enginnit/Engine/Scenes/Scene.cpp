#include "Scene.h"
#include "SceneLoader.h"

Scene::Scene() : Node() {
}

Scene::Scene(string filePath) : Node() {
	SceneLoader loader = SceneLoader();
	loader.LoadFromFile(this, filePath);
}