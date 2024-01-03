#ifndef ENGINNIT_SPATIAL2D
#define ENGINNIT_SPATIAL2D

#include "Vector2.h"

using namespace std;

class Spatial2D {
public:
	Vector2 position;
	float rotation;
	Vector2 scale;

	int depthLayer;

	Spatial2D();
	Spatial2D(Vector2 position);
	Spatial2D(Vector2 position, float rotation);
};
#endif