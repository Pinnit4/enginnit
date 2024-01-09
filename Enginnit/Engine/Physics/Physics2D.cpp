#include "Physics2D.h"
#include "../Graphics/Graphics.h"

std::list<Rigidbody2D*> Physics2D::rgRb = {};
std::list<Collider2D*> Physics2D::rgCl = {};

Physics2D::Physics2D() {
	rgRb.clear();
}

void Physics2D::Initialize() {
	rgRb.clear();
	Graphics::onEndRender.push_back([&]() {DebugRender(); });
}

void Physics2D::Tick(float deltaTime) {
	TickRigidbodies(deltaTime);
}

void Physics2D::TickRigidbodies(float deltaTime) {
	if (rgRb.size() == 0)
		return;

	for (auto it = rgRb.begin(); it != rgRb.end(); it++) {
		(*it)->PhysicsTick(deltaTime);
		ProcessRigidbodyCollisions((*it));
	}
}

void Physics2D::DebugRender() {
	Color color = Color(1, 0.5, 0.5);

	for (auto it = rgRb.begin(); it != rgRb.end(); it++)
		(*it)->DebugRender(color);
}

void Physics2D::Shutdown() {
	rgRb.clear();
}

void Physics2D::RegisterRigidbody(Rigidbody2D* rb) {
	if (rgRb.size() > 1) {
		auto findIt = std::find(rgRb.begin(), rgRb.end(), rb);
		if ((findIt) != rgRb.end()) return;
	}
	else if (rgRb.size() > 0) {
		if (rgRb.front() == rb) return;
	}

	rgRb.push_back(rb);
}

void Physics2D::UnregisterRigidbody(Rigidbody2D* rb) {
	if (rgRb.size() > 0)
		rgRb.remove_if([&](Rigidbody2D* x) -> bool {return x == rb; });
}

void Physics2D::RegisterCollider(Collider2D* cl) {
	if (rgCl.size() > 1) {
		auto findIt = std::find(rgCl.begin(), rgCl.end(), cl);
		if ((findIt) != rgCl.end()) return;
	}
	else if (rgCl.size() > 0) {
		if (rgCl.front() == cl) return;
	}
	rgCl.push_back(cl);
}

void Physics2D::UnregisterCollider(Collider2D* cl) {
	if (rgCl.size() > 0)
		rgCl.remove_if([&](Collider2D* x) -> bool {return x == cl; });
}

void Physics2D::ProcessRigidbodyCollisions(Rigidbody2D* rb) {
	for (auto it = rgCl.begin(); it != rgCl.end(); it++) {
		if (rb == (*it)) continue;
		if (Collider2D::AreColliding(*(*it), *rb))
			rb->ProcessCollision((*it));
	}
}