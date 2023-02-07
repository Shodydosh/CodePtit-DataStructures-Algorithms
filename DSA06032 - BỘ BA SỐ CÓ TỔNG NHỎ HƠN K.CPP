#include <bits/stdc++.h>
using namespace std;
long long n, k, target;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--)
    {

        cin >> n >> k;
        ll num[100000];
        for (ll i = 0; i < n; i++)
            cin >> num[i];
        sort(num, num + n);
        ll ans = 0;
        for (ll i = 0; i < n - 2; i++)
            for (ll j = i + 1; j < n - 1; j++)
                ans += (lower_bound(num + j + 1, num + n, k - num[j] - num[i])) - num - j - 1;
        cout << ans << endl;
    }
}
