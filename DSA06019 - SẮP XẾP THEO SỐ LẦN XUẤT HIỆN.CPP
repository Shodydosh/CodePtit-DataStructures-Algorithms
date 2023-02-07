#include <bits/stdc++.h>
using namespace std;
int a[100000];
long long n, k, target;

#define ll long long
int fre[100000] = {};

bool cmp(int x, int y)
{
    if (fre[x] > fre[y])
        return 1;
    if (fre[x] == fre[y] && x < y)
        return 1;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--)
    {

        cin >> n;
        int num[100000];
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
            fre[num[i]]++;
        }

        sort(num, num + n, cmp);

        for (int i = 0; i < n; i++)
        {
            cout << num[i] << ' ';
            fre[num[i]] = 0;
        }

        cout << endl;
    }
}
