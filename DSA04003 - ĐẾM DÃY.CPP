#include <bits/stdc++.h>
using namespace std;

long long M = 123456789;

long long calculate(long long n, long long k)
{
    if (k == 1)
        return n;
    long long tmp = calculate(n, k / 2);
    if (k % 2 == 0)
        return ((tmp % M) * (tmp % M)) % M;
    else
        return (tmp % M) * (tmp % M) * n % M;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--)
    {
        long long k;
        cin >> k;
        cout << calculate(2, k - 1) << endl;
    }
}
