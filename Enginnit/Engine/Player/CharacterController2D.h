#ifndef CHARACTER_CONTROLLER2D
#define CHARACTER_CONTROLLER2D

#include "../Graphics/Sprite.h"
#include "../Physics/Rigidbody2D.h"
#include "../IO/Keyboard.h"
#include "../Animations/SpriteAnimator.h"
#include "../Scenes/SceneObject.h"

using namespace std;

class CharacterController2D : public Sprite, public Rigidbody2D, public SceneObject {
public:
	float movementSpeed;
	
	SpriteAnimator animator;

	string idleRightAnim, idleLeftAnim, idleUpAnim, idleDownAnim;
	string runRightAnim, runLeftAnim, runUpAnim, runDownAnim;

	CharacterController2D();
	CharacterController2D(string filePath);
	
	void Tick(double deltaTime) override;
	void PhysicsTick(double deltaTime) override;
private:
};
#endif