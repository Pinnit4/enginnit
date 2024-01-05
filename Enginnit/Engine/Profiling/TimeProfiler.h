#ifndef ENGINNIT_TIME_PROFILER
#define ENGINNIT_TIME_PROFILER

#include <iostream>
#include <chrono>
#include <ctime> 
#include <map>

using namespace std;

class TimeProfiler {
public:
	static int StartProfiler();
	static double StopProfiler(int pId);
private:
	static map<int, chrono::system_clock::time_point> start;
	static int counter;
};
#endif#pragma once
