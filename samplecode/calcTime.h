#pragma once

#include <vector>
#include <ctime>

#ifdef TIME_TEST
	#define T_START() _timeStart()
	#define T_END() _timeEnd()
	#define T_TICK() _getTick()
	#define T_SEC() _getSec()
#else
	#define T_START()
	#define T_END()
	#define T_TICK()
	#define T_SEC()
#endif

static clock_t orig;

void _timeStart()
{
	orig = clock();
}

clock_t _timeEnd()
{
	return clock() - orig;
}

int _getTick()
{
	return orig;
}

float _getSec()
{
	return (float)orig / CLOCKS_PER_SEC;
}