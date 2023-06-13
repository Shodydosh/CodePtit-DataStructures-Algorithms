### DEM CAP

```cpp
int cal(int x, int Y[], int n, int spec[])
{
    if (x == 0)
        return 0;
    if (x == 1)
        return spec[0];
    int *i = upper_bound(Y, Y + n, x);
    int a = (Y + n) - i;
    a += (spec[0] + spec[1]);
    if (x == 2)
        a -= (spec[3] + spec[4]);

    if (x == 3)
        a += spec[2];
    return a;
}

int count1(int X[], int Y[], int m, int n)
{
    int spec[5] = {0};
    for (int i = 0; i < n; i++)
        if (Y[i] < 5)
            spec[Y[i]]++;
    sort(Y, Y + n);
    int t = 0;
    for (int i = 0; i < m; i++)
        t += cal(X[i], Y, n, spec);
    return t;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int m[100000], n[100000];
        for (int i = 0; i < a; i++)
            cin >> m[i];
        for (int i = 0; i < b; i++)
            cin >> n[i];
        cout << count1(m, n, a, b) << endl;
    }
}
```

### TIM KIEM TRONG DAY SAP XEP VONG

```cpp
int search(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid + 1;

        if (nums[mid] >= nums[left])
        {
            // means that the left half is sorted ascendingly
            // ex: 4 5 6 7 0 1 2
            if (target >= nums[left] && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            // nums[mid] < nums[left]
            // means that the right half is sorted ascendingly
            // ex: 7 0 1 2
            if (target > nums[mid] && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}

```

### SAP XEP CHEN

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> ans;
    int a[1000];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        sort(a, a + i + 1);
        cout << "Buoc " << i << ": ";
        for (int j = 0; j <= i; j++)
            cout << a[j] << ' ';
        cout << endl;
    }
}
```

### SAP XEP CHON

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
int n;
cin >> n;
int a[1000];
for (int i = 0; i < n; i++)
cin >> a[i];
for (int i = 0; i < n - 1; i++)
{
int minn = i;
for (int j = i; j < n; j++)
if (a[minn] > a[j])
minn = j;
swap(a[minn], a[i]);
cout << "Buoc " << i + 1 << ": ";
for (int j = 0; j < n; j++)
cout << a[j] << " ";
cout << endl;
}
}
```

### SAP XEP NOI BOT

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[1000];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int check = 1;
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                check = 0;
            }
        }
        if (check)
            break;

        // out
        cout << "Buoc " << i << ": ";
        for (int j = 0; j < n; j++)
            cout << a[j] << " ";
        cout << endl;
    }
}
```

### BO BA CO TONG BANG K

```cpp

int main()
{
    run()
    {

        cin >> n >> k;
        ll num[100000];
        for (ll i = 0; i < n; i++)
            cin >> num[i];
        sort(num, num + n);
        int check = 0;
        for (ll i = 0; i < n - 2; i++)
        {

            for (ll j = i + 1; j < n - 1; j++)
            {
                int tmp1 = (lower_bound(num + j + 1, num + n, k - num[j] - num[i])) - num - j - 1;
                int tmp2 = (upper_bound(num + j + 1, num + n, k - num[j] - num[i])) - num - j - 1;
                if (tmp1 != tmp2)
                {
                    check = 1;
                    break;
                }
            }
            if (check)
                break;
        }

        if (check)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

```
