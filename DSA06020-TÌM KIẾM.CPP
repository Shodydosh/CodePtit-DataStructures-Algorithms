#include <bits/stdc++.h>
using namespace std;
int n, target;
int a[505];

int solve(int a[], int targe)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = r - (r - l) / 2;
        if (a[mid] == target)
        {
            return 1;
        }
        else if (a[mid] > target)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> target;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << solve(a, target) << endl;
    }
}
