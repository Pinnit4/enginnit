#include "Math.h"

float Math::Lerp(float a, float b, float t) { return a * (1.0 - t) + (b * t); }
double Math::Lerp(double a, double b, double t) { return a * (1.0 - t) + (b * t); }

Vector2f Math::Lerp(Vector2f a, Vector2f b, float t) { return Vector2f(Lerp(a.x, b.x, t), Lerp(a.y, b.y, t)); }
Vector3f Math::Lerp(Vector3f a, Vector3f b, float t) { return Vector3f(Lerp(a.x, b.x, t), Lerp(a.y, b.y, t), Lerp(a.z, b.z, t)); }
Vector4 Math::Lerp(Vector4 a, Vector4 b, float t) { return Vector4(Lerp(a.x, b.x, t), Lerp(a.y, b.y, t), Lerp(a.z, b.z, t), Lerp(a.w, b.w, t)); }

float Math::InverseLerp(float a, float b, float x) { return (x - a) / (b - x); }
double Math::InverseLerp(double a, double b, double x) { return (x - a) / (b - x); }

Vector2f Math::InverseLerp(Vector2f a, Vector2f b, float x) { return Vector2f(InverseLerp(a.x, b.x, x), InverseLerp(a.y, b.y, x)); }
Vector3f Math::InverseLerp(Vector3f a, Vector3f b, float x) { return Vector3f(InverseLerp(a.x, b.x, x), InverseLerp(a.y, b.y, x), InverseLerp(a.z, b.z, x)); }
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

float Math::Max(vector<float> values) {
	float max = values[0];
	for (int i = 1; i < values.size(); i++) {
		max = Max(max, values[i]);
	}
	return max;
}
float Math::Min(vector<float> values) {
	float min = values[0];
	for (int i = 1; i < values.size(); i++) {
		min = Min(min, values[i]);
	}
	return min;
}
float Math::Max(float a, float b) { if (a > b) return a; return b; }
float Math::Min(float a, float b) { if (a < b) return a; return b; }

double Math::Max(vector<double> values) {
	double max = values[0];
	for (int i = 1; i < values.size(); i++) {
		max = Max(max, values[i]);
	}
	return max;
}
double Math::Min(vector<double> values) {
	double min = values[0];
	for (int i = 1; i < values.size(); i++) {
		min = Min(min, values[i]);
	}
	return min;
}
double Math::Max(double a, double b) { if (a > b) return a; return b; }
double Math::Min(double a, double b) { if (a < b) return a; return b; }

int Math::Max(vector<int> values) {
	int max = values[0];
	for (int i = 1; i < values.size(); i++) {
		max = Max(max, values[i]);
	}
	return max;
}
int Math::Min(vector<int> values) {
	int min = values[0];
	for (int i = 1; i < values.size(); i++) {
		min = Min(min, values[i]);
	}
	return min;
}
int Math::Max(int a, int b) { if (a > b) return a; return b; }
int Math::Min(int a, int b) { if (a < b) return a; return b; }

double Math::ConvertToRadians(double degrees) { return (degrees * PI) / 180.0; }
double Math::ConvertToDegrees(double radians) { return (radians * 180.0) / PI; }

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