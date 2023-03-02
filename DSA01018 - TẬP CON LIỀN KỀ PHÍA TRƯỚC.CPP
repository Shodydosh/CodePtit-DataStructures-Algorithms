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

int f[50];

main()
{
    faster();
    run()
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < k; i++)
            cin >> a[i];
        string s = string(n, '1');
        for (int i = 0; i < k; i++)
            s[a[i] - 1] = '0';
        prev_permutation(all(s));
        for (int i = 0; i < n; i++)
            if (s[i] == '0')
                cout << i + 1 << ' ';
        cout << endl;
    }
}
