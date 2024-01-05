#include "TimeProfiler.h"

map<int, chrono::system_clock::time_point> TimeProfiler::start = map<int, chrono::system_clock::time_point>();
int TimeProfiler::counter = 0;

int TimeProfiler::StartProfiler() {
	counter++;
	auto st = chrono::system_clock::now();
	start.insert({ counter, st });
	return counter;
}

double TimeProfiler::StopProfiler(int pId) {
	auto end = chrono::system_clock::now();

	auto st = start[pId];
	start.erase(pId);

	chrono::duration<double> elapsed_seconds = end - st;
	return elapsed_seconds.count();
}