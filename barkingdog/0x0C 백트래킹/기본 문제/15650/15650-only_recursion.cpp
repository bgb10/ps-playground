#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void func(int k, int cur) {
    if(cur > n && k < m) return;
    if(k == m) {
        for(int i=0; i<m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    arr[k] = cur;
    func(k + 1, cur + 1);
    func(k, cur + 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0, 1);
    return 0;
}