#include <bits/stdc++.h>
using namespace std;
int a[1000000];
long long n, k, target;

#define ll long long
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    // cin >> t;
    t = 1;
    while (t--)
    {

        cin >> n;
        for (int i = 0; i < pow(2, n); i++)
        {
            string s = bitset<16>(i).to_string();
            /* Taking the last n bits of the string. */
            s = s.substr(16 - n, n);
            if (s.find("0000") == -1 && s.find("11") == -1 && s[0] == '1' && s[n - 1] == '0')
            {
                for (auto c : s)
                    (c == '1') ? cout << '8' : cout << '6';
                cout << endl;
            }
        }
    }
}
