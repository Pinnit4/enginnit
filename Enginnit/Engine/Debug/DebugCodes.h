#ifndef ENGINNIT_DEBUG_CODES
#define ENGINNIT_DEBUG_CODES

#include "../Math/Math.h"

#include <iostream>
#include <map>

using namespace std;

class DebugCodes {
public:
	static void SetInt(string code, int value);
	static int GetInt(string code, int defaultValue);

	static void SetString(string code, string value);
	static string GetString(string code, string defaultValue);

	static void SetFloat(string code, float value);
	static float GetFloat(string code, float defaultValue);

	static void SetBool(string code, bool value);
	static bool GetBool(string code, bool defaultValue);

	static void SetDouble(string code, double value);
	static double GetDouble(string code, double defaultValue);
private:
	static map<string, int> intValues;
	static map<string, string> stringValues;
	static map<string, float> floatValues;
	static map<string, bool> boolValues;
	static map<string, double> doubleValues;
};
#endif