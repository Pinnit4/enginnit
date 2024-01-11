#ifndef ENGINNIT_MATH_INTERPOLATIONS
#define ENGINNIT_MATH_INTERPOLATIONS

#include "Vectors/Vectors.h"

namespace Math {
	float Lerp(float a, float b, float t);
	double Lerp(double a, double b, double t);

	Vector2f Lerp(Vector2f a, Vector2f b, float t);
	Vector2d Lerp(Vector2d a, Vector2d b, double t);

	Vector3f Lerp(Vector3f a, Vector3f b, float t);
	Vector3d Lerp(Vector3d a, Vector3d b, double t);

	Vector4f Lerp(Vector4f a, Vector4f b, float t);
	Vector4d Lerp(Vector4d a, Vector4d b, double t);

	float InverseLerp(float a, float b, float x);
	double InverseLerp(double a, double b, double x);

	float InverseLerp(Vector2f a, Vector2f b, Vector2f x);
	double InverseLerp(Vector2d a, Vector2d b, Vector2d x);

	float InverseLerp(Vector3f a, Vector3f b, Vector3f x);
	double InverseLerp(Vector3d a, Vector3d b, Vector3d x);

	float InverseLerp(Vector4f a, Vector4f b, Vector4f x);
	double InverseLerp(Vector4d a, Vector4d b, Vector4d x);
};
#endif