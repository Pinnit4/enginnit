#ifndef ENGINNIT_NODE_MANAGER
#define ENGINNIT_NODE_MANAGER

#include "Node.h"

#include <list>
#include <vector>
#include <functional>

using namespace std;

class NodeManager {
public:
	NodeManager();

	static void RegisterRootNode(Node* sp);
	static void UnregisterRootNode(Node* sp);

	void PhysicsTick(double deltaTime);
	void Tick(double deltaTime);
	void LateTick(double deltaTime);

private:
	static list<Node*> rgNd;
};

#endif