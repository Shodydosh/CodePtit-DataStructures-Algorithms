#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define run() \
	int t;    \
	cin >> t; \
	while (t--)
#define faster()                      \
	cin.tie(0);                       \
	ios_base::sync_with_stdio(false); \
	cout.tie(0);

int n, m, ans, a, b;
int parent[100001];
int sz[100001];

void makeSet()
{
	ans = 0;
	for (int i = 0; i < 100001; i++)
	{
		parent[i] = i;
		sz[i] = 1;
	}
}

int find(int u)
{
	if (u == parent[u])
		return u;
	return parent[u] = find(parent[u]);
}

void Union(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return; // cung 1 parent
	if (sz[a] < sz[b])
		swap(a, b);
	parent[b] = a;
	sz[a] += sz[b];
	ans = max(ans, sz[a]);
}

main()
{
	faster();
	run()
	{
		makeSet();
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			Union(a, b);
		}
		cout << ans << endl;
	}
}
