#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        int a[n];
        set<int> se;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            se.insert(a[i]);
        }
        sort(a, a + n);
        int minn = a[0], maxx = a[n - 1];
        cout << maxx - minn - se.size() + 1 << endl;
    }
}
