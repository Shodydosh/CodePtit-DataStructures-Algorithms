#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pop pop_back
#define ll long long

int n;
vector<string> ans;
int a[100] = {0};

void Try(int i, string s, int count)
{
    for (int j = i + 1; j <= n; j++)
    {
        if (a[i] < a[j])
        {
            if (count > 0)
                ans.pb(s + to_string(a[j]) + " ");
            Try(j, s + to_string(a[j]) + " ", count + 1);
        }
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
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        Try(0, "", 0);
        sort(ans.begin(), ans.end());
        for (string x : ans)
            cout << x << endl;
    }
}
