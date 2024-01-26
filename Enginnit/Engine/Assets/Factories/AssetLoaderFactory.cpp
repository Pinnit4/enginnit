#include "AssetLoaderFactory.h"

#include "../../Scenes/Objects/SceneObjectLoader.h"
#include "../../Scenes/SceneLoader.h"
#include "../../Player/CharacterController2DLoader.h"
#include "../../Maps/TiledMapLoader.h"

AssetLoader* AssetLoaderFactory::GetAssetLoader(string type) {

	if (type == "Scene") return new SceneLoader();
	if (type == "CharacterController2D") return new CharacterController2DLoader();
	if (type == "TiledMap") return new TiledMapLoader();
	if (type == "SceneObject") return new SceneObjectLoader();

	return new AssetLoader();
}