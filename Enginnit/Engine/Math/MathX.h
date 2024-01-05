#ifndef ENGINNIT_MATHX
#define ENGINNIT_MATHX

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

using namespace std;

class MathX {
public:
	static float Lerp(float a, float b, float t);
	
	static Vector2 Lerp(Vector2 a, Vector2 b, float t);
	static Vector3 Lerp(Vector3 a, Vector3 b, float t);
	static Vector4 Lerp(Vector4 a, Vector4 b, float t);

	static float InverseLerp(float a, float b, float x);

	static Vector2 InverseLerp(Vector2 a, Vector2 b, float x);
	static Vector3 InverseLerp(Vector3 a, Vector3 b, float x);
	static Vector4 InverseLerp(Vector4 a, Vector4 b, float x);
};
#endif