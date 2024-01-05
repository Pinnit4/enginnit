#include "MathX.h"

float MathX::Lerp(float a, float b, float t) {
	return a * (1.0 - t) + (b * t);
}
double MathX::Lerp(double a, double b, double t) {
	return a * (1.0 - t) + (b * t);
}

Vector2 MathX::Lerp(Vector2 a, Vector2 b, float t) {
	return Vector2(Lerp(a.x, b.x, t), Lerp(a.y, b.y, t));
}
Vector3 MathX::Lerp(Vector3 a, Vector3 b, float t) {
	return Vector3(Lerp(a.x, b.x, t), Lerp(a.y, b.y, t), Lerp(a.z, b.z, t));
}
Vector4 MathX::Lerp(Vector4 a, Vector4 b, float t) {
	return Vector4(Lerp(a.x, b.x, t), Lerp(a.y, b.y, t), Lerp(a.z, b.z, t), Lerp(a.w, b.w, t));
}

float MathX::InverseLerp(float a, float b, float x) {
	return (x - a) / (b - x);
}
double MathX::InverseLerp(double a, double b, double x) {
	return (x - a) / (b - x);
}

Vector2 MathX::InverseLerp(Vector2 a, Vector2 b, float x) {
	return Vector2(InverseLerp(a.x, b.x, x), InverseLerp(a.y, b.y, x));
}
Vector3 MathX::InverseLerp(Vector3 a, Vector3 b, float x) {
	return Vector3(InverseLerp(a.x, b.x, x), InverseLerp(a.y, b.y, x), InverseLerp(a.z, b.z, x));
}
Vector4 MathX::InverseLerp(Vector4 a, Vector4 b, float x) {
	return Vector4(InverseLerp(a.x, b.x, x), InverseLerp(a.y, b.y, x), InverseLerp(a.z, b.z, x), InverseLerp(a.w, b.w, x));
}

float MathX::Clamp(float value, float min, float max) {
	if (value < min) return min;
	if (value > max) return max;
	return value;
}
double MathX::Clamp(double value, double min, double max) {
	if (value < min) return min;
	if (value > max) return max;
	return value;
}
int MathX::Clamp(int value, int min, int max) {
	if (value < min) return min;
	if (value >= max) return max;
	return value;
}

float MathX::Repeat(float value, float min, float max) {
	if (value < min) return max;
	if (value > max) return min;
	return value;
}
double MathX::Repeat(double value, double min, double max) {
	if (value < min) return max;
	if (value > max) return min;
	return value;
}
int MathX::Repeat(int value, int min, int max) {
	if (value < min) return max;
	if (value >= max) return min;
	return value;
}