#ifndef CHARACTER_CONTROLLER2D
#define CHARACTER_CONTROLLER2D

#include "../Graphics/Sprite.h"
#include "../Physics/Rigidbody2D.h"
#include "../IO/Keyboard.h"

using namespace std;

class CharacterController2D : public Sprite, public Rigidbody2D {
public:
	float movementSpeed;
	
	Texture upTexture;
	Texture downTexture;
	Texture leftTexture;
	Texture rightTexture;

	CharacterController2D(string filePath);

	void Tick(double deltaTime);
private:

};
#endif