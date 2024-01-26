#include "SceneObject.h"

SceneObject::SceneObject() 
{ 
	parent = NULL;
	children = {};
}

void SceneObject::Start() 
{
	StartInternal();
	for (auto c : children) c->Start();
}
void SceneObject::Tick(double deltaTime) 
{
	TickInternal(deltaTime);
	for (auto c : children) c->TickInternal(deltaTime);
}

void SceneObject::StartInternal() {}
void SceneObject::TickInternal(double deltaTime) {}

void SceneObject::SetParent(SceneObject* _parent) {
	if (parent != _parent) {
		if (parent != NULL) {
			parent->RemoveChild(this);
		}
		parent = _parent;
		parent->AddChild(this);
	}
}

void SceneObject::AddChild(SceneObject* _child) {
	children.push_back(_child);
}

void SceneObject::RemoveChild(SceneObject* _child) {
	if (children.size() > 0) {
		children.remove_if([&](SceneObject* x) -> bool {return x == _child; });
	}
}
