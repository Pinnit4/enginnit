#ifndef COLORHEADER
#define COLORHEADER

struct Color {
	float r;
	float g;
	float b;
	float a;

	Color() { r = 1; g = 1; b = 1; a = 1; }
	Color(float _r, float _g, float _b) { r = _r; g = _g; b = _b; a = 1; }
	Color(float _r, float _g, float _b, float _a) { r = _r; g = _g; b = _b; a = _a; }

	Color(const Color& other) { r = other.r; g = other.g; b = other.b; a = other.a; }

	Color& operator +=(const Color& x) { r += x.r; g += x.g; b += x.b; a += x.a; return *this; }
	Color& operator +(const Color& x) { Color c = Color(r + x.r, g + x.g, b + x.b, a + x.a); return c; }
	Color& operator +(const Color& x) const { Color c = Color(r + x.r, g + x.g, b + x.b, a + x.a); return c; }

	Color& operator -=(const Color& x) { r -= x.r; g -= x.g; b -= x.b; a -= x.a; return *this; }
	Color& operator -(const Color& x) { Color c = Color(r - x.r, g - x.g, b - x.b, a - x.a); return c; }
	Color& operator -(const Color& x) const { Color c = Color(r - x.r, g - x.g, b - x.b, a - x.a); return c; }

	Color& operator *=(const Color& x) { r *= x.r; g *= x.g;  b *= x.b; a *= x.a; return *this; }
	Color& operator *(const Color& x) { Color c = Color(r * x.r, g * x.g, b * x.b, a * x.a); return c; }
	Color& operator *(const Color& x) const { Color c = Color(r * x.r, g * x.g, b + x.b, a * x.a); return c; }

	Color& operator /=(const Color& x) { r /= x.r; g /= x.g;  b /= x.b; a /= x.a; return *this; }
	Color& operator /(const Color& x) { Color c = Color(r / x.r, g / x.g, b / x.b, a / x.a); return c; }
	Color& operator /(const Color& x) const { Color c = Color(r / x.r, g / x.g, b / x.b, a / x.a); return c; }

	Color& operator *=(const float x) { r *= x; g *= x;  b *= x; a *= x; return *this; }
	Color& operator *(const float x) { Color c = Color(r * x, g * x, b * x, a * x); return c; }
	Color& operator *(const float x) const { Color c = Color(r * x, g * x, b * x, a * x); return c; }

	Color& operator /=(const float x) { r /= x; g /= x; b /= x; a /= x; return *this; }
	Color& operator /(const float x) { Color c = Color(r / x, g / x, b / x, a / x); return c; }
	Color& operator /(const float x) const { Color c = Color(r / x, g / x, b / x, a / x); return c; }

	bool operator==(const Color& x) { return r == x.r && g == x.g && b == x.b && a == x.a; }
	bool operator==(const Color& x) const { return r == x.r && g == x.g && b == x.b && a == x.a; }

	bool operator!=(const Color& x) { return !operator==(x); }
	bool operator!=(const Color& x) const { return !operator==(x); }

	static Color Black() { return  Color(0, 0, 0, 1); }
	static Color White() { return Color(1, 1, 1, 1); }
	static Color Clear() { return  Color(1, 1, 1, 0); }

	static Color Red() { return Color(1, 0, 0, 1); }
	static Color Green() { return  Color(0, 1, 0, 1); }
	static Color Blue() { return Color(0, 0, 1, 1); }
};

#endif