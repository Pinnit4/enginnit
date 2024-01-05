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

	static  void LoadFromFile(CharacterController2D* cc, string filePath) {
		cc->animator.animations.clear();
		AssetFile::ReadAssetFile(filePath, [&](string id, vector<string> values) {
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
			else if (id == "anim") {
				string name = values[0];
				SpriteAnimation* anim = new SpriteAnimation();
				SpriteAnimationAsset::LoadFromFile(anim, values[1]);
				cc->animator.animations.insert({ name, anim });
			}
			});

		cc->animator.Play(cc->idleLeftAnim);
	}
};
#endif