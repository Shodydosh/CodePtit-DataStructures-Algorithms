#include <bits/stdc++.h>
using namespace std;
int n, k, cnt = 0;
vector<int> tmp;

void render()
{
    if (cnt > k || tmp.size() > n)
        return;

    if (tmp.size() == n && cnt == k)
    {
        for (auto x : tmp)
            cout << x;
        cout << endl;
        return;
    }

    for (int i = 0; i <= 1; i++)
    {
        tmp.push_back(i);
        cnt += i;
        render();
        cnt -= i;
        tmp.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        render();
    }
}
