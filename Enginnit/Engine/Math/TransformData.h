#ifndef TRANSFORMDATAHEADER
#define TRANSFORMDATAHEADER

#include "Spatial2D.h"

using namespace std;

struct TransformData {
	Vector2f position;
	Vector2f scale;
	float rotation;

	TransformData(Vector2f _position) {
		position = _position;
		rotation = 0;
		scale = Vector2f::One();
	}

	TransformData(Vector2f _position, float _rotation) {
		position = _position;
		rotation = _rotation;
		scale = Vector2f::One();
	}

	TransformData(Vector2f _position, float _rotation, Vector2f _scale) {
		position = _position;
		rotation = _rotation;
		scale = _scale;
	}

	static TransformData FromSpatial2D(Spatial2D sp) {
		return TransformData(sp.position, sp.rotation, sp.scale);
	}
};

#endif