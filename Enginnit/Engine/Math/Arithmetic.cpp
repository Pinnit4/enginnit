#include "Arithmetic.h"

float Math::Clamp(float value, float min, float max) {
	if (value < min) return min;
	if (value > max) return max;
	return value;
}
double Math::Clamp(double value, double min, double max) {
	if (value < min) return min;
	if (value > max) return max;
	return value;
}
int Math::Clamp(int value, int min, int max) {
	if (value < min) return min;
	if (value >= max) return max;
	return value;
}

float Math::Repeat(float value, float min, float max) {
	if (value < min) return max;
	if (value > max) return min;
	return value;
}
double Math::Repeat(double value, double min, double max) {
	if (value < min) return max;
	if (value > max) return min;
	return value;
}
int Math::Repeat(int value, int min, int max) {
	if (value < min) return max;
	if (value >= max) return min;
	return value;
}

float Math::Max(vector<float> values) {
	float max = values[0];
	for (int i = 1; i < values.size(); i++) {
		max = Max(max, values[i]);
	}
	return max;
}
float Math::Min(vector<float> values) {
	float min = values[0];
	for (int i = 1; i < values.size(); i++) {
		min = Min(min, values[i]);
	}
	return min;
}
float Math::Max(float a, float b) { if (a > b) return a; return b; }
float Math::Min(float a, float b) { if (a < b) return a; return b; }

double Math::Max(vector<double> values) {
	double max = values[0];
	for (int i = 1; i < values.size(); i++) {
		max = Max(max, values[i]);
	}
	return max;
}
double Math::Min(vector<double> values) {
	double min = values[0];
	for (int i = 1; i < values.size(); i++) {
		min = Min(min, values[i]);
	}
	return min;
}
double Math::Max(double a, double b) { if (a > b) return a; return b; }
double Math::Min(double a, double b) { if (a < b) return a; return b; }

int Math::Max(vector<int> values) {
	int max = values[0];
	for (int i = 1; i < values.size(); i++) {
		max = Max(max, values[i]);
	}
	return max;
}
int Math::Min(vector<int> values) {
	int min = values[0];
	for (int i = 1; i < values.size(); i++) {
		min = Min(min, values[i]);
	}
	return min;
}
int Math::Max(int a, int b) { if (a > b) return a; return b; }
int Math::Min(int a, int b) { if (a < b) return a; return b; }