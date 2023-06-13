### MAX HEAP

```cpp
    priority_queue<int> q;
```

### MIN HEAP

```cpp
    priority_queue<int, vector<int>, greater<int> > q;
```

### DEQUE

```cpp
main()
{
    long long t;
    deque<int> dq;
    cin >> t;
    while (t--)
    {
        string s;
        int n;
        cin >> s;
        if (s == "PUSHBACK")
        {
            cin >> n;
            dq.push_back(n);
        }
        else if (s == "PUSHFRONT")
        {
            cin >> n;
            dq.push_front(n);
        }
        else if (s == "PRINTFRONT")
            (dq.size()) ? cout << dq.front() << endl : cout << "NONE\n";
        else if (s == "PRINTBACK")
            (dq.size()) ? cout << dq.back() << endl : cout << "NONE\n";
        else if (s == "POPFRONT" && dq.size())
            dq.pop_front();
        else if (s == "POPBACK" && dq.size())
            dq.pop_back();
    }
}
```

### MOT SO BAI TUONG TU NHAU

```cpp
void render(long long n)
{
    queue<string> q;
    q.push("1");
    while (q.size())
    {
        string tmp = q.front();
        q.pop();
        if (tmp.length() > len(n) || stoll(tmp) > n)
            return;
        ans++;
        q.push(tmp + "0");
        q.push(tmp + "1");
    }
}

```

### SO LOC PHAT 3

```cpp
int n;
vector<string> ans;
void render(int n)
{
    queue<string> q;
    q.push("6");
    q.push("8");
    while (!q.empty())
    {
        string tmp = q.front();
        q.pop();
        if (tmp.size() > n)
            return;
        else
        {
            ans.push_back(tmp);
            q.push("6" + tmp);
            q.push("8" + tmp);
        }
    }
}

bool cmp(string a, string b)
{
    if (a.size() != b.size())
        return a.size() > b.size();
    return a > b;
}

main()
{
    faster();
    run()
    {
        cin >> n;
        render(n);
        sort(all(ans), cmp);
        cout << ans.size() << endl;
        for (auto s : ans)
            cout << s << ' ';
        cout << endl;
        ans.clear();
    }
}
```

### GIA TRI NHO NHAT CUA XAU

dùng max heap

```cpp
long long solve(string s, long long k){
	long long cnt[27] = {};
	for(char c : s){
		cnt[int(c - 'A')]++;
	}
	priority_queue<long long> q;
	for(long long i=0; i<=26; i++) if(cnt[i]) q.push(cnt[i]);

	while(k--){
		long long tmp = q.top(); q.pop();
		if(tmp > 0){
			tmp = tmp - 1;
			q.push(tmp);
		}
		else return 0;
	}

	long long ans = 0;
	while(q.size()){
		long long tmp = q.top();
		ans += tmp * tmp;
		q.pop();
	}
	return ans;
}

main(){
	faster();
	run(){
		long long n;
		cin >> n;
		string s;
		cin >> s;
		cout << solve(s, n) << endl;
	}
}
```
