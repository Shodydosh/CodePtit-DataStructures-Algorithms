#include <bits/stdc++.h>
using namespace std;

long long maxSubArray(vector<long long> &nums)
{
    long long n = nums.size();
    long long maxVal = INT_MIN;
    long long tmpMax = 0;
    for (int i = 0; i < n; i++)
    {
        tmpMax = max(nums[i], tmpMax + nums[i]);
        maxVal = max(maxVal, tmpMax);
    }
    return maxVal;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    // t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> num1(n);
        for (int i = 0; i < n; i++)
            cin >> num1[i];
        cout << maxSubArray(num1) << endl;
    }
}
