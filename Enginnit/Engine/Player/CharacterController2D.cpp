#include "CharacterController2D.h"

#include <string>
#include "CharacterController2DAsset.h"

using namespace std;

CharacterController2D::CharacterController2D(string filePath) : Sprite(), Rigidbody2D() {
	CharacterController2DAsset::LoadFromFile(this, filePath);
}

void CharacterController2D::Tick(double deltaTime) {

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
		SetTexture(rightTexture);
	else if (input.x < 0)
		SetTexture(leftTexture);
	else if (input.y > 0)
		SetTexture(upTexture);
	else if (input.y < 0)
		SetTexture(downTexture);

	position += input.GetNormalized() * movementSpeed * deltaTime;
}