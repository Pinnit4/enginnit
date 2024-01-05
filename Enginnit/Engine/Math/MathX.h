#ifndef ENGINNIT_MATHX
#define ENGINNIT_MATHX

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

using namespace std;

class MathX {
public:
	static float Lerp(float a, float b, float t);
	static double Lerp(double a, double b, double t);

	static Vector2 Lerp(Vector2 a, Vector2 b, float t);
	static Vector3 Lerp(Vector3 a, Vector3 b, float t);
	static Vector4 Lerp(Vector4 a, Vector4 b, float t);

	static float InverseLerp(float a, float b, float x);
	static double InverseLerp(double a, double b, double x);

	static Vector2 InverseLerp(Vector2 a, Vector2 b, float x);
	static Vector3 InverseLerp(Vector3 a, Vector3 b, float x);
	static Vector4 InverseLerp(Vector4 a, Vector4 b, float x);

	static float Clamp(float value, float min, float max);
	static double Clamp(double value, double min, double max);
	static int Clamp(int value, int min, int max);

	static float Repeat(float value, float min, float max);
	static double Repeat(double value, double min, double max);
	static int Repeat(int value, int min, int max);
};
#endif