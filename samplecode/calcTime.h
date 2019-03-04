#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <cstring>
#include <fstream>
#include <iomanip>

#ifdef TIME_TEST
	#define T_START() _timeStart()
	#define T_END() _timeEnd()
	#define T_TICK(fmt, ...)  \
    do \
    {  \
        char buf[1024], buf2[1024]; \
        std::sprintf(buf, (fmt), ##__VA_ARGS__); \
        std::sprintf(buf2, " [Used %d tick]\n", _getTick()); \
        std::strcat(buf, buf2); \
        std::printf("[*] %s", buf); \
    } \
    while(0)
	#define T_SEC(fmt, ...)  \
    do \
    {  \
        char buf[1024], buf2[1024]; \
        std::sprintf(buf, (fmt), ##__VA_ARGS__); \
        std::sprintf(buf2, " [Used %.3f s]\n", _getSec()); \
        std::strcat(buf, buf2); \
        std::printf("[*] %s", buf); \
    } \
    while(0)

    #define T_SEC_gnu(x)  \
    do \
    {  \
        std::ofstream out("./gnu_"+ std::string(x) +".txt" ,ios_base::out|ios_base::app); \
        out <<  std::fixed << std::setprecision(7) << _getSec() << ' '; \
    } \
    while(0)

#else
	#define T_START()
	#define T_END()
	#define T_TICK(fmt, ...)
	#define T_SEC(fmt, ...)
#endif

static clock_t orig;

void _timeStart()
{
	orig = clock();
}

void _timeEnd()
{
	orig = clock() - orig;
}

int _getTick()
{
	return orig;
}

float _getSec()
{
	return (float)orig / CLOCKS_PER_SEC;
}