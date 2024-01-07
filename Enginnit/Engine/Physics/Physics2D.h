#ifndef PHYSICS2DHEADER
#define PHYSICS2DHEADER

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

	static void RegisterRigidbody(Rigidbody2D* sp);
	static void UnregisterRigidbody(Rigidbody2D* sp);

private:
	static std::list<Rigidbody2D*> rgRb;

	void TickRigidbodies(float deltaTime);
	void DebugRender();
};

#endif
