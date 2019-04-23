#include <bits/stdc++.h>

using namespace std;

void init()
{
	srand(time(NULL));
}

int rand_int(int from, int to)
{
	return from + (rand() % (to - from) + 1);
}

string gen_str(int len)
{
	string str;

	char myarr[8] = {'a', 'c', 't', 'g' ,'A' , 'C', 'T', 'G'};
	for (int i = 0; i < len; ++i)
	{
		str += myarr[rand_int(0,7)];
	}
	return str;
}

void gen_file(string name, int times, int len, int checker)
{
	ofstream ofs(name);

	for(int i = 0; i < times; i++)
		ofs << gen_str(len) << " " << gen_str(checker) << '\n';
}



int main(int argc, char const *argv[])
{
	init();
	int times = strtol(argv[1], NULL, 10);
	int len = strtol(argv[2], NULL, 10);
	int checker = strtol(argv[3], NULL, 10);
	gen_file("test.txt", times, len, checker);
	return 0;
}