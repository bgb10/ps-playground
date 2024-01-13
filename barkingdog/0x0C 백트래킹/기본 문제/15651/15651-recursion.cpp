#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void func(int cur, int k) {
    if(cur > n) return;
    arr[k] = cur;
    if(k == m-1) {
        for(int i=0; i<m; i++) cout << arr[i] << ' ';
        cout << '\n';
        func(cur + 1, k);
        return;
    }
    func(1, k+1);
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