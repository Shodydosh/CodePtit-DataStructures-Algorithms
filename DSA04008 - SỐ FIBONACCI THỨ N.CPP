#include <bits/stdc++.h>
using namespace std;
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

main()
{
    ios_base::sync_with_stdio(0);
    F[0] = 1;
    F[1] = 1;

    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << f(n - 1) << endl;
    }
}
