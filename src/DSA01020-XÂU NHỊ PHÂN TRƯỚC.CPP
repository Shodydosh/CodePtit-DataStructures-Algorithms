#include <bits/stdc++.h>
using namespace std;
int n, target;
int a[505];

string beforee(string s)
{
    int j = 1;
    while (j <= s.size())
    {
        if (s[s.size() - j] == '1')
        {
            s[s.size() - j] = '0';
            break;
        }
        else
        {
            s[s.size() - j] = '1';
            j++;
        }
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << beforee(s) << endl;
    }
}
