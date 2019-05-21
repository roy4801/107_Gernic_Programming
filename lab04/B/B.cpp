#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "B"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	string str;
	regex reg("\\d{4}[-]\\d{4}[-]\\d{4}[-]\\d{4}");

	while(getline(cin, str))
	{
		if(regex_match(str, reg))
		{
			regex r("\\d{4}");
			smatch sm;
			int acc = 0;
			for(; regex_search(str, sm, r); str = sm.suffix().str())
			{
				acc += stoi(sm[0]);
			}
			cout << "True " << acc << '\n';
		}
		else
		{
			cout << "False" << '\n';
		}
	}

	return 0;
}