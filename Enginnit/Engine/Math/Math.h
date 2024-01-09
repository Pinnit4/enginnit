#ifndef ENGINNIT_MATH
#define ENGINNIT_MATH

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

#define PI 3.14159265

#include <math.h>
#include <vector>

namespace Math {
	float Lerp(float a, float b, float t);
	double Lerp(double a, double b, double t);

	Vector2f Lerp(Vector2f a, Vector2f b, float t);
	Vector3f Lerp(Vector3f a, Vector3f b, float t);
	Vector4 Lerp(Vector4 a, Vector4 b, float t);

	float InverseLerp(float a, float b, float x);
	double InverseLerp(double a, double b, double x);

	Vector2f InverseLerp(Vector2f a, Vector2f b, float x);
	Vector3f InverseLerp(Vector3f a, Vector3f b, float x);
	Vector4 InverseLerp(Vector4 a, Vector4 b, float x);

	float Clamp(float value, float min, float max);
	double Clamp(double value, double min, double max);
	int Clamp(int value, int min, int max);

	float Repeat(float value, float min, float max);
	double Repeat(double value, double min, double max);
	int Repeat(int value, int min, int max);

	double ConvertToRadians(double degrees);
	double ConvertToDegrees(double radians);

	float Max(vector<float> values);
	float Min(vector<float> values);

	float Max(float a, float b);
	float Min(float a, float b);

	double Max(vector<double> values);
	double Min(vector<double> values);

	double Max(double a, double b);
	double Min(double a, double b);

	int Max(vector<int> values);
	int Min(vector<int> values);

	int Max(int a, int b);
	int Min(int a, int b);

	Vector2f RotatePoint(Vector2f point, Vector2f pivot, float angle);
};
#endif