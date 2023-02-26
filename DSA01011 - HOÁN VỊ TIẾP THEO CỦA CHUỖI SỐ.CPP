#include <bits/stdc++.h>
using namespace std;
int n;
long long M = 1000000007;
#define all(x) x.begin(), x.end()

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        string s;
        cin >> s;

        cout << a << ' ';
        if (next_permutation(s.begin(), s.end()))
            cout << s << endl;
        else
            cout << "BIGGEST\n";
    }
}
