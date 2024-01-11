#include "Trigonometry.h"
#include "MathConstants.h"

double Math::ConvertToRadians(double degrees) { return (degrees * PI) / 180.0; }
float Math::ConvertToRadians(float degrees) { return (degrees * PI) / 180.0; }

double Math::ConvertToDegrees(double radians) { return (radians * 180.0) / PI; }
float Math::ConvertToDegrees(float radians) { return (radians * 180.0) / PI; }

Vector2f Math::RotatePoint(Vector2f point, Vector2f pivot, float angle) {
	double rad = ConvertToRadians(angle);

	double s = sin(rad);
	double c = cos(rad);

	point -= pivot;

	point.x = (float)(point.x * c - point.y * s);
	point.y = (float)(point.x * s + point.y * c);

	point += pivot;

	return point;
}

Vector2d Math::RotatePoint(Vector2d point, Vector2d pivot, double angle) {
	double rad = ConvertToRadians(angle);

	double s = sin(rad);
	double c = cos(rad);

	point -= pivot;

	point.x = (float)(point.x * c - point.y * s);
	point.y = (float)(point.x * s + point.y * c);

	point += pivot;

	return point;
}