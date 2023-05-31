#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pop pop_back
#define ll long long
int n, k;
int a[505];
int visited[505] = {};
vector<int> tmp;

vector<pair<int, int>> ans;

void solveHanoiTower(int disks, char src, char aux, char des)
{
    if (disks == 1)
    {
        cout << src << " --> " << des << endl;
        return;
    }

    solveHanoiTower(disks - 1, src, des, aux); // src to aux
    cout << src << " --> " << des << endl;     // move 1 from src to des
    solveHanoiTower(disks - 1, aux, src, des); // aux to des
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    char A = 'A';
    char B = 'B';
    char C = 'C';
    solveHanoiTower(t, A, B, C);
}
