#ifndef ENGINNIT_TEXTURE_LOADER
#define ENGINNIT_TEXTURE_LOADER

#include <string>
#include <map>
#include <vector>
#include "Texture.h"

class TextureLoader {
public:
	static Texture LoadTexture(string path);
private:
	static map<string, Texture> textureCache;
};

#endif