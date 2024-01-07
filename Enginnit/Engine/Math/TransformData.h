#ifndef TRANSFORMDATAHEADER
#define TRANSFORMDATAHEADER

#include <corecrt_math.h>
#include "Vector2.h"
#include "Spatial2D.h"

using namespace std;

struct TransformData {
	Vector2 position;
	Vector2 scale;
	float rotation;
	float x;
	float y;

	TransformData(Vector2 _position) {
		position = _position;
		rotation = 0;
		scale = Vector2::One();
	}

	TransformData(Vector2 _position, float _rotation) {
		position = _position;
		rotation = _rotation;
		scale = Vector2::One();
	}

	TransformData(Vector2 _position, float _rotation, Vector2 _scale) {
		position = _position;
		rotation = _rotation;
		scale = _scale;
	}

	static TransformData FromSpatial2D(Spatial2D sp) {
		return TransformData(sp.position, sp.rotation, sp.scale);
	}
};

#endif