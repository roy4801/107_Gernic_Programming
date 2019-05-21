#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "D"
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
	// regex r("[+-]{0,1}\\d*(\\.|[eE])\\d*[eE]?[+-]?\\d*[flFL]?");
	regex reg("\\d*(\\.|[eE][+-]*)\\d*([eE]{1}[+-]*\\d*|[eE]{0})[flFL]?");

	string str;
	smatch sm;

	while(getline(cin,str))
	{
		if (regex_match(str, sm, reg))
		{
			cout << "TRUE" << "\n\n";
		}
		else
		{
			cout << "FALSE" << '\n';
			while (regex_search(str, sm, reg))
			{
				cout << sm[0].str() << '\n';
				str = sm.suffix().str();
			}
			cout << "\n";
		}

	}

	return 0;
}