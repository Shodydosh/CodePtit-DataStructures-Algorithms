### TAP CON KE TIEP

```cpp
	#include <bits/stdc++.h>
	using namespace std;
	#define all(s) s.begin(), s.end()
	#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#define run() long long t; cin >> t; while(t--)

	int main(){
		faster();
		run(){
			int n, k;
			cin >> n >> k;
			vector<int> a(k);
			for(int i=0; i<k; i++)
				cin >> a[i];
			string s = string(n,'1');
			for(auto x : a) s[x-1] = '0';
			next_permutation(all(s));
			for(int i=0; i<n; i++) if(s[i] == '0') cout << i+1 << ' ';
			cout << endl;
		};
	}
```

### DAT TEN 1

```cpp
	int main(){
		faster();
		int n, k;
		cin >> n >> k;
		vector<string> s(n);
		for(int i=0; i<n; i++) cin >> s[i];

		sort(all(s));
		s.erase(unique(all(s)), s.end());

		n = s.size();
		string tmp = string(k, '0') + string(n-k, '1');
		do {
			for(int i=0; i<n; i++){
				if(tmp[i] == '0'){
					cout << s[i] << ' ';
				}
			}
			cout << endl;
		}
		while(next_permutation(all(tmp)));
	}
```

### PHUONG AN TOI UU

```cpp
	#include <bits/stdc++.h>
	using namespace std;
	#define all(s) s.begin(), s.end()
	#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#define run() long long t; cin >> t; while(t--)

	int main(){
		faster();
		int n, m;
		cin >> n >> m;
		int a[n], w[n];
		for(int i=0; i<n; i++) cin >> a[i];
		for(int j=0; j<n; j++) cin >> w[j];

		string res = "";
		int maxVal = INT_MIN, val =0, wei= 0;
		for(int i=1; i<pow(2, n); i++){

			string s = bitset<20>(i).to_string();
			s = s.substr(20-n, n);
			val = 0;
			wei = 0;
			for(int j=0; j<n; j++){
				if(s[j] == '1'){
					val += a[j];
					wei += w[j];
				}
			}
			if(val >= maxVal && wei <= m){
				res = s;
				maxVal = val;
			}
		}
		cout << maxVal << endl;
		for(int i=0; i<n; i++){
			cout << res[i] << ' ';
		}
	}

```

### GRAY 1

```cpp

#include <bits/stdc++.h>
using namespace std;
int a[1000000];
long long n, k, target;

#define ll long long
#define all(x) x.begin(), x.end()
string s[1025];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        s[1] = "0";
        s[2] = "1";
        int len = pow(2, n);

        if (n > 1)
        {
            int middle = 2;
            for (int i = 2; i <= n; i++)
            {
                int tmp = pow(2, i); // số lượng các mã Gray thứ i
                for (int j = 1; j <= middle; j++)
                {
                    s[tmp - j + 1] = "1" + s[j];
                    s[j] = "0" + s[j];
                }
                middle = tmp;
            }
        }

        // cout << "check" << endl;
        for (int i = 1; i <= len; i++)
            cout << s[i] << ' ';
        cout << endl;
    }
}

```

### GRAY 2

gray to bin

```cpp

#include <bits/stdc++.h>
using namespace std;
#define all(s) s.begin(), s.end()
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define run() long long t; cin >> t; while(t--)

int main(){
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	faster();

	int n; cin >> n;
	string s[n];
	for(int i=0; i<n; i++)
		cin >> s[i];
	for(int i=0; i<n; i++){
		string tmp = "";
		tmp = s[i][0];
		for(int j=1; j<s[i].size(); j++){
			int k = tmp.size()-1;
			if(s[i][j] != tmp[k]){
				tmp += "1";
			}
			else tmp += "0";
		}
		cout << tmp << endl;
	}
}

```

### GRAY 3

```cpp

#include <bits/stdc++.h>
using namespace std;
int a[1000000];
long long n, k, target;

#define ll long long
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    string s[t];
    // t = 1;
    for (int i = 0; i < t; i++)
        cin >> s[i];
    for (int i = 0; i < t; i++)
    {
        cout << s[i][0];
        for (int j = 1; j < s[i].size(); j++)
            cout << (s[i][j] + s[i][j - 1] - '0' - '0') % 2;
        cout << endl;
    }
}

```
