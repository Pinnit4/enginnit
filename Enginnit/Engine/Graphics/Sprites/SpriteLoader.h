#ifndef ENGINNIT_SPRITE_LOADER
#define ENGINNIT_SPRITE_LOADER

#include <string>
#include <vector>

#include "Sprite.h"
#include "../../Assets/AssetFile.h"
#include "../../Assets/AssetLoader.h"

#include "../Textures/TextureLoader.h"

using namespace std;

class SpriteLoader : public AssetLoader {
public:
	SpriteLoader() : AssetLoader() {
		sp = NULL;
	}
protected:
	Sprite* sp;

	virtual void OnLoadStart() override {
		AssetLoader::OnLoadStart();
		sp = (Sprite*)asset;
	}
	virtual void OnLoadFinish() override {
		sp = NULL;
		AssetLoader::OnLoadFinish();
	}

	virtual void OnSaveStart() override {
		AssetLoader::OnSaveStart();
		sp = (Sprite*)asset;
	}
	virtual void OnSaveFinish() override {
		sp = NULL;
		AssetLoader::OnSaveFinish();
	}

	virtual string GetType() override { return "Sprite"; }

	virtual vector<vector<string>> SaveToFileInternal(vector<vector<string>> v) override {
		v = AssetLoader::SaveToFileInternal(v);

		v.push_back(TextureLoader::SaveAsLine(sp->GetTexture(), "texture"));

		vector<string> margins = { "margins" };

		for (float i : sp->GetMargins())
			margins.push_back(to_string(i));

		return v;
	}
	virtual bool ProcessLineInternal(string id, vector<string> values) override {
		if (!AssetLoader::ProcessLineInternal(id, values))
			return false;

		if (id == "texture")
			sp->SetTexture(TextureLoader::LoadFromLine(values));
		else if (id == "margins") {
			vector<int> margins = {};
			for (auto i : values)
				margins.push_back(stoi(i));

			sp->SetMargins(margins);
		}
		else
			return true;

		return false;
	}
};
#endif
