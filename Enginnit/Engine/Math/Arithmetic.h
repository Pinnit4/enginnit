#ifndef ENGINNIT_MATH_ARITHMETIC
#define ENGINNIT_MATH_ARITHMETIC

#include "Vectors/Vectors.h"

#include <vector>

namespace Math {
	float Clamp(float value, float min, float max);
	double Clamp(double value, double min, double max);
	int Clamp(int value, int min, int max);

	float Repeat(float value, float min, float max);
	double Repeat(double value, double min, double max);
	int Repeat(int value, int min, int max);

	float Max(vector<float> values);
	float Min(vector<float> values);

	float Max(float a, float b);
	float Min(float a, float b);

	double Max(vector<double> values);
	double Min(vector<double> values);

	double Max(double a, double b);
	double Min(double a, double b);

	int Max(vector<int> values);
	int Min(vector<int> values);

	int Max(int a, int b);
	int Min(int a, int b);
};
#endif