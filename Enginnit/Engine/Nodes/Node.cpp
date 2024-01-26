#include "Node.h"

#include "NodeManager.h"

Node::Node() 
{ 
	parent = NULL;
	children = {};
	NodeManager::RegisterRootNode(this);
}

void Node::Start() 
{
	StartInternal();
	for (auto c : children) c->Start();
}
void Node::StartInternal() {}

void Node::PhysicsTick(double deltaTime)
{
	PhysicsTickInternal(deltaTime);
	for (auto c : children) c->PhysicsTick(deltaTime);
}
void Node::PhysicsTickInternal(double deltaTime) {}

void Node::Tick(double deltaTime) 
{
	TickInternal(deltaTime);
	for (auto c : children) c->Tick(deltaTime);
}
void Node::TickInternal(double deltaTime) {}

void Node::LateTick(double deltaTime)
{
	LateTickInternal(deltaTime);
	for (auto c : children) c->LateTick(deltaTime);
}
void Node::LateTickInternal(double deltaTime) {}

void Node::SetParent(Node* _parent) {
	if (parent != _parent) {
		if (parent != NULL) {
			parent->RemoveChild(this);
		}
		parent = _parent;
		parent->AddChild(this);

		if (parent == NULL)
			NodeManager::RegisterRootNode(this);
		else
			NodeManager::UnregisterRootNode(this);
	}
}

void Node::AddChild(Node* _child) {
	children.push_back(_child);
}

void Node::RemoveChild(Node* _child) {
	if (children.size() > 0) {
		children.remove_if([&](Node* x) -> bool {return x == _child; });
	}
}
