#include "Spatial2D.h"

Spatial2D::Spatial2D() {
	position = Vector2f::Zero();
	rotation = 0;
	scale = Vector2f::One();
	depthLayer = 0;
}

Spatial2D::Spatial2D(Vector2f _position) {
	position = _position;
	rotation = 0;
	scale = Vector2f::One();
	depthLayer = 0;
}

Spatial2D::Spatial2D(Vector2f _position, float _rotation) {
	position = _position;
	rotation = _rotation;
	scale = Vector2f::One();
	depthLayer = 0;
}