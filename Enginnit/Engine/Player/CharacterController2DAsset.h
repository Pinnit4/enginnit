#ifndef CHARACTER_CONTROLLER2D_ASSET
#define CHARACTER_CONTROLLER2D_ASSET

#include "CharacterController2D.h"
#include "../IO/AssetFile.h"
#include "../Graphics/TextureAsset.h"
#include "../Animations/SpriteAnimationAsset.h"
#include <vector>

using namespace std;

class CharacterController2DAsset {
public:
	static void SaveToFile(CharacterController2D* cc, string filePath) {
		vector<vector<string>> v = {
			{"type", "CharacterController2D"},
			{"speed", to_string(cc->movementSpeed)},

			{"idle_r_anim", cc->idleRightAnim},
			{"idle_l_anim", cc->idleLeftAnim},
			{"idle_u_anim", cc->idleUpAnim},
			{"idle_d_anim", cc->idleDownAnim},

			{"run_r_anim", cc->runRightAnim},
			{"run_l_anim", cc->runLeftAnim},
			{"run_u_anim", cc->runUpAnim},
			{"run_d_anim", cc->runDownAnim},

			{"depth", to_string(cc->depthLayer)}
		};

		for (auto i = cc->animator.animations.begin(); i != cc->animator.animations.end(); i++) 
			v.push_back({ (*i).first, (*i).second->path });

		AssetFile::WriteAssetFile(filePath, v);
	}

	static void LoadFromFile(CharacterController2D* _cc, string filePath) {
		cc = _cc;

		cc->animator.animations.clear();
		AssetFile::ReadAssetFile(filePath, [&](string id, vector<string> values) {
			ProcessLine(id, values);
			});

		cc->animator.Play(cc->idleLeftAnim);

		cc = NULL;
	}

	static void LoadExtraLines(CharacterController2D* _cc, vector<map<string, vector<string>>> lines) {
		cc = _cc;

		for (auto line : lines) {
			for (auto kvp : line) 
				ProcessLine(kvp.first, kvp.second);
		}

		cc = NULL;
	}

private:
	static CharacterController2D* cc;

	static void ProcessLine(string id, vector<string> values) {
		if (id == "speed")
			cc->movementSpeed = stof(values[0]);

		else if (id == "idle_r_anim")
			cc->idleRightAnim = values[0];
		else if (id == "idle_l_anim")
			cc->idleLeftAnim = values[0];
		else if (id == "idle_u_anim")
			cc->idleUpAnim = values[0];
		else if (id == "idle_d_anim")

			cc->idleDownAnim = values[0];
		else if (id == "run_r_anim")
			cc->runRightAnim = values[0];
		else if (id == "run_l_anim")
			cc->runLeftAnim = values[0];
		else if (id == "run_u_anim")
			cc->runUpAnim = values[0];
		else if (id == "run_d_anim")

			cc->runDownAnim = values[0];
		else if (id == "depth")
			cc->depthLayer = stoi(values[0]);
		else if (id == "anim")
			LoadAnimation(values);

		else if (id == "position")
			cc->position = Vector2f(stof(values[0]), stof(values[1]));
		else if (id == "rotation")
			cc->rotation = stof(values[0]);
		else if (id == "scale")
			cc->scale = Vector2f(stof(values[0]), stof(values[1]));
		else if (id == "pivot")
			cc->pivot = Vector2f(stof(values[0]), stof(values[1]));
		else if (id == "gravity")
			cc->useGravity = (stoi(values[0]) == 1);
	}

	static void LoadAnimation(vector<string> values) {
		string name = values[0];
		SpriteAnimation* anim = new SpriteAnimation();
		SpriteAnimationAsset::LoadFromFile(anim, values[1]);
		cc->animator.animations.insert({ name, anim });
	}
};
#endif