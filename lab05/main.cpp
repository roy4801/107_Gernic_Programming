#include <bits/stdc++.h>
using namespace std;

#define PROB "data"
#define N 100000
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> PP;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF 0x3f3f3f3f
int d[N+5];
int parent[N+5];
vector<P> G[N+5]; // fr, to, wei
int n, t;
void dijkstra(int s)
{
	for(int i = 0; i <= n; i++) d[i] = INF;

	priority_queue<P, vector<P>, greater<P> > pq; // (wei, to)
	int cur, to, wei;

	pq.emplace(0, s);
	parent[s] = s;

	while(!pq.empty())
	{
		tie(wei, cur) = pq.top();
		pq.pop();

		if(d[cur] != INF)
			continue;

		d[cur] = wei;
		for(auto i : G[cur])
		{
			tie(to, wei) = i;
			if(d[to] == INF)
			{
				pq.emplace(d[cur] + wei, to);
				parent[to] = cur;
			}
		}
	}
}
int fr, to, wei;
vector<int> p;
void path(int src, int start)
{
    if(start != src)
        path(src, parent[start]);
    p.PB(start);
}

int main()
{
	#ifdef DBG
	freopen(PROB ".in", "r", stdin);
	freopen(PROB ".out", "w", stdout);
	#endif
	while(cin >> n >> t)
	{
		while(cin >> fr >> to >> wei)
			G[fr].PB(MP(to, wei));

		dijkstra(t);

		vector<P> v;
		for(int i = 1; i <= n; i++)
			v.PB(MP(d[i], i)); // wei, to
		sort(v.begin(), v.end());

		for(auto &i : v)
		{
			if(i.F != 0)
			{
				path(1, i.S);
				for(int i = 0; i < p.size(); i++)
					printf("%d%s", p[i], i!=p.size()-1 ? "->" : " ");
				printf("%d\n", i.F);
				p.clear();
			}
		}
	}
	return 0;
}