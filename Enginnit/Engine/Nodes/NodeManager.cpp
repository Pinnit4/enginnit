#include "NodeManager.h"

list<Node*> NodeManager::rgNd = {};

NodeManager::NodeManager() {
}

void NodeManager::RegisterRootNode(Node* nd) {
	if (rgNd.size() > 0) {
		list<Node*>::iterator findIt = find(rgNd.begin(), rgNd.end(), nd);
		if ((findIt) != rgNd.end()) return;
	}
	else if (rgNd.size() > 0) {
		if (rgNd.front() != nd) return;
	}
	rgNd.push_back(nd);
}

void NodeManager::UnregisterRootNode(Node* nd) {
	if (rgNd.size() > 0) {
		rgNd.remove_if([&](Node* x) -> bool {return x == nd; });
	}
}

void NodeManager::PhysicsTick(double deltaTime) {
	for (auto nd : rgNd) nd->PhysicsTick(deltaTime);
}

void NodeManager::Tick(double deltaTime) {
	for (auto nd : rgNd) nd->Tick(deltaTime);
}

void NodeManager::LateTick(double deltaTime) {
	for (auto nd : rgNd) nd->LateTick(deltaTime);
}