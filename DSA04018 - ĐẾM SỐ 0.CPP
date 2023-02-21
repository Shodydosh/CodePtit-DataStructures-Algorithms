#include <bits/stdc++.h>
using namespace std;
int a[505], mid;
int ans;

void findd(long long left, long long right)
{
    if (left > right)
        return;
    mid = left + (right - left) / 2;
    if (a[mid] == 0)
    {
        findd(mid + 1, right);
    }
    else
    {
        ans = mid;
        findd(left, mid - 1);
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (a[n - 1] == 0)
            cout << n << endl;
        else
        {
            findd(0, n - 1);
            cout << ans << endl;
        }
    }
}
