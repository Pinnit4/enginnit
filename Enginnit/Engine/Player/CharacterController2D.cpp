#include "CharacterController2D.h"

#include "../Debug/DebugConsole.h"
#include "CharacterController2DLoader.h"

using namespace std;

void MoveCamera(double deltaTime);
void FocusCameraOnPlayer(CharacterController2D* cc, Vector2f offset);

CharacterController2D::CharacterController2D() : Rigidbody2D(), Node() {
	sprite = new Sprite(spatial);
	animator = new SpriteAnimator(sprite);
	movementSpeed = 0;
}

CharacterController2D::CharacterController2D(string filePath) : Rigidbody2D(), Node() {
	sprite = new Sprite(spatial);
	animator = new SpriteAnimator(sprite);
	movementSpeed = 0;

	CharacterController2DLoader loader = CharacterController2DLoader();
	loader.LoadFromFile(this, filePath);

	Vector2f size = Vector2f(sprite->GetTexture().GetWidth(), sprite->GetTexture().GetHeight());
	rect->SetCenter(sprite->pivot * size);
	rect->SetSize(size);
}

void CharacterController2D::TickInternal(double deltaTime) {
	animator->Tick(deltaTime);
	//MoveCamera(deltaTime);
	FocusCameraOnPlayer(this, Vector2f::Zero());
}

void CharacterController2D::PhysicsTick(double deltaTime) {
	Rigidbody2D::PhysicsTick(deltaTime);
	TickMovement(deltaTime);
}

void CharacterController2D::TickMovement(double deltaTime) {
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
		DebugConsole::Log("Character pos: " + spatial->position.ToString());

	if (input.x > 0) 
		animator->SwitchAnimation(runRightAnim);
	else if (input.x < 0) 
		animator->SwitchAnimation(runLeftAnim);
	else if (input.y > 0)
		animator->SwitchAnimation(runUpAnim);
	else if (input.y < 0)
		animator->SwitchAnimation(runDownAnim);
	else {
		string currentAnim = animator->GetCurrentAnimationName();
		if (currentAnim == runRightAnim)
			animator->SwitchAnimation(idleRightAnim);
		else if (currentAnim == runLeftAnim)
			animator->SwitchAnimation(idleLeftAnim);
		else if (currentAnim == runUpAnim)
			animator->SwitchAnimation(idleUpAnim);
		else if (currentAnim == runDownAnim)
			animator->SwitchAnimation(idleDownAnim);
	}

	spatial->position += (input.GetNormalized() * (movementSpeed * deltaTime));
	//sprite->position = position;
	//sprite->depthLayer = depthLayer;
}

void FocusCameraOnPlayer(CharacterController2D* cc, Vector2f offset) {
	Vector2f pos = cc->spatial->position;
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