#include <bits/stdc++.h>
using namespace std;
long long M = 1000000007;
int a[8][8], b, value[8][8];
int maxVal = INT_MIN;

bool validate(int i, int j)
{
    for (int k = 0; k < i; k++)
        if (a[k][j] == 1)
            return 0;
    // dưới phải -> trên trái
    for (int x = i, y = j; x >= 0 && y >= 0; x--, y--)
        if (a[x][y] == 1)
            return 0;
    // dưới trái -> trên phải
    for (int x = i, y = j; x >= 0 && y < 8; x--, y++)
        if (a[x][y] == 1)
            return 0;

    return 1;
}

void Try(int i, int S = 0)
{
    if (i == 8)
    {
        maxVal = max(S, maxVal);
        return;
    }

    for (int j = 0; j < 8; j++)
    {
        if (validate(i, j))
        {
            a[i][j] = 1;
            Try(i + 1, S + value[i][j]);
            a[i][j] = 0;
        }
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                cin >> value[i][j];
        Try(0);
        cout << maxVal << endl;
        maxVal = INT_MIN;
    }
}
