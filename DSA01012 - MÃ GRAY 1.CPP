#include <bits/stdc++.h>
using namespace std;
int a[1000000];
long long n, k, target;

#define ll long long
#define all(x) x.begin(), x.end()
string s[1025];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        s[1] = "0";
        s[2] = "1";
        int len = pow(2, n);

        if (n > 1)
        {
            int middle = 2;
            for (int i = 2; i <= n; i++)
            {
                int tmp = pow(2, i); // số lượng các mã Gray thứ i
                for (int j = 1; j <= middle; j++)
                {
                    s[tmp - j + 1] = "1" + s[j];
                    s[j] = "0" + s[j];
                }
                middle = tmp;
            }
        }

        // cout << "check" << endl;
        for (int i = 1; i <= len; i++)
            cout << s[i] << ' ';
        cout << endl;
    }
}
