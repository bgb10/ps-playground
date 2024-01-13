#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void func(int cur, int k) {
    if(cur > n && k < m) return;
    if(k == m) {
        for(int i=0; i<m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    arr[k] = cur;
    func(cur, k + 1);
    func(cur + 1, k);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(1, 0);
    return 0;
}