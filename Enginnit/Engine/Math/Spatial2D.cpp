#include "Spatial2D.h"

Spatial2D::Spatial2D() {
	position = Vector2f(0);
	rotation = 0;
	scale = Vector2f(1);

	depthLayer = 0;
}

Spatial2D::Spatial2D(Vector2f _position) {
	position = Vector2f(_position);
	rotation = 0;
	scale = Vector2f(1);

	depthLayer = 0;
}

Spatial2D::Spatial2D(Vector2f _position, float _rotation) {
	position = Vector2f(_position);
	rotation = _rotation;
	scale = Vector2f(1);

	depthLayer = 0;
}

Spatial2D::Spatial2D(Vector2f _position, float _rotation, Vector2f _scale) {
	position = Vector2f(_position);
	rotation = _rotation;
	scale = _scale;

	depthLayer = 0;
}

Spatial2D::Spatial2D(const Spatial2D& source) {
	position = source.position;
	rotation = source.rotation;
	scale = source.scale;

	depthLayer = source.depthLayer;
}