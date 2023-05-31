#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pop pop_back
#define ll long long

int calculate(string s1, string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();
    // int l1 = sizeof(s1) / sizeof(s1[0]);
    // int l2 = sizeof(s2) / sizeof(s2[0]);
    // int dp[l1 + 1][l2 + 1] = {};
    int dp[l1 + 1][l2 + 1] = {};

    int maxLength = 0;
    for (int i = 0; i < l1; i++)
        for (int j = 0; j < l2; j++)
        {
            if (s1[i] == s2[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    return dp[l1][l2];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    // t = 1;
    while (t--)
    {
        string s1, s2;
        cin >> s1;
        cin >> s2;
        cout << s1 << ' ' << s2 << endl;
        cout << calculate(s1, s2) << endl;
    }
}
