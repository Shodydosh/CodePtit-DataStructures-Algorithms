#include <bits/stdc++.h>
using namespace std;

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
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (k < a[0])
        {
            cout << -1 << endl;
        }
        else
        {
            int pos = upper_bound(a.begin(), a.end(), k) - a.begin();
            cout << pos << endl;
        }
    }
}
