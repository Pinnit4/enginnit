#ifndef VECTOR2HEADER
#define VECTOR2HEADER

#include <corecrt_math.h>

using namespace std;

struct Vector2 {
	float x;
	float y;

	Vector2() { x = 0; y = 0; }
	Vector2(float _x, float _y) { x = _x; y = _y; }
	Vector2(const Vector2& other) { x = other.x; y = other.y; }

	void Normalize() {
		float length = GetLength();
		if (length != 0) {
			x /= length; y /= length;
		}
	}

	Vector2 GetNormalized()
	{
		float length = GetLength();
		if (length != 0)
			return Vector2(x / length, y / length);
		else
			return Vector2(x, y);
	}

	float GetLength() { return (float)sqrt(GetSqrMagnitude()); }
	float GetSqrMagnitude() { return ((x * x) + (y * y)); }

	Vector2& operator +=(const Vector2& a) { x += a.x; y += a.y; return *this; }
	Vector2& operator +(const Vector2& a) { x += a.x; y += a.y; return *this; }

	Vector2& operator -=(const Vector2& a) { x -= a.x; y -= a.y; return *this; }
	Vector2& operator -(const Vector2& a) { x -= a.x; y -= a.y; return *this; }

	Vector2& operator *=(const Vector2& a) { x *= a.x; y *= a.y; return *this; }
	Vector2& operator *(const Vector2& a) { x *= a.x; y *= a.y; return *this; }

	Vector2& operator /=(const Vector2& a) { x /= a.x; y /= a.y; return *this; }
	Vector2& operator /(const Vector2& a) { x /= a.x; y /= a.y; return *this; }

	Vector2& operator *=(const float a) { x *= a; y *= a; return *this; }
	Vector2& operator *(const float a) { x *= a; y *= a; return *this; }

	Vector2& operator /=(const float a) { x /= a; y /= a; return *this; }
	Vector2& operator /(const float a) { x /= a; y /= a; return *this; }

	bool operator==(const Vector2& a) { return x == a.x && y == a.y; }
	bool operator!=(const Vector2& a) { return !operator==(a); }

	static Vector2 Zero() { return Vector2(0, 0); }
	static Vector2 One() { return Vector2(1, 1); }

	static Vector2 Up() { return Vector2(0, 1); }
	static Vector2 Down() { return Vector2(0, -1); }
	static Vector2 Left() { return Vector2(-1, 0); }
	static Vector2 Right() { return Vector2(1, 0); }
};

struct Vector2Double {
	double x;
	double y;

	Vector2Double() { x = 0; y = 0; }
	Vector2Double(float _x, float _y) { x = _x; y = _y; }
	Vector2Double(const Vector2Double& other) { x = other.x; y = other.y; }

	void Normalize() {
		float length = GetLength();
		if (length != 0) {
			x /= length; y /= length;
		}
	}

	Vector2Double GetNormalized()
	{
		float length = GetLength();
		if (length != 0)
			return Vector2Double(x / length, y / length);
		else
			return Vector2Double(x, y);
	}

	double GetLength() { return sqrt(GetSqrMagnitude()); }
	double GetSqrMagnitude() { return ((x * x) + (y * y)); }

	Vector2Double& operator +=(const Vector2Double& a) { x += a.x; y += a.y; return *this; }
	Vector2Double& operator +(const Vector2Double& a) { x += a.x; y += a.y; return *this; }

	Vector2Double& operator -=(const Vector2Double& a) { x -= a.x; y -= a.y; return *this; }
	Vector2Double& operator -(const Vector2Double& a) { x -= a.x; y -= a.y; return *this; }

	Vector2Double& operator *=(const Vector2Double& a) { x *= a.x; y *= a.y; return *this; }
	Vector2Double& operator *(const Vector2Double& a) { x *= a.x; y *= a.y; return *this; }

	Vector2Double& operator /=(const Vector2Double& a) { x /= a.x; y /= a.y; return *this; }
	Vector2Double& operator /(const Vector2Double& a) { x /= a.x; y /= a.y; return *this; }

	Vector2Double& operator *=(const double a) { x *= a; y *= a; return *this; }
	Vector2Double& operator *(const double a) { x *= a; y *= a; return *this; }

	Vector2Double& operator /=(const double a) { x /= a; y /= a; return *this; }
	Vector2Double& operator /(const double a) { x /= a; y /= a; return *this; }

	bool operator==(const Vector2Double& a) { return x == a.x && y == a.y; }
	bool operator!=(const Vector2Double& a) { return !operator==(a); }

	static Vector2Double Zero() { return Vector2Double(0, 0); }
	static Vector2Double One() { return Vector2Double(1, 1); }

	static Vector2Double Up() { return Vector2Double(0, 1); }
	static Vector2Double Down() { return Vector2Double(0, -1); }
	static Vector2Double Left() { return Vector2Double(-1, 0); }
	static Vector2Double Right() { return Vector2Double(1, 0); }
};

struct Vector2Int {
	int x;
	int y;

	Vector2Int() { x = 0; y = 0; }
	Vector2Int(int _x, int _y) { x = _x; y = _y; }
	Vector2Int(const Vector2Int& other) { x = other.x; y = other.y; }

	float GetLength() { return (float)sqrt(GetSqrMagnitude()); }
	float GetSqrMagnitude() { return ((x * x) + (y * y)); }

	Vector2Int& operator +=(const Vector2Int& a) { x += a.x; y += a.y; return *this; }
	Vector2Int& operator +(const Vector2Int& a) { x += a.x; y += a.y; return *this; }

	Vector2Int& operator -=(const Vector2Int& a) { x -= a.x; y -= a.y; return *this; }
	Vector2Int& operator -(const Vector2Int& a) { x -= a.x; y -= a.y; return *this; }

	Vector2Int& operator *=(const Vector2Int& a) { x *= a.x; y *= a.y; return *this; }
	Vector2Int& operator *(const Vector2Int& a) { x *= a.x; y *= a.y; return *this; }

	Vector2Int& operator /=(const Vector2Int& a) { x /= a.x; y /= a.y; return *this; }
	Vector2Int& operator /(const Vector2Int& a) { x /= a.x; y /= a.y; return *this; }

	Vector2Int& operator *=(const float a) { x *= a; y *= a; return *this; }
	Vector2Int& operator *(const float a) { x *= a; y *= a; return *this; }

	Vector2Int& operator /=(const float a) { x /= a; y /= a; return *this; }
	Vector2Int& operator /(const float a) { x /= a; y /= a; return *this; }

	bool operator==(const Vector2Int& a) { return x == a.x && y == a.y; }
	bool operator!=(const Vector2Int& a) { return !operator==(a); }

	static Vector2Int Zero() { return Vector2Int(0, 0); }
	static Vector2Int One() { return Vector2Int(1, 1); }

	static Vector2Int Up() { return Vector2Int(0, 1); }
	static Vector2Int Down() { return Vector2Int(0, -1); }
	static Vector2Int Left() { return Vector2Int(-1, 0); }
	static Vector2Int Right() { return Vector2Int(1, 0); }
};

#endif