#pragma once

#include <vector>
#include <ctime>

#ifdef TIME_TEST
	#define T_START() timeStart()
	#define T_END() timeEnd()
#else
	#define T_START()
	#define T_END()
#endif

static clock_t orig;

void timeStart()
{
	orig = clock();
}

clock_t timeEnd()
{
	return clock() - orig;
}

int getTick()
{
	return orig;
}

float getSec()
{
	return (float)orig / CLOCKS_PER_SEC;
}