#include <bits/stdc++.h>
using namespace std;
long long a[100005];
long long n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--)
    {
        int check = 1;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            if (a[i] > a[i + 1])
            {
                cout << (i + 1) % n << endl;
                check = 0;
                break;
            }
    }
}
