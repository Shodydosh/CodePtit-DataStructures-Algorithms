#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    cin >> t;
    int a[1005];
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);

        if (n % 2 == 0)
        {
            for (int i = 0; i < n / 2; i++)
            {
                cout << a[n - i - 1] << ' ' << a[i] << ' ';
            }
            cout << endl;
        }
        else
        {
            for (int i = 0; i < n / 2; i++)
            {
                cout << a[n - i - 1] << ' ' << a[i] << ' ';
            }
            cout << a[n / 2] << endl;
        }
    }
    return 0;
}
