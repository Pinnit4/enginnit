#ifndef VECTOR3HEADER
#define VECTOR3HEADER

#include <corecrt_math.h>

using namespace std;

struct Vector3f {
	float x;
	float y;
	float z;

	Vector3f() { x = 0; y = 0; z = 0; }
	Vector3f(float _x, float _y) { x = _x; y = _y; z = 0; }
	Vector3f(float _x, float _y, float _z) { x = _x; y = _y; z = _z; }
	Vector3f(const Vector3f& other) { x = other.x; y = other.y; z = other.z; }

	void Normalize() {
		float length = GetLength();
		if (length != 0) {
			x /= length; y /= length; z /= length;
		}
	}

	Vector3f GetNormalized()
	{
		float length = GetLength();
		if (length != 0)
			return Vector3f(x / length, y / length, z / length);
		else
			return Vector3f(x, y, z);
	}

	float GetLength() { return (float)sqrt(GetSqrMagnitude()); }
	float GetSqrMagnitude() { return ((x * x) + (y * y) + (z * z)); }

	Vector3f& operator +=(const Vector3f& a) { x += a.x; y += a.y; z += a.z; return *this; }
	Vector3f& operator +(const Vector3f& a) { Vector3f v = Vector3f(x + a.x, y + a.y, z + a.z); return v; }
	Vector3f& operator +(const Vector3f& a) const { Vector3f v = Vector3f(x + a.x, y + a.y, z + a.z); return v; }

	Vector3f& operator -=(const Vector3f& a) { x -= a.x; y -= a.y; z -= a.z; return *this; }
	Vector3f& operator -(const Vector3f& a) { Vector3f v = Vector3f(x - a.x, y - a.y, z - a.z); return v; }
	Vector3f& operator -(const Vector3f& a) const { Vector3f v = Vector3f(x - a.x, y - a.y, z - a.z); return v; }

	Vector3f& operator *=(const Vector3f& a) { x *= a.x; y *= a.y;  z *= a.z; return *this; }
	Vector3f& operator *(const Vector3f& a) { Vector3f v = Vector3f(x * a.x, y * a.y, z * a.z); return v; }
	Vector3f& operator *(const Vector3f& a) const { Vector3f v = Vector3f(x * a.x, y * a.y, z * a.z); return v; }

	Vector3f& operator /=(const Vector3f& a) { x /= a.x; y /= a.y;  z /= a.z; return *this; }
	Vector3f& operator /(const Vector3f& a) { Vector3f v = Vector3f(x / a.x, y / a.y, z / a.z); return v; }
	Vector3f& operator /(const Vector3f& a) const { Vector3f v = Vector3f(x / a.x, y / a.y, z / a.z); return v; }

	Vector3f& operator *=(const float a) { x *= a; y *= a;  z *= a; return *this; }
	Vector3f& operator *(const float a) { Vector3f v = Vector3f(x * a, y * a, z * a); return v; }
	Vector3f& operator *(const float a) const { Vector3f v = Vector3f(x * a, y * a, z * a); return v; }

	Vector3f& operator /=(const float a) { x /= a; y /= a; z /= a; return *this; }
	Vector3f& operator /(const float a) { Vector3f v = Vector3f(x / a, y / a, z / a); return v; }
	Vector3f& operator /(const float a) const { Vector3f v = Vector3f(x / a, y / a, z / a); return v; }

	bool operator==(const Vector3f& a) { return x == a.x && y == a.y && z == a.z; }
	bool operator==(const Vector3f& a) const { return x == a.x && y == a.y && z == a.z; }

	bool operator!=(const Vector3f& a) { return !operator==(a); }
	bool operator!=(const Vector3f& a) const { return !operator==(a); }

	static Vector3f Zero() { return Vector3f(0, 0, 0); }
	static Vector3f One() { return Vector3f(1, 1, 1); }

	static Vector3f Up() { return Vector3f(0, 1, 0); }
	static Vector3f Down() { return Vector3f(0, -1, 0); }

	static Vector3f Left() { return Vector3f(-1, 0, 0); }
	static Vector3f Right() { return Vector3f(1, 0, 0); }

	static Vector3f Forward() { return Vector3f(0, 0, 1); }
	static Vector3f Back() { return Vector3f(0, 0, -1); }
};

#endif