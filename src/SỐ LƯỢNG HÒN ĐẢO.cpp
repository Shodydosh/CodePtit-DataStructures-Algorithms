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
#define pb push_back

vector<int> k[10005];
int n, m, a, b;
int mp[505][505];
int visited[505][505];

void DFS(int i, int j)
{
	if (i < 0 || j < 0 || i > n || j > m || !mp[i][j])
		return;
	mp[i][j] = 0;

	DFS(i, j + 1);
	DFS(i + 1, j + 1);
	DFS(i - 1, j + 1);

	DFS(i, j - 1);
	DFS(i + 1, j - 1);
	DFS(i - 1, j - 1);

	DFS(i - 1, j);
	DFS(i + 1, j);
}

int main()
{
	faster();
	run()
	{
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < 1005; i++)
			k[i].clear();

		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> mp[i][j];
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (mp[i][j] == 1)
				{
					res++;
					DFS(i, j);
				}
			}
		}
		cout << res << endl;
	}
}
