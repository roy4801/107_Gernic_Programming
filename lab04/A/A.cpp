#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "A"
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
	regex reg("\\w+");

	while(getline(cin, str))
	{
		smatch sm;
		vector <string> ans;
		// cout << str << '\n';
		while(regex_search(str, sm, reg))
		{
			ans.push_back(sm[0]);
			str = sm.suffix().str();
		}

		sort(ans.begin(), ans.end(), [](const string &lhs, const string &rhs){
			return lhs > rhs;
		});

		for(const auto &i : ans)
			cout << i << '\n';
		cout << '\n';
	}



	return 0;
}