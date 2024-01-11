#ifndef VECTOR4HEADER
#define VECTOR4HEADER

#include <corecrt_math.h>

using namespace std;

struct Vector4f {
	float x;
	float y;
	float z;
	float w;

	Vector4f() { x = 0; y = 0; z = 0; w = 0; }
	Vector4f(float _x, float _y) { x = _x; y = _y; z = 0; w = 0; }
	Vector4f(float _x, float _y, float _z) { x = _x; y = _y; z = _z; w = 0; }
	Vector4f(float _x, float _y, float _z, float _w) { x = _x; y = _y; z = _z; w = _w; }
	Vector4f(const Vector4f& other) { x = other.x; y = other.y; z = other.z; w = other.w; }

	void Normalize() {
		float length = GetLength();
		if (length != 0) {
			x /= length; y /= length; z /= length;
		}
	}

	Vector4f GetNormalized()
	{
		float length = GetLength();
		if (length != 0)
			return Vector4f(x / length, y / length, z / length, w / length);
		else
			return Vector4f(x, y, z, w);
	}

	float GetLength() { return (float)sqrt(GetSqrMagnitude()); }
	float GetSqrMagnitude() { return ((x * x) + (y * y) + (z * z) + (w * w)); }

	Vector4f& operator +=(const Vector4f& a) { x += a.x; y += a.y; z += a.z; w += a.w; return *this; }
	Vector4f& operator +(const Vector4f& a) { Vector4f v = Vector4f(x + a.x, y + a.y, z + a.z, w + a.w); return v; }
	Vector4f& operator +(const Vector4f& a) const { Vector4f v = Vector4f(x + a.x, y + a.y, z + a.z, w + a.w); return v; }

	Vector4f& operator -=(const Vector4f& a) { x -= a.x; y -= a.y; z -= a.z; w -= a.w; return *this; }
	Vector4f& operator -(const Vector4f& a) { Vector4f v = Vector4f(x - a.x, y - a.y, z - a.z, w - a.w); return v; }
	Vector4f& operator -(const Vector4f& a) const { Vector4f v = Vector4f(x - a.x, y - a.y, z - a.z, w - a.w); return v; }

	Vector4f& operator *=(const Vector4f& a) { x *= a.x; y *= a.y;  z *= a.z; w *= a.w; return *this; }
	Vector4f& operator *(const Vector4f& a) { Vector4f v = Vector4f(x * a.x, y * a.y, z * a.z, w * a.w); return v; }
	Vector4f& operator *(const Vector4f& a) const { Vector4f v = Vector4f(x * a.x, y * a.y, z * a.z, w * a.w); return v; }

	Vector4f& operator /=(const Vector4f& a) { x /= a.x; y /= a.y;  z /= a.z; w /= a.w; return *this; }
	Vector4f& operator /(const Vector4f& a) { Vector4f v = Vector4f(x / a.x, y / a.y, z / a.z, w / a.w); return v; }
	Vector4f& operator /(const Vector4f& a) const { Vector4f v = Vector4f(x / a.x, y / a.y, z / a.z, w / a.w); return v; }

	Vector4f& operator *=(const float a) { x *= a; y *= a;  z *= a; w *= a; return *this; }
	Vector4f& operator *(const float a) { Vector4f v = Vector4f(x * a, y * a, z * a, w * a); return v; }
	Vector4f& operator *(const float a) const { Vector4f v = Vector4f(x * a, y * a, z * a, w * a); return v; }

	Vector4f& operator /=(const float a) { x /= a; y /= a; z /= a; w /= a; return *this; }
	Vector4f& operator /(const float a) { Vector4f v = Vector4f(x / a, y / a, z / a, w / a); return v; }
	Vector4f& operator /(const float a) const { Vector4f v = Vector4f(x / a, y / a, z / a, w / a); return v; }

	bool operator==(const Vector4f& a) { return x == a.x && y == a.y && z == a.z && w == a.w; }
	bool operator==(const Vector4f& a) const { return x == a.x && y == a.y && z == a.z && w == a.w; }

	bool operator!=(const Vector4f& a) { return !operator==(a); }
	bool operator!=(const Vector4f& a) const { return !operator==(a); }

	static Vector4f Zero() { return Vector4f(0, 0, 0, 0); }
	static Vector4f One() { return Vector4f(1, 1, 1, 1); }
};

struct Vector4d {
	double x;
	double y;
	double z;
	double w;

	Vector4d() { x = 0; y = 0; z = 0; w = 0; }
	Vector4d(double _x, double _y) { x = _x; y = _y; z = 0; w = 0; }
	Vector4d(double _x, double _y, double _z) { x = _x; y = _y; z = _z; w = 0; }
	Vector4d(double _x, double _y, double _z, double _w) { x = _x; y = _y; z = _z; w = _w; }
	Vector4d(const Vector4d& other) { x = other.x; y = other.y; z = other.z; w = other.w; }

	void Normalize() {
		double length = GetLength();
		if (length != 0) {
			x /= length; y /= length; z /= length;
		}
	}

	Vector4d GetNormalized()
	{
		double length = GetLength();
		if (length != 0)
			return Vector4d(x / length, y / length, z / length, w / length);
		else
			return Vector4d(x, y, z, w);
	}

	double GetLength() { return sqrt(GetSqrMagnitude()); }
	double GetSqrMagnitude() { return ((x * x) + (y * y) + (z * z) + (w * w)); }

	Vector4d& operator +=(const Vector4d& a) { x += a.x; y += a.y; z += a.z; w += a.w; return *this; }
	Vector4d& operator +(const Vector4d& a) { Vector4d v = Vector4d(x + a.x, y + a.y, z + a.z, w + a.w); return v; }
	Vector4d& operator +(const Vector4d& a) const { Vector4d v = Vector4d(x + a.x, y + a.y, z + a.z, w + a.w); return v; }

	Vector4d& operator -=(const Vector4d& a) { x -= a.x; y -= a.y; z -= a.z; w -= a.w; return *this; }
	Vector4d& operator -(const Vector4d& a) { Vector4d v = Vector4d(x - a.x, y - a.y, z - a.z, w - a.w); return v; }
	Vector4d& operator -(const Vector4d& a) const { Vector4d v = Vector4d(x - a.x, y - a.y, z - a.z, w - a.w); return v; }

	Vector4d& operator *=(const Vector4d& a) { x *= a.x; y *= a.y;  z *= a.z; w *= a.w; return *this; }
	Vector4d& operator *(const Vector4d& a) { Vector4d v = Vector4d(x * a.x, y * a.y, z * a.z, w * a.w); return v; }
	Vector4d& operator *(const Vector4d& a) const { Vector4d v = Vector4d(x * a.x, y * a.y, z * a.z, w * a.w); return v; }

	Vector4d& operator /=(const Vector4d& a) { x /= a.x; y /= a.y;  z /= a.z; w /= a.w; return *this; }
	Vector4d& operator /(const Vector4d& a) { Vector4d v = Vector4d(x / a.x, y / a.y, z / a.z, w / a.w); return v; }
	Vector4d& operator /(const Vector4d& a) const { Vector4d v = Vector4d(x / a.x, y / a.y, z / a.z, w / a.w); return v; }

	Vector4d& operator *=(const double a) { x *= a; y *= a;  z *= a; w *= a; return *this; }
	Vector4d& operator *(const double a) { Vector4d v = Vector4d(x * a, y * a, z * a, w * a); return v; }
	Vector4d& operator *(const double a) const { Vector4d v = Vector4d(x * a, y * a, z * a, w * a); return v; }

	Vector4d& operator /=(const double a) { x /= a; y /= a; z /= a; w /= a; return *this; }
	Vector4d& operator /(const double a) { Vector4d v = Vector4d(x / a, y / a, z / a, w / a); return v; }
	Vector4d& operator /(const double a) const { Vector4d v = Vector4d(x / a, y / a, z / a, w / a); return v; }

	bool operator==(const Vector4d& a) { return x == a.x && y == a.y && z == a.z && w == a.w; }
	bool operator==(const Vector4d& a) const { return x == a.x && y == a.y && z == a.z && w == a.w; }

	bool operator!=(const Vector4d& a) { return !operator==(a); }
	bool operator!=(const Vector4d& a) const { return !operator==(a); }

	static Vector4d Zero() { return Vector4d(0, 0, 0, 0); }
	static Vector4d One() { return Vector4d(1, 1, 1, 1); }
};

#endif