#include <bits/stdc++.h>
using namespace std;
int visited[505] = {}, n;
int a[505];
vector<vector<int>> ans;
vector<int> tmp;

void render()
{
    if (tmp.size() == n)
    {
        ans.push_back(tmp);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            tmp.push_back(i);
            render();
            visited[i] = 0;
            tmp.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    int index;
    cin >> t;
    while (t--)
    {
        cin >> n;
        render();
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            for (auto x : ans[i])
                cout << x;
            cout << ' ';
        }
        cout << endl;
        ans.clear();
    }
    return 0;
}
