#include <bits/stdc++.h>
using namespace std;

long long M = 1000000007;

long long reverse(long long n)
{
    string tmp = to_string(n);
    reverse(tmp.begin(), tmp.end());
    return stoll(tmp);
}

long long sqr(long long x)
{
    return ((x % M) * (x % M)) % M;
}

long long calculate(long long n, long long reve)
{
    if (reve == 1)
        return n;
    long long tmp = calculate(n, reve / 2);
    if (reve % 2 == 0)
        return sqr(tmp);
    else
        return sqr(tmp) * n % M;
}

main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << calculate(n, reverse(n)) % M << endl;
    }
}
