#include "SpriteAnimator.h"

SpriteAnimator::SpriteAnimator() {
	isPlaying = false;
	sprite = NULL;
	currentAnimation = NULL;
	currentAnimationName = "";
	frameCountdown = 0;
	currentFrame = 0;
}
SpriteAnimator::SpriteAnimator(Sprite* _sprite) {
	isPlaying = false;
	sprite = _sprite;
	currentAnimation = NULL;
	currentAnimationName = "";
	frameCountdown = 0;
	currentFrame = 0;
}

void SpriteAnimator::Play(string animationName) {
	auto anim = animations.find(animationName);

	currentAnimationName = animationName;
	currentAnimation = (*anim).second;

	currentFrame = 0;
	frameCountdown = 1.0 / currentAnimation->fps;

	DisplayCurrentFrame();

	isPlaying = true;
}

void SpriteAnimator::Stop() {
	isPlaying = false;
}

void SpriteAnimator::Resume() {
	isPlaying = true;
}

void SpriteAnimator::Tick(double deltaTime) {
	if (!isPlaying) return;

	frameCountdown -= deltaTime;

	if (frameCountdown <= 0.0) {
		currentFrame = Math::Repeat(currentFrame + 1, 0, currentAnimation->frames.size());
		frameCountdown += 1.0 / currentAnimation->fps;

		DisplayCurrentFrame();
	}
}

void SpriteAnimator::DisplayCurrentFrame() {
	Texture frameTx = currentAnimation->frames[currentFrame];
	sprite->SetTexture(frameTx);
}

string SpriteAnimator::GetCurrentAnimationName() { return currentAnimationName; }