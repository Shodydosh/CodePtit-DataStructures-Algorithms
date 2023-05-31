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

int n, m, a, b, cnt = 0;
vector<int> k[1005];
int visited[1005];

void reset()
{
	cnt = 0;
	for (int i = 0; i < n; i++)
		k[i].clear();
	memset(visited, 0, sizeof(visited));
}

void dfs(int u)
{
	visited[u] = 1;
	cnt++;
	for (auto x : k[u])
	{
		if (!visited[x])
			dfs(x);
	}
}

main()
{
	faster();
	run()
	{
		reset();
		cin >> n;
		for (int i = 0; i < n - 1; i++)
		{
			cin >> a >> b;
			k[a].push_back(b);
			k[b].push_back(a);
		}
		dfs(1);
		int chk = 1;
		for (int i = 1; i <= n; i++)
			if (!visited[i])
			{
				chk = 0;
				break;
			}
		if (!chk)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}
