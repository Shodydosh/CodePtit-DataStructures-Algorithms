#include <bits/stdc++.h>
using namespace std;
long long n, k, target;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        ll num[100000];
        for (ll i = 0; i < n; i++)
            cin >> num[i];
        sort(num, num + n);
        int check = 0;
        for (ll i = 0; i < n - 2; i++)
        {

            for (ll j = i + 1; j < n - 1; j++)
            {
                int tmp1 = (lower_bound(num + j + 1, num + n, k - num[j] - num[i])) - num - j - 1;
                int tmp2 = (upper_bound(num + j + 1, num + n, k - num[j] - num[i])) - num - j - 1;
                if (tmp1 != tmp2)
                {
                    check = 1;
                    break;
                }
            }
            if (check)
                break;
        }

        if (check)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
