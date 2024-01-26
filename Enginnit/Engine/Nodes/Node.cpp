#include "Node.h"

Node::Node() 
{ 
	parent = NULL;
	children = {};
}

void Node::Start() 
{
	StartInternal();
	for (auto c : children) c->Start();
}
void Node::Tick(double deltaTime) 
{
	TickInternal(deltaTime);
	for (auto c : children) c->Tick(deltaTime);
}

void Node::StartInternal() {}
void Node::TickInternal(double deltaTime) {}

void Node::SetParent(Node* _parent) {
	if (parent != _parent) {
		if (parent != NULL) {
			parent->RemoveChild(this);
		}
		parent = _parent;
		parent->AddChild(this);
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
