#ifndef TEXTURE_ASSET
#define TEXTURE_ASSET

#include <string>
#include <vector>

#include "Texture.h"
#include "TextureLoader.h"

using namespace std;

class TextureAsset {
public:
	// min & max Ys are inverted (from bottom to top internally, from top to bottom for the user)
	// so we invert them here
	static vector<string> SaveAsLine(Texture tx, string lineId) {
		int h = tx.GetHeight() - 1;
		return {
			lineId,
			tx.GetPath(),
			tx.GetName(),
			to_string(tx.GetAnchorMin().x),
			to_string(h - tx.GetAnchorMax().y),
			to_string(tx.GetAnchorMax().x),
			to_string(h - tx.GetAnchorMin().y),
		};
	}

	static Texture LoadFromLine(vector<string> values) {
		Texture tx = TextureLoader::LoadTexture(values[0]);
		if (values.size() < 2) return tx;

		tx.SetName(values[1]);
		if (values.size() < 6) return tx;

		int h = tx.GetHeight() - 1;
		Vector2i anchorMin = Vector2i(stoi(values[2]), h - stoi(values[5]));
		Vector2i anchorMax = Vector2i(stoi(values[4]), h - stoi(values[3]));
		tx.SetAnchors(anchorMin, anchorMax);

		return tx;
	}
};
#endif
