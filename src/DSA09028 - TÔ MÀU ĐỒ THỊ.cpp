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

int n, m, q, a, b, res = 1;
vector<int> k[1005];
int col[1005], visited[1005];

void bfs(int u)
{
    visited[u] = 1;
    queue<int> q;
    q.push(u);
    while (q.size())
    {
        int tmp = q.front();
        q.pop();
        for (auto x : k[tmp])
        {
            if (visited[x])
            {
                if (col[x] == col[tmp])
                    col[x]++;
                res = max(res, col[x]);
            }
            else
            {
                q.push(x);
                visited[x] = 1;
            }
        }
    }
}

void reset()
{
    memset(visited, 0, sizeof(visited));
    memset(col, 0, sizeof(col));
    for (int i = 0; i < 1005; i++)
        k[i].clear();
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            bfs(i);
    }
}

main()
{
    faster();
    run()
    {
        reset();
        cin >> n >> m >> q;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            k[a].push_back(b);
            k[b].push_back(a);
        }
        solve();
        if (res < q)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
