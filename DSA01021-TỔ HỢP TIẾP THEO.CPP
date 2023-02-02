#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int a[n], b[n];
        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }

        int tmp = k - 1;
        while (a[tmp] == n - k + tmp + 1)
            tmp--;
        // cout << '<' << tmp << '>' << endl;
        if (tmp < 0)
        {
            cout << k << endl;
        }
        else
        {
            b[tmp]++;
            for (int i = tmp + 1; i < k; i++)
            {
                b[i] = b[i - 1] + 1;
            }

            // for (int i = 0; i < k; i++)
            //     cout << b[i] << ' ';
            // cout << endl;

            int cnt = 0;
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    if (a[i] == b[j])
                    {
                        cnt++;
                        break;
                    }
                }
            }
            cout << k - cnt << endl;
        }
    }
    return 0;
}
