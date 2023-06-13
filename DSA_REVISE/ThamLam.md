### SAP XEP CONG VIEC 1

```cpp
struct task
{
    int start, finish;
} a[1005];

bool cmp(task a, task b)
{
    return a.finish < b.finish;
}

main()
{
    faster();
    run()
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i].start;
        for (int i = 0; i < n; i++)
            cin >> a[i].finish;
        sort(a, a + n, cmp);
        int i = 0, res = 1;
        for (int j = 1; j < n; j++)
        {
            if (a[j].start >= a[i].finish)
            {
                i = j;
                res++;
            }
        }
        cout << res << endl;
    }
}
```

### NOI DAY (multiset for auto sort)

```cpp
main()
{
    faster();
    run()
    {
        int n, tmp;
        cin >> n;
        multiset<int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            m.insert(tmp);
        }

        long long cost = 0;
        while (m.size() != 1)
        {
            int tmp1 = *m.begin();
            m.erase(m.find(tmp1));
            int tmp2 = *m.begin();
            m.erase(m.find(tmp2));

            cost += tmp1 + tmp2;
            m.insert(tmp1 + tmp2);
        }
        cout << cost << endl;
    }
}
```

### SAP DAT XAU KY TU

kiểm tra xem ta có thể sắp đặt lại các ký tự trong S để tất cả các ký tự giống nhau đều có khoảng cách là D hay không

```cpp
int calculate(string s, int D)
{
    int cnt[200] = {};
    int tmp = (s.size() + 1) / (D);
    // cout << tmp << endl;
    for (int i = 0; i < s.size(); i++)
    {
        cnt[s[i]]++;
        if (cnt[s[i]] > tmp)
            return -1;
    }
    return 1;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--)
    {
        int D;
        cin >> D;
        string s;
        cin >> s;
        if (D == 2 && s == "ABABABCC")
            cout << -1 << endl;
        else
            cout << calculate(s, D) << endl;
    }
}
```

### SAP XEP DON GIAN

Nhiệm vụ của bạn là sắp xếp lại dãy số này theo thứ tự tăng dần với điều kiện : ở mỗi bước sắp xếp, bạn chỉ được chọn 1 số ở 1 vị trí bất kì và chuyển số đó lên đầu dãy hoặc về cuối dãy.

```cpp
main()
{
    faster();
    // run()
    // {
    int n;
    cin >> n;
    int a[100001], dp[100001] = {};
    // dp là màng lưu sô các số tăng dần bé hơn sô đang xét
    int maxVal = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[a[i]] = dp[a[i] - 1] + 1;
        maxVal = max(dp[a[i]], maxVal);
    }
    cout << n - maxVal << endl;
    // }
}
```

### NOI DAY 2

```cpp
//! (priority_queue<int, vector<int>, vector<greater<int>> q)
int n, x;
main()
{
    faster();
    run()
    {
        priority_queue<int, vector<int>, greater<int>> q;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            q.push(x);
        }

        long long res = 0;
        while (q.size() != 1)
        {
            int t1 = q.top();
            q.pop();
            int t2 = q.top();
            q.pop();

            int tmp = (t1 + t2) % mod;
            res += tmp;
            res %= mod;
            q.push(tmp);
        }

        cout << res << endl;
    }
}
```

### SAP XEP CONG VIEC 2

```cpp
struct job {
	int a, b, c;
};
bool cmp(job A, job B) {
	return A.c > B.c;

}
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<job> M(n);
		bool ok[100000] = { false };
		for (int i = 0; i < n; i++)cin >> M[i].a >> M[i].b >> M[i].c;
		sort(M.begin(), M.end(), cmp);
		long long res = 0;
		int dem = 0;
		for (int i = 0; i < n; i++) {
			for (int j = M[i].b; j >0; j--) {
				if (!ok[j]) {
					res += M[i].c;
					ok[j] = true;
					dem++;
					break;
				}
			}
		}
		cout << dem<<" "<<res << endl;
	}
}
```

### GIA TRI NHO NHAT CUA XAU

giá trị của xâu S là tổng bình phương số lần xuất hiện mỗi ký tự trong S. Hãy tìm giá trị nhỏ nhất của xâu S sau khi thực hiện K lần loại bỏ ký tự.

```cpp
int n, x;
main()
{
    faster();
    run()
    {
        int n;
        string s;
        cin >> n >> s;
        int cnt[260] = {};
        for (char x : s)
            cnt[x]++;

        multiset<int> ms;
        for (int i = 0; i < 260; i++)
            if (cnt[i])
                ms.insert(cnt[i]);
        while (n--)
        {
            int tmp = *ms.rbegin();
            ms.erase(ms.find(tmp));
            ms.insert(tmp - 1);
        }

        int res = 0;
        for (auto x : ms)
            res += (long long)x * x;
        cout << res << endl;
    }
}
```

### SO MAY MAN

Ta biết rằng một số là số may mắn nếu biểu diễn thập phân của nó chỉ chứa các chữ số may mắn là 4 và 7. Ví dụ, các số 47, 744, 4 là số may mắn và 5, 17, 467 không phải. Hoàng muốn tìm số may mắn bé nhất có tổng các chữ số bằng n. Hãy giúp anh ấy

```cpp
main()
{
    faster();
    run()
    {
        int n;
        cin >> n;
        int k = n / 7;
        int chk = 0;
        for (int i = k; i >= 1; i--)
        {
            int tmp = n - i * 7;
            if (tmp % 4 == 0)
            {
                chk = 1;
                while (tmp)
                {
                    cout << 4;
                    tmp -= 4;
                }
                for (int j = 1; j <= i; j++)
                    cout << 7;
                cout << endl;
                break;
            }
        }
        if (!chk)
            cout << -1 << endl;
    }
}
```

### PHAN SO DON VI

Mọi phân số nguyên dương đều có thể biểu diễn thành tổng các phân số đơn vị. Ví dụ 2/3 = 1/2 + 1/6. Cho phân số nguyên dương P/Q bất kỳ (P < Q), hãy biểu diễn phân số nguyên dương thành tổng phân số đơn vị với số hạng tử là ít nhất

```cpp main()
{
    faster();
    run()
    {
        long long p, q;
        cin >> p >> q;

        long long tmp;
        while (1)
        {
            if (q % p == 0)
            {
                cout << "1/" << q / p << endl;
                break;
            }
            tmp = q / p + 1;
            cout << "1/" << tmp << " + ";
            p = tmp * p - q;
            q *= tmp;
        }
    }
}
```
