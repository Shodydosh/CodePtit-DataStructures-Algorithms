#include <bits/stdc++.h>
using namespace std;

#define ll long long
int n, k;

vector<vector<int>> ans;
vector<int> tmp;
vector<int> v;

string calculate(int n)
{
    queue<string> q;
    q.push("9");
    while (q.size())
    {
        string tmp = q.front();
        q.pop();
        if (stoll(tmp) % n == 0)
            return tmp;
        q.push(tmp + "0");
        q.push(tmp + "9");
    }
    return "-1";
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
        cin >> n;
        cout << calculate(n) << endl;
    }
}
