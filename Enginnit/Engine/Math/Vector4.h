#ifndef VECTOR4HEADER
#define VECTOR4HEADER

#include <corecrt_math.h>

using namespace std;

struct Vector4 {
	float x;
	float y;
	float z;
	float w;

	Vector4() { x = 0; y = 0; z = 0; w = 0; }
	Vector4(float _x, float _y) { x = _x; y = _y; z = 0; w = 0; }
	Vector4(float _x, float _y, float _z) { x = _x; y = _y; z = _z; w = 0; }
	Vector4(float _x, float _y, float _z, float _w) { x = _x; y = _y; z = _z; w = _w; }
	Vector4(const Vector4& other) { x = other.x; y = other.y; z = other.z; w = other.w; }

	void Normalize() {
		float length = GetLength();
		if (length != 0) {
			x /= length; y /= length; z /= length;
		}
	}

	Vector4 GetNormalized()
	{
		float length = GetLength();
		if (length != 0)
			return Vector4(x / length, y / length, z / length, w / length);
		else
			return Vector4(x, y, z, w);
	}

	float GetLength() { return (float)sqrt(GetSqrMagnitude()); }
	float GetSqrMagnitude() { return ((x * x) + (y * y) + (z * z) + (w * w)); }

	Vector4& operator +=(const Vector4& a) { x += a.x; y += a.y; z += a.z; w += a.w; return *this; }
	Vector4& operator +(const Vector4& a) { Vector4 v = Vector4(x + a.x, y + a.y, z + a.z, w + a.w); return v; }
	Vector4& operator +(const Vector4& a) const { Vector4 v = Vector4(x + a.x, y + a.y, z + a.z, w + a.w); return v; }

	Vector4& operator -=(const Vector4& a) { x -= a.x; y -= a.y; z -= a.z; w -= a.w; return *this; }
	Vector4& operator -(const Vector4& a) { Vector4 v = Vector4(x - a.x, y - a.y, z - a.z, w - a.w); return v; }
	Vector4& operator -(const Vector4& a) const { Vector4 v = Vector4(x - a.x, y - a.y, z - a.z, w - a.w); return v; }

	Vector4& operator *=(const Vector4& a) { x *= a.x; y *= a.y;  z *= a.z; w *= a.w; return *this; }
	Vector4& operator *(const Vector4& a) { Vector4 v = Vector4(x * a.x, y * a.y, z * a.z, w * a.w); return v; }
	Vector4& operator *(const Vector4& a) const { Vector4 v = Vector4(x * a.x, y * a.y, z * a.z, w * a.w); return v; }

	Vector4& operator /=(const Vector4& a) { x /= a.x; y /= a.y;  z /= a.z; w /= a.w; return *this; }
	Vector4& operator /(const Vector4& a) { Vector4 v = Vector4(x / a.x, y / a.y, z / a.z, w / a.w); return v; }
	Vector4& operator /(const Vector4& a) const { Vector4 v = Vector4(x / a.x, y / a.y, z / a.z, w / a.w); return v; }

	Vector4& operator *=(const float a) { x *= a; y *= a;  z *= a; w *= a; return *this; }
	Vector4& operator *(const float a) { Vector4 v = Vector4(x * a, y * a, z * a, w * a); return v; }
	Vector4& operator *(const float a) const { Vector4 v = Vector4(x * a, y * a, z * a, w * a); return v; }

	Vector4& operator /=(const float a) { x /= a; y /= a; z /= a; w /= a; return *this; }
	Vector4& operator /(const float a) { Vector4 v = Vector4(x / a, y / a, z / a, w / a); return v; }
	Vector4& operator /(const float a) const { Vector4 v = Vector4(x / a, y / a, z / a, w / a); return v; }

	bool operator==(const Vector4& a) { return x == a.x && y == a.y && z == a.z && w == a.w; }
	bool operator==(const Vector4& a) const { return x == a.x && y == a.y && z == a.z && w == a.w; }

	bool operator!=(const Vector4& a) { return !operator==(a); }
	bool operator!=(const Vector4& a) const { return !operator==(a); }

	static Vector4 Zero() { return Vector4(0, 0, 0, 0); }
	static Vector4 One() { return Vector4(1, 1, 1, 1); }
};

#endif