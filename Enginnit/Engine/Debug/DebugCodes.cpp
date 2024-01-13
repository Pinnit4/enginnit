#include "DebugCodes.h"

map<string, int> DebugCodes::intValues = {};
map<string, string> DebugCodes::stringValues = {};
map<string, float> DebugCodes::floatValues = {};
map<string, bool> DebugCodes::boolValues = {};
map<string, double> DebugCodes::doubleValues = {};

void DebugCodes::SetInt(string code, int value) {
	auto it = intValues.find(code);
	if (it != intValues.end())
		it->second = value;
	else
		intValues.insert(make_pair(code, value));
}
int DebugCodes::GetInt(string code, int defaultValue) {
	auto it = intValues.find(code);
	if (it != intValues.end())
		return it->second;
	else
		return defaultValue;
}

void DebugCodes::SetString(string code, string value) {
	auto it = stringValues.find(code);
	if (it != stringValues.end())
		it->second = value;
	else
		stringValues.insert(make_pair(code, value));
}
string DebugCodes::GetString(string code, string defaultValue) {
	auto it = stringValues.find(code);
	if (it != stringValues.end())
		return it->second;
	else
		return defaultValue;
}

void DebugCodes::SetFloat(string code, float value) {
	auto it = floatValues.find(code);
	if (it != floatValues.end())
		it->second = value;
	else
		floatValues.insert(make_pair(code, value));
}
float DebugCodes::GetFloat(string code, float defaultValue) {
	auto it = floatValues.find(code);
	if (it != floatValues.end())
		return it->second;
	else
		return defaultValue;
}

void DebugCodes::SetBool(string code, bool value) {
	auto it = boolValues.find(code);
	if (it != boolValues.end())
		it->second = value;
	else
		boolValues.insert(make_pair(code, value));
}
bool DebugCodes::GetBool(string code, bool defaultValue) {
	auto it = boolValues.find(code);
	if (it != boolValues.end())
		return it->second;
	else
		return defaultValue;
}

void DebugCodes::SetDouble(string code, double value) {
	auto it = doubleValues.find(code);
	if (it != doubleValues.end())
		it->second = value;
	else
		doubleValues.insert(make_pair(code, value));
}
double DebugCodes::GetDouble(string code, double defaultValue) {
	auto it = doubleValues.find(code);
	if (it != doubleValues.end())
		return it->second;
	else
		return defaultValue;
}