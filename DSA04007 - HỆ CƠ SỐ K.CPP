#include <bits/stdc++.h>
using namespace std;
long long M = 1000000007;

int kToInt(string n, int k)
{
    int res = 0;
    for (int i = 0; i < n.length(); i++)
        res = res * k + (n[i] - '0');
    return res;
}

string intToK(int n, int k)
{
    string res = "";
    while (n)
    {
        res = to_string(n % k) + res;
        n /= k;
    }
    return res;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        int k;
        string a, b;
        cin >> k >> a >> b;
        int n1 = kToInt(a, k);
        int n2 = kToInt(b, k);
        cout << intToK(n1 + n2, k) << endl;
    }
}
