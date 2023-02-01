#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int n;

void render(int i)
{
    if (ans.size() == n)
    {
        for (auto x : ans)
            cout << x << ' ';
        cout << endl;
        return;
    }
    if (i < n / 2)
    {
        for (int j = 0; j <= 1; j++)
        {
            ans.push_back(j);
            render(i + 1);
            ans.pop_back();
        }
    }
    else
    {
        if (n % 2 == 1)
            n--;
        ans.push_back(ans[n - i - 1]);
        render(i + 1);
        ans.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    render(0);
    return 0;
}
