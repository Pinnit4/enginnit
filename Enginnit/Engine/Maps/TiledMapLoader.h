#ifndef ENGINNIT_TILED_MAP_LOADER
#define ENGINNIT_TILED_MAP_LOADER

#include "TiledMap.h"
#include "../Scenes/Scenes.h"

#include "../Graphics/Tiles/TilesetLoader.h"

using namespace std;

class TiledMapLoader : public SceneObjectLoader {
public:
	TiledMapLoader() : SceneObjectLoader() { }

protected:
	TiledMap* tm;

	virtual void OnLoadStart() override {
		SceneObjectLoader::OnLoadStart();
		tm = (TiledMap*)obj;
	}
	virtual void OnLoadFinish() override {
		tm = NULL;
		SceneObjectLoader::OnLoadFinish();
	}

	virtual void OnSaveStart() override {
		SceneObjectLoader::OnSaveStart();
		tm = (TiledMap*)obj;
	}
	virtual void OnSaveFinish() override {
		tm = NULL;
		SceneObjectLoader::OnSaveFinish();
	}

	virtual string GetType() override { return "TiledMap"; }

	virtual vector<vector<string>> SaveToFileInternal(vector<vector<string>> v) override {
		v = SceneObjectLoader::SaveToFileInternal(v);

		v.push_back({"tileset", tm->tileset->path });

		for (unsigned int i = 0; i < tm->spriteGridIds.size(); i++) {
			vector<char> tileLine = tm->spriteGridIds[i];

			string st = "";
			for (unsigned int j = 0; j < tileLine.size(); j++)
				st += tileLine[j];

			v.push_back({ "tile_line", st });
		}

		for (unsigned int i = 0; i < tm->colliderGridIds.size(); i++) {
			vector<char> collLine = tm->colliderGridIds[i];

			string st = "";
			for (unsigned int j = 0; j < collLine.size(); j++)
				st += collLine[j];

			v.push_back({ "coll_line", st });
		}

		return v;
	}

	virtual bool ProcessLineInternal(string id, vector<string> values) override {
		if (!SceneObjectLoader::ProcessLineInternal(id, values))
			return false;

		if (id == "tileset")
			TilesetLoader::LoadFromFile(tm->tileset, values[0]);
		else if (id == "position")
			tm->position = Vector2f(stof(values[0]), stof(values[1]));

		else if (id == "tile_line") {
			vector<char> tileLine = vector<char>();

			for (unsigned int i = 0; i < values[0].size(); i++)
				tileLine.push_back(values[0].at(i));

			tm->spriteGridIds.push_back(tileLine);
		}
		else if (id == "coll_line") {
			vector<char> tileLine = vector<char>();

			for (unsigned int i = 0; i < values[0].size(); i++)
				tileLine.push_back(values[0].at(i));

			tm->colliderGridIds.push_back(tileLine);
		}

		else
			return true;

		return false;
	}
};
#endif