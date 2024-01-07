#ifndef ENGINNIT_RECT2D
#define ENGINNIT_RECT2D

#include "Vector2.h"
#include "../Graphics/Color.h"
#include "TransformData.h"
#include "Math.h"

class Rect2D {
public:
	Rect2D();
	Rect2D(Vector2 size);
	Rect2D(Vector2 center, Vector2 size);

	void SetCenter(Vector2 center);
	void SetSize(Vector2 size);

	Vector2 GetCenter();
	Vector2 GetSize();

	void DebugRender(TransformData data, Color color);
	void RefreshRotation(float rotation);
private:
	Vector2 center;
	Vector2 size;

	Vector2 upperLeftVertex;
	Vector2 upperRightVertex;
	Vector2 lowerLeftVertex;
	Vector2 lowerRightVertex;

	float lastRotation;

	void UpdateVertices();
};
#endif