#ifndef ENGINNIT_SPRITE_ANIMATOR
#define ENGINNIT_SPRITE_ANIMATOR

#include "GLFW/glfw3.h"

#include <iostream>
#include <string>
#include <vector>

#include "../Math/Math.h"
#include "../Math/Spatial2D.h"

#include "../Graphics/Tiles/Tileset.h"
#include "../Graphics/Sprite.h"
#include "SpriteAnimation.h"

using namespace std;

struct SpriteAnimator {
public:
	Sprite* sprite;
	map<string, SpriteAnimation*> animations;

	SpriteAnimator();
	SpriteAnimator(Sprite* sprite);

	void Tick(double deltaTime);
	void Play(string animationName);
	void Stop();
	void Resume();

	string GetCurrentAnimationName();

private:
	double frameCountdown;
	int currentFrame;

	string currentAnimationName;
	SpriteAnimation* currentAnimation;

	bool isPlaying;

	void DisplayCurrentFrame();
};
#endif