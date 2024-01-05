#include "CharacterController2D.h"

#include <string>
#include "CharacterController2DAsset.h"
#include "../Graphics/Graphics.h"

using namespace std;

void MoveCharacter(CharacterController2D* cc, double deltaTime);
void MoveCamera(double deltaTime);
void FocusCameraOnPlayer(CharacterController2D* cc, Vector2 offset);

CharacterController2D::CharacterController2D(string filePath) : Sprite(), Rigidbody2D() {
	CharacterController2DAsset::LoadFromFile(this, filePath);
}

void CharacterController2D::Tick(double deltaTime) {

	MoveCharacter(this, deltaTime);
	//MoveCamera(deltaTime);
	FocusCameraOnPlayer(this, Vector2::Zero());
}

void MoveCharacter(CharacterController2D* cc, double deltaTime) {
	Vector2 input = Vector2::Zero();
	if (Keyboard::GetKey(GLFW_KEY_W))
		input.y += 1;
	if (Keyboard::GetKey(GLFW_KEY_S))
		input.y -= 1;
	if (Keyboard::GetKey(GLFW_KEY_A))
		input.x -= 1;
	if (Keyboard::GetKey(GLFW_KEY_D))
		input.x += 1;

	if (input.x > 0)
		cc->SetTexture(cc->rightTexture);
	else if (input.x < 0)
		cc->SetTexture(cc->leftTexture);
	else if (input.y > 0)
		cc->SetTexture(cc->upTexture);
	else if (input.y < 0)
		cc->SetTexture(cc->downTexture);

	cc->position += input.GetNormalized() * cc->movementSpeed * deltaTime;
}

void FocusCameraOnPlayer(CharacterController2D* cc, Vector2 offset) {
	Graphics::SetCameraPosition(cc->position + offset);
}

void MoveCamera(double deltaTime) {
	Vector2 input = Vector2::Zero();
	if (Keyboard::GetKey(GLFW_KEY_UP))
		input.y += 1;
	if (Keyboard::GetKey(GLFW_KEY_DOWN))
		input.y -= 1;
	if (Keyboard::GetKey(GLFW_KEY_LEFT))
		input.x -= 1;
	if (Keyboard::GetKey(GLFW_KEY_RIGHT))
		input.x += 1;

	Graphics::MoveCamera(input.GetNormalized() * 50 * deltaTime);
}