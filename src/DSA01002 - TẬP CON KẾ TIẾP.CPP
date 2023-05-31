#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int visited[1000000] = {};
vector<int> ans;
long long n, k, target;

#define ll long long

void nextt()
{
    int tmp = k - 1;
    while (a[tmp] == n - k + 1 + tmp)
        tmp--;

    if (tmp < 0)
        for (int i = 0; i < k; i++)
            a[i] = n + i - k - 1;
    else
    {
        a[tmp]++;
        for (int j = tmp + 1; j < k; j++)
            a[j] = a[tmp] + j - tmp;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < k; i++)
            cin >> a[i];
        nextt();
        for (int i = 0; i < k; i++)
            cout << a[i] << ' ';
        cout << endl;
    }
}
