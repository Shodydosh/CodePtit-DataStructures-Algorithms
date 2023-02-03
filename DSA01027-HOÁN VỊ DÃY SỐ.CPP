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
        for (auto x : tmp)
            cout << x << ' ';
        cout << endl;
        ans.push_back(tmp);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            tmp.push_back(a[i]);
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
    // cin >> t;
    // while (t--)
    // {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    render();
    // }
    return 0;
}
