#include <bits/stdc++.h>
using namespace std;
int visited[1000000] = {};
vector<string> words;
vector<string> ans;
long long n, k, target;

#define ll long long

void print()
{
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << endl;
}

void Try(int i, int index)
{
    if (i == k)
        print();
    int z;
    (i == 0) ? z = index : z = index + 1;
    for (int j = z; j < words.size(); j++)
    {
        ans.push_back(words[j]);
        Try(i + 1, j);
        ans.pop_back();
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
        set<string> se;
        for (int i = 0; i < n; i++)
        {
            string tmp;
            cin >> tmp;
            se.insert(tmp);
        }

        set<string>::iterator it;

        for (it = se.begin(); it != se.end(); it++)
            words.push_back(*it);
        Try(0, 0);
        cout << endl;
    }
}
