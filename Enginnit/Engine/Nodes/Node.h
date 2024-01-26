#ifndef ENGINNIT_NODE
#define ENGINNIT_NODE

#include "../Assets/Asset.h"

#include <string>
#include <list>
#include <map>
#include <vector>

using namespace std;

class Node : public Asset {
public:
	Node();

	vector<map<string, vector<string>>> inParentVariables;
	
	void Start();

	void PhysicsTick(double deltaTime);
	void Tick(double deltaTime);
	void LateTick(double deltaTime);

	void SetParent(Node* parent);
protected:
	Node* parent;
	list<Node*> children;

	virtual void StartInternal();
	
	virtual void PhysicsTickInternal(double deltaTime);
	virtual void TickInternal(double deltaTime);
	virtual void LateTickInternal(double deltaTime);

	void AddChild(Node* child);
	void RemoveChild(Node* child);
};

#endif