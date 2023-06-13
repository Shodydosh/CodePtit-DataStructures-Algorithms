### SAP XEP QUAN HAU 1

```cpp
#include <bits/stdc++.h>
using namespace std;
#define all(s) s.begin(), s.end()
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define run() long long t; cin >> t; while(t--)

int n, ans = 0;
int col[111] = {};
int cheo1[111] = {}; //i+j
int cheo2[111] = {}; //i-j+n

void Try(int i){
	if(i ==n+1){
		ans++;
		return;
	}

	for(int j=1; j<=n; j++){
		if(!col[j] && !cheo1[i+j] && !cheo2[i-j+n]){
			col[j] = cheo1[i+j] = cheo2[i-j+n] = 1;
			Try(i+1);
			col[j] = cheo1[i+j] = cheo2[i-j+n] = 0;
		}
	}
}

int main(){
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	faster();
	run(){
		ans = 0;
		cin >> n;
		Try(1);
		cout << ans << endl;
	}
}
```

### THAP HA NOI

```cpp
    #include <bits/stdc++.h>
    using namespace std;
    #define all(s) s.begin(), s.end()
    #define faster() ios_base::sync_with_stdio(0); cin.tie(0);
    #define run() long long t; cin >> t; while(t--)

    int n, ans = 0;
    int col[111] = {};
    int cheo1[111] = {}; //i+j
    int cheo2[111] = {}; //i-j+n

    void solveHT(int disks, char src, char aux, char des){
        if(disks == 1){
            cout << src << " -> " << des << endl; return;
        }

        solveHT(disks-1, src, des, aux);
        cout << src << " -> " << des << endl;
        solveHT(disks-1, aux, src, des);
    }

    int main(){
    //	freopen("in.txt", "r", stdin);
    //	freopen("out.txt", "w", stdout);
        faster();
        int n;
        cin >> n;
        char A = 'A', B = 'B', C = 'C';
        solveHT(n, A, B, C);
    }
```

### SO NGUYEN TO

```cpp
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

int n;
vector<string> ans;
vector<int> s;

int check[252] = {};
int PrimeCheck(int n)
{
    if (n <= 1)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;
    return 1;
}
void init()
{
    for (int i = 0; i <= 200; i++)
        if (PrimeCheck(i))
            check[i] = 1;
}

void Try(int curr, int high, int low, string s, int cnt)
{
    if (curr <= low || cnt > n)
        return;
    for (int i = low + 1; i <= curr; i++)
    {
        if (check[i])
        {
            if (high == 0 && cnt == n)
            {
                ans.push_back(s);
                return;
            }
            if (high >= i)
                Try(curr, high - i, i, s + to_string(i) + ' ', cnt + 1);
        }
    }
}

main()
{
    faster();
    init();
    run()
    {
        int low, high;
        cin >> n >> low >> high;
        Try(high, high, low, "", 0);
        sort(all(ans));
        cout << ans.size() << endl;
        for (string x : ans)
            cout << x << endl;
        ans.clear();
    }
}
```

### CHIA DEU

/chia day thanh k day con lien tiep co tong bang nhau

```cpp
#include <bits/stdc++.h>
using namespace std;
#define all(s) s.begin(), s.end()
#define faster() ios_base::sync_with_stdio(0); cin.tie(0);
#define run() long long t; cin >> t; while(t--)
int n, k, res = 0;
int a[100005];
void Try(int i, int s, int target, int cnt){
	if(cnt == k && i == n){
		res++;
		return;
	}

	for(int j=i; j<n; j++){
		s += a[j];
		if(s == target) Try(j+1, 0, target, cnt+1);
	}
}
int main(){
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	faster();
	cin >> n >> k;
	int sum = 0;
	for(int i=0; i<n; i++){
		cin >> a[i]; sum+= a[i];
	}
	if(sum%k!=0){
		cout << 0 << endl;
	}
	else {
		Try(0, 0, sum/k, 0);
		cout << res << endl;
	}
}

```

### NGUOI DI DU LICH

```cpp
#include <bits/stdc++.h>
using namespace std;
#define all(s) s.begin(), s.end()
#define faster() ios_base::sync_with_stdio(0); cin.tie(0);
#define run() long long t; cin >> t; while(t--)

int n;
int M[20][20];
vector<int> A[1001];
bool check[1001] = {};
int res = INT_MAX;
void DFS(int u, int sum, int par, int count){
	if(sum >= res) return;
	check[u] = true;

	for(auto x : A[u]){
		if(!check[x]) DFS(x, sum + M[u][x], u, count+1);
		else if(x ==1 && x != par && count == n) res = min(res, sum + M[u][1]);
	}

	check[u] = false;
}


int main(){
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	faster();
	cin >> n;
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin >> M[i][j];
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) if(i!=j) A[i].push_back(j);
	DFS(1, 0, 0, 1);
	cout << res << endl;
}


```
