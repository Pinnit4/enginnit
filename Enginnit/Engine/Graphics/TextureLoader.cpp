#include "TextureLoader.h"

map<string, Texture> TextureLoader::textureCache = {};

Texture TextureLoader::LoadTexture(string path) {
	if (!textureCache.count(path)) {
		Texture tx = Texture(path);
		textureCache.insert({ path,tx });
		return tx;
	}

	return Texture(textureCache[path]);
}