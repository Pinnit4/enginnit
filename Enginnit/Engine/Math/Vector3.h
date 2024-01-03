#ifndef VECTOR3HEADER
#define VECTOR3HEADER

#include <corecrt_math.h>

using namespace std;

struct Vector3 {
	float x;
	float y;
	float z;

	Vector3() { x = 0; y = 0; z = 0; }
	Vector3(float _x, float _y) { x = _x; y = _y; z = 0; }
	Vector3(float _x, float _y, float _z) { x = _x; y = _y; z = _z; }
	Vector3(const Vector3& other) { x = other.x; y = other.y; z = other.z; }

	void Normalize() {
		float length = GetLength();
		if (length != 0) {
			x /= length; y /= length; z /= length;
		}
	}

	Vector3 GetNormalized()
	{
		float length = GetLength();
		if (length != 0)
			return Vector3(x / length, y / length, z / length);
		else
			return Vector3(x, y, z);
	}

	float GetLength() { return (float)sqrt(GetSqrMagnitude()); }
	float GetSqrMagnitude() { return ((x * x) + (y * y) + (z * z)); }

	Vector3& operator +=(const Vector3& a) { x += a.x; y += a.y; z += a.z; return *this; }
	Vector3& operator +(const Vector3& a) { x += a.x; y += a.y; z += a.z; return *this; }

	Vector3& operator -=(const Vector3& a) { x -= a.x; y -= a.y; z -= a.z; return *this; }
	Vector3& operator -(const Vector3& a) { x -= a.x; y -= a.y; z -= a.z; return *this; }

	Vector3& operator *=(const Vector3& a) { x *= a.x; y *= a.y;  z *= a.z; return *this; }
	Vector3& operator *(const Vector3& a) { x *= a.x; y *= a.y;  z *= a.z; return *this; }

	Vector3& operator /=(const Vector3& a) { x /= a.x; y /= a.y;  z /= a.z; return *this; }
	Vector3& operator /(const Vector3& a) { x /= a.x; y /= a.y;  z /= a.z; return *this; }

	Vector3& operator *=(const float a) { x *= a; y *= a;  z *= a; return *this; }
	Vector3& operator *(const float a) { x *= a; y *= a; z *= a; return *this; }

	Vector3& operator /=(const float a) { x /= a; y /= a; z /= a; return *this; }
	Vector3& operator /(const float a) { x /= a; y /= a; z /= a; return *this; }

	bool operator==(const Vector3& a) { return x == a.x && y == a.y && z == a.z; }
	bool operator!=(const Vector3& a) { return !operator==(a); }

	static Vector3 Zero() { return Vector3(0, 0, 0); }
	static Vector3 One() { return Vector3(1, 1, 1); }

	static Vector3 Up() { return Vector3(0, 1, 0); }
	static Vector3 Down() { return Vector3(0, -1, 0); }

	static Vector3 Left() { return Vector3(-1, 0, 0); }
	static Vector3 Right() { return Vector3(1, 0, 0); }

	static Vector3 Forward() { return Vector3(0, 0, 1); }
	static Vector3 Back() { return Vector3(0, 0, -1); }
};

#endif