#ifndef ENGINNIT_POLYGON
#define ENGINNIT_POLYGON

#include "../Vectors/Vectors.h"
#include <vector>

class Polygon {
public:
	Polygon();
	Polygon(Vector2f center);

	void SetCenter(Vector2f center);
	Vector2f GetCenter();

	vector<Vector2f> GetPoints();

	void UpdateVertices();
	void RefreshRotation(float rotation);

	bool Intersects(Polygon other);
	bool Contains(Polygon other);
	bool Contains(Vector2f point);
protected:
	vector<Vector2f> points;
	Vector2f center;

	float lastRotation;

	virtual void CreateVertices();
};
#endif