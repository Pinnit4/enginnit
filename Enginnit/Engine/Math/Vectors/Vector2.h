#ifndef VECTOR2HEADER
#define VECTOR2HEADER

#include <corecrt_math.h>
#include <string>

using namespace std;

struct Vector2f {
	float x;
	float y;

	Vector2f() { x = 0; y = 0; }
	Vector2f(float a) { x = a; y = a; }
	Vector2f(float _x, float _y) { x = _x; y = _y; }
	Vector2f(const Vector2f& other) { x = other.x; y = other.y; }

	static float Dot(const Vector2f& a, const Vector2f& b) { return (a.x * b.x) + (a.y * b.y); }

	static Vector2f Project(const Vector2f& a, const Vector2f& b) {
		float dot = Dot(a, b);
		float x = ((b.x * b.x) + (b.y * b.y));
		return Vector2f((dot / x) * b.x, (dot / x) * b.y);
	}

	void Normalize() {
		float length = (float)GetLength();
		if (length != 0) {
			x /= length; y /= length;
		}
	}

	Vector2f GetNormalized()
	{
		float length = (float)GetLength();
		if (length != 0)
			return Vector2f(x / length, y / length);
		else
			return Vector2f(x, y);
	}

	float GetLength() { return (float)sqrt(GetSqrMagnitude()); }
	float GetSqrMagnitude() { return ((x * x) + (y * y)); }

	//Vector2f& operator =(const Vector2f& a) { x = a.x; y = a.y; return *this; }

	Vector2f& operator +=(const Vector2f& a) { x += a.x; y += a.y; return *this; }
	Vector2f& operator +(const Vector2f& a) { Vector2f v = Vector2f(x + a.x, y + a.y); return v; }
	Vector2f& operator +(const Vector2f& a) const { Vector2f v = Vector2f(x + a.x, y + a.y); return v; }

	Vector2f& operator -=(const Vector2f& a) { x -= a.x; y -= a.y; return *this; }
	Vector2f& operator -(const Vector2f& a) { Vector2f v = Vector2f(x - a.x, y - a.y); return v; }
	Vector2f& operator -(const Vector2f& a) const { Vector2f v = Vector2f(x - a.x, y - a.y); return v; }

	Vector2f& operator *=(const Vector2f& a) { x *= a.x; y *= a.y; return *this; }
	Vector2f& operator *(const Vector2f& a) { Vector2f v = Vector2f(x * a.x, y * a.y); return v; }
	Vector2f& operator *(const Vector2f& a) const { Vector2f v = Vector2f(x * a.x, y * a.y); return v; }

	Vector2f& operator /=(const Vector2f& a) { x /= a.x; y /= a.y; return *this; }
	Vector2f& operator /(const Vector2f& a) { Vector2f v = Vector2f(x / a.x, y / a.y); return v; }
	Vector2f& operator /(const Vector2f& a) const { Vector2f v = Vector2f(x / a.x, y / a.y); return v; }

	Vector2f& operator *=(const float a) { x *= a; y *= a; return *this; }
	Vector2f& operator *(const float a) { Vector2f v = Vector2f(x * a, y * a); return v; }
	Vector2f& operator *(const float a) const { Vector2f v = Vector2f(x * a, y * a); return v; }

	Vector2f& operator /=(const float a) { x /= a; y /= a; return *this; }
	Vector2f& operator /(const float a) { Vector2f v = Vector2f(x / a, y / a); return v; }
	Vector2f& operator /(const float a) const { Vector2f v = Vector2f(x / a, y / a); return v; }

	bool operator==(const Vector2f& a) { return x == a.x && y == a.y; }
	bool operator==(const Vector2f& a) const { return x == a.x && y == a.y; }

	bool operator!=(const Vector2f& a) { return !operator==(a); }
	bool operator!=(const Vector2f& a) const { return !operator==(a); }

	static Vector2f Zero() { return Vector2f(0, 0); }
	static Vector2f One() { return Vector2f(1, 1); }

	static Vector2f Up() { return Vector2f(0, 1); }
	static Vector2f Down() { return Vector2f(0, -1); }
	static Vector2f Left() { return Vector2f(-1, 0); }
	static Vector2f Right() { return Vector2f(1, 0); }

	string ToString() { return ("(" + to_string(x) + "," + to_string(y) + ")"); }
};

struct Vector2d {
	double x;
	double y;

	Vector2d() { x = 0; y = 0; }
	Vector2d(double _x, double _y) { x = _x; y = _y; }
	Vector2d(const Vector2d& other) { x = other.x; y = other.y; }

	void Normalize() {
		double length = GetLength();
		if (length != 0) {
			x /= length; y /= length;
		}
	}

	Vector2d GetNormalized()
	{
		double length = GetLength();
		if (length != 0)
			return Vector2d(x / length, y / length);
		else
			return Vector2d(x, y);
	}

	double GetLength() { return sqrt(GetSqrMagnitude()); }
	double GetSqrMagnitude() { return ((x * x) + (y * y)); }

	//Vector2d& operator =(const Vector2d& a) { x = a.x; y = a.y; return *this; }

	Vector2d& operator +=(const Vector2d& a) { x += a.x; y += a.y; return *this; }
	Vector2d& operator +(const Vector2d& a) { Vector2d v = Vector2d(x + a.x, y + a.y); return v; }
	Vector2d& operator +(const Vector2d& a) const { Vector2d v = Vector2d(x + a.x, y + a.y); return v; }

	Vector2d& operator -=(const Vector2d& a) { x -= a.x; y -= a.y; return *this; }
	Vector2d& operator -(const Vector2d& a) { Vector2d v = Vector2d(x - a.x, y - a.y); return v; }
	Vector2d& operator -(const Vector2d& a) const { Vector2d v = Vector2d(x - a.x, y - a.y); return v; }

	Vector2d& operator *=(const Vector2d& a) { x *= a.x; y *= a.y; return *this; }
	Vector2d& operator *(const Vector2d& a) { Vector2d v = Vector2d(x * a.x, y * a.y); return v; }
	Vector2d& operator *(const Vector2d& a) const { Vector2d v = Vector2d(x * a.x, y * a.y); return v; }

	Vector2d& operator /=(const Vector2d& a) { x /= a.x; y /= a.y; return *this; }
	Vector2d& operator /(const Vector2d& a) { Vector2d v = Vector2d(x / a.x, y / a.y); return v; }
	Vector2d& operator /(const Vector2d& a) const { Vector2d v = Vector2d(x / a.x, y / a.y); return v; }

	Vector2d& operator *=(const double a) { x *= a; y *= a; return *this; }
	Vector2d& operator *(const double a) {Vector2d v = Vector2d(x * a, y * a);return v;}
	Vector2d& operator *(const double a) const { Vector2d v = Vector2d(x * a, y * a); return v; }

	Vector2d& operator /=(const double a) { x /= a; y /= a; return *this; }
	Vector2d& operator /(const double a) {Vector2d v = Vector2d(x / a, y / a);return v;}
	Vector2d& operator /(const double a) const { Vector2d v = Vector2d(x / a, y / a); return v; }

	bool operator==(const Vector2d& a) { return x == a.x && y == a.y; }
	bool operator==(const Vector2d& a) const { return x == a.x && y == a.y; }

	bool operator!=(const Vector2d& a) { return !operator==(a); }
	bool operator!=(const Vector2d& a) const { return !operator==(a); }


	static Vector2d Zero() { return Vector2d(0, 0); }
	static Vector2d One() { return Vector2d(1, 1); }

	static Vector2d Up() { return Vector2d(0, 1); }
	static Vector2d Down() { return Vector2d(0, -1); }
	static Vector2d Left() { return Vector2d(-1, 0); }
	static Vector2d Right() { return Vector2d(1, 0); }

	string ToString() { return ("(" + to_string(x) + "," + to_string(y) + ")"); }
};

struct Vector2i {
	int x;
	int y;

	Vector2i() { x = 0; y = 0; }
	Vector2i(int _x, int _y) { x = _x; y = _y; }
	Vector2i(const Vector2i& other) { x = other.x; y = other.y; }

	float GetLength() { return (float)sqrt(GetSqrMagnitude()); }
	float GetSqrMagnitude() { return (float)((x * x) + (y * y)); }

	//Vector2i& operator =(const Vector2i& a) { x = a.x; y = a.y; return *this; }

	operator Vector2f() const { return Vector2f(x, y); }
	operator Vector2d() const { return Vector2d(x, y); }

	Vector2i& operator +=(const Vector2i& a) { x += a.x; y += a.y; return *this; }
	Vector2i& operator +(const Vector2i& a) {Vector2i v = Vector2i(x + a.x, y + a.y);return v;}
	Vector2i& operator +(const Vector2i& a) const { Vector2i v = Vector2i(x + a.x, y + a.y); return v; }

	Vector2i& operator -=(const Vector2i& a) { x -= a.x; y -= a.y; return *this; }
	Vector2i& operator -(const Vector2i& a) {Vector2i v = Vector2i(x - a.x, y - a.y);return v;}
	Vector2i& operator -(const Vector2i& a) const { Vector2i v = Vector2i(x - a.x, y - a.y); return v; }

	Vector2i& operator *=(const Vector2i& a) { x *= a.x; y *= a.y; return *this; }
	Vector2i& operator *(const Vector2i& a) {Vector2i v = Vector2i(x * a.x, y * a.y);return v;}
	Vector2i& operator *(const Vector2i& a) const { Vector2i v = Vector2i(x * a.x, y * a.y); return v; }

	Vector2i& operator /=(const Vector2i& a) { x /= a.x; y /= a.y; return *this; }
	Vector2i& operator /(const Vector2i& a) {Vector2i v = Vector2i(x / a.x, y / a.y);return v;}
	Vector2i& operator /(const Vector2i& a) const { Vector2i v = Vector2i(x / a.x, y / a.y); return v; }

	Vector2i& operator *=(const int a) { x *= a; y *= a; return *this; }
	Vector2i& operator *(const int a) {Vector2i v = Vector2i(x * a, y * a);return v;}
	Vector2i& operator *(const int a) const { Vector2i v = Vector2i(x * a, y * a); return v; }

	Vector2i& operator /=(const int a) { x /= a; y /= a; return *this; }
	Vector2i& operator /(const int a) {Vector2i v = Vector2i(x / a, y / a);return v;}
	Vector2i& operator /(const int a) const { Vector2i v = Vector2i(x / a, y / a); return v; }

	bool operator==(const Vector2i& a) { return x == a.x && y == a.y; }
	bool operator==(const Vector2i& a) const { return x == a.x && y == a.y; }

	bool operator!=(const Vector2i& a) { return !operator==(a); }
	bool operator!=(const Vector2i& a) const { return !operator==(a); }

	static Vector2i Zero() { return Vector2i(0, 0); }
	static Vector2i One() { return Vector2i(1, 1); }

	static Vector2i Up() { return Vector2i(0, 1); }
	static Vector2i Down() { return Vector2i(0, -1); }
	static Vector2i Left() { return Vector2i(-1, 0); }
	static Vector2i Right() { return Vector2i(1, 0); }

	string ToString() { return ("(" + to_string(x) + "," + to_string(y) + ")"); }
};

#endif