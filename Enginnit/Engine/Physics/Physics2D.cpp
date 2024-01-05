#include "Physics2D.h"

std::list<Rigidbody2D*> Physics2D::rgRb = {};

Physics2D::Physics2D() {
	rgRb.clear();
}

void Physics2D::Initialize() {
	rgRb.clear();
}

void Physics2D::Tick(float deltaTime) {
	TickRigidbodies(deltaTime);
}

void Physics2D::TickRigidbodies(float deltaTime) {
	if (rgRb.size() == 0)
		return;

	for (std::list<Rigidbody2D*>::iterator it = rgRb.begin(); it != rgRb.end(); it++) {
		(*it)->PhysicsTick(deltaTime);
	}
}

void Physics2D::Shutdown() {

}

void Physics2D::RegisterRigidbody(Rigidbody2D* rb) {
	if (rgRb.size() > 1) {
		std::list<Rigidbody2D*>::iterator findIt = std::find(rgRb.begin(), rgRb.end(), rb);
		if ((findIt) != rgRb.end()) return;
	}
	else if (rgRb.size() > 0) {
		if (rgRb.front() != rb) return;
	}
	rgRb.push_back(rb);
}

void Physics2D::UnregisterRigidbody(Rigidbody2D* rb) {
	if (rgRb.size() > 0) {
		rgRb.remove_if([&](Rigidbody2D* x) -> bool {return x == rb; });
	}
}