#include <bits/stdc++.h>
using namespace std;

long long M = 123456789;

long long calculate(long long k, long long val)
{
    if (k % 2 == 1)
        return val;
    return calculate(k / 2, val + 1);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        cout << char(calculate(k, 1) + 'A' - 1) << endl;
    }
}
