#ifndef ENGINNIT_MATH_TRIGONOMETRY
#define ENGINNIT_MATH_TRIGONOMETRY

#include "Vectors/Vectors.h"
#include <math.h>

namespace Math {
	float ConvertToRadians(float degrees);
	double ConvertToRadians(double degrees);

	float ConvertToDegrees(float radians);
	double ConvertToDegrees(double radians);

	Vector2f RotatePoint(Vector2f point, Vector2f pivot, float angle);
	Vector2d RotatePoint(Vector2d point, Vector2d pivot, double angle);
};
#endif