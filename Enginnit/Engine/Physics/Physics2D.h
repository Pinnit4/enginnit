#ifndef ENGINNIT_PHYSICS2D
#define ENGINNIT_PHYSICS2D

#include "GLFW/glfw3.h"
#pragma comment(lib, "opengl32.lib")

#include <list>
#include "Rigidbody2D.h"

#include <iostream>
using namespace std;

class Physics2D {
public:
	Physics2D();

	void Initialize();
	void Tick(float deltaTime);
	void Shutdown();

	static void RegisterRigidbody(Rigidbody2D* rb);
	static void UnregisterRigidbody(Rigidbody2D* rb);

	static void RegisterCollider(Collider2D* cl);
	static void UnregisterCollider(Collider2D* cl);

private:
	static std::list<Rigidbody2D*> rgRb;
	static std::list<Collider2D*> rgCl;

	void TickRigidbodies(float deltaTime);
	void DebugRender();

	void ProcessRigidbodyCollisions(Rigidbody2D* rb);
};

#endif
