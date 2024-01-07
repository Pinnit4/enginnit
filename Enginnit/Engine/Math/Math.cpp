#include "Math.h"

float Math::Lerp(float a, float b, float t) { return a * (1.0 - t) + (b * t); }
double Math::Lerp(double a, double b, double t) { return a * (1.0 - t) + (b * t); }

Vector2 Math::Lerp(Vector2 a, Vector2 b, float t) { return Vector2(Lerp(a.x, b.x, t), Lerp(a.y, b.y, t)); }
Vector3 Math::Lerp(Vector3 a, Vector3 b, float t) { return Vector3(Lerp(a.x, b.x, t), Lerp(a.y, b.y, t), Lerp(a.z, b.z, t)); }
Vector4 Math::Lerp(Vector4 a, Vector4 b, float t) { return Vector4(Lerp(a.x, b.x, t), Lerp(a.y, b.y, t), Lerp(a.z, b.z, t), Lerp(a.w, b.w, t)); }

float Math::InverseLerp(float a, float b, float x) { return (x - a) / (b - x); }
double Math::InverseLerp(double a, double b, double x) { return (x - a) / (b - x); }

Vector2 Math::InverseLerp(Vector2 a, Vector2 b, float x) { return Vector2(InverseLerp(a.x, b.x, x), InverseLerp(a.y, b.y, x)); }
Vector3 Math::InverseLerp(Vector3 a, Vector3 b, float x) { return Vector3(InverseLerp(a.x, b.x, x), InverseLerp(a.y, b.y, x), InverseLerp(a.z, b.z, x)); }
Vector4 Math::InverseLerp(Vector4 a, Vector4 b, float x) { return Vector4(InverseLerp(a.x, b.x, x), InverseLerp(a.y, b.y, x), InverseLerp(a.z, b.z, x), InverseLerp(a.w, b.w, x)); }

float Math::Clamp(float value, float min, float max) {
	if (value < min) return min;
	if (value > max) return max;
	return value;
}
double Math::Clamp(double value, double min, double max) {
	if (value < min) return min;
	if (value > max) return max;
	return value;
}
int Math::Clamp(int value, int min, int max) {
	if (value < min) return min;
	if (value >= max) return max;
	return value;
}

float Math::Repeat(float value, float min, float max) {
	if (value < min) return max;
	if (value > max) return min;
	return value;
}
double Math::Repeat(double value, double min, double max) {
	if (value < min) return max;
	if (value > max) return min;
	return value;
}
int Math::Repeat(int value, int min, int max) {
	if (value < min) return max;
	if (value >= max) return min;
	return value;
}

double Math::ConvertToRadians(double degrees) { return (degrees * PI) / 180.0; }
double Math::ConvertToDegrees(double radians) { return (radians * 180.0) / PI; }

Vector2 Math::RotatePoint(Vector2 point, Vector2 pivot, float angle) {
	double rad = ConvertToRadians(angle);

	double s = sin(rad);
	double c = cos(rad);

	point -= pivot;

	point.x = (float)(point.x * c - point.y * s);
	point.y = (float)(point.x * s + point.y * c);

	point += pivot;

	return point;
}