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

#endif