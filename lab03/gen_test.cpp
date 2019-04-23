#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

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
	std::string tmp;
	char dna[8] = {'a', 'c', 't', 'g', 'A', 'C', 'T', 'G'};
	for (int i = 0; i < len; i++)
		tmp += dna[rand_int(0,7)];

	return tmp;
}

void gen_str_to_file(std::string name, int times, int mother, int child)
{
	std::ofstream ofs(name);
	for (int i = 0; i < times; i++)
		ofs << rand_str(mother) << " " << rand_str(child) << '\n';
}


int main(int argc, char const *argv[])
{
	int times = strtol(argv[1], NULL, 10);
	int mother = strtol(argv[2], NULL, 10);
	int child = strtol(argv[3], NULL, 10);

	gen_str_to_file("test.txt", times, mother, child);
	return 0;
}