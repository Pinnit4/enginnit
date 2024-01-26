#include "AssetFactory.h"

#include "../../Player/CharacterController2D.h"
#include "../../Maps/TiledMap.h"

Asset* AssetFactory::CreateAsset(string type, string filePath) {
	if (type == "CharacterController2D") {
		if (filePath != "")
			return new CharacterController2D(filePath);
		else
			return new CharacterController2D();
	}

	if (type == "TiledMap") {
		if (filePath != "")
			return new TiledMap(filePath);
		else
			return new TiledMap();
	}

	return NULL;
}