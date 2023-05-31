### CodePtit-DataStructures-Algorithms-Cheatsheet

<details>
  <summary>INIT</summary>
<div>
<h2 align="center"><img src = "https://media2.giphy.com/media/QssGEmpkyEOhBCb7e1/giphy.gif?cid=ecf05e47a0n3gi1bfqntqmob8g9aid1oyj2wr3ds3mg700bl&rid=giphy.gif" width = 20px> INIT</h2>
<p align="start"> 
  
```c++
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define run() long long t; cin >> t; while(t--)
#define faster() cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
```
  
</p>
</div>
</details>

<details>
  <summary>SINH HOAN VI</summary>
<div>
<h2 align="center"><img src = "https://media2.giphy.com/media/QssGEmpkyEOhBCb7e1/giphy.gif?cid=ecf05e47a0n3gi1bfqntqmob8g9aid1oyj2wr3ds3mg700bl&rid=giphy.gif" width = 20px> SINH HOAN VI</h2>
<p align="start"> 
  
<h3>DSA01019 - HAHAHA</h3>
  
```c++
string s = bitset<16>(i).to_string();
/* Taking the last n bits of the string. */
s = s.substr(16 - n, n);
/* 1 ~ H, 0 ~ A */
if (s.find("11") == -1 && s[0] == '1' && s[n - 1] == '0')
{
    for (auto c : s)
        (c == '1') ? cout << 'H' : cout << 'A';
    cout << endl;
}
```
  
<h3>DSA01021 - TỔ HỢP TIẾP THEO</h3>
  
```c++
int tmp = k - 1;
while (a[tmp] == n - k + tmp + 1)
tmp--;

if (tmp < 0)
    cout << k << endl;
else
{
    b[tmp]++;
    for (int i = tmp + 1; i < k; i++)
        b[i] = b[i - 1] + 1;

    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (a[i] == b[j])
            {
                cnt++;
                break;
            }
        }
    }
    cout << k - cnt << endl;
}
```
  
</p>
</div>
</details>
