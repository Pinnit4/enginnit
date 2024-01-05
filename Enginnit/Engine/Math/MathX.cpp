#include "MathX.h"

float MathX::Lerp(float a, float b, float t) {
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

Vector2 MathX::InverseLerp(Vector2 a, Vector2 b, float x) {
	return Vector2(InverseLerp(a.x, b.x, x), InverseLerp(a.y, b.y, x));
}
Vector3 MathX::InverseLerp(Vector3 a, Vector3 b, float x) {
	return Vector3(InverseLerp(a.x, b.x, x), InverseLerp(a.y, b.y, x), InverseLerp(a.z, b.z, x));
}
Vector4 MathX::InverseLerp(Vector4 a, Vector4 b, float x) {
	return Vector4(InverseLerp(a.x, b.x, x), InverseLerp(a.y, b.y, x), InverseLerp(a.z, b.z, x), InverseLerp(a.w, b.w, x));
}