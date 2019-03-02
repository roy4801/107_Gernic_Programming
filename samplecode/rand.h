#pragma once

#include <vector>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

void init_rand()
{
	srand(time(NULL));
}

int rand_int(int from,int to)
{
	return from + (rand() % (to - from) + 1);
}

std::string rand_str(int len)
{
	std::string test;
	for (int j = 0; j < len; ++j)
		test += char(rand_int(32,126));
	return test;
}

void gen_str_print(int len,int size)
{
	for(int i = 0; i < size; i++)
		std::cout << rand_str(len) << '\n';
}
void gen_str_to_file(std::string name,int len,int size)
{
	std::ofstream ofs(name);
	for(int i = 0; i < size; i++)
		ofs << rand_str(len) << '\n';
}
