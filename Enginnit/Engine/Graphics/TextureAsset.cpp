#include "TextureAsset.h"

using namespace std;

// min & max Ys are inverted (from bottom to top internally, from top to bottom for the user)
// so we invert them here
vector<string> TextureAsset::SaveAsLine(Texture tx, string lineId) {
	int h = tx.GetHeight() - 1;
	return {
		lineId,
		tx.GetPath(),
		to_string(tx.GetAnchorMin().x),
		to_string(h - tx.GetAnchorMax().y),
		to_string(tx.GetAnchorMax().x),
		to_string(h - tx.GetAnchorMin().y)
	};
}

Texture TextureAsset::LoadFromLine(vector<string> values) {
	Texture tx = Texture(values[0]);
	if (values.size() >= 5) {
		int h = tx.GetHeight() - 1;
		Vector2Int anchorMin = Vector2Int(stoi(values[1]), h - stoi(values[4]));
		Vector2Int anchorMax = Vector2Int(stoi(values[3]), h - stoi(values[2]));
		tx.SetAnchors(anchorMin, anchorMax);
	}
	return tx;
}