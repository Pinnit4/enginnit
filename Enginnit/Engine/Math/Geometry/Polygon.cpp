#include "Polygon.h"

#include "../Trigonometry.h"
#include <iostream>

Vector2f GetProjectionMinMaxOnAxis(Polygon polygon, Vector2f axis);
float GetProjectionScalarOnAxis(Vector2f vertex, Vector2f axis);

Polygon::Polygon() {
	center = Vector2f(0);
	UpdateVertices();
}

Polygon::Polygon(Vector2f _center) {
	center = _center;
	UpdateVertices();
}

void Polygon::SetCenter(Vector2f _center) {
	center = _center;
	UpdateVertices();
}

Vector2f Polygon::GetCenter() { return center; }

vector<Vector2f> Polygon::GetPoints() { return points; }

void Polygon::UpdateVertices() {

	points.clear();

	CreateVertices();

	lastRotation = 0;
}

void Polygon::CreateVertices() {}

void Polygon::RefreshRotation(float rotation) {
	float rotDelta = rotation - lastRotation;
	if (rotDelta == 0) return;

	for (unsigned int i = 0; i < points.size(); i++)
		points[i] = Math::RotatePoint(points[i], Vector2f(0), rotDelta);

	lastRotation = rotation;
}

bool Polygon::Intersects(Polygon other)
{
	vector<Polygon> aux = { *this, other };
	for (Polygon polygon : aux)
	{
		auto points = polygon.GetPoints();

		for (int i1 = 0; i1 < points.size(); i1++)
		{
			int i2 = (i1 + 1) % points.size();
			Vector2f p1 = points[i1];
			Vector2f p2 = points[i2];

			Vector2f axis = Vector2f(p2.y - p1.y, p1.x - p2.x);

			Vector2f aMinMax = GetProjectionMinMaxOnAxis(*this, axis);
			Vector2f bMinMax = GetProjectionMinMaxOnAxis(other, axis);

			if (aMinMax.y < bMinMax.x || bMinMax.y < aMinMax.x)
				return false;
		}
	}

	return true;
}

bool Polygon::Contains(Polygon other) {
	for (Vector2f point : other.points) {
		if (!Contains(point)) return false;
	}

	return true;
}

// Taken from: https://www.geeksforgeeks.org/how-to-check-if-a-given-point-lies-inside-a-polygon/
bool Polygon::Contains(Vector2f point) {
	int num_vertices = points.size();
	double x = point.x, y = point.y;
	bool inside = false;

	// Store the first point in the polygon and initialize the second point
	Vector2f p1 = points[0];
	Vector2f p2;

	// Loop through each edge in the polygon
	for (int i = 1; i <= points.size(); i++) {
		p2 = points[i % points.size()];	// Get the next point in the polygon

		if (y > min(p1.y, p2.y)) {					// Check if the point is above the minimum y coordinate of the edge
			if (y <= max(p1.y, p2.y)) {				// Check if the point is below the maximum y coordinate of the edge
				if (x <= max(p1.x, p2.x)) {			// Check if the point is to the left of the maximum x coordinate of the edge
					double x_intersection = (y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x; 	// Calculate the x-intersection of the line connecting the point to the edge
					if (p1.x == p2.x || x <= x_intersection) { // Check if the point is on the same line as the edge or to the left of the x-intersection
						inside = !inside; // Flip the inside flag
					}
				}
			}
		}

		// Store the current point as the first point for the next iteration
		p1 = p2;
	}

	// Return the value of the inside flag
	return inside;
}

Vector2f GetProjectionMinMaxOnAxis(Polygon polygon, Vector2f axis) {
	float min = 0, max = 0;
	bool set = false;
	for (auto point : polygon.GetPoints()) {

		float scalar = GetProjectionScalarOnAxis(point, axis);

		if (!set || scalar < min)
			min = scalar;
		if (!set || scalar > max)
			max = scalar;

		set = true;
	}
	return Vector2f(min, max);
}

float GetProjectionScalarOnAxis(Vector2f vertex, Vector2f axis) {
	Vector2f projection = Vector2f::Project(vertex, axis);
	float scalar = Vector2f::Dot(projection, axis);
	return scalar;
}