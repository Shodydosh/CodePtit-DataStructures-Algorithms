#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int visited[1000000] = {};
vector<int> ans;
long long n, k, target;

#define ll long long

void init()
{
    for (int i = 0; i <= k; i++)
        a[i] = i;
}

void print()
{
    for (int i = 1; i <= k; i++)
        cout << a[i];
    cout << ' ';
}

void Try(int i)
{
    for (int j = a[i - 1] + 1; j <= n - k + i; j++)
    {
        a[i] = j;
        if (i == k)
            print();
        else
            Try(i + 1);
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
        init();
        Try(1);
        cout << endl;
    }
}
