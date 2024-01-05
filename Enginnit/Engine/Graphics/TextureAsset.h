#ifndef TEXTURE_ASSET
#define TEXTURE_ASSET

#include <string>
#include <vector>

#include "Texture.h"

using namespace std;

class TextureAsset {
public:
	static vector<string> SaveAsLine(Texture tx, string lineId);
	static Texture LoadFromLine(vector<string> values);
};
#endif
