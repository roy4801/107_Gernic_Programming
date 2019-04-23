#include <bits/stdc++.h>

using namespace std;

#define PROBLEM ""
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back


int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("test.txt", "r" ,stdin);
	freopen("A.out", "w", stdout);
	#endif

	string str;
	string check;
	vector <int> vec;

	while(cin >> str >> check)
	{
		int ans1=0,ans2=0,ans3=0,ans4=0;
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == 'a' || str[i] == 'A')
			{
				ans1++;
			}
			else if(str[i] == 'c' || str[i] == 'C')
			{
				ans2++;
			}
			else if(str[i] == 'g' || str[i] == 'G')
			{
				ans3++;
			}
			else if(str[i] == 't' || str[i] == 'T')
			{
				ans4++;
			}
		}


		for (int i = 0; i < str.size()-check.size()+1; ++i)
		{
			bool flag = 0;
			for(int j = 0; j < check.size(); ++j)
			{
				if (toupper(str[i+j]) != toupper(check[j]) )
				{
					flag = 1;
				}
			}
			if (!flag)
				vec.push_back(i);

		}

		cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << '\n';
		for (auto i : vec)
			cout << i << " ";
		cout << vec.size() << '\n';
		vec.clear();
	}




	return 0;
}
