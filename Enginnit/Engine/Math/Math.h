#ifndef ENGINNIT_MATH
#define ENGINNIT_MATH

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

#define PI 3.14159265

#include <math.h>

namespace Math {
	float Lerp(float a, float b, float t);
	double Lerp(double a, double b, double t);

	Vector2 Lerp(Vector2 a, Vector2 b, float t);
	Vector3 Lerp(Vector3 a, Vector3 b, float t);
	Vector4 Lerp(Vector4 a, Vector4 b, float t);

	float InverseLerp(float a, float b, float x);
	double InverseLerp(double a, double b, double x);

	Vector2 InverseLerp(Vector2 a, Vector2 b, float x);
	Vector3 InverseLerp(Vector3 a, Vector3 b, float x);
	Vector4 InverseLerp(Vector4 a, Vector4 b, float x);

	float Clamp(float value, float min, float max);
	double Clamp(double value, double min, double max);
	int Clamp(int value, int min, int max);

	float Repeat(float value, float min, float max);
	double Repeat(double value, double min, double max);
	int Repeat(int value, int min, int max);

	double ConvertToRadians(double degrees);
	double ConvertToDegrees(double radians);

	Vector2 RotatePoint(Vector2 point, Vector2 pivot, float angle);
};
#endif