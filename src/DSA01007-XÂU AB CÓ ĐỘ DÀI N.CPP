#include <bits/stdc++.h>
using namespace std;
int n;
vector<char> tmp;

void render()
{
    if (tmp.size() == n)
    {
        for (auto x : tmp)
            cout << x;
        cout << ' ';
        return;
    }

    tmp.push_back('A');
    render();
    tmp.pop_back();
    tmp.push_back('B');
    render();
    tmp.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        render();
        cout << endl;
    }
}
