#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pop pop_back
#define ll long long
int n, k;
vector<string> ans;
string a = "";

int check(string s)
{
    int count = 1;
    int OK = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0' && s[i - 1] == '0')
        {
            count++;
            if (count == k)
                OK++;
            if (count > k)
                return 0;
        }
        else
            count = 1;
    }
    if (OK == 1)
        return 1;
    return 0;
}

void render()
{
    for (int i = 0; i < pow(2, n); i++)
    {
        /* Converting the number to binary and then to string. */
        string s = bitset<20>(i).to_string();
        s = s.substr(20 - n, n);

        if (check(s))
            ans.push_back(s);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto x : ans)
    {
        for (auto c : x)
            (c == '0') ? cout << 'A' : cout << 'B';
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < k; i++)
            a += 'A';
        render();
    }
}
