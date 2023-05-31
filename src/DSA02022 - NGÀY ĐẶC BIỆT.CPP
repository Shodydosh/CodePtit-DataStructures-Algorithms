#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pop pop_back
#define ll long long
int n, k, tmp;
int a[505];

vector<string> ans;

void render(string s)
{
    if (s[0] == '0' && s[1] == '0')
        return;
    if (s[2] == '0' && s[3] == '0' || s[2] == '1')
        return;
    if (s[4] == '0')
        return;

    // for (int i = 0; i < 4; i++)
    // {
    //     if (s[i] != s[7 - i])
    //         return;
    // }

    string res = "";
    res += s[0] == '1' ? "2" : "0";
    res += s[1] == '1' ? "2" : "0";
    res += '/';
    res += s[2] == '1' ? "2" : "0";
    res += s[3] == '1' ? "2" : "0";
    res += '/';
    res += "2";
    res += s[5] == '1' ? "2" : "0";
    res += s[6] == '1' ? "2" : "0";
    res += s[7] == '1' ? "2" : "0";
    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = pow(2, 6); i < pow(2, 8); i++)
    {
        string s = bitset<20>(i).to_string();
        // cout << s << endl;
        s = s.substr(12, 8);
        render(s);
    }
}
