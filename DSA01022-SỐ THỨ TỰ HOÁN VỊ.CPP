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
        // for (auto x : tmp)
        //     cout << x << ' ';
        // cout << endl;
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
        for (int i = 0; i < n; i++)
            cin >> a[i];
        render();
        for (int j = 0; j < ans.size(); j++)
        {
            int check = 1;
            for (int i = 0; i < n; i++)
            {
                if (ans[j][i] != a[i])
                {
                    check = 0;
                    break;
                }
            }
            if (check)
            {
                index = j;
                break;
            }
        }
        cout << index + 1 << endl;
        index = 0;
    }
    return 0;
}
