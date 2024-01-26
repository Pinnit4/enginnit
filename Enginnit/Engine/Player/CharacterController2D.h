#ifndef CHARACTER_CONTROLLER2D
#define CHARACTER_CONTROLLER2D

#include "../Graphics/Graphics.h"
#include "../Physics/Rigidbody2D.h"
#include "../IO/Input.h"
#include "../Animations/SpriteAnimator.h"
#include "../Nodes/Node.h"

using namespace std;

class CharacterController2D : public Node {
public:
	CharacterController2D();
	CharacterController2D(string filePath);

	Spatial2D* spatial;
	float movementSpeed;

	string idleRightAnim, idleLeftAnim, idleUpAnim, idleDownAnim;
	string runRightAnim, runLeftAnim, runUpAnim, runDownAnim;

	Sprite* GetSprite() { return sprite; }
	SpriteAnimator* GetAnimator() { return animator; }

	Rigidbody2D* GetRigidbody() { return rb; }

protected:
	Sprite* sprite;
	SpriteAnimator* animator;

	Rigidbody2D* rb;

	void PhysicsTickInternal(double deltaTime) override;
	void TickInternal(double deltaTime) override;

	void TickMovement(double deltaTime);
};
#endif