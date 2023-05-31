#include <bits/stdc++.h>
using namespace std;
long long M = 1000000007;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        long long n;
        cin >> n;
        long long a[n];
        long long dp[n + 1] = {};
        for (long long i = 0; i < n; i++)
            cin >> a[i];
        long long maxVal = 0;
        for (long long i = 0; i < n; i++)
        {
            long long tmp = 1;
            for (long long j = 0; j < i; j++)
                if (a[i] > a[j])
                    tmp = max(tmp, 1 + dp[j]);

            dp[i] = tmp;
            maxVal = max(dp[i], maxVal);
        }
        cout << maxVal << endl;
    }
}
