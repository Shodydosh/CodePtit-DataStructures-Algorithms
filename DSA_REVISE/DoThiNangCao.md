### DFS - CAY KHUNG

```cpp
int n, m, u, a, b;
vector<int> k[1005];
vector<vector<int>> baseTree;
int visited[1005] = {};

void reset()
{
    baseTree.clear();
    for (int i = 0; i < 1005; i++)
        k[i].clear();
    memset(visited, 0, sizeof(visited));
}

void dfs(int u)
{
    visited[u] = 1;
    for (auto x : k[u])
    {
        if (!visited[x])
        {
            baseTree.push_back({u, x});
            visited[x] = 1;
            dfs(x);
        }
    }
}

main()
{
    faster();
    run()
    {
        reset();
        cin >> n >> m >> u;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            k[a].push_back(b);
            k[b].push_back(a);
        }
        dfs(u);
        int chk = 1;
        for (int i = 1; i <= n; i++)
            if (!visited[i])
            {
                chk = 0;
                break;
            }
        if (chk)
            for (auto x : baseTree)
                cout << x[0] << ' ' << x[1] << endl;
        else
            cout << -1 << endl;
    }
}
```

### DIJKSTRA

```cpp
void dijkstra(int s)
{
    vector<long long> d(n + 1, INF);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    // distance / vertex

    Q.push({0, s});
    while (!Q.empty())
    {
        pair<int, int> top = Q.top();
        Q.pop();
        int u = top.second;
        int kc = top.first;
        if (kc > d[u])
            continue;
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second; // distance from i -> v
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << d[i] << ' ';
    cout << endl;
}
```

### FLOYD

```cpp
int main()
{
    faster();
    int n, m, u, v, w, q;
    cin >> n >> m;
    for (int i = 0; i <= 104; i++)
        for (int j = 0; j <= 104; j++)
            (i == j) ? D[i][j] = 0 : D[i][j] = 1000;
    while (m--)
    {
        cin >> u >> v >> w;
        D[u][v] = D[v][u] = w;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (D[i][j] > D[i][k] + D[k][j])
                    D[i][j] = D[i][k] + D[k][j];
    cin >> q;
    while (q--)
    {
        cin >> u >> v;
        cout << D[u][v] << endl;
    }
}
```

### KRUSKAL

```cpp
int n, m, ans;
int parent[100001];
int sz[100001];

struct canh
{
    int dau, cuoi, ts;
};

int cmp(canh a, canh b)
{
    return a.ts < b.ts;
}

void makeSets(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

int Find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a == b)
        return 0;

    if (sz[a] < sz[b])
        swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
    ans = max(ans, sz[a]);
    return 1;
}

int main()
{
    int n, m, dau, cuoi, ts;
    faster();
    run()
    {
        cin >> n >> m;
        vector<canh> ds;
        for (int i = 0; i < m; i++)
        {
            cin >> dau >> cuoi >> ts;
            ds.push_back({dau, cuoi, ts});
        }
        sort(all(ds), cmp);
        makeSets(n);
        int res = 0;
        for (int i = 0; i < ds.size(); i++)
            if (Union(ds[i].dau, ds[i].cuoi))
                // có nghĩa là nếu thêm cạnh này vào thì sẽ thành chu trình
                res += ds[i].ts;
        cout << res << endl;
    }
    return 0;
}
```
