### LUY THUA

```cpp
#include <bits/stdc++.h>
using namespace std;
#define all(s) s.begin(), s.end()
#define faster() ios_base::sync_with_stdio(0); cin.tie(0);
#define run() long long t; cin >> t; while(t--)

long long M = 1e9+ 7;
long long sqr(long long x){
	return ((x% M) * (x%M )) % M;
}

long long calc(long long n, long long k){
	if(k == 1) return n;
	long long tmp = calc(n, k/2);
	if(k % 2) return sqr(tmp) * n % M;
	return sqr(tmp);
}

int main(){
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	faster();
	run(){
		int n, k;
		cin >> n >> k;
		cout << calc(n, k) << endl;
	}
}
```

### GAP DOI DAY SO

```cpp
#include <bits/stdc++.h>
using namespace std;
#define all(s) s.begin(), s.end()
#define faster() ios_base::sync_with_stdio(0); cin.tie(0);
#define run() long long t; cin >> t; while(t--)

long long calc(long long k, long long val){
	if(k % 2 == 1) return val;
	else return calc(k/2, val+1);
}

int main(){
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	faster();
	run(){
		long long n, k;
		cin >> n >> k;
		cout << calc(k, 1) << endl;
	}
}
```

### DAY XAU FIBONACCI

```cpp
    #include <bits/stdc++.h>
    using namespace std;
    #define all(s) s.begin(), s.end()
    #define faster() ios_base::sync_with_stdio(0); cin.tie(0);
    #define run() long long t; cin >> t; while(t--)

    long long len[94];
    char findChar(long long n, long long k){
        if(n == 1) return 'A';
        if(n == 2) return 'B';
        if(k <= len[n-2]) return findChar(n-2, k);
        else return findChar(n-1, k - len[n-2]);
    }

    int main(){
    //	freopen("in.txt", "r", stdin);
    //	freopen("out.txt", "w", stdout);
        faster();
        len[1] = len[2] = 1;
        for(int i=3; i<=93; i++)
            len[i] = len[i-1] + len[i-2];
        run(){
            long long n, k;
            cin >> n >> k;
            cout << findChar(n, k) << endl;
        }
        return 0;
    }


```

### DAY CON LIEN TIEP CO TONG LON NHAT

```cpp
long long maxSubArray(vector<long long> &nums)
{
    long long n = nums.size();
    long long maxVal = INT_MIN;
    long long tmpMax = 0;
    for (int i = 0; i < n; i++)
    {
        tmpMax = max(nums[i], tmpMax + nums[i]);
        maxVal = max(maxVal, tmpMax);
    }
    return maxVal;
}
```

### FLOOR(X)

```cpp
int pos = upper_bound(a.begin(), a.end(), k) - a.begin();
```

### LUY THUA MA TRAN

```cpp
void mat_mul(long long a[100][100], long long b[100][100], int n)
{
    long long c[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (int z = 0; z < n; z++)
                c[i][j] += (a[i][z] * b[z][j]) % mod;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = c[i][j] % mod;
}

void mat_pow(long long m[100][100], int n, int k)
{
    if (k == 1)
        return;
    mat_pow(m, n, k / 2);
    mat_mul(m, m, n);
    if (k % 2 == 1)
        mat_mul(m, tmp, n);
}
```

### DAY SO VO HAN && Nth FIBONACCI

```cpp
#define M 1000000007;
map<long long, long long> F;

long long f(long long n)
{
    if (F.count(n))
        return F[n];
    long long k = n / 2;
    if (n % 2 == 0)
    {
        return F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % M;
    }
    else
    {
        return F[n] = (f(k) * f(k + 1) + f(k - 1) * f(k)) % M;
    }
}
```

### HE SO SO K

```cpp
#include <bits/stdc++.h>
using namespace std;
long long M = 1000000007;

int kToInt(string n, int k)
{
    int res = 0;
    for (int i = 0; i < n.length(); i++)
        res = res * k + (n[i] - '0');
    return res;
}

string intToK(int n, int k)
{
    string res = "";
    while (n)
    {
        res = to_string(n % k) + res;
        n /= k;
    }
    return res;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        int k;
        string a, b;
        cin >> k >> a >> b;
        int n1 = kToInt(a, k);
        int n2 = kToInt(b, k);
        cout << intToK(n1 + n2, k) << endl;
    }
}
```
