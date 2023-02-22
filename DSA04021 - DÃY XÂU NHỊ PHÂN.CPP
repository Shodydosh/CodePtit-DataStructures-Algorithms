#include <iostream>
#include <string>
using namespace std;
long long f[94];

char findd(long long n, long long k)
{
    if (n == 1)
        return '0';
    if (n == 2)
        return '1';
    if (k <= f[n - 2])
        return findd(n - 2, k);
    return findd(n - 1, k - f[n - 2]);
}

main()
{
    long long t;
    cin >> t;
    f[1] = 1;
    f[2] = 1;
    for (long long i = 3; i <= 93; i++)
        f[i] = f[i - 1] + f[i - 2];
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        cout << findd(n, k) << endl;
    }
    return 0;
}
