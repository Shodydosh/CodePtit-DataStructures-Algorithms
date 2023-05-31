#include <bits/stdc++.h>
using namespace std;
long long a[100005];
long long n, k;

#define F(i, a, b) for (int i = a; i < b; ++i)
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        F(i, 0, n)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        ll ans = 0;
        for (ll i = 0; i < n - 1; i++)
        {
            /* Finding the index of the first element greater than `k-a[i]` in the array `a` starting
            from index `i+1` to `n-1`. */
            ll x = upper_bound(a + i + 1, a + n, k - a[i]) - a;
            /* Finding the index of the first element greater than or equal to `k-a[i]` in the array
            `a` starting
            from index `i+1` to `n-1`. */
            ll y = lower_bound(a + i + 1, a + n, k - a[i]) - a;

            // cout << a[i] << ' ' << a[x] << ' ' << a[y] << ' ' << x << ' ' << y << endl;

            // then x - y equals the amount of numbers = k - a[i];
            ans += (x - y);
        }
        cout << ans << endl;
    }
}
