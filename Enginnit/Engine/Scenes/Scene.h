#ifndef ENGINNIT_SCENE
#define ENGINNIT_SCENE

#include <string>
#include "../Nodes/Node.h"

using namespace std;

class Scene : public Node {
public:
	Scene();
	Scene(string filePath);
private:
};
#endif
