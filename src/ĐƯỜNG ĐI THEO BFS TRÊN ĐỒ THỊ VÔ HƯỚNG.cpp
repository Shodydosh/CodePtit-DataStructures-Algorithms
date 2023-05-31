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

int visited[1005] = {};
vector<int> k[1005];

int v, e;
int a, b, st, goal;
int OK = 0;
string res = "";

void bfs(int u)
{
	queue<pair<int, string>> q;
	q.push({u, to_string(u)});
	while (!q.empty())
	{
		pair<int, string> x = q.front();
		q.pop();
		visited[x.first] = 1;
		for (auto y : k[x.first])
		{
			if (!visited[y])
			{
				visited[y] = 1;
				if (y == goal)
				{
					OK = 1;
					res = x.second + ' ' + to_string(y);
				}
				q.push({y, x.second + ' ' + to_string(y)});
			}
		}
	}
}

void reset()
{
	res = "";
	OK = 0;
	for (int i = 0; i < 1005; i++)
		k[i].clear();
	memset(visited, 0, sizeof(visited));
}

main()
{
	faster();
	run()
	{
		reset();
		cin >> v >> e >> st >> goal;
		for (int i = 0; i < e; i++)
		{
			cin >> a >> b;
			k[a].push_back(b);
			k[b].push_back(a);
		}
		bfs(st);
		if (OK)
			cout << res << endl;
		else
			cout << -1 << endl;
	}
}
