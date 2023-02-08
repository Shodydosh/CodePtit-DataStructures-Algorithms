#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int visited[1000000] = {};
vector<int> ans;
long long n, k, target;

#define ll long long
#define all(x) x.begin(), x.end()

// vector<int> v = { 1, 1, 3, 3, 3, 10, 1, 3, 3, 7, 7, 8 }, i;
// Using std::unique
// ip = std::unique(v.begin(), v.begin() + 12);
// Now v becomes {1 3 10 1 3 7 8 * * * * *}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        cin >> n >> k;
        vector<int> num(n);
        for (auto &x : num)
            cin >> x;
        sort(all(num));
        /* Removing the duplicates from the vector. */
        vector<int>::iterator ip = unique(all(num));

        /* Resizing the vector to the size of the distance between the begining of the vector and the
        iterator. */
        num.resize(distance(num.begin(), ip));
        n = num.size();

        /* Creating a string of length n, with k zeros and n-k ones. */
        // similar to a binary string
        string s = string(k, '0') + string(n - k, '1');

        do
        {
            // 1 2 3 4 5
            // 00011 1 2 3
            // 00101 1 2 4
            // 00110 1 2 5
            // 01001 1 3 4
            // 01010 1 3 5
            // 01100 1 4 5
            // 10001 2 3 4
            // 10010 2 3 5
            // 10100 2 4 5
            // 11000 3 4 5
            // cout << s << ' ';
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '0')
                    cout << num[i] << ' ';
            }
            cout << endl;
        } while (next_permutation(all(s)));
    }
}
