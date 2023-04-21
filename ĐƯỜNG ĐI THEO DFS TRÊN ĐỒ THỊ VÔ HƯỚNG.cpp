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
string res;
int a, b, st, goal;
int OK = 0;

void dfs(int u, string path)
{
    visited[u] = 1;
    for (int i = 0; i < k[u].size(); i++)
    {
        int h = k[u][i];
        if (!visited[h])
        {
            if (h == goal)
            {
                OK = 1;
                res += path + ' ' + to_string(h);
            }
            dfs(h, path + ' ' + to_string(h));
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
        dfs(st, to_string(st));
        if (OK)
            cout << res << endl;
        else
            cout << -1 << endl;
    }
}
