#include "Spatial2D.h"

Spatial2D::Spatial2D() {
	position = Vector2::Zero();
	rotation = 0;
	scale = Vector2::One();
	depthLayer = 0;
}

Spatial2D::Spatial2D(Vector2 _position) {
	position = _position;
	rotation = 0;
	scale = Vector2::One();
	depthLayer = 0;
}

Spatial2D::Spatial2D(Vector2 _position, float _rotation) {
	position = _position;
	rotation = _rotation;
	scale = Vector2::One();
	depthLayer = 0;
}