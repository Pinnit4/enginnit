#include "TextureManager.h"

map<string, Texture> TextureManager::textureCache = {};

Texture TextureManager::GetTexture(string path) {
	if (!textureCache.count(path)) {
		Texture tx = Texture(path);
		textureCache.insert({ path,tx });
		return tx;
	}

	return Texture(textureCache[path]);
}