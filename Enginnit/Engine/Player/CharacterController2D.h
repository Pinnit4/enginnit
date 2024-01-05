#ifndef CHARACTER_CONTROLLER2D
#define CHARACTER_CONTROLLER2D

#include "../Graphics/Sprite.h"
#include "../Physics/Rigidbody2D.h"
#include "../IO/Keyboard.h"
#include "../Animations/SpriteAnimator.h"

using namespace std;

class CharacterController2D : public Sprite, public Rigidbody2D {
public:
	float movementSpeed;
	
	SpriteAnimator animator;

	string idleRightAnim, idleLeftAnim, idleUpAnim, idleDownAnim;
	string runRightAnim, runLeftAnim, runUpAnim, runDownAnim;

	CharacterController2D(string filePath);

	void Tick(double deltaTime);
private:
};
#endif