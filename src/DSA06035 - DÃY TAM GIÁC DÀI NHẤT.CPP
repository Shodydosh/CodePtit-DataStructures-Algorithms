#include <bits/stdc++.h>
using namespace std;
long long a[100005];
long long n, k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        long long a[n];
        for (long long i = 0; i < n; i++)
            cin >> a[i];
        long long dpr[n] = {}, dpl[n] = {};
        for (long long i = 1; i < n; i++)
            if (a[i] > a[i - 1])
                dpl[i] = dpl[i - 1] + 1;
        for (long long i = n - 2; i >= 0; i--)
            if (a[i] > a[i + 1])
                dpr[i] = dpr[i + 1] + 1;
        long long maxx = INT_MIN;
        for (long long i = 0; i < n; i++)
        {
            int tmp = dpl[i] + dpr[i] + 1;
            if (tmp > maxx)
                maxx = tmp;
        }
        cout << maxx << endl;
    }
}
