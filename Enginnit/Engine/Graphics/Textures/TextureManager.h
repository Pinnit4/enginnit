#ifndef ENGINNIT_TEXTURE_MANAGER
#define ENGINNIT_TEXTURE_MANAGER

#include <string>
#include <map>
#include <vector>
#include "Texture.h"

class TextureManager {
public:
	static Texture GetTexture(string path);
private:
	static map<string, Texture> textureCache;
};

#endif