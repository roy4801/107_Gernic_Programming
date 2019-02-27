#include <iostream>
#include <string>
#include <algorithm>
#include <rand.h>

using namespace std;

void usage(string name)
{
	const string s = "Usage: " + name + " <len> <lines>\n";
	cout << s << '\n';
}

int main(int argc, char* argv[])
{
	init_rand();

	if(argc != 3)
	{
		usage(argv[0]);
		exit(EXIT_FAILURE);
	}

	int length = strtol(argv[1], NULL, 10);
	int lines = strtol(argv[2], NULL, 10);
    gen_str_to_file("testcase.txt", length, lines);
	return 0;
}