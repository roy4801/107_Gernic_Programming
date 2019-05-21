#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "C"
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
	regex r("(\\+\\(\\d{3}\\)-\\d-\\d{4})-(\\d{4})");
	string s;
	smatch sm;

	while(getline(cin, s))
	{
		// If regex matches and the res[7] == res[9] (區碼一樣)
		if(regex_search(s, sm, r) && sm[0].str()[7] == sm[0].str()[9])
			cout << regex_replace(s, r, "+(XXX)-X-XXXX-$2") << '\n';
		else
			cout << s << '\n';
	}
	return 0;
}