#include "CharacterController2D.h"

#include "CharacterController2DAsset.h"

using namespace std;

void MoveCharacter(CharacterController2D* cc, double deltaTime);
void MoveCamera(double deltaTime);
void FocusCameraOnPlayer(CharacterController2D* cc, Vector2f offset);

CharacterController2D::CharacterController2D() : Sprite(), Rigidbody2D(), SceneObject() {
	animator = SpriteAnimator(this);
	movementSpeed = 0;
}

CharacterController2D::CharacterController2D(string filePath) : Sprite(), Rigidbody2D(), SceneObject() {
	animator = SpriteAnimator(this);
	movementSpeed = 0;

	CharacterController2DAsset::LoadFromFile(this, filePath);

	Vector2f size = Vector2f(GetTexture().GetWidth(), GetTexture().GetHeight());
	rect->SetCenter(pivot * size);
	rect->SetSize(size);
}

void CharacterController2D::Tick(double deltaTime) {
	animator.Tick(deltaTime);
	//MoveCamera(deltaTime);
	FocusCameraOnPlayer(this, Vector2f::Zero());
}

void CharacterController2D::PhysicsTick(double deltaTime) {
	Rigidbody2D::PhysicsTick(deltaTime);
	MoveCharacter(this, deltaTime);
}

void MoveCharacter(CharacterController2D* cc, double deltaTime) {
	Vector2f input = Vector2f::Zero();
	if (Keyboard::GetKey(GLFW_KEY_W))
		input.y += 1;
	if (Keyboard::GetKey(GLFW_KEY_S))
		input.y -= 1;
	if (Keyboard::GetKey(GLFW_KEY_A))
		input.x -= 1;
	if (Keyboard::GetKey(GLFW_KEY_D))
		input.x += 1;

	if (Keyboard::GetKeyDown(GLFW_KEY_K))
		cout << cc->position.ToString() << endl;

	if (input.x > 0) {
		if (cc->animator.GetCurrentAnimationName() != cc->runRightAnim)
			cc->animator.Play(cc->runRightAnim);
	}
	else if (input.x < 0) {
		if (cc->animator.GetCurrentAnimationName() != cc->runLeftAnim)
			cc->animator.Play(cc->runLeftAnim);
	}
	else if (input.y > 0) {
		if (cc->animator.GetCurrentAnimationName() != cc->runUpAnim)
			cc->animator.Play(cc->runUpAnim);
	}
	else if (input.y < 0) {
		if (cc->animator.GetCurrentAnimationName() != cc->runDownAnim)
			cc->animator.Play(cc->runDownAnim);
	}
	else {
		string currentAnim = cc->animator.GetCurrentAnimationName();
		if (currentAnim == cc->runRightAnim)
			cc->animator.Play(cc->idleRightAnim);
		else if (currentAnim == cc->runLeftAnim)
			cc->animator.Play(cc->idleLeftAnim);
		else if (currentAnim == cc->runUpAnim)
			cc->animator.Play(cc->idleUpAnim);
		else if (currentAnim == cc->runDownAnim)
			cc->animator.Play(cc->idleDownAnim);
	}

	cc->position += (input.GetNormalized() * (cc->movementSpeed * deltaTime));
}

void FocusCameraOnPlayer(CharacterController2D* cc, Vector2f offset) {
	Vector2f pos = cc->position;
	GraphicsManager::SetCameraPosition(pos + offset);
}

void MoveCamera(double deltaTime) {
	Vector2f input = Vector2f::Zero();
	if (Keyboard::GetKey(GLFW_KEY_UP))
		input.y += 1;
	if (Keyboard::GetKey(GLFW_KEY_DOWN))
		input.y -= 1;
	if (Keyboard::GetKey(GLFW_KEY_LEFT))
		input.x -= 1;
	if (Keyboard::GetKey(GLFW_KEY_RIGHT))
		input.x += 1;

	GraphicsManager::MoveCamera(input.GetNormalized() * 50 * deltaTime);
}