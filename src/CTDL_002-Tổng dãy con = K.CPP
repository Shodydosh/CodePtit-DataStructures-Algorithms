#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int a[505];
int n, target, cnt = 0;

void render(int i, int sum = 0)
{
    if (sum == target)
    {
        cnt++;
        for (auto x : ans)
            cout << x << ' ';
        cout << endl;
        return;
    }
    if (sum > target || i >= n)
        return;

    render(i + 1, sum);
    ans.push_back(a[i]);
    render(i + 1, sum + a[i]);
    ans.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> target;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    render(0);
    cout << cnt;
    return 0;
}
