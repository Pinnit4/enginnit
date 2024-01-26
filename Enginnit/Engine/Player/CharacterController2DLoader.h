#ifndef ENGINNIT_CHARACTER_CONTROLLER2D_LOADER
#define ENGINNIT_CHARACTER_CONTROLLER2D_LOADER

#include "CharacterController2D.h"
#include "../Nodes/NodeLoader.h"

#include "../Graphics/Textures/TextureLoader.h"
#include "../Animations/SpriteAnimationLoader.h"

using namespace std;

class CharacterController2DLoader : public NodeLoader {
public:
	CharacterController2DLoader() : NodeLoader()
	{ 
		cc = NULL;
	}

protected:
	CharacterController2D* cc;

	virtual void OnLoadStart() override {
		NodeLoader::OnLoadStart();
		cc = (CharacterController2D*)obj;
	}
	virtual void OnLoadFinish() override {
		cc->GetAnimator()->Play(cc->idleLeftAnim);
		cc = NULL;
		NodeLoader::OnLoadFinish();
	}

	virtual void OnSaveStart() override {
		NodeLoader::OnSaveStart();
		cc = (CharacterController2D*)obj;
	}
	virtual void OnSaveFinish() override {
		cc = NULL;
		NodeLoader::OnSaveFinish();
	}

	virtual string GetType() override { return "CharacterController2D"; }

	virtual vector<vector<string>> SaveToFileInternal(vector<vector<string>> v) override {
		v = NodeLoader::SaveToFileInternal(v);

		v.push_back({ "speed", to_string(cc->movementSpeed) });

		v.push_back({ "idle_r_anim", cc->idleRightAnim });
		v.push_back({ "idle_l_anim", cc->idleLeftAnim });
		v.push_back({ "idle_u_anim", cc->idleUpAnim });
		v.push_back({ "idle_d_anim", cc->idleDownAnim });

		v.push_back({ "run_r_anim", cc->runRightAnim });
		v.push_back({ "run_l_anim", cc->runLeftAnim });
		v.push_back({ "run_u_anim", cc->runUpAnim });
		v.push_back({ "run_d_anim", cc->runDownAnim });

		v.push_back({ "depth", to_string(cc->spatial->depthLayer) });

		for (auto i = cc->GetAnimator()->animations.begin(); i != cc->GetAnimator()->animations.end(); i++)
			v.push_back({ (*i).first, (*i).second->path });

		return v;
	}

	virtual bool ProcessLineInternal(string id, vector<string> values) override {
		if (!NodeLoader::ProcessLineInternal(id, values))
			return false;

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
			cc->spatial->depthLayer = stoi(values[0]);
		else if (id == "anim")
			LoadAnimation(cc, values);

		else if (id == "position")
			cc->spatial->position = Vector2f(stof(values[0]), stof(values[1]));
		else if (id == "rotation")
			cc->spatial->rotation = stof(values[0]);
		else if (id == "scale")
			cc->spatial->scale = Vector2f(stof(values[0]), stof(values[1]));
		else if (id == "pivot")
			cc->GetSprite()->pivot = Vector2f(stof(values[0]), stof(values[1]));
		else if (id == "gravity")
			cc->GetRigidbody()->useGravity = (stoi(values[0]) == 1);

		else
			return true;

		return false;
	}

	void LoadAnimation(CharacterController2D* cc, vector<string> values) {
		string name = values[0];
		SpriteAnimation* anim = new SpriteAnimation();
		SpriteAnimationLoader::LoadFromFile(anim, values[1]);
		cc->GetAnimator()->animations.insert({name, anim});
	}
};
#endif