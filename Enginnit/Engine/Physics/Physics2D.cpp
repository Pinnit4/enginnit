#include "Physics2D.h"
#include "../Graphics/Graphics.h"
#include "../Debug/DebugCodes.h"

std::list<Rigidbody2D*> Physics2D::rgRb = {};
std::list<Collider2D*> Physics2D::rgCl = {};

Physics2D::Physics2D() {
	rgRb.clear();
}

void Physics2D::Initialize() {
	rgRb.clear();
#ifdef _DEBUG
	GraphicsManager::beforeUiRender.push_back([&]() { DebugRender(); });
#endif
}

void Physics2D::Tick(float deltaTime) {
	TickRigidbodies(deltaTime);
}

void Physics2D::TickRigidbodies(float deltaTime) {
	if (rgRb.size() == 0)
		return;

	for (auto rb : rgRb) {
		rb->Preprocess(deltaTime);
		ProcessRigidbodyCollisions(rb);
		rb->Postprocess(deltaTime);
	}
}

void Physics2D::DebugRender() {
	if (DebugCodes::GetInt("show_hitbox", 0) == 1)
	{
		for (auto cl : rgCl)
			cl->DebugRender();
	}
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
	for (auto cl : rgCl) {
		if (rb == cl) continue;
		if (Collider2D::AreColliding(*cl, *rb))
			rb->ProcessCollision(cl);
	}
}