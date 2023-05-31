#include <bits/stdc++.h>
using namespace std;
int n, k, s;
int a, b;

int visited[1001] = {};
vector<int> adj[1001];

void BFS(int s)
{
    queue<int> qq;
    qq.push(s);
    while (!qq.empty())
    {
        int x = qq.front();
        qq.pop();
        cout << x << ' ';
        for (int v : adj[x])
            if (!visited[v])
            {
                qq.push(v);
                visited[v] = 1;
            }
    }
    cout << endl;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < 1001; i++)
            adj[i].clear();
        cin >> n >> k >> s;

        for (int i = 0; i < k; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        visited[s] = 1;
        BFS(s);
        cout << endl;
    }
}
