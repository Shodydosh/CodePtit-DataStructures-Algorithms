#include <bits/stdc++.h>
using namespace std;
// int a[1000000];
int visited[1000000] = {};
vector<int> ans;
long long n, k, target;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            a[i] = i + 1;
        int tmp = n * (n - 1);
        do
        {
            for (int i = 0; i < n; i++)
                cout << a[i];
            cout << ' ';
        } while (next_permutation(a.begin(), a.end()));
        cout << endl;
    }
}
