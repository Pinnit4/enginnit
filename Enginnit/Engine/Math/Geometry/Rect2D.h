#ifndef ENGINNIT_RECT2D
#define ENGINNIT_RECT2D

#include "Polygon.h"

class Rect2D : public Polygon {
public:
	Rect2D();
	Rect2D(Vector2f size);
	Rect2D(Vector2f center, Vector2f size);

	void SetSize(Vector2f size);
	Vector2f GetSize();
protected:
	Vector2f size;
	void CreateVertices() override;
};
#endif