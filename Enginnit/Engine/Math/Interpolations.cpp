#include "Interpolations.h"

float Math::Lerp(float a, float b, float t) { return a * (1.0 - t) + (b * t); }
double Math::Lerp(double a, double b, double t) { return a * (1.0 - t) + (b * t); }

Vector2f Math::Lerp(Vector2f a, Vector2f b, float t) { return Vector2f(Lerp(a.x, b.x, t), Lerp(a.y, b.y, t)); }
Vector2d Math::Lerp(Vector2d a, Vector2d b, double t) { return Vector2d(Lerp(a.x, b.x, t), Lerp(a.y, b.y, t)); }

Vector3f Math::Lerp(Vector3f a, Vector3f b, float t) { return Vector3f(Lerp(a.x, b.x, t), Lerp(a.y, b.y, t), Lerp(a.z, b.z, t)); }
Vector3d Math::Lerp(Vector3d a, Vector3d b, double t) { return Vector3d(Lerp(a.x, b.x, t), Lerp(a.y, b.y, t), Lerp(a.z, b.z, t)); }

Vector4f Math::Lerp(Vector4f a, Vector4f b, float t) { return Vector4f(Lerp(a.x, b.x, t), Lerp(a.y, b.y, t), Lerp(a.z, b.z, t), Lerp(a.w, b.w, t)); }
Vector4d Math::Lerp(Vector4d a, Vector4d b, double t) { return Vector4d(Lerp(a.x, b.x, t), Lerp(a.y, b.y, t), Lerp(a.z, b.z, t), Lerp(a.w, b.w, t)); }

float Math::InverseLerp(float a, float b, float x) { return (x - a) / (b - a); }
double Math::InverseLerp(double a, double b, double x) { return (x - a) / (b - a); }

float Math::InverseLerp(Vector2f a, Vector2f b, Vector2f x) { return ((x - a).GetSqrMagnitude() / (b - a).GetSqrMagnitude()); }
double Math::InverseLerp(Vector2d a, Vector2d b, Vector2d x) { return ((x - a).GetSqrMagnitude() / (b - a).GetSqrMagnitude()); }

float Math::InverseLerp(Vector3f a, Vector3f b, Vector3f x) { return ((x - a).GetSqrMagnitude() / (b - a).GetSqrMagnitude()); }
double Math::InverseLerp(Vector3d a, Vector3d b, Vector3d x) { return ((x - a).GetSqrMagnitude() / (b - a).GetSqrMagnitude()); }

float Math::InverseLerp(Vector4f a, Vector4f b, Vector4f x) { return ((x - a).GetSqrMagnitude() / (b - a).GetSqrMagnitude()); }
double Math::InverseLerp(Vector4d a, Vector4d b, Vector4d x) { return ((x - a).GetSqrMagnitude() / (b - a).GetSqrMagnitude()); }