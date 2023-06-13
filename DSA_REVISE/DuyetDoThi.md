### DFS

```cpp
void dfs(vector<int> adj[], int src, int visited[])
{
    cout << src << " ";
    visited[src] = 1;

    for (int i = 0; i < adj[src].size(); i++)
    {
        int tmp = adj[src][i];
        if (!visited[tmp])
        {
            dfs(adj, tmp, visited);
        }
    }
}
```

### BFS

```cpp
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
```

### DISJOINT SET UNION - KIEM TRA CHU TRINH

```cpp
int n, m, ans = 0, a, b;
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
	{
		ans = 1;
		return; // cung 1 parent
	}
	if (sz[a] < sz[b])
		swap(a, b);
	sz[a] += sz[b];
	parent[b] = a;
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
		if (ans)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
```

### CANH CAU

```cpp
int visited[1005] = {};
vector<int> k[1005];
vector<pair<int, int>> s;
vector<pair<int, int>> ans;

int v, e, res;
void dfs(int u)
{
    visited[u] = 1;
    for (int i = 0; i < k[u].size(); i++)
    {
        int h = k[u][i];
        if (!visited[h])
            dfs(h);
    }
}
void reset()
{
    for (int i = 0; i < 1005; i++)
        k[i].clear();
    memset(visited, 0, sizeof(visited));
}

int tplt()
{
    int cnt = 0;
    for (int i = 1; i <= v; i++)
        if (!visited[i])
        {
            cnt++;
            dfs(i);
        }
    return cnt;
}

void canhcau(int canh)
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
        if (i != canh)
        {
            k[s[i].first].push_back(s[i].second);
            k[s[i].second].push_back(s[i].first);
        }
    cnt = tplt();
    if (cnt > res)
    {
        if (s[canh].first < s[canh].second)
            ans.push_back({s[canh].first, s[canh].second});
        else
            ans.push_back({s[canh].second, s[canh].first});
    }
}

main()
{
    faster();
    run()
    {
        reset();
        cin >> v >> e;
        s.clear();
        ans.clear();
        int start, end;
        for (int i = 0; i < e; i++)
        {
            cin >> start >> end;
            s.push_back({start, end});
            k[start].push_back(end);
            k[end].push_back(start);
        }
        res = tplt();
        for (int i = 0; i < s.size(); i++)
        {
            reset();
            canhcau(i);
        }
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i].first << ' ' << ans[i].second << ' ';
        cout << endl;
    }
}
```

### DUONG DI THEO BFS DO THI VO HUONG

```cpp
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
```

### THANH PHAN LIEN THONG BFS

```cpp
int visited[1005] = {};
vector<int> k[1005];

int v, e;
int a, b, st, goal;

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        visited[x] = 1;
        for (auto y : k[x])
        {
            if (!visited[y])
            {
                visited[y] = 1;
                q.push(y);
            }
        }
    }
}

void reset()
{
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
        cin >> v >> e;
        for (int i = 0; i < e; i++)
        {
            cin >> a >> b;
            k[a].push_back(b);
            k[b].push_back(a);
        }
        int res = 0;
        for (int i = 1; i <= v; i++)
        {
            if (!visited[i])
            {
                res++;
                bfs(i);
            }
        }
        cout << res << endl;
    }
}
```

### LIEN THONG MANH - DFS

```cpp
vector<int> k[10005];
int visited[10005];

void DFS(int u)
{
	visited[u] = 1;
	for (auto x : k[u])
		if (!visited[x])
			DFS(x);
}

int main()
{
	faster();
	run()
	{
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < 1005; i++)
			k[i].clear();

		int n, m, a, b;
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			k[a].pb(b);
		}

		int tmp = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				tmp++;
				DFS(i);
			}
		}

		(tmp == 1) ? cout << "YES\n" : cout << "NO\n";
	}
}
```

### SO LUONG HON DAO

```cpp
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
```

### LIET KE DINH TRU

```cpp
vector<int> k[10005];
int visited[10005];

void DFS(int u)
{
	visited[u] = 1;
	for (auto x : k[u])
		if (!visited[x])
			DFS(x);
}

int main()
{
	faster();
	run()
	{
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < 1005; i++)
			k[i].clear();

		int n, m, a, b;
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			k[a].pb(b);
			k[b].pb(a);
		}

		int tmp = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				tmp++;
				DFS(i);
			}
		}

		for (int i = 1; i <= n; i++)
		{
			memset(visited, 0, sizeof(visited));
			int cnt = 0;
			visited[i] = 1;
			for (int j = 1; j <= n; j++)
			{
				if (!visited[j])
				{
					cnt++;
					DFS(j);
				}
			}
			if (cnt > tmp)
				cout << i << ' ';
		}
		cout << endl;
	}
}
```
