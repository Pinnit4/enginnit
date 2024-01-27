#ifndef VECTOR3HEADER
#define VECTOR3HEADER

#include <corecrt_math.h>

using namespace std;

struct Vector3f {
	float x;
	float y;
	float z;

	Vector3f() { x = 0; y = 0; z = 0; }
	Vector3f(float a) { x = a; y = a; z = a; }
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

	float operator [](int i) {
		switch (i) {
		case 1: return y;
		case 2: return z;
		default: return x;
		}
	}

	float operator [](int i) const {
		switch (i) {
		case 1: return y;
		case 2: return z;
		default: return x;
		}
	}

	static Vector3f Up() { return Vector3f(0, 1, 0); }
	static Vector3f Down() { return Vector3f(0, -1, 0); }

	static Vector3f Left() { return Vector3f(-1, 0, 0); }
	static Vector3f Right() { return Vector3f(1, 0, 0); }

	static Vector3f Forward() { return Vector3f(0, 0, 1); }
	static Vector3f Back() { return Vector3f(0, 0, -1); }

	string ToString() { return ("(" + to_string(x) + "," + to_string(y) + "," + to_string(z) + ")"); }
};

struct Vector3d {
	double x;
	double y;
	double z;

	Vector3d() { x = 0; y = 0; z = 0; }
	Vector3d(double a) { x = a; y = a; z = a; }
	Vector3d(double _x, double _y) { x = _x; y = _y; z = 0; }
	Vector3d(double _x, double _y, double _z) { x = _x; y = _y; z = _z; }
	Vector3d(const Vector3d& other) { x = other.x; y = other.y; z = other.z; }

	void Normalize() {
		double length = GetLength();
		if (length != 0) {
			x /= length; y /= length; z /= length;
		}
	}

	Vector3d GetNormalized()
	{
		double length = GetLength();
		if (length != 0)
			return Vector3d(x / length, y / length, z / length);
		else
			return Vector3d(x, y, z);
	}

	double GetLength() { return sqrt(GetSqrMagnitude()); }
	double GetSqrMagnitude() { return ((x * x) + (y * y) + (z * z)); }

	Vector3d& operator +=(const Vector3d& a) { x += a.x; y += a.y; z += a.z; return *this; }
	Vector3d& operator +(const Vector3d& a) { Vector3d v = Vector3d(x + a.x, y + a.y, z + a.z); return v; }
	Vector3d& operator +(const Vector3d& a) const { Vector3d v = Vector3d(x + a.x, y + a.y, z + a.z); return v; }

	Vector3d& operator -=(const Vector3d& a) { x -= a.x; y -= a.y; z -= a.z; return *this; }
	Vector3d& operator -(const Vector3d& a) { Vector3d v = Vector3d(x - a.x, y - a.y, z - a.z); return v; }
	Vector3d& operator -(const Vector3d& a) const { Vector3d v = Vector3d(x - a.x, y - a.y, z - a.z); return v; }

	Vector3d& operator *=(const Vector3d& a) { x *= a.x; y *= a.y;  z *= a.z; return *this; }
	Vector3d& operator *(const Vector3d& a) { Vector3d v = Vector3d(x * a.x, y * a.y, z * a.z); return v; }
	Vector3d& operator *(const Vector3d& a) const { Vector3d v = Vector3d(x * a.x, y * a.y, z * a.z); return v; }

	Vector3d& operator /=(const Vector3d& a) { x /= a.x; y /= a.y;  z /= a.z; return *this; }
	Vector3d& operator /(const Vector3d& a) { Vector3d v = Vector3d(x / a.x, y / a.y, z / a.z); return v; }
	Vector3d& operator /(const Vector3d& a) const { Vector3d v = Vector3d(x / a.x, y / a.y, z / a.z); return v; }

	Vector3d& operator *=(const double a) { x *= a; y *= a;  z *= a; return *this; }
	Vector3d& operator *(const double a) { Vector3d v = Vector3d(x * a, y * a, z * a); return v; }
	Vector3d& operator *(const double a) const { Vector3d v = Vector3d(x * a, y * a, z * a); return v; }

	Vector3d& operator /=(const double a) { x /= a; y /= a; z /= a; return *this; }
	Vector3d& operator /(const double a) { Vector3d v = Vector3d(x / a, y / a, z / a); return v; }
	Vector3d& operator /(const double a) const { Vector3d v = Vector3d(x / a, y / a, z / a); return v; }

	bool operator==(const Vector3d& a) { return x == a.x && y == a.y && z == a.z; }
	bool operator==(const Vector3d& a) const { return x == a.x && y == a.y && z == a.z; }

	bool operator!=(const Vector3d& a) { return !operator==(a); }
	bool operator!=(const Vector3d& a) const { return !operator==(a); }

	double operator [](int i) {
		switch (i) {
		case 1: return y;
		case 2: return z;
		default: return x;
		}
	}

	double operator [](int i) const {
		switch (i) {
		case 1: return y;
		case 2: return z;
		default: return x;
		}
	}

	static Vector3d Up() { return Vector3d(0, 1, 0); }
	static Vector3d Down() { return Vector3d(0, -1, 0); }

	static Vector3d Left() { return Vector3d(-1, 0, 0); }
	static Vector3d Right() { return Vector3d(1, 0, 0); }

	static Vector3d Forward() { return Vector3d(0, 0, 1); }
	static Vector3d Back() { return Vector3d(0, 0, -1); }

	string ToString() { return ("(" + to_string(x) + "," + to_string(y) + "," + to_string(z) + ")"); }
};

struct Vector3i {
	int x;
	int y;
	int z;

	Vector3i() { x = 0; y = 0; z = 0; }
	Vector3i(int a) { x = a; y = a; z = a; }
	Vector3i(int _x, int _y) { x = _x; y = _y; z = 0; }
	Vector3i(int _x, int _y, int _z) { x = _x; y = _y; z = _z; }
	Vector3i(const Vector3i& other) { x = other.x; y = other.y; z = other.z; }

	float GetLength() { return sqrt(GetSqrMagnitude()); }
	int GetSqrMagnitude() { return ((x * x) + (y * y) + (z * z)); }

	Vector3i& operator +=(const Vector3i& a) { x += a.x; y += a.y; z += a.z; return *this; }
	Vector3i& operator +(const Vector3i& a) { Vector3i v = Vector3i(x + a.x, y + a.y, z + a.z); return v; }
	Vector3i& operator +(const Vector3i& a) const { Vector3i v = Vector3i(x + a.x, y + a.y, z + a.z); return v; }

	Vector3i& operator -=(const Vector3i& a) { x -= a.x; y -= a.y; z -= a.z; return *this; }
	Vector3i& operator -(const Vector3i& a) { Vector3i v = Vector3i(x - a.x, y - a.y, z - a.z); return v; }
	Vector3i& operator -(const Vector3i& a) const { Vector3i v = Vector3i(x - a.x, y - a.y, z - a.z); return v; }

	Vector3i& operator *=(const Vector3i& a) { x *= a.x; y *= a.y;  z *= a.z; return *this; }
	Vector3i& operator *(const Vector3i& a) { Vector3i v = Vector3i(x * a.x, y * a.y, z * a.z); return v; }
	Vector3i& operator *(const Vector3i& a) const { Vector3i v = Vector3i(x * a.x, y * a.y, z * a.z); return v; }

	Vector3i& operator /=(const Vector3i& a) { x /= a.x; y /= a.y;  z /= a.z; return *this; }
	Vector3i& operator /(const Vector3i& a) { Vector3i v = Vector3i(x / a.x, y / a.y, z / a.z); return v; }
	Vector3i& operator /(const Vector3i& a) const { Vector3i v = Vector3i(x / a.x, y / a.y, z / a.z); return v; }

	Vector3i& operator *=(const int a) { x *= a; y *= a;  z *= a; return *this; }
	Vector3i& operator *(const int a) { Vector3i v = Vector3i(x * a, y * a, z * a); return v; }
	Vector3i& operator *(const int a) const { Vector3i v = Vector3i(x * a, y * a, z * a); return v; }

	Vector3i& operator /=(const int a) { x /= a; y /= a; z /= a; return *this; }
	Vector3i& operator /(const int a) { Vector3i v = Vector3i(x / a, y / a, z / a); return v; }
	Vector3i& operator /(const int a) const { Vector3i v = Vector3i(x / a, y / a, z / a); return v; }

	bool operator==(const Vector3i& a) { return x == a.x && y == a.y && z == a.z; }
	bool operator==(const Vector3i& a) const { return x == a.x && y == a.y && z == a.z; }

	bool operator!=(const Vector3i& a) { return !operator==(a); }
	bool operator!=(const Vector3i& a) const { return !operator==(a); }

	int operator [](int i) {
		switch (i) {
		case 1: return y;
		case 2: return z;
		default: return x;
		}
	}

	int operator [](int i) const {
		switch (i) {
		case 1: return y;
		case 2: return z;
		default: return x;
		}
	}

	static Vector3i Up() { return Vector3i(0, 1, 0); }
	static Vector3i Down() { return Vector3i(0, -1, 0); }

	static Vector3i Left() { return Vector3i(-1, 0, 0); }
	static Vector3i Right() { return Vector3i(1, 0, 0); }

	static Vector3i Forward() { return Vector3i(0, 0, 1); }
	static Vector3i Back() { return Vector3i(0, 0, -1); }

	string ToString() { return ("(" + to_string(x) + "," + to_string(y) + "," + to_string(z) + ")"); }
};

#endif