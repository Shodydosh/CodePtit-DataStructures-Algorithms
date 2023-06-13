### XAU CON CHUNG DAI NHAT

```cpp
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pop pop_back
#define ll long long

int calculate(string s1, string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();
    int dp[l1 + 1][l2 + 1] = {};

    int maxLength = 0;
    for (int i = 0; i < l1; i++)
        for (int j = 0; j < l2; j++)
        {
            if (s1[i] == s2[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    return dp[l1][l2];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    // t = 1;
    while (t--)
    {
        string s1, s2;
        cin >> s1;
        cin >> s2;
        cout << calculate(s1, s2) << endl;
    }
}
```

### DAY CON CO TONG BANG S

dùng mảng dp để lưu các giá trị có thể xảy ra của tổng theo từng số
dp[x] == 1 means that x is reachable

```cpp
main()
{
    faster();
    run()
    {
        long long n, sum;
        cin >> n >> sum;
        int a[n];
        int dp[50000] = {};
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            dp[a[i]] = 1;
        }
        for (int i = 0; i < n; i++)
            for (int j = sum; j >= a[i]; j--)
                if (dp[j - a[i]] == 1)
                    dp[j] = 1;
        (dp[sum] == 1) ? cout << "YES" : cout << "NO";
        cout << endl;
    }
}
```

### TO HOP C(N, K)

```cpp
int dp[1001][1001];

main()
{
    faster();
    for (int i = 0; i <= 1000; i++)
        for (int j = 0; j <= 1000; j++)
        {
            if (i == j || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
        }
    run()
    {
        int n, k;
        cin >> n >> k;
        cout << dp[n][k] << endl;
    }
}
```

### BAC THANG

Một chiếc cầu thang có N bậc. Mỗi bước, bạn được phép bước lên trên tối đa K bước. Hỏi có tất cả bao nhiêu cách bước để đi hết cầu thang? (Tổng số bước đúng bằng N).

```cpp
main()
{
    faster();
    run()
    {
        int n, k;
        cin >> n >> k;
        long long dp[100005] = {};
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= min(i, k); j++)
                dp[i] = (dp[i] + dp[i - j]) % 1000000007;
        cout << dp[n] << endl;
    }
}
```

### CAI TUI

```cpp
main()
{
    faster();
    run()
    {
        cin >> n >> k;
        vector<pair<int, int>> v(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> v[i].second; //!  weight
        for (int i = 1; i <= n; i++)
            cin >> v[i].first; //!  value
        static int dp[1001][1001];

        // dp[i,j] là giá trị lớn nhất có thể chọn trong số các vật {1,2,…,i-1}
        // giới hạn trọng lượng là j

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else
                {
                    if (j >= v[i].second)
                        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i].second] + v[i].first);
                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }
        }
        cout << dp[n][k] << endl;
    }
}
```

### GIAI MA

Một bản tin M đã mã hóa bí mật thành các con số theo ánh xạ như sau: ‘A’->1, ‘B’->2, .., ‘Z’->26. Hãy cho biết có bao nhiêu cách khác nhau để giải mã bản tin M. Ví dụ với bản mã M=”123” nó có thể được giải mã thành ABC (1 2 3), LC (12 3), AW(1 23).

```cpp
int cal(string s)
{
    if (s[0] == '0')
        return 0;
    int dp[10000] = {0};
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= s.size(); i++)
    {
        if (s[i - 1] > '0')
            dp[i] = dp[i - 1];
        if (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6')
            dp[i] += dp[i - 2];
    }
    return dp[s.length()];
}
```

### NHA KHONG KE NHAU

```cpp
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> dp(n);
        int nums[n];
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        int maxVal = INT_MIN;
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
            maxVal = max(maxVal, dp[i]);
        }
        cout << maxVal << endl;
    }
}
```

### SO UGLY

Số Ugly là các số chỉ có ước số là 2, 3, 5

```cpp
main()
{
    faster();
    run()
    {
        int n;
        cin >> n;
        int dp[10005] = {};
        dp[1] = 1;
        int a = 1, b = 1, c = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = min(dp[a] * 2, min(dp[b] * 3, dp[c] * 5));
            if (dp[i] == dp[a] * 2)
                a++;
            if (dp[i] == dp[b] * 3)
                b++;
            if (dp[i] == dp[c] * 5)
                c++;
        }
        cout << dp[n] << endl;
    }
}
```

### DAY SO BITONIC

```cpp
main()
{
    faster();
    run()
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int dec[100000] = {}, inc[100000] = {};
        for (int i = 0; i < n; i++)
        {
            inc[i] = a[i];
            for (int j = 0; j < i; j++)
                if (a[i] > a[j])
                    inc[i] = max(inc[j] + a[i], inc[i]);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            dec[i] = a[i];
            for (int j = i + 1; j < n; j++)
                if (a[i] > a[j])
                    dec[i] = max(dec[j] + a[i], dec[i]);
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, dec[i] + inc[i] - a[i]);
        }
        cout << ans << endl;
    }
}
```

### KY TU GIONG NHAU

Thao tác insert: chèn một ký tự với thời gian là X.
Thao tác delete: loại bỏ ký tự cuối cùng với thời gian là Y.
Thao tác copying: copy và paste tất cả các ký tự đã viết để số ký tự được nhân đôi với thời gian là Z.

```cpp
int cal(int n, int x, int y, int z)
{
    int F[105] = {0};
    F[1] = x;
    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
            F[i] = min(F[i - 1] + x, F[i / 2] + z);
        else
            F[i] = min(F[i - 1] + x, F[(i + 1) / 2] + z + y);
    }
    return F[n];
}

main()
{
    faster();
    run()
    {
        int n, x, y, z;
        cin >> n >> x >> y >> z;
        cout << cal(n, x, y, z) << endl;
    }
}
```

### TONG CAC XAU CON

```cpp
main()
{
    faster();
    run()
    {
        string s;
        cin >> s;
        long long res = 0;
        for (int i = 1; i <= s.size(); i++)
            for (int j = 0; j <= s.size() - i; j++)
                res += stoll(s.substr(j, i));
        cout << res << endl;
    }
}
```
