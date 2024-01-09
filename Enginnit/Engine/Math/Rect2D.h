#ifndef ENGINNIT_RECT2D
#define ENGINNIT_RECT2D

#include "Vector2.h"
#include "../Graphics/Color.h"
#include "TransformData.h"
#include "Math.h"

class Rect2D {
public:
	Rect2D();
	Rect2D(Vector2f size);
	Rect2D(Vector2f center, Vector2f size);

	void SetCenter(Vector2f center);
	void SetSize(Vector2f size);

	Vector2f GetCenter();
	Vector2f GetSize();

	Vector2f GetUpperLeftVertex();
	Vector2f GetUpperRightVertex();
	Vector2f GetLowerLeftVertex();
	Vector2f GetLowerRightVertex();

	void DebugRender(TransformData data, Color color);
	void RefreshRotation(float rotation);
private:
	Vector2f center;
	Vector2f size;

	Vector2f upperLeftVertex;
	Vector2f upperRightVertex;
	Vector2f lowerLeftVertex;
	Vector2f lowerRightVertex;

	float lastRotation;

	void UpdateVertices();
};
#endif