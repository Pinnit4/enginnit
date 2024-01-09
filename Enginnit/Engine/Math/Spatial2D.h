#ifndef ENGINNIT_SPATIAL2D
#define ENGINNIT_SPATIAL2D

#include "Vector2.h"

using namespace std;

class Spatial2D {
public:
	Vector2f position;
	float rotation;
	Vector2f scale;

	int depthLayer;

	Spatial2D();
	Spatial2D(Vector2f position);
	Spatial2D(Vector2f position, float rotation);
};
#endif